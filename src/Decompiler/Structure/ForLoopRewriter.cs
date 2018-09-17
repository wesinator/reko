﻿#region License
/* 
 * Copyright (C) 1999-2018 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core;
using Reko.Core.Absyn;
using Reko.Core.Expressions;
using Reko.Core.Operators;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reko.Structure
{
    public class ForLoopRewriter
    {
        private Procedure proc;

        public ForLoopRewriter(Procedure proc)
        {
            this.proc = proc;
        }

        public void Transform()
        {
            RewriteForLoops(proc.Body);
        }

        /// <summary>
        /// Locate loops in a list of statements and if they are for-loops,
        /// rewrite them as such.
        /// </summary>
        public void RewriteForLoops(List<AbsynStatement> stmts)
        {
            for (int i = 0; i < stmts.Count; ++i)
            {
                ForLoopCandidate candidate;
                switch (stmts[i])
                {
                case AbsynWhile whi:
                    RewriteForLoops(whi.Body);
                    candidate = TryMakeLoopCandidate(whi.Condition, whi.Body, stmts, i);
                    if (candidate != null)
                    {
                        stmts[i] = MakeForLoop(candidate, stmts);
                    }
                    break;
                case AbsynDoWhile dow:
                    RewriteForLoops(dow.Body);
                    candidate = TryMakeLoopCandidate(dow.Condition, dow.Body, stmts, i);
                    if (candidate != null)
                    {
                        stmts[i] = MakeForLoop(candidate, stmts);
                    }
                    break;
                case AbsynIf ifStm:
                    RewriteForLoops(ifStm.Then);
                    RewriteForLoops(ifStm.Else);
                    break;
                case AbsynSwitch sw:
                    RewriteForLoops(sw.Statements);
                    break;
                default:
                    break;
                }
            }
            stmts.RemoveAll(s => s == null);
        }

        /// <summary>
        /// Attempts to identify the variable controlling a for loop,
        /// and the statement that update the variable within the loop body.
        /// </summary>
        /// <param name="cond">Possible loop control condition</param>
        /// <param name="loopBody">The body of the loop which may contain an update variable</param>
        /// <param name="container">List of statements in which the loop is located.</param>
        /// <param name="i">Position of the candidate loop within the container.</param>
        /// <returns>A for loop candidate if a loop has been recognized, otherwise null.</returns>
        public ForLoopCandidate TryMakeLoopCandidate(
            Expression cond,
            List<AbsynStatement> loopBody,
            List<AbsynStatement> container, 
            int i)
        {
            if (!(cond is BinaryExpression cmp) ||
                !(cmp.Operator is ConditionalOperator))
                return null;

            var (loopVariable, update) = IdentifyLoopVariable(loopBody, cmp);
            if (loopVariable == null)
                return null;

            var initializer = FindInitializer(loopVariable, container, i);
            var candidate = new ForLoopCandidate
            {
                LoopBody = loopBody,
                Container = container,
                LoopVariable = loopVariable,
                Initializer = initializer,
                Condition = cmp,
                Update = update,
            };
            return candidate;
        }

        private (Identifier,AbsynAssignment) IdentifyLoopVariable(
            List<AbsynStatement> loopBody,
            BinaryExpression cmp)
        {
            List<AbsynAssignment> updates;
            Identifier loopVariable;
            var idLeft = cmp.Left as Identifier;
            var idRight = cmp.Right as Identifier;
            var leftUpdates = FindUpdateAssignments(idLeft, loopBody);
            var rightUpdates = FindUpdateAssignments(idRight, loopBody);
            if (leftUpdates.Count == 1)
            {
                if (rightUpdates.Count == 1)
                    return (null, null);
                loopVariable = idLeft;
                updates = leftUpdates;
            }
            else if (rightUpdates.Count == 1)
            {
                loopVariable = idRight;
                updates = rightUpdates;
            }
            else
                return (null, null);
            return (loopVariable, updates[0]);
        }

        private AbsynAssignment FindInitializer(Identifier loopVariable, List<AbsynStatement> stmts, int i)
        {
            for (i = i - 1; i >= 0; --i)
            {
                if (!(stmts[i] is AbsynAssignment ass))
                    return null;
                if (ass.Dst == loopVariable)
                    return ass;
                if (UsedIdentifierFinder.Contains(ass.Dst, loopVariable))
                    return null;
                if (UsedIdentifierFinder.Contains(ass.Src, loopVariable))
                    return null;
            }
            return null;
        }

        private List<AbsynAssignment> FindUpdateAssignments(Identifier id, List<AbsynStatement> stmts)
        {
            var updates = new List<AbsynAssignment>();
            if (id == null)
                return updates;
            for (int i = stmts.Count - 1; i >= 0; --i)
            {
                var stm = stmts[i];
                if (!(stm is AbsynAssignment ass))
                    return updates;
                if (id != ass.Dst)
                {
                    if (UsedIdentifierFinder.Contains(ass.Src, id) ||
                        UsedIdentifierFinder.Contains(ass.Dst, id))
                    {
                        return updates;
                    }
                    continue;
                }
                if (ass.Src is BinaryExpression bin)
                {
                    if (id == bin.Left)
                        updates.Add(ass);
                }
                else if (ass.Src is FieldAccess fa)
                {
                    if (fa.Structure is Dereference de)
                    {
                        if (de.Expression == id)
                            updates.Add(ass);
                    }
                }
            }
            return updates;
        }

        private AbsynFor MakeForLoop(ForLoopCandidate candidate, List<AbsynStatement> stmts)
        {
            var iInit = stmts.IndexOf(candidate.Initializer);
            if (iInit >= 0)
            {
                stmts[iInit] = null;
            }
            candidate.LoopBody.Remove(candidate.Update);
            var forLoop = new AbsynFor(
                candidate.Initializer,
                candidate.Condition,
                candidate.Update,
                candidate.LoopBody);
            return forLoop;
        }

        private class UsedIdentifierFinder : ExpressionVisitorBase
        {
            private Identifier id;
            private bool found;

            public static bool Contains(Expression expr, Identifier id)
            {
                var uif = new UsedIdentifierFinder { id = id };
                expr.Accept(uif);
                return uif.found;
            }

            public override void VisitIdentifier(Identifier id)
            {
                this.found |= (id == this.id);
            }
        }
    }

    public class ForLoopCandidate
    {
        public List<AbsynStatement> Container;
        public List<AbsynStatement> LoopBody;
        public Identifier LoopVariable;
        public AbsynAssignment Initializer;
        public Expression Condition;
        public AbsynAssignment Update;
    }
}
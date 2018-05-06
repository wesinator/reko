﻿#region License
/* 
 * Copyright (C) 2017-2018 Christian Hostelet.
 * inspired by work from:
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
using Reko.Libraries.Microchip;
using System;
using System.Collections.Generic;
using System.Text;

namespace Reko.Arch.MicrochipPIC.Common
{
    public class PICPostprocessProgram
    {
        private readonly Program program;
        private readonly PICArchitecture architecture;
        private readonly PIC pic;
        private readonly SegmentMap newMap;

        private Dictionary<IMemoryRegion, int> regionsCounter;

        private PICPostprocessProgram(Program prog, PICArchitecture arch)
        {
            program = prog;
            architecture = arch;
            pic = arch.PICDescriptor;
            newMap = new SegmentMap(PICProgAddress.Ptr(0));
        }

        public static Program Validate(Program prog, PICArchitecture arch)
            => new PICPostprocessProgram(prog ?? throw new ArgumentNullException(nameof(prog)),
                                         arch ?? throw new ArgumentNullException(nameof(arch)))
                    .PerformValidation();

        private Program PerformValidation()
        {
            var user = program.User;
            user.Processor = pic.Name;
            user.TextEncoding = Encoding.ASCII;

            // Re-assign memory segments according to PIC memory program space definition.
            
            foreach (var segt in program.SegmentMap.Segments.Values)
            {
                var curAddr = segt.Address;
                var curSize = segt.ContentSize;
                do
                {
                    var regn = PICMemoryDescriptor.GetProgramRegion(curAddr);
                    if (regn == null)
                        throw new InvalidOperationException("Attempt to load a binary image which is not compatible with the selected PIC's program memory space.");
                    var fitSize = Math.Min(regn.PhysicalByteAddrRange.End - curAddr, curSize);
                    var rd = segt.MemoryArea.CreateLeReader(curAddr);
                    var b = rd.ReadBytes((int)fitSize);
                    var splitMem = new MemoryArea(curAddr, b);
                    if (regn.Contains(curAddr, curSize))
                    {
                        var newsegt = new ImageSegment(GetRegionSequentialName(regn), splitMem, GetAccessMode(regn));
                        newMap.AddSegment(newsegt);
                    }
                    curSize -= (uint)fitSize;
                    curAddr += fitSize;
                } while (curSize > 0);

            }
            program.SegmentMap = newMap;
            SetPICExecMode();
            
            return program;
        }

        /// <summary>
        /// Gets a unique region's name.
        /// </summary>
        /// <param name="regn">The PIC program memory region descriptor.</param>
        private string GetRegionSequentialName(IMemoryRegion regn)
        {
            if (regionsCounter == null)
            {
                regionsCounter = new Dictionary<IMemoryRegion, int>();
            }
            if (regionsCounter.TryGetValue(regn, out var counter))
            {
                regionsCounter[regn] = counter+1;
                return $"{regn.RegionName}_{counter}";
            }
            regionsCounter[regn] = 2;
            return $"{regn.RegionName}_1";
        }

        /// <summary>
        /// Gets the memory segment access mode based on PIC memory region's attributes
        /// </summary>
        /// <param name="regn">The PIC program memory region descriptor.</param>
        /// <returns>
        /// The Reko memory segment access mode.
        /// </returns>
        /// <exception cref="InvalidOperationException">Thrown when the requested operation is invalid.</exception>
        private AccessMode GetAccessMode(IMemoryRegion regn)
        {
            if (regn.TypeOfMemory != MemoryDomain.Prog && regn.TypeOfMemory != MemoryDomain.Other)
                throw new InvalidOperationException($"{nameof(GetAccessMode)}({regn.TypeOfMemory})");

            switch (regn.SubtypeOfMemory)
            {
                case MemorySubDomain.Code:
                case MemorySubDomain.ExtCode:
                case MemorySubDomain.Debugger:
                case MemorySubDomain.Test:
                    return AccessMode.ReadExecute;
            }
            return AccessMode.Read;
        }

        /// <summary>
        /// Sets the PIC execution mode per the configuration bits (if present in the memory image).
        /// </summary>
        private void SetPICExecMode()
        {
            var dcf = PICMemoryDescriptor.GetDCRField("XINST");
            if (dcf == null)
                return;
            var dcr = PICMemoryDescriptor.GetDCR(dcf.RegAddress);
            if (!program.SegmentMap.TryFindSegment(dcr.Address, out ImageSegment xinstsegt))
                return;
            uint xinstval;
            if (dcr.BitWidth <= 8)
                xinstval = xinstsegt.MemoryArea.ReadByte(dcf.RegAddress);
            else if (dcr.BitWidth <= 16)
                xinstval = xinstsegt.MemoryArea.ReadLeUInt16(dcf.RegAddress);
            else
                xinstval = xinstsegt.MemoryArea.ReadLeUInt32(dcf.RegAddress);
            if (dcr.CheckIf("XINST", "ON", xinstval))
            {
                PICMemoryDescriptor.ExecMode = PICExecMode.Extended;
                architecture.Description = architecture.Options.ProcessorModel.PICName + " (extended)";
            }
            else
            {
                PICMemoryDescriptor.ExecMode = PICExecMode.Traditional;
                architecture.Description = architecture.Options.ProcessorModel.PICName + " (traditional)";
            }
        }

    }

}

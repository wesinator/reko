#region License
/* 
 * Copyright (C) 1999-2018 John K�ll�n.
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

using NUnit.Framework;
using Reko.Arch.X86;
using Reko.Assemblers.x86;
using Reko.Core;
using Reko.Core.Machine;
using Reko.Core.Services;
using Reko.Core.Types;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.IO;
using System.Linq;
using System.Text;

namespace Reko.UnitTests.Arch.Intel
{
    [TestFixture]
    public class X86DisassemblerTests
    {
        private ServiceContainer sc;
        private X86Disassembler dasm;
        private X86Options options;

        public X86DisassemblerTests()
        {
            sc = new ServiceContainer();
            sc.AddService<IFileSystemService>(new FileSystemServiceImpl());
        }

        private X86Instruction Disassemble16(params byte[] bytes)
        {
            MemoryArea img = new MemoryArea(Address.SegPtr(0xC00, 0), bytes);
            EndianImageReader rdr = img.CreateLeReader(img.BaseAddress);
            var dasm = new X86Disassembler(ProcessorMode.Real, rdr, PrimitiveType.Word16, PrimitiveType.Word16, false);
            if (options != null)
            {
                dasm.Emulate8087 = options.Emulate8087;
            }
            return dasm.First();
        }

        private X86Instruction Disassemble32(params byte[] bytes)
        {
            var img = new MemoryArea(Address.Ptr32(0x10000), bytes);
            var rdr = img.CreateLeReader(img.BaseAddress);
            var dasm = new X86Disassembler(ProcessorMode.Protected32, rdr, PrimitiveType.Word32, PrimitiveType.Word32, false);
            return dasm.First();
        }

        private X86Instruction Disassemble64(params byte[] bytes)
        {
            var img = new MemoryArea(Address.Ptr64(0x10000), bytes);
            var rdr = img.CreateLeReader(img.BaseAddress);
            var dasm = new X86Disassembler(
                ProcessorMode.Protected64,
                rdr,
                PrimitiveType.Word32,
                PrimitiveType.Word64,
                true);
            return dasm.First();
        }

        private void CreateDisassembler16(params byte[] bytes)
        {
            var mem = new MemoryArea(Address.SegPtr(0x0C00, 0), bytes);
            CreateDisassembler16(mem);
        }

        private void CreateDisassembler16(MemoryArea mem)
        {
            dasm = new X86Disassembler(
                ProcessorMode.Real,
                mem.CreateLeReader(mem.BaseAddress),
                PrimitiveType.Word16,
                PrimitiveType.Word16,
                false);
            if (options != null)
            {
                dasm.Emulate8087 = options.Emulate8087;
            }
        }

        private void CreateDisassembler32(MemoryArea image)
        {
            dasm = new X86Disassembler(
                ProcessorMode.Protected32,
                image.CreateLeReader(image.BaseAddress),
                PrimitiveType.Word32,
                PrimitiveType.Word32,
                false);
        }

        private void CreateDisassembler16(EndianImageReader rdr)
        {
            dasm = new X86Disassembler(
                ProcessorMode.Real,
                rdr,
                PrimitiveType.Word16,
                PrimitiveType.Word16,
                false);
        }

        private void AssertCode16(string sExp, params byte[] bytes)
        {
            var instr = Disassemble16(bytes);
            Assert.AreEqual(sExp, instr.ToString());
        }

        private void AssertCode32(string sExp, params byte[] bytes)
        {
            var instr = Disassemble32(bytes);
            Assert.AreEqual(sExp, instr.ToString());
        }

        private X86Instruction AssertCode64(string sExp, params byte[] bytes)
        {
            var instr = Disassemble64(bytes);
            Assert.AreEqual(sExp, instr.ToString());
            return instr;
        }

        [SetUp]
        public void Setup()
        {
            options = null;
        }

        [Test]
        public void X86dis_Sequence()
        {
            X86TextAssembler asm = new X86TextAssembler(sc, new X86ArchitectureReal("x86-real-16"));
            var program = asm.AssembleFragment(
                Address.SegPtr(0xB96, 0),
                @"	mov	ax,0
	cwd
foo:
	lodsb	
	dec		cx
	jnz		foo
");

            CreateDisassembler16(program.SegmentMap.Segments.Values.First().MemoryArea);
            StringBuilder sb = new StringBuilder();
            foreach (var instr in dasm.Take(5))
            {
                Address addr = instr.Address;
                sb.AppendFormat("{0}\t{1}\r\n", addr, instr.ToString());
            }

            string s = sb.ToString();
            Assert.AreEqual(
                "0B96:0000\tmov\tax,0000\r\n" +
                "0B96:0003\tcwd\r\n" +
                "0B96:0004\tlodsb\r\n" +
                "0B96:0005\tdec\tcx\r\n" +
                "0B96:0006\tjnz\t0004\r\n",
                s);
        }

        [Test]
        public void SegmentOverrides()
        {
            X86TextAssembler asm = new X86TextAssembler(sc, new X86ArchitectureReal("x86-real-16"));
            var program = asm.AssembleFragment(
                Address.SegPtr(0xB96, 0),
                "foo	proc\r\n" +
                "		mov	bx,[bp+4]\r\n" +
                "		mov	ax,[bx+4]\r\n" +
                "		mov cx,cs:[si+4]\r\n");

            CreateDisassembler16(program.SegmentMap.Segments.Values.First().MemoryArea);
            X86Instruction[] instrs = dasm.Take(3).ToArray();
            Assert.AreEqual(Registers.ss, ((MemoryOperand)instrs[0].op2).DefaultSegment);
            Assert.AreEqual(Registers.ds, ((MemoryOperand)instrs[1].op2).DefaultSegment);
            Assert.AreEqual(Registers.cs, ((MemoryOperand)instrs[2].op2).DefaultSegment);
        }

        [Test]
        public void Rotations()
        {
            X86TextAssembler asm = new X86TextAssembler(sc, new X86ArchitectureReal("x86-real-16"));
            var lr = asm.AssembleFragment(
                Address.SegPtr(0xB96, 0),
                "foo	proc\r\n" +
                "rol	ax,cl\r\n" +
                "ror	word ptr [bx+2],cl\r\n" +
                "rcr	word ptr [bp+4],4\r\n" +
                "rcl	ax,1\r\n");

            MemoryArea img = lr.SegmentMap.Segments.Values.First().MemoryArea;
            CreateDisassembler16(img.CreateLeReader(img.BaseAddress));
            StringBuilder sb = new StringBuilder();
            foreach (var instr in dasm.Take(4))
            {
                sb.AppendFormat("{0}\r\n", instr.ToString());
            }
            string s = sb.ToString();
            Assert.AreEqual(
                "rol\tax,cl\r\n" +
                "ror\tword ptr [bx+02],cl\r\n" +
                "rcr\tword ptr [bp+04],04\r\n" +
                "rcl\tax,01\r\n", s);
        }

        [Test]
        public void Extensions()
        {
            X86TextAssembler asm = new X86TextAssembler(sc, new X86ArchitectureReal("x86-real-16"));
            var program = asm.AssembleFragment(
                Address.SegPtr(0xA14, 0),
@"		.i86
foo		proc
		movsx	ecx,word ptr [bp+8]
		movzx   edx,cl
		movsx	ebx,bx
		movzx	ax,byte ptr [bp+04]
");
            CreateDisassembler16(program.SegmentMap.Segments.Values.First().MemoryArea);
            StringBuilder sb = new StringBuilder();
            foreach (var ii in dasm.Take(4))
            {
                sb.AppendLine(string.Format("{0}", ii.ToString()));
            }
            string s = sb.ToString();
            Assert.AreEqual(
@"movsx	ecx,word ptr [bp+08]
movzx	edx,cl
movsx	ebx,bx
movzx	ax,byte ptr [bp+04]
", s);
        }

        private X86Instruction DisEnumerator_TakeNext(System.Collections.Generic.IEnumerator<X86Instruction> e)
        {
            e.MoveNext();
            return e.Current;
        }

        [Test]
        public void Dis_x86_InvalidKeptStateRegression()
        {
            X86TextAssembler asm = new X86TextAssembler(sc, new X86ArchitectureFlat32("x86-protected-32"));
            var lr = asm.AssembleFragment(
                Address.Ptr32(0x01001000),

                "db 0xf2, 0x0f, 0x70, 0x00, 0x00\r\n" +
                "db 0xf3, 0x0f, 0x70, 0x00, 0x00\r\n");

            /* Before (incorrect):
             *  pshuflw xmm0, dqword ptr ds:[eax], 0
             *  pshuflw xmm0, dqword ptr ds:[eax], 0
             *  
             *  
             * After (correct):
             *  pshuflw xmm0, dqword ptr ds:[eax], 0
             *  pshufhw xmm0, dqword ptr ds:[eax], 0
             */

            MemoryArea img = lr.SegmentMap.Segments.Values.First().MemoryArea;
            CreateDisassembler32(img);
            var instructions = dasm.GetEnumerator();

            X86Instruction one = DisEnumerator_TakeNext(instructions);
            X86Instruction two = DisEnumerator_TakeNext(instructions);

            Assert.AreEqual(Opcode.pshuflw, one.code);
            Assert.AreEqual("xmm0", one.op1.ToString());
            Assert.AreEqual("[eax]", one.op2.ToString());

            Assert.AreEqual(Opcode.pshufhw, two.code);
            Assert.AreEqual("xmm0", two.op1.ToString());
            Assert.AreEqual("[eax]", two.op2.ToString());
        }

        [Test]
        public void DisEdiTimes2()
        {
            X86TextAssembler asm = new X86TextAssembler(sc, new X86ArchitectureFlat32("x86-protected-32"));
            var program = asm.AssembleFragment(Address.SegPtr(0x0B00, 0),
                @"	.i386
	mov ebx,[edi*2]
");
            CreateDisassembler32(program.SegmentMap.Segments.Values.First().MemoryArea);
            var instr = dasm.First();
            MemoryOperand mem = (MemoryOperand)instr.op2;
            Assert.AreEqual(2, mem.Scale);
            Assert.AreEqual(RegisterStorage.None, mem.Base);
            Assert.AreEqual(Registers.edi, mem.Index);
        }

        [Test]
        public void DisFpuInstructions()
        {
            using (FileUnitTester fut = new FileUnitTester("Intel/DisFpuInstructions.txt"))
            {
                X86TextAssembler asm = new X86TextAssembler(sc, new X86ArchitectureReal("x86-real-16"));
                Program lr;
                using (var rdr = new StreamReader(FileUnitTester.MapTestPath("Fragments/fpuops.asm")))
                {
                    lr = asm.Assemble(Address.SegPtr(0xC32, 0), rdr);
                }
                CreateDisassembler16(lr.SegmentMap.Segments.Values.First().MemoryArea);
                foreach (X86Instruction instr in dasm)
                {
                    fut.TextWriter.WriteLine("{0}", instr.ToString());
                }
                fut.AssertFilesEqual();
            }
        }

        [Test]
        public void DisSignedByte()
        {
            var instr = Disassemble16(0x83, 0xC6, 0x1);  // add si,+01
            Assert.AreEqual("add\tsi,01", instr.ToString());
            Assert.AreEqual(PrimitiveType.Word16, instr.op1.Width);
            Assert.AreEqual(PrimitiveType.Byte, instr.op2.Width);
            Assert.AreEqual(PrimitiveType.Word16, instr.dataWidth);
        }

        [Test]
        public void DisLesBxStackArg()
        {
            var instr = Disassemble16(0xC4, 0x5E, 0x6);		// les bx,[bp+06]
            Assert.AreEqual("les\tbx,[bp+06]", instr.ToString());
            Assert.AreSame(PrimitiveType.Ptr32, instr.op2.Width);
        }

        [Test]
        public void SegFromBits()
        {
            Assert.AreSame(Registers.es, X86Disassembler.SegFromBits(0));
            Assert.AreSame(Registers.cs, X86Disassembler.SegFromBits(1));
            Assert.AreSame(Registers.ss, X86Disassembler.SegFromBits(2));
            Assert.AreSame(Registers.ds, X86Disassembler.SegFromBits(3));
            Assert.AreSame(Registers.fs, X86Disassembler.SegFromBits(4));
            Assert.AreSame(Registers.gs, X86Disassembler.SegFromBits(5));
        }

        [Test]
        public void X86dis_bswap()
        {
            var instr = Disassemble32(0x0F, 0xC8); ;		// bswap eax
            Assert.AreEqual("bswap\teax", instr.ToString());
            instr = Disassemble32(0x0F, 0xCF);       //  bswap edi
            Assert.AreEqual("bswap\tedi", instr.ToString());
        }

        [Test]
        public void X86dis_RelocatedOperand()
        {
            byte[] image = new byte[] { 0xB8, 0x78, 0x56, 0x34, 0x12 };	// mov eax,0x12345678
            MemoryArea img = new MemoryArea(Address.Ptr32(0x00100000), image);
            img.Relocations.AddPointerReference(0x00100001ul - img.BaseAddress.ToLinear(), 0x12345678);
            EndianImageReader rdr = img.CreateLeReader(img.BaseAddress);
            X86Disassembler dasm = new X86Disassembler(
                ProcessorMode.Protected32,
                rdr,
                PrimitiveType.Word32,
                PrimitiveType.Word32,
                false);
            X86Instruction instr = dasm.First();
            Assert.AreEqual("mov\teax,12345678", instr.ToString());
            Assert.AreEqual("ptr32", instr.op2.Width.ToString());
        }

        [Test]
        public void X86Dis_RelocatedSegment()
        {
            byte[] image = new byte[] { 0x2E, 0xC7, 0x06, 0x01, 0x00, 0x00, 0x08 }; // mov cs:[0001],0800
            MemoryArea img = new MemoryArea(Address.SegPtr(0x900, 0), image);
            img.Relocations.AddSegmentReference(5, 0x0800);
            EndianImageReader rdr = img.CreateLeReader(img.BaseAddress);
            CreateDisassembler16(rdr);
            X86Instruction instr = dasm.First();
            Assert.AreEqual("mov\tword ptr cs:[0001],0800", instr.ToString());
            Assert.AreEqual("selector", instr.op2.Width.ToString());
        }

        [Test]
        public void X86dis_TestWithImmediateOperands()
        {
            var instr = Disassemble16(0xF6, 0x06, 0x26, 0x54, 0x01);     // test byte ptr [5426],01
            Assert.AreEqual("test\tbyte ptr [5426],01", instr.ToString());
            Assert.AreSame(PrimitiveType.Byte, instr.op1.Width);
            Assert.AreSame(PrimitiveType.Byte, instr.op2.Width);
            Assert.AreSame(PrimitiveType.Byte, instr.dataWidth, "Instruction data width should be byte");
        }

        [Test]
        public void X86dis_RelativeCallTest()
        {
            var instr = Disassemble16(0xE8, 0x00, 0xF0);
            Assert.AreEqual("call\tF003", instr.ToString());
            Assert.AreSame(PrimitiveType.Word16, instr.op1.Width);
        }

        [Test]
        public void X86dis_farCall()
        {
            var instr = Disassemble16(0x9A, 0x78, 0x56, 0x34, 0x12, 0x90, 0x90);
            Assert.AreEqual("call\tfar 1234:5678", instr.ToString());
        }

        [Test]
        public void X86dis_Xlat16()
        {
            var instr = Disassemble16(0xD7);
            Assert.AreEqual("xlat", instr.ToString());
            Assert.AreEqual(PrimitiveType.Byte, instr.dataWidth);
            Assert.AreEqual(PrimitiveType.Word16, instr.addrWidth);
        }

        [Test]
        public void X86Dis_xlat32()
        {
            var instr = Disassemble32(0xD7);
            Assert.AreEqual("xlat", instr.ToString());
            Assert.AreEqual(PrimitiveType.Byte, instr.dataWidth);
            Assert.AreEqual(PrimitiveType.Word32, instr.addrWidth);
        }

        [Test]
        public void X86dis_hlt()
        {
            var instr = Disassemble16(0xF4);
            Assert.AreEqual("hlt", instr.ToString());
        }

        [Test]
        public void Dis_X86_64_rexW()
        {
            var instr = Disassemble64(0x48, 0x8D, 0x54, 0x24, 0x20);
            Assert.AreEqual("lea\trdx,[rsp+20]", instr.ToString());
        }

        [Test]
        public void Dis_X86_64_rexWR()
        {
            var instr = Disassemble64(0x4C, 0x8D, 0x54, 0x24, 0x20);
            Assert.AreEqual("lea\tr10,[rsp+20]", instr.ToString());
        }

        [Test]
        public void Dis_X86_64_rexWB()
        {
            var instr = Disassemble64(0x49, 0x8D, 0x54, 0x24, 0x20);
            Assert.AreEqual("lea\trdx,[r12+20]", instr.ToString());
        }

        [Test]
        public void Dis_X86_64_rexR()
        {
            var instr = Disassemble64(0x44, 0x33, 0xC0);
            Assert.AreEqual("xor\tr8d,eax", instr.ToString());
        }

        [Test]
        public void Dis_X86_64_rexRB()
        {
            var instr = Disassemble64(0x45, 0x33, 0xC0);
            Assert.AreEqual("xor\tr8d,r8d", instr.ToString());
        }

        [Test]
        public void Dis_x86_64_rexB_bytesize()
        {
            var instr = Disassemble64(0x41, 0x30, 0xC0);
            Assert.AreEqual("xor\tr8b,al", instr.ToString());
        }

        [Test]
        public void Dis_x86_64_rexR_bytesize_sil()
        {
            var instr = Disassemble64(0x44, 0x30, 0xC6);
            Assert.AreEqual("xor\tsil,r8b", instr.ToString());
        }

        [Test]
        public void Dis_x86_64_rexB_wordsize()
        {
            var instr = Disassemble64(0x66, 0x41, 0x33, 0xC6);
            Assert.AreEqual("xor\tax,r14w", instr.ToString());
        }

        [Test]
        public void Dis_x86_64_movaps()
        {
            var instr = Disassemble64(0x0f, 0x28, 0x44, 0x24, 0x20);
            Assert.AreEqual("movaps\txmm0,[rsp+20]", instr.ToString());
        }

        [Test]
        public void Dis_x86_64_movdqa()
        {
            var instr = Disassemble64(0x66, 0x0f, 0x7f, 0x44, 0x24, 0x20);
            Assert.AreEqual("movdqa\t[rsp+20],xmm0", instr.ToString());
        }

        [Test]
        public void Dis_x86_cmovnz()
        {
            var instr = Disassemble32(0x0F, 0x45, 0xC1);
            Assert.AreEqual("cmovnz\teax,ecx", instr.ToString());
        }

        [Test]
        public void Dis_x86_pxor()
        {
            var instr = Disassemble32(0x0F, 0xEF, 0xC1);
            Assert.AreEqual("pxor\tmm0,mm1", instr.ToString());
        }

        [Test]
        public void Dis_x86_Cmpxchg()
        {
            var instr = Disassemble32(0x0f, 0xb1, 0x0a, 0x85, 0xc0, 0x0f, 0x85, 0xdc);
            Assert.AreEqual("cmpxchg\t[edx],ecx", instr.ToString());
        }

        [Test]
        public void Dis_x86_Xadd()
        {
            var instr = Disassemble32(0x0f, 0xC1, 0xC2);
            Assert.AreEqual("xadd\tedx,eax", instr.ToString());
        }

        [Test]
        public void Dis_x86_cvttsd2si()
        {
            var instr = Disassemble32(0xF2, 0x0F, 0x2C, 0xC3);
            Assert.AreEqual("cvttsd2si\teax,xmm3", instr.ToString());
        }

        [Test]
        public void Dis_x86_fucompp()
        {
            var instr = Disassemble32(0xDA, 0xE9);
            Assert.AreEqual("fucompp", instr.ToString());
        }

        [Test]
        public void Dis_x86_Call32()
        {
            var instr = Disassemble32(0xE9, 0x78, 0x56, 0x34, 012);
            var addrOp = (AddressOperand)instr.op1;
            Assert.AreEqual("0C35567D", addrOp.ToString());
        }

        [Test]
        public void Dis_x86_Call16()
        {
            var instr = Disassemble16(0xE9, 0x78, 0x56);
            var addrOp = (ImmediateOperand)instr.op1;
            Assert.AreEqual("567B", addrOp.ToString());
        }

        [Test]
        public void Dis_x86_DirectOperand32()
        {
            var instr = Disassemble32(0x8B, 0x15, 0x22, 0x33, 0x44, 0x55, 0x66);
            Assert.AreEqual("mov\tedx,[55443322]", instr.ToString());
            var memOp = (MemoryOperand)instr.op2;
            Assert.AreEqual("ptr32", memOp.Offset.DataType.ToString());
        }

        [Test]
        public void Dis_x86_DirectOperand16()
        {
            var instr = Disassemble16(0x8B, 0x16, 0x22, 0x33, 0x44);
            Assert.AreEqual("mov\tdx,[3322]", instr.ToString());
            var memOp = (MemoryOperand)instr.op2;
            Assert.AreEqual("word16", memOp.Offset.DataType.ToString());
        }

        [Test]
        public void Dis_x86_Movdqa()
        {
            var instr = Disassemble32(0x66, 0x0F, 0x6F, 0x06, 0x12, 0x34, 0x56);
            Assert.AreEqual("movdqa\txmm0,[esi]", instr.ToString());
        }
        //$TOD: copy only gives me n-1 bytes rathern than n. bytes
        //   0048D4A8 

        // 66 0F 6F 06                    f.o    
        [Test]
        public void Dis_x86_bts()
        {
            var instr = Disassemble32(0x0F, 0xAB, 0x04, 0x24, 0xEB);
            Assert.AreEqual("bts\t[esp],eax", instr.ToString());
        }

        [Test]
        public void Dis_x86_cpuid()
        {
            var instr = Disassemble32(0x0F, 0xA2);
            Assert.AreEqual("cpuid", instr.ToString());
        }

        [Test]
        public void Dis_x86_xgetbv()
        {
            var instr = Disassemble32(0x0F, 0x01, 0xD0);
            Assert.AreEqual("xgetbv", instr.ToString());
        }

        [Test]
        public void Dis_x86_rdtsc()
        {
            var instr = Disassemble32(0x0F, 0x31);
            Assert.AreEqual("rdtsc", instr.ToString());
        }

        [Test]
        public void Dis_x86_foo()
        {
            var instr = Disassemble32(0x0F, 0xBA, 0xF3, 0x00);
            Assert.AreEqual("btr\tebx,00", instr.ToString());
        }

        [Test]
        public void Dis_x86_movd_32()
        {
            AssertCode32("movd\tdword ptr [esi],mm1", 0x0F, 0x7E, 0x0E);
            AssertCode32("movd\tdword ptr [esi],xmm1", 0x66, 0x0F, 0x7E, 0x0E);
            AssertCode32("movq\txmm1,qword ptr [esi]", 0xF3, 0x0F, 0x7E, 0x0E);
            AssertCode32("movd\tesi,mm1", 0x0F, 0x7E, 0xCE);
            AssertCode32("movd\tesi,xmm1", 0x66, 0x0F, 0x7E, 0xCE);
            AssertCode32("movq\txmm1,xmm6", 0xF3, 0x0F, 0x7E, 0xCE);
        }

        [Test]
        public void Dis_x86_movd_64()
        {
            AssertCode64("movd\tdword ptr [rsi],mm1", 0x0F, 0x7E, 0x0E);
            AssertCode64("movd\tdword ptr [rsi],xmm1", 0x66, 0x0F, 0x7E, 0x0E);
            AssertCode64("movq\txmm1,qword ptr [rsi]", 0xF3, 0x0F, 0x7E, 0x0E);
            AssertCode64("movd\tesi,mm1", 0x0F, 0x7E, 0xCE);
            AssertCode64("movd\tesi,xmm1", 0x66, 0x0F, 0x7E, 0xCE);
            AssertCode64("movq\txmm1,xmm6", 0xF3, 0x0F, 0x7E, 0xCE);
        }

        [Test]
        public void Dis_x86_movd_64_rex()
        {
            AssertCode64("movq\t[rsi],mm1", 0x48, 0x0F, 0x7E, 0x0E);
            AssertCode64("movq\tqword ptr [rsi],xmm1", 0x66, 0x48, 0x0F, 0x7E, 0x0E);
            AssertCode64("movq\trsi,mm1", 0x48, 0x0F, 0x7E, 0xCE);
            AssertCode64("movq\trsi,xmm1", 0x66, 0x48, 0x0F, 0x7E, 0xCE);
        }

        [Test]
        public void Dis_x86_punpcklbw()
        {
            AssertCode32("punpcklbw\txmm1,xmm3", 0x66, 0x0f, 0x60, 0xcb);
        }

        [Test]
        public void Dis_x86_more2()
        {
            AssertCode32("movlhps\txmm3,xmm3", 0x0f, 0x16, 0xdb);
            AssertCode32("pshuflw\txmm3,xmm3,00", 0xf2, 0x0f, 0x70, 0xdb, 0x00);
        }

        [Test]
        public void X86dis_pcmpeqb()
        {
            AssertCode32("pcmpeqb\txmm0,[eax]", 0x66, 0x0f, 0x74, 0x00);
        }

        [Test]
        public void Dis_x86_more3()
        {
            AssertCode32("stmxcsr\tdword ptr [ebp-0C]", 0x0f, 0xae, 0x5d, 0xf4);
            AssertCode32("palignr\txmm3,xmm1,00", 0x66, 0x0f, 0x3a, 0x0f, 0xd9, 0x00);
            AssertCode32("movq\t[edi],xmm1", 0x66, 0x0f, 0xd6, 0x0f);
            AssertCode32("ldmxcsr\tdword ptr [ebp+08]", 0x0F, 0xAE, 0x55, 0x08);
            AssertCode32("pcmpistri\txmm0,[edi-10],40", 0x66, 0x0F, 0x3A, 0x63, 0x47, 0xF0, 0x40);
        }

        [Test]
        public void Dis_x86_64_movsxd()
        {
            AssertCode64("movsx\trcx,dword ptr [rax+3C]", 0x48, 0x63, 0x48, 0x3c);
        }

        [Test]
        public void Dis_x86_64_rip_relative()
        {
            AssertCode64("mov\trax,[rip+00100000]", 0x49, 0x8b, 0x05, 0x00, 0x00, 0x10, 0x00);
            AssertCode64("mov\trax,[rip+00100000]", 0x48, 0x8b, 0x05, 0x00, 0x00, 0x10, 0x00);
        }

        [Test]
        public void Dis_x86_64_sub_immediate_dword()
        {
            AssertCode64("sub\trsp,+00000508", 0x48, 0x81, 0xEC, 0x08, 0x05, 0x00, 0x00);
        }

        [Test]
        public void Dis_x86_nops()
        {
            AssertCode64("nop", 0x90);
            AssertCode64("nop", 0x66, 0x90);
            AssertCode64("nop\tdword ptr [rax]", 0x0F, 0x1F, 0x00);
            AssertCode64("nop\tdword ptr [rax+00]", 0x0F, 0x1F, 0x40, 0x00);
            AssertCode64("nop\tdword ptr [rax+rax+00]", 0x0F, 0x1F, 0x44, 0x00, 0x00);
            AssertCode64("nop\tword ptr [rax+rax+00]", 0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00);
            AssertCode64("nop\tdword ptr [rax+00000000]", 0x0F, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00);
            AssertCode64("nop\tdword ptr [rax+rax+00000000]", 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00);
            AssertCode64("nop\tword ptr [rax+rax+00000000]", 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00);
        }

        [Test]
        public void Dis_x86_rex_prefix_40()
        {
            AssertCode64("push\trbp", 0x40, 0x55);
        }

        [Test]
        public void Dis_x86_repz_ret()
        {
            AssertCode64("ret", 0xF3, 0xC3);
        }

        [Test]
        public void Dis_x86_emulate_x87_int_39()
        {
            options = new X86Options { Emulate8087 = true };
            CreateDisassembler16(0xCD, 0x39, 0x5E, 0xEA);
            var instrs = dasm.Take(2)
                .Select(i => i.ToString())
                .ToArray();
            Assert.AreEqual("nop", instrs[0]);
            Assert.AreEqual("fstp\tdouble ptr [bp-16]", instrs[1]);
        }

        [Test]
        public void Dis_x86_emulate_x87_int_3C()
        {
            options = new X86Options { Emulate8087 = true };
            CreateDisassembler16(0xCD, 0x3C, 0xDD, 0x06, 0x8B, 0x04);
            var instrs = dasm.Take(2)
                .Select(i => i.ToString())
                .ToArray();
            Assert.AreEqual("nop", instrs[0]);
            Assert.AreEqual("fld\tdouble ptr es:[048B]", instrs[1]);
        }

        [Test(Description = "Very large 32-bit offsets can be treated as negative offsets")]
        public void Dis_x86_LargeNegativeOffset()
        {
            AssertCode32("mov\tesi,[eax-0000FFF0]", 0x8B, 0xB0, 0x10, 0x00, 0xFF, 0xFF);
            AssertCode32("mov\tesi,[eax+FFFF0000]", 0x8B, 0xB0, 0x00, 0x00, 0xFF, 0xFF);
        }

        [Test]
        public void Dis_x86_StringOps()
        {
            X86TextAssembler asm = new X86TextAssembler(sc, new X86ArchitectureFlat32("x86-protected-32"));
            var lr = asm.AssembleFragment(
                Address.Ptr32(0x01001000),

                "movsb\r\n" +
                "movsw\r\n" +
                "movsd\r\n" +

                "scasb\r\n" +
                "scasw\r\n" +
                "scasd\r\n" +

                "cmpsb\r\n" +
                "cmpsw\r\n" +
                "cmpsd\r\n" +

                "lodsb\r\n" +
                "lodsw\r\n" +
                "lodsd\r\n" +

                "stosb\r\n" +
                "stosw\r\n" +
                "stosd\r\n");

            MemoryArea img = lr.SegmentMap.Segments.Values.First().MemoryArea;
            CreateDisassembler32(img);
            var instructions = dasm.GetEnumerator();

            List<X86Instruction> instr = new List<X86Instruction>();
            for (int i = 0; i < 5 * 3; i++)
            {
                instr.Add(DisEnumerator_TakeNext(instructions));
            }
            Assert.AreEqual(Opcode.movsb, instr[0].code);
            Assert.AreEqual(Opcode.movs, instr[1].code);
            Assert.AreEqual("word16", instr[1].dataWidth.Name);
            Assert.AreEqual(Opcode.movs, instr[2].code);
            Assert.AreEqual("word32", instr[2].dataWidth.Name);

            Assert.AreEqual(Opcode.scasb, instr[3].code);
            Assert.AreEqual(Opcode.scas, instr[4].code);
            Assert.AreEqual("word16", instr[4].dataWidth.Name);
            Assert.AreEqual(Opcode.scas, instr[5].code);
            Assert.AreEqual("word32", instr[5].dataWidth.Name);

            Assert.AreEqual(Opcode.cmpsb, instr[6].code);
            Assert.AreEqual(Opcode.cmps, instr[7].code);
            Assert.AreEqual("word16", instr[7].dataWidth.Name);
            Assert.AreEqual(Opcode.cmps, instr[8].code);
            Assert.AreEqual("word32", instr[8].dataWidth.Name);

            Assert.AreEqual(Opcode.lodsb, instr[9].code);
            Assert.AreEqual(Opcode.lods, instr[10].code);
            Assert.AreEqual("word16", instr[10].dataWidth.Name);
            Assert.AreEqual(Opcode.lods, instr[11].code);
            Assert.AreEqual("word32", instr[11].dataWidth.Name);

            Assert.AreEqual(Opcode.stosb, instr[12].code);
            Assert.AreEqual(Opcode.stos, instr[13].code);
            Assert.AreEqual("word16", instr[13].dataWidth.Name);
            Assert.AreEqual(Opcode.stos, instr[14].code);
            Assert.AreEqual("word32", instr[14].dataWidth.Name);
        }

        [Test]
        public void X86dis_regression()
        {
            AssertCode64("movups\t[rsp+20],xmm0", 0x0F, 0x11, 0x44, 0x24, 0x20);
        }

        [Test]
        public void X86dis_fucomi()
        {
            AssertCode32("fucomi\tst(0),st(3)", 0xDB, 0xEB);
        }

        [Test]
        public void X86dis_fucomip()
        {
            AssertCode32("fucomip\tst(0),st(1)", 0xDF, 0xE9);
        }

        [Test]
        public void X86dis_movups()
        {
            AssertCode64("movups\txmm0,[rbp-20]", 0x0F, 0x10, 0x45, 0xE0);
            AssertCode64("movupd\txmm0,[rbp-20]", 0x66, 0x0F, 0x10, 0x45, 0xE0);
            AssertCode64("movss\txmm0,dword ptr [rbp-20]", 0xF3, 0x0F, 0x10, 0x45, 0xE0);
            AssertCode64("movsd\txmm0,double ptr [rbp-20]", 0xF2, 0x0F, 0x10, 0x45, 0xE0);
        }

        [Test]
        public void X86dis_movups_16bit()
        {
            AssertCode16("movups\txmm7,xmm3", 0x0F, 0x10, 0xFB);
        }

        [Test]
        public void X86dis_ucomiss()
        {
            AssertCode64("ucomiss\txmm0,dword ptr [rip+0000B12D]", 0x0F, 0x2E, 0x05, 0x2D, 0xB1, 0x00, 0x00);
        }

        [Test]
        public void X86dis_ucomisd()
        {
            AssertCode64("ucomisd\txmm0,double ptr [rip+0000B12D]", 0x66, 0x0F, 0x2E, 0x05, 0x2D, 0xB1, 0x00, 0x00);
        }

        [Test]
        public void X86dis_addss()
        {
            AssertCode64("addss\txmm1,dword ptr [rip+0000B0FB]", 0xF3, 0x0F, 0x58, 0x0D, 0xFB, 0xB0, 0x00, 0x00);
        }

        [Test]
        public void X86dis_cvtsi2ss()
        {
            AssertCode64("cvtsi2ss\txmm0,rax", 0xF3, 0x48, 0x0F, 0x2A, 0xC0);
        }

        [Test]
        public void X86dis_out_dx()
        {
            AssertCode16("out\tdx,al", 0xEE);
            AssertCode16("out\tdx,ax", 0xEF);
        }

        [Test]
        public void X86dis_x64_push()
        {
            AssertCode64("push\tr15", 0x41, 0x57);
        }

        [Test]
        public void X86dis_x64_push_immediate()
        {
            AssertCode64("push\t42", 0x6A, 0x42);
        }

        [Test]
        public void X86dis_rep_prefix_to_ucomiss()
        {
            AssertCode32("illegal", 0xF2, 0x0F, 0x2E, 0x00);
        }

        [Test]
        public void X86dis_pause()
        {
            AssertCode32("pause", 0xF3, 0x90);
        }

        [Test]
        public void X86dis_mfence()
        {
            AssertCode32("mfence", 0x0F, 0xAE, 0xF0);
        }

        [Test]
        public void X86dis_lfence()
        {
            AssertCode32("lfence", 0x0F, 0xAE, 0xE8);
        }

        [Test]
        public void X86dis_xorps()
        {
            AssertCode32("xorps\txmm0,xmm0", 0x0F, 0x57, 0xC0);
        }

        [Test]
        public void X86dis_xorpd()
        {
            AssertCode32("xorpd\txmm0,xmm0", 0x66, 0x0F, 0x57, 0xC0);
        }

        [Test]
        public void X86dis_aesimc()
        {
            AssertCode64("aesimc\txmm0,xmm0", 0x66, 0x0F, 0x38, 0xDB, 0xC0);
        }

        [Test]
        public void X86dis_vmovss()
        {
            AssertCode64("vmovss\txmm0,dword ptr [rip+00000351]", 0xC5, 0xFA, 0x10, 0x05, 0x51, 0x03, 0x00, 0x00);
        }

        [Test]
        public void X86dis_vcvtsi2ss()
        {
            AssertCode64("vcvtsi2ss\txmm0,xmm0,rax", 0xC4, 0xE1, 0xFA, 0x2A, 0xC0);
        }

        [Test]
        public void X86dis_vcvtsi2sd()
        {
            AssertCode64("vcvtsi2sd\txmm0,xmm0,rdx", 0xC4, 0xE1, 0xFB, 0x2A, 0xC2);
        }

        [Test]
        public void X86dis_call_Ev()
        {
            AssertCode64("call\trax", 0xFF, 0xD0);
        }

        [Test]
        public void X86dis_vaddsd()
        {
            AssertCode64("vaddsd\txmm0,xmm0,xmm0", 0xC5, 0xFB, 0x58, 0xC0);
        }

        [Test]
        public void X86dis_vmovapd()
        {
            AssertCode64("vmovapd\tymm1,[rax]", 0xC5, 0xFD, 0x28, 0x08);
        }

        [Test]
        public void X86dis_vmovaps()
        {
            AssertCode64("vmovaps\t[rcx+4D],xmm4", 0xC5, 0xF8, 0x29, 0x61, 0x4D);
        }

        [Test]
        public void X86dis_vmovsd()
        {
            AssertCode64("vmovsd\tdouble ptr [rcx],xmm0", 0xC5, 0xFB, 0x11, 0x01);
        }

        [Test]
        public void X86dis_vxorps()
        {
            AssertCode64("vxorpd\txmm0,xmm0,xmm0", 0xC5, 0xF9, 0x57, 0xC0);
        }

        [Test]
        public void X86dis_vaddpd()
        {
            AssertCode64("vaddpd\tymm0,ymm0,[rbp-00000090]", 0xC5, 0xFD, 0x58, 0x85, 0x70, 0xFF, 0xFF, 0xFF);
        }

        [Test]
        public void X86dis_64_lea()
        {
            AssertCode64("lea\trdi,[rip+000000DA]", 0x48, 0x8D, 0x3D, 0xDA, 0x00, 0x00, 0x00);
        }

        [Test]
        public void X86dis_vxorpd_256()
        {
            AssertCode64("vxorpd\tymm0,ymm0,ymm0", 0xC5, 0xFD, 0x57, 0xC0);
        }

        [Test]
        public void X86dis_vxorpd_mem_256()
        {
            AssertCode64("vxorpd\tymm1,ymm0,[rcx]", 0xC5, 0xFD, 0x57, 0x09);
        }

        [Test]
        public void X86dis_lar()
        {
            AssertCode32("lar\teax,word ptr [edx+42]", 0x0F, 0x02, 0x42, 0x42);
        }


        [Test]
        public void X86dis_lsl()
        {
            AssertCode32("lsl\teax,word ptr [edx+42]", 0x0F, 0x03, 0x42, 0x42);
        }


        [Test]
        public void X86dis_syscall()
        {
            AssertCode64("syscall", 0x0F, 0x05, 0x42, 0x42);
            AssertCode32("illegal", 0x0F, 0x05, 0x42, 0x42);
        }

        // o64
        [Test]
        public void X86dis_clts()
        {
            AssertCode32("clts", 0x0F, 0x06);
        }


        [Test]
        public void X86dis_sysret()
        {
            AssertCode64("sysret", 0x0F, 0x07);
            AssertCode32("illegal", 0x0F, 0x07);
        }

        // o64
        [Test]
        public void X86dis_invd()
        {
            AssertCode32("invd", 0x0F, 0x08);
        }

        [Test]
        public void X86dis_wbinvd()
        {
            AssertCode32("wbinvd", 0x0F, 0x09);
        }


        [Test]
        public void X86dis_ud2()
        {
            AssertCode32("ud2", 0x0F, 0x0B);
        }


        [Test]
        public void X86dis_prefetch()
        {
            AssertCode32("prefetchw\tdword ptr [edx+42]", 0x0F, 0x0D, 0x42, 0x42);
        }

        // /1
        [Test]
        public void X86dis_movlps()
        {
            AssertCode32("movlps\txmm0,qword ptr [edx+42]", 0x0F, 0x12, 0x42, 0x42);
        }


        [Test]
        public void X86dis_unpcklpd()
        {
            AssertCode32("unpcklps\txmm0,[edx+42]", 0x0F, 0x14, 0x42, 0x42);
            AssertCode32("unpcklpd\txmm0,[edx+42]", 0x66, 0x0F, 0x14, 0x42, 0x42);
        }


        [Test]
        public void X86dis_movhpd()
        {
            AssertCode32("movhps\tqword ptr [edx+42],xmm0", 0x0F, 0x17, 0x42, 0x42);
            AssertCode32("movhpd\tqword ptr [edx+42],xmm0", 0x66, 0x0F, 0x17, 0x42, 0x42);
        }

        [Test]
        public void X86dis_mov_from_control_Reg()
        {
            AssertCode32("mov\tedx,cr0", 0x0F, 0x20, 0x42, 0x42);
        }

        [Test]
        public void X86dis_mov_debug_reg()
        {
            AssertCode32("mov\tedx,dr0", 0x0F, 0x21, 0x42, 0x42);
        }

        [Test]
        public void X86dis_mov_control_reg()
        {
            AssertCode32("mov\tcr0,edx", 0x0F, 0x22, 0x42);
        }

        [Test]
        public void X86dis_mov_to_debug_reg()
        {
            AssertCode32("mov\tdr0,edx", 0x0F, 0x23, 0x42);
        }


        [Test]
        public void X86dis_movntps()
        {
            AssertCode32("movntps\t[edx+42],xmm0", 0x0F, 0x2B, 0x42, 0x42);
        }

        [Test]
        public void X86dis_cvttps2pi()
        {
            AssertCode32("cvtps2pi\tmm0,xmmword ptr [edx+42]", 0x0F, 0x2D, 0x42, 0x42);
        }

        [Test]
        public void X86dis_comiss()
        {
            AssertCode32("comiss\txmm0,dword ptr [edx+42]", 0x0F, 0x2F, 0x42, 0x42);
        }

        [Test]
        public void X86dis_wrmsr()
        {
            AssertCode32("wrmsr", 0x0F, 0x30, 0x42, 0x42);
        }

        [Test]
        public void X86dis_rdtsc()
        {
            AssertCode32("rdtsc", 0x0F, 0x31, 0x42, 0x42);
        }

        [Test]
        public void X86dis_rdmsr()
        {
            AssertCode32("rdmsr", 0x0F, 0x32, 0x42, 0x42);
        }

        [Test]
        public void X86dis_rdpmc()
        {
            AssertCode32("rdpmc", 0x0F, 0x33, 0x42, 0x42);
        }

        [Test]
        public void X86dis_sysenter()
        {
            AssertCode32("sysenter", 0x0F, 0x34, 0x42, 0x42);
        }

        [Test]
        public void X86dis_sysexit()
        {
            AssertCode32("sysexit", 0x0F, 0x35, 0x42, 0x42);
        }

        [Test]
        public void X86dis_getsec()
        {
            AssertCode32("getsec", 0x0F, 0x37, 0x42, 0x42);
        }

        [Test]
        public void X86dis_vpmovsxbw()
        {
            AssertCode32("illegal", 0x0F, 0x38, 0x30, 0x42, 0x42);
            AssertCode32("vpmovsxbw\txmm0,qword ptr [edx+42]", 0x66, 0x0F, 0x38, 0x30, 0x42, 0x42);
        }


        [Test]
        public void X86dis_permq()
        {
            AssertCode32("illegal", 0x0F, 0x3A, 0x00, 0x42, 0x42);
            AssertCode32("vpermq\tymm0,[edx+42],06", 0x66, 0x0F, 0x3A, 0x00, 0x42, 0x42, 0x6);
        }

        // v
        [Test]
        public void X86dis_movmskps()
        {
            AssertCode32("movmskps\teax,xmm2", 0x0F, 0x50, 0x42, 0x42);
        }

        [Test]
        public void X86dis_sqrtps()
        {
            AssertCode32("sqrtps\txmm0,[edx+42]", 0x0F, 0x51, 0x42, 0x42);
        }

        [Test]
        public void X86dis_rsqrtps()
        {
            AssertCode32("rsqrtps\txmm0,[edx+42]", 0x0F, 0x52, 0x42, 0x42);
        }

        [Test]
        public void X86dis_rcpps()
        {
            AssertCode32("rcpps\txmm0,[edx+42]", 0x0F, 0x53, 0x42, 0x42);
        }

        [Test]
        public void X86dis_andps()
        {
            AssertCode32("andps\txmm0,[edx+42]", 0x0F, 0x54, 0x42, 0x42);
        }

        [Test]
        public void X86dis_andnps()
        {
            AssertCode32("andnps\txmm0,[edx+42]", 0x0F, 0x55, 0x42, 0x42);
        }

        [Test]
        public void X86dis_orps()
        {
            AssertCode32("orps\txmm0,[edx+42]", 0x0F, 0x56, 0x42, 0x42);
        }

        [Test]
        public void X86dis_cvtps2pd()
        {
            AssertCode32("cvtps2pd\txmm0,[edx+42]", 0x0F, 0x5A, 0x42, 0x42);
        }

        [Test]
        public void X86dis_cvtdq2ps()
        {
            AssertCode32("cvtdq2ps\txmm0,[edx+42]", 0x0F, 0x5B, 0x42, 0x42);
        }

        [Test]
        public void X86dis_minps()
        {
            AssertCode32("minps\txmm0,[edx+42]", 0x0F, 0x5D, 0x42, 0x42);
        }

        [Test]
        public void X86dis_punpckldq()
        {
            AssertCode32("punpckldq\tmm0,dword ptr [edx+42]", 0x0F, 0x62, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pcmpgtb()
        {
            AssertCode32("pcmpgtb\tmm0,dword ptr [edx+42]", 0x0F, 0x64, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pcmpgtw()
        {
            AssertCode32("pcmpgtw\tmm0,dword ptr [edx+42]", 0x0F, 0x65, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pcmpgtd()
        {
            AssertCode32("pcmpgtd\tmm0,dword ptr [edx+42]", 0x0F, 0x66, 0x42, 0x42);
        }

        [Test]
        public void X86dis_packuswb()
        {
            AssertCode32("packuswb\tmm0,dword ptr [edx+42]", 0x0F, 0x67, 0x42, 0x42);
        }

        [Test]
        public void X86dis_punpckhbw()
        {
            AssertCode32("punpckhbw\tmm0,dword ptr [edx+42]", 0x0F, 0x68, 0x42, 0x42);
        }

        [Test]
        public void X86dis_punpckhwd()
        {
            AssertCode32("punpckhwd\tmm0,dword ptr [edx+42]", 0x0F, 0x69, 0x42, 0x42);
        }

        [Test]
        public void X86dis_punpckhdq()
        {
            AssertCode32("punpckhdq\tmm0,dword ptr [edx+42]", 0x0F, 0x6A, 0x42, 0x42);
        }

        [Test]
        public void X86dis_packssdw()
        {
            AssertCode32("packssdw\tmm0,dword ptr [edx+42]", 0x0F, 0x6B, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pcmpeqw()
        {
            AssertCode32("pcmpeqw\tmm0,[edx+42]", 0x0F, 0x75, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pcmpeqd()
        {
            AssertCode32("pcmpeqd\tmm0,[edx+42]", 0x0F, 0x76, 0x42, 0x42);
        }

        [Test]
        public void X86dis_emms()
        {
            AssertCode32("emms", 0x0F, 0x77);
        }

        // /v
        [Test]
        public void X86dis_vmread()
        {
            AssertCode32("vmread\t[edx+42],eax", 0x0F, 0x78, 0x42, 0x42);
        }


        [Test]
        public void X86dis_vmwrite()
        {
            AssertCode32("vmwrite\teax,[edx+42]", 0x0F, 0x79, 0x42, 0x42);
        }

        [Test]
        public void X86dis_btc()
        {
            AssertCode32("btc\teax,[edx+42]", 0x0F, 0xBB, 0x42, 0x42);
        }


        [Test]
        public void X86dis_bsf()
        {
            AssertCode32("bsf\teax,[edx+42]", 0x0F, 0xBC, 0x42, 0x42);
        }

        [Test]
        public void X86dis_cmpps()
        {
            AssertCode32("cmpps\txmm0,[edx+42],08", 0x0F, 0xC2, 0x42, 0x42, 0x08);
        }

        [Test]
        public void X86dis_movnti()
        {
            AssertCode32("movnti\t[edx+42],eax", 0x0F, 0xC3, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pinsrw()
        {
            //$TODO check encoding; look in the Intel spec.
            AssertCode32("pinsrw\tmm0,edx", 0x0F, 0xC4, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pextrw()
        {
            AssertCode32("pextrw\teax,mm2,42", 0x0F, 0xC5, 0x42, 0x42);
        }

        [Test]
        public void X86dis_vshufps()
        {
            AssertCode32("vshufps\txmm0,[edx+42],07", 0x0F, 0xC6, 0x42, 0x42, 0x7);
        }

        [Test]
        public void X86dis_psrlq()
        {
            AssertCode32("psrlq\tmm0,[edx+42]", 0x0F, 0xD3, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pmullw()
        {
            AssertCode32("pmullw\tmm0,[edx+42]", 0x0F, 0xD5, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pmovmskb()
        {
            AssertCode32("pmovmskb\teax,mm2", 0x0F, 0xD7, 0x42);
        }

        [Test]
        public void X86dis_psubusb()
        {
            AssertCode32("psubusb\tmm0,[edx+42]", 0x0F, 0xD8, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pminub()
        {
            AssertCode32("pminub\tmm0,[edx+42]", 0x0F, 0xDA, 0x42, 0x42);
        }

        [Test]
        public void X86dis_paddusb()
        {
            AssertCode32("paddusb\tmm0,[edx+42]", 0x0F, 0xDC, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pmaxub()
        {
            AssertCode32("pmaxub\tmm0,[edx+42]", 0x0F, 0xDE, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pavgb()
        {
            AssertCode32("pavgb\tmm0,[edx+42]", 0x0F, 0xE0, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psraw()
        {
            AssertCode32("psraw\tmm0,[edx+42]", 0x0F, 0xE1, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psrad()
        {
            AssertCode32("psrad\tmm0,[edx+42]", 0x0F, 0xE2, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pmulhuw()
        {
            AssertCode32("pmulhuw\tmm0,[edx+42]", 0x0F, 0xE4, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pmulhw()
        {
            AssertCode32("pmulhw\tmm0,[edx+42]", 0x0F, 0xE5, 0x42, 0x42);
        }

        [Test]
        public void X86dis_movntq()
        {
            AssertCode32("movntq\t[edx+42],mm0", 0x0F, 0xE7, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psubsb()
        {
            AssertCode32("psubsb\tmm0,[edx+42]", 0x0F, 0xE8, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psubsw()
        {
            AssertCode32("psubsw\tmm0,[edx+42]", 0x0F, 0xE9, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pminsw()
        {
            AssertCode32("pminsw\tmm0,[edx+42]", 0x0F, 0xEA, 0x42, 0x42);
        }

        [Test]
        public void X86dis_por()
        {
            AssertCode32("por\tmm0,[edx+42]", 0x0F, 0xEB, 0x42, 0x42);
        }

        [Test]
        public void X86dis_paddsb()
        {
            AssertCode32("paddsb\tmm0,[edx+42]", 0x0F, 0xEC, 0x42, 0x42);
        }

        [Test]
        public void X86dis_paddsw()
        {
            AssertCode32("paddsw\tmm0,[edx+42]", 0x0F, 0xED, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pmaxsw()
        {
            AssertCode32("pmaxsw\tmm0,[edx+42]", 0x0F, 0xEE, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pxor()
        {
            AssertCode32("pxor\tmm0,[edx+42]", 0x0F, 0xEF, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psllw()
        {
            AssertCode32("psllw\tmm0,[edx+42]", 0x0F, 0xF1, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pslld()
        {
            AssertCode32("pslld\tmm0,[edx+42]", 0x0F, 0xF2, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psllq()
        {
            AssertCode32("psllq\tmm0,[edx+42]", 0x0F, 0xF3, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pmuludq()
        {
            AssertCode32("pmuludq\tmm0,[edx+42]", 0x0F, 0xF4, 0x42, 0x42);
        }

        [Test]
        public void X86dis_pmaddwd()
        {
            AssertCode32("pmaddwd\tmm0,[edx+42]", 0x0F, 0xF5, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psadbw()
        {
            AssertCode32("psadbw\tmm0,[edx+42]", 0x0F, 0xF6, 0x42, 0x42);
        }

        [Test]
        public void X86dis_maskmovq()
        {
            AssertCode32("maskmovq\tmm0,[edx+42]", 0x0F, 0xF7, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psubb()
        {
            AssertCode32("psubb\tmm0,[edx+42]", 0x0F, 0xF8, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psubw()
        {
            AssertCode32("psubw\tmm0,[edx+42]", 0x0F, 0xF9, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psubd()
        {
            AssertCode32("psubd\tmm0,[edx+42]", 0x0F, 0xFA, 0x42, 0x42);
        }

        [Test]
        public void X86dis_psubq()
        {
            AssertCode32("psubq\tmm0,[edx+42]", 0x0F, 0xFB, 0x42, 0x42);
        }

        [Test]
        public void X86dis_paddb()
        {
            AssertCode32("paddb\tmm0,[edx+42]", 0x0F, 0xFC, 0x42, 0x42);
        }

        [Test]
        public void X86dis_paddw()
        {
            AssertCode32("paddw\tmm0,[edx+42]", 0x0F, 0xFD, 0x42, 0x42);
        }

        [Test]
        public void X86dis_paddd()
        {
            AssertCode32("paddd\tmm0,[edx+42]", 0x0F, 0xFE, 0x42, 0x42);
        }

        [Test]
        public void X86dis_fcmovb()
        {
            AssertCode32("fcmovb\tst(0),st(1)", 0xDA, 0xC1);
        }

        [Test]
        public void X86dis_fcmove()
        {
            AssertCode32("fcmove\tst(0),st(1)", 0xDA, 0xC9);
        }

        [Test]
        public void X86dis_fcmovbe()
        {
            AssertCode32("fcmovbe\tst(0),st(1)", 0xDA, 0xD1);
        }

        [Test]
        public void X86dis_fcmovu()
        {
            AssertCode32("fcmovu\tst(0),st(1)", 0xDA, 0xD9);
        }

        [Test]
        public void X86dis_fucompp()
        {
            AssertCode32("fucompp", 0xDA, 0xE9);
        }

        [Test]
        public void X86dis_fisttp()
        {
            AssertCode32("fisttp\tdword ptr [eax]", 0xDB, 0x08);
        }

        [Test]
        public void X86dis_fld_real80()
        {
            AssertCode32("fld\ttword ptr [eax]", 0xDB, 0x28);
        }

        [Test]
        public void X86dis_fcmovne()
        {
            AssertCode32("fcmovne\tst(0),st(1)", 0xDB, 0xC9);
        }

        [Test]
        public void X86dis_fcmovnbe()
        {
            AssertCode32("fcmovnbe\tst(0),st(1)", 0xDB, 0xD1);
        }

        [Test]
        public void X86dis_fcmovnu()
        {
            AssertCode32("fcmovnu\tst(0),st(1)", 0xDB, 0xD9);
        }

        [Test]
        public void X86dis_fclex()
        {
            AssertCode32("fclex", 0xDB, 0xE2);
        }

        [Test]
        public void X86dis_finit()
        {
            AssertCode32("fninit", 0xDB, 0xE3);
        }


        [Test]
        public void X86dis_fisttp_i64()
        {
            AssertCode32("fisttp\tqword ptr [eax+42]", 0xDD, 0x48, 0x42);
        }


        [Test]
        public void X86dis_ffree()
        {
            AssertCode32("ffree\tst(2)", 0xDD, 0xC2);
        }


        [Test]
        public void X86dis_fucom()
        {
            AssertCode32("fucom\tst(5),st(0)", 0xDD, 0xE5);
        }

        [Test]
        public void X86dis_fucomp()
        {
            AssertCode32("fucomp\tst(2)", 0xDD, 0xEA);
        }

        [Test]
        public void X86dis_fisttp_int16()
        {
            AssertCode32("fisttp\tword ptr [eax+42]", 0xDF, 0x48, 0x42);
        }

        [Test]
        public void X86dis_fild_i16()
        {
            AssertCode32("fild\tword ptr [eax+42]", 0xDF, 0x40, 0x42);
        }

        [Test]
        public void X86dis_fcomip()
        {
            AssertCode32("fcomip\tst(0),st(2)", 0xDF, 0xF2);
        }

        //0x0F, 0xC7,       // grp9
        //0x0F, 0xD0, 
    }
}


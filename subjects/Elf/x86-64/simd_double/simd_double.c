// simd_double.c
// Generated by decompiling simd_double
// using Reko decompiler version 0.8.0.0.

#include "simd_double.h"

// 00000000000005A0: void _init()
void _init()
{
	word64 rax_4 = globals->qw200FE8;
	if (rax_4 != 0x00)
	{
		word64 rsp_15;
		byte SCZO_16;
		word64 rax_17;
		byte SZO_18;
		bool C_19;
		bool Z_20;
		__gmon_start__();
	}
}

// 0000000000000620: void _start(Register (ptr64 Eq_17) rdx, Stack Eq_18 qwArg00)
void _start( * rdx, Eq_18 qwArg00)
{
	__align((char *) fp + 0x08);
	__libc_start_main(&globals->t0898, qwArg00, (char *) fp + 0x08, &globals->t0A70, &globals->t0AE0, rdx, fp);
	__hlt();
}

// 0000000000000650: void deregister_tm_clones()
void deregister_tm_clones()
{
	if (2101320 == 2101320)
		return;
	<anonymous> * rax_27 = globals->ptr200FD8;
	if (rax_27 == null)
		return;
	word64 rsp_33;
	word64 rdi_34;
	word64 rbp_35;
	word64 rax_36;
	byte SCZO_37;
	bool Z_38;
	byte SZO_39;
	bool C_40;
	rax_27();
}

// 0000000000000690: void register_tm_clones()
void register_tm_clones()
{
	int64 rsi_7 = 2101320 - 2101320;
	if ((rsi_7 >> 0x03) + ((rsi_7 >> 0x03) >>u 0x3F) >> 0x01 == 0x00)
		return;
	<anonymous> * rax_34 = globals->ptr200FF0;
	if (rax_34 == null)
		return;
	word64 rsp_40;
	word64 rdi_41;
	word64 rsi_42;
	word64 rbp_43;
	byte SCZO_44;
	word64 rax_45;
	bool Z_46;
	byte SZO_47;
	bool C_48;
	rax_34();
}

// 00000000000006E0: void __do_global_dtors_aux()
void __do_global_dtors_aux()
{
	if (globals->b201048 != 0x00)
		return;
	if (globals->qw200FF8 != 0x00)
	{
		word64 rsp_25;
		byte SCZO_26;
		bool Z_27;
		word64 rbp_28;
		word64 rdi_29;
		__cxa_finalize();
	}
	deregister_tm_clones();
	globals->b201048 = 0x01;
}

// 0000000000000720: void frame_dummy()
void frame_dummy()
{
	register_tm_clones();
}

// 000000000000072A: Register (ptr64 void) _mm_malloc(Register uint64 rsi, Register Eq_123 rdi)
void(uint64 rsi, Eq_123 rdi)
{
	void * rax_22;
	if (rsi == 0x01)
		rax_22 = malloc(rdi);
	else
	{
		if (rsi == 0x02 || rsi == 0x04)
			;
		word64 rsp_44;
		word64 rbp_45;
		byte SCZO_46;
		word64 rdi_47;
		word64 rsi_48;
		bool Z_49;
		word64 rax_50;
		word64 rdx_51;
		word64 rcx_52;
		word32 eax_53;
		byte SZO_54;
		bool C_55;
		posix_memalign();
		if (eax_53 == 0x00)
			rax_22 = qwLoc10;
		else
			rax_22 = null;
	}
	return rax_22;
}

// 000000000000078D: void _mm_free(Register (ptr64 (arr real64)) rdi)
void _mm_free(real64 * rdi[])
{
	free(rdi);
}

// 00000000000007A8: Register uint64 vec_add(Register (ptr64 (arr real64)) rcx, Register (ptr64 (arr real64)) rdx, Register (ptr64 (arr real64)) rsi, Register word64 rdi)
uint64 vec_add(real64 * rcx[], real64 * rdx[], real64 * rsi[], word64 rdi)
{
	__align(fp);
	uint64 rcx_22 = globals->qw0B00;
	uint128 rdx_rax_25 = (uint128) (uint64) rdi;
	uint64 rdx_27 = (uint64) (rdx_rax_25 % rcx_22);
	uint64 rax_29 = (uint64) (rdx_rax_25 /u rcx_22);
	if (0x00 >= rax_29)
		return rdx_27 - 0x08;
}

// 0000000000000898: void main(Register Eq_184 xmm0)
void main(Eq_184 xmm0)
{
	real64 rax_13[] = _mm_malloc(0x20, 0x2000);
	real64 rax_20[] = _mm_malloc(0x20, 0x2000);
	real64 rax_27[] = _mm_malloc(0x20, 0x2000);
	Eq_201 qwLoc10_163 = 0x00;
	while (qwLoc10_163 < 0x0400)
	{
		real64 * rcx_150 = rax_13 + qwLoc10_163;
		ui32 eax_152 = (word32) qwLoc10_163;
		if (qwLoc10_163 >= 0x00)
			xmm0 = DPB(xmm0, (real64) qwLoc10_163, 0);
		else
		{
			real64 v26_173 = (real64) (qwLoc10_163 >> 0x01 | (uint64) (eax_152 & 0x01));
			xmm0 = DPB(xmm0, v26_173 + v26_173, 0);
		}
		*rcx_150 = (real64) xmm0;
		qwLoc10_163 = (word64) qwLoc10_163 + 0x01;
	}
	Eq_201 qwLoc18_133 = 0x00;
	while (qwLoc18_133 < 0x0400)
	{
		Eq_234 rax_117 = (word64) qwLoc18_133.u1 + 0x01;
		ui32 eax_118 = (word32) rax_117;
		real64 * rcx_122 = rax_20 + qwLoc18_133;
		if (rax_117 >= 0x00)
			xmm0 = DPB(xmm0, (real64) rax_117, 0);
		else
		{
			real64 v19_143 = (real64) (rax_117 >> 0x01 | (uint64) (eax_118 & 0x01));
			xmm0 = DPB(xmm0, v19_143 + v19_143, 0);
		}
		*rcx_122 = (real64) xmm0;
		qwLoc18_133 = (word64) qwLoc18_133.u1 + 0x01;
	}
	Eq_201 qwLoc20_114 = 0x00;
	while (qwLoc20_114 < 0x0400)
	{
		xmm0 = __xorpd(xmm0, xmm0);
		rax_27[qwLoc20_114] = (real64) xmm0;
		qwLoc20_114 = (word64) qwLoc20_114.u1 + 0x01;
	}
	struct Eq_277 * rsp_69 = vec_add(rax_20, rax_13, rax_27, 0x0400);
	Eq_201 qwLoc28_103 = 0x00;
	while (qwLoc28_103 < 0x0400)
	{
		printf("%g\n", rsp_69->tFFFFFFF8);
		qwLoc28_103 = (word64) qwLoc28_103 + 0x01;
	}
	_mm_free(rax_13);
	_mm_free(rax_20);
	_mm_free(rax_27);
}

// 0000000000000A70: void __libc_csu_init(Register word32 edi)
void __libc_csu_init(word32 edi)
{
	_init();
	if (0x00200DF0 - 2100712 >> 0x03 != 0x00)
	{
		do
		{
			word64 rsp_72;
			word64 r15_73;
			word64 r14_74;
			word32 r15d_75;
			word32 edi_76;
			word64 r13_77;
			word64 r12_78;
			word64 rbp_79;
			word64 rbx_80;
			word64 rsi_81;
			word64 rdx_82;
			byte SCZO_83;
			byte SZO_84;
			bool C_85;
			bool Z_86;
			word32 ebx_87;
			word64 rdi_88;
			globals->ptr200DE8();
		} while (rbp_79 != rbx_80 + 0x01);
	}
}

// 0000000000000AE0: void __libc_csu_fini()
void __libc_csu_fini()
{
}

// 0000000000000AE4: void _fini()
void _fini()
{
}


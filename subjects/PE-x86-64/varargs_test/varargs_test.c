// varargs_test.c
// Generated by decompiling varargs_test.exe
// using Reko decompiler version 0.6.1.0.

#include "varargs_test.h"

word32 fn0000000140001000(ptr64 & silOut)
{
	fn0000000140001140(qwLocC8, qwLocC0, qwLocB8, qwLocB0);
	Mem22[fp - 0x90 + 0x00:word64] = fp - 0x84;
	Mem25[fp - 0x98 + 0x00:word64] = fp - 0x88;
	Mem28[fp - 0xA0 + 0x00:word64] = fp - 0x78;
	Mem32[fp - 0xA8 + 0x00:word64] = fp - 0x80;
	fn00000001400010D0(qwArg00, qwArg08, qwArg10, qwArg18);
	byte sil_42;
	return fn00000001400011B0(Mem32[fp - 0x10 + 0x00:word64] ^ fp - 200, out sil_42);
}

word64 fn00000001400010C0()
{
	return 0x0000000140003628;
}

void fn00000001400010D0(word64 qwArg08, word64 qwArg10, word64 qwArg18, word64 qwArg20)
{
	word64 rsp_27;
	word64 rcx_28;
	word64 rdx_29;
	word64 r8_30;
	word64 r9_31;
	word64 rbx_32;
	word64 rsi_33;
	word64 rdi_34;
	byte SCZO_35;
	word32 ecx_36;
	byte SZO_37;
	byte C_38;
	word64 rax_39;
	word32 r9d_40;
	_acrt_iob_func();
	word64 rsp_52;
	word64 rcx_53;
	word64 rdx_54;
	word64 r8_55;
	word64 r9_56;
	word64 rbx_57;
	word64 rsi_58;
	word64 rdi_59;
	byte SCZO_60;
	word32 ecx_61;
	byte SZO_62;
	byte C_63;
	word64 rax_64;
	word32 r9d_65;
	_stdio_common_vfscanf();
	return;
}

word64 fn0000000140001130()
{
	return 0x0000000140003620;
}

void fn0000000140001140(word64 qwArg08, word64 qwArg10, word64 qwArg18, word64 qwArg20)
{
	word64 rsp_26;
	word64 rcx_27;
	word64 rdx_28;
	word64 r8_29;
	word64 r9_30;
	word64 rbx_31;
	word64 rsi_32;
	word64 rdi_33;
	byte SCZO_34;
	word32 ecx_35;
	word64 rax_36;
	word32 r9d_37;
	byte SZO_38;
	byte C_39;
	_acrt_iob_func();
	word64 rsp_51;
	word64 rcx_52;
	word64 rdx_53;
	word64 r8_54;
	word64 r9_55;
	word64 rbx_56;
	word64 rsi_57;
	word64 rdi_58;
	byte SCZO_59;
	word32 ecx_60;
	word64 rax_61;
	word32 r9d_62;
	byte SZO_63;
	byte C_64;
	_stdio_common_vfprintf();
	return;
}

word32 fn00000001400011B0(word64 rcx, ptr64 & silOut)
{
	*silOut = sil;
	word64 rcx_6 = __rol(rcx, 0x10);
	if (rcx_6 == 0x00)
	{
		__ror(rcx_6, 0x10);
		byte sil_24;
		return fn000000014000147C(qwArg08, out sil_24);
	}
	else
		return eax;
}

void fn00000001400011D4(word64 rbx, word64 r8, word64 r13)
{
	word64 rsp_8;
	word64 rbx_9;
	byte SCZO_10;
	word32 ecx_11;
	word32 eax_12;
	word64 rax_13;
	byte al_14;
	byte SZO_15;
	byte C_16;
	byte Z_17;
	word64 rcx_18;
	word64 r8_19;
	word64 r13_20;
	byte bl_21;
	set_app_type();
	fn0000000140001920();
	_set_fmode(dwLoc2C);
	word64 rax_26 = __p__commode();
	fn0000000140001ABC();
	Mem29[rax_26 + 0x00:word32] = 0x00;
	word32 eax_31 = fn000000014000164C(0x01, r8_19, r13_20, qwLoc2C);
	byte al_33 = (byte) eax_31;
	if (al_33 != 0x00)
	{
		fn0000000140001B5C(qwArg00, qwArg04, qwArg08, qwArg0C);
		fn0000000140001854(eax_31);
		fn0000000140001918();
		word64 rsp_74;
		word64 rbx_75;
		byte SCZO_76;
		word32 ecx_77;
		word32 eax_78;
		word64 rax_79;
		byte al_80;
		byte SZO_81;
		byte C_82;
		byte Z_83;
		word64 rcx_84;
		word64 r8_85;
		word64 r13_86;
		byte bl_87;
		configure_narrow_argv();
		if (false)
		{
			fn0000000140001928();
			word32 eax_92 = fn0000000140001958();
			if (eax_92 != 0x00)
			{
				word64 rsp_147;
				word64 rbx_148;
				byte SCZO_149;
				word32 ecx_150;
				word32 eax_151;
				word64 rax_152;
				byte al_153;
				byte SZO_154;
				byte C_155;
				byte Z_156;
				word64 rcx_157;
				word64 r8_158;
				word64 r13_159;
				byte bl_160;
				_setusermatherr();
			}
			fn0000000140001DD0();
			fn0000000140001DD0();
			fn0000000140001ABC();
			word64 rsp_97;
			word64 rbx_98;
			byte SCZO_99;
			word32 ecx_100;
			word32 eax_101;
			word64 rax_102;
			byte al_103;
			byte SZO_104;
			byte C_105;
			byte Z_106;
			word64 rcx_107;
			word64 r8_108;
			word64 r13_109;
			byte bl_110;
			configthreadlocale();
			fn0000000140001938();
			if (0x01 != 0x00)
			{
				word64 rsp_131;
				word64 rbx_132;
				byte SCZO_133;
				word32 ecx_134;
				word32 eax_135;
				word64 rax_136;
				byte al_137;
				byte SZO_138;
				byte C_139;
				byte Z_140;
				word64 rcx_141;
				word64 r8_142;
				word64 r13_143;
				byte bl_144;
				initialize_narrow_environment();
			}
			fn0000000140001ABC();
			return;
		}
	}
	else
	{
		word64 rcx_164;
		byte bl_165;
		fn0000000140001974(0x07, qwLoc04, qwArg00, qwArg04, qwArg0C, out rcx_164, out bl_165);
		int3();
	}
	word64 rcx_68;
	byte bl_69;
	fn0000000140001974(0x07, qwLoc04, qwArg00, qwArg04, qwArg0C, out rcx_68, out bl_69);
	int3();
	int3();
	fn0000000140001290();
	return;
}

void fn0000000140001290()
{
	fn000000014000193C();
	return;
}

void fn00000001400012A0()
{
	fn0000000140001B14();
	fn0000000140001ABC();
	word64 rsp_8;
	byte SCZO_9;
	word32 ecx_10;
	word32 eax_11;
	Mem0[0x0000000140002098 + 0x00:word32]();
	return;
}

word64 fn00000001400012BC(word32 edx, word64 rdi, word64 r13, selector gs, word64 qwArg08, word64 qwArg10)
{
	if (fn0000000140001600(0x01, edx, r13) == 0x00)
	{
		word64 rcx_362;
		byte bl_363;
		fn0000000140001974(0x07, qwLoc04, qwArg00, qwArg04, qwArg0C, out rcx_362, out bl_363);
		int3();
	}
	Mem23[fp - 0x14 + 0x00:byte] = 0x00;
	word32 eax_25 = fn00000001400015C4(gs);
	word64 rax_28 = DPB(rax, eax_25, 0);
	byte bl_29 = (byte) eax_25;
	word32 ecx_33 = Mem23[0x00000001400035B0 + 0x00:word32];
	if (ecx_33 == 0x01)
	{
		ecx_33 = 0x07;
		word64 rcx_355;
		rax_28 = DPB(rax, fn0000000140001974(0x07, qwLoc04, qwArg00, qwArg04, qwArg0C, out rcx_355, out bl_29), 0);
	}
	word64 rax_233;
	if (ecx_33 == 0x00)
	{
		Mem331[0x00000001400035B0 + 0x00:word32] = 0x01;
		word64 rdx_332 = 0x00000001400021D0;
		word64 rcx_333 = 0x00000001400021B8;
		word64 rax_334 = DPB(rax_28, _initterm_e(rcx_333, rdx_332), 0);
		if (_initterm_e(rcx_333, rdx_332) != 0x00)
		{
			rax_233 = DPB(rax_28, 0xFF, 0);
			return rax_233;
		}
		_initterm(0x00000001400021A0, 0x00000001400021B0);
		Mem344[0x00000001400035B0 + 0x00:word32] = 0x02;
	}
	else
		Mem346[fp - 0x14 + 0x00:byte] = 0x01;
	fn00000001400017B4(bl_29);
	word64 rax_80 = fn0000000140001964();
	if (Mem23[rax_80 + 0x00:word64] != 0x00)
	{
		word64 rax_293 = fn0000000140001718(rax_80);
		byte al_294 = (byte) rax_293;
		if (al_294 != 0x00)
		{
			word64 rbx_299 = Mem23[rax_80 + 0x00:word64];
			fn0000000140001BF4();
			word32 ebx_300 = (word32) rbx_299;
			word64 rsp_307;
			word64 rbx_308;
			word64 rsi_309;
			word64 rdi_310;
			byte SCZO_311;
			word32 ecx_312;
			byte al_313;
			byte SZO_314;
			byte C_315;
			byte Z_316;
			byte sil_317;
			byte bl_318;
			word64 rdx_319;
			word64 rcx_320;
			word64 rax_321;
			word32 eax_322;
			byte cl_323;
			word32 r8d_324;
			word32 edx_325;
			word32 ebx_326;
			word64 r8_327;
			word64 r13_328;
			selector gs_329;
			byte dl_330;
			ebx_300();
		}
	}
	word64 rax_107 = fn000000014000196C();
	if (Mem23[rax_107 + 0x00:word64] != 0x00)
	{
		word64 rax_260 = fn0000000140001718(rax_107);
		byte al_261 = (byte) rax_260;
		if (al_261 != 0x00)
		{
			word64 rsp_267;
			word64 rbx_268;
			word64 rsi_269;
			word64 rdi_270;
			byte SCZO_271;
			word32 ecx_272;
			byte al_273;
			byte SZO_274;
			byte C_275;
			byte Z_276;
			byte sil_277;
			byte bl_278;
			word64 rdx_279;
			word64 rcx_280;
			word64 rax_281;
			word32 eax_282;
			byte cl_283;
			word32 r8d_284;
			word32 edx_285;
			word32 ebx_286;
			word64 r8_287;
			word64 r13_288;
			selector gs_289;
			byte dl_290;
			register_thread_local_exe_atexit_callback();
		}
	}
	word64 rsp_115;
	word64 rbx_116;
	word64 rsi_117;
	word64 rdi_118;
	byte SCZO_119;
	word32 ecx_120;
	byte al_121;
	byte SZO_122;
	byte C_123;
	byte Z_124;
	byte sil_125;
	byte bl_126;
	word64 rdx_127;
	word64 rcx_128;
	word64 rax_129;
	word32 eax_130;
	byte cl_131;
	word32 r8d_132;
	word32 edx_133;
	word32 ebx_134;
	word64 r8_135;
	word64 r13_136;
	selector gs_137;
	byte dl_138;
	_p___argv();
	word64 rsp_141;
	word64 rbx_142;
	word64 rsi_143;
	word64 rdi_144;
	byte SCZO_145;
	word32 ecx_146;
	byte al_147;
	byte SZO_148;
	byte C_149;
	byte Z_150;
	byte sil_151;
	byte bl_152;
	word64 rdx_153;
	word64 rcx_154;
	word64 rax_155;
	word32 eax_156;
	byte cl_157;
	word32 r8d_158;
	word32 edx_159;
	word32 ebx_160;
	word64 r8_161;
	word64 r13_162;
	selector gs_163;
	byte dl_164;
	_p___argc();
	word64 rsp_167;
	word64 rbx_168;
	word64 rsi_169;
	word64 rdi_170;
	byte SCZO_171;
	word32 ecx_172;
	byte al_173;
	byte SZO_174;
	byte C_175;
	byte Z_176;
	byte sil_177;
	byte bl_178;
	word64 rdx_179;
	word64 rcx_180;
	word32 eax_182;
	byte cl_183;
	word32 r8d_184;
	word32 edx_185;
	word32 ebx_186;
	word64 r8_187;
	word64 r13_188;
	selector gs_189;
	byte dl_190;
	word64 rax_181;
	get_initial_narrow_environment();
	byte sil_195;
	word32 eax_196 = fn0000000140001000(out sil_195);
	byte al_200 = fn0000000140001AC0();
	if (al_200 == 0x00)
		exit(DPB(rcx_180, eax_196, 0));
	if (sil_195 == 0x00)
	{
		word64 rsp_234;
		word64 rbx_235;
		word64 rsi_236;
		word64 rdi_237;
		byte SCZO_238;
		word32 ecx_239;
		byte al_240;
		byte SZO_241;
		byte C_242;
		byte Z_243;
		byte sil_244;
		byte bl_245;
		word64 rdx_246;
		word64 rcx_247;
		word32 eax_249;
		byte cl_250;
		word32 r8d_251;
		word32 edx_252;
		word32 ebx_253;
		word64 r8_254;
		word64 r13_255;
		selector gs_256;
		byte dl_257;
		cexit();
	}
	rax_233 = DPB(rax_181, fn00000001400017D8(0x00), 0);
	return rax_233;
}

DWORD Win32CrtStartup()
{
	fn000000014000186C(rbx, qwLoc24, qwLoc1C, qwLoc14, qwLoc10, qwLoc0C);
	return fn00000001400012BC(edx, rdi, r13, gs, qwArg08, qwArg10);
}

word32 fn0000000140001448()
{
	SetUnhandledExceptionFilter(tLoc20);
	UnhandledExceptionFilter(tLoc20);
	word64 rsp_24;
	word64 rbx_25;
	byte SCZO_26;
	word64 rcx_27;
	word32 ecx_28;
	byte SZO_29;
	byte C_30;
	word32 eax_31;
	word64 rax_32;
	word32 edx_33;
	Mem0[0x0000000140002058 + 0x00:word64]();
	return eax_31;
}

word32 fn000000014000147C(word64 qwArg08, ptr64 & silOut)
{
	if (IsProcessorFeaturePresent(tLoc38) == 0x00)
	{
		byte sil_15;
		*silOut = fn0000000140001550(0x00000001400030E0, qwLoc3C, qwLoc2C);
		Mem18[0x00000001400031D8 + 0x00:word64] = Mem0[fp + 0x00:word64];
		Mem21[0x0000000140003178 + 0x00:word64] = fp + 0x08;
		Mem23[0x0000000140003050 + 0x00:word64] = Mem21[0x00000001400031D8 + 0x00:word64];
		word64 rax_24 = Mem23[fp + 0x08:word64];
		Mem25[0x0000000140003160 + 0x00:word64] = rax_24;
		Mem26[0x0000000140003040 + 0x00:word32] = 0xC0000409;
		Mem27[0x0000000140003044 + 0x00:word32] = 0x01;
		Mem28[0x0000000140003058 + 0x00:word32] = 0x01;
		word64 rax_30 = DPB(rax_24, 0x08, 0);
		0x0000000140003060[rax_30 * 0x00] = 0x02;
		word64 rax_35 = DPB(rax_30 *s 0x00, 0x08, 0);
		(fp - 0x18)[rax_35 * 0x00] = Mem33[0x0000000140003000 + 0x00:word64];
		(fp - 0x18)[DPB(rax_35 *s 0x00, 0x08, 0) * 0x01] = Mem38[0x0000000140003008 + 0x00:word64];
		return fn0000000140001448();
	}
	else
		__fastfail(0x02);
}

byte fn0000000140001550(word64 rcx, word64 qwArg04, word64 qwArg14)
{
	RtlCaptureContext(tLoc48);
	word64 rsi_16 = Mem0[rcx + 0xF8:word64];
l000000014000156A:
	word64 rax_50 = RtlLookupFunctionEntry(rsi_16, fp + 0x14, DPB(r8, 0x00, 0));
	if (rax_50 != 0x00)
	{
		word64 rsp_97;
		word64 rbx_98;
		word64 rdi_100;
		byte SCZO_101;
		word64 rcx_102;
		word32 edi_103;
		byte SZO_104;
		byte C_105;
		word32 r8d_106;
		word64 rdx_107;
		word64 rax_108;
		byte Z_110;
		word64 r9_111;
		word32 ecx_112;
		byte SO_113;
		byte sil_114;
		KERNEL32.dll!RtlVirtualUnwind();
		if (edi_103 < ~0x00)
			goto l000000014000156A;
	}
	return (byte) qwLoc04;
}

word32 fn00000001400015C4(selector gs)
{
	word32 eax_15;
	word32 eax_26 = fn0000000140001DC4();
	if (eax_26 != 0x00)
	{
		word64 rax_38 = Mem0[gs:0x30:word64];
		word64 rcx_39 = Mem0[rax_38 + 0x08:word64];
		do
		{
			__lock();
			__lock();
			eax_26 = 0x00;
			rax_38 = DPB(rax_38, 0x00, 0);
			if (!__cmpxchg(Mem0[0x00000001400035B8 + 0x00:word64], rcx_39, Mem44, out Mem51))
				goto l00000001400015F2;
		} while (rcx_39 == rax_38);
		eax_15 = 0x01;
	}
	else
	{
l00000001400015F2:
		eax_15 = DPB(eax_26, 0x00, 0);
	}
	return eax_15;
	return eax_15;
	return eax_15;
}

byte fn0000000140001600(word32 ecx, word32 edx, word64 r13)
{
	byte al_16 = (byte) (word32) Mem0[0x00000001400035F0 + 0x00:byte];
	word64 rbx_14 = DPB(rbx, 0x01, 0);
	if (ecx == 0x00)
		al_16 = 0x01;
	byte al_34;
	Mem18[0x00000001400035F0 + 0x00:byte] = al_16;
	byte bl_26 = fn0000000140001BFC(edx, rbx_14, r13, qwLoc20, qwLoc1C, qwLoc18, qwLoc14, qwLoc10);
	fn0000000140001938();
	if (true)
	{
		fn0000000140001938();
		if (true)
		{
			al_34 = bl_26;
			return al_34;
		}
		fn0000000140001938();
	}
	al_34 = 0x00;
	return al_34;
}

word32 fn000000014000164C(word32 ecx, word64 r8, word64 r13, word64 qwArg08)
{
	if (ecx >u 0x01)
	{
		word64 rcx_156;
		byte bl_157;
		fn0000000140001974(0x05, qwLoc48, qwLoc44, qwLoc40, qwLoc38, out rcx_156, out bl_157);
		int3();
		int3();
		int3();
		int3();
		return (word32) fn0000000140001718(rcx_156);
	}
	else
	{
		word32 eax_35 = fn0000000140001DC4();
		if (eax_35 == 0x00 || ecx != 0x00)
		{
			word64 rdx_44 = Mem0[0x0000000140003000 + 0x00:word64];
			word64 r8_56 = __ror(r8 | ~0x00, (byte) (0x40 - ((word32) rdx_44 & 0x3F))) ^ rdx_44;
			Mem59[r13 - 0x20 + 0x00:word64] = r8_56;
			Mem61[r13 - 0x18 + 0x00:word64] = r8_56;
		}
		else
		{
			word32 eax_105;
			word64 rsp_69;
			word64 rbx_70;
			word64 rbp_71;
			byte SCZO_72;
			word32 ebx_73;
			word32 ecx_74;
			byte CZ_75;
			word32 eax_76;
			byte SZO_77;
			byte C_78;
			byte Z_79;
			word64 rcx_80;
			byte al_81;
			word64 rdx_82;
			word64 r8_83;
			word32 edx_84;
			byte cl_85;
			word64 r13_86;
			byte bl_87;
			word64 rax_88;
			initialize_onexit_table();
			if (eax_76 != 0x00)
				eax_105 = DPB(eax_76, 0x00, 0);
			else
			{
				word64 rsp_121;
				word64 rbx_122;
				word64 rbp_123;
				byte SCZO_124;
				word32 ebx_125;
				word32 ecx_126;
				byte CZ_127;
				word32 eax_128;
				byte SZO_129;
				byte C_130;
				byte Z_131;
				word64 rcx_132;
				byte al_133;
				word64 rdx_134;
				word64 r8_135;
				word32 edx_136;
				byte cl_137;
				word64 r13_138;
				byte bl_139;
				word64 rax_140;
				initialize_onexit_table();
				eax_105 = DPB(eax_128, eax_128 == 0x00, 0);
			}
			return eax_105;
		}
	}
}

word64 fn0000000140001718(word64 rcx)
{
	word64 rax_103;
	if (Mem0[0x0000000140000000 + 0x00:word16] == 23117)
	{
		rax = (int64) Mem0[0x000000014000003C + 0x00:word32];
		word64 rdx_50 = 0x0000000140000000;
		word64 rcx_52 = rax + rdx_50;
		if (Mem0[rcx_52 + 0x00:word32] == 0x4550 && Mem0[rcx_52 + 0x18:word16] == 0x020B)
		{
			word64 rax_115 = DPB(rax, (word32) Mem0[rcx_52 + 0x06:word16], 0);
			word64 rdx_117 = rcx_52 + 0x18 + DPB(rax, (word32) Mem0[rcx_52 + 0x14:word16], 0);
			word64 r8_60 = rcx - rdx_50;
			word64 rcx_111 = rax_115 * 0x05;
			word64 r9_70 = rdx_117 + (rax_115 * 0x05) * 0x08;
			while (rdx_117 != r9_70)
			{
				word32 ecx_110 = Mem0[rdx_117 + 0x0C:word32];
				rcx_111 = DPB(rcx_111, ecx_110, 0);
				if (r8_60 >=u rcx_111)
				{
					rax_115 = DPB(rax_115, Mem0[rdx_117 + 0x08:word32] + ecx_110, 0);
					if (r8_60 <u rax_115)
						goto l000000014000178F;
				}
				rdx_117 = rdx_117 + 0x28;
			}
			rdx_117 = DPB(rdx_117, 0x00, 0);
l000000014000178F:
			if (rdx_117 == 0x00)
				rax_103 = DPB(rax_115, 0x00, 0);
			else if (Mem0[rdx_117 + 0x24:word32] < 0x00)
				rax_103 = DPB(rax_115, 0x00, 0);
			else
				rax_103 = DPB(rax_115, 0x01, 0);
			return rax_103;
		}
	}
	rax_103 = DPB(rax, 0x00, 0);
	return rax_103;
}

void fn00000001400017B4(byte cl)
{
	word64 rdx_13 = DPB(rdx, 0x00, 0);
	if (fn0000000140001DC4() != 0x00 && cl == 0x00)
		Mem31[0x00000001400035B8 + 0x00:word64] = rdx_13;
	return;
}

word32 fn00000001400017D8(byte dl)
{
	if (Mem0[0x00000001400035F0 + 0x00:byte] == 0x00 || dl == 0x00)
	{
		fn0000000140001938();
		fn0000000140001938();
	}
	return (word32) qwLoc04;
}

word64 fn0000000140001804(word32 eax)
{
	word64 rbx_25;
	word32 eax_23;
	word64 rcx_21;
	word64 rdx_7 = Mem0[0x0000000140003000 + 0x00:word64];
	word32 edx_8 = (word32) rdx_7;
	byte cl_14 = (byte) (edx_8 & 0x3F);
	word64 rdx_16 = __ror(rdx_7 ^ Mem0[0x00000001400035C0 + 0x00:word64], cl_14);
	if (rdx_16 == ~0x00)
	{
		word64 rsp_51;
		byte SCZO_53;
		word64 rdx_54;
		word32 ecx_56;
		word32 edx_57;
		byte SZO_58;
		byte C_59;
		byte cl_60;
		byte Z_61;
		word64 rax_63;
		crt_atexit();
	}
	else
	{
		word64 rsp_67;
		byte SCZO_69;
		word64 rdx_70;
		word32 ecx_72;
		word32 edx_73;
		byte SZO_74;
		byte C_75;
		byte cl_76;
		byte Z_77;
		word64 rax_79;
		register_onexit_function();
	}
	word64 rcx_28 = DPB(rcx_21, 0x00, 0);
	if (eax_23 == 0x00)
		rcx_28 = rbx_25;
	return rcx_28;
}

void fn0000000140001854(word32 eax)
{
	fn0000000140001804(eax);
	return;
}

void fn000000014000186C(word64 rbx, word64 qwArg0C, word64 qwArg14, word64 qwArg1C, word64 qwArg20, word64 qwArg24)
{
	word64 rax_15 = Mem0[0x0000000140003000 + 0x00:word64];
	if (rax_15 == rbx)
	{
		GetSystemTimeAsFileTime(tLoc20);
		word64 v15_50 = qwArg14 & 0x00 ^ DPB(qwArg14 & 0x00, GetCurrentThreadId(), 0) ^ DPB(qwArg14 & 0x00, GetCurrentProcessId(), 0);
		QueryPerformanceCounter(tLoc20);
		rax_15 = (DPB(qwArg14 & 0x00, dwArg1C, 0) << 0x20 ^ qwArg1C ^ v15_50 ^ fp + 0x0C) & fp + 0x0C;
		if (rax_15 == rbx)
			rax_15 = fp + 0x0C;
		Mem70[0x0000000140003000 + 0x00:word64] = rax_15;
	}
	Mem32[0x0000000140003008 + 0x00:word64] = ~rax_15;
	return;
}

void fn0000000140001918()
{
	return;
}

void fn0000000140001920()
{
	return;
}

void fn0000000140001928()
{
	word64 rsp_4;
	word64 rcx_5;
	Mem0[0x0000000140002028 + 0x00:word64]();
	return;
}

void fn0000000140001938()
{
	return;
}

void fn000000014000193C()
{
	word64 rax_4 = fn0000000140001130();
	Mem7[rax_4 + 0x00:word64] = Mem0[rax_4 + 0x00:word64] | 0x04;
	word64 rax_10 = fn00000001400010C0();
	Mem12[rax_10 + 0x00:word64] = Mem7[rax_10 + 0x00:word64] | 0x02;
	return;
}

word32 fn0000000140001958()
{
	return (word32) (Mem0[0x0000000140003014 + 0x00:word32] == 0x00);
}

word64 fn0000000140001964()
{
	return 0x0000000140003638;
}

word64 fn000000014000196C()
{
	return 0x0000000140003630;
}

word32 fn0000000140001974(word32 ecx, word64 qwArg04, word64 qwArg08, word64 qwArg0C, word64 qwArg14, ptr64 & rcxOut, ptr64 & blOut)
{
	if (IsProcessorFeaturePresent(tLoc05C4) == 0x00)
	{
		Mem22[0x0000000140003610 + 0x00:word32] = Mem0[0x0000000140003610 + 0x00:word32] & 0x00;
		word32 eax_28 = memset(ptrLoc05C4, dwLoc05BC, tLoc05B4);
		RtlCaptureContext(tLoc05C0);
		word64 rax_37 = RtlLookupFunctionEntry(qwLoc03DC, fp + 0x14, DPB(r8, 0x00, 0));
		if (rax_37 != 0x00)
		{
			word64 rsp_138;
			word64 rbx_139;
			word64 rbp_140;
			byte SCZO_141;
			word32 ebx_142;
			word32 ecx_143;
			word32 eax_144;
			byte SZO_145;
			byte C_146;
			byte Z_147;
			word64 rcx_148;
			word32 edx_149;
			word64 rdx_150;
			word32 r8d_151;
			word64 rax_152;
			word64 r8_153;
			word64 r9_154;
			byte bl_155;
			KERNEL32.dll!RtlVirtualUnwind();
		}
		memset(ptrLoc05C4, dwLoc05BC, tLoc05B4);
		word32 eax_73 = IsDebuggerPresent();
		SetUnhandledExceptionFilter(tLoc05C0);
		word64 rcx_85;
		*rcxOut = fp - 1412;
		word32 eax_109 = UnhandledExceptionFilter(tLoc05C0);
		if (eax_109 == 0x00)
		{
			eax_109 = 0x00 - (-(eax_73 == 0x01) == 0x00);
			Mem112[0x0000000140003610 + 0x00:word32] = Mem22[0x0000000140003610 + 0x00:word32] & eax_109;
		}
		byte bl_99;
		*blOut = (byte) qwArg0C;
		return eax_109;
	}
	else
		__fastfail(ecx);
}

void fn0000000140001ABC()
{
	return;
}

byte fn0000000140001AC0()
{
	byte al_21;
	word64 rax_7 = DPB(rax, GetModuleHandleW(tLoc24), 0);
	if (rax_7 != 0x00 && Mem0[rax_7 + 0x00:word16] == 23117)
	{
		word64 rax_49 = (int64) Mem0[rax_7 + 0x3C:word32] + rax_7;
		if (Mem0[rax_49 + 0x00:word32] == 0x4550 && (Mem0[rax_49 + 0x18:word16] == 0x020B && Mem0[rax_49 + 0x84:word32] >u 0x0E))
		{
			al_21 = Mem0[rax_49 + 0xF8:word32] != 0x00;
			return al_21;
		}
	}
	al_21 = 0x00;
	return al_21;
}

void fn0000000140001B14()
{
	word64 rsp_4;
	word64 rcx_5;
	Mem0[0x0000000140002068 + 0x00:word64]();
	return;
}

void fn0000000140001B24(word64 rcx)
{
	word64 rax_5 = Mem0[rcx + 0x00:word64];
	if (Mem0[rax_5 + 0x00:word32] == ~0x1F928C9C && Mem0[rax_5 + 0x18:word32] == 0x04)
	{
		word32 ecx_32 = Mem0[rax_5 + 0x20:word32];
		word64 rcx_33 = DPB(rcx, ecx_32, 0);
		if (rcx_33 <=u ~0x19930521 || ecx_32 == 0x01994000)
		{
			word64 rsp_37;
			byte SCZO_38;
			word64 rax_39;
			word64 rcx_40;
			byte Z_41;
			word32 ecx_42;
			word32 eax_43;
			byte CZ_44;
			byte SZO_45;
			byte C_46;
			api-ms-win-crt-runtime-l1-1-0.dll!terminate();
			int3();
			fn0000000140001B5C(qwLoc28, qwLoc24, qwLoc20, qwLoc1C);
			return;
		}
	}
	return;
}

void fn0000000140001B5C(word64 qwArg08, word64 qwArg0C, word64 qwArg10, word64 qwArg14)
{
	word64 rbx_11 = 0x0000000140002680;
	word64 rsi_12 = 0x0000000140002680;
	while (rbx_11 <u rsi_12)
	{
		word64 rdi_37 = Mem0[rbx_11 + 0x00:word64];
		if (rdi_37 != 0x00)
		{
			fn0000000140001BF4();
			word64 rsp_53;
			word64 rdi_56;
			byte SCZO_57;
			byte C_58;
			byte SZO_59;
			byte Z_60;
			word64 rcx_61;
			edi();
		}
		rbx_11 = rbx_11 + 0x08;
	}
	return;
}

void fn0000000140001BA8(word64 qwArg08, word64 qwArg0C, word64 qwArg10, word64 qwArg14)
{
	word64 rbx_11 = 0x0000000140002690;
	word64 rsi_12 = 0x0000000140002690;
	while (rbx_11 <u rsi_12)
	{
		word64 rdi_37 = Mem0[rbx_11 + 0x00:word64];
		if (rdi_37 != 0x00)
		{
			fn0000000140001BF4();
			word64 rsp_53;
			word64 rdi_56;
			byte SCZO_57;
			byte C_58;
			byte SZO_59;
			byte Z_60;
			word64 rcx_61;
			edi();
		}
		rbx_11 = rbx_11 + 0x08;
	}
	return;
}

void fn0000000140001BF4()
{
	word64 rsp_3;
	Mem0[0x0000000140002190 + 0x00:word64]();
	return;
}

byte fn0000000140001BFC(word32 edx, word64 rbx, word64 r13, word64 qwArg0C, word64 qwArg10, word64 qwArg14, word64 qwArg18, word64 qwArg1C)
{
	Mem17[0x000000014000301C + 0x00:word32] = 0x02;
	word32 eax_18;
	word32 ebx_19;
	word32 ecx_20;
	word32 edx_21;
	__cpuid(0x00, 0x00, &eax_18, &ebx_19, &ecx_20, &edx_21);
	Mem23[0x0000000140003018 + 0x00:word32] = 0x01;
	word32 r8d_174 = Mem23[0x0000000140003614 + 0x00:word32];
	word32 eax_51;
	word32 ebx_52;
	word32 ecx_53;
	word32 edx_54;
	__cpuid(0x01, 0x00, &eax_51, &ebx_52, &ecx_53, &edx_54);
	Mem57[r13 - 0x08 + 0x00:word32] = ecx_53;
	word32 r11d_191 = ebx_19 ^ 1752462657 | edx_21 ^ 0x69746E65 | ecx_20 ^ 0x444D4163;
	if ((edx_21 ^ 0x49656E69 | ecx_20 ^ 1818588270 | ebx_19 ^ 1970169159) == 0x00)
	{
		Mem179[0x0000000140003020 + 0x00:word64] = Mem57[0x0000000140003020 + 0x00:word64] | ~0x00;
		Mem186[0x0000000140003614 + 0x00:word32] = r8d_174 | 0x04;
		r8d_174 = r8d_174 | 0x04;
		if ((eax_51 & 0x0FFF3FF0) == 0x000106C0 || ((eax_51 & 0x0FFF3FF0) == 0x00020660 || (eax_51 & 0x0FFF3FF0) == 0x00020670))
		{
l0000000140001CDE:
			r8d_174 = r8d_174 | 0x04 | 0x01;
			Mem201[0x0000000140003614 + 0x00:word32] = r8d_174;
			goto l0000000140001CE9;
		}
		word32 eax_206 = (eax_51 & 0x0FFF3FF0) + ~0x0003064F;
		word64 rax_207 = DPB(rax, eax_206, 0);
		if (eax_206 <=u 0x20)
		{
			r11d_191 = 0x00010001;
			if (!__bt(rbx, rax_207))
				goto l0000000140001CDE;
		}
	}
l0000000140001CE9:
	if (r11d_191 == 0x00 && (eax_51 & 0x0FF00F00) >=u 0x00600F00)
	{
		r8d_174 = r8d_174 | 0x04;
		Mem177[0x0000000140003614 + 0x00:word32] = r8d_174;
	}
	Mem88[r13 - 0x1C + 0x00:word32] = ecx_53;
	if (eax_18 >= 0x07)
	{
		word32 eax_157;
		word32 ebx_158;
		word32 ecx_159;
		word32 edx_160;
		__cpuid(0x07, 0x00, &eax_157, &ebx_158, &ecx_159, &edx_160);
		if (!__bt(ebx_158, 0x09))
			Mem170[0x0000000140003614 + 0x00:word32] = r8d_174 | 0x02;
	}
	if (!__bt(ecx_53, 0x14))
	{
		Mem123[0x0000000140003018 + 0x00:word32] = 0x02;
		Mem124[0x000000014000301C + 0x00:word32] = 0x06;
		if (!__bt(ecx_53, 0x1B) && !__bt(ecx_53, 0x1C))
		{
			word64 edx_eax_128 = __xgetbv(0x00);
			if (((byte) (edx_eax_128 << 0x20 | edx_eax_128) & 0x06) == 0x06)
			{
				word32 eax_139 = Mem124[0x000000014000301C + 0x00:word32];
				Mem144[0x0000000140003018 + 0x00:word32] = 0x03;
				Mem149[0x000000014000301C + 0x00:word32] = eax_139 | 0x08;
				if ((bLoc1C & 0x20) != 0x00)
				{
					Mem153[0x0000000140003018 + 0x00:word32] = 0x05;
					Mem154[0x000000014000301C + 0x00:word32] = eax_139 | 0x08 | 0x20;
				}
			}
		}
	}
	return (byte) qwArg14;
}

word32 fn0000000140001DC4()
{
	return (word32) (Mem0[0x0000000140003030 + 0x00:word32] != 0x00);
}

void fn0000000140001DD0()
{
	return;
}

void fn0000000140001E7C(word64 rax, word64 rdx, word64 r9)
{
	fn0000000140001E9C(rax, rdx, r9, Mem0[r9 + 0x38:word64]);
	return;
}

void fn0000000140001E9C(word64 rax, word64 rcx, word64 rdx, word64 r8)
{
	word64 rcx_20;
	word32 r11d_7 = Mem0[r8 + 0x00:word32];
	word64 r9_12 = rcx;
	word64 r10_17 = rcx;
	rcx_20 = rcx;
	if ((Mem0[rax + 0x00:byte] & 0x04) != 0x00)
	{
		rcx_20 = (int64) -Mem0[rax + 0x08:word32];
		r10_17 = (int64) Mem0[r8 + 0x04:word32] + rcx & rcx_20;
	}
	word64 rax_24 = Mem0[rdx + 0x10:word64];
	word64 rdx_23 = Mem0[(int64) (r11d_7 & ~0x07) + r10_17:word64];
	word64 rcx_27 = DPB(rcx_20, Mem0[rax_24 + 0x08:word32], 0) + Mem0[rdx + 0x08:word64];
	if ((Mem0[rcx_27 + 0x03:byte] & 0x0F) != 0x00)
		r9_12 = rcx + DPB(rax_24, (word32) Mem0[rcx_27 + 0x03:byte] & ~0x0F, 0);
	word64 r9_37 = r9_12 ^ rdx_23;
	byte sil_45;
	fn00000001400011B0(r9_37, out sil_45);
	return;
}

void fn0000000140001F10()
{
	word64 rsp_3;
	word32 eax_4;
	eax();
	return;
}

void fn0000000140001F12(word64 rcx)
{
	word64 rsp_14;
	word64 rbp_15;
	byte SCZO_16;
	word64 rdx_17;
	word64 rax_18;
	word64 rcx_19;
	word32 ecx_20;
	seh_filter_exe();
	return;
}

void fn0000000140001F30(word64 rcx)
{
	return;
}

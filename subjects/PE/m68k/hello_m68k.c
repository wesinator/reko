// hello_m68k.c
// Generated by decompiling hello_m68k.exe
// using Reko decompiler version 0.8.0.0.

#include "hello_m68k.h"

// 00001004: void Win32CrtStartup()
void Win32CrtStartup()
{
	__btst(d0, d1);
}

// 00001498: void fn00001498()
void fn00001498()
{
}

// 0000149C: void fn0000149C(Register word32 d0, Register word32 a5)
void fn0000149C(word32 d0, word32 a5)
{
	__syscall(43424);
	if (DPB(dwLoc0A, 0x4270, 0) == 0x00)
		*(word16 *) 0x0AF0 = 0x1A;
	else
	{
		__syscall(43118);
		__syscall(43262);
		__syscall(43282);
		__syscall(0xA930);
		__syscall(0xA9CC);
		__syscall(43387);
		__syscall(0xA850);
		__syscall(43398);
	}
	__syscall(~0x560B);
}

// 000014E8: void fn000014E8(Register word32 a5, Stack int32 dwArg02)
void fn000014E8(word32 a5, int32 dwArg02)
{
	0x00 = 0x00;
	__syscall(43424);
	if (dwLoc12 == null)
	{
		*(word16 *) 0x0AF0 = ~0x025C;
		__syscall(~0x560B);
		goto l0000159A;
	}
	else
	{
		struct Eq_71 * a3_40 = *dwLoc12;
		uint32 d0_43 = a3_40->dw0000;
		word16 * a2_44 = a5 - d0_43;
		word16 * a0_164 = a2_44;
		uint32 d0_163 = d0_43 >> 0x01;
		if (d0_43 >> 0x01 != 0x00)
		{
			do
			{
				*a0_164 = 0x00;
				++a0_164;
				--d0_163;
			} while (d0_163 != 0x00);
		}
		word32 a2_50 = a2_44 - a3_40->dw0004;
		__syscall(0xA02E);
		uint32 d0_52 = a3_40->dw0008;
		word16 * a2_53 = a2_50 - d0_52;
		word16 * a0_157 = a2_53;
		uint32 d0_156 = d0_52 >> 0x01;
		if (d0_52 >> 0x01 != 0x00)
		{
			do
			{
				*a0_157 = 0x00;
				++a0_157;
				--d0_156;
			} while (d0_156 != 0x00);
		}
		ptr32 * a2_60 = a2_53 - a3_40->dw000C;
		struct Eq_124 * a3_122 = &a3_40->dw000C + 0x01 + a3_40->dw0004 / 0x0010 + a3_40->dw000C / 0x0010;
		__syscall(0xA02E);
l00001556:
		ui32 d0_126;
		ci8 v19_77 = a3_122->b0000;
		++a3_122;
		int32 d0_123 = (int32) v19_77;
		byte CVZN_80 = cond(v19_77);
		if (v19_77 <= 0x00)
		{
			if (v19_77 >= 0x00)
			{
				if (a3_122->b0000 != 0x00)
				{
					a3_122 += 0x04;
					d0_126 = DPB(__swap(DPB(d0_123, a3_122[0x01], 0)), a3_122[0x03], 0) * 0x02;
l00001578:
					a2_60 += d0_126;
					if (dwArg02 != 0x00 && DPB(CVZN_80, false, 0))
						*a2_60 = (*a2_60 + dwArg02)->ptr0002;
					else
						*a2_60 += dwLoc02;
					goto l00001556;
				}
l0000159A:
				__syscall(0xA9A3);
				return;
			}
			++a3_122;
			d0_123 = DPB(d0_123, a3_122->b0000, 0);
		}
		d0_126 = DPB(d0_123, (word16) (d0_123 * 0x02), 0);
		goto l00001578;
	}
}

// 000015E8: void fn000015E8(Register word32 d0, Register ptr32 a5, Stack word32 dwArg04)
void fn000015E8(word32 d0, ptr32 a5, word32 dwArg04)
{
	word32 a7_24;
	word32 a6_25;
	word32 d3_26;
	byte CVZN_27;
	word32 d0_30;
	byte ZN_31;
	bool C_32;
	bool V_33;
	bool Z_34;
	word32 a0_35;
	byte CVZNX_36;
	struct Eq_234 * a5_110;
	struct Eq_235 * a2_112;
	(a5 + 0x0082)();
	if (d0_30 == 0x00)
		return;
	int32 d3_113;
	if (a2_112 - (a5_110->aFFFFF578 + 0x0A) == 0x00)
		d3_113 = 0x00;
	else
	{
		if (a2_112 - (a5_110->aFFFFF578 + 0x0012) != 0x00)
			return;
		d3_113 = 0x01;
	}
	++a5_110->dwFFFFFAA8;
	if (((word16) a2_112->dw000C & 0x010C) != 0x00)
		return;
	if (a5_110->aFFFFF578[d3_113] == 0x00)
	{
		word32 a7_138;
		word32 a6_139;
		byte CVZN_141;
		word32 d0_144;
		byte ZN_145;
		bool C_146;
		bool V_147;
		bool Z_148;
		word32 a0_149;
		byte CVZNX_150;
		(*((char *) &a5_110->dwFFFFFAA8 + 0x05CA))();
		a5_110->aFFFFF578[d3_113] = d0_144;
		if (d0_144 == 0x00)
			return;
	}
	word32 d0_115 = a5_110->aFFFFF578[d3_113];
	a2_112->dw0008 = d0_115;
	a2_112->dw0000 = d0_115;
	a2_112->dw0018 = 0x0200;
	a2_112->dw0004 = 0x0200;
	a2_112->dw000E |= 0x1102;
}

// 00001680: void fn00001680(Stack word32 dwArg04, Stack (ptr32 Eq_322) dwArg08)
void fn00001680(word32 dwArg04, Eq_322 * dwArg08)
{
	if (dwArg04 == 0x00)
	{
		if (!__btst(dwArg08->t000E, 0x04))
			fn00001D80(dwArg08);
	}
	else
	{
		if (__btst(dwArg08->t000E, 0x04))
			return;
		fn00001D80(dwArg08);
		dwArg08->t000E &= ~0x1100;
		dwArg08->dw0018 = 0x00;
		dwArg08->dw0000 = 0x00;
		dwArg08->dw0008 = 0x00;
	}
}

// 000016D0: void fn000016D0(Register (ptr32 Eq_365) a5, Stack (ptr32 byte) dwArg08)
void fn000016D0(Eq_365 * a5, byte * dwArg08)
{
	byte v17_42 = *dwArg08;
	Eq_371 dwLoc0C_121 = 0x00;
	word32 d6_131 = DPB(d6, v17_42, 0);
	byte * dwArg08_122 = dwArg08 + 0x01;
	if (v17_42 != 0x00)
	{
		while (!DPB(CZ, false, 0))
		{
			int32 d0_139;
			ci8 v25_136 = (byte) d6_131 - 0x20;
			CZ = cond(v25_136);
			if (v25_136 >= 0x00 && (byte) d6_131 <= 0x78)
				d0_139 = (int32) (a5->aFFFFF7E8[(int32) (byte) d6_131] & 0x0F);
			else
				d0_139 = 0x00;
			word32 d0_150 = (int32) ((a5 + -2040 + dwLoc0C_121)[d0_139 * 0x08] >> 0x04);
			dwLoc0C_121 = d0_150;
			if (0x07 - d0_150 >= 0x00)
			{
				word32 a7_160;
				word32 a6_161;
				word32 a4_162;
				word32 a3_163;
				word32 a2_164;
				word32 d7_165;
				word32 d6_166;
				word32 d5_167;
				word32 d4_168;
				word32 d3_169;
				word32 a5_170;
				byte CVZN_171;
				word32 a0_172;
				byte CVZNX_173;
				byte ZN_174;
				bool C_175;
				bool V_176;
				bool Z_177;
				byte CZ_178;
				byte VZN_179;
				word32 d0_180;
				word32 d2_181;
				(0x1758 + (int32) (globals->a1758)[(int32) ((int16) d0_150) * 0x02])();
				return;
			}
			byte v38_183 = *dwArg08_122;
			d6_131 = DPB(d6_131, v38_183, 0);
			++dwArg08_122;
			if (v38_183 == 0x00)
				return;
		}
	}
}

// 00001C40: void fn00001C40(Register (ptr32 Eq_459) a5, Stack int32 dwArg04, Stack byte bArg07, Stack (ptr32 Eq_462) dwArg08, Stack (ptr32 int32) dwArg0C)
void fn00001C40(Eq_459 * a5, int32 dwArg04, byte bArg07, Eq_462 * dwArg08, int32 * dwArg0C)
{
	int32 d0_17;
	int32 v5_10 = dwArg08->dw0004 - 0x01;
	dwArg08->dw0004 = v5_10;
	if (v5_10 >= 0x00)
	{
		*dwArg08->ptr0000 = bArg07;
		byte * a0_45 = dwArg08->ptr0000;
		d0_17 = (int32) (int16) (int32) *a0_45;
		dwArg08->ptr0000 = a0_45 + 0x01;
	}
	else
		d0_17 = fn00001E94(a5, dwArg04, SLICE(dwArg04, byte, 24), dwArg08);
	if (-0x01 - d0_17 != 0x00)
		++*dwArg0C;
	else
		*dwArg0C = d0_17;
}

// 00001C84: void fn00001C84(Register (ptr32 Eq_459) a5, Stack int32 dwArg04, Stack word32 dwArg08, Stack (ptr32 Eq_462) dwArg0C, Stack (ptr32 int32) dwArg10)
void fn00001C84(Eq_459 * a5, int32 dwArg04, word32 dwArg08, Eq_462 * dwArg0C, int32 * dwArg10)
{
	Eq_524 VZN_28 = DPB(VZN, false, 0);
	if (!VZN_28)
	{
		do
		{
			fn00001C40(a5, dwArg04, SLICE(dwArg04, byte, 24), dwArg0C, dwArg10);
			VZN_28 = DPB(VZN_28, false, 0);
		} while (VZN_28);
	}
}

// 00001CC4: void fn00001CC4(Register (ptr32 Eq_459) a5, Stack (ptr32 byte) dwArg04, Stack word32 dwArg08, Stack (ptr32 Eq_462) dwArg0C, Stack (ptr32 int32) dwArg10)
void fn00001CC4(Eq_459 * a5, byte * dwArg04, word32 dwArg08, Eq_462 * dwArg0C, int32 * dwArg10)
{
	Eq_539 VZN_28 = DPB(VZN, false, 0);
	if (!VZN_28)
	{
		byte * d3_58 = dwArg04;
		do
		{
			int32 d0_80 = (int32) *d3_58;
			fn00001C40(a5, d0_80, SLICE(d0_80, byte, 24), dwArg0C, dwArg10);
			++d3_58;
			VZN_28 = DPB(VZN_28, false, 0);
		} while (VZN_28);
	}
}

// 00001D0C: void fn00001D0C(Stack (ptr32 word32) dwArg04)
void fn00001D0C(word32 * dwArg04)
{
	*dwArg04 += 0x04;
}

// 00001D24: Register int32 fn00001D24(Register (ptr32 Eq_566) a5, Stack (ptr32 Eq_322) dwArg04)
int32 fn00001D24(Eq_566 * a5, Eq_322 * dwArg04)
{
	if (dwArg04 == null)
		return fn00001E04(a5, 0x00);
	word32 d0_48 = fn00001D80(dwArg04);
	if (d0_48 != 0x00)
		return -0x01;
	bool Z_63 = __btst(dwArg04->t000E, 0x06);
	if (Z_63)
		return 0x00;
	word32 a7_69;
	word32 a6_70;
	word32 a2_71;
	byte CVZN_72;
	word32 d0_73;
	bool Z_74;
	word32 d2_75;
	byte ZN_76;
	bool C_77;
	bool V_78;
	word32 a5_79;
	(*((char *) &a5->dwFFFFF800 + 0x088A))();
	return (int32) (bool) cond(d0_73);
}

// 00001D80: Register int32 fn00001D80(Stack (ptr32 Eq_322) dwArg04)
int32 fn00001D80(Eq_322 * dwArg04)
{
	struct Eq_607 * d1_20 = dwArg04->dw000C;
	int32 d3_117 = 0x00;
	struct Eq_322 * a2_18 = dwArg04;
	if (0x02 - (d1_20 & 0x03) == 0x00 && ((word16) d1_20 & 0x0108) != 0x00)
	{
		int32 d0_72 = dwArg04->dw0008;
		int32 d4_74 = dwArg04->dw0000 - d0_72;
		if (d4_74 > 0x00)
		{
			word32 a7_88;
			word32 a6_89;
			word32 d4_91;
			byte CVZN_93;
			word32 d1_94;
			word32 d0_95;
			byte ZN_96;
			bool C_97;
			bool V_98;
			word32 d2_99;
			bool Z_100;
			byte CVZNX_101;
			byte VZN_102;
			word32 a5_103;
			(a5 + 0x0092)();
			if (d0_95 - d4_91 == 0x00)
			{
				struct Eq_607 * d0_108 = a2_18->dw000C;
				if (!__btst((byte) d0_108, 0x07))
				{
					struct Eq_607 * d0_111;
					__bclr(d0_108, 0x01, out d0_111);
					a2_18->dw000C = d0_111;
				}
			}
			else
			{
				__bset(a2_18->dw000F, 0x05, out a2_18->dw000F);
				d3_117 = -0x01;
			}
		}
	}
	a2_18->dw0000 = a2_18->dw0008;
	a2_18->dw0004 = 0x00;
	return d3_117;
}

// 00001DF4: void fn00001DF4(Register (ptr32 Eq_566) a5)
void fn00001DF4(Eq_566 * a5)
{
	fn00001E04(a5, 0x01);
}

// 00001E04: Register int32 fn00001E04(Register (ptr32 Eq_566) a5, Stack int32 dwArg04)
int32 fn00001E04(Eq_566 * a5, int32 dwArg04)
{
	struct Eq_322 * a2_104 = (char *) a5 - 2688;
	int32 d4_101 = 0x00;
	int32 d5_102 = 0x00;
	if ((char *) a5 - 2688 - a5->dwFFFFF800 <= 0x00)
	{
		do
		{
			if (dwArg04 == 0x01 && ((word16) a2_104->dw000C & 131) != 0x00)
			{
				if (fn00001D24(a5, a2_104) != ~0x00)
					++d4_101;
			}
			else if (dwArg04 == 0x00 && !__btst(a2_104->dw000F, 0x01))
			{
				int32 d0_118 = fn00001D24(a5, a2_104);
				if (d0_118 == ~0x00)
					d5_102 = d0_118;
			}
			++a2_104;
		} while (a2_104 - a5->dwFFFFF800 <= 0x00);
	}
	if (0x01 - dwArg04 != 0x00)
		d4_101 = d5_102;
	return d4_101;
}

// 00001E94: Register int32 fn00001E94(Register (ptr32 Eq_459) a5, Stack int32 dwArg04, Stack byte bArg07, Stack (ptr32 Eq_462) dwArg08)
int32 fn00001E94(Eq_459 * a5, int32 dwArg04, byte bArg07, Eq_462 * dwArg08)
{
	struct Eq_607 * d0_27 = dwArg08->ptr000C;
	struct Eq_462 * a3_122 = dwArg08;
	int32 d3_118 = dwArg08->dw0010;
	struct Eq_771 * a2_121 = &dwArg08->ptr000C;
	if (((word16) d0_27 & 0x82) != 0x00 && !__btst((byte) d0_27, 0x06))
	{
		if (__btst((byte) d0_27, 0x00))
		{
l00001EDA:
			struct Eq_607 * d0_91;
			__bset(dwArg08->ptr000C, 0x01, out d0_91);
			dwArg08->ptr000C = d0_91;
			struct Eq_607 * d0_95;
			__bclr(d0_91, 0x04, out d0_95);
			dwArg08->ptr000C = d0_95;
			dwArg08->dw0004 = 0x00;
			struct Eq_607 * d0_103 = dwArg08->ptr000C;
			cui16 v23_104 = (word16) d0_103 & 0x010C;
			int32 d4_102 = 0x00;
			ui32 d0_105 = DPB(d0_103, v23_104, 0);
			if (v23_104 == 0x00)
			{
				if (dwArg08 - ((char *) a5 - 2656) == 0x00 || dwArg08 - ((char *) a5 - 2624) == 0x00)
				{
					word32 a7_364;
					word32 a6_365;
					word32 d5_368;
					byte CVZN_371;
					word32 d1_373;
					byte ZN_374;
					bool C_375;
					bool V_376;
					bool Z_377;
					word32 a0_378;
					byte CVZNX_380;
					word32 d2_382;
					(*((char *) &a5->dwFFFFFAA8 + 0x05DA))();
					if (d0_105 != 0x00)
						goto l00001F1C;
				}
				fn00002014(d0_105, a5, a3_122);
			}
l00001F1C:
			int32 d5_148;
			if (((word16) a2_121->dw0000 & 0x0108) != 0x00)
			{
				byte * d0_189 = a3_122->ptr0008;
				d5_148 = a3_122->ptr0000 - d0_189;
				a3_122->ptr0000 = d0_189 + 0x01;
				a3_122->dw0004 = a3_122->dw0018 - 0x01;
				Eq_942 VZN_204 = DPB(VZN, false, 0);
				if (!VZN_204)
				{
					word32 a7_216;
					word32 a6_217;
					struct Eq_957 * a3_218;
					word32 d4_221;
					word32 d3_222;
					byte CVZN_223;
					int32 d0_224;
					word32 d1_225;
					byte ZN_226;
					bool C_227;
					bool V_228;
					bool Z_229;
					word32 a0_230;
					word32 a5_231;
					byte CVZNX_232;
					byte VZN_233;
					word32 d2_234;
					(*((char *) &a5->dwFFFFFAA8 + 1514))();
					*a3_218->ptr0008 = bArg07;
					d4_102 = d0_224;
				}
				else
				{
					ptr32 a0_242 = (char *) a5 - 0x06A8;
					bool Z_243 = __btst(a0_242 + d3_118, 0x05);
					if (!Z_243)
					{
						word32 a7_280;
						word32 a6_281;
						word32 d3_286;
						byte CVZN_287;
						word32 d0_288;
						word32 d1_289;
						byte ZN_290;
						bool C_291;
						bool V_292;
						bool Z_293;
						word32 a0_294;
						word32 a5_295;
						byte CVZNX_296;
						byte VZN_297;
						word32 d2_298;
						(*((char *) &a5->dwFFFFFAA8 + 1522))();
					}
					*a3_122->ptr0008 = bArg07;
				}
			}
			else
			{
				word32 a7_312;
				word32 a6_313;
				word32 a3_314;
				word32 d4_317;
				word32 d3_318;
				byte CVZN_319;
				int32 d0_320;
				word32 d1_321;
				byte ZN_322;
				bool C_323;
				bool V_324;
				bool Z_325;
				word32 a0_326;
				word32 a5_327;
				byte CVZNX_328;
				byte VZN_329;
				word32 d2_330;
				(*((char *) &a5->dwFFFFFAA8 + 1514))();
				d4_102 = d0_320;
			}
			if (d4_102 - d5_148 == 0x00)
				return dwArg04 & 0xFF;
			__bset(a2_121->t0003, 0x05, out a2_121->t0003);
			return -0x01;
		}
		dwArg08->dw0004 = 0x00;
		d0_27 = dwArg08->ptr000C;
		if (!__btst((byte) d0_27, 0x04))
		{
			dwArg08->ptr0000 = dwArg08->ptr0008;
			__bclr(dwArg08->t000F, 0x00, out dwArg08->t000F);
			goto l00001EDA;
		}
	}
	struct Eq_607 * d0_59;
	__bset(d0_27, 0x05, out d0_59);
	dwArg08->ptr000C = d0_59;
	return -0x01;
}

// 00001FD8: void fn00001FD8(Register (ptr32 Eq_1018) a5)
void fn00001FD8(Eq_1018 * a5)
{
	struct Eq_322 * d4_24 = (char *) a5 - 2592;
	if ((char *) a5 - 2592 - a5->dwFFFFF800 <= 0x00)
	{
		do
		{
			word32 d3_57;
			fn00002068(d4_24, out d3_57) == ~0x00;
			++d4_24;
		} while (d4_24 - a5->dwFFFFF800 <= 0x00);
	}
}

// 00002014: void fn00002014(Register ui32 d0, Register (ptr32 Eq_459) a5, Stack (ptr32 Eq_462) dwArg04)
void fn00002014(ui32 d0, Eq_459 * a5, Eq_462 * dwArg04)
{
	++a5->dwFFFFFAA8;
	word32 a7_20;
	word32 a6_21;
	struct Eq_1055 * a2_22;
	byte CVZN_23;
	word32 a5_24;
	byte CVZNX_25;
	ptr32 d0_26;
	bool Z_27;
	word32 a0_28;
	word32 d2_29;
	(*((char *) &a5->dwFFFFFAA8 + 0x05CA))();
	a2_22->ptr0008 = d0_26;
	if (d0_26 != 0x00)
	{
		__bset(a2_22->t000F, 0x03, out a2_22->t000F);
		a2_22->dw0018 = 0x0200;
	}
	else
	{
		__bset(a2_22->t000F, 0x02, out a2_22->t000F);
		a2_22->ptr0008 = (char *) &a2_22->t000F + 0x05;
		a2_22->dw0018 = 0x01;
	}
	a2_22->ptr0000 = a2_22->ptr0008;
	a2_22->dw0004 = 0x00;
}

// 00002068: Register int32 fn00002068(Stack (ptr32 Eq_322) dwArg04, Register out ptr32 d3Out)
int32 fn00002068(Eq_322 * dwArg04, ptr32 & d3Out)
{
	int32 d0_19 = dwArg04->dw000C;
	int32 d3_105 = -0x01;
	struct Eq_322 * a2_107 = dwArg04;
	if (__btst((byte) d0_19, 0x06))
	{
		if (((word16) d0_19 & 131) != 0x00)
		{
			fn00001D80(dwArg04);
			word32 d0_96 = fn000020F0(dwArg04);
			word32 a7_103;
			word32 a6_104;
			byte CVZN_106;
			word32 d0_108;
			bool Z_109;
			byte ZN_110;
			bool C_111;
			bool V_112;
			ptr32 a5_113;
			byte VN_114;
			word32 d2_115;
			(a5 + 0x00A2)();
			Eq_1158 VN_120 = DPB(VN_114, false, 0);
			if (!VN_120)
				d3_105 = -0x01;
			else
			{
				int32 d0_123 = a2_107->dw001C;
				if (d0_123 != 0x00)
				{
					word32 a7_130;
					word32 a6_131;
					word32 d3_132;
					byte CVZN_133;
					word32 a2_134;
					word32 d0_135;
					bool Z_136;
					byte ZN_137;
					bool C_138;
					bool V_139;
					ptr32 a5_140;
					byte VN_141;
					word32 d2_142;
					(a5_113 + 0x00B2)();
					word32 a7_153;
					word32 a6_154;
					byte CVZN_156;
					word32 d0_158;
					bool Z_159;
					byte ZN_160;
					bool C_161;
					bool V_162;
					word32 a5_163;
					byte VN_164;
					word32 d2_165;
					(a5_140 + 122)();
					a2_107->dw001C = 0x00;
				}
			}
		}
		a2_107->dw000C = 0x00;
		return d3_105;
	}
	else
	{
		dwArg04->dw000C = 0x00;
		return -0x01;
	}
}

// 000020F0: Register word32 fn000020F0(Stack (ptr32 Eq_322) dwArg04)
word32 fn000020F0(Eq_322 * dwArg04)
{
	word32 d0_14 = dwArg04->dw000C;
	if (((word16) d0_14 & 131) != 0x00)
	{
		bool Z_41 = __btst((byte) d0_14, 0x03);
		if (!Z_41)
		{
			word32 a7_47;
			word32 a6_48;
			struct Eq_1219 * a2_49;
			byte CVZN_50;
			word32 d1_52;
			byte ZN_53;
			bool C_54;
			bool V_55;
			bool Z_56;
			word32 a5_57;
			word32 d2_58;
			(a5 + 122)();
			__bclr(a2_49->t000F, 0x03, out a2_49->t000F);
			a2_49->dw0000 = 0x00;
			a2_49->dw0008 = 0x00;
			a2_49->dw0004 = 0x00;
		}
	}
	return d0_14;
}

// 000021F0: void fn000021F0(Register (ptr32 Eq_1252) a5)
void fn000021F0(Eq_1252 * a5)
{
	struct Eq_1253 * d0_19 = a5->ptrFFFFFAA0->ptr001C;
	struct Eq_1253 * a1_22 = d0_19;
	if (d0_19 != null)
	{
		int32 d1_48;
		for (d1_48 = 0x00; d1_48 < 0x03; ++d1_48)
		{
			word32 d0_55 = *a1_22->ptr0004;
			if (d0_55 != 0x45434F4E)
			{
				if (d0_55 == 0x46535953)
				{
					a5->aFFFFF958[d1_48] |= 0x01;
					struct Eq_1289 * a0_74 = *a1_22->ptr0008;
					struct Eq_1296 * a0_76 = DPB(a0_74, a0_74->w0002, 0);
					a0_76[d1_48 * 0x04] = (struct Eq_1296) a0_76;
				}
			}
			else
			{
				a5->aFFFFF958[d1_48] |= 0x41;
				a1_22[d1_48 * 0x04 / 0x0014] = (struct Eq_1253) a1_22;
			}
			++a1_22;
		}
	}
}

// 00002264: void fn00002264(Stack (ptr32 byte) dwArg04)
void fn00002264(byte * dwArg04)
{
	if (dwArg04 != null)
	{
		byte v11_39 = *dwArg04;
		if (v11_39 != 0x00)
		{
			byte * a2_43 = dwArg04;
			int32 d0_46;
			byte * a1_51 = dwArg04 + 0x01;
			for (d0_46 = (int32) v11_39; d0_46 != 0x00; --d0_46)
			{
				*a2_43 = *a1_51;
				++a1_51;
				++a2_43;
			}
			*a2_43 = 0x00;
		}
	}
}

// 00002294: void fn00002294(Register (ptr32 Eq_1353) a5, Stack word32 dwArg04)
void fn00002294(Eq_1353 * a5, word32 dwArg04)
{
	fn00002354(a5, dwArg04, 0x00, 0x00, 0x00);
}

// 000022C4: void fn000022C4(Register ptr32 a5)
void fn000022C4(ptr32 a5)
{
	fn000023B4(a5 + -744, a5 + -0x02E4);
	word32 a0_23 = fn000023B4(a5 + -0x02F0, a5 + -0x02EC);
	word32 a7_34;
	word32 a6_35;
	word32 a2_36;
	byte CVZN_37;
	ptr32 a5_38;
	bool Z_39;
	bool C_40;
	bool N_41;
	bool V_42;
	word32 a1_43;
	word32 d0_44;
	word32 a0_45;
	byte ZN_46;
	(a5 + 0x00C2)();
	0x00 = 0x00;
	word32 dwLoc16_55 = DPB(dwLoc16, 0xA1AD, 8);
	word32 a7_62;
	word32 a6_63;
	word32 a2_64;
	byte CVZN_65;
	struct Eq_1408 * a5_66;
	bool Z_67;
	bool C_68;
	bool N_69;
	bool V_70;
	word32 a1_71;
	word32 d0_72;
	word32 a0_73;
	byte ZN_74;
	(a5_38 + 0x00C2)();
	if (a2_64 - dwLoc16_55 != 0x00)
	{
		__syscall(0xA1AD);
		if (false)
			a5_66->dwFFFFF948 = a0_73;
	}
}

// 00002354: void fn00002354(Register (ptr32 Eq_1353) a5, Stack word32 dwArg04, Stack int32 dwArg08, Stack int32 dwArg0C, Stack byte bArg0F)
void fn00002354(Eq_1353 * a5, word32 dwArg04, int32 dwArg08, int32 dwArg0C, byte bArg0F)
{
	a5->bFFFFFA9C = bArg0F;
	if (dwArg08 == 0x00)
	{
		if (a5->ptrFFFFFD3C != null)
			fn000023B4(a5->ptrFFFFFD3C, a5->tFFFFFD38);
		fn000023B4((char *) &a5->ptrFFFFFAA0 + 0x0280, (char *) &a5->ptrFFFFFAA0 + 0x0288);
	}
	word32 a0_22 = fn000023B4((char *) &a5->ptrFFFFFAA0 + 0x028C, (char *) &a5->ptrFFFFFAA0 + 656);
	if (dwArg0C == 0x00)
	{
		if (a5->ptrFFFFFAA0 != null)
			a5->ptrFFFFFAA0->dw000E = dwArg04;
		word32 a7_43;
		word32 a6_44;
		word32 a5_45;
		byte CVZN_46;
		byte ZN_47;
		bool C_48;
		bool V_49;
		bool Z_50;
		word32 a0_51;
		(*((char *) &a5->ptrFFFFFD3C + 0x0326))();
	}
}

// 000023B4: Register (ptr32 word32) fn000023B4(Stack (ptr32 word32) dwArg04, Stack Eq_1370 dwArg08)
word32 * fn000023B4(word32 * dwArg04, Eq_1370 dwArg08)
{
	Eq_1370 d4_18 = dwArg08;
	word32 * d3_20 = dwArg04;
	if (dwArg08 - dwArg04 > 0x00)
	{
		do
		{
			a0 = d3_20;
			<anonymous> * d0_54 = *d3_20;
			if (d0_54 != null && d0_54 != (<anonymous> *) ~0x00)
			{
				word32 a7_75;
				word32 a6_76;
				word32 d5_77;
				byte CVZN_80;
				byte VZ_81;
				word32 d0_83;
				bool Z_84;
				byte CVZNX_85;
				byte CZ_86;
				d0_54();
			}
			++d3_20;
		} while (d4_18 - d3_20 > 0x00);
	}
	return a0;
}

// 000023F8: void fn000023F8(Register Eq_1512 a5, Stack ptr32 dwArg04)
void fn000023F8(Eq_1512 a5, ptr32 dwArg04)
{
	fn00002418(a5);
	fn0000243C(a5, dwArg04);
	<anonymous> * a0_18 = *((word32) a5 - 1288);
	word32 a7_19;
	word32 a6_20;
	byte CVZN_21;
	word32 a5_22;
	word32 a0_23;
	a0_18();
}

// 00002418: void fn00002418(Register Eq_1512 a5)
void fn00002418(Eq_1512 a5)
{
	fn0000243C(a5, 252);
	<anonymous> * a0_12 = *((word32) a5 - 1012);
	if (a0_12 != null)
	{
		word32 a7_26;
		word32 a6_27;
		word32 a0_29;
		word32 d0_30;
		byte CVZN_31;
		bool Z_32;
		a0_12();
	}
	fn0000243C(a5, 0xFF);
}

// 0000243C: void fn0000243C(Register Eq_1512 a5, Stack ptr32 dwArg04)
void fn0000243C(Eq_1512 a5, ptr32 dwArg04)
{
	int32 d1_104 = 0x00;
	struct Eq_1552 * d2_103 = (word32) a5 - 0x044C;
	while (dwArg04 - d2_103->dw0000 != 0x00)
	{
		++d2_103;
		++d1_104;
		if (d2_103 - (a5 + -1012) >=u 0x00)
			break;
	}
	if (dwArg04 - *((word32) a5 + (d1_104 * 0x08 - 0x044C)) == 0x00)
	{
		byte * a0_64 = *((word32) a5 + (d1_104 * 0x08 - 0x0448));
		byte * a1_65 = a0_64;
		do
		{
			a1_65 = a1_109 + 0x01;
			byte * a1_109 = a1_65;
		} while (*a1_109 != 0x00);
		word32 a7_87;
		word32 a6_88;
		word32 a2_89;
		byte CVZN_90;
		word32 a1_91;
		word32 a5_92;
		word32 d1_93;
		word32 a0_94;
		word32 d2_95;
		word32 d0_96;
		bool Z_97;
		byte CVZNX_98;
		bool C_99;
		byte ZN_100;
		bool V_101;
		(a5 + 0x0092)();
	}
}

// 000024B0: void fn000024B0(Register (ptr32 Eq_1610) a5, Stack Eq_1611 dwArg04)
void fn000024B0(Eq_1610 * a5, Eq_1611 dwArg04)
{
	fn000024C4(a5, fp - 0x04, dwArg04, a5->dwFFFFFAC4);
}

// 000024C4: void fn000024C4(Register (ptr32 Eq_1610) a5, Register ptr32 a6, Stack Eq_1611 dwArg04, Stack word32 dwArg08)
void fn000024C4(Eq_1610 * a5, ptr32 a6, Eq_1611 dwArg04, word32 dwArg08)
{
	if (-0x0020 - dwArg04 < 0x00)
		return;
	Eq_1629 d3_49 = DPB((word32) dwArg04 + 0x03, (word16) ((word32) dwArg04 + 0x03) & ~0x03, 0);
	do
	{
		*(fp - 0x10) = (union Eq_1629 *) d3_49;
		word32 d4_60;
		if (fn00002510(a5, fp - 0x04, dwArg00, out d4_60) != 0x00 || d4_60 == 0x00)
			return;
		*(fp - 0x10) = (union Eq_1629 *) d3_49;
	} while (fn00002644(a5, dwArg00) != 0x00);
}

// 00002510: Register int32 fn00002510(Register (ptr32 Eq_1610) a5, Register ptr32 a6, Stack (ptr32 Eq_1649) dwArg04, Register out ptr32 d4Out)
int32 fn00002510(Eq_1610 * a5, ptr32 a6, Eq_1649 * dwArg04, ptr32 & d4Out)
{
	*d4Out = d4;
	Eq_1673 a0_22;
	struct Eq_1674 * d0_23 = fn000027B0(a5, dwArg04, out a0_22);
	struct Eq_1674 * a2_139 = d0_23;
	if (d0_23 == null)
	{
		if (-0x01 - fn000028A0(a0_22, a5, fp - 0x04, dwArg04) == 0x00)
			return 0x00;
		*(fp - 0x10) = (struct Eq_1649 **) dwArg04;
		word32 a0_132;
		struct Eq_1674 * d0_133 = fn000027B0(a5, dwArg00, out a0_132);
		a2_139 = d0_133;
		if (d0_133 == null)
			fn000027A0();
	}
	struct Eq_607 * d0_55 = a2_139->ptr0000->ptr0004;
	word32 d1_58 = a2_139->dw0004;
	if (0x04 - ((DPB(d0_55, (word16) d0_55 & ~0x03, 0) - DPB(d1_58, (word16) d1_58 & ~0x03, 0)) - dwArg04) != 0x00)
	{
		*(fp - 0x10) = (struct Eq_1649 **) dwArg04;
		*(fp - 0x14) = (struct Eq_1674 **) a2_139;
		struct Eq_1778 * d0_103 = fn000025B4(a5, dwArg00, dwArg04);
		if (d0_103 != null)
		{
			struct Eq_607 * d0_111;
			__bclr(d0_103->ptr0004, 0x01, out d0_111);
			struct Eq_607 * d0_113;
			__bset(d0_111, 0x00, out d0_113);
			d0_103->ptr0004 = d0_113;
		}
	}
	word32 d0_74 = a2_139->dw0004;
	a2_139->dw0004 = DPB(d0_74, (word16) d0_74 & ~0x03, 0);
	a5->ptrFFFFFACC = a2_139->ptr0000;
	word32 d0_81 = a2_139->dw0004;
	return DPB(d0_81, (word16) d0_81 & ~0x03, 0) + 0x04;
}

// 000025B4: Register (ptr32 Eq_1688) fn000025B4(Register (ptr32 Eq_1610) a5, Stack (ptr32 Eq_1649) dwArg04, Stack (ptr32 Eq_1649) dwArg08)
Eq_1688 * fn000025B4(Eq_1610 * a5, Eq_1649 * dwArg04, Eq_1649 * dwArg08)
{
	struct Eq_1688 * a0_14 = dwArg04->ptr0000;
	struct Eq_607 * d0_15 = a0_14->ptr0004;
	word32 d1_18 = dwArg04->dw0004;
	if (DPB(d0_15, (word16) d0_15 & ~0x03, 0) - DPB(d1_18, (word16) d1_18 & ~0x03, 0) - 0x04 - dwArg08 <= 0x00)
		return null;
	word32 a0_58;
	struct Eq_1688 * d0_59 = fn0000273C(a0_14, a5, out a0_58);
	if (d0_59 == null)
		return null;
	word32 d0_65 = dwArg04->dw0004;
	struct Eq_1846 * d0_68 = dwArg08 + DPB(d0_65, (word16) d0_65 & ~0x03, 0) / 0x08;
	d0_59->ptr0004 = (struct Eq_607 *) &d0_68->ptr0004;
	d0_68->ptr0004 = d0_59;
	d0_59->ptr0000 = dwArg04->ptr0000;
	dwArg04->ptr0000 = d0_59;
	return d0_59;
}

// 00002610: void fn00002610(Register (ptr32 Eq_1868) a5, Stack word32 dwArg04)
void fn00002610(Eq_1868 * a5, word32 dwArg04)
{
	a5->dwFFFFFD34 = dwArg04;
}

// 00002644: Register int32 fn00002644(Register (ptr32 Eq_1610) a5, Stack (ptr32 Eq_1649) dwArg04)
int32 fn00002644(Eq_1610 * a5, Eq_1649 * dwArg04)
{
	<anonymous> * a0_9 = a5->ptrFFFFFD34;
	if (a0_9 == null)
		return 0x00;
	word32 a7_46;
	word32 a6_47;
	word32 a5_48;
	word32 a0_49;
	word32 d0_50;
	byte CVZN_51;
	bool Z_52;
	byte ZN_53;
	bool C_54;
	bool V_55;
	a0_9();
	if (d0_50 == 0x00)
		return 0x00;
	return 0x01;
}

// 0000273C: Register (ptr32 Eq_1688) fn0000273C(Register (ptr32 Eq_1688) a0, Register (ptr32 Eq_1610) a5, Register out ptr32 a0Out)
Eq_1688 * fn0000273C(Eq_1688 * a0, Eq_1610 * a5, ptr32 & a0Out)
{
	struct Eq_1688 * d0_17;
	if (a5->ptrFFFFFAD0 == null)
	{
		word32 a0_34;
		d0_17 = fn0000275C(a0, a5, out a0_34);
		if (d0_17 == null)
			return d0_17;
	}
	d0_17 = a5->ptrFFFFFAD0;
	a5->ptrFFFFFAD0 = d0_17->ptr0000;
	word32 a0_29;
	*a0Out = d0_17;
	return d0_17;
}

// 0000275C: Register int32 fn0000275C(Register (ptr32 Eq_1688) a0, Register (ptr32 Eq_1610) a5, Register out ptr32 a0Out)
int32 fn0000275C(Eq_1688 * a0, Eq_1610 * a5, ptr32 & a0Out)
{
	*a0Out = a0;
	__syscall(0xA11E);
	if (a0 == null)
		return 0x00;
	a5->ptrFFFFFAD0 = a0;
	struct Eq_1688 * d0_32 = a0;
	struct Eq_1688 * d1_38 = (char *) &a0->ptr0004 + 0x04;
	if (&a0->dw0FF8 - a0 > 0x00)
	{
		do
		{
			d0_32->ptr0000 = d1_66;
			d0_32 = d1_66;
			d1_38 = (struct Eq_1688 *) ((char *) &d1_66->ptr0004 + 0x04);
			struct Eq_1688 * d1_66 = d1_38;
		} while (&a0->dw0FF8 - d1_66 > 0x00);
	}
	a0->dw0FF8 = 0x00;
	word32 a0_46;
	*a0Out = (word32 *) &a0->dw0FF8;
	return 0x01;
}

// 000027A0: void fn000027A0()
void fn000027A0()
{
	word32 a7_13;
	word32 a6_14;
	word32 d2_15;
	byte CVZN_16;
	word32 a5_17;
	(a5 + 0x005A)();
}

// 000027B0: Register (ptr32 Eq_1688) fn000027B0(Register (ptr32 Eq_1610) a5, Stack (ptr32 Eq_1649) dwArg04, Register out ptr32 a0Out)
Eq_1688 * fn000027B0(Eq_1610 * a5, Eq_1649 * dwArg04, ptr32 & a0Out)
{
	*a0Out = a0;
	struct Eq_1688 * a2_111 = a5->ptrFFFFFACC;
	struct Eq_1688 * a1_33 = null;
	if ((char *) &a5->ptrFFFFFAD0 + 0x04 - a2_111 != 0x00)
	{
		do
		{
			ui32 * a4_210 = &a2_111->ptr0004;
			if ((*a4_210 & 0x03) == 0x01)
			{
				while (true)
				{
					struct Eq_1688 * a0_227 = a2_111->ptr0000;
					*a0Out = a0_227;
					struct Eq_607 * d0_228 = a0_227->ptr0004;
					ui32 d3_232 = *a4_210;
					if (DPB(d0_228, (word16) d0_228 & ~0x03, 0) - DPB(d3_232, (word16) d3_232 & ~0x03, 0) - 0x04 - dwArg04 >= 0x00)
						break;
					if ((d0_228 & 0x03) != 0x01)
						goto l0000280C;
					a2_111->ptr0000 = a0_227->ptr0000;
					a0_227->ptr0000 = a5->ptrFFFFFAD0;
					a5->ptrFFFFFAD0 = a0_227;
				}
l00002880:
				a1_33 = a2_111;
				return a1_33;
			}
l0000280C:
			a2_111 = a2_111->ptr0000;
		} while (a2_111 - ((char *) (&a5->ptrFFFFFAD0) + 0x04) != 0x00);
	}
	a2_111 = a5->ptrFFFFFAC8;
	if (a2_111 - a5->ptrFFFFFACC == 0x00)
		return a1_33;
	do
	{
		ui32 * a3_121 = &a2_111->ptr0004;
		if ((*a3_121 & 0x03) == 0x01)
		{
			do
			{
				struct Eq_1688 * a0_156 = a2_111->ptr0000;
				*a0Out = a0_156;
				struct Eq_607 * d3_157 = a0_156->ptr0004;
				ui32 d1_161 = *a3_121;
				if (DPB(d3_157, (word16) d3_157 & ~0x03, 0) - DPB(d1_161, (word16) d1_161 & ~0x03, 0) - 0x04 - dwArg04 >= 0x00)
					goto l00002880;
				if ((d3_157 & 0x03) != 0x01)
					goto l0000288C;
				a2_111->ptr0000 = a0_156->ptr0000;
				a0_156->ptr0000 = a5->ptrFFFFFAD0;
				a5->ptrFFFFFAD0 = a0_156;
			} while (a0_156 - a5->ptrFFFFFACC != 0x00);
			a5->ptrFFFFFACC = a2_111;
			struct Eq_1688 * a0_185 = a2_111->ptr0000;
			*a0Out = a0_185;
			struct Eq_607 * d0_186 = a0_185->ptr0004;
			ui32 d1_189 = *a3_121;
			if (DPB(d0_186, (word16) d0_186 & ~0x03, 0) - DPB(d1_189, (word16) d1_189 & ~0x03, 0) - 0x04 - dwArg04 >= 0x00)
				goto l00002880;
			return a1_33;
		}
l0000288C:
		a2_111 = a2_111->ptr0000;
	} while (a2_111 - a5->ptrFFFFFACC != 0x00);
	return null;
}

// 000028A0: Register int32 fn000028A0(Register Eq_1673 a0, Register (ptr32 Eq_1610) a5, Register ptr32 a6, Stack (ptr32 Eq_1649) dwArg04)
int32 fn000028A0(Eq_1673 a0, Eq_1610 * a5, ptr32 a6, Eq_1649 * dwArg04)
{
	int32 d4_262 = a5->dwFFFFFAF4;
	word32 a2_25 = DPB(a2, 0x10, 0);
	int32 d5_198 = -0x01;
	word32 d3_34 = DPB((char *) &dwArg04->dw0004 + 0x03, (word16) ((char *) &dwArg04->dw0004 + 0x03) & ~0x03, 0);
	if (d4_262 - a5->dwFFFFFAE0 < 0x00)
	{
		int32 d7_256 = d4_262 << 0x04;
		do
		{
			if (*((word32) *a5->tFFFFFADC + d7_256) != 0x00)
			{
				*(fp - 0x20) = d3_34;
				*(fp - 0x24) = d4_262;
				if (fn00002A54(a5, dwArg00, dwArg04) != ~0x00)
				{
					a5->dwFFFFFAF4 = d4_262;
					return 0x00;
				}
			}
			a0 = *a5->tFFFFFADC;
			if (*((word32) a0 + d7_256) == 0x00)
			{
				d5_198 = d4_262;
				break;
			}
			++d4_262;
			d7_256 += a2_25;
		} while (d4_262 - a5->dwFFFFFAE0 < 0x00);
	}
	if (-0x01 - d5_198 != 0x00)
	{
l000029B4:
		*(fp - 0x20) = d3_34;
		*(fp - 0x24) = d5_198;
		return fn000029C8(a0, a5, fp - 0x04, dwArg00, dwArg04);
	}
	if (a5->tFFFFFADC != 0x00)
	{
		a0 = a5->tFFFFFADC;
		__syscall(0xA024);
	}
	if (a5->tFFFFFADC != 0x00)
	{
		a0 = a5->tFFFFFAF0;
		if (*a0 == 0x00)
			goto l00002974;
	}
	__syscall(0xA122);
	if (a0 == 0x00)
		return -0x01;
	__syscall(41001);
	if (a5->tFFFFFADC != 0x00)
	{
		__syscall(0xA02E);
		__syscall(0xA023);
	}
	a5->tFFFFFADC = a0;
l00002974:
	a0 = (word32) *a5->tFFFFFADC + (a5->dwFFFFFAE0 << 0x04);
	int32 d0_144;
	for (d0_144 = 0x07; d0_144 != ~0x00; --d0_144)
	{
		*a0 = 0x00;
		struct Eq_2325 * a0_150 = (word32) a0 + 0x04;
		a0_150->dw0000 = 0x00;
		a0_150->dw0004 = 0x00;
		a0_150->dw0008 = 0x00;
		a0_150->dw000C = 0x00;
		a0_150->dw0010 = 0x00;
		a0_150->dw0014 = 0x00;
		a0_150->dw0018 = 0x00;
		a0_150->dw001C = 0x00;
		a0_150->dw0020 = 0x00;
		a0_150->dw0024 = 0x00;
		a0_150->dw0028 = 0x00;
		a0_150->dw002C = 0x00;
		a0_150->dw0030 = 0x00;
		a0_150->dw0034 = 0x00;
		a0_150->dw0038 = 0x00;
		a0 = &a0_150->dw0038 + 0x01;
	}
	d5_198 = a5->dwFFFFFAE0;
	a5->dwFFFFFAE0 += 0x0020;
	goto l000029B4;
}

// 000029C8: Register int32 fn000029C8(Register Eq_1673 a0, Register (ptr32 Eq_1610) a5, Register ptr32 a6, Stack ui32 dwArg04, Stack (ptr32 Eq_1649) dwArg08)
int32 fn000029C8(Eq_1673 a0, Eq_1610 * a5, ptr32 a6, ui32 dwArg04, Eq_1649 * dwArg08)
{
	word32 d4_18 = a5->dwFFFFFAEC;
	struct Eq_1649 * d4_136 = DPB(d4_18 + 0x0FFF, (word16) (d4_18 + 0x0FFF) & 0xF000, 0);
	if (d4_136 - dwArg08 < 0x00)
		d4_136 = dwArg08;
	int32 d0_104;
	__syscall(0xA11E);
	if (a0 != 0x00)
	{
		word32 a1_77 = *a5->tFFFFFADC;
		if (((word16) a0 & 0x03) != 0x00)
			*((word32) a0 + dwArg04 * 0x10) = DPB((word32) a0 + 0x03, (word16) ((word32) a0 + 0x03) & ~0x03, 0);
		else
			*((word32) a0 + dwArg04 * 0x10) = a0;
		struct Eq_2452 * a1_89 = a1_77 + (dwArg04 << 0x04);
		a1_89->t000C = a0;
		a1_89->ptr0008 = d4_136;
		a1_89->dw0004 = 0x00;
		d0_104 = fn00002A54(a5, dwArg04, dwArg08);
		if (d0_104 == 0x00)
			return d0_104;
		*(fp - 0x14) = dwArg04;
		fn00002AE0(a2, a5, dwArg00);
	}
	d0_104 = -0x01;
	return d0_104;
}

// 00002A54: Register int32 fn00002A54(Register (ptr32 Eq_1610) a5, Stack ui32 dwArg04, Stack (ptr32 Eq_1649) dwArg08)
int32 fn00002A54(Eq_1610 * a5, ui32 dwArg04, Eq_1649 * dwArg08)
{
	struct Eq_2485 * a2_101 = (word32) *a5->tFFFFFADC + (dwArg04 << 0x04);
	word32 d4_27 = a2_101->dw0008;
	word32 d1_28 = a2_101->dw0004;
	up32 d0_30 = d4_27 - d1_28;
	up32 d3_39 = DPB((char *) &dwArg08->ptr0000 + 0x03, (word16) ((char *) &dwArg08->ptr0000 + 0x03) & ~0x03, 0);
	struct Eq_607 * a1_125 = a2_101->dw0000 + d1_28;
	if (d3_39 - d0_30 > 0x00)
	{
		__syscall(0xA020);
		word32 d4_93 = d4_27 - d0_30 + d3_39;
		word32 d4_97 = DPB(d4_93 + 0x04, (word16) (d4_93 + 0x04) & ~0x03, 0);
		a2_101 = (word32) *a5->tFFFFFADC + (dwArg04 << 0x04);
		if (*a5->tFFFFFAF0 != 0x00)
			return -0x01;
		a2_101->dw0008 = d4_97;
		a1_125 = a2_101->dw0000 + a2_101->dw0004;
	}
	a2_101->dw0004 += d3_39;
	if (fn00002BB4(a5, a1_125, d3_39) != 0x00)
		fn000027A0();
	return 0x00;
}

// 00002AE0: void fn00002AE0(Register (arr Eq_3170) a2, Register (ptr32 Eq_1610) a5, Stack ui32 dwArg04)
void fn00002AE0(Eq_3170 a2[], Eq_1610 * a5, ui32 dwArg04)
{
	if (*((word32) *a5->tFFFFFADC + dwArg04 * 0x10) != 0x00)
		__syscall(0xA01F);
	a2[dwArg04].dw0000 = 0x00;
	a2[dwArg04].dw0004 = 0x00;
	a2[dwArg04].dw0008 = 0x00;
}

// 00002B18: void fn00002B18(Register (ptr32 Eq_2609) a5, Stack Eq_2610 dwArg04)
void fn00002B18(Eq_2609 * a5, Eq_2610 dwArg04)
{
	if (dwArg04 != 0x00)
	{
		struct Eq_2613 * a2_37 = *(dwArg04 - 0x04);
		struct Eq_607 * d1_38 = a2_37->ptr0004;
		if (DPB(d1_38, (word16) d1_38 & ~0x03, 0) - (dwArg04 - 0x04) != 0x00)
			fn000027A0();
		struct Eq_607 * d0_45;
		__bclr(a2_37->ptr0004, 0x01, out d0_45);
		struct Eq_607 * d0_47;
		__bset(d0_45, 0x00, out d0_47);
		a2_37->ptr0004 = d0_47;
		if (-0x01 - a5->tFFFFFAE4 != 0x00 && d0_47 - (a5->ptrFFFFFACC)->ptr0004 < 0x00)
		{
			word32 d1_61 = a2_37->ptr0000->dw0004;
			if (DPB(d1_61, (word16) d1_61 & ~0x03, 0) - DPB(d0_47, (word16) d0_47 & ~0x03, 0) - 0x04 - a5->tFFFFFAE4 >= 0x00)
				a5->ptrFFFFFACC = a2_37;
		}
	}
}

// 00002BB4: Register int32 fn00002BB4(Register (ptr32 Eq_1610) a5, Stack (ptr32 Eq_607) dwArg04, Stack up32 dwArg08)
int32 fn00002BB4(Eq_1610 * a5, Eq_607 * dwArg04, up32 dwArg08)
{
	struct Eq_1688 *** dwLoc1C_103 = fp + ~0x17;
	struct Eq_1688 * a0_29;
	struct Eq_1688 * d0_30 = fn0000273C(fp + ~0x17, a5, out a0_29);
	if (d0_30 != null)
	{
		struct Eq_1688 * a0_119;
		if (fn0000273C(a0_29, a5, out a0_119) == null)
			goto l00002DE8;
		word32 a0_125;
		if (fn0000273C(a0_119, a5, out a0_125) != null)
		{
			struct Eq_1688 * a3_147;
			Eq_2723 d0_139 = fn00002EA8(a5, dwArg04, fp + ~0x07);
			if (d0_139 == 0x00)
			{
				if (0x02 - (dwLoc08->ptr0004 & 0x03) != 0x00)
					goto l00002DE8;
				a3_147 = dwLoc08;
			}
			else
			{
				a3_147 = d0_30;
				dwLoc1C_103 = fp + ~0x13;
			}
			a3_147->ptr0004 = dwArg04;
			struct Eq_607 * d1_151;
			__bclr(dwArg04, 0x01, out d1_151);
			struct Eq_607 * d1_153;
			bool Z_154 = __bset(d1_151, 0x00, out d1_153);
			a3_147->ptr0004 = d1_153;
			dwArg04->ptr0000 = a3_147;
			if (0x03 - ((word32) d0_139 + 0x03) >= 0x00)
			{
				word32 a7_168;
				word32 a6_169;
				word32 a2_170;
				byte CVZN_171;
				word32 a3_172;
				word32 d2_173;
				word32 a0_174;
				int32 d0_175;
				bool Z_176;
				byte ZN_177;
				bool C_178;
				bool V_179;
				word32 d1_180;
				word32 a5_181;
				byte CVZNX_182;
				word32 a1_183;
				byte VZ_184;
				(11352 + (int32) (globals->a2C58)[(int32) ((int16) ((word32) d0_139 + 0x03)) * 0x02])();
				return d0_175;
			}
			if (0x02 - (dwLoc08->ptr0004 & 0x03) == 0x00)
			{
				if ((char *) &a5->ptrFFFFFAD0 + 0x04 - dwLoc08->ptr0000 == 0x00)
				{
					struct Eq_607 * d0_277 = a3_147->ptr0004;
					uint32 d0_280 = DPB(d0_277, (word16) d0_277 & ~0x03, 0) + dwArg08 / 0x04;
					if (d0_280 - a5->dwFFFFFAD8 > 0x00)
						a5->dwFFFFFAD8 = d0_280;
				}
				fn00002E18(a3_147, dwArg08, dwLoc08->ptr0000, fp + ~0x1B);
				struct Eq_607 * d0_223 = dwLoc08->ptr0000->ptr0004;
				struct Eq_607 * d1_227 = dwLoc08->ptr0004;
				up32 d0_230 = DPB(d0_223, (word16) d0_223 & ~0x03, 0) - DPB(d1_227, (word16) d1_227 & ~0x03, 0);
				fn00002E18(dwLoc08, d0_230, a3_147, fp + ~0x1B);
				struct Eq_607 * d0_241 = a5->ptrFFFFFACC->ptr0004;
				if (DPB(d0_241, (word16) d0_241 & ~0x03, 0) - dwArg04 > 0x00)
				{
					struct Eq_607 * d0_262 = a3_147->ptr0000->ptr0004;
					struct Eq_607 * d1_265 = a3_147->ptr0004;
					if (DPB(d0_262, (word16) d0_262 & ~0x03, 0) - DPB(d1_265, (word16) d1_265 & ~0x03, 0) - 0x04 - a5->dwFFFFFAE4 >= 0x00)
						a5->ptrFFFFFACC = a3_147;
				}
				return 0x00;
			}
		}
	}
l00002DE8:
	if (*dwLoc1C_103 != 0x00)
	{
		do
		{
			**dwLoc1C_103 = (struct Eq_1688 ***) a5->ptrFFFFFAD0;
			a5->ptrFFFFFAD0 = (struct Eq_1688 *) *dwLoc1C_103;
			struct Eq_1688 *** v30_111 = (char *) dwLoc1C_103 + 0x04;
			dwLoc1C_103 = v30_111;
		} while (*v30_111 != 0x00);
	}
	return -0x01;
}

// 00002E18: void fn00002E18(Stack (ptr32 Eq_1688) dwArg04, Stack up32 dwArg08, Stack (ptr32 Eq_1688) dwArg0C, Stack (ptr32 (ptr32 (ptr32 Eq_1688))) dwArg10)
void fn00002E18(Eq_1688 * dwArg04, up32 dwArg08, Eq_1688 * dwArg0C, Eq_1688 * * * dwArg10)
{
	struct Eq_607 * d2_18 = dwArg04->ptr0004;
	struct Eq_1688 * a2_121 = dwArg04;
	if (0x02 - (d2_18 & 0x03) != 0x00)
	{
		struct Eq_607 * d1_63 = dwArg0C->ptr0004;
		if ((d1_63 & 0x03) == 0x02)
		{
			struct Eq_607 * d2_72 = DPB(d2_18, (word16) d2_18 & ~0x03, 0) + dwArg08 / 0x04;
			dwArg0C->ptr0004 = d2_72;
			struct Eq_607 * d2_76;
			__bclr(d2_72, 0x00, out d2_76);
			struct Eq_607 * d2_78;
			__bset(d2_76, 0x01, out d2_78);
			dwArg0C->ptr0004 = d2_78;
			dwArg04->ptr0000 = dwArg0C;
			return;
		}
		struct Eq_607 * d2_95 = DPB(d2_18, (word16) d2_18 & ~0x03, 0) + dwArg08 / 0x04;
		if (DPB(d1_63, (word16) d1_63 & ~0x03, 0) - d2_95 != 0x00)
		{
			struct Eq_1688 ** a0_104 = *dwArg10;
			struct Eq_1688 * v33_105 = *a0_104;
			*dwArg10 = (struct Eq_1688 ***) ((char *) a0_104 + 0x04);
			v33_105->ptr0004 = d2_95;
			struct Eq_607 * d2_112;
			__bclr(d2_95, 0x00, out d2_112);
			struct Eq_607 * d2_114;
			__bset(d2_112, 0x01, out d2_114);
			v33_105->ptr0004 = d2_114;
			dwArg04->ptr0000 = v33_105;
			a2_121 = v33_105;
		}
	}
	a2_121->ptr0000 = dwArg0C;
}

// 00002EA8: Register int32 fn00002EA8(Register (ptr32 Eq_1610) a5, Stack (ptr32 Eq_607) dwArg04, Stack (ptr32 (ptr32 Eq_1688)) dwArg08)
int32 fn00002EA8(Eq_1610 * a5, Eq_607 * dwArg04, Eq_1688 * * dwArg08)
{
	if ((char *) &a5->ptrFFFFFAD0 + 0x04 - a5->ptrFFFFFAC8 == 0x00)
		return -0x03;
	struct Eq_607 * d0_35 = a5->ptrFFFFFAC8->ptr0004;
	if (DPB(d0_35, (word16) d0_35 & ~0x03, 0) - dwArg04 > 0x00)
		return -0x01;
	uint32 d0_48 = a5->dwFFFFFAD8;
	if (DPB(d0_48, (word16) d0_48 & ~0x03, 0) - dwArg04 <= 0x00)
		return -0x02;
	struct Eq_1688 * a1_61 = a5->ptrFFFFFAC8;
	while (true)
	{
		struct Eq_1688 * a0_63 = a1_61->ptr0000;
		struct Eq_607 * d1_64 = a0_63->ptr0004;
		if (DPB(d1_64, (word16) d1_64 & ~0x03, 0) - dwArg04 > 0x00)
			break;
		a1_61 = a0_63;
	}
	*dwArg08 = (struct Eq_1688 **) a1_61;
	struct Eq_607 * d1_76 = a1_61->ptr0004;
	int32 d0_75 = 0x00;
	if (DPB(d1_76, (word16) d1_76 & ~0x03, 0) - dwArg04 != 0x00)
		d0_75 = 0x01;
	return d0_75;
}

// 00003340: void fn00003340(Register (ptr32 Eq_3105) a5, Stack word16 wArg06)
void fn00003340(Eq_3105 * a5, word16 wArg06)
{
	a5->dwFFFFF940 = (int32) wArg06;
	int32 d2_19 = 0x00;
	struct Eq_3113 * d0_21 = &a5->dwFFFFF940 + 111;
	do
	{
		if (wArg06 - d0_21->w0000 == 0x00)
		{
			a5->dwFFFFF93C = (int32) a5->aFFFFFAFE[d2_19].w0000;
			return;
		}
		++d0_21;
		++d2_19;
	} while (d0_21 - (a5 + -0x044C) <u 0x00);
	a5->dwFFFFF93C = 22;
}


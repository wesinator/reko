// m68k_jump.c
// Generated by decompiling D:\dev\uxmal\reko\master\subjects\regressions\reko-121\m68k_jump.bin
// using Decompiler version 0.5.5.0.

#include "m68k_jump.h"

void fn0000C000(int32 d1, int32 * d4, int32 d5, Eq_5 * a0, int32 * a1, ui32 * a3)
{
	Mem54[0x00FF0F08 + 0x00:word32] = Mem0[a0 + 0x00:word32];
	*0x00FF0F04 = 0x00;
	int32 * a6_145 = a1;
	int32 d6_142 = 0x00;
	int32 a4_119 = 0x00;
	word32 d7_368 = 0xFF;
	a0_157 = a0;
l0000C3B4:
	while (true)
	{
		Eq_5 * a0_157;
		if (*0x00FF0F04 - *0x00FF0F08 >= 0x00)
			break;
		ui32 d3_121 = DPB(a4_119, (&a0->dw0004)[a4_119 / 0x0C], 0);
		a4_119 = a4_119 + 0x01;
		ui32 d3_122 = d3_121 & 0xFF;
		ci16 v31_129 = (word16) DPB(d3_121 & 0xFF, (byte) DPB(d3_121 & 0xFF, (word16) (d3_121 & 0xFF) & 0xF0, 0) >> 0x02, 0) - 44;
		if (v31_129 <= 0x00)
			switch (v31_129)
			{
			case 0x00:
				__btst(d4, 0xFF);
				break;
			case 0x01:
				d6_142 = DPB(__swap(DPB(d6_142, a0_157->b0002, 0)), Mem57[a0_157 + 0x00:byte], 0);
				*a6_145 = d6_142;
				Mem147[0x00FF0F04 + 0x00:word32] = Mem144[0x00FF0F04 + 0x00:word32] + 0x04;
				a6_145 = a6_145[0x01];
				break;
			case 0x02:
				d4 = (DPB(d3_121 & 0xFF, (byte) (d3_121 & 0xFF) & 0x0F, 0) << 0x08 | DPB(a4_119, (&a0->dw0004)[a4_119 / 0x0C], 0) & 0xFF) + 0x02 << 0x02;
				a0_157 = a6_145 - d4;
				a4_119 = a4_119 + 0x01;
				d6_142 = DPB(__swap(DPB(d6_142, a0_157->b0002, 0)), a0_157->b0001, 0);
				goto l0000C0FC;
			case 0x03:
				d1 = DPB(d1, (byte) d1 | 0x4E, 0);
				goto l0000C0FC;
			case 0x04:
				__btst(d4, 0xFF);
				while (true)
				{
					d3_122 = d3_122 - 0x01;
					if (d3_122 == ~0x00)
						break;
					d6_142 = DPB(__swap(DPB(d6_142, Mem57[a0 + 0x05 + a4_119:byte], 0)), Mem57[a0 + 0x07 + a4_119:byte], 0);
					*a6_145 = d6_142;
					Mem222[0x00FF0F04 + 0x00:word32] = Mem219[0x00FF0F04 + 0x00:word32] + 0x04;
					a4_119 = a4_119 + 0x04;
					a6_145 = a6_145[0x01];
				}
				break;
			case 0x05:
				*a6_145 = d6_142;
				Mem228[0x00FF0F04 + 0x00:word32] = Mem225[0x00FF0F04 + 0x00:word32] + 0x04;
				a6_145 = a6_145[0x01];
				break;
			case 0x06:
				ui32 d3_231 = d3_121 & 0xFF & 0xFF;
				d5 = 0x0F;
				d4 = null;
				d1 = 0x00;
				while ((byte) d3_231 != 0x00)
				{
					if (!__btst(d3_231, 0x00))
					{
						d6_142 = d6_142 & ~d5 | Mem57[a3 + DPB(d4, (word16) d4 << 0x02, 0):word32];
						d4 = d4 + 0x01;
					}
					*a3 = *a3 << 0x04;
					a0_157->dw0004 = a0_157->dw0004 << 0x04;
					a0_157->dw0008 = a0_157->dw0008 << 0x04;
					d3_231 = DPB(d3_231, (byte) d3_231 >> 0x01, 0);
					d5 = d5 << 0x04;
				}
				*a6_145 = d6_142;
				Mem250[0x00FF0F04 + 0x00:word32] = Mem247[0x00FF0F04 + 0x00:word32] + 0x04;
				a6_145 = a6_145[0x01];
				break;
			case 0x07:
				ui32 d3_339 = DPB(a4_119, (&a0->dw0004)[a4_119 / 0x0C], 0);
				a4_119 = a4_119 + 0x01;
				d4 = DPB(d3_339 & 0xFF, (byte) (d3_339 & 0xFF) >> 0x04, 0);
				d3_122 = DPB(d3_339 & 0xFF, (byte) (d3_339 & 0xFF) & 0x0F, 0);
				d6_142 = 0x00;
				goto l0000C22A;
			case 0x08:
l0000C22A:
				while (true)
				{
					d3_122 = d3_122 - 0x01;
					if (d3_122 == 0x00)
						break;
					d6_142 = d6_142 | d5;
					d5 = d5 << 0x04;
					d4 = d4 << 0x04;
				}
				goto l0000C240;
			case 0x09:
l0000C23E:
				d4 = d4 << 0x04;
				goto l0000C240;
			case 0x0A:
				do
				{
					d6_142 = d6_142 | d1;
					d1 = d1 << 0x04;
					d5 = d5 << 0x04;
					d4 = d4 << 0x04;
					d3_122 = d3_398 - 0x01;
					ui32 d3_398 = d3_122;
				} while (d3_398 != 0x00);
				while (true)
				{
					d7_368 = d7_368 - 0x01;
					if (d7_368 == 0x00)
						break;
					d6_142 = d6_142 | d5;
					d5 = d5 << 0x04;
					d4 = d4 << 0x04;
				}
				while (d4 != null)
				{
					d6_142 = d6_142 | d4;
					d4 = d4 << 0x04;
				}
				*a6_145 = d6_142;
				Mem387[0x00FF0F04 + 0x00:word32] = Mem384[0x00FF0F04 + 0x00:word32] + 0x04;
				a6_145 = a6_145[0x01];
				d7_368 = 0xFF;
				break;
			}
	}
	return;
}


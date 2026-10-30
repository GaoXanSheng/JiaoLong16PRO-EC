#include "ec_globals.h"

void f_0000(void)
{
    f_0070();
    return;
}

void f_0070(void)
{
    A = 0;
    DPTR = 0x2005;
    XD(DPTR) = A;
    DPTR = 0x2003;
    A = XD(DPTR);
    A &= 0x08;
    if (A != 0) goto L_009C;
    DPTR = 0x2006;
    A = XD(DPTR);
    A &= 0x03;
    if (A != 0x03) { C = (A < 0x03); goto L_008A; }
    A = XD(DPTR);
    XD(DPTR) = A;
    goto L_009C;
    L_009C:
    RB(0) = 0xFF;
    A = 0;
    L_009F:
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    if (--RB(0)) goto L_009F;
    DPTR = 0x8000;
    RB(7) = 0x00;
    RB(6) = 0x18;
    A = 0;
    L_00AA:
    XD(DPTR) = A;
    DPTR++;
    if (--RB(7)) goto L_00AA;
    if (--RB(6)) goto L_00AA;
    SP = 0xC0;
    DPTR = 0x1001;
    A = 0x3F;
    XD(DPTR) = A;
    f_280A();
    f_2D41();
    f_23E4();
    f_2D46();
    STACK[++SP] = A;
    DPTR = 0x2006;
    A = XD(DPTR);
    DPTR = 0x0082;
    XD(DPTR) = A;
    A = STACK[SP--];
    f_5864();
    f_0112();
    return;
    L_008A:
    A = XD(DPTR);
    A |= 0x07;
    XD(DPTR) = A;
    DPTR = 0x1F01;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x1F07;
    XD(DPTR) = A;
    L_009A:
    goto L_009A;
}

void f_0112(void)
{
    DPTR = 0x7178;
    L_0115:
    A = 0;
    RB(6) = 0x01;
    A = CD(DPTR + A);
    if (A == 0) goto L_00D7;
    DPTR++;
    RB(7) = A;
    A &= 0x3F;
    if (!((A >> 5) & 1)) goto L_012B;
    A &= 0x1F;
    RB(6) = A;
    A = 0;
    A = CD(DPTR + A);
    DPTR++;
    if (A == 0) goto L_012B;
    RB(6)++;
    L_012B:
    tmp = A; A = RB(7); RB(7) = tmp;
    A &= 0xC0;
    ADD8((A));
    if (A == 0) goto L_00DA;
    if (C != 0) goto L_00EC;
    A = 0;
    A = CD(DPTR + A);
    DPTR++;
    RB(2) = A;
    A = 0;
    A = CD(DPTR + A);
    DPTR++;
    RB(0) = A;
    L_013C:
    A = 0;
    A = CD(DPTR + A);
    DPTR++;
    tmp = A; A = RB(0); RB(0) = tmp;
    tmp = A; A = DPL; DPL = tmp;
    tmp = A; A = RB(0); RB(0) = tmp;
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = DPH; DPH = tmp;
    tmp = A; A = RB(2); RB(2) = tmp;
    XD(DPTR) = A;
    DPTR++;
    tmp = A; A = RB(0); RB(0) = tmp;
    tmp = A; A = DPL; DPL = tmp;
    tmp = A; A = RB(0); RB(0) = tmp;
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = DPH; DPH = tmp;
    tmp = A; A = RB(2); RB(2) = tmp;
    if (--RB(7)) goto L_013C;
    if (--RB(6)) goto L_013C;
    goto L_0115;
    L_00EC:
    A = 0;
    A = CD(DPTR + A);
    DPTR++;
    RB(0) = A;
    A &= 0x07;
    ADD8(0x0C);
    tmp = A; A = RB(0); RB(0) = tmp;
    C = 0;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    A = (A << 4) | (A >> 4);
    A &= 0x0F;
    A |= 0x20;
    tmp = A; A = RB(0); RB(0) = tmp;
    A = CD(0x00FE + A);
    if (C != 0) goto L_0104;
    A = ~A;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    goto L_0105;
    L_0105:
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    if (--RB(7)) goto L_00EC;
    goto L_0115;
    L_0104:
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    L_00DA:
    A = 0;
    A = CD(DPTR + A);
    DPTR++;
    RB(0) = A;
    L_00DE:
    A = 0;
    A = CD(DPTR + A);
    DPTR++;
    if (C != 0) goto L_00E6;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    goto L_00E7;
    L_00E7:
    RB(0)++;
    if (--RB(7)) goto L_00DE;
    goto L_0115;
    L_00E6:
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    L_00D7:
    f_0200();
    return;
}

void f_0169(void)
{
    DPTR = 0x170A;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_01AE;
    DPTR = 0x1106;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    DPTR = 0x1102;
    A = 0x04;
    XD(DPTR) = A;
    if (!BIT_RAM(0x60)) goto L_0198;
    A = 0;
    DPTR = 0x0043;
    XD(DPTR) = A;
    L_0186:
    f_07EB();
    if (C == 0) goto L_019B;
    DPTR = 0x170A;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_019B;
    f_07F7();
    goto L_0186;
    L_019B:
    f_07DC();
    RB(0) = 0x84;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x02;
    f_0802();
    DPTR = 0x170E;
    A = XD(DPTR);
    RB(0) = 0x99;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    goto L_01C5;
    L_01C5:
    f_28A5();
    return;
    L_0198:
    f_07D0();
    L_01AE:
    DPTR = 0x1700;
    A = 0x11;
    XD(DPTR) = A;
    DPTR = 0x1701;
    f_07BF();
    RB(0) = 0xAA;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x02;
    DPTR = 0x1106;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
}

void f_0200(void)
{
    f_0600();
    f_0DFB();
    SP = 0xC0;
    f_2483();
    DPTR = 0x1042;
    A = 0x07;
    XD(DPTR) = A;
    DPTR = 0x16E7;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    DPTR = 0x3105;
    A = 0x34;
    XD(DPTR) = A;
    RB(7) = 0x07;
    f_2B7A();
    f_2B7F();
    f_2B84();
    A = RB(7);
    A ^= 0x33;
    if (A != 0) goto L_0258;
    DPTR = 0x1000;
    A = XD(DPTR);
    A &= 0x7F;
    XD(DPTR) = A;
    SFR_F7 = 0x01;
    SFR_F7 = 0x01;
    SFR_F7 = 0x01;
    SFR_F7 = 0x01;
    A = 0;
    DPTR = 0x0045;
    XD(DPTR) = A;
    f_2B89();
    f_22ED();
    f_064D();
    goto L_0261;
    L_0261:
    f_2B93();
    A = RB(7);
    A = ~A;
    if (A != 0) goto L_0261;
    f_0F6F();
    f_064D();
    f_2B98();
    A = RB(7);
    if (A != 0) goto L_027B;
    f_2B9D();
    L_027B:
    RB(7) = DIR(0x26);
    A = RB(7);
    if (A != 0) goto L_0261;
    RB(7) = DIR(0x27);
    A = RB(7);
    if (A != 0) goto L_0261;
    f_2BA2();
    A = RB(7);
    if (A != 0) goto L_0261;
    SFR_87 = 0x01;
    goto L_0261;
    L_0258:
    f_23C1();
    f_2B8E();
    f_061A();
}

void f_0290(void)
{
    DPTR = 0x1709;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_02D5;
    DPTR = 0x1106;
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    DPTR = 0x1102;
    A = 0x08;
    XD(DPTR) = A;
    if (!BIT_RAM(0x60)) goto L_02BF;
    A = 0;
    DPTR = 0x0043;
    XD(DPTR) = A;
    L_02AD:
    f_07EB();
    if (C == 0) goto L_02C2;
    DPTR = 0x1709;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_02C2;
    f_07F7();
    goto L_02AD;
    L_02C2:
    f_07DC();
    RB(0) = 0x84;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x01;
    f_0802();
    DPTR = 0x170D;
    A = XD(DPTR);
    RB(0) = 0x98;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    goto L_02E6;
    L_02E6:
    f_28AA();
    return;
    L_02BF:
    f_07D0();
    L_02D5:
    DPTR = 0x1700;
    f_07B9();
    RB(0) = 0xAA;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x01;
    DPTR = 0x1106;
    A = XD(DPTR);
    A |= 0x08;
    XD(DPTR) = A;
}

void f_02E9(void)
{
    DPTR = 0x1708;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_032E;
    DPTR = 0x1106;
    A = XD(DPTR);
    A &= 0xEF;
    XD(DPTR) = A;
    DPTR = 0x1102;
    A = 0x10;
    XD(DPTR) = A;
    if (!BIT_RAM(0x60)) goto L_0318;
    A = 0;
    DPTR = 0x0043;
    XD(DPTR) = A;
    L_0306:
    f_07EB();
    if (C == 0) goto L_031B;
    DPTR = 0x1708;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_031B;
    f_07F7();
    goto L_0306;
    L_031B:
    f_07DC();
    A = 0;
    RB(0) = 0x84;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_0802();
    DPTR = 0x170C;
    A = XD(DPTR);
    RB(0) = 0x97;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    goto L_033F;
    L_033F:
    f_28AF();
    return;
    L_0318:
    f_07D0();
    L_032E:
    DPTR = 0x1701;
    f_07B9();
    A = 0;
    RB(0) = 0xAA;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x1106;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
}

void f_0539(void)
{
    STACK[++SP] = A;
    STACK[++SP] = B;
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    STACK[++SP] = PSW;
    PSW = 0x10;
    f_22C7();
    BIT_SET(0x35, 1);
    RB(7) = DIR(0x64);
    C = 1;
    A = RB(7);
    SUBB8(0x00);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_0564;
    DIR(0x64)--;
    RB(7) = DIR(0x64);
    A = RB(7);
    if (A != 0) goto L_0564;
    DIR(0x62) = 0xFF;
    DIR(0x63) = 0xFF;
    L_0564:
    PSW = STACK[SP--];
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    B = STACK[SP--];
    A = STACK[SP--];
    return;
}

void f_056F(void)
{
    STACK[++SP] = A;
    STACK[++SP] = B;
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    STACK[++SP] = PSW;
    PSW = 0x10;
    if (!BIT_RAM(0x6E)) goto L_0584;
    f_2B3E();
    goto L_05C8;
    L_05C8:
    f_2B43();
    PSW = STACK[SP--];
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    B = STACK[SP--];
    A = STACK[SP--];
    return;
    L_0584:
    DPTR = 0x1110;
    A = XD(DPTR);
    A ^= 0x22;
    if (A != 0) goto L_0591;
    f_0169();
    goto L_05C8;
    L_0591:
    DPTR = 0x1110;
    A = XD(DPTR);
    A ^= 0x23;
    if (A != 0) goto L_059E;
    f_0290();
    goto L_05C8;
    L_059E:
    DPTR = 0x1110;
    A = XD(DPTR);
    A ^= 0x24;
    if (A != 0) goto L_05AB;
    f_02E9();
    goto L_05C8;
    L_05AB:
    DPTR = 0x1110;
    A = XD(DPTR);
    B = 0x02;
    DPTR = 0x0639;
    f_7A15();
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
}

void f_05D6(void)
{
    STACK[++SP] = A;
    STACK[++SP] = B;
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    STACK[++SP] = PSW;
    PSW = 0x10;
    f_22E6();
    A = DIR(0x41);
    if (!((A >> 4) & 1)) goto L_05F3;
    BIT_SET(0x32, 1);
    DIR(0x41) &= 0xEF;
    f_22DB();
    L_05F3:
    PSW = STACK[SP--];
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    B = STACK[SP--];
    A = STACK[SP--];
    return;
}

void f_0600(void)
{
    SFR_A8 = (SFR_A8 & ~(1 << 7)) | (((0) & 1) << 7);
    return;
}

void f_0607(void)
{
    SFR_A8 = (SFR_A8 & ~(1 << 7)) | (((1) & 1) << 7);
    return;
}

void f_060A(void)
{
    DPTR = 0x1107;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    return;
}

void f_0612(void)
{
    DPTR = 0x1107;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    return;
}

void f_061A(void)
{
    DPTR = 0x1100;
    A = 0xFF;
    XD(DPTR) = A;
    DPTR = 0x1101;
    XD(DPTR) = A;
    DPTR = 0x1102;
    XD(DPTR) = A;
    DPTR = 0x1103;
    XD(DPTR) = A;
    DPTR = 0x1114;
    XD(DPTR) = A;
    DPTR = 0x1118;
    XD(DPTR) = A;
    DPTR = 0x111C;
    XD(DPTR) = A;
    DPTR = 0x1120;
    XD(DPTR) = A;
    DPTR = 0x1124;
    XD(DPTR) = A;
    DPTR = 0x1128;
    XD(DPTR) = A;
    DPTR = 0x1150;
    XD(DPTR) = A;
    SFR_A8 = (SFR_A8 & ~(1 << 2)) | (((1) & 1) << 2);
    f_0607();
    return;
}

void f_064D(void)
{
    f_0607();
    f_060A();
    f_0612();
    f_2B48();
    return;
}

void f_07B9(void)
{
    A = 0x11;
    XD(DPTR) = A;
    DPTR = 0x1702;
}

void f_07BF(void)
{
    XD(DPTR) = A;
    DPTR = 0x1106;
    A = XD(DPTR);
    A &= 0xE3;
    XD(DPTR) = A;
    DPTR = 0x1102;
    A = 0x1C;
    XD(DPTR) = A;
    BIT_SET(0x18, 1);
    return;
}

void f_07D0(void)
{
    A = 0;
    DPTR = 0x200B;
    XD(DPTR) = A;
    XD(DPTR) = A;
    XD(DPTR) = A;
    XD(DPTR) = A;
    XD(DPTR) = A;
    XD(DPTR) = A;
    XD(DPTR) = A;
    return;
}

void f_07DC(void)
{
    DPTR = 0x1700;
    A = 0x11;
    XD(DPTR) = A;
    DPTR = 0x1701;
    XD(DPTR) = A;
    DPTR = 0x1702;
    XD(DPTR) = A;
    return;
}

void f_07EB(void)
{
    DPTR = 0x0043;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x05);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_07F7(void)
{
    DPTR = 0x200B;
    XD(DPTR) = A;
    DPTR = 0x0043;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    return;
}

void f_0802(void)
{
    BIT_SET(0x34, 1);
    BIT_SET(0x18, 0);
    RB(0) = 0xAA;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xFF;
    return;
}

void f_080B(void)
{
    DPTR = 0x1500;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_0819;
    f_0974();
    f_081A();
    L_0819:
    return;
}

void f_081A(void)
{
    L_081A:
    DPTR = 0x1500;
    A = XD(DPTR);
    if (!((A >> 3) & 1)) goto L_0850;
    DPTR = 0x1504;
    A = XD(DPTR);
    DIR(0x35) = A;
    A = 0;
    DIR(0x36) = A;
    RB(7) = DIR(0x35);
    f_09E9();
    RB(7) = DIR(0x35);
    f_2B4D();
    DPTR = 0x83B2;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_0841;
    RB(7) = 0xAB;
    f_2B52();
    L_0841:
    DPTR = 0x83B2;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_0867;
    RB(7) = DIR(0x35);
    f_2B52();
    goto L_0867;
    L_0867:
    DPTR = 0x1500;
    A = XD(DPTR);
    A &= 0x10;
    if (A != 0) goto L_0872;
    if (!BIT_RAM(0x6D)) goto L_087A;
    L_0872:
    f_0954();
    A = RB(7);
    A ^= 0x01;
    if (A == 0) goto L_081A;
    L_087A:
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((1) & 1) << 3);
    f_0607();
    f_0612();
    f_2B5C();
    return;
    L_0850:
    DPTR = 0x1504;
    A = XD(DPTR);
    DIR(0x37) = A;
    RB(7) = DIR(0x36);
    A = RB(7);
    if (A == 0) goto L_0867;
    RB(7) = DIR(0x35);
    f_09B6();
    RB(7) = DIR(0x35);
    f_2B57();
    DIR(0x36)--;
}

void f_08CB(void)
{
    DPTR = 0x1501;
    A = RB(7);
    XD(DPTR) = A;
    A = 0;
    RB(7) = A;
    f_098A();
    return;
}

void f_08D5(void)
{
    RB(7) = DIR(0x36);
    A = RB(7);
    A ^= 0x01;
    if (A != 0) goto L_08E6;
    RB(7) = DIR(0x37);
    f_2B6B();
    f_08CB();
    BIT_SET(0x6D, 0);
    L_08E6:
    return;
}

void f_0954(void)
{
    L_0954:
    DPTR = 0x1500;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_0971;
    if (!((SFR_88 >> 7) & 1)) goto L_0954;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    A = XD(DPTR);
    A &= 0xEF;
    XD(DPTR) = A;
    A = 0;
    RB(7) = A;
    f_098A();
    BIT_SET(0x6D, 0);
    RB(7) = 0x00;
    return;
    L_0971:
    RB(7) = 0x01;
    return;
}

void f_0974(void)
{
    f_0600();
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    SFR_8D = 0xFA;
    SFR_8B = 0x01;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    return;
}

void f_098A(void)
{
    DPTR = 0x069D;
    A = RB(7);
    XD(DPTR) = A;
    A ^= 0x01;
    if (A != 0) goto L_0996;
    f_0600();
    L_0996:
    DPTR = 0x1604;
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x200B;
    XD(DPTR) = A;
    XD(DPTR) = A;
    DPTR = 0x1604;
    A = XD(DPTR);
    A |= 0x08;
    XD(DPTR) = A;
    DPTR = 0x069D;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_09B5;
    f_0607();
    L_09B5:
    return;
}

void f_09B6(void)
{
    A = RB(7);
    f_7A4A();
    RB(1)++;
    C = 1;
    goto L_09C7;
    L_09C7:
    if (--RB(7)) goto L_094D;
    RB(1)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    BIT_SET(0x09, C);
    A = SFR_93;
    RB(1)++;
    A = RB(0);
    f_08D5();
    return;
    L_094D:
    f_0A28();
    A = DIR(0x37);
    XD(DPTR) = A;
    return;
}

void f_09E9(void)
{
    A = RB(7);
    f_7A4A();
    RB(2)++;
    RB(4)++;
    goto L_09FB;
    L_09FB:
    if (B == 0) { C = 0; } else { tmp = A % B; A = A / B; B = tmp; C = 0; }
    RB(2)++;
    RB(3)--;
    BIT_SET(0x0A, C);
    RB(6)--;
    A = CD(DPTR + A);
    RB(2)++;
    f_09DC();
    return;
}

void f_0A28(void)
{
    A = RB(7);
    RB(6) = A;
    RB(4) = 0x00;
    A = 0;
    ADD8(RB(5));
    RB(7) = A;
    A = RB(4);
    ADDC8(RB(6));
    RB(0) = 0xB7;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)--;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    return;
}

void f_0A41(void)
{
    f_0DE8();
    A |= 0x10;
    XD(DPTR) = A;
    DPTR = 0x1300;
    A = XD(DPTR);
    A &= 0xFC;
    XD(DPTR) = A;
    if (!BIT_RAM(0x00)) goto L_0A55;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    L_0A55:
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(5);
    tmp = A; A = RB(7); RB(7) = tmp;
    DPTR = 0x1306;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x8109;
    A = 0x64;
    XD(DPTR) = A;
    return;
}

void f_0A64(void)
{
    f_0A41();
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    SFR_8D = 0xB2;
    SFR_8B = 0x19;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    L_0A79:
    if (((SFR_88 >> 7) & 1)) goto L_0A86;
    f_0DF4();
    if (A == 0) goto L_0A86;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_0A79;
    L_0A86:
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((1) & 1) << 3);
    return;
}

void f_0A8D(void)
{
    DPTR = 0x004B;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x03);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_0AA8;
    f_0DDB();
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x004B;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    f_0B19();
    L_0AA8:
    return;
}

void f_0AA9(void)
{
    DPTR = 0x004C;
    f_0DDB();
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x004C;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    DPTR = 0x004B;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x004C;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(6));
    if (C != 0) goto L_0ADB;
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x004B;
    XD(DPTR) = A;
    RB(6) = DIR(0x4A);
    A = RB(6);
    A = (A << 4) | (A >> 4);
    A &= 0x0F;
    RB(6) = A;
    A = DIR(0x4A);
    A &= 0x0F;
    A ^= RB(6);
    if (A != 0) goto L_0ADB;
    DIR(0x41) &= 0xEF;
    L_0ADB:
    return;
}

void f_0ADC(void)
{
    DPTR = 0x0698;
    A = RB(7);
    XD(DPTR) = A;
    f_0DF4();
    if (A != 0) goto L_0AEB;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_0AF3;
    L_0AEB:
    DPTR = 0x0698;
    A = XD(DPTR);
    RB(7) = A;
    f_0A8D();
    return;
    L_0AF3:
    DPTR = 0x0698;
    A = XD(DPTR);
    RB(7) = A;
    f_0A41();
    return;
}

void f_0B19(void)
{
    f_22DB();
    DIR(0x41) |= 0x10;
    return;
}

void f_0B20(void)
{
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    f_0B19();
    f_0DF4();
    if (A != 0) goto L_0B7A;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_0B7A;
    DPTR = 0x004B;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x00);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_0B45;
    f_0AA9();
    f_0A41();
    return;
    L_0B45:
    if (BIT_RAM(0x04)) goto L_0B7A;
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_0B7A;
    f_2B75();
    A = RB(7);
    A = ~A;
    if (A != 0) goto L_0B5C;
    DIR(0x41) &= 0xEF;
    goto L_0B62;
    L_0B62:
    DPTR = 0x0693;
    A = XD(DPTR);
    if (A == 0) goto L_0B7A;
    C = BIT_RAM(0x57);
    A = 0;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(6) = A;
    BIT_SET(0x57, 0);
    tmp = A; A = RB(5); RB(5) = tmp;
    A = RB(6);
    tmp = A; A = RB(5); RB(5) = tmp;
    f_0B7B();
    A = RB(7);
    if (A == 0) goto L_0B7A;
    BIT_SET(0x57, 1);
    L_0B7A:
    return;
    L_0B5C:
    DPTR = 0x0693;
    A = 0x01;
    XD(DPTR) = A;
}

void f_0B7B(void)
{
    tmp = A; A = RB(6); RB(6) = tmp;
    A = RB(5);
    tmp = A; A = RB(6); RB(6) = tmp;
    tmp = A; A = RB(5); RB(5) = tmp;
    tmp = A; A = RB(5); RB(5) = tmp;
    f_0B83();
    return;
}

void f_0B83(void)
{
    DPTR = 0x0694;
    A = RB(5);
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    if (BIT_RAM(0x06)) goto L_0B97;
    A++;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x0694;
    XD(DPTR) = A;
    goto L_0BBB;
    L_0BBB:
    DPTR = 0x0695;
    A = XD(DPTR);
    if (A == 0) goto L_0BC4;
    f_0A41();
    L_0BC4:
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    return;
    L_0B97:
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(5) = A;
    f_0BCA();
    A = RB(7);
    RB(5) = A;
    RB(4) = 0x00;
    A = ~A;
    if (A != 0) goto L_0BA8;
    goto L_0BAC;
    L_0BAC:
    DPTR = 0x0694;
    A++;
    XD(DPTR) = A;
    goto L_0BBB;
    L_0BA8:
    A = RB(5);
    A |= RB(4);
    if (A != 0) goto L_0BB3;
    L_0BB3:
    A = 0;
    DPTR = 0x0694;
    XD(DPTR) = A;
    DPTR++;
    A++;
    XD(DPTR) = A;
}

void f_0BCA(void)
{
    A = 0;
    RB(6) = A;
    A = RB(7);
    RB(3) = A;
    RB(2) = 0x00;
    A ^= 0xF0;
    if (A != 0) goto L_0BD8;
    RB(7) = 0xFF;
    goto L_0C06;
    L_0C06:
    A = RB(6);
    if (A == 0) goto L_0C13;
    tmp = A; A = RB(6); RB(6) = tmp;
    A = RB(5);
    tmp = A; A = RB(6); RB(6) = tmp;
    A = RB(6);
    if (A == 0) goto L_0C13;
    A = RB(7);
    A |= 0x80;
    RB(7) = A;
    L_0C13:
    return;
    L_0BD8:
    A = RB(3);
    A |= RB(2);
    if (A != 0) goto L_0BDF;
    RB(7) = A;
    goto L_0C06;
    L_0BDF:
    A = RB(7);
    A &= 0x80;
    if (A != 0) goto L_0BEE;
    A = RB(7);
    DPTR = 0x0D45;
    A = CD(DPTR + A);
    RB(7) = A;
    RB(6) = 0x01;
    goto L_0C06;
    L_0BEE:
    A = RB(7);
    RB(3) = A;
    RB(2) = 0x00;
    A ^= 0x83;
    if (A != 0) goto L_0BFC;
    RB(7) = 0x41;
    RB(6) = 0x01;
    goto L_0C06;
    L_0BFC:
    A = RB(3);
    A ^= 0x84;
    A |= RB(2);
    if (A != 0) goto L_0C06;
    RB(7) = 0x54;
    RB(6) = 0x01;
}

void f_0C8A(void)
{
    DPTR = 0x3207;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_0CBD;
    DPTR = 0x3206;
    A = 0x8F;
    XD(DPTR) = A;
    DIR(0x6B) = 0xEA;
    DIR(0x6C) = 0x60;
    L_0C9E:
    DPTR = 0x3207;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_0CB4;
    A = DIR(0x6C);
    DIR(0x6C)--;
    if (A != 0) goto L_0CAE;
    DIR(0x6B)--;
    L_0CAE:
    A = DIR(0x6C);
    A |= DIR(0x6B);
    if (A != 0) goto L_0C9E;
    L_0CB4:
    DPTR = 0x3206;
    A = 0x87;
    XD(DPTR) = A;
    f_5AC6();
    L_0CBD:
    DPTR = 0x3203;
    A = XD(DPTR);
    A &= 0x04;
    if (A == 0) goto L_0CF6;
    DPTR = 0x3204;
    A = XD(DPTR);
    A |= 0x11;
    XD(DPTR) = A;
    DIR(0x6B) = 0xEA;
    DIR(0x6C) = 0x60;
    L_0CD2:
    DPTR = 0x3203;
    A = XD(DPTR);
    A &= 0x04;
    if (A == 0) goto L_0CE8;
    A = DIR(0x6C);
    DIR(0x6C)--;
    if (A != 0) goto L_0CE2;
    DIR(0x6B)--;
    L_0CE2:
    A = DIR(0x6C);
    A |= DIR(0x6B);
    if (A != 0) goto L_0CD2;
    L_0CE8:
    DPTR = 0x3204;
    A = XD(DPTR);
    A |= 0x10;
    DIR(0x65) = A;
    DIR(0x65) &= 0xEF;
    A = DIR(0x65);
    XD(DPTR) = A;
    L_0CF6:
    return;
}

void f_0CF7(void)
{
    DPTR = 0x3241;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_0D0B;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_0D0B;
    DPTR = 0x3240;
    A = XD(DPTR);
    A |= 0x11;
    XD(DPTR) = A;
    L_0D0B:
    DPTR = 0x3241;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_0D23;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_0D23;
    DPTR = 0x3240;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    L_0D23:
    return;
}

void f_0D24(void)
{
    DPTR = 0x310F;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_0D44;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_0D44;
    DPTR = 0x3205;
    A = 0x99;
    XD(DPTR) = A;
    DPTR = 0x3104;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_0D44;
    A = 0;
    DPTR = 0x16A6;
    XD(DPTR) = A;
    L_0D44:
    return;
}

void f_0DDB(void)
{
    A = XD(DPTR);
    A &= 0x03;
    ADD8(0x47);
    DPL = A;
    A = 0;
    ADDC8(0x00);
    DPH = A;
    return;
}

void f_0DE8(void)
{
    tmp = A; A = RB(5); RB(5) = tmp;
    A = RB(7);
    tmp = A; A = RB(5); RB(5) = tmp;
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0x0F;
    XD(DPTR) = A;
    A = XD(DPTR);
    return;
}

void f_0DF4(void)
{
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0x01;
    return;
}

void f_0DFB(void)
{
    A = 0;
    DPTR = 0x1000;
    XD(DPTR) = A;
    DPTR = 0x2005;
    XD(DPTR) = A;
    DPTR = 0x1020;
    A = 0x08;
    XD(DPTR) = A;
    DPTR = 0x1031;
    A = 0x1E;
    XD(DPTR) = A;
    DPTR = 0x1036;
    A = 0x84;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x103A;
    XD(DPTR) = A;
    DPTR = 0x1051;
    XD(DPTR) = A;
    DPTR = 0x1054;
    XD(DPTR) = A;
    DPTR = 0x1058;
    XD(DPTR) = A;
    DPTR = 0x1063;
    XD(DPTR) = A;
    DPTR = 0x1064;
    XD(DPTR) = A;
    DPTR = 0x1072;
    XD(DPTR) = A;
    DPTR = 0x1075;
    XD(DPTR) = A;
    DPTR = 0x1112;
    XD(DPTR) = A;
    DPTR = 0x1113;
    XD(DPTR) = A;
    DPTR = 0x1306;
    XD(DPTR) = A;
    DPTR = 0x1600;
    A = 0x04;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x16F7;
    XD(DPTR) = A;
    DPTR = 0x16F8;
    XD(DPTR) = A;
    DPTR = 0x16F9;
    XD(DPTR) = A;
    DPTR = 0x16FA;
    XD(DPTR) = A;
    DPTR = 0x16FB;
    XD(DPTR) = A;
    DPTR = 0x16FC;
    XD(DPTR) = A;
    DPTR = 0x16FF;
    XD(DPTR) = A;
    DPTR = 0x1914;
    XD(DPTR) = A;
    DPTR = 0x1915;
    XD(DPTR) = A;
    DPTR = 0x191C;
    XD(DPTR) = A;
    DPTR = 0x191D;
    A = 0x04;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x1D05;
    XD(DPTR) = A;
    DPTR = 0x1E02;
    XD(DPTR) = A;
    DPTR = 0x1E03;
    A++;
    XD(DPTR) = A;
    DPTR = 0x1E04;
    A = 0x70;
    XD(DPTR) = A;
    DPTR = 0x1E05;
    A = 0x51;
    XD(DPTR) = A;
    DPTR = 0x1E09;
    A = 0x01;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x1E0A;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x2006;
    A = 0x4C;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x200A;
    XD(DPTR) = A;
    DPTR = 0x200C;
    A = 0x09;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x200D;
    XD(DPTR) = A;
    DPTR = 0x2010;
    A = 0x13;
    XD(DPTR) = A;
    DPTR = 0x2012;
    A = 0x20;
    XD(DPTR) = A;
    DPTR = 0x2014;
    A = 0x03;
    XD(DPTR) = A;
    DPTR = 0x2015;
    A = 0x80;
    XD(DPTR) = A;
    DPTR = 0x2016;
    A = 0x14;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x201B;
    XD(DPTR) = A;
    DPTR = 0x201D;
    XD(DPTR) = A;
    DPTR = 0x201E;
    XD(DPTR) = A;
    DPTR++;
    A = 0x80;
    XD(DPTR) = A;
    DPTR = 0x3105;
    A = 0x0A;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x3115;
    XD(DPTR) = A;
    DPTR = 0x31A1;
    XD(DPTR) = A;
    DPTR = 0x31A2;
    XD(DPTR) = A;
    DPTR = 0x3292;
    A = 0x40;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x3295;
    XD(DPTR) = A;
    DPTR = 0x3297;
    XD(DPTR) = A;
    return;
}

void f_0F6F(void)
{
    L_0F6F:
    RB(7) = DIR(0x26);
    A = RB(7);
    if (A != 0) goto L_0F84;
    RB(7) = DIR(0x27);
    A = RB(7);
    if (A != 0) goto L_0F84;
    f_2BA2();
    A = RB(7);
    A ^= 0x01;
    if (A == 0) goto L_0F84;
    f_1049();
    return;
    L_0F84:
    DPTR = 0x160A;
    A = XD(DPTR);
    A &= 0x04;
    if (A == 0) goto L_0FAC;
    DPTR = 0x3205;
    A = XD(DPTR);
    A ^= 0x99;
    if (A != 0) goto L_0FA9;
    f_0CF7();
    f_0C8A();
    DPTR = 0x00F5;
    A = XD(DPTR);
    A ^= 0x03;
    if (A != 0) goto L_0FAC;
    A++;
    XD(DPTR) = A;
    f_5AC7();
    goto L_0FAC;
    L_0FAC:
    if (!BIT_RAM(0x30)) goto L_0FB6;
    BIT_SET(0x30, 0);
    f_11AB();
    goto L_0F6F;
    L_0FB6:
    if (!BIT_RAM(0x31)) goto L_0FC0;
    BIT_SET(0x31, 0);
    f_107C();
    goto L_0F6F;
    L_0FC0:
    if (!BIT_RAM(0x32)) goto L_0FCA;
    BIT_SET(0x32, 0);
    f_0B20();
    goto L_0F6F;
    L_0FCA:
    if (!BIT_RAM(0x33)) goto L_0FD4;
    BIT_SET(0x33, 0);
    f_2BA7();
    goto L_0F6F;
    L_0FD4:
    if (!BIT_RAM(0x34)) goto L_0FDE;
    BIT_SET(0x34, 0);
    f_2BAC();
    goto L_0F6F;
    L_0FDE:
    f_2BB1();
    if (!BIT_RAM(0x35)) goto L_0FEB;
    BIT_SET(0x35, 0);
    f_107F();
    goto L_0F6F;
    L_0FEB:
    if (!BIT_RAM(0x36)) goto L_0FF6;
    BIT_SET(0x36, 0);
    f_080B();
    f_0F6F();
    return;
    L_0FF6:
    f_2BB6();
    if (!BIT_RAM(0x38)) goto L_1004;
    BIT_SET(0x38, 0);
    f_104A();
    f_0F6F();
    return;
    L_1004:
    if (!BIT_RAM(0x39)) goto L_100F;
    BIT_SET(0x39, 0);
    f_2BBB();
    f_0F6F();
    return;
    L_100F:
    if (!BIT_RAM(0x3A)) goto L_1017;
    BIT_SET(0x3A, 0);
    f_0F6F();
    return;
    L_1017:
    if (!BIT_RAM(0x3C)) goto L_1022;
    BIT_SET(0x3C, 0);
    f_2BC0();
    f_0F6F();
    return;
    L_1022:
    if (!BIT_RAM(0x3D)) goto L_102D;
    BIT_SET(0x3D, 0);
    f_2BC5();
    f_0F6F();
    return;
    L_102D:
    if (!BIT_RAM(0x3E)) goto L_1038;
    BIT_SET(0x3E, 0);
    f_2BCA();
    f_0F6F();
    return;
    L_1038:
    if (!BIT_RAM(0x3F)) goto L_1043;
    BIT_SET(0x3F, 0);
    f_2BCF();
    f_0F6F();
    return;
    L_1043:
    f_2BD4();
    f_0F6F();
    return;
    L_0FA9:
    f_0D24();
}

void f_104A(void)
{
    DPTR = 0x004B;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x004C;
    A = XD(DPTR);
    A ^= RB(7);
    if (A != 0) goto L_1064;
    RB(7) = DIR(0x4A);
    A = RB(7);
    A = (A << 4) | (A >> 4);
    A &= 0x0F;
    RB(7) = A;
    A = DIR(0x4A);
    A &= 0x0F;
    A ^= RB(7);
    if (A == 0) goto L_1067;
    L_1064:
    f_0B19();
    L_1067:
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_1071;
    BIT_SET(0x30, 1);
    L_1071:
    DPTR = 0x1500;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_107B;
    BIT_SET(0x36, 1);
    L_107B:
    return;
}

void f_107C(void)
{
    f_2BD9();
    return;
}

void f_107F(void)
{
    f_1164();
    DIR(0x43)++;
    RB(7) = DIR(0x43);
    C = 0;
    A = RB(7);
    SUBB8(0x0A);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_1093;
    A = 0;
    DIR(0x43) = A;
    L_1093:
    f_2BDE();
    A = RB(7);
    A ^= 0x01;
    if (A != 0) goto L_109E;
    f_1163();
    return;
    L_109E:
    A = DIR(0x43);
    B = 0x05;
    if (B == 0) { C = 0; } else { tmp = A % B; A = A / B; B = tmp; C = 0; }
    A = B;
    if (A == 0) goto L_10AB;
    f_1163();
    return;
    L_10AB:
    f_116C();
    DIR(0x44)++;
    A = DIR(0x44);
    if (!((A >> 0) & 1)) goto L_10B8;
    f_1178();
    return;
    L_10B8:
    f_117E();
    A = DIR(0x44);
    ADD8(0xFC);
    if (A == 0) goto L_10D2;
    ADD8(0xFE);
    if (A == 0) goto L_10D7;
    ADD8(0xFE);
    if (A == 0) goto L_10DC;
    ADD8(0x06);
    if (A != 0) goto L_10ED;
    f_1181();
    goto L_10F0;
    L_10F0:
    RB(7) = DIR(0x44);
    A = RB(7);
    if (A != 0) goto L_1163;
    DIR(0x45)++;
    A = DIR(0x45);
    if (!((A >> 0) & 1)) goto L_10FF;
    f_1190();
    return;
    L_10FF:
    A = DIR(0x45);
    f_7A4A();
    EC_UNSUPPORTED();
    A = (A << 1) | (A >> 7);
    f_1125();
    return;
    L_1163:
    return;
    L_10ED:
    A = 0;
    DIR(0x44) = A;
    L_10DC:
    DIR(0x46)++;
    A = DIR(0x46);
    if (!((A >> 0) & 1)) goto L_10E8;
    f_118A();
    goto L_10F0;
    L_10E8:
    f_118D();
    goto L_10F0;
    L_10D7:
    f_1187();
    goto L_10F0;
    L_10D2:
    f_1184();
    goto L_10F0;
}

void f_1125(void)
{
    goto L_1132;
    L_1132:
    f_1196();
    return;
}

void f_1164(void)
{
    f_2BE3();
    RB(7) = DIR(0x43);
    f_2BE8();
    return;
}

void f_116C(void)
{
    BIT_SET(0x38, 1);
    A = DIR(0x40);
    if (!((A >> 4) & 1)) goto L_1175;
    BIT_SET(0x37, 1);
    L_1175:
    f_2BED();
    return;
}

void f_1178(void)
{
    f_2BF2();
    f_2BF7();
    return;
}

void f_117E(void)
{
    f_2BFC();
    return;
}

void f_1181(void)
{
    f_2C01();
    return;
}

void f_1184(void)
{
    f_2C06();
    return;
}

void f_1187(void)
{
    f_2C0B();
    return;
}

void f_118A(void)
{
    f_2C10();
    return;
}

void f_118D(void)
{
    f_2C15();
    return;
}

void f_1190(void)
{
    f_2C1A();
    return;
}

void f_1196(void)
{
    f_2C24();
    return;
}

void f_11AB(void)
{
    f_18D9();
    if (A == 0) goto L_1213;
    A = XD(DPTR);
    if (!((A >> 3) & 1)) goto L_11CE;
    A = 0;
    DIR(0x31) = A;
    BIT_SET(0x68, 0);
    DPTR = 0x130A;
    A = XD(DPTR);
    DIR(0x30) = A;
    RB(7) = DIR(0x30);
    f_179A();
    RB(7) = DIR(0x30);
    f_2C47();
    if (!BIT_RAM(0x68)) goto L_1210;
    goto L_11FD;
    L_11FD:
    BIT_SET(0x68, 0);
    RB(0) = 0xBB;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    f_0ADC();
    goto L_1210;
    L_1210:
    f_060A();
    L_1213:
    return;
    L_11CE:
    f_18E0();
    if (!BIT_RAM(0x6B)) goto L_11E9;
    A = DIR(0x32);
    A &= 0x02;
    if (A == 0) goto L_11DF;
    f_2C4C();
    goto L_11E2;
    L_11E2:
    BIT_SET(0x6B, 0);
    A = 0;
    DIR(0x31) = A;
    goto L_1210;
    L_11DF:
    f_2C51();
    L_11E9:
    RB(7) = DIR(0x31);
    A = RB(7);
    if (A == 0) goto L_1208;
    RB(7) = DIR(0x30);
    f_173D();
    RB(7) = DIR(0x30);
    f_2C56();
    DIR(0x31)--;
    if (!BIT_RAM(0x68)) goto L_1210;
    L_1208:
    f_12C6();
    RB(7) = DIR(0x32);
    f_14C9();
}

void f_1237(void)
{
    A--;
    if (RB(7) != 0x7F) { C = (RB(7) < 0x7F); goto L_123C; }
    f_14C6();
    return;
    L_123C:
    A--;
    tmp = A; A = XD(((unsigned int)SFR_A0 << 8) | RB(0)); XD(((unsigned int)SFR_A0 << 8) | RB(0)) = tmp;
    RB(7) = 0x01;
    f_14C6();
    return;
}

void f_129F(void)
{
    BIT_SET(0x05, 0);
    return;
}

void f_12BB(void)
{
    BIT_SET(0x04, 1);
    RB(0) = 0xB2;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A |= 0x01;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_2C60();
    return;
}

void f_12C6(void)
{
    BIT_SET(0x04, 0);
    RB(0) = 0xB2;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0xFE;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
}

void f_135F(void)
{
    DIR(0x20) = DIR(0x32);
    if (!BIT_RAM(0x04)) goto L_136A;
    f_12BB();
    goto L_136D;
    L_136D:
    DPTR = 0x1304;
    A = XD(DPTR);
    if (!BIT_RAM(0x02)) goto L_1378;
    A |= 0x04;
    XD(DPTR) = A;
    return;
    L_1378:
    A &= 0xFB;
    XD(DPTR) = A;
    return;
    L_136A:
    f_12C6();
}

void f_1491(void)
{
    f_2C5B();
    RB(0) = 0x9B;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_14B0;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(0x87);
    RB(0) = A;
    A = 0xFD;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0) = 0x9B;
    f_18A8();
    RB(0) = 0x9B;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A--;
    RB(7) = A;
    f_2C9C();
    goto L_14BA;
    L_14BA:
    RB(7) = DIR(0x32);
    f_2CA6();
    return;
    L_14B0:
    RB(7) = 0x14;
    f_2335();
    RB(7) = 0xFC;
    f_2CA1();
}

void f_14C6(void)
{
    DIR(0x31) = RB(7);
    return;
}

void f_14C9(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    A = 0;
    RB(7) = A;
    f_2CAB();
    A = 0;
    DPTR = 0x0694;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    RB(0) = 0xAC;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_14E4;
    f_1598();
    return;
    L_14E4:
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPTR++;
    XD(DPTR) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(0x10);
    if (A == 0) goto L_150D;
    ADD8(0xFD);
    if (A == 0) goto L_1517;
    ADD8(0x06);
    if (A != 0) goto L_1531;
    DPTR = 0x0693;
    A = XD(DPTR);
    DIR(0x28) = A;
    DPTR++;
    A = 0xFA;
    XD(DPTR) = A;
    A = 0;
    RB(0) = 0xAC;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(7) = DIR(0x28);
    f_2CB0();
    C = BIT_RAM(0x41);
    BIT_SET(0x48, C);
    goto L_1537;
    L_1537:
    DPTR = 0x0697;
    A = XD(DPTR);
    RB(7) = A;
    A ^= 0xF3;
    if (A == 0) goto L_1545;
    A = RB(7);
    A ^= 0xED;
    if (A != 0) goto L_1547;
    L_1545:
    BIT_SET(0x1A, 1);
    L_1547:
    RB(0) = 0x9C;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_1558;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    if (A == 0) goto L_1590;
    f_0ADC();
    goto L_1590;
    L_1590:
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    f_2CC4();
    return;
    L_1558:
    f_189C();
    RB(7) = 0x01;
    f_2CAB();
    DPTR = 0x0697;
    A = XD(DPTR);
    A ^= 0xED;
    RB(0) = 0x9C;
    if (A != 0) goto L_1571;
    f_18C6();
    A &= 0x07;
    goto L_1574;
    L_1574:
    RB(5) = A;
    RB(3) = 0x01;
    f_2CBA();
    DPTR = 0x0697;
    A = XD(DPTR);
    RB(7) = A;
    A ^= 0xF3;
    if (A == 0) goto L_1588;
    A = RB(7);
    A ^= 0xED;
    if (A != 0) goto L_1590;
    L_1588:
    DPTR = 0x0697;
    A = XD(DPTR);
    RB(7) = A;
    f_2CBF();
    L_1571:
    f_18C6();
    L_1531:
    DPTR = 0x0694;
    A = 0xFE;
    XD(DPTR) = A;
    L_1517:
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(0) = 0x94;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    RB(6) = 0x00;
    f_2CB5();
    DPTR = 0x0694;
    L_1528:
    A = 0xFA;
    XD(DPTR) = A;
    A = 0;
    RB(0) = 0xAC;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    goto L_1537;
    L_150D:
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(0) = 0x93;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR++;
    goto L_1528;
}

void f_1598(void)
{
    DPTR = 0x0693;
    A = XD(DPTR);
    f_7A4A();
    SFR_DA--;
    A = RB(4);
    PSW--;
    A = RB(5);
    SFR_DC--;
    A = RB(6);
    SFR_E5--;
    XD(DPTR) = A;
    SFR_EF--;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    if (((B >> 4) & 1)) { B = (B & ~(1 << 4)) | (((0) & 1) << 4); goto L_15CB; }
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    DIR(0x16) = A;
    RB(6)--;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    SFR_DA--;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    SFR_DA--;
    RB(0) = A;
    SFR_DA--;
    RB(1) = A;
    SFR_DA--;
    RB(2) = A;
    SFR_DA--;
    RB(3) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    ADD8(RB(0));
    L_15CB:
    RB(7) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    A ^= 0x12;
    RB(0)--;
    EC_UNSUPPORTED();
    RB(0) = 0xAC;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xED;
    f_166A();
    return;
}

void f_166A(void)
{
    RB(0) = 0x9C;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_1693;
    RB(7) = A;
    f_2CAB();
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    if (A == 0) goto L_16E3;
    f_0ADC();
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(7) = A;
    if (A == 0) goto L_16E3;
    f_0A8D();
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(7) = A;
    if (A == 0) goto L_16E3;
    f_0A8D();
    goto L_16E3;
    L_16E3:
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    f_2CD3();
    return;
    L_1693:
    f_189C();
    DPTR = 0x0693;
    A = XD(DPTR);
    A = ~A;
    if (A != 0) goto L_169F;
    goto L_16B9;
    L_16B9:
    RB(7) = 0x02;
    goto L_16BF;
    L_16BF:
    f_2CAB();
    RB(0) = 0x9C;
    f_18C6();
    RB(5) = A;
    RB(3) = 0x01;
    f_2CBA();
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    A ^= 0xF4;
    if (A == 0) goto L_16DB;
    A = RB(7);
    A ^= 0xF5;
    if (A != 0) goto L_16E3;
    L_16DB:
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    f_2CBF();
    L_169F:
    DPTR = 0x0693;
    A = XD(DPTR);
    A ^= 0xF2;
    if (A != 0) goto L_16AB;
    RB(7) = 0x03;
    goto L_16BF;
    L_16AB:
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    A ^= 0xF3;
    if (A == 0) goto L_16B9;
    A = RB(7);
    A ^= 0xED;
    if (A != 0) goto L_16BD;
    L_16BD:
    RB(7) = 0x01;
}

void f_173D(void)
{
    A = RB(7);
    f_7A4A();
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    A ^= RB(7);
    if (A == 0) goto L_175C;
    C = C || (BIT_RAM(0x73));
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    DIR(0x74) = 0x17;
    RB(0) = 0x76;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    RB(3) = 0x77;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    RB(6) = 0x90;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    f_1491();
    return;
    L_175C:
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    SFR_A5 = RB(2);
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    SFR_D1 = RB(5);
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    DPTR = 0xD217;
    A = CD(DPTR + A);
    C = 1;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    SUBB8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    A = da_a(A);
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    SUBB8(RB(1));
    f_135F();
    return;
}

void f_179A(void)
{
    A = RB(7);
    f_7A4A();
    RB(0)--;
    ADDC8((DIR(0x20)));
    RB(0)--;
    ADDC8(RB(0));
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(0)--;
    ADDC8(RB(3));
    ADDC8(0x18);
    ADDC8(RB(6));
    ADDC8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    RB(0)--;
    f_1237();
    return;
}

void f_189C(void)
{
    RB(0) = 0x9C;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(0x87);
    RB(0) = A;
    A = 0xFD;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0) = 0x9C;
}

void f_18A8(void)
{
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(0x87);
    RB(0) = A;
    A = 0xF7;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
}

void f_18C6(void)
{
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A--;
    RB(7) = A;
    DPTR = 0x0693;
    A = XD(DPTR);
    return;
}

void f_18D9(void)
{
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0x02;
    return;
}

void f_18E0(void)
{
    DPTR = 0x130A;
    A = XD(DPTR);
    DIR(0x32) = A;
    return;
}

void f_18EE(void)
{
    A = 0;
    RB(7) = A;
    L_18F0:
    A = RB(7);
    C = 0;
    SUBB8(0xC8);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_1903;
    DPTR = 0x06AE;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    RB(7)++;
    goto L_18F0;
    L_1903:
    return;
}

void f_1904(void)
{
    tmp = A; A = RB(6); RB(6) = tmp;
    A = RB(7);
    tmp = A; A = RB(6); RB(6) = tmp;
    A = RB(6);
    f_21EE();
    f_21C1();
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xFD;
    f_2254();
    ADD8(0x75);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    f_21C1();
    A = 0xFE;
    f_2254();
    f_225F();
    f_21C1();
    A = 0x40;
    f_2254();
    f_228F();
    f_21C1();
    A = 0x40;
    XD(DPTR) = A;
    f_18EE();
    A = RB(6);
    B = 0x0F;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x7F);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    f_21C1();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    A = RB(6);
    B = 0x0F;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x81);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(5) = A;
    A = RB(7);
    A |= RB(5);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_18EE();
    A = RB(6);
    f_225B();
    f_21C1();
    f_2253();
    f_228F();
    f_21C1();
    f_2253();
    ADD8(0x77);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    f_21C1();
    A = 0x02;
    f_2254();
    f_226B();
    f_21C1();
    A = 0x03;
    XD(DPTR) = A;
    f_18EE();
    A = RB(6);
    f_2267();
    f_21C1();
    A = 0x07;
    f_2254();
    ADD8(0x77);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    f_21C1();
    A = 0x01;
    XD(DPTR) = A;
    B = 0x0E;
    A = RB(6);
    DPTR = 0x6FD0;
    f_7A15();
    f_21C3();
    A = 0;
    XD(DPTR) = A;
    A = RB(6);
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x2F);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    f_21C1();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    A = RB(6);
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x33);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(5) = A;
    A = ~A;
    RB(4) = A;
    A = RB(7);
    A &= RB(4);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    A = RB(6);
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x31);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    f_2238();
    A = RB(5);
    XD(DPTR) = A;
    B = 0x0E;
    A = RB(6);
    DPTR = 0x6FD4;
    f_7A15();
    f_21C3();
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x007C;
    A = XD(DPTR);
    A = ~A;
    if (A != 0) goto L_1A4B;
    DPTR = 0x0056;
    XD(DPTR) = A;
    A = RB(6);
    RB(5) = A;
    RB(4) = 0x00;
    if (A != 0) goto L_1A2A;
    DPTR = 0x0059;
    XD(DPTR) = A;
    goto L_1A40;
    L_1A40:
    A = 0;
    DPTR = 0x007D;
    XD(DPTR) = A;
    DPTR = 0x007C;
    A = 0x44;
    XD(DPTR) = A;
    L_1A4B:
    return;
    L_1A2A:
    A = RB(5);
    A ^= 0x01;
    A |= RB(4);
    if (A != 0) goto L_1A36;
    DPTR = 0x005A;
    XD(DPTR) = A;
    goto L_1A40;
    L_1A36:
    A = RB(5);
    A ^= 0x02;
    A |= RB(4);
    if (A != 0) goto L_1A40;
    DPTR = 0x005B;
    XD(DPTR) = A;
}

void f_1A4C(void)
{
    DPTR = 0x069B;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    A = RB(3);
    XD(DPTR) = A;
    DPTR = 0x069A;
    A = RB(7);
    XD(DPTR) = A;
    RB(5) = 0x01;
    f_20AF();
    A = RB(7);
    if (A != 0) goto L_1A68;
    DPTR = 0x06A4;
    XD(DPTR) = A;
    f_1C0E();
    return;
    L_1A68:
    DPTR = 0x06A2;
    A = 0xEE;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x06A4;
    XD(DPTR) = A;
    RB(0) = 0xAF;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x069B;
    A = XD(DPTR);
    if (((A >> 7) & 1)) goto L_1A80;
    f_1B12();
    return;
    L_1A80:
    DPTR = 0x06A0;
    A = XD(DPTR);
    if (A == 0) goto L_1A8E;
    DPTR = 0x069C;
    A = XD(DPTR);
    RB(7) = A;
    f_203A();
    L_1A8E:
    DPTR = 0x069C;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x069A;
    A = XD(DPTR);
    f_21B6();
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x06A0;
    A = XD(DPTR);
    if (A == 0) goto L_1AAA;
    DPTR = 0x069D;
    A = XD(DPTR);
    RB(7) = A;
    f_203A();
    L_1AAA:
    DPTR = 0x069D;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x069A;
    A = XD(DPTR);
    f_21FD();
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x069B;
    A = XD(DPTR);
    A &= 0x7F;
    XD(DPTR) = A;
    DPTR = 0x06A0;
    A = XD(DPTR);
    if (A == 0) goto L_1AD1;
    DPTR = 0x069E;
    f_2248();
    f_203A();
    L_1AD1:
    DPTR = 0x069E;
    f_2297();
    DPTR = 0x069A;
    f_2209();
    f_2238();
    A = RB(5);
    XD(DPTR) = A;
    DPTR = 0x069B;
    A = XD(DPTR);
    A ^= 0x0C;
    if (A != 0) goto L_1B29;
    DPTR = 0x06A0;
    A = XD(DPTR);
    if (A == 0) goto L_1AFA;
    DPL = RB(7);
    DPH = RB(6);
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    f_203A();
    L_1AFA:
    DPTR = 0x069E;
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    DPL = A;
    DPH = RB(6);
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    f_2273();
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    goto L_1B29;
    L_1B29:
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(7) = A;
    f_22A3();
    f_21C1();
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x06A0;
    A = XD(DPTR);
    if (A == 0) goto L_1B58;
    RB(0) = 0xAF;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(5) = A;
    f_22AF();
    f_2238();
    A = RB(6);
    XD(DPTR) = A;
    DPTR = 0x069B;
    A = XD(DPTR);
    A |= 0xC0;
    RB(6) = A;
    A = RB(5);
    goto L_1B60;
    L_1B60:
    f_21EE();
    f_21C1();
    A = RB(6);
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    f_221D();
    L_1B73:
    if (((SFR_88 >> 7) & 1)) goto L_1B89;
    DPTR = 0x069A;
    f_21D1();
    A = XD(DPTR);
    DPTR = 0x06A3;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0x7E;
    if (A == 0) goto L_1B73;
    f_2216();
    L_1B89:
    if (!((SFR_88 >> 7) & 1)) goto L_1B99;
    f_2216();
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    goto L_1BAF;
    L_1BAF:
    DPTR = 0x06A2;
    A = 0xEE;
    XD(DPTR) = A;
    goto L_1BBC;
    L_1BBC:
    DPTR = 0x06A2;
    A = XD(DPTR);
    A ^= 0xEE;
    if (A != 0) goto L_1BCA;
    DPTR = 0x06A4;
    XD(DPTR) = A;
    goto L_1C05;
    L_1C05:
    DPTR = 0x069A;
    f_21D1();
    A = 0xFE;
    XD(DPTR) = A;
    L_1BCA:
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(7) = A;
    f_21B6();
    A = XD(DPTR);
    if (!((A >> 0) & 1)) goto L_1BFF;
    A = RB(7);
    f_220A();
    f_21DD();
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x069E;
    A = XD(DPTR);
    RB(4) = A;
    DPTR++;
    A = XD(DPTR);
    RB(5) = A;
    f_2288();
    DPTR = 0x069B;
    A = XD(DPTR);
    A ^= 0x0C;
    if (A != 0) goto L_1BFF;
    f_2273();
    f_21DD();
    A = XD(DPTR);
    DPL = RB(5);
    DPH = RB(4);
    DPTR++;
    XD(DPTR) = A;
    L_1BFF:
    DPTR = 0x06A4;
    A = 0x01;
    XD(DPTR) = A;
    L_1B99:
    DPTR = 0x06A3;
    A = XD(DPTR);
    RB(7) = A;
    A &= 0x7C;
    if (A == 0) goto L_1BB7;
    A = RB(7);
    A &= 0x18;
    if (A == 0) goto L_1BAF;
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    L_1BB7:
    A = 0;
    DPTR = 0x06A2;
    XD(DPTR) = A;
    L_1B58:
    DPTR = 0x069B;
    A = XD(DPTR);
    A |= 0x40;
    RB(6) = A;
    A = RB(7);
}

void f_1B12(void)
{
    DPTR = 0x069C;
    A = XD(DPTR);
    DPTR = 0x069A;
    f_21B1();
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x069D;
    f_21FA();
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(7) = A;
    f_22A3();
    f_21C1();
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x06A0;
    A = XD(DPTR);
    if (A == 0) goto L_1B58;
    RB(0) = 0xAF;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(5) = A;
    f_22AF();
    f_2238();
    A = RB(6);
    XD(DPTR) = A;
    DPTR = 0x069B;
    A = XD(DPTR);
    A |= 0xC0;
    RB(6) = A;
    A = RB(5);
    goto L_1B60;
    L_1B60:
    f_21EE();
    f_21C1();
    A = RB(6);
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    f_221D();
    L_1B73:
    if (((SFR_88 >> 7) & 1)) goto L_1B89;
    DPTR = 0x069A;
    f_21D1();
    A = XD(DPTR);
    DPTR = 0x06A3;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0x7E;
    if (A == 0) goto L_1B73;
    f_2216();
    L_1B89:
    if (!((SFR_88 >> 7) & 1)) goto L_1B99;
    f_2216();
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    goto L_1BAF;
    L_1BAF:
    DPTR = 0x06A2;
    A = 0xEE;
    XD(DPTR) = A;
    goto L_1BBC;
    L_1BBC:
    DPTR = 0x06A2;
    A = XD(DPTR);
    A ^= 0xEE;
    if (A != 0) goto L_1BCA;
    DPTR = 0x06A4;
    XD(DPTR) = A;
    goto L_1C05;
    L_1C05:
    DPTR = 0x069A;
    f_21D1();
    A = 0xFE;
    XD(DPTR) = A;
    L_1BCA:
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(7) = A;
    f_21B6();
    A = XD(DPTR);
    if (!((A >> 0) & 1)) goto L_1BFF;
    A = RB(7);
    f_220A();
    f_21DD();
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x069E;
    A = XD(DPTR);
    RB(4) = A;
    DPTR++;
    A = XD(DPTR);
    RB(5) = A;
    f_2288();
    DPTR = 0x069B;
    A = XD(DPTR);
    A ^= 0x0C;
    if (A != 0) goto L_1BFF;
    f_2273();
    f_21DD();
    A = XD(DPTR);
    DPL = RB(5);
    DPH = RB(4);
    DPTR++;
    XD(DPTR) = A;
    L_1BFF:
    DPTR = 0x06A4;
    A = 0x01;
    XD(DPTR) = A;
    L_1B99:
    DPTR = 0x06A3;
    A = XD(DPTR);
    RB(7) = A;
    A &= 0x7C;
    if (A == 0) goto L_1BB7;
    A = RB(7);
    A &= 0x18;
    if (A == 0) goto L_1BAF;
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    L_1BB7:
    A = 0;
    DPTR = 0x06A2;
    XD(DPTR) = A;
    L_1B58:
    DPTR = 0x069B;
    A = XD(DPTR);
    A |= 0x40;
    RB(6) = A;
    A = RB(7);
}

void f_1C0E(void)
{
    DPTR = 0x06A4;
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void f_1C14(void)
{
    DPTR = 0x06A1;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    A = RB(3);
    XD(DPTR) = A;
    DPTR = 0x06A0;
    A = RB(7);
    XD(DPTR) = A;
    RB(5) = 0x01;
    f_20AF();
    A = RB(7);
    if (A != 0) goto L_1C30;
    DPTR = 0x06A6;
    XD(DPTR) = A;
    f_1D43();
    return;
    L_1C30:
    A = 0;
    DPTR = 0x06A6;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x06A2;
    A = XD(DPTR);
    DPTR = 0x06A0;
    f_21B1();
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x06A3;
    f_21FA();
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    A = RB(6);
    f_21D2();
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x06A1;
    A = XD(DPTR);
    A |= 0x40;
    RB(7) = A;
    f_21EA();
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    f_221D();
}

void f_1C6F(void)
{
    L_1C6F:
    if (!((SFR_88 >> 7) & 1)) goto L_1C75;
    f_1D1A();
    return;
    L_1C75:
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(3) = A;
    f_21D2();
    A = XD(DPTR);
    RB(7) = A;
    A &= 0xFC;
    if (A == 0) goto L_1C6F;
    A = RB(7);
    A &= 0x7C;
    if (A == 0) goto L_1CA0;
    A = RB(7);
    A &= 0x18;
    if (A == 0) goto L_1C95;
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    L_1C95:
    f_2216();
    A = 0;
    DPTR = 0x06A6;
    XD(DPTR) = A;
    f_1D1A();
    return;
    L_1CA0:
    A = RB(3);
    f_222C();
    f_21DD();
    A = XD(DPTR);
    DPTR = 0x06A4;
    f_2283();
    DPTR = 0x06A7;
    A = XD(DPTR);
    if (A != 0) goto L_1CD9;
    DPTR = 0x06A0;
    f_2209();
    f_21DD();
    A = XD(DPTR);
    DPTR = 0x06A7;
    XD(DPTR) = A;
    A = XD(DPTR);
    RB(7) = A;
    C = 0;
    SUBB8(0x20);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_1CCF;
    goto L_1CD1;
    L_1CD1:
    DPTR = 0x06A7;
    A = RB(7);
    XD(DPTR) = A;
    f_2CD8();
    L_1CD9:
    DPTR = 0x06A7;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    DPTR = 0x06A4;
    A = 0;
    B = 0x01;
    f_77E5();
    DPTR = 0x06A7;
    A = XD(DPTR);
    RB(7) = A;
    RB(6) = 0x00;
    A ^= 0x01;
    if (A != 0) goto L_1CFE;
    f_21EA();
    f_21C1();
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    L_1CFE:
    DPTR = 0x06A0;
    A = XD(DPTR);
    f_22A3();
    f_21C1();
    A = 0xFE;
    XD(DPTR) = A;
    A = RB(7);
    A |= RB(6);
    if (A == 0) goto L_1D12;
    f_1C6F();
    return;
    L_1D12:
    f_2216();
    DPTR = 0x06A6;
    A++;
    XD(DPTR) = A;
    L_1CCF:
    RB(7) = 0x20;
}

void f_1D1A(void)
{
    if (!((SFR_88 >> 7) & 1)) goto L_1D2D;
    f_2216();
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    A = 0;
    DPTR = 0x06A6;
    XD(DPTR) = A;
    L_1D2D:
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(7) = A;
    f_21EE();
    f_21C1();
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    A = RB(7);
    f_21D2();
    A = 0xFE;
    XD(DPTR) = A;
}

void f_1D43(void)
{
    DPTR = 0x06A6;
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void f_1D49(void)
{
    DPTR = 0x06A1;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    A = RB(3);
    XD(DPTR) = A;
    DPTR = 0x06A0;
    A = RB(7);
    XD(DPTR) = A;
    RB(5) = 0x01;
    f_20AF();
    A = RB(7);
    if (A != 0) goto L_1D65;
    DPTR = 0x06A8;
    XD(DPTR) = A;
    f_1EAD();
    return;
    L_1D65:
    A = 0;
    DPTR = 0x06A8;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x06A7;
    A = XD(DPTR);
    if (A == 0) goto L_1D94;
    A = 0;
    RB(0) = 0xAF;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x06A2;
    A = XD(DPTR);
    RB(7) = A;
    f_203A();
    DPTR = 0x06A3;
    A = XD(DPTR);
    RB(7) = A;
    f_203A();
    DPTR = 0x06A6;
    A = XD(DPTR);
    RB(7) = A;
    f_203A();
    f_2245();
    f_203A();
    L_1D94:
    DPTR = 0x06A1;
    A = XD(DPTR);
    A &= 0x7F;
    XD(DPTR) = A;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x06A0;
    f_21B4();
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x06A3;
    f_21FA();
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x06A6;
    A = XD(DPTR);
    RB(7) = A;
    A = RB(6);
    f_220A();
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x06A9;
    A = RB(7);
    XD(DPTR) = A;
    f_2245();
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(6) = A;
    f_222C();
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    A = RB(6);
    f_21D2();
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x06A7;
    A = XD(DPTR);
    DPTR = 0x06A1;
    if (A == 0) goto L_1DE9;
    A = XD(DPTR);
    A |= 0xC0;
    goto L_1DEC;
    L_1DEC:
    RB(7) = A;
    DPTR = 0x06A0;
    f_21ED();
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    f_221D();
    L_1DE9:
    A = XD(DPTR);
    A |= 0x40;
}

void f_1E03(void)
{
    L_1E03:
    if (!((SFR_88 >> 7) & 1)) goto L_1E09;
    f_1E94();
    return;
    L_1E09:
    f_21CE();
    A = XD(DPTR);
    RB(7) = A;
    A &= 0xFC;
    if (A == 0) goto L_1E03;
    A = RB(7);
    A &= 0x7C;
    if (A == 0) goto L_1E2F;
    A = RB(7);
    A &= 0x18;
    if (A == 0) goto L_1E24;
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    L_1E24:
    f_2216();
    A = 0;
    DPTR = 0x06A8;
    XD(DPTR) = A;
    f_1E94();
    return;
    L_1E2F:
    DPTR = 0x06A9;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    DPTR = 0x06A4;
    A = 0;
    B = 0x01;
    f_77E5();
    DPTR = 0x06A9;
    A = XD(DPTR);
    if (A == 0) goto L_1E8B;
    DPTR = 0x06A7;
    A = XD(DPTR);
    if (A == 0) goto L_1E77;
    DPTR = 0x06A4;
    f_2297();
    f_2228();
    f_2238();
    A = RB(5);
    XD(DPTR) = A;
    DPL = RB(7);
    DPH = RB(6);
    A = XD(DPTR);
    RB(7) = A;
    f_203A();
    DPTR = 0x06A9;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_1E82;
    RB(0) = 0xAF;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    DPTR = 0x06A0;
    A = XD(DPTR);
    f_22AF();
    goto L_1E7D;
    L_1E7D:
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    L_1E82:
    f_21CE();
    A = 0xFE;
    XD(DPTR) = A;
    f_1E03();
    return;
    L_1E77:
    f_2245();
    f_2228();
    L_1E8B:
    f_2216();
    DPTR = 0x06A8;
    A = 0x01;
    XD(DPTR) = A;
}

void f_1E94(void)
{
    if (!((SFR_88 >> 7) & 1)) goto L_1EA7;
    f_2216();
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    A = 0;
    DPTR = 0x06A8;
    XD(DPTR) = A;
    L_1EA7:
    f_21CE();
    A = 0xFE;
    XD(DPTR) = A;
}

void f_1EAD(void)
{
    DPTR = 0x06A8;
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void f_1EB3(void)
{
    DPTR = 0x0695;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    A = RB(3);
    XD(DPTR) = A;
    DPTR = 0x0694;
    A = RB(7);
    XD(DPTR) = A;
    RB(5) = 0x01;
    f_20AF();
    A = RB(7);
    if (A != 0) goto L_1ECF;
    DPTR = 0x0697;
    XD(DPTR) = A;
    f_1F6A();
    return;
    L_1ECF:
    RB(3) = 0xEE;
    A = 0;
    DPTR = 0x0697;
    XD(DPTR) = A;
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0694;
    f_21B4();
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x0696;
    f_21FA();
    f_21C1();
    A = RB(7);
    XD(DPTR) = A;
    A = RB(6);
    f_21D2();
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x0694;
    f_21ED();
    f_21DD();
    A = 0x44;
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    f_221D();
    L_1F0C:
    if (((SFR_88 >> 7) & 1)) goto L_1F22;
    DPTR = 0x0694;
    f_21D1();
    A = XD(DPTR);
    DPTR = 0x0698;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0x7E;
    if (A == 0) goto L_1F0C;
    f_2216();
    L_1F22:
    if (!((SFR_88 >> 7) & 1)) goto L_1F34;
    f_2216();
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    RB(3) = 0xEE;
    goto L_1F50;
    L_1F50:
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(3);
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    A ^= 0xEE;
    DPTR = 0x0697;
    if (A != 0) goto L_1F5E;
    XD(DPTR) = A;
    goto L_1F61;
    L_1F61:
    DPTR = 0x0694;
    f_21D1();
    A = 0xFE;
    XD(DPTR) = A;
    L_1F5E:
    A = 0x01;
    XD(DPTR) = A;
    L_1F34:
    DPTR = 0x0698;
    A = XD(DPTR);
    RB(7) = A;
    A &= 0x7C;
    if (A == 0) goto L_1F4E;
    A = RB(7);
    A &= 0x18;
    if (A == 0) goto L_1F4A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    L_1F4A:
    RB(3) = 0xEE;
    goto L_1F50;
    L_1F4E:
    A = 0;
    RB(3) = A;
}

void f_1F6A(void)
{
    DPTR = 0x0697;
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void f_1F70(void)
{
    DPTR = 0x06A1;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    A = RB(2);
    XD(DPTR) = A;
    DPTR++;
    A = RB(3);
    XD(DPTR) = A;
    DPTR = 0x06A0;
    A = RB(7);
    XD(DPTR) = A;
    RB(5) = 0x01;
    f_20AF();
    A = RB(7);
    if (A != 0) goto L_1F8F;
    DPTR = 0x06A4;
    XD(DPTR) = A;
    f_2034();
    return;
    L_1F8F:
    RB(3) = 0xEE;
    A = 0;
    DPTR = 0x06A4;
    XD(DPTR) = A;
    DPTR = 0x06A1;
    A = XD(DPTR);
    A |= 0x01;
    RB(7) = A;
    DPTR = 0x06A0;
    f_21B4();
    A = RB(7);
    XD(DPTR) = A;
    A = RB(6);
    f_21D2();
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x06A0;
    f_21ED();
    f_21DD();
    A = 0x44;
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    f_221D();
    L_1FC3:
    if (((SFR_88 >> 7) & 1)) goto L_1FD9;
    DPTR = 0x06A0;
    f_21D1();
    A = XD(DPTR);
    DPTR = 0x06A5;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0x7E;
    if (A == 0) goto L_1FC3;
    f_2216();
    L_1FD9:
    if (!((SFR_88 >> 7) & 1)) goto L_1FEB;
    f_2216();
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    RB(3) = 0xEE;
    goto L_2007;
    L_2007:
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(3);
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    A ^= 0xEE;
    if (A != 0) goto L_2015;
    DPTR = 0x06A4;
    XD(DPTR) = A;
    goto L_202B;
    L_202B:
    DPTR = 0x06A0;
    f_21D1();
    A = 0xFE;
    XD(DPTR) = A;
    L_2015:
    DPTR = 0x06A0;
    f_2209();
    f_21DD();
    A = XD(DPTR);
    DPTR = 0x06A2;
    f_2283();
    DPTR = 0x06A4;
    A = 0x01;
    XD(DPTR) = A;
    L_1FEB:
    DPTR = 0x06A5;
    A = XD(DPTR);
    RB(7) = A;
    A &= 0x7C;
    if (A == 0) goto L_2005;
    A = RB(7);
    A &= 0x18;
    if (A == 0) goto L_2001;
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    L_2001:
    RB(3) = 0xEE;
    goto L_2007;
    L_2005:
    A = 0;
    RB(3) = A;
}

void f_2034(void)
{
    DPTR = 0x06A4;
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void f_203A(void)
{
    RB(0) = 0xAF;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    A &= 0x80;
    if (A != 0) goto L_204D;
    A = RB(7);
    ADD8((A));
    RB(7) = A;
    A ^= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    goto L_205A;
    L_205A:
    A = RB(7);
    A &= 0x80;
    if (A != 0) goto L_2067;
    A = RB(7);
    ADD8((A));
    RB(0) = 0xAF;
    A ^= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
    L_2067:
    A = RB(7);
    ADD8((A));
    RB(7) = A;
    RB(0) = 0xAF;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0x07;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
    L_204D:
    A = RB(7);
    ADD8((A));
    RB(7) = A;
    RB(0) = 0xAF;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0x09;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
}

void f_2075(void)
{
    A = RB(7);
    f_2267();
    f_21DD();
    A = XD(DPTR);
    RB(7) = A;
    A &= 0x03;
    RB(6) = A;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    A ^= 0x03;
    if (A != 0) goto L_208A;
    RB(7) = A;
    return;
    L_208A:
    RB(7) = 0x01;
    return;
}

void f_208D(void)
{
    A = RB(7);
    f_225B();
    f_21C1();
    A = XD(DPTR);
    A &= 0xFB;
    if (A != 0) goto L_20A9;
    A = RB(7);
    B = 0x0F;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    f_228F();
    f_21DD();
    A = XD(DPTR);
    A &= 0xFB;
    if (A == 0) goto L_20AC;
    L_20A9:
    RB(7) = 0x00;
    return;
    L_20AC:
    RB(7) = 0x01;
    return;
}

void f_20AF(void)
{
    DPTR = 0x06AA;
    A = RB(7);
    XD(DPTR) = A;
    DPTR++;
    A = 0x01;
    XD(DPTR) = A;
    f_208D();
    A = RB(7);
    if (A != 0) goto L_20C4;
    DPTR = 0x06AB;
    XD(DPTR) = A;
    goto L_2114;
    L_2114:
    DPTR = 0x06AB;
    A = XD(DPTR);
    RB(7) = A;
    return;
    L_20C4:
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(5);
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    A ^= 0x01;
    if (A != 0) goto L_20D4;
    DPTR = 0x06AA;
    A = XD(DPTR);
    RB(7) = A;
    f_2CDD();
    L_20D4:
    DPTR = 0x06AA;
    A = XD(DPTR);
    RB(7) = A;
    f_2075();
    A = RB(7);
    A ^= 0x01;
    if (A != 0) goto L_2103;
    DPTR = 0x06AB;
    XD(DPTR) = A;
    DPTR = 0x06AA;
    A = XD(DPTR);
    RB(7) = A;
    f_22BB();
    f_21C1();
    A = XD(DPTR);
    RB(6) = A;
    A++;
    XD(DPTR) = A;
    DPTR = 0x008F;
    A = XD(DPTR);
    RB(5) = A;
    A = RB(6);
    C = 1;
    SUBB8(RB(5));
    if (C != 0) goto L_2114;
    f_1904();
    goto L_2114;
    L_2103:
    DPTR = 0x06AA;
    A = XD(DPTR);
    f_22BB();
    f_21DD();
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x06AB;
    A++;
    XD(DPTR) = A;
}

void f_211A(void)
{
    DPTR = 0x008F;
    A = 0x14;
    XD(DPTR) = A;
    return;
}

void f_21B1(void)
{
    A |= 0x01;
    RB(7) = A;
}

void f_21B4(void)
{
    A = XD(DPTR);
    RB(6) = A;
}

void f_21B6(void)
{
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x23);
    DPL = A;
    A = 0;
    ADDC8(0x21);
}

void f_21C1(void)
{
    DPH = A;
}

void f_21C3(void)
{
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(4);
    return;
}

void f_21CE(void)
{
    DPTR = 0x06A0;
    A = XD(DPTR);
}

void f_21D2(void)
{
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x27);
    DPL = A;
    A = 0;
    ADDC8(0x21);
}

void f_21DD(void)
{
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(6);
    return;
}

void f_21EA(void)
{
    DPTR = 0x06A0;
    A = XD(DPTR);
}

void f_21EE(void)
{
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x21);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_21FA(void)
{
    A = XD(DPTR);
    RB(7) = A;
    A = RB(6);
}

void f_21FD(void)
{
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x25);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_220A(void)
{
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x29);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_2216(void)
{
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((1) & 1) << 3);
    return;
}

void f_221D(void)
{
    SFR_8D = 0xB2;
    SFR_8B = 0x19;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    return;
}

void f_2228(void)
{
    DPTR = 0x06A0;
    A = XD(DPTR);
}

void f_222C(void)
{
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x2D);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_2238(void)
{
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(2) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(2);
    return;
}

void f_2245(void)
{
    DPTR = 0x06A4;
}

void f_2248(void)
{
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    DPL = A;
    DPH = RB(6);
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void f_2254(void)
{
    XD(DPTR) = A;
    A = RB(6);
    B = 0x0F;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    return;
}

void f_225B(void)
{
    B = 0x0F;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
}

void f_225F(void)
{
    ADD8(0x7B);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_2267(void)
{
    B = 0x0F;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
}

void f_226B(void)
{
    ADD8(0x79);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_2273(void)
{
    DPTR = 0x069A;
    A = XD(DPTR);
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x2B);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_2283(void)
{
    RB(7) = A;
    A = XD(DPTR);
    RB(4) = A;
    DPTR++;
    A = XD(DPTR);
}

void f_2288(void)
{
    DPL = A;
    DPH = RB(4);
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_228F(void)
{
    ADD8(0x7D);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_2297(void)
{
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    DPL = A;
    DPH = RB(6);
    A = XD(DPTR);
    RB(5) = A;
    return;
}

void f_22A3(void)
{
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x27);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_22AF(void)
{
    B = 0x15;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x34);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_22BB(void)
{
    B = 0x0F;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x82);
    DPL = A;
    A = 0;
    ADDC8(0x21);
    return;
}

void f_22C7(void)
{
    A = 0;
    SFR_8A = A;
    SFR_8C = 0xFD;
    SFR_88 = (SFR_88 & ~(1 << 5)) | (((0) & 1) << 5);
    return;
}

void f_22DB(void)
{
    SFR_8B = 0x01;
    SFR_8D = 0xFA;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    return;
}

void f_22E6(void)
{
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    BIT_SET(0x32, 0);
    return;
}

void f_22ED(void)
{
    SFR_88 = (SFR_88 & ~(1 << 4)) | (((0) & 1) << 4);
    SFR_88 = (SFR_88 & ~(1 << 5)) | (((0) & 1) << 5);
    A = 0;
    SFR_8A = A;
    SFR_8C = 0xFD;
    SFR_89 = 0x11;
    SFR_88 = (SFR_88 & ~(1 << 4)) | (((1) & 1) << 4);
    SFR_A8 = (SFR_A8 & ~(1 << 1)) | (((1) & 1) << 1);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_8B = 0x01;
    SFR_8D = 0xFA;
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((1) & 1) << 3);
    return;
}

void f_230B(void)
{
    DPTR = 0x06A0;
    A = RB(7);
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    f_0600();
    L_2317:
    DPTR = 0x06A0;
    A = XD(DPTR);
    if (A == 0) goto L_232F;
    f_2350();
    L_2320:
    if (!((SFR_88 >> 7) & 1)) goto L_2320;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    DPTR = 0x06A0;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    goto L_2317;
    L_232F:
    f_0607();
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((1) & 1) << 3);
    return;
}

void f_2335(void)
{
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    L_233D:
    A = RB(7);
    if (A == 0) goto L_234D;
    f_2350();
    L_2343:
    if (!((SFR_88 >> 7) & 1)) goto L_2343;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    RB(7)--;
    goto L_233D;
    L_234D:
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((1) & 1) << 3);
    return;
}

void f_2350(void)
{
    SFR_8D = 0xFD;
    A = 0;
    SFR_8B = A;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    return;
}

void f_235B(void)
{
    RB(0) = 0xB4;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x22;
    RB(0) = 0x96;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x2A;
    RB(0) = 0xB5;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x30;
    DIR(0x25) = 0x0F;
    A = 0;
    DIR(0x28) = A;
    DIR(0x2A) = A;
    RB(0) = 0xB0;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0xC3;
    A |= 0x28;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0) = 0xB2;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0xFB;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0) = 0xB1;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x01;
    A |= 0x64;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0) = 0xB2;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A |= 0x01;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0xDF;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0xF7;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0xEF;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A |= 0x40;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DIR(0x20) = 0x10;
    A = 0;
    DPTR = 0x0019;
    XD(DPTR) = A;
    DPTR = 0x001A;
    XD(DPTR) = A;
    DPTR = 0x001B;
    XD(DPTR) = A;
    DPTR = 0x001C;
    XD(DPTR) = A;
    DIR(0x22) = A;
    return;
}

void f_23B2(void)
{
    A = 0;
    DIR(0x26) = A;
    DIR(0x27) = A;
    DIR(0x2B) = A;
    DIR(0x40) = A;
    DIR(0x41) = A;
    DIR(0x29) = A;
    return;
}

void f_23C1(void)
{
    f_235B();
    f_23B2();
    f_23C0();
    f_22ED();
    f_2405();
    f_211A();
    DPTR = 0x31A1;
    A = 0x80;
    XD(DPTR) = A;
    DPTR = 0x31A2;
    A = 0x10;
    XD(DPTR) = A;
    RB(7) = 0x3C;
    f_2C7E();
    return;
}

void f_23E4(void)
{
    RB(7) = 0x20;
    DPTR = 0x0000;
    L_23E9:
    RB(4) = DPH;
    C = 0;
    A = RB(4);
    SUBB8(0x01);
    if (C == 0) goto L_23F6;
    A = 0;
    XD(DPTR) = A;
    DPTR++;
    goto L_23E9;
    L_23F6:
    A = RB(7);
    C = 0;
    SUBB8(0xC0);
    if (C == 0) goto L_2404;
    tmp = A; A = RB(0); RB(0) = tmp;
    A = RB(7);
    tmp = A; A = RB(0); RB(0) = tmp;
    A = 0;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(7)++;
    goto L_23F6;
    L_2404:
    return;
}

void f_2405(void)
{
    A = 0;
    RB(7) = A;
    L_2407:
    A = RB(7);
    C = 0;
    SUBB8(0x12);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_2445;
    A = RB(7);
    B = 0x03;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x4D);
    DPL = A;
    A = 0;
    ADDC8(0x24);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(5) = A;
    RB(0) = 0xB7;
    A = RB(4);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(5);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    B = 0x03;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x4F);
    DPL = A;
    A = 0;
    ADDC8(0x24);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    DPL = RB(5);
    DPH = RB(4);
    XD(DPTR) = A;
    RB(7)++;
    goto L_2407;
    L_2445:
    DPTR = 0x1032;
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    return;
}

void f_2483(void)
{
    f_280A();
    return;
}

void f_2494(void)
{
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    L_2499:
    DPTR = 0x0693;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x14);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_24D4;
    A = XD(DPTR);
    ADD8((A));
    ADD8((A));
    ADD8(0x58);
    DPL = A;
    A = 0;
    ADDC8(0x27);
    f_27B9();
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x0693;
    A = XD(DPTR);
    ADD8((A));
    ADD8((A));
    ADD8(0x5A);
    DPL = A;
    A = 0;
    ADDC8(0x27);
    f_27B9();
    A = 0xFF;
    XD(DPTR) = A;
    DPTR = 0x0693;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_2499;
    L_24D4:
    return;
}

void f_24D5(void)
{
    A = 0;
    DPTR = 0x1B08;
    XD(DPTR) = A;
    DPTR = 0x1B0A;
    XD(DPTR) = A;
    DPTR = 0x1B0B;
    XD(DPTR) = A;
    DPTR = 0x1B04;
    A = 0xFF;
    XD(DPTR) = A;
    DPTR = 0x1B05;
    XD(DPTR) = A;
    DPTR = 0x1B06;
    XD(DPTR) = A;
    DPTR = 0x1B07;
    XD(DPTR) = A;
    DPTR = 0x1B11;
    XD(DPTR) = A;
    DPTR = 0x1B15;
    XD(DPTR) = A;
    DPTR = 0x1B19;
    XD(DPTR) = A;
    DPTR = 0x1B1D;
    XD(DPTR) = A;
    DPTR = 0x1B21;
    XD(DPTR) = A;
    DPTR = 0x1B25;
    XD(DPTR) = A;
    DPTR = 0x1B29;
    XD(DPTR) = A;
    DPTR = 0x1B2D;
    XD(DPTR) = A;
    DPTR = 0x1B31;
    XD(DPTR) = A;
    return;
}

void f_251B(void)
{
    DPTR = 0x1602;
    A = XD(DPTR);
    A &= 0x02;
    DPTR = 0x1B20;
    if (A == 0) goto L_252C;
    A = XD(DPTR);
    A |= 0x40;
    XD(DPTR) = A;
    goto L_2530;
    L_2530:
    DPTR = 0x1B21;
    A = 0x40;
    XD(DPTR) = A;
    A = 0x08;
    f_27B0();
    A |= 0x08;
    XD(DPTR) = A;
    return;
    L_252C:
    A = XD(DPTR);
    A &= 0xBF;
    XD(DPTR) = A;
}

void f_254E(void)
{
    DPTR = 0x1B24;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    DPTR = 0x1B25;
    A = 0x10;
    XD(DPTR) = A;
    DPTR = 0x113C;
    A = 0x02;
    XD(DPTR) = A;
    DPTR = 0x113D;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    return;
}

void f_2578(void)
{
    DPTR = 0x1B20;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    DPTR = 0x1B21;
    A = 0x80;
    XD(DPTR) = A;
    DPTR = 0x1138;
    A = 0x10;
    XD(DPTR) = A;
    DPTR = 0x1139;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    return;
}

void f_25B0(void)
{
    DPTR = 0x1602;
    A = XD(DPTR);
    A &= 0x01;
    DPTR = 0x1B20;
    if (A == 0) goto L_25C1;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    goto L_25C5;
    L_25C5:
    f_27A8();
    A |= 0x04;
    XD(DPTR) = A;
    return;
    L_25C1:
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
}

void f_25DB(void)
{
    DPTR = 0x1B19;
    A = 0x10;
    XD(DPTR) = A;
    DPTR = 0x1B1A;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    DPTR = 0x1130;
    A = 0x10;
    XD(DPTR) = A;
    DPTR = 0x1131;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    return;
}

void f_2605(void)
{
    DPTR = 0x1B1C;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    DPTR = 0x1B1D;
    A = 0x10;
    XD(DPTR) = A;
    DPTR = 0x1134;
    A = 0x02;
    XD(DPTR) = A;
    DPTR = 0x1135;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    return;
}

void f_265A(void)
{
    A = 0;
    RB(7) = A;
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x66;
    if (A == 0) goto L_2665;
    RB(7)++;
    L_2665:
    DPTR = 0x8392;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_266F;
    RB(7) = 0x01;
    L_266F:
    DPTR = 0x83B1;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_2679;
    RB(7) = 0x01;
    L_2679:
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_2683;
    RB(7) = 0x01;
    L_2683:
    DPTR = 0x83F6;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_268D;
    RB(7) = 0x01;
    L_268D:
    DPTR = 0x83C0;
    A = XD(DPTR);
    A &= 0x20;
    if (A == 0) goto L_2697;
    RB(7) = 0x01;
    L_2697:
    DPTR = 0x83BB;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_26A1;
    RB(7) = 0x01;
    L_26A1:
    A = RB(7);
    if (A != 0) goto L_26BC;
    DPTR = 0x8302;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x04);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_26B8;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    RB(7) = 0x02;
    goto L_26C1;
    L_26C1:
    A = RB(7);
    A--;
    if (A == 0) goto L_26CF;
    A--;
    if (A == 0) goto L_26CF;
    ADD8(0x02);
    if (A != 0) goto L_26CF;
    RB(7) = 0x01;
    return;
    L_26CF:
    RB(7) = 0x00;
    return;
    L_26B8:
    A = 0;
    RB(7) = A;
    goto L_26BD;
    L_26BD:
    DPTR = 0x8302;
    XD(DPTR) = A;
    L_26BC:
    A = 0;
}

void f_27A8(void)
{
    DPTR = 0x1B21;
    A = 0x20;
    XD(DPTR) = A;
    A = 0x04;
}

void f_27B0(void)
{
    DPTR = 0x1138;
    XD(DPTR) = A;
    DPTR = 0x1139;
    A = XD(DPTR);
    return;
}

void f_27B9(void)
{
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(6);
    return;
}

void f_27C6(void)
{
    XD(DPTR) = A;
    DPTR = 0x1E02;
    XD(DPTR) = A;
    DPTR = 0x1E05;
    XD(DPTR) = A;
    return;
}

void f_27D0(void)
{
    DPTR = 0x8378;
    A = RB(7);
    XD(DPTR) = A;
    RB(7) = 0x20;
    f_36DF();
    return;
}

void f_27DA(void)
{
    f_3025();
    A = RB(7);
    A ^= 0x01;
    if (A != 0) goto L_27E7;
    RB(7) = 0x21;
    f_36DF();
    L_27E7:
    return;
}

void f_27E8(void)
{
    DPTR = 0x8130;
    A = XD(DPTR);
    A |= 0x7F;
    XD(DPTR) = A;
    DPTR = 0x8131;
    A = XD(DPTR);
    A |= 0x5B;
    XD(DPTR) = A;
    DPTR = 0x8134;
    A = XD(DPTR);
    A |= 0x53;
    XD(DPTR) = A;
    return;
}

void f_2800(void)
{
    STACK[++SP] = DIR(0x08);
    A = 0x28;
    STACK[++SP] = A;
    STACK[++SP] = DPL;
    STACK[++SP] = DPH;
}

void f_280A(void)
{
    DIR(0x08) = 0x0A;
    SFR_90 = (SFR_90 & ~(1 << 0)) | (((0) & 1) << 0);
    SFR_90 = (SFR_90 & ~(1 << 1)) | (((0) & 1) << 1);
    SFR_90 = (SFR_90 & ~(1 << 2)) | (((0) & 1) << 2);
    return;
}

void f_2814(void)
{
    ec_jump((unsigned int)DPTR);
    return;
}

void f_2828(void)
{
    ec_jump((unsigned int)DPTR);
    return;
}

void f_2850(void)
{
    DPTR = 0xC407;
    f_2800();
    return;
}

void f_2855(void)
{
    DPTR = 0xC408;
    f_2800();
    return;
}

void f_285A(void)
{
    DPTR = 0xC409;
    f_2800();
    return;
}

void f_285F(void)
{
    DPTR = 0xC40A;
    f_2800();
    return;
}

void f_2864(void)
{
    DPTR = 0xC40B;
    f_2800();
    return;
}

void f_2869(void)
{
    DPTR = 0xC40C;
    f_2800();
    return;
}

void f_286E(void)
{
    DPTR = 0xC40D;
    f_2800();
    return;
}

void f_2873(void)
{
    DPTR = 0xC40E;
    f_2800();
    return;
}

void f_2878(void)
{
    DPTR = 0xC40F;
    f_2800();
    return;
}

void f_287D(void)
{
    DPTR = 0xC422;
    f_2800();
    return;
}

void f_2882(void)
{
    DPTR = 0xC436;
    f_2800();
    return;
}

void f_28A5(void)
{
    DPTR = 0xC45D;
    f_2800();
    return;
}

void f_28AA(void)
{
    DPTR = 0xC45E;
    f_2800();
    return;
}

void f_28AF(void)
{
    DPTR = 0xC45F;
    f_2800();
    return;
}

void f_2B3E(void)
{
    DPTR = 0xC4B3;
    f_2800();
    return;
}

void f_2B43(void)
{
    DPTR = 0xC5A8;
    f_2800();
    return;
}

void f_2B48(void)
{
    DPTR = 0xC4AA;
    f_2800();
    return;
}

void f_2B4D(void)
{
    DPTR = 0xB3E5;
    f_2800();
    return;
}

void f_2B52(void)
{
    DPTR = 0xDB85;
    f_2800();
    return;
}

void f_2B57(void)
{
    DPTR = 0xB3E4;
    f_2800();
    return;
}

void f_2B5C(void)
{
    DPTR = 0xB430;
    f_2800();
    return;
}

void f_2B61(void)
{
    DPTR = 0x80D9;
    f_2828();
    return;
}

void f_2B6B(void)
{
    DPTR = 0xB546;
    f_2800();
    return;
}

void f_2B75(void)
{
    DPTR = 0x821A;
    f_2814();
    return;
}

void f_2B7A(void)
{
    DPTR = 0xC98E;
    f_2800();
    return;
}

void f_2B7F(void)
{
    DPTR = 0xB95E;
    f_2800();
    return;
}

void f_2B84(void)
{
    DPTR = 0x9000;
    f_2800();
    return;
}

void f_2B89(void)
{
    DPTR = 0xBF96;
    f_2800();
    return;
}

void f_2B8E(void)
{
    DPTR = 0xBE02;
    f_2800();
    return;
}

void f_2B93(void)
{
    DPTR = 0xA1E8;
    f_2800();
    return;
}

void f_2B98(void)
{
    DPTR = 0x9DB2;
    f_2800();
    return;
}

void f_2B9D(void)
{
    DPTR = 0x8FF8;
    f_2800();
    return;
}

void f_2BA2(void)
{
    DPTR = 0xB092;
    f_2800();
    return;
}

void f_2BA7(void)
{
    DPTR = 0x8A45;
    f_2800();
    return;
}

void f_2BAC(void)
{
    DPTR = 0x8FD6;
    f_2800();
    return;
}

void f_2BB1(void)
{
    DPTR = 0xA303;
    f_2800();
    return;
}

void f_2BB6(void)
{
    DPTR = 0xA1C8;
    f_2800();
    return;
}

void f_2BBB(void)
{
    DPTR = 0xC5BB;
    f_2800();
    return;
}

void f_2BC0(void)
{
    DPTR = 0xA1C2;
    f_2800();
    return;
}

void f_2BC5(void)
{
    DPTR = 0xA1C5;
    f_2800();
    return;
}

void f_2BCA(void)
{
    DPTR = 0xA1C6;
    f_2800();
    return;
}

void f_2BCF(void)
{
    DPTR = 0xA1C7;
    f_2800();
    return;
}

void f_2BD4(void)
{
    DPTR = 0xA1C9;
    f_2800();
    return;
}

void f_2BD9(void)
{
    DPTR = 0x8179;
    f_2814();
    return;
}

void f_2BDE(void)
{
    DPTR = 0xA1CA;
    f_2800();
    return;
}

void f_2BE3(void)
{
    DPTR = 0x9BC2;
    f_2800();
    return;
}

void f_2BE8(void)
{
    DPTR = 0xA108;
    f_2800();
    return;
}

void f_2BED(void)
{
    DPTR = 0xA11E;
    f_2800();
    return;
}

void f_2BF2(void)
{
    DPTR = 0x9B8E;
    f_2800();
    return;
}

void f_2BF7(void)
{
    DPTR = 0xA12D;
    f_2800();
    return;
}

void f_2BFC(void)
{
    DPTR = 0xA158;
    f_2800();
    return;
}

void f_2C01(void)
{
    DPTR = 0xA173;
    f_2800();
    return;
}

void f_2C06(void)
{
    DPTR = 0xA176;
    f_2800();
    return;
}

void f_2C0B(void)
{
    DPTR = 0xA179;
    f_2800();
    return;
}

void f_2C10(void)
{
    DPTR = 0xA17F;
    f_2800();
    return;
}

void f_2C15(void)
{
    DPTR = 0xA188;
    f_2800();
    return;
}

void f_2C1A(void)
{
    DPTR = 0xA189;
    f_2800();
    return;
}

void f_2C24(void)
{
    DPTR = 0xA19F;
    f_2800();
    return;
}

void f_2C47(void)
{
    DPTR = 0xC376;
    f_2800();
    return;
}

void f_2C4C(void)
{
    DPTR = 0xA02E;
    f_2800();
    return;
}

void f_2C51(void)
{
    DPTR = 0xA02F;
    f_2800();
    return;
}

void f_2C56(void)
{
    DPTR = 0xC35F;
    f_2800();
    return;
}

void f_2C5B(void)
{
    DPTR = 0x9160;
    f_2800();
    return;
}

void f_2C60(void)
{
    DPTR = 0x8172;
    f_2814();
    return;
}

void f_2C7E(void)
{
    DPTR = 0x8B4F;
    f_2800();
    return;
}

void f_2C9C(void)
{
    DPTR = 0x9036;
    f_2800();
    return;
}

void f_2CA1(void)
{
    DPTR = 0x8AED;
    f_2800();
    return;
}

void f_2CA6(void)
{
    DPTR = 0xC3B5;
    f_2800();
    return;
}

void f_2CAB(void)
{
    DPTR = 0x8FFB;
    f_2800();
    return;
}

void f_2CB0(void)
{
    DPTR = 0x82FD;
    f_2814();
    return;
}

void f_2CB5(void)
{
    DPTR = 0x81CE;
    f_2814();
    return;
}

void f_2CBA(void)
{
    DPTR = 0x8E71;
    f_2800();
    return;
}

void f_2CBF(void)
{
    DPTR = 0x9B1B;
    f_2800();
    return;
}

void f_2CC4(void)
{
    DPTR = 0xC3AF;
    f_2800();
    return;
}

void f_2CD3(void)
{
    DPTR = 0xC3A9;
    f_2800();
    return;
}

void f_2CD8(void)
{
    DPTR = 0xA2D5;
    f_2800();
    return;
}

void f_2CDD(void)
{
    DPTR = 0xA78B;
    f_2800();
    return;
}

void f_2CE2(void)
{
    DPTR = 0x8001;
    f_2828();
    return;
}

void f_2CE7(void)
{
    DPTR = 0xBA82;
    f_2800();
    return;
}

void f_2CEC(void)
{
    DPTR = 0xB44D;
    f_2800();
    return;
}

void f_2D41(void)
{
    DPTR = 0xBDEB;
    f_2800();
    return;
}

void f_2D46(void)
{
    DPTR = 0xBE97;
    f_2800();
    return;
}

void f_2D4B(void)
{
    DPTR = 0x825E;
    f_2814();
    return;
}

void f_2D50(void)
{
    DPTR = 0x8836;
    f_2814();
    return;
}

void f_2D55(void)
{
    DPTR = 0x86FE;
    f_2814();
    return;
}

void f_2D5A(void)
{
    DPTR = 0x9698;
    f_2814();
    return;
}

void f_2D64(void)
{
    DPTR = 0x86DD;
    f_2814();
    return;
}

void f_2D6E(void)
{
    DPTR = 0x8FEB;
    f_2814();
    return;
}

void f_2D7D(void)
{
    DPTR = 0x80D2;
    f_2828();
    return;
}

void f_2DD2(void)
{
    DPTR = 0x94D7;
    f_2814();
    return;
}

void f_2DDC(void)
{
    DPTR = 0xE50F;
    f_2800();
    return;
}

void f_2DE2(void)
{
    A = RB(7);
    if (A == 0) goto L_2DF9;
    DPTR = 0x898A;
    A = XD(DPTR);
    A &= 0x40;
    if (A == 0) goto L_2DF0;
    RB(7) = 0x01;
    return;
    L_2DF0:
    DPTR = 0x89A6;
    A = XD(DPTR);
    A |= 0x40;
    XD(DPTR) = A;
    goto L_2E3B;
    L_2E3B:
    f_424E();
    f_1A4C();
    A = RB(7);
    if (A == 0) goto L_2E4E;
    f_44FF();
    if (A == 0) goto L_2E4E;
    RB(7) = 0x72;
    f_2B52();
    L_2E4E:
    f_424E();
    f_1A4C();
    A = RB(7);
    if (A == 0) goto L_2E61;
    f_44FF();
    if (A == 0) goto L_2E61;
    RB(7) = 0x73;
    f_2B52();
    L_2E61:
    f_424E();
    f_1A4C();
    A = RB(7);
    if (A == 0) goto L_2E77;
    f_44FF();
    if (A == 0) goto L_2E74;
    RB(7) = 0x74;
    f_2B52();
    L_2E74:
    RB(7) = 0x01;
    return;
    L_2E77:
    RB(7) = 0x00;
    return;
    L_2DF9:
    f_4473();
    XD(DPTR) = A;
    DPTR = 0x837E;
    XD(DPTR) = A;
    DPTR = 0x837F;
    XD(DPTR) = A;
    f_449C();
    A = 0x7C;
    f_425C();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_2E18;
    RB(7) = 0x70;
    f_2B52();
    L_2E18:
    f_43D2();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_2E29;
    RB(7) = 0x71;
    f_2B52();
    L_2E29:
    DPTR = 0x898A;
    A = XD(DPTR);
    A &= 0x40;
    if (A != 0) goto L_2E34;
    RB(7) = 0x01;
    return;
    L_2E34:
    DPTR = 0x89A6;
    A = XD(DPTR);
    A &= 0xBF;
    XD(DPTR) = A;
}

void f_2E7A(void)
{
    f_42BF();
    if (A != 0) goto L_2E82;
    f_2F35();
    return;
    L_2E82:
    C = 0;
    DPTR = 0x848F;
    A = XD(DPTR);
    SUBB8(0x18);
    DPTR = 0x848E;
    A = XD(DPTR);
    SUBB8(0x01);
    if (C != 0) goto L_2E98;
    f_43E2();
    A = 0x0D;
    goto L_2EA7;
    L_2EA7:
    f_4435();
    A = 0x0F;
    f_443F();
    A = 0x0F;
    XD(DPTR) = A;
    return;
    L_2E98:
    C = 0;
    DPTR = 0x848F;
    A = XD(DPTR);
    SUBB8(0xE6);
    f_43EC();
    if (C != 0) goto L_2EB3;
    f_44D6();
    L_2EB3:
    C = 0;
    DPTR = 0x848F;
    A = XD(DPTR);
    SUBB8(0x64);
    f_43EC();
    if (C != 0) goto L_2ED3;
    A = 0;
    DPTR = 0x837A;
    XD(DPTR) = A;
    A = 0x04;
    f_4356();
    A = 0x05;
    XD(DPTR) = A;
    DPTR = 0x89D0;
    A = 0x80;
    goto L_2EEE;
    L_2EEE:
    XD(DPTR) = A;
    DPTR = 0x89D1;
    A = 0x05;
    XD(DPTR) = A;
    return;
    L_2ED3:
    C = 0;
    DPTR = 0x848F;
    A = XD(DPTR);
    SUBB8(0x5A);
    f_43EC();
    if (C != 0) goto L_2EF6;
    f_43E2();
    A = 0x03;
    f_4435();
    A = 0x05;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x89D0;
    L_2EF6:
    C = 0;
    DPTR = 0x848F;
    A = XD(DPTR);
    SUBB8(0x41);
    f_43EC();
    if (C != 0) goto L_2F13;
    DPTR = 0x837A;
    A = 0x80;
    f_4353();
    A = 0x03;
    f_443F();
    A = 0x03;
    XD(DPTR) = A;
    return;
    L_2F13:
    C = 0;
    DPTR = 0x848F;
    A = XD(DPTR);
    SUBB8(0x2D);
    f_43EC();
    if (C != 0) goto L_2F35;
    A = 0;
    DPTR = 0x837A;
    f_4353();
    A = 0x02;
    XD(DPTR) = A;
    DPTR = 0x89D0;
    A = 0x80;
    XD(DPTR) = A;
    DPTR = 0x89D1;
    A = 0x02;
    XD(DPTR) = A;
    L_2F35:
    return;
}

void f_2F36(void)
{
    f_4449();
    DPTR = 0x89A4;
    A = 0x8B;
    if (C != 0) goto L_2F49;
    XD(DPTR) = A;
    DPTR = 0x89A5;
    A = 0x2C;
    XD(DPTR) = A;
    goto L_2F50;
    L_2F50:
    DPTR = 0x83C0;
    A = XD(DPTR);
    if (A != 0) goto L_2F67;
    f_42BF();
    DPTR = 0x89A6;
    if (A == 0) goto L_2F62;
    A = 0x14;
    goto L_2F64;
    L_2F64:
    f_44E1();
    L_2F67:
    return;
    L_2F62:
    A = 0x16;
    L_2F49:
    XD(DPTR) = A;
    DPTR = 0x89A5;
    A = 0x28;
    XD(DPTR) = A;
}

void f_2F68(void)
{
    A = 0;
    DPTR = 0x0694;
    XD(DPTR) = A;
    tmp = A; A = RB(0); RB(0) = tmp;
    A = 0x95;
    tmp = A; A = RB(0); RB(0) = tmp;
    tmp = A; A = RB(4); RB(4) = tmp;
    A = 0x06;
    tmp = A; A = RB(4); RB(4) = tmp;
    tmp = A; A = RB(5); RB(5) = tmp;
    A = 0x01;
    tmp = A; A = RB(5); RB(5) = tmp;
    RB(3) = 0xFF;
    RB(2) = 0x42;
    RB(1) = 0x46;
    RB(6) = A;
    RB(7) = 0x02;
    f_7712();
    f_43F3();
    if (A == 0) goto L_2F8D;
    RB(7) = 0x00;
    return;
    L_2F8D:
    f_2E7A();
    f_2F36();
    f_42D2();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_2FA2;
    f_4388();
    L_2FA2:
    DPTR = 0x83C0;
    A = XD(DPTR);
    if (A != 0) goto L_2FB4;
    f_424E();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_2FB4;
    f_4388();
    L_2FB4:
    f_43FA();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_2FC3;
    f_4388();
    L_2FC3:
    f_440A();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_2FD2;
    f_4388();
    L_2FD2:
    f_441A();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_2FE1;
    f_4388();
    L_2FE1:
    f_42FB();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_2FF0;
    f_4388();
    L_2FF0:
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_2FFA;
    RB(7) = A;
    return;
    L_2FFA:
    f_449C();
    DPTR++;
    A = 0x7C;
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_300C;
    f_4388();
    L_300C:
    f_43D2();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_301B;
    f_4388();
    L_301B:
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x89CF;
    XD(DPTR) = A;
    return;
}

void f_3025(void)
{
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    f_42BF();
    if (A != 0) goto L_303C;
    f_447C();
    f_43A4();
    DPTR = 0x0693;
    A++;
    XD(DPTR) = A;
    RB(7) = A;
    return;
    L_303C:
    f_4473();
    XD(DPTR) = A;
    DPTR = 0x8392;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_3058;
    DPTR = 0x8390;
    A = XD(DPTR);
    DPTR++;
    A = XD(DPTR);
    DPTR = 0x837E;
    XD(DPTR) = A;
    DPTR = 0x8390;
    A = XD(DPTR);
    goto L_305D;
    L_305D:
    DPTR = 0x837F;
    XD(DPTR) = A;
    f_2F68();
    A = RB(7);
    if (A == 0) goto L_3078;
    f_4324();
    if (C != 0) goto L_3071;
    RB(7) = 0x40;
    f_36DF();
    L_3071:
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    goto L_308B;
    L_308B:
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    return;
    L_3078:
    f_42BF();
    if (A != 0) goto L_3081;
    f_447C();
    XD(DPTR) = A;
    L_3081:
    A = 0;
    DPTR = 0x8380;
    XD(DPTR) = A;
    DPTR = 0x0693;
    A++;
    XD(DPTR) = A;
    L_3058:
    A = 0;
    DPTR = 0x837E;
    XD(DPTR) = A;
}

void f_3037(void)
{
    A = CD(DPTR + A);
    A++;
    XD(DPTR) = A;
    RB(7) = A;
    return;
}

void f_3091(void)
{
    tmp = A; A = RB(0); RB(0) = tmp;
    A = 0x93;
    tmp = A; A = RB(0); RB(0) = tmp;
    tmp = A; A = RB(4); RB(4) = tmp;
    A = 0x06;
    RB(2) = 0x42;
    RB(1) = 0x48;
    f_437A();
    f_43F3();
    if (A == 0) goto L_30F6;
    f_42BF();
    if (A != 0) goto L_30F6;
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x66;
    if (A != 0) goto L_30F6;
    f_4506();
    f_2CE7();
    DPTR = 0x160A;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    DPTR = 0x0693;
    A = 0x10;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    L_30C9:
    DPTR = 0x0695;
    f_448A();
    if (C == 0) goto L_30F6;
    f_44B6();
    A = 0x93;
    f_42A5();
    f_1A4C();
    A = RB(7);
    if (A == 0) goto L_30EE;
    f_44B6();
    DPTR++;
    A = 0x93;
    f_42A6();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_30F6;
    L_30EE:
    DPTR = 0x0695;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_30C9;
    L_30F6:
    return;
}

void f_326A(void)
{
    DPTR = 0x8132;
    A = XD(DPTR);
    A |= 0x37;
    XD(DPTR) = A;
    DPTR = 0x8133;
    A = XD(DPTR);
    A |= 0xE0;
    XD(DPTR) = A;
    DPTR = 0x8134;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    return;
}

void f_3280(void)
{
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x0695;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x0697;
    f_79E4();
    f_43AB();
    if (A == 0) goto L_32C0;
    DPTR = 0x8460;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_32A9;
    A = XD(DPTR);
    A |= 0x08;
    goto L_32C6;
    L_32C6:
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    L_32CB:
    f_43AB();
    if (A != 0) goto L_32D3;
    f_34B0();
    return;
    L_32D3:
    f_43F3();
    if (A != 0) goto L_32DB;
    f_27E8();
    L_32DB:
    DPTR = 0x8907;
    A = XD(DPTR);
    if (A != 0) goto L_32EF;
    DPTR = 0x8906;
    A = XD(DPTR);
    if (A != 0) goto L_32EF;
    DPTR = 0x8460;
    A = XD(DPTR);
    A &= 0xF7;
    goto L_32FC;
    L_32FC:
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    goto L_330B;
    L_330B:
    f_44C2();
    if (C == 0) goto L_3316;
    DPTR = 0x8917;
    A = XD(DPTR);
    if (A == 0) goto L_3319;
    L_3316:
    f_43B9();
    L_3319:
    DPTR = 0x8902;
    A = XD(DPTR);
    DPTR = 0x847A;
    XD(DPTR) = A;
    DPTR = 0x8903;
    A = XD(DPTR);
    DPTR = 0x847B;
    XD(DPTR) = A;
    DPTR = 0x8916;
    A = XD(DPTR);
    DPTR = 0x8474;
    XD(DPTR) = A;
    DPTR = 0x8917;
    A = XD(DPTR);
    DPTR = 0x8475;
    XD(DPTR) = A;
    DPTR = 0x8904;
    A = XD(DPTR);
    DPTR = 0x8470;
    XD(DPTR) = A;
    DPTR = 0x8905;
    A = XD(DPTR);
    DPTR = 0x8471;
    XD(DPTR) = A;
    DPTR = 0x8914;
    A = XD(DPTR);
    DPTR = 0x8472;
    XD(DPTR) = A;
    DPTR = 0x8915;
    A = XD(DPTR);
    DPTR = 0x8473;
    XD(DPTR) = A;
    DPTR = 0x8900;
    A = XD(DPTR);
    DPTR = 0x8476;
    XD(DPTR) = A;
    DPTR = 0x8901;
    A = XD(DPTR);
    DPTR = 0x8477;
    XD(DPTR) = A;
    DPTR = 0x895A;
    A = XD(DPTR);
    DPTR = 0x848A;
    XD(DPTR) = A;
    DPTR = 0x895B;
    A = XD(DPTR);
    DPTR = 0x848B;
    XD(DPTR) = A;
    DPTR = 0x895C;
    A = XD(DPTR);
    DPTR = 0x848C;
    XD(DPTR) = A;
    DPTR = 0x895D;
    A = XD(DPTR);
    DPTR = 0x848D;
    XD(DPTR) = A;
    DPTR = 0x8907;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x8906;
    A = XD(DPTR);
    RB(4) = 0x00;
    f_451E();
    A = DIR(0x6C);
    SUBB8(0x00);
    A = DIR(0x6B);
    SUBB8(0x80);
    if (C != 0) goto L_33AF;
    DIR(0x6C) ^= 0xFF;
    DIR(0x6B) ^= 0xFF;
    DIR(0x6C)++;
    A = DIR(0x6C);
    if (A != 0) goto L_33AF;
    DIR(0x6B)++;
    L_33AF:
    RB(7) = DIR(0x6C);
    DPTR = 0x846C;
    A = RB(7);
    XD(DPTR) = A;
    A = DIR(0x6B);
    DPTR = 0x846D;
    XD(DPTR) = A;
    DPTR = 0x8908;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8398;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_33DB;
    DPTR = 0x8908;
    A = XD(DPTR);
    DPTR = 0x8398;
    XD(DPTR) = A;
    DPTR = 0x8908;
    A = XD(DPTR);
    DPTR = 0x847C;
    XD(DPTR) = A;
    f_44CE();
    L_33DB:
    f_44C2();
    if (C == 0) goto L_3418;
    DPTR = 0x8917;
    A = XD(DPTR);
    if (A != 0) goto L_3418;
    DPTR = 0x8918;
    A = XD(DPTR);
    DPTR = 0x8468;
    XD(DPTR) = A;
    DPTR = 0x8919;
    A = XD(DPTR);
    DPTR = 0x8469;
    XD(DPTR) = A;
    DPTR = 0x8908;
    A = XD(DPTR);
    B = 0x3C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    RB(7) = A;
    DPTR = 0x89E0;
    A = B;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x89E0;
    A = XD(DPTR);
    DPTR++;
    A = XD(DPTR);
    DPTR = 0x846E;
    XD(DPTR) = A;
    DPTR = 0x89E0;
    A = XD(DPTR);
    goto L_347D;
    L_347D:
    DPTR = 0x846F;
    XD(DPTR) = A;
    L_3481:
    DPTR = 0x8399;
    C = 0;
    f_432B();
    if (C == 0) goto L_3495;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    A ^= 0x03;
    if (A != 0) goto L_3495;
    f_44CE();
    L_3495:
    DPTR = 0x8392;
    A = XD(DPTR);
    A &= 0x80;
    if (A == 0) goto L_34B0;
    f_4528();
    if (A != 0) goto L_34B0;
    DPTR = 0x8392;
    A = XD(DPTR);
    A &= 0x7F;
    XD(DPTR) = A;
    A = 0;
    RB(5) = A;
    RB(7) = 0x21;
    f_2CEC();
    L_34B0:
    return;
    L_3418:
    DPTR = 0x890E;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8468;
    A = XD(DPTR);
    A ^= RB(7);
    if (A != 0) goto L_3430;
    DPTR = 0x890F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8469;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_344B;
    L_3430:
    RB(7) = 0x01;
    f_36DF();
    DPTR = 0x890E;
    A = XD(DPTR);
    DPTR = 0x8468;
    XD(DPTR) = A;
    DPTR = 0x890F;
    A = XD(DPTR);
    DPTR = 0x8469;
    XD(DPTR) = A;
    f_43B9();
    f_44CE();
    L_344B:
    DPTR = 0x846F;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x846E;
    A = XD(DPTR);
    RB(4) = 0x00;
    ADD8(0x00);
    DIR(0x61) = A;
    A = RB(4);
    ADDC8(RB(6));
    DIR(0x60) = A;
    DPTR = 0x8469;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x8468;
    A = XD(DPTR);
    f_451E();
    A = DIR(0x61);
    SUBB8((DIR(0x6C)));
    A = DIR(0x60);
    SUBB8((DIR(0x6B)));
    if (C != 0) goto L_3481;
    A = XD(DPTR);
    DPTR = 0x846E;
    XD(DPTR) = A;
    DPTR = 0x8469;
    A = XD(DPTR);
    L_32EF:
    DPTR = 0x8907;
    A = XD(DPTR);
    DPTR = 0x8460;
    if (!((A >> 7) & 1)) goto L_3303;
    A = XD(DPTR);
    A |= 0x08;
    L_3303:
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    L_32A9:
    f_4517();
    DPTR = 0x8460;
    if (A == 0) goto L_32B6;
    A = XD(DPTR);
    A &= 0xF7;
    goto L_32C6;
    L_32B6:
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    goto L_32CB;
    L_32C0:
    DPTR = 0x8460;
    A = XD(DPTR);
    A &= 0xF7;
}

void f_36DF(void)
{
    DPTR = 0x8370;
    A = RB(7);
    f_43A4();
    DPTR = 0x8370;
    A = XD(DPTR);
    f_7A4A();
    ADDC8(XD(((unsigned int)SFR_A0 << 8) | RB(1)));
    RB(7)++;
    f_3037();
    return;
}

void f_3787(void)
{
    DPTR = 0x83AC;
    A = XD(DPTR);
    RB(7) = A;
    DPTR++;
    A = XD(DPTR);
    DPTR = 0x83AE;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x8896;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_37B7;
    DPTR = 0x8397;
    A = 0x19;
    XD(DPTR) = A;
    DPTR = 0x8903;
    A = 0x0B;
    XD(DPTR) = A;
    DPTR = 0x8902;
    A = 0xA4;
    XD(DPTR) = A;
    DPTR = 0x8896;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    L_37B7:
    DPTR = 0x8903;
    A = XD(DPTR);
    DPTR = 0x8902;
    f_4289();
    DPTR = 0x83AC;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    C = 1;
    DPTR = 0x83AD;
    A = XD(DPTR);
    SUBB8(0xAA);
    DPTR = 0x83AC;
    A = XD(DPTR);
    SUBB8(0x0A);
    if (C != 0) goto L_37EE;
    DPTR++;
    A = XD(DPTR);
    ADD8(0x56);
    RB(7) = A;
    DPTR = 0x83AC;
    A = XD(DPTR);
    ADDC8(0xF5);
    RB(6) = A;
    RB(5) = 0x0A;
    f_7790();
    DPTR = 0x8397;
    A = RB(7);
    XD(DPTR) = A;
    return;
    L_37EE:
    A = 0;
    DPTR = 0x8397;
    XD(DPTR) = A;
    return;
}

void f_37F4(void)
{
    DPTR = 0x8907;
    A = XD(DPTR);
    if (!((A >> 7) & 1)) goto L_3814;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x8906;
    f_428A();
    RB(6) = A;
    C = 0;
    A = 0xFF;
    SUBB8(RB(7));
    DPTR = 0x8959;
    XD(DPTR) = A;
    A = 0xFF;
    SUBB8(RB(6));
    DPTR = 0x8958;
    XD(DPTR) = A;
    return;
    L_3814:
    A = 0;
    DPTR = 0x8958;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    return;
}

void f_381C(void)
{
    DPTR = 0x8901;
    A = XD(DPTR);
    A &= 0x80;
    if (A != 0) goto L_382A;
    f_4293();
    f_1A4C();
    L_382A:
    return;
}

void f_382B(void)
{
    DPTR = 0x8915;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_3858;
    DPTR = 0x838C;
    f_44E9();
    if (C != 0) goto L_3864;
    f_452F();
    if (A != 0) goto L_3864;
    DPTR = 0x8395;
    A = XD(DPTR);
    A |= 0x08;
    XD(DPTR) = A;
    RB(7) = 0x12;
    f_36DF();
    f_4348();
    RB(5) = 0x06;
    RB(7) = 0x84;
    f_2CE7();
    goto L_3864;
    L_3864:
    DPTR = 0x8905;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x8904;
    f_428A();
    DPTR = 0x0693;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    C = 1;
    DPTR = 0x0694;
    A = XD(DPTR);
    SUBB8(0x50);
    DPTR = 0x0693;
    A = XD(DPTR);
    SUBB8(0x46);
    if (C != 0) goto L_38B2;
    DPTR = 0x838D;
    f_44E9();
    if (C != 0) goto L_38BE;
    f_452F();
    if (A != 0) goto L_38BE;
    DPTR = 0x8395;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    RB(7) = 0x12;
    f_36DF();
    DPTR = 0x8905;
    A = XD(DPTR);
    RB(3) = A;
    DPTR = 0x8904;
    A = XD(DPTR);
    DPTR = 0x06B2;
    XD(DPTR) = A;
    RB(5) = 0x05;
    RB(7) = 0x84;
    f_2CE7();
    return;
    L_38BE:
    return;
    L_38B2:
    DPTR = 0x8395;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x838D;
    XD(DPTR) = A;
    L_3858:
    DPTR = 0x8395;
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x838C;
    XD(DPTR) = A;
}

void f_39A4(void)
{
    f_42BF();
    if (A == 0) goto L_39AC;
    f_3A90();
    return;
    L_39AC:
    DPTR = 0x8397;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x41);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_39D5;
    DPTR = 0x8853;
    f_4327();
    if (C == 0) goto L_39C4;
    f_3A9D();
    return;
    L_39C4:
    A = 0;
    XD(DPTR) = A;
    f_4348();
    RB(5) = 0x06;
    RB(7) = 0x84;
    f_2CE7();
    RB(7) = 0x16;
    f_5D69();
    return;
    L_39D5:
    DPTR = 0x8397;
    f_4371();
    if (C != 0) goto L_39E0;
    f_3A82();
    return;
    L_39E0:
    DPTR = 0x8397;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x2D);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_39FA;
    A = 0;
    DPTR = 0x8853;
    XD(DPTR) = A;
    f_430B();
    if (C != 0) goto L_3A3B;
    f_3A8C();
    return;
    L_3A3B:
    goto L_3A9A;
    L_3A9A:
    A &= 0xFD;
    XD(DPTR) = A;
    return;
    L_39FA:
    DPTR = 0x8397;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x0A);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_3A3D;
    A = 0;
    DPTR = 0x8853;
    XD(DPTR) = A;
    DPTR = 0x8908;
    A = XD(DPTR);
    f_444E();
    if (C != 0) goto L_3A34;
    DPTR = 0x8847;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    C = 1;
    DPTR = 0x8959;
    A = XD(DPTR);
    SUBB8(0xB8);
    DPTR = 0x8958;
    A = XD(DPTR);
    SUBB8(0x1A);
    DPTR = 0x8846;
    A = XD(DPTR);
    if (C != 0) goto L_3A31;
    goto L_3A85;
    L_3A85:
    A |= 0x02;
    XD(DPTR) = A;
    DPTR = 0x8847;
    A = XD(DPTR);
    L_3A31:
    f_3A93();
    return;
    L_3A34:
    f_430B();
    if (C != 0) goto L_3A3B;
    f_3A8C();
    return;
    L_3A3D:
    DPTR = 0x8397;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x00);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) { f_3A82(); return; }
    A = 0;
    DPTR = 0x8853;
    XD(DPTR) = A;
    DPTR = 0x8847;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    DPTR = 0x8908;
    A = XD(DPTR);
    SUBB8(0x32);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_3A6B;
    f_4312();
    if (C != 0) goto L_3A69;
    f_3A8C();
    return;
    L_3A69:
    goto L_3A9A;
    L_3A6B:
    C = 1;
    DPTR = 0x8959;
    A = XD(DPTR);
    SUBB8(0x02);
    DPTR = 0x8958;
    A = XD(DPTR);
    SUBB8(0x00);
    DPTR = 0x8846;
    A = XD(DPTR);
    if (C != 0) goto L_3A80;
    f_3A8C();
    return;
    L_3A80:
    goto L_3A9A;
}

void f_3A82(void)
{
    f_4536();
    A |= 0x02;
    XD(DPTR) = A;
    DPTR = 0x8847;
    A = XD(DPTR);
}

void f_3A8C(void)
{
    A |= 0x02;
    XD(DPTR) = A;
    return;
}

void f_3A90(void)
{
    f_4536();
}

void f_3A93(void)
{
    A &= 0xFD;
    XD(DPTR) = A;
    DPTR = 0x8847;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    return;
}

void f_3A9E(void)
{
    f_4528();
    if (A == 0) goto L_3AA8;
    A = XD(DPTR);
    A ^= 0x33;
    if (A != 0) goto L_3ADF;
    L_3AA8:
    DPTR = 0x847C;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x02);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_3ADD;
    f_43AB();
    if (A == 0) goto L_3ADD;
    f_42BF();
    if (A != 0) goto L_3ADF;
    DPTR = 0x83A3;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    A ^= 0x28;
    if (A != 0) goto L_3AE4;
    XD(DPTR) = A;
    RB(7) = 0x14;
    f_5D69();
    A = 0;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    RB(3) = A;
    RB(5) = 0x0D;
    RB(7) = 0x84;
    f_2CE7();
    return;
    L_3AE4:
    return;
    L_3ADF:
    A = 0;
    DPTR = 0x83A3;
    XD(DPTR) = A;
    L_3ADD:
    goto L_3ADF;
}

void f_3AE5(void)
{
    f_43AB();
    if (A == 0) goto L_3B43;
    f_42BF();
    if (A != 0) goto L_3B43;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_3B43;
    DPTR = 0x83AC;
    A = XD(DPTR);
    if (A != 0) goto L_3AFC;
    DPTR++;
    A = XD(DPTR);
    L_3AFC:
    if (A == 0) goto L_3B43;
    C = 0;
    DPTR = 0x83AD;
    A = XD(DPTR);
    SUBB8(0x5A);
    DPTR = 0x83AC;
    A = XD(DPTR);
    SUBB8(0x0A);
    if (C == 0) goto L_3B37;
    DPTR = 0x83AB;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_3B32;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    RB(3) = A;
    RB(5) = 0x07;
    RB(7) = 0x84;
    f_2CE7();
    f_4348();
    RB(5) = 0x08;
    RB(7) = 0x85;
    f_2CE7();
    DPTR = 0x83AB;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    L_3B32:
    f_42E2();
    goto L_3B4C;
    L_3B4C:
    f_4528();
    if (A == 0) goto L_3B54;
    f_42E2();
    L_3B54:
    return;
    L_3B37:
    f_42E2();
    DPTR = 0x83AB;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    goto L_3B4C;
    L_3B43:
    f_42E2();
    DPTR = 0x83AB;
    f_433F();
}

void f_3B55(void)
{
    f_3787();
    f_37F4();
    f_382B();
    f_27FE();
    f_39A4();
    f_3A9E();
    f_3AE5();
    f_381C();
    return;
}

void f_3B6D(void)
{
    DPTR = 0x8370;
    A = XD(DPTR);
    A ^= 0x04;
    if (A != 0) goto L_3B87;
    f_4517();
    if (A == 0) goto L_3B87;
    f_3025();
    A = RB(7);
    A ^= 0x01;
    if (A != 0) goto L_3B87;
    RB(7) = 0x10;
    f_36DF();
    L_3B87:
    return;
}

void f_3B88(void)
{
    DPTR = 0x8370;
    A = XD(DPTR);
    A ^= 0x05;
    if (A != 0) goto L_3B9D;
    DPTR = 0x8914;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_3B9D;
    RB(7) = 0x11;
    f_36DF();
    L_3B9D:
    return;
}

void f_3CBE(void)
{
    f_4473();
    A++;
    XD(DPTR) = A;
    DPTR = 0x837E;
    A = 0xC0;
    XD(DPTR) = A;
    DPTR = 0x837F;
    A = 0x44;
    XD(DPTR) = A;
    f_2F68();
    A = RB(7);
    if (A == 0) goto L_3CDF;
    f_4324();
    if (C != 0) goto L_3CE8;
    RB(7) = 0x40;
    f_36DF();
    return;
    L_3CE8:
    return;
    L_3CDF:
    DPTR = 0x8393;
    A = XD(DPTR);
    A |= 0x20;
    f_439D();
}

void f_3CE9(void)
{
    f_42BF();
    if (A == 0) goto L_3D3C;
    DPTR = 0x8393;
    A = XD(DPTR);
    A &= 0x20;
    if (A != 0) goto L_3CF9;
    f_3CBE();
    return;
    L_3CF9:
    f_43AB();
    if (A == 0) goto L_3D12;
    f_438F();
    RB(4) = 0x00;
    RB(5) = 0xC8;
    f_42B4();
    if (A != 0) goto L_3D5C;
    f_4510();
    RB(7) = 0x04;
    f_3D4F();
    return;
    L_3D5C:
    return;
    L_3D12:
    f_438F();
    f_42B0();
    if (A != 0) goto L_3D27;
    f_3CBE();
    f_4364();
    if (C != 0) goto L_3D5C;
    RB(7) = 0x01;
    f_3D59();
    return;
    L_3D27:
    DPTR = 0x8386;
    RB(4) = 0x02;
    RB(5) = 0x58;
    f_44F4();
    if (A != 0) goto L_3D5C;
    f_3D5D();
    if (A == 0) goto L_3D5C;
    RB(7) = 0x01;
    f_3D4F();
    return;
    L_3D3C:
    f_438F();
    RB(4) = 0x00;
    RB(5) = 0x64;
    f_44F4();
    if (A != 0) goto L_3D5C;
    f_3D5D();
    if (A == 0) goto L_3D52;
    RB(7) = 0x01;
    L_3D52:
    f_4364();
    if (C != 0) goto L_3D5C;
    RB(7) = 0x04;
}

void f_3D4F(void)
{
    f_36DF();
    return;
}

void f_3D59(void)
{
    f_27D0();
    return;
}

void f_3D5D(void)
{
    DPTR = 0x069D;
    A = 0x14;
    XD(DPTR) = A;
    RB(6) = 0x89;
    DPTR++;
    A = 0x89;
    XD(DPTR) = A;
    DPTR++;
    A = 0x0C;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = 0x16;
    RB(5) = 0x0C;
    RB(7) = A;
    f_1A4C();
    A = RB(7);
    return;
}

void f_3DAD(void)
{
    DPTR = 0x8490;
    A = XD(DPTR);
    A &= 0x04;
    if (A != 0) goto L_3DC7;
    f_3025();
    A = RB(7);
    DPTR = 0x8490;
    if (A != 0) goto L_3DC3;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    return;
    L_3DC3:
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    L_3DC7:
    return;
}

void f_3DC8(void)
{
    DPTR = 0x8490;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_3DD8;
    A = XD(DPTR);
    A &= 0x04;
    if (A != 0) goto L_3DF0;
    f_3DAD();
    return;
    L_3DF0:
    return;
    L_3DD8:
    DPTR = 0x8490;
    A = XD(DPTR);
    A &= 0x04;
    if (A == 0) goto L_3DF0;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    DPTR = 0x8131;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    RB(7) = 0x01;
    f_36DF();
}

void f_3EF1(void)
{
    f_42BF();
    if (A == 0) goto L_3F47;
    DPTR = 0x83C0;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_3F0A;
    DPTR = 0x8370;
    A = XD(DPTR);
    A ^= 0x30;
    if (A == 0) goto L_3F5D;
    RB(7) = 0x30;
    goto L_3F5A;
    L_3F5A:
    f_36DF();
    L_3F5D:
    return;
    L_3F0A:
    DPTR = 0x83C0;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_3F1E;
    DPTR = 0x8370;
    A = XD(DPTR);
    A ^= 0x31;
    if (A == 0) goto L_3F5D;
    RB(7) = 0x31;
    goto L_3F5A;
    L_3F1E:
    DPTR = 0x83C0;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_3F32;
    DPTR = 0x8370;
    A = XD(DPTR);
    A ^= 0x32;
    if (A == 0) goto L_3F5D;
    RB(7) = 0x32;
    goto L_3F5A;
    L_3F32:
    DPTR = 0x8394;
    A = XD(DPTR);
    if (A == 0) goto L_3F5D;
    A = 0;
    RB(7) = A;
    f_2DE2();
    A = RB(7);
    if (A == 0) goto L_3F5D;
    f_4333();
    RB(7) = 0x04;
    goto L_3F5A;
    L_3F47:
    DPTR = 0x8394;
    A = XD(DPTR);
    if (A == 0) goto L_3F5D;
    A = 0;
    RB(7) = A;
    f_2DE2();
    A = RB(7);
    if (A == 0) goto L_3F5D;
    f_4333();
    RB(7) = 0x05;
}

void f_3F5E(void)
{
    DPTR = 0x83BC;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_3FAB;
    A = XD(DPTR);
    A &= 0xEF;
    XD(DPTR) = A;
    DPTR = 0x8952;
    A = XD(DPTR);
    if (A != 0) goto L_3FA4;
    DPTR = 0x8953;
    A = XD(DPTR);
    if (A != 0) goto L_3FA4;
    DPTR = 0x8486;
    A = XD(DPTR);
    A ^= 0x21;
    if (A != 0) goto L_3F8C;
    DPTR = 0x8487;
    A = XD(DPTR);
    A ^= 0x28;
    if (A != 0) goto L_3F8C;
    DPTR = 0x8486;
    XD(DPTR) = A;
    goto L_3FA7;
    L_3FA7:
    DPTR = 0x8487;
    XD(DPTR) = A;
    L_3FAB:
    return;
    L_3F8C:
    DPTR = 0x8486;
    A = XD(DPTR);
    DPTR = 0x8952;
    XD(DPTR) = A;
    DPTR = 0x8487;
    A = XD(DPTR);
    DPTR = 0x8953;
    XD(DPTR) = A;
    DPTR = 0x8131;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    return;
    L_3FA4:
    f_44A9();
}

void f_3FAC(void)
{
    DPTR = 0x83F0;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8372;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x64);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_4013;
    A = 0;
    XD(DPTR) = A;
    f_43F3();
    if (A != 0) goto L_3FCB;
    f_326A();
    L_3FCB:
    f_43AB();
    if (A == 0) goto L_3FF3;
    f_3B55();
    f_3091();
    f_3280();
    f_3F5E();
    f_452F();
    if (A != 0) goto L_3FE4;
    f_3EF1();
    L_3FE4:
    f_42BF();
    if (A == 0) goto L_3FEE;
    f_3B6D();
    goto L_4013;
    L_4013:
    DPTR = 0x8370;
    A = XD(DPTR);
    f_7A4A();
    if (C != 0) goto L_405B;
    f_4040();
    return;
    L_405B:
    ADDC8(RB(6));
    RB(1)++;
    f_27DA();
    return;
    L_3FEE:
    f_3B88();
    goto L_4013;
    L_3FF3:
    A = 0;
    DPTR = 0x8853;
    XD(DPTR) = A;
    DPTR = 0x8854;
    XD(DPTR) = A;
    DPTR = 0x8846;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    DPTR = 0x8847;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    f_42E2();
    DPTR = 0x83AB;
    f_433F();
}

void f_4040(void)
{
    ADDC8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    C = 0;
    f_3CE9();
    return;
}

void f_4061(void)
{
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    f_42C6();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_4075;
    f_43B2();
    L_4075:
    DPTR = 0x89A6;
    A = 0x14;
    f_44E1();
    f_424E();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_4089;
    f_43B2();
    L_4089:
    f_42EF();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_4098;
    f_43B2();
    L_4098:
    DPTR = 0x1603;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_40A6;
    f_44D6();
    XD(DPTR) = A;
    goto L_40AC;
    L_40AC:
    f_43FA();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_40BB;
    f_43B2();
    L_40BB:
    f_4436();
    A = 0x0F;
    XD(DPTR) = A;
    f_440A();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_40D0;
    f_43B2();
    L_40D0:
    f_4440();
    A = 0x0F;
    XD(DPTR) = A;
    f_441A();
    f_425D();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_40E5;
    f_43B2();
    L_40E5:
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x89D6;
    XD(DPTR) = A;
    A = RB(7);
    if (A != 0) goto L_40F8;
    DPTR = 0x8998;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    L_40F8:
    return;
    L_40A6:
    f_43E2();
    A = 0x0D;
    XD(DPTR) = A;
}

void f_40F9(void)
{
    f_43F3();
    if (A == 0) goto L_4101;
    f_41AC();
    return;
    L_4101:
    DPTR = 0x83C3;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_410C;
    f_41AC();
    return;
    L_410C:
    DPTR = 0x8998;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_4117;
    f_4061();
    L_4117:
    f_4449();
    if (C != 0) goto L_4140;
    DPTR = 0x89A4;
    A = XD(DPTR);
    A ^= 0x8B;
    if (A != 0) goto L_412C;
    DPTR = 0x89A5;
    A = XD(DPTR);
    A ^= 0x2C;
    if (A == 0) goto L_4159;
    L_412C:
    DPTR = 0x89A4;
    A = 0x8B;
    XD(DPTR) = A;
    A = 0x2C;
    f_42CE();
    f_425D();
    f_1A4C();
    A = RB(7);
    goto L_4159;
    L_4159:
    DPTR = 0x89CB;
    A = XD(DPTR);
    A ^= 0xD4;
    if (A != 0) goto L_4169;
    DPTR = 0x89CC;
    A = XD(DPTR);
    A ^= 0x05;
    if (A == 0) goto L_4172;
    L_4169:
    f_42EF();
    f_425D();
    f_1A4C();
    L_4172:
    DPTR = 0x83C0;
    A = XD(DPTR);
    if (A != 0) goto L_41AC;
    DPTR = 0x8998;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_41AC;
    f_42BF();
    if (A == 0) goto L_4195;
    DPTR = 0x898A;
    A = XD(DPTR);
    A ^= 0x14;
    if (A == 0) goto L_41A3;
    DPTR = 0x89A6;
    A = 0x14;
    XD(DPTR) = A;
    goto L_41A3;
    L_41A3:
    f_44E2();
    f_424E();
    f_1A4C();
    L_41AC:
    return;
    L_4195:
    DPTR = 0x898A;
    A = XD(DPTR);
    A ^= 0x16;
    if (A == 0) goto L_41A3;
    DPTR = 0x89A6;
    A = 0x16;
    XD(DPTR) = A;
    L_4140:
    DPTR = 0x89A4;
    A = XD(DPTR);
    A ^= 0x8B;
    if (A != 0) goto L_4150;
    DPTR = 0x89A5;
    A = XD(DPTR);
    A ^= 0x28;
    if (A == 0) goto L_4159;
    L_4150:
    f_42C6();
    f_425D();
    f_1A4C();
}

void f_424E(void)
{
    DPTR = 0x069D;
    A = 0x3B;
    XD(DPTR) = A;
    RB(6) = 0x89;
    DPTR++;
    A = 0x89;
    XD(DPTR) = A;
    A = 0xA6;
    DPTR++;
}

void f_425D(void)
{
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = 0x12;
    RB(5) = 0x8C;
    RB(7) = A;
    return;
}

void f_428A(void)
{
    A = XD(DPTR);
    RB(4) = 0x00;
    ADD8(0x00);
    RB(7) = A;
    A = RB(4);
    ADDC8(RB(6));
    return;
}

void f_4293(void)
{
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    DPTR = 0x069D;
    A = 0x03;
    XD(DPTR) = A;
    RB(6) = 0x89;
    DPTR++;
    A = 0x89;
    XD(DPTR) = A;
    A = 0x00;
    DPTR++;
}

void f_42A6(void)
{
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = 0x16;
    RB(5) = 0x8C;
    RB(7) = A;
    return;
}

void f_42B4(void)
{
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    f_7790();
    A = RB(5);
    A |= RB(4);
    return;
}

void f_42BF(void)
{
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x01;
    return;
}

void f_42C6(void)
{
    DPTR = 0x89A4;
    A = 0x8B;
    XD(DPTR) = A;
    A = 0x28;
}

void f_42CE(void)
{
    DPTR = 0x89A5;
    XD(DPTR) = A;
}

void f_42D2(void)
{
    DPTR = 0x069D;
    A = 0x3D;
    XD(DPTR) = A;
    RB(6) = 0x89;
    DPTR++;
    A = 0x89;
    XD(DPTR) = A;
    DPTR++;
    A = 0xA4;
    return;
}

void f_42E2(void)
{
    A = 0;
    DPTR = 0x83AA;
    XD(DPTR) = A;
    DPTR = 0x8490;
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    return;
}

void f_42EF(void)
{
    DPTR = 0x89D2;
    A = 0xD4;
    XD(DPTR) = A;
    DPTR = 0x89D3;
    A = 0x05;
    XD(DPTR) = A;
}

void f_42FB(void)
{
    DPTR = 0x069D;
    A = 0x3C;
    XD(DPTR) = A;
    RB(6) = 0x89;
    DPTR++;
    A = 0x89;
    XD(DPTR) = A;
    DPTR++;
    A = 0xD2;
    return;
}

void f_430B(void)
{
    DPTR = 0x8847;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
}

void f_4312(void)
{
    C = 1;
    DPTR = 0x8959;
    A = XD(DPTR);
    SUBB8(0xB9);
    DPTR = 0x8958;
    A = XD(DPTR);
    SUBB8(0x0F);
    DPTR = 0x8846;
    A = XD(DPTR);
    return;
}

void f_4324(void)
{
    DPTR = 0x8380;
}

void f_4327(void)
{
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    C = 1;
}

void f_432B(void)
{
    A = XD(DPTR);
    SUBB8(0x03);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_4333(void)
{
    A = 0;
    DPTR = 0x83A0;
    XD(DPTR) = A;
    DPTR = 0x8395;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
}

void f_433F(void)
{
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    return;
}

void f_4348(void)
{
    DPTR = 0x8397;
    A = XD(DPTR);
    RB(3) = A;
    A = 0;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    return;
}

void f_4353(void)
{
    XD(DPTR) = A;
    A = 0x02;
}

void f_4356(void)
{
    DPTR = 0x837B;
    XD(DPTR) = A;
    DPTR = 0x89CD;
    A = 0x80;
    XD(DPTR) = A;
    DPTR = 0x89CE;
    return;
}

void f_4364(void)
{
    A = 0;
    DPTR = 0x8386;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8381;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
}

void f_4371(void)
{
    A = XD(DPTR);
    C = 1;
    SUBB8(0x3C);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_437A(void)
{
    tmp = A; A = RB(4); RB(4) = tmp;
    tmp = A; A = RB(5); RB(5) = tmp;
    A = 0x01;
    tmp = A; A = RB(5); RB(5) = tmp;
    RB(3) = 0xFF;
    RB(6) = 0x00;
    RB(7) = 0x02;
    f_7712();
    return;
}

void f_4388(void)
{
    DPTR = 0x0694;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    return;
}

void f_438F(void)
{
    DPTR = 0x8386;
    A = 0;
    B = 0x01;
    f_77E5();
    DPTR = 0x8386;
    return;
}

void f_439D(void)
{
    XD(DPTR) = A;
    DPTR = 0x8392;
    A = XD(DPTR);
    A |= 0x04;
}

void f_43A4(void)
{
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8380;
    XD(DPTR) = A;
    return;
}

void f_43AB(void)
{
    DPTR = 0x8392;
    A = XD(DPTR);
    A &= 0x02;
    return;
}

void f_43B2(void)
{
    DPTR = 0x0693;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    return;
}

void f_43B9(void)
{
    DPTR = 0x890C;
    A = XD(DPTR);
    DPTR = 0x846E;
    XD(DPTR) = A;
    DPTR = 0x890D;
    A = XD(DPTR);
    DPTR = 0x846F;
    XD(DPTR) = A;
    return;
}

void f_43D2(void)
{
    DPTR = 0x069D;
    A = 0x15;
    XD(DPTR) = A;
    RB(6) = 0x83;
    DPTR++;
    A = 0x83;
    XD(DPTR) = A;
    DPTR++;
    A = 0x7E;
    return;
}

void f_43E2(void)
{
    DPTR = 0x837A;
    A = 0x80;
    XD(DPTR) = A;
    DPTR = 0x837B;
    return;
}

void f_43EC(void)
{
    DPTR = 0x848E;
    A = XD(DPTR);
    SUBB8(0x00);
    return;
}

void f_43F3(void)
{
    DPTR = 0x83C0;
    A = XD(DPTR);
    A &= 0x20;
    return;
}

void f_43FA(void)
{
    DPTR = 0x069D;
    A = 0x3F;
    XD(DPTR) = A;
    RB(6) = 0x83;
    DPTR++;
    A = 0x83;
    XD(DPTR) = A;
    DPTR++;
    A = 0x7A;
    return;
}

void f_440A(void)
{
    DPTR = 0x069D;
    A = 0x16;
    XD(DPTR) = A;
    RB(6) = 0x89;
    DPTR++;
    A = 0x89;
    XD(DPTR) = A;
    DPTR++;
    A = 0xCD;
    return;
}

void f_441A(void)
{
    DPTR = 0x069D;
    A = 0x17;
    XD(DPTR) = A;
    RB(6) = 0x89;
    DPTR++;
    A = 0x89;
    XD(DPTR) = A;
    DPTR++;
    A = 0xD0;
    return;
}

void f_4436(void)
{
    A = 0;
    DPTR = 0x89CD;
    XD(DPTR) = A;
    DPTR = 0x89CE;
    return;
}

void f_4440(void)
{
    A = 0;
    DPTR = 0x89D0;
    XD(DPTR) = A;
    DPTR = 0x89D1;
    return;
}

void f_4449(void)
{
    DPTR = 0x847C;
    A = XD(DPTR);
    C = 1;
}

void f_444E(void)
{
    SUBB8(0x1E);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_4473(void)
{
    A = 0;
    DPTR = 0x837C;
    XD(DPTR) = A;
    DPTR = 0x837D;
    return;
}

void f_447C(void)
{
    DPTR = 0x8393;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    DPTR = 0x8392;
    A = XD(DPTR);
    A |= 0x10;
    return;
}

void f_448A(void)
{
    A = XD(DPTR);
    C = 0;
    SUBB8(0x05);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_449C(void)
{
    DPTR = 0x069D;
    A = 0x14;
    XD(DPTR) = A;
    RB(6) = 0x83;
    DPTR++;
    A = 0x83;
    XD(DPTR) = A;
    return;
}

void f_44A9(void)
{
    DPTR = 0x8952;
    A = XD(DPTR);
    DPTR = 0x8486;
    XD(DPTR) = A;
    DPTR = 0x8953;
    A = XD(DPTR);
    return;
}

void f_44B6(void)
{
    A = 0;
    DPTR = 0x069D;
    XD(DPTR) = A;
    RB(6) = 0x06;
    DPTR++;
    A = 0x06;
    XD(DPTR) = A;
    return;
}

void f_44C2(void)
{
    DPTR = 0x8916;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x0F);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_44CE(void)
{
    DPTR = 0x8392;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    return;
}

void f_44D6(void)
{
    A = 0;
    DPTR = 0x837A;
    XD(DPTR) = A;
    DPTR = 0x837B;
    A = 0x0B;
    return;
}

void f_44E2(void)
{
    DPTR = 0x89A7;
    A = 0x08;
    XD(DPTR) = A;
    return;
}

void f_44E9(void)
{
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    C = 1;
    SUBB8(0x08);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_44F4(void)
{
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    f_7790();
    A = RB(5);
    A |= RB(4);
    return;
}

void f_44FF(void)
{
    DPTR = 0x83B2;
    A = XD(DPTR);
    A &= 0x04;
    return;
}

void f_4506(void)
{
    DPTR = 0x06B2;
    XD(DPTR) = A;
    RB(3) = A;
    RB(5) = 0x09;
    RB(7) = 0x84;
    return;
}

void f_4510(void)
{
    DPTR = 0x8386;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    return;
}

void f_4517(void)
{
    DPTR = 0x8914;
    A = XD(DPTR);
    A &= 0x20;
    return;
}

void f_451E(void)
{
    ADD8(0x00);
    DIR(0x6C) = A;
    A = RB(4);
    ADDC8(RB(6));
    DIR(0x6B) = A;
    C = 1;
    return;
}

void f_4528(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    return;
}

void f_452F(void)
{
    DPTR = 0x8394;
    A = XD(DPTR);
    A &= 0x08;
    return;
}

void f_4536(void)
{
    A = 0;
    DPTR = 0x8853;
    XD(DPTR) = A;
    DPTR = 0x8846;
    A = XD(DPTR);
    return;
}

void f_4821(void)
{
    DIR(0x74) &= 0xEE;
    XD(DPTR) = A;
    return;
}

void f_50B9(void)
{
    DPTR = 0x0694;
    A = RB(7);
    XD(DPTR) = A;
    if (A != 0x0A) { C = (A < 0x0A); goto L_50C1; }
    L_50C1:
    if (C == 0) goto L_513F;
    DPTR = 0x50CA;
    RB(0) = A;
    ADD8(RB(0));
    ADD8(RB(0));
    ec_jump((unsigned int)DPTR + A);
    return;
    L_513F:
    A = 0;
    DPTR = 0x0695;
    XD(DPTR) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x91);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(5) = A;
    RB(0) = 0xB7;
    A = RB(4);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(5);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x94);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(0) = 0xB9;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(1) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x93);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPL = RB(5);
    DPH = RB(4);
    A = XD(DPTR);
    A &= RB(7);
    if (A == 0) goto L_51A4;
    RB(7) = 0x01;
    goto L_51A6;
    L_51A6:
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(6) = A;
    A ^= RB(7);
    if (A != 0) goto L_51B1;
    f_5264();
    return;
    L_51B1:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(5) = A;
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    if (A != 0) goto L_51D7;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x96);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    DPL = RB(5);
    DPH = RB(4);
    XD(DPTR) = A;
    f_5270();
    return;
    L_51D7:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A == 0) goto L_51EA;
    f_5270();
    return;
    L_51EA:
    A = RB(6);
    if (A == 0) goto L_5224;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x97);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    goto L_525D;
    L_525D:
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_5270();
    return;
    L_5224:
    DPTR = 0x0694;
    A = XD(DPTR);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x99);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    A = ~A;
    RB(6) = A;
    A = RB(7);
    A &= RB(6);
    L_51A4:
    RB(7) = 0x00;
}

void f_50E8(void)
{
    DPTR = 0x1602;
    A = XD(DPTR);
    A &= 0x08;
    if (A != 0) goto L_50F4;
    RB(7) = 0x01;
    goto L_5136;
    L_5136:
    DPTR = 0x0695;
    A = RB(7);
    XD(DPTR) = A;
    goto L_5144;
    L_5144:
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x91);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(5) = A;
    RB(0) = 0xB7;
    A = RB(4);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(5);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x94);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(0) = 0xB9;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(1) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x93);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPL = RB(5);
    DPH = RB(4);
    A = XD(DPTR);
    A &= RB(7);
    if (A == 0) goto L_51A4;
    RB(7) = 0x01;
    goto L_51A6;
    L_51A6:
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(6) = A;
    A ^= RB(7);
    if (A != 0) goto L_51B1;
    f_5264();
    return;
    L_51B1:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(5) = A;
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    if (A != 0) goto L_51D7;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x96);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    DPL = RB(5);
    DPH = RB(4);
    XD(DPTR) = A;
    f_5270();
    return;
    L_51D7:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A == 0) goto L_51EA;
    f_5270();
    return;
    L_51EA:
    A = RB(6);
    if (A == 0) goto L_5224;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x97);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    goto L_525D;
    L_525D:
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_5270();
    return;
    L_5224:
    DPTR = 0x0694;
    A = XD(DPTR);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x99);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    A = ~A;
    RB(6) = A;
    A = RB(7);
    A &= RB(6);
    L_51A4:
    RB(7) = 0x00;
    L_50F4:
    RB(7) = 0x00;
    goto L_5136;
}

void f_50F8(void)
{
    DPTR = 0x1602;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_5104;
    RB(7) = 0x01;
    goto L_5106;
    L_5106:
    goto L_5136;
    L_5136:
    DPTR = 0x0695;
    A = RB(7);
    XD(DPTR) = A;
    goto L_5144;
    L_5144:
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x91);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(5) = A;
    RB(0) = 0xB7;
    A = RB(4);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(5);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x94);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(0) = 0xB9;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(1) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x93);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPL = RB(5);
    DPH = RB(4);
    A = XD(DPTR);
    A &= RB(7);
    if (A == 0) goto L_51A4;
    RB(7) = 0x01;
    goto L_51A6;
    L_51A6:
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(6) = A;
    A ^= RB(7);
    if (A != 0) goto L_51B1;
    f_5264();
    return;
    L_51B1:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(5) = A;
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    if (A != 0) goto L_51D7;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x96);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    DPL = RB(5);
    DPH = RB(4);
    XD(DPTR) = A;
    f_5270();
    return;
    L_51D7:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A == 0) goto L_51EA;
    f_5270();
    return;
    L_51EA:
    A = RB(6);
    if (A == 0) goto L_5224;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x97);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    goto L_525D;
    L_525D:
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_5270();
    return;
    L_5224:
    DPTR = 0x0694;
    A = XD(DPTR);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x99);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    A = ~A;
    RB(6) = A;
    A = RB(7);
    A &= RB(6);
    L_51A4:
    RB(7) = 0x00;
    L_5104:
    RB(7) = 0x00;
}

void f_5108(void)
{
    DPTR = 0x1609;
    A = XD(DPTR);
    A &= 0x04;
    if (A != 0) goto L_5114;
    RB(7) = 0x01;
    goto L_5116;
    L_5116:
    goto L_5136;
    L_5136:
    DPTR = 0x0695;
    A = RB(7);
    XD(DPTR) = A;
    goto L_5144;
    L_5144:
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x91);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(5) = A;
    RB(0) = 0xB7;
    A = RB(4);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(5);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x94);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(0) = 0xB9;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(1) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x93);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPL = RB(5);
    DPH = RB(4);
    A = XD(DPTR);
    A &= RB(7);
    if (A == 0) goto L_51A4;
    RB(7) = 0x01;
    goto L_51A6;
    L_51A6:
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(6) = A;
    A ^= RB(7);
    if (A != 0) goto L_51B1;
    f_5264();
    return;
    L_51B1:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(5) = A;
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    if (A != 0) goto L_51D7;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x96);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    DPL = RB(5);
    DPH = RB(4);
    XD(DPTR) = A;
    f_5270();
    return;
    L_51D7:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A == 0) goto L_51EA;
    f_5270();
    return;
    L_51EA:
    A = RB(6);
    if (A == 0) goto L_5224;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x97);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    goto L_525D;
    L_525D:
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_5270();
    return;
    L_5224:
    DPTR = 0x0694;
    A = XD(DPTR);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x99);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    A = ~A;
    RB(6) = A;
    A = RB(7);
    A &= RB(6);
    L_51A4:
    RB(7) = 0x00;
    L_5114:
    RB(7) = 0x00;
}

void f_5118(void)
{
    DPTR = 0x1602;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_5124;
    RB(7) = 0x01;
    goto L_5126;
    L_5126:
    goto L_5136;
    L_5136:
    DPTR = 0x0695;
    A = RB(7);
    XD(DPTR) = A;
    goto L_5144;
    L_5144:
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x91);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(5) = A;
    RB(0) = 0xB7;
    A = RB(4);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(5);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x94);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(0) = 0xB9;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(1) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x93);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPL = RB(5);
    DPH = RB(4);
    A = XD(DPTR);
    A &= RB(7);
    if (A == 0) goto L_51A4;
    RB(7) = 0x01;
    goto L_51A6;
    L_51A6:
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(6) = A;
    A ^= RB(7);
    if (A != 0) goto L_51B1;
    f_5264();
    return;
    L_51B1:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(5) = A;
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    if (A != 0) goto L_51D7;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x96);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    DPL = RB(5);
    DPH = RB(4);
    XD(DPTR) = A;
    f_5270();
    return;
    L_51D7:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A == 0) goto L_51EA;
    f_5270();
    return;
    L_51EA:
    A = RB(6);
    if (A == 0) goto L_5224;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x97);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    goto L_525D;
    L_525D:
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_5270();
    return;
    L_5224:
    DPTR = 0x0694;
    A = XD(DPTR);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x99);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    A = ~A;
    RB(6) = A;
    A = RB(7);
    A &= RB(6);
    L_51A4:
    RB(7) = 0x00;
    L_5124:
    RB(7) = 0x00;
}

void f_5128(void)
{
    DPTR = 0x1604;
    A = XD(DPTR);
    A &= 0x10;
    if (A != 0) goto L_5134;
    RB(7) = 0x01;
    goto L_5136;
    L_5136:
    DPTR = 0x0695;
    A = RB(7);
    XD(DPTR) = A;
    goto L_5144;
    L_5144:
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x91);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(5) = A;
    RB(0) = 0xB7;
    A = RB(4);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(5);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x94);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(0) = 0xB9;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(1) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x93);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPL = RB(5);
    DPH = RB(4);
    A = XD(DPTR);
    A &= RB(7);
    if (A == 0) goto L_51A4;
    RB(7) = 0x01;
    goto L_51A6;
    L_51A6:
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(6) = A;
    A ^= RB(7);
    if (A != 0) goto L_51B1;
    f_5264();
    return;
    L_51B1:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(5) = A;
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    if (A != 0) goto L_51D7;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x96);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    DPL = RB(5);
    DPH = RB(4);
    XD(DPTR) = A;
    f_5270();
    return;
    L_51D7:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A == 0) goto L_51EA;
    f_5270();
    return;
    L_51EA:
    A = RB(6);
    if (A == 0) goto L_5224;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x97);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    goto L_525D;
    L_525D:
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_5270();
    return;
    L_5224:
    DPTR = 0x0694;
    A = XD(DPTR);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x99);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    A = ~A;
    RB(6) = A;
    A = RB(7);
    A &= RB(6);
    L_51A4:
    RB(7) = 0x00;
    L_5134:
    RB(7) = 0x00;
}

void f_513D(void)
{
    goto L_513F;
    L_513F:
    A = 0;
    DPTR = 0x0695;
    XD(DPTR) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x91);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(5) = A;
    RB(0) = 0xB7;
    A = RB(4);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(5);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x94);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(0) = 0xB9;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(1) = A;
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x93);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPL = RB(5);
    DPH = RB(4);
    A = XD(DPTR);
    A &= RB(7);
    if (A == 0) goto L_51A4;
    RB(7) = 0x01;
    goto L_51A6;
    L_51A6:
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(6) = A;
    A ^= RB(7);
    if (A != 0) goto L_51B1;
    f_5264();
    return;
    L_51B1:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(5) = A;
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    if (A != 0) goto L_51D7;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x96);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    DPL = RB(5);
    DPH = RB(4);
    XD(DPTR) = A;
    f_5270();
    return;
    L_51D7:
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(4);
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A == 0) goto L_51EA;
    f_5270();
    return;
    L_51EA:
    A = RB(6);
    if (A == 0) goto L_5224;
    A = RB(1);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x97);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    goto L_525D;
    L_525D:
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_5270();
    return;
    L_5224:
    DPTR = 0x0694;
    A = XD(DPTR);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x99);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    A = ~A;
    RB(6) = A;
    A = RB(7);
    A &= RB(6);
    L_51A4:
    RB(7) = 0x00;
}

void f_5264(void)
{
    RB(0) = 0xB9;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(6) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPL = A;
    DPH = RB(6);
    A = 0;
    XD(DPTR) = A;
}

void f_5270(void)
{
    DPTR = 0x0694;
    A = XD(DPTR);
    B = 0x0C;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x9B);
    DPL = A;
    A = 0;
    ADDC8(0x52);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(7) = A;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    f_7A70();
    return;
}

void f_5340(void)
{
    DPTR = 0x1904;
    A = 0x1F;
    XD(DPTR) = A;
    DPTR = 0x190C;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8C00;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8C02;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8C04;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8C06;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8C08;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8C0A;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8C0C;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8C0E;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x1901;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    return;
}

void f_5387(void)
{
    DPTR = 0x1904;
    A = XD(DPTR);
    A &= 0x80;
    if (A == 0) goto L_53A2;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    DPTR = 0x1919;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x1918;
    A = XD(DPTR);
    DPTR = 0x8C00;
    f_54C4();
    L_53A2:
    DPTR = 0x190C;
    A = XD(DPTR);
    A &= 0x80;
    if (A == 0) goto L_53BD;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    DPTR = 0x190E;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x190D;
    A = XD(DPTR);
    DPTR = 0x8C06;
    f_54C4();
    L_53BD:
    return;
}

void f_53BE(void)
{
    DPTR = 0x1900;
    A = XD(DPTR);
    A |= 0x08;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    DPTR = 0x1901;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    DPTR = 0x1900;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    DPTR = 0x1902;
    A = 0x63;
    XD(DPTR) = A;
    DPTR = 0x1901;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    f_54A4();
    return;
}

void f_53F4(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    if (A != 0) goto L_5443;
    DPTR = 0x89B9;
    f_54D0();
    if (C == 0) goto L_5415;
    DPTR = 0x8C00;
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x89B5;
    A = RB(6);
    B = RB(7);
    f_77E5();
    return;
    L_5415:
    A = 0;
    DPTR = 0x89B9;
    XD(DPTR) = A;
    DPTR = 0x89B5;
    f_54B8();
    DPTR = 0x89B7;
    A = RB(6);
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    f_54DC();
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    RB(4) = 0x00;
    RB(5) = 0x4B;
    f_777E();
    RB(0) = 0x07;
    A = RB(7);
    L_543A:
    tmp = A; A = RB(6); RB(6) = tmp;
    C = 0;
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    tmp = A; A = RB(6); RB(6) = tmp;
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    if (--RB(0)) goto L_543A;
    goto L_544D;
    L_544D:
    DPTR = 0x89BB;
    XD(DPTR) = A;
    return;
    L_5443:
    f_54DC();
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x89B9;
    XD(DPTR) = A;
}

void f_5452(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    if (A != 0) goto L_548E;
    DPTR = 0x89C0;
    f_54D0();
    if (C == 0) goto L_5473;
    DPTR = 0x8C06;
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x89BC;
    A = RB(6);
    B = RB(7);
    f_77E5();
    return;
    L_5473:
    A = 0;
    DPTR = 0x89C0;
    XD(DPTR) = A;
    DPTR = 0x89BC;
    f_54B8();
    DPTR = 0x89BE;
    A = RB(6);
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x89BC;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    return;
    L_548E:
    A = 0;
    DPTR = 0x89BC;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x89BE;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x89C0;
    XD(DPTR) = A;
    DPTR = 0x89C1;
    XD(DPTR) = A;
    return;
}

void f_54A4(void)
{
    DPTR = 0x1904;
    A = 0x80;
    XD(DPTR) = A;
    DPTR = 0x190C;
    A = 0x83;
    XD(DPTR) = A;
    DPTR = 0x1901;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    return;
}

void f_54B8(void)
{
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    RB(4) = 0x00;
    RB(5) = 0x0A;
    f_7790();
    return;
}

void f_54C4(void)
{
    RB(4) = 0x00;
    ADD8(0x00);
    RB(7) = A;
    A = RB(4);
    ADDC8(RB(6));
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_54D0(void)
{
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x0A);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_54DC(void)
{
    A = 0;
    DPTR = 0x89B5;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x89B7;
    return;
}

void f_57EA(void)
{
    DPTR = 0x8313;
    A = XD(DPTR);
    if (A == 0) goto L_57FD;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A != 0) goto L_57FD;
    DPTR = 0x1606;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    L_57FD:
    return;
}

void f_57FE(void)
{
    DPTR = 0x83D8;
    A = XD(DPTR);
    A ^= 0x64;
    if (A == 0) goto L_5809;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    L_5809:
    return;
}

void f_5816(void)
{
    DPTR = 0x831C;
    A = XD(DPTR);
    if (A != 0) goto L_582A;
    DPTR = 0x1603;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    tmp = A; A = RB(7); RB(7) = tmp;
    tmp = A; A = RB(7); RB(7) = tmp;
    DPTR = 0x831C;
    A = RB(7);
    XD(DPTR) = A;
    L_582A:
    return;
}

void f_582B(void)
{
    DPTR = 0x831C;
    A = XD(DPTR);
    if (A == 0) goto L_583E;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A != 0) goto L_583E;
    DPTR = 0x1603;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    L_583E:
    return;
}

void f_583F(void)
{
    DPTR = 0x8318;
    A = XD(DPTR);
    if (A != 0) goto L_5853;
    DPTR = 0x1606;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    tmp = A; A = RB(7); RB(7) = tmp;
    tmp = A; A = RB(7); RB(7) = tmp;
    DPTR = 0x8318;
    A = RB(7);
    XD(DPTR) = A;
    L_5853:
    return;
}

void f_5854(void)
{
    DPTR = 0x8318;
    A = XD(DPTR);
    if (A == 0) goto L_5863;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A != 0) goto L_5863;
    f_6721();
    L_5863:
    return;
}

void f_5864(void)
{
    DPTR = 0x0082;
    A = XD(DPTR);
    A &= 0x03;
    A--;
    if (A == 0) goto L_5877;
    A--;
    if (A == 0) goto L_5880;
    A--;
    if (A == 0) goto L_588B;
    ADD8(0x03);
    if (A != 0) goto L_5897;
    L_5877:
    f_66D4();
    if (A != 0) goto L_5894;
    A = 0xFC;
    XD(DPTR) = A;
    return;
    L_5894:
    A = 0xEC;
    XD(DPTR) = A;
    L_5897:
    return;
    L_588B:
    f_66D4();
    if (A != 0) goto L_5894;
    A = 0xFD;
    XD(DPTR) = A;
    return;
    L_5880:
    f_66D4();
    if (A != 0) goto L_5889;
    A = 0xFE;
    XD(DPTR) = A;
    return;
    L_5889:
    goto L_5894;
}

void f_5C00(void)
{
    f_9081();
    return;
}

void f_5CF7(void)
{
    f_66C2();
    if (A == 0) goto L_5D13;
    DPTR = 0x8311;
    A = RB(7);
    XD(DPTR) = A;
    A = 0x50;
    f_6695();
    DPTR = 0x8311;
    f_6664();
    RB(5) = 0x02;
    RB(7) = 0x80;
    f_2CE7();
    L_5D13:
    return;
}

void f_5D14(void)
{
    f_66C2();
    if (A == 0) goto L_5D37;
    DPTR = 0x8311;
    A = RB(7);
    XD(DPTR) = A;
    A = 0x30;
    f_6695();
    DPTR = 0x83F2;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    DPTR = 0x8311;
    f_6664();
    RB(5) = 0x02;
    RB(7) = 0x80;
    f_2CE7();
    L_5D37:
    return;
}

void f_5D38(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x33;
    if (A == 0) goto L_5D51;
    DPTR = 0x8310;
    A = RB(7);
    XD(DPTR) = A;
    A = 0x03;
    f_6650();
    RB(5) = 0x01;
    RB(7) = 0x80;
    f_2CE7();
    L_5D51:
    return;
}

void f_5D52(void)
{
    f_66E5();
    if (A == 0) goto L_5D68;
    DPTR = 0x8310;
    A = RB(7);
    XD(DPTR) = A;
    A = 0x05;
    f_6650();
    RB(5) = 0x01;
    RB(7) = 0x80;
    f_2CE7();
    L_5D68:
    return;
}

void f_5D69(void)
{
    tmp = A; A = RB(3); RB(3) = tmp;
    A = RB(7);
    tmp = A; A = RB(3); RB(3) = tmp;
    f_66E5();
    if (A == 0) goto L_5D80;
    DPTR = 0x83F7;
    A = XD(DPTR);
    A |= 0x02;
    f_6709();
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(3);
    tmp = A; A = RB(7); RB(7) = tmp;
    f_5D52();
    L_5D80:
    return;
}

void f_5D81(void)
{
    f_66E5();
    if (A != 0) goto L_5D9A;
    RB(7) = 0xFF;
    f_2B52();
    DPTR = 0x83F7;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    DPTR = 0x8300;
    A = 0x06;
    f_6698();
    L_5D9A:
    return;
}

void f_6021(void)
{
    DPTR = 0x83F1;
    A = XD(DPTR);
    A &= 0x03;
    RB(7) = A;
    DPTR = 0x8312;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_6032;
    A = RB(7);
    XD(DPTR) = A;
    return;
    L_6032:
    DPTR = 0x83F1;
    A = XD(DPTR);
    A &= 0x03;
    ADD8(0xFE);
    if (A == 0) goto L_606E;
    A--;
    if (A == 0) goto L_6058;
    ADD8(0x03);
    if (A != 0) goto L_607B;
    DPTR = 0x8300;
    A = XD(DPTR);
    ADD8(0xCD);
    if (A == 0) goto L_6053;
    ADD8(0x23);
    if (A != 0) goto L_607B;
    RB(7) = 0x01;
    goto L_6055;
    L_6055:
    f_5D52();
    return;
    L_607B:
    return;
    L_6053:
    RB(7) = 0x02;
    L_6058:
    DPTR = 0x8300;
    A = XD(DPTR);
    ADD8(0xAB);
    if (A == 0) goto L_6069;
    ADD8(0x22);
    if (A != 0) goto L_607B;
    RB(7) = 0x21;
    f_5D14();
    return;
    L_6069:
    RB(7) = 0x01;
    f_5CF7();
    return;
    L_606E:
    DPTR = 0x8300;
    A = XD(DPTR);
    ADD8(0xF0);
    if (A != 0) goto L_607B;
    RB(7) = 0x03;
    f_5D38();
}

void f_607C(void)
{
    DPTR = 0x83F1;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    f_674C();
    if (A == 0) goto L_608F;
    DPTR = 0x83F1;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    L_608F:
    DPTR = 0x83F1;
    A = XD(DPTR);
    A &= 0xFD;
    f_6712();
    if (A == 0) goto L_60A1;
    DPTR = 0x83F1;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    L_60A1:
    f_6021();
    return;
}

void f_60A4(void)
{
    f_66E5();
    if (A != 0) goto L_6116;
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_60B6;
    f_671A();
    if (A == 0) goto L_6116;
    L_60B6:
    DPTR = 0x8307;
    A = XD(DPTR);
    RB(7) = A;
    C = 0;
    A = 0;
    SUBB8(RB(7));
    A = 0x80;
    RB(0) = A;
    SUBB8(RB(0));
    if (C != 0) goto L_6116;
    DPTR = 0x83C1;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_60D1;
    f_671A();
    if (A == 0) goto L_6116;
    L_60D1:
    DPTR = 0x83C0;
    A = XD(DPTR);
    A &= 0x20;
    if (A != 0) goto L_60EE;
    DPTR = 0x83BB;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_60EE;
    f_671A();
    if (A != 0) goto L_60EE;
    DPTR = 0x8310;
    A = XD(DPTR);
    A ^= 0x1F;
    if (A != 0) goto L_60F4;
    L_60EE:
    DPTR = 0x8314;
    A = 0x06;
    XD(DPTR) = A;
    L_60F4:
    DPTR = 0x8314;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x06);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_610B;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    A ^= 0x06;
    if (A != 0) goto L_6116;
    goto L_6113;
    L_6113:
    f_5D81();
    L_6116:
    return;
    L_610B:
    DPTR = 0x8314;
    A = XD(DPTR);
    A ^= 0x06;
    if (A != 0) goto L_6116;
}

void f_6117(void)
{
    DPTR = 0x8307;
    A = XD(DPTR);
    if (A == 0) goto L_6149;
    DPTR = 0x8315;
    A = XD(DPTR);
    if (A != 0) goto L_6125;
    DPTR++;
    A = XD(DPTR);
    L_6125:
    if (A != 0) goto L_6135;
    DPTR = 0x8307;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    DPTR = 0x8315;
    f_66CC();
    goto L_613B;
    L_613B:
    DPTR = 0x8307;
    A = XD(DPTR);
    if (A != 0) goto L_6149;
    f_66C9();
    RB(7) = 0x04;
    f_5CF7();
    L_6149:
    DPTR = 0x8308;
    A = XD(DPTR);
    if (A == 0) goto L_6157;
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x8300;
    A = 0xFF;
    XD(DPTR) = A;
    L_6157:
    return;
    L_6135:
    DPTR = 0x8315;
    f_6745();
}

void f_61A3(void)
{
    DPTR = 0x1604;
    A = XD(DPTR);
    A &= 0x04;
    if (A == 0) goto L_61D4;
    DPTR = 0x8108;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x33);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_61FA;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    ADD8(0xEC);
    if (A == 0) goto L_61CC;
    ADD8(0x0A);
    if (A != 0) goto L_61FA;
    DPTR = 0x1D01;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    return;
    L_61FA:
    return;
    L_61CC:
    DPTR = 0x1607;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    return;
    L_61D4:
    DPTR = 0x8108;
    A = XD(DPTR);
    if (A == 0) goto L_61FA;
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x1607;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    DPTR = 0x1D01;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    DPTR = 0x83F7;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xEF;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8109;
    XD(DPTR) = A;
}

void f_61FB(void)
{
    f_61A3();
    DPTR = 0x8303;
    A = XD(DPTR);
    if (A != 0) goto L_6206;
    DPTR++;
    A = XD(DPTR);
    L_6206:
    if (A == 0) goto L_6218;
    DPTR = 0x8303;
    f_6745();
    DPTR = 0x8303;
    A = XD(DPTR);
    if (A != 0) goto L_6216;
    DPTR++;
    A = XD(DPTR);
    L_6216:
    if (A != 0) goto L_6274;
    L_6218:
    f_66C2();
    if (A == 0) goto L_6227;
    A = XD(DPTR);
    A ^= 0x33;
    if (A == 0) goto L_6227;
    A = XD(DPTR);
    A ^= 0x55;
    if (A != 0) goto L_622A;
    L_6227:
    f_607C();
    L_622A:
    DPTR = 0x8300;
    A = XD(DPTR);
    f_7A4A();
    DIR(0x65) ^= A;
    A = (A >> 1) | (A << 7);
    DIR(0x68) ^= A;
    DIR(0x62)++;
    A ^= RB(3);
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    DIR(0x74) ^= A;
    if (BIT_RAM(0x62)) { BIT_SET(0x62, 0); goto L_62A1; }
    if (!BIT_RAM(0x62)) goto L_62B6;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    DIR(0x5F) ^= A;
    if (C == 0) goto L_62A9;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= DIR(0x62);
    A &= RB(4);
    if (A == 0) goto L_62AF;
    A &= RB(1);
    A ^= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DIR(0x6E) ^= A;
    RB(7) = A;
    DIR(0x71) ^= A;
    f_6117();
    return;
    L_62AF:
    RB(5)--;
    A = 0x02;
    XD(DPTR) = A;
    L_62B3:
    return;
    L_62A9:
    RB(1)++;
    f_5D81();
    DPTR = 0x831D;
    L_62B6:
    BIT_SET(0x70, 0);
    ADDC8(RB(4));
    DPTR = 0x160A;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_62FA;
    DPTR = 0x8897;
    A = XD(DPTR);
    if (A != 0) goto L_62FA;
    A++;
    XD(DPTR) = A;
    A = 0;
    RB(5) = A;
    RB(7) = 0xD5;
    f_2CEC();
    A = 0;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    RB(3) = 0x01;
    RB(5) = 0x05;
    RB(7) = 0x82;
    f_2CE7();
    DPTR = 0x841D;
    f_6664();
    RB(5) = 0x06;
    RB(7) = 0x85;
    f_2CE7();
    RB(7) = 0xAA;
    f_2B52();
    RB(7) = 0x30;
    f_2B52();
    return;
    L_62FA:
    return;
    L_62A1:
    EC_UNSUPPORTED();
    DPTR = 0x831D;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_62B3;
    L_6274:
    return;
}

void f_6275(void)
{
    f_66C2();
    if (A != 0) goto L_629D;
    DPTR = 0x160A;
    A = XD(DPTR);
    A &= 0x80;
    if (A != 0) goto L_629D;
    DPTR = 0x2278;
    A = 0xA5;
    XD(DPTR) = A;
    RB(7) = 0x11;
    f_5D69();
    DPTR = 0x831D;
    A = 0x01;
    XD(DPTR) = A;
    f_66DE();
    if (A == 0) goto L_629D;
    RB(7) = 0x66;
    f_2B52();
    L_629D:
    f_66E5();
    if (A != 0) goto L_62B3;
    DPTR = 0x831D;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_62B3;
    f_5D81();
    DPTR = 0x831D;
    A = 0x02;
    XD(DPTR) = A;
    L_62B3:
    return;
}

void f_62B4(void)
{
    f_66C2();
    if (A != 0) goto L_62F5;
    DPTR = 0x160A;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_62FA;
    DPTR = 0x8897;
    A = XD(DPTR);
    if (A != 0) goto L_62FA;
    A++;
    XD(DPTR) = A;
    A = 0;
    RB(5) = A;
    RB(7) = 0xD5;
    f_2CEC();
    A = 0;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    RB(3) = 0x01;
    RB(5) = 0x05;
    RB(7) = 0x82;
    f_2CE7();
    DPTR = 0x841D;
    f_6664();
    RB(5) = 0x06;
    RB(7) = 0x85;
    f_2CE7();
    RB(7) = 0xAA;
    f_2B52();
    RB(7) = 0x30;
    f_2B52();
    return;
    L_62FA:
    return;
    L_62F5:
    A = 0;
    DPTR = 0x8897;
    XD(DPTR) = A;
}

void f_62FB(void)
{
    DPTR = 0x8418;
    f_6664();
    RB(5) = 0x01;
    RB(7) = 0x85;
    f_2CE7();
    DPTR = 0x8419;
    f_6664();
    RB(5) = 0x02;
    RB(7) = 0x85;
    f_2CE7();
    DPTR = 0x841A;
    f_6664();
    RB(5) = 0x03;
    RB(7) = 0x85;
    f_2CE7();
    DPTR = 0x841B;
    f_6664();
    RB(5) = 0x04;
    RB(7) = 0x85;
    f_2CE7();
    DPTR = 0x841C;
    f_6664();
    RB(5) = 0x05;
    RB(7) = 0x85;
    f_2CE7();
    DPTR = 0x841D;
    f_6664();
    RB(5) = 0x06;
    RB(7) = 0x85;
    f_2CE7();
    DPTR = 0x841E;
    f_6664();
    RB(5) = 0x07;
    RB(7) = 0x85;
    f_2CE7();
    DPTR = 0x8397;
    f_6664();
    RB(5) = 0x08;
    RB(7) = 0x85;
    f_2CE7();
    return;
}

void f_63BD(void)
{
    DPTR = 0x1144;
    A = 0x02;
    XD(DPTR) = A;
    DPTR = 0x1145;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    DPTR = 0x1B31;
    A = 0x02;
    XD(DPTR) = A;
    return;
}

void f_6650(void)
{
    DPTR = 0x8300;
    XD(DPTR) = A;
    DPTR = 0x8301;
    A = 0x01;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8305;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8310;
}

void f_6664(void)
{
    A = XD(DPTR);
    RB(3) = A;
    A = 0;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    return;
}

void f_6695(void)
{
    DPTR = 0x8300;
}

void f_6698(void)
{
    XD(DPTR) = A;
    DPTR = 0x8301;
    A = 0x01;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8305;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    return;
}

void f_66C2(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    return;
}

void f_66C9(void)
{
    DPTR = 0x8303;
}

void f_66CC(void)
{
    A = 0x03;
    XD(DPTR) = A;
    DPTR++;
    A = 0xE8;
    XD(DPTR) = A;
    return;
}

void f_66D4(void)
{
    DPTR = 0x1610;
    A = XD(DPTR);
    A ^= 0x84;
    DPTR = 0x8310;
    return;
}

void f_66DE(void)
{
    DPTR = 0x83B2;
    A = XD(DPTR);
    A &= 0x01;
    return;
}

void f_66E5(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x55;
    return;
}

void f_6709(void)
{
    XD(DPTR) = A;
    DPTR = 0x160A;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    return;
}

void f_6712(void)
{
    XD(DPTR) = A;
    DPTR = 0x1603;
    A = XD(DPTR);
    A &= 0x40;
    return;
}

void f_671A(void)
{
    DPTR = 0x83F7;
    A = XD(DPTR);
    A &= 0x02;
    return;
}

void f_6721(void)
{
    DPTR = 0x1606;
    A = XD(DPTR);
    A &= 0xEF;
    XD(DPTR) = A;
    return;
}

void f_6731(void)
{
    DPTR = 0x83F3;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    return;
}

void f_6745(void)
{
    A = 0xFF;
    B = A;
    f_77E5();
    return;
}

void f_674C(void)
{
    DPTR = 0x160A;
    A = XD(DPTR);
    A &= 0x02;
    return;
}

void f_765E(void)
{
    L_765E:
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    RB(1)++;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    if (--RB(7)) goto L_765E;
    goto L_76DE;
    L_76DE:
    A = RB(4);
    RB(2) = A;
    RB(1) = B;
    A = RB(5);
    RB(3) = A;
    return;
}

void f_7666(void)
{
    L_7666:
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    RB(1)++;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    if (--RB(7)) goto L_7666;
    goto L_76DE;
    L_76DE:
    A = RB(4);
    RB(2) = A;
    RB(1) = B;
    A = RB(5);
    RB(3) = A;
    return;
}

void f_766E(void)
{
    DPL = RB(0);
    DPH = RB(4);
    L_7672:
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    RB(1)++;
    XD(DPTR) = A;
    DPTR++;
    if (--RB(7)) goto L_7672;
    goto L_76DE;
    L_76DE:
    A = RB(4);
    RB(2) = A;
    RB(1) = B;
    A = RB(5);
    RB(3) = A;
    return;
}

void f_7690(void)
{
    goto L_76DE;
    L_76DE:
    A = RB(4);
    RB(2) = A;
    RB(1) = B;
    A = RB(5);
    RB(3) = A;
    return;
}

void f_7705(void)
{
    DPL = RB(1);
    DPH = RB(2);
    L_7709:
    A = 0;
    A = CD(DPTR + A);
    DPTR++;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    if (--RB(7)) goto L_7709;
    goto L_76DE;
    L_76DE:
    A = RB(4);
    RB(2) = A;
    RB(1) = B;
    A = RB(5);
    RB(3) = A;
    return;
}

void f_7712(void)
{
    B = RB(0);
    A = RB(7);
    if (A == 0) goto L_7718;
    RB(6)++;
    L_7718:
    A |= RB(6);
    if (A == 0) goto L_76DE;
    B = RB(0);
    A = RB(5);
    ADD8(0x02);
    if (A != 0x04) { C = (A < 0x04); goto L_7723; }
    L_7723:
    if (C == 0) goto L_76DE;
    DPL = A;
    A = RB(3);
    ADD8(0x02);
    if (A != 0x04) { C = (A < 0x04); goto L_772D; }
    L_772D:
    if (C == 0) goto L_76DE;
    A = (A << 1) | (A >> 7);
    A = (A << 1) | (A >> 7);
    A |= DPL;
    A = (A << 1) | (A >> 7);
    DPTR = 0x7692;
    ec_jump((unsigned int)DPTR + A);
    return;
    L_76DE:
    A = RB(4);
    RB(2) = A;
    RB(1) = B;
    A = RB(5);
    RB(3) = A;
    return;
}

void f_7738(void)
{
    if (RB(3) != 0x01) { C = (RB(3) < 0x01); goto L_7741; }
    DPL = RB(1);
    DPH = RB(2);
    A = XD(DPTR);
    return;
    L_7741:
    if (C == 0) goto L_7745;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    return;
    L_7745:
    if (RB(3) != 0xFE) { C = (RB(3) < 0xFE); goto L_774A; }
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    return;
    L_774A:
    DPL = RB(1);
    DPH = RB(2);
    A = 0;
    A = CD(DPTR + A);
    return;
}

void f_7751(void)
{
    if (RB(3) != 0x01) { C = (RB(3) < 0x01); goto L_7760; }
    A = DPL;
    ADD8(RB(1));
    DPL = A;
    A = DPH;
    ADDC8(RB(2));
    DPH = A;
    A = XD(DPTR);
    return;
    L_7760:
    if (C == 0) goto L_7768;
    A = RB(1);
    ADD8((DPL));
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    return;
    L_7768:
    if (RB(3) != 0xFE) { C = (RB(3) < 0xFE); goto L_7771; }
    A = RB(1);
    ADD8((DPL));
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    return;
    L_7771:
    A = DPL;
    ADD8(RB(1));
    DPL = A;
    A = DPH;
    ADDC8(RB(2));
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    return;
}

void f_777E(void)
{
    A = RB(7);
    B = RB(5);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    RB(0) = B;
    tmp = A; A = RB(7); RB(7) = tmp;
    B = RB(4);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(RB(0));
    tmp = A; A = RB(6); RB(6) = tmp;
    B = RB(5);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(RB(6));
    RB(6) = A;
    return;
}

void f_7790(void)
{
    if (RB(4) != 0x00) { C = (RB(4) < 0x00); goto L_779E; }
    if (RB(6) != 0x00) { C = (RB(6) < 0x00); goto L_77BF; }
    A = RB(7);
    B = RB(5);
    if (B == 0) { C = 0; } else { tmp = A % B; A = A / B; B = tmp; C = 0; }
    RB(7) = A;
    RB(5) = B;
    return;
    L_77BF:
    A = RB(5);
    RB(0) = A;
    B = A;
    A = RB(6);
    if (B == 0) { C = 0; } else { tmp = A % B; A = A / B; B = tmp; C = 0; }
    if (((PSW >> 2) & 1)) goto L_77E4;
    RB(6) = A;
    RB(5) = B;
    B = 0x08;
    L_77CE:
    A = RB(7);
    ADD8(RB(7));
    RB(7) = A;
    A = RB(5);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(5) = A;
    if (C != 0) goto L_77DD;
    SUBB8(RB(0));
    if (C == 0) goto L_77DF;
    if (--B) goto L_77CE;
    return;
    L_77DF:
    RB(5) = A;
    RB(7)++;
    if (--B) goto L_77CE;
    L_77E4:
    return;
    L_77DD:
    C = 0;
    SUBB8(RB(0));
    L_779E:
    A = 0;
    tmp = A; A = RB(4); RB(4) = tmp;
    RB(0) = A;
    B = 0x08;
    L_77A4:
    A = RB(7);
    ADD8(RB(7));
    RB(7) = A;
    A = RB(6);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(6) = A;
    A = RB(4);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(4) = A;
    A = RB(6);
    SUBB8(RB(5));
    A = RB(4);
    SUBB8(RB(0));
    if (C != 0) goto L_77B8;
    RB(4) = A;
    A = RB(6);
    SUBB8(RB(5));
    RB(6) = A;
    RB(7)++;
    L_77B8:
    if (--B) goto L_77A4;
    A = 0;
    tmp = A; A = RB(6); RB(6) = tmp;
    RB(5) = A;
    return;
}

void f_77E5(void)
{
    tmp = A; A = B; B = tmp;
    RB(0) = A;
    DPTR++;
    A = XD(DPTR);
    ADD8(RB(0));
    XD(DPTR) = A;
    tmp = A; A = B; B = tmp;
    RB(0) = A;
    A = DPL;
    DPL--;
    if (A != 0) goto L_77F7;
    DPH--;
    L_77F7:
    A = XD(DPTR);
    ADDC8(RB(0));
    XD(DPTR) = A;
    return;
}

void f_7808(void)
{
    A = RB(0);
    B = RB(7);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    tmp = A; A = RB(4); RB(4) = tmp;
    B = RB(3);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(RB(4));
    RB(4) = A;
    A = RB(1);
    B = RB(6);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(RB(4));
    RB(4) = A;
    B = RB(2);
    A = RB(5);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(RB(4));
    RB(4) = A;
    A = RB(2);
    B = RB(6);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    tmp = A; A = RB(5); RB(5) = tmp;
    RB(0) = B;
    B = RB(3);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(RB(5));
    tmp = A; A = RB(4); RB(4) = tmp;
    ADDC8(RB(0));
    ADD8((B));
    RB(5) = A;
    A = RB(1);
    B = RB(7);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(RB(4));
    tmp = A; A = RB(5); RB(5) = tmp;
    ADDC8((B));
    RB(4) = A;
    A = RB(3);
    B = RB(6);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    RB(6) = A;
    RB(1) = B;
    A = RB(3);
    B = RB(7);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    tmp = A; A = RB(7); RB(7) = tmp;
    tmp = A; A = B; B = tmp;
    ADD8(RB(6));
    tmp = A; A = RB(5); RB(5) = tmp;
    ADDC8(RB(1));
    RB(6) = A;
    A = 0;
    ADDC8(RB(4));
    RB(4) = A;
    A = RB(2);
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(RB(5));
    tmp = A; A = RB(6); RB(6) = tmp;
    ADDC8((B));
    RB(5) = A;
    A = 0;
    ADDC8(RB(4));
    RB(4) = A;
    return;
}

void f_7893(void)
{
    if (RB(0) != 0x00) { C = (RB(0) < 0x00); goto L_7857; }
    if (RB(1) != 0x00) { C = (RB(1) < 0x00); goto L_78F2; }
    if (RB(2) != 0x00) { C = (RB(2) < 0x00); goto L_78C9; }
    A = RB(4);
    B = RB(3);
    if (B == 0) { C = 0; } else { tmp = A % B; A = A / B; B = tmp; C = 0; }
    tmp = A; A = RB(7); RB(7) = tmp;
    tmp = A; A = RB(6); RB(6) = tmp;
    tmp = A; A = RB(5); RB(5) = tmp;
    RB(4) = A;
    A = B;
    tmp = A; A = RB(3); RB(3) = tmp;
    RB(1) = A;
    RB(0) = 0x18;
    L_78AA:
    A = RB(7);
    ADD8(RB(7));
    RB(7) = A;
    A = RB(6);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(6) = A;
    A = RB(5);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(5) = A;
    A = RB(4);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(4) = A;
    A = RB(3);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(3) = A;
    if (C) { C = (0) & 1; goto L_78BF; }
    SUBB8(RB(1));
    if (C != 0) goto L_78C3;
    L_78BF:
    A = RB(3);
    SUBB8(RB(1));
    RB(3) = A;
    RB(7)++;
    L_78C3:
    if (--RB(0)) goto L_78AA;
    A = 0;
    RB(1) = A;
    RB(2) = A;
    return;
    L_78C9:
    RB(0) = 0x18;
    L_78CB:
    A = RB(7);
    ADD8(RB(7));
    RB(7) = A;
    A = RB(6);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(6) = A;
    A = RB(5);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(5) = A;
    A = RB(4);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(4) = A;
    tmp = A; A = RB(1); RB(1) = tmp;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(1); RB(1) = tmp;
    if (C) { C = (0) & 1; goto L_78E2; }
    SUBB8(RB(3));
    A = RB(1);
    SUBB8(RB(2));
    if (C != 0) goto L_78E9;
    L_78E2:
    A = RB(4);
    SUBB8(RB(3));
    RB(4) = A;
    A = RB(1);
    SUBB8(RB(2));
    RB(1) = A;
    RB(7)++;
    L_78E9:
    if (--RB(0)) goto L_78CB;
    A = 0;
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(2) = A;
    A = 0;
    tmp = A; A = RB(4); RB(4) = tmp;
    RB(3) = A;
    return;
    L_78F2:
    B = 0x10;
    A = RB(7);
    ADD8(RB(7));
    RB(7) = A;
    A = RB(6);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(6) = A;
    A = RB(5);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(5) = A;
    tmp = A; A = RB(4); RB(4) = tmp;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(4); RB(4) = tmp;
    L_7857:
    B = 0x08;
    DPL = 0x00;
    L_785D:
    A = RB(7);
    ADD8(RB(7));
    RB(7) = A;
    A = RB(6);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(6) = A;
    tmp = A; A = RB(5); RB(5) = tmp;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(5); RB(5) = tmp;
    tmp = A; A = RB(4); RB(4) = tmp;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(4); RB(4) = tmp;
    tmp = A; A = DPL; DPL = tmp;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = DPL; DPL = tmp;
    SUBB8(RB(3));
    A = RB(5);
    SUBB8(RB(2));
    A = RB(4);
    SUBB8(RB(1));
    A = DPL;
    SUBB8(RB(0));
    if (C != 0) goto L_7884;
    DPL = A;
    A = RB(6);
    SUBB8(RB(3));
    RB(6) = A;
    A = RB(5);
    SUBB8(RB(2));
    RB(5) = A;
    A = RB(4);
    SUBB8(RB(1));
    RB(4) = A;
    RB(7)++;
    L_7884:
    if (--B) goto L_785D;
    A = 0;
    tmp = A; A = RB(6); RB(6) = tmp;
    RB(3) = A;
    A = 0;
    tmp = A; A = RB(5); RB(5) = tmp;
    RB(2) = A;
    A = 0;
    tmp = A; A = RB(4); RB(4) = tmp;
    RB(1) = A;
    RB(0) = DPL;
    return;
}

void f_7901(void)
{
    tmp = A; A = RB(0); RB(0) = tmp;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(0); RB(0) = tmp;
    if (C) { C = (0) & 1; goto L_790E; }
    SUBB8(RB(3));
    A = RB(4);
    SUBB8(RB(2));
    A = RB(0);
    SUBB8(RB(1));
    if (C != 0) goto L_7918;
    L_790E:
    A = RB(5);
    SUBB8(RB(3));
    RB(5) = A;
    A = RB(4);
    SUBB8(RB(2));
    RB(4) = A;
    A = RB(0);
    SUBB8(RB(1));
    RB(0) = A;
    RB(7)++;
    L_7918:
    if (--B) goto L_78F5;
    A = 0;
    tmp = A; A = RB(5); RB(5) = tmp;
    RB(3) = A;
    A = 0;
    tmp = A; A = RB(4); RB(4) = tmp;
    RB(2) = A;
    A = 0;
    tmp = A; A = RB(0); RB(0) = tmp;
    RB(1) = A;
    return;
    L_78F5:
    A = RB(7);
    ADD8(RB(7));
    RB(7) = A;
    A = RB(6);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(6) = A;
    A = RB(5);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(5) = A;
    tmp = A; A = RB(4); RB(4) = tmp;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(4); RB(4) = tmp;
}

void f_7959(void)
{
    A = RB(3);
    SUBB8(RB(7));
    B = A;
    A = RB(2);
    SUBB8(RB(6));
    B |= A;
    A = RB(1);
    SUBB8(RB(5));
    B |= A;
    A = RB(0);
    SUBB8(RB(4));
    A |= B;
    return;
}

void f_796A(void)
{
    A = RB(0);
    if (A == 0) goto L_797C;
    L_796D:
    A = RB(4);
    C = 0;
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    RB(4) = A;
    A = RB(5);
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    RB(5) = A;
    A = RB(6);
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    RB(6) = A;
    A = RB(7);
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    RB(7) = A;
    if (--RB(0)) goto L_796D;
    L_797C:
    return;
}

void f_79B0(void)
{
    A = XD(DPTR);
    RB(4) = A;
    DPTR++;
    A = XD(DPTR);
    RB(5) = A;
    DPTR++;
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void f_79CC(void)
{
    A = XD(DPTR);
    RB(0) = A;
    DPTR++;
    A = XD(DPTR);
    RB(1) = A;
    DPTR++;
    A = XD(DPTR);
    RB(2) = A;
    DPTR++;
    A = XD(DPTR);
    RB(3) = A;
    return;
}

void f_79D8(void)
{
    A = RB(4);
    XD(DPTR) = A;
    DPTR++;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    A = RB(6);
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_79E4(void)
{
    RB(0) = DPL;
    B = DPH;
    DPH = STACK[SP--];
    DPL = STACK[SP--];
    f_79FB();
    f_79FB();
    f_79FB();
    f_79FB();
    A = 0;
    ec_jump((unsigned int)DPTR + A);
    return;
}

void f_79FB(void)
{
    A = 0;
    A = CD(DPTR + A);
    DPTR++;
    tmp = A; A = DPH; DPH = tmp;
    tmp = A; A = B; B = tmp;
    tmp = A; A = DPH; DPH = tmp;
    tmp = A; A = RB(0); RB(0) = tmp;
    tmp = A; A = DPL; DPL = tmp;
    tmp = A; A = RB(0); RB(0) = tmp;
    XD(DPTR) = A;
    DPTR++;
    tmp = A; A = DPH; DPH = tmp;
    tmp = A; A = B; B = tmp;
    tmp = A; A = DPH; DPH = tmp;
    tmp = A; A = RB(0); RB(0) = tmp;
    tmp = A; A = DPL; DPL = tmp;
    tmp = A; A = RB(0); RB(0) = tmp;
    return;
}

void f_7A15(void)
{
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8((DPL));
    DPL = A;
    A = B;
    ADDC8((DPH));
    DPH = A;
    return;
}

void f_7A21(void)
{
    A = XD(DPTR);
    RB(3) = A;
    DPTR++;
    A = XD(DPTR);
    RB(2) = A;
    DPTR++;
    A = XD(DPTR);
    RB(1) = A;
    return;
}

void f_7A2A(void)
{
    RB(0) = A;
    A = XD(DPTR);
    RB(3) = A;
    DPTR++;
    DPTR++;
    A = XD(DPTR);
    RB(1) = A;
    ADD8((B));
    XD(DPTR) = A;
    A = DPL;
    DPL--;
    if (A != 0) goto L_7A3C;
    DPH--;
    L_7A3C:
    A = XD(DPTR);
    RB(2) = A;
    ADDC8(RB(0));
    XD(DPTR) = A;
    return;
}

void f_7A41(void)
{
    A = RB(3);
    XD(DPTR) = A;
    DPTR++;
    A = RB(2);
    XD(DPTR) = A;
    DPTR++;
    A = RB(1);
    XD(DPTR) = A;
    return;
}

void f_7A4A(void)
{
    DPH = STACK[SP--];
    DPL = STACK[SP--];
    RB(0) = A;
    L_7A4F:
    A = 0;
    A = CD(DPTR + A);
    if (A != 0) goto L_7A65;
    A = 0x01;
    A = CD(DPTR + A);
    if (A != 0) goto L_7A65;
    DPTR++;
    DPTR++;
    L_7A5A:
    A = CD(DPTR + A);
    RB(0) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(0);
    A = 0;
    ec_jump((unsigned int)DPTR + A);
    return;
    L_7A65:
    A = 0x02;
    A = CD(DPTR + A);
    A ^= RB(0);
    if (A == 0) goto L_7A5A;
    DPTR++;
    DPTR++;
    DPTR++;
    goto L_7A4F;
}

void f_7A70(void)
{
    DPH = RB(2);
    DPL = RB(1);
    A = 0;
    ec_jump((unsigned int)DPTR + A);
    return;
}


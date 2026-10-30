#include "ec_globals.h"

void f_805C(void)
{
    f_FE00();
    return;
}

void f_80D2(void)
{
    if (BIT_RAM(0x3F)) { BIT_SET(0x3F, 0); f_80D9(); return; }
    XD(DPTR) = A;
    DPTR = 0x103C;
}

void f_80D9(void)
{
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x06;
    XD(DPTR) = A;
    DPTR = 0x009D;
    A = XD(DPTR);
    A ^= 0xBF;
    if (A != 0) goto L_8101;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x50;
    XD(DPTR) = A;
    L_8101:
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x01;
    XD(DPTR) = A;
    DPTR = 0x009A;
    A = XD(DPTR);
    DPTR = 0x103F;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x05;
    XD(DPTR) = A;
    L_8137:
    DPTR = 0x103F;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_8137;
    A = 0;
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x103D;
    XD(DPTR) = A;
    return;
}

void f_8172(void)
{
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = XD(DPTR);
    A &= 0x01;
}

void f_8179(void)
{
    if (A != 0) goto L_8173;
    DPTR = 0x103C;
    A = 0xFE;
    L_8173:
    DPTR = 0x103F;
    A = XD(DPTR);
    A &= 0x01;
}

void f_8180(void)
{
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x9F;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x0094;
    XD(DPTR) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x04);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_81C0;
    DPTR = 0x103F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    ADD8(0x90);
    DPL = A;
    A = 0;
    ADDC8(0x00);
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    L_81C0:
    DPTR = 0x0090;
    A = XD(DPTR);
    DPTR = 0x009D;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
}

void f_81BE(void)
{
    goto L_8197;
    L_8197:
    DPTR = 0x0094;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x04);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_81C0;
    DPTR = 0x103F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    ADD8(0x90);
    DPL = A;
    A = 0;
    ADDC8(0x00);
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    L_81C0:
    DPTR = 0x0090;
    A = XD(DPTR);
    DPTR = 0x009D;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
}

void f_81CE(void)
{
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x05;
    XD(DPTR) = A;
    L_81DF:
    DPTR = 0x103F;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_81DF;
    A = 0;
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x103D;
    XD(DPTR) = A;
    return;
}

void f_821A(void)
{
    XD(DPTR) = A;
    L_821B:
    DPTR = 0x103F;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_821B;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0xAB;
    XD(DPTR) = A;
    A = 0;
    XD(DPTR) = A;
    XD(DPTR) = A;
    XD(DPTR) = A;
    DPTR = 0x0094;
    XD(DPTR) = A;
    L_8242:
    DPTR = 0x0094;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x04);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_826B;
    DPTR = 0x103F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    ADD8(0x90);
    DPL = A;
    A = 0;
    ADDC8(0x00);
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_8242;
    L_826B:
    DPTR = 0x0090;
    A = XD(DPTR);
    DPTR = 0x009D;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x05;
    XD(DPTR) = A;
    L_828A:
    DPTR = 0x103F;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_828A;
    A = 0;
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x103D;
    XD(DPTR) = A;
    return;
}

void f_824E(void)
{
    RB(4)--;
    DPTR = 0x103F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    ADD8(0x90);
    DPL = A;
    A = 0;
    ADDC8(0x00);
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_8242;
    L_8242:
    DPTR = 0x0094;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x04);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_826B;
    L_826B:
    DPTR = 0x0090;
    A = XD(DPTR);
    DPTR = 0x009D;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x05;
    XD(DPTR) = A;
    L_828A:
    DPTR = 0x103F;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_828A;
    A = 0;
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x103D;
    XD(DPTR) = A;
    return;
}

void f_825E(void)
{
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_8242;
    L_8242:
    DPTR = 0x0094;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x04);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_826B;
    DPTR = 0x103F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    ADD8(0x90);
    DPL = A;
    A = 0;
    ADDC8(0x00);
    L_826B:
    DPTR = 0x0090;
    A = XD(DPTR);
    DPTR = 0x009D;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x05;
    XD(DPTR) = A;
    L_828A:
    DPTR = 0x103F;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_828A;
    A = 0;
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x103D;
    XD(DPTR) = A;
    return;
}

void f_82FD(void)
{
    SUBB8((SFR_F5));
    C = C && (((A >> 4) & 1));
    ADDC8(0x00);
    DPH = A;
    A = XD(DPTR);
    DPTR = 0x103F;
    XD(DPTR) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_82EE;
    L_82EE:
    DPTR = 0x0094;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x03);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_8312;
    A = XD(DPTR);
    ADD8(0x95);
    DPL = A;
    A = 0;
    L_8312:
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x05;
    XD(DPTR) = A;
    L_8329:
    DPTR = 0x103F;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_8329;
    A = 0;
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x103D;
    XD(DPTR) = A;
    return;
}

void f_86DD(void)
{
    RB(7) = A;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x103B;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x05;
    XD(DPTR) = A;
    DPTR = 0x103F;
}

void f_86FE(void)
{
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_86FB;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x0B;
    XD(DPTR) = A;
    DPTR = 0x0095;
    A = XD(DPTR);
    DPTR = 0x103F;
    XD(DPTR) = A;
    DPTR = 0x0096;
    A = XD(DPTR);
    DPTR = 0x103F;
    XD(DPTR) = A;
    DPTR = 0x0097;
    A = XD(DPTR);
    DPTR = 0x103F;
    XD(DPTR) = A;
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x0094;
    XD(DPTR) = A;
    L_8738:
    DPTR = 0x103F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x009B;
    A = XD(DPTR);
    RB(4) = A;
    DPTR++;
    A = XD(DPTR);
    DPL = A;
    DPH = RB(4);
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    DPTR = 0x009C;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    DPTR = 0x0094;
    A = XD(DPTR);
    if (A != 0) goto L_8738;
    DPTR = 0x103C;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A++;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = 0x05;
    XD(DPTR) = A;
    L_8773:
    DPTR = 0x103F;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_8773;
    A = 0;
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x103D;
    XD(DPTR) = A;
    return;
    L_86FB:
    DPTR = 0x103F;
}

void f_8827(void)
{
    DPTR = 0x0098;
    A = RB(7);
    XD(DPTR) = A;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(5);
    tmp = A; A = RB(7); RB(7) = tmp;
    DPTR = 0x0095;
    A = RB(7);
    XD(DPTR) = A;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(3);
    tmp = A; A = RB(7); RB(7) = tmp;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x06B6;
    A = XD(DPTR);
    DPTR = 0x0097;
    XD(DPTR) = A;
    f_0600();
    tmp = A; A = RB(4); RB(4) = tmp;
    A = 0x82;
    tmp = A; A = RB(4); RB(4) = tmp;
    tmp = A; A = RB(5); RB(5) = tmp;
    A = 0x9C;
    tmp = A; A = RB(5); RB(5) = tmp;
    A = 0;
    RB(7) = A;
    f_BEBF();
}

void f_8968(void)
{
    A = RB(7);
    if (A != 0) goto L_8972;
    DPTR = 0x009F;
    A = 0x4F;
    XD(DPTR) = A;
    return;
    L_8972:
    DPTR = 0x009F;
    A = 0x0F;
    XD(DPTR) = A;
    return;
}

void f_8979(void)
{
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(7);
    tmp = A; A = RB(1); RB(1) = tmp;
    DPTR = 0x103E;
    A = XD(DPTR);
    DPTR = 0x069B;
    XD(DPTR) = A;
    DPTR = 0x1063;
    A = XD(DPTR);
    DPTR = 0x069C;
    XD(DPTR) = A;
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(7) = A;
    RB(6) = 0x00;
    if (A == 0) goto L_899C;
    A ^= 0x01;
    if (A == 0) goto L_899C;
    f_8A23();
    return;
    L_899C:
    A = RB(7);
    A |= RB(6);
    if (A != 0) goto L_89A8;
    DPTR = 0x103E;
    A = 0x40;
    XD(DPTR) = A;
    goto L_89B4;
    L_89B4:
    DPTR = 0x103D;
    A = RB(1);
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = RB(5);
    XD(DPTR) = A;
    DPTR = 0x103B;
    A = RB(3);
    XD(DPTR) = A;
    L_89C3:
    DPTR = 0x0697;
    A = XD(DPTR);
    if (A != 0) goto L_89CB;
    DPTR++;
    A = XD(DPTR);
    L_89CB:
    if (A == 0) goto L_8A13;
    DPTR = 0x103D;
    A = RB(1);
    XD(DPTR) = A;
    DPTR = 0x103C;
    A = RB(5);
    XD(DPTR) = A;
    DPTR = 0x103B;
    A = RB(3);
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(0) = A;
    DPTR++;
    A = XD(DPTR);
    DPL = A;
    DPH = RB(0);
    A = RB(7);
    XD(DPTR) = A;
    RB(3)++;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(3);
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    if (A != 0) goto L_89FD;
    RB(5)++;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(5);
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    if (A != 0) goto L_89FD;
    RB(1)++;
    L_89FD:
    DPTR = 0x0699;
    A = 0;
    B = 0x01;
    f_77E5();
    DPTR = 0x0697;
    A = 0xFF;
    B = A;
    f_77E5();
    goto L_89C3;
    L_8A13:
    DPTR = 0x069B;
    A = XD(DPTR);
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x069C;
    A = XD(DPTR);
    DPTR = 0x1063;
    XD(DPTR) = A;
    return;
    L_89A8:
    A = 0;
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x1063;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
}

void f_8A24(void)
{
    DPTR = 0x103E;
    A = 0x40;
    XD(DPTR) = A;
    DPTR = 0x103D;
    A = RB(7);
    XD(DPTR) = A;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(5);
    tmp = A; A = RB(7); RB(7) = tmp;
    DPTR = 0x103C;
    A = RB(7);
    XD(DPTR) = A;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(3);
    tmp = A; A = RB(7); RB(7) = tmp;
    DPTR = 0x103B;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x103F;
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void f_8A45(void)
{
    f_9FB3();
    if (A != 0) goto L_8A5C;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_8A51;
    goto L_8A5C;
    L_8A5C:
    RB(7) = 0x06;
    f_8B45();
    return;
    L_8A51:
    RB(0) = 0x85;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_8A59;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    goto L_8A61;
    L_8A61:
    RB(0) = 0x8B;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    f_8AED();
    if (!BIT_RAM(0x13)) goto L_8A76;
    f_90F9();
    RB(7) = 0x06;
    f_8B4F();
    f_8AE9();
    return;
    L_8A76:
    A = 0;
    RB(7) = A;
    L_8A78:
    f_9E96();
    if (C == 0) goto L_8A9B;
    f_9F2B();
    if (A == 0) goto L_8A98;
    A = RB(7);
    f_9E32();
    f_9EC7();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    f_9E72();
    RB(5) = A;
    A = RB(6);
    A |= RB(5);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    L_8A98:
    RB(7)++;
    goto L_8A78;
    L_8A9B:
    A = 0;
    RB(7) = A;
    L_8A9D:
    f_9E96();
    if (C == 0) goto L_8AE4;
    RB(0) = 0x87;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= RB(7);
    if (A != 0) goto L_8AE1;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    f_9E62();
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(4);
    A = 0x17;
    XD(DPTR) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    f_9E4D();
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(4);
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(6) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xC3);
    DPL = A;
    A = 0;
    ADDC8(0x6B);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(5) = A;
    A = RB(6);
    A |= RB(5);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    L_8AE1:
    RB(7)++;
    goto L_8A9D;
    L_8AE4:
    RB(7) = 0x06;
    f_8B45();
    L_8A59:
    if (!BIT_RAM(0x05)) goto L_8A61;
}

void f_8AE9(void)
{
    f_9BE8();
    return;
}

void f_8AED(void)
{
    tmp = A; A = RB(5); RB(5) = tmp;
    A = RB(7);
    tmp = A; A = RB(5); RB(5) = tmp;
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0x0F;
    XD(DPTR) = A;
    if (!BIT_RAM(0x13)) goto L_8B27;
    RB(0) = 0x87;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_8B04;
    A = 0x40;
    XD(DPTR) = A;
    goto L_8B20;
    L_8B20:
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    L_8B27:
    DPTR = 0x1304;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    DPTR = 0x1300;
    A = XD(DPTR);
    A &= 0xFC;
    XD(DPTR) = A;
    if (!BIT_RAM(0x01)) goto L_8B3C;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    L_8B3C:
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(5);
    tmp = A; A = RB(7); RB(7) = tmp;
    DPTR = 0x1308;
    A = RB(7);
    XD(DPTR) = A;
    return;
    L_8B04:
    RB(0) = 0x87;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0x01;
    if (A != 0) goto L_8B13;
    DPTR = 0x1304;
    A = 0x80;
    XD(DPTR) = A;
    goto L_8B20;
    L_8B13:
    RB(0) = 0x87;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0x02;
    if (A != 0) goto L_8B20;
    DPTR = 0x1304;
    A = 0xC0;
    XD(DPTR) = A;
}

void f_8B45(void)
{
    RB(0) = 0x80;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    C = 0;
    SUBB8(RB(7));
    if (C == 0) goto L_8B4E;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    L_8B4E:
    return;
}

void f_8B4F(void)
{
    RB(0) = 0xA1;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    C = 0;
    SUBB8(RB(7));
    if (C == 0) goto L_8B58;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    L_8B58:
    return;
}

void f_8B59(void)
{
    DPTR = 0x06A0;
    A = RB(7);
    XD(DPTR) = A;
    RB(0) = 0x90;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_8B8C;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_8B8C;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x97);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_8B81;
    A = 0x97;
    ADD8(RB(7));
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0x03;
    if (A == 0) goto L_8B81;
    A = XD(DPTR);
    ADD8(0x97);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0x04;
    if (A != 0) goto L_8B8C;
    L_8B81:
    DPTR = 0x06A0;
    A = XD(DPTR);
    ADD8(0x97);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(0) = 0x91;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    L_8B8C:
    f_9FB3();
    if (A != 0) goto L_8B99;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_8B99;
    if (!BIT_RAM(0x05)) goto L_8BA4;
    L_8B99:
    f_9F49();
    RB(0) = 0x8B;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0) = 0xAD;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x33;
    return;
    L_8BA4:
    f_9F49();
    RB(7) = A;
    f_8AED();
    RB(0) = 0x85;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_8BB1;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    L_8BB1:
    if (!BIT_RAM(0x13)) goto L_8BBF;
    if (BIT_RAM(0x64)) goto L_8C27;
    f_90F9();
    RB(7) = 0x06;
    f_8B4F();
    return;
    L_8C27:
    return;
    L_8BBF:
    if (BIT_RAM(0x64)) goto L_8C27;
    A = 0;
    RB(7) = A;
    L_8BC4:
    f_9E96();
    if (C == 0) goto L_8BE7;
    f_9F2B();
    if (A == 0) goto L_8BE4;
    A = RB(7);
    f_9E32();
    f_9EC7();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    f_9E72();
    RB(5) = A;
    A = RB(6);
    A |= RB(5);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    L_8BE4:
    RB(7)++;
    goto L_8BC4;
    L_8BE7:
    A = 0;
    RB(7) = A;
    L_8BE9:
    f_9E96();
    if (C == 0) goto L_8C22;
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(6) = A;
    A ^= RB(7);
    if (A != 0) goto L_8C1F;
    A = XD(DPTR);
    RB(5) = A;
    f_9E62();
    RB(2) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(2);
    A = 0x17;
    XD(DPTR) = A;
    A = RB(5);
    f_9E4D();
    f_9EC7();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(5) = A;
    A = RB(6);
    f_9E75();
    RB(6) = A;
    A = RB(5);
    A |= RB(6);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    L_8C1F:
    RB(7)++;
    goto L_8BE9;
    L_8C22:
    RB(7) = 0x06;
    f_8B45();
}

void f_8C28(void)
{
    DPTR = 0x06A0;
    A = RB(7);
    XD(DPTR) = A;
    RB(0) = 0x9D;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_8C3E;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    A = XD(DPTR);
    ADD8(0x97);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    f_0A8D();
    goto L_8C4A;
    L_8C4A:
    f_0B19();
    RB(0) = 0x9D;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_8C69;
    RB(0) = 0xAD;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0x33;
    if (A != 0) goto L_8C5E;
    if (BIT_RAM(0x64)) goto L_8C8F;
    goto L_8C6C;
    L_8C6C:
    DPTR = 0x06A0;
    f_9E30();
    f_9ED0();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x06A0;
    A = XD(DPTR);
    f_9E75();
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    RB(7) = 0x06;
    f_8B45();
    L_8C8F:
    return;
    L_8C5E:
    if (BIT_RAM(0x64)) goto L_8C8F;
    f_90F9();
    RB(7) = 0x06;
    f_8B4F();
    return;
    L_8C69:
    if (BIT_RAM(0x64)) goto L_8C8F;
    L_8C3E:
    DPTR = 0x06A0;
    A = XD(DPTR);
    ADD8(0x97);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    f_2D4B();
}

void f_8C90(void)
{
    DPTR = 0x06A0;
    A = RB(7);
    XD(DPTR) = A;
    DPTR++;
    A = RB(5);
    XD(DPTR) = A;
    BIT_SET(0x61, 0);
    f_9E2B();
    A = 0;
    RB(7) = A;
    f_9E26();
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x80);
    RB(0) = 0x8C;
    f_9E8E();
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x01;
    if (A == 0) goto L_8CD8;
    A = 0x97;
    ADD8(RB(7));
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0xFA;
    if (A != 0) goto L_8CC6;
    f_9E87();
    A = 0x02;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_8D52();
    return;
    L_8CC6:
    f_9F3D();
    if (C == 0) goto L_8CCE;
    f_8D52();
    return;
    L_8CCE:
    f_9E85();
    A = 0x04;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_8D52();
    return;
    L_8CD8:
    f_9E8F();
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x10;
    if (A == 0) goto L_8D04;
    DPTR = 0x06A0;
    A = XD(DPTR);
    ADD8(0x97);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0xFA;
    if (A != 0) goto L_8CF6;
    f_9E87();
    A = 0x20;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_8D52();
    return;
    L_8CF6:
    f_9F3D();
    if (C != 0) { f_8D52(); return; }
    f_9E85();
    A = 0x40;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_8D52();
    return;
    L_8D04:
    DPTR = 0x06A0;
    f_9F63();
    if (A != 0) goto L_8D14;
    A = 0x88;
    ADD8(RB(7));
    RB(0) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x02;
    goto L_8D33;
    L_8D33:
    f_8D5E();
    ADD8(0xB0);
    goto L_8D4F;
    L_8D4F:
    RB(0) = 0x8C;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    L_8D14:
    DPTR = 0x06A0;
    A = XD(DPTR);
    ADD8(0x88);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x08;
    if (A == 0) goto L_8D27;
    f_8D5E();
    ADD8(0xC0);
    goto L_8D4F;
    L_8D27:
    DPTR = 0x06A0;
    A = XD(DPTR);
    ADD8(0x88);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0x02;
    if (A != 0) goto L_8D3A;
    L_8D3A:
    DPTR = 0x06A0;
    A = XD(DPTR);
    ADD8(0xA2);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) { f_8D52(); return; }
    RB(7) = 0xFF;
    f_9E26();
    DPTR = 0x06A0;
    A = XD(DPTR);
    ADD8(0xA0);
}

void f_8D52(void)
{
    DPTR = 0x06A1;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_8D5D;
    f_90F9();
    L_8D5D:
    return;
}

void f_8D5E(void)
{
    RB(7) = 0xFF;
    f_9E26();
    DPTR = 0x06A0;
    A = XD(DPTR);
    return;
}

void f_8D68(void)
{
    DPTR = 0x069E;
    A = RB(7);
    XD(DPTR) = A;
    if (!BIT_RAM(0x60)) goto L_8D90;
    BIT_SET(0x60, 0);
    f_9E30();
    f_9ED0();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x069E;
    A = XD(DPTR);
    f_9E75();
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_9E2B();
    return;
    L_8D90:
    if (!BIT_RAM(0x61)) goto L_8D9D;
    DPTR = 0x069E;
    A = XD(DPTR);
    RB(7) = A;
    RB(5) = 0x01;
    f_8C90();
    return;
    L_8D9D:
    A = 0;
    RB(7) = A;
    f_9E26();
    f_9E2B();
    f_9F60();
    A &= 0x80;
    if (A == 0) goto L_8DAF;
    f_8B59();
    return;
    L_8DAF:
    f_9F60();
    A &= 0x40;
    if (A == 0) goto L_8DB9;
    f_8C28();
    return;
    L_8DB9:
    f_90F9();
    return;
}

void f_8DBD(void)
{
    f_9144();
    DPTR = 0x1106;
    A = XD(DPTR);
    A &= 0xE3;
    f_9EEF();
    BIT_SET(0x18, 0);
    BIT_SET(0x34, 0);
    return;
}

void f_8E13(void)
{
    A = 0;
    DPTR = 0x069C;
    XD(DPTR) = A;
    f_9FBA();
    if (A != 0) goto L_8E2D;
    f_9FC1();
    if (A != 0) goto L_8E2D;
    f_9FC8();
    if (A != 0) goto L_8E2D;
    if (BIT_RAM(0x34)) goto L_8E2D;
    if (!BIT_RAM(0x18)) goto L_8E6D;
    L_8E2D:
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    f_9F9D();
    L_8E38:
    if (((SFR_88 >> 7) & 1)) goto L_8E48;
    if (!BIT_RAM(0x34)) goto L_8E38;
    DPTR = 0x069C;
    A = 0x01;
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    L_8E48:
    if (!((SFR_88 >> 7) & 1)) goto L_8E58;
    f_9DB2();
    A = RB(7);
    A ^= 0x01;
    if (A != 0) goto L_8E58;
    DPTR = 0x069C;
    A++;
    XD(DPTR) = A;
    L_8E58:
    DPTR = 0x069C;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_8E69;
    BIT_SET(0x34, 0);
    BIT_SET(0x64, 1);
    f_8FD6();
    BIT_SET(0x64, 0);
    L_8E69:
    f_9F13();
    return;
    L_8E6D:
    f_90EA();
    return;
}

void f_8E71(void)
{
    DPTR = 0x0698;
    A = RB(7);
    XD(DPTR) = A;
    DPTR++;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    A = RB(3);
    XD(DPTR) = A;
    if (!BIT_RAM(0x61)) goto L_8E90;
    RB(0) = 0x9E;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    f_9CE2();
    A = RB(7);
    A ^= 0x01;
    if (A != 0) goto L_8E9B;
    f_93F0();
    goto L_8E9B;
    L_8E9B:
    f_8DBD();
    DPTR = 0x0699;
    A = XD(DPTR);
    A = ~A;
    if (A != 0) goto L_8EA9;
    RB(7) = 0x78;
    goto L_8ECB;
    L_8ECB:
    f_8B45();
    A = 0;
    RB(7) = A;
    f_9E26();
    BIT_SET(0x61, 0);
    BIT_SET(0x60, 1);
    DPTR = 0x0698;
    f_9E60();
    f_9EFE();
    DPTR = 0x0699;
    f_9E9F();
    DPTR = 0x0698;
    f_9E60();
    f_9EC7();
    A = 0x1E;
    f_9E4B();
    f_9ED0();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x0698;
    A = XD(DPTR);
    RB(7) = A;
    f_9E75();
    RB(5) = A;
    A = RB(6);
    A |= RB(5);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_9D63();
    return;
    L_8EA9:
    RB(0) = 0x85;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_8EB0;
    goto L_8EB5;
    L_8EB5:
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    B = 0x06;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    DPTR = 0x069B;
    XD(DPTR) = A;
    goto L_8EC6;
    L_8EC6:
    DPTR = 0x069B;
    A = XD(DPTR);
    RB(7) = A;
    L_8EB0:
    RB(0) = 0x9D;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_8EC0;
    L_8EC0:
    DPTR = 0x069B;
    A = 0x06;
    XD(DPTR) = A;
    L_8E90:
    DPTR = 0x069A;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_8E9B;
    f_8E13();
}

void f_8F10(void)
{
    DPTR = 0x069B;
    A = RB(7);
    XD(DPTR) = A;
    DPTR++;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    A = RB(3);
    XD(DPTR) = A;
    A = 0;
    RB(0) = 0x95;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_8DBD();
    BIT_SET(0x61, 0);
    BIT_SET(0x60, 0);
    f_9E5D();
    f_9EFE();
    DPTR = 0x069C;
    f_9E9F();
    f_9E5D();
    f_9EC7();
    A = 0x1E;
    XD(DPTR) = A;
    RB(5) = 0x01;
    f_97FC();
    A = RB(7);
    if (A != 0) goto L_8F6B;
    DPTR = 0x069E;
    XD(DPTR) = A;
    L_8F47:
    DPTR = 0x069D;
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(6));
    if (C == 0) goto L_8F6B;
    f_9E5D();
    f_9EC7();
    A = 0x17;
    XD(DPTR) = A;
    RB(5) = 0x02;
    f_97FC();
    A = RB(7);
    if (A != 0) goto L_8F6B;
    DPTR = 0x069E;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_8F47;
    L_8F6B:
    DPTR = 0x069B;
    A = XD(DPTR);
    f_9E62();
    f_9EC7();
    f_9EED();
    return;
}

void f_8F79(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    A = 0;
    RB(7) = A;
    f_9CDD();
    f_9BE8();
    if (!BIT_RAM(0x1B)) goto L_8F9A;
    RB(7) = 0x01;
    f_9CDD();
    DPTR = 0x0693;
    f_9F36();
    f_8E71();
    BIT_SET(0x1B, 0);
    return;
    L_8F9A:
    A = DIR(0x32);
    ADD8(0x0D);
    if (A == 0) goto L_8FA4;
    ADD8(0x0B);
    if (A != 0) goto L_8FA6;
    L_8FA4:
    BIT_SET(0x1B, 1);
    L_8FA6:
    RB(7) = DIR(0x32);
    A = RB(7);
    A = ~A;
    if (A != 0) goto L_8FB0;
    RB(7) = 0x03;
    goto L_8FC8;
    L_8FC8:
    f_9CDD();
    DPTR = 0x0693;
    f_9F36();
    f_8E71();
    return;
    L_8FB0:
    RB(7) = DIR(0x32);
    A = RB(7);
    A ^= 0xF2;
    if (A != 0) goto L_8FBB;
    RB(7) = 0x02;
    goto L_8FC8;
    L_8FBB:
    RB(7) = DIR(0x32);
    A = RB(7);
    A ^= 0xE9;
    if (A != 0) goto L_8FC6;
    RB(7) = 0x04;
    goto L_8FC8;
    L_8FC6:
    RB(7) = 0x01;
}

void f_8FBA(void)
{
    RB(5)++;
    RB(7) = DIR(0x32);
    A = RB(7);
    A ^= 0xE9;
    if (A != 0) goto L_8FC6;
    RB(7) = 0x04;
    goto L_8FC8;
    L_8FC8:
    f_9CDD();
    DPTR = 0x0693;
    f_9F36();
    f_8E71();
    return;
    L_8FC6:
    RB(7) = 0x01;
}

void f_8FD6(void)
{
    RB(0) = 0x84;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DPTR = 0x069D;
    XD(DPTR) = A;
    A = XD(DPTR);
    A = ~A;
    if (A == 0) goto L_8FF7;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x97);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(5) = A;
    f_C5F4();
    L_8FF7:
    return;
}

void f_8FEB(void)
{
    RB(0) = 0x84;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xFF;
    DPTR = 0x069D;
    A = XD(DPTR);
    RB(7) = A;
    f_8D68();
    return;
}

void f_8FF8(void)
{
    f_96C8();
    return;
}

void f_8FFB(void)
{
    RB(0) = 0x9D;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
}

void f_9000(void)
{
    DPTR = 0x0045;
    A = XD(DPTR);
    A ^= 0x33;
    if (A != 0) goto L_900B;
    RB(7) = 0x33;
    return;
    L_900B:
    DPTR = 0x0045;
    A = XD(DPTR);
    A ^= 0x55;
    if (A != 0) goto L_9033;
    DPTR = 0x227C;
    A = 0x55;
    XD(DPTR) = A;
    DPTR++;
    A = 0xAA;
    XD(DPTR) = A;
    DPTR++;
    A = 0x55;
    XD(DPTR) = A;
    DPTR++;
    A = 0xAA;
    XD(DPTR) = A;
    DPTR = 0x1F01;
    A = 0x20;
    XD(DPTR) = A;
    DPTR = 0x1F07;
    A = 0x5A;
    XD(DPTR) = A;
    L_9031:
    goto L_9031;
    L_9033:
    RB(7) = 0x00;
    return;
}

void f_9036(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    f_129F();
    f_9BE8();
    A = 0;
    RB(7) = A;
    f_9CDD();
    A = 0;
    RB(0) = 0x90;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    if (!BIT_RAM(0x1B)) goto L_906D;
    RB(7) = 0x01;
    f_9CDD();
    RB(0) = 0x82;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A = ~A;
    if (A != 0) goto L_905C;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = DIR(0x32);
    goto L_9064;
    L_9064:
    f_9F33();
    f_8E71();
    BIT_SET(0x1B, 0);
    return;
    L_905C:
    RB(0) = 0x83;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A = ~A;
    if (A != 0) goto L_9064;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = DIR(0x32);
    L_906D:
    A = DIR(0x32);
    ADD8(0x0E);
    if (A == 0) goto L_9098;
    A--;
    if (A == 0) goto L_9088;
    A--;
    if (A == 0) goto L_9090;
    A--;
    if (A == 0) goto L_9094;
    ADD8(0xF6);
    if (A == 0) goto L_909E;
    ADD8(0x17);
    if (A != 0) goto L_90BE;
    RB(0) = 0x82;
    goto L_908A;
    L_908A:
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xFF;
    BIT_SET(0x1B, 1);
    goto L_90BE;
    L_90BE:
    RB(7) = DIR(0x32);
    A = RB(7);
    A = ~A;
    if (A != 0) goto L_90C8;
    RB(7) = 0x03;
    goto L_90E0;
    L_90E0:
    f_9CDD();
    f_9F33();
    f_8E71();
    return;
    L_90C8:
    RB(7) = DIR(0x32);
    A = RB(7);
    A ^= 0xF2;
    if (A != 0) goto L_90D3;
    RB(7) = 0x02;
    goto L_90E0;
    L_90D3:
    RB(7) = DIR(0x32);
    A = RB(7);
    A ^= 0xE9;
    if (A != 0) goto L_90DE;
    RB(7) = 0x04;
    goto L_90E0;
    L_90DE:
    RB(7) = 0x01;
    L_909E:
    BIT_SET(0x19, 0);
    BIT_SET(0x13, 0);
    A = 0;
    RB(7) = A;
    L_90A4:
    f_9E96();
    if (C == 0) goto L_90BE;
    RB(0) = 0x9B;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A--;
    A ^= RB(7);
    if (A == 0) goto L_90BB;
    f_9F0B();
    if (A == 0) goto L_90BB;
    A = 0x88;
    ADD8(RB(7));
    RB(0) = A;
    A = 0;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    L_90BB:
    RB(7)++;
    goto L_90A4;
    L_9094:
    BIT_SET(0x19, 0);
    goto L_90BE;
    L_9090:
    BIT_SET(0x19, 1);
    goto L_90BE;
    L_9088:
    RB(0) = 0x83;
    L_9098:
    RB(0) = 0x90;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x02;
    goto L_90BE;
}

void f_90EA(void)
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

void f_90F9(void)
{
    A = 0;
    RB(7) = A;
    L_90FB:
    f_9E96();
    if (C == 0) goto L_911E;
    f_9F2B();
    if (A == 0) goto L_911B;
    A = RB(7);
    f_9E32();
    f_9EC7();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    f_9E72();
    RB(5) = A;
    A = RB(6);
    A |= RB(5);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    L_911B:
    RB(7)++;
    goto L_90FB;
    L_911E:
    A = 0;
    RB(7) = A;
    L_9120:
    f_9E96();
    if (C == 0) goto L_9143;
    f_9F0B();
    if (A == 0) goto L_9140;
    A = RB(7);
    f_9E32();
    f_9EC7();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    f_9E72();
    RB(5) = A;
    A = RB(6);
    A |= RB(5);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    L_9140:
    RB(7)++;
    goto L_9120;
    L_9143:
    return;
}

void f_9144(void)
{
    f_90EA();
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    SFR_8D = 0xFF;
    SFR_8B = 0x8C;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    L_9159:
    if (!((SFR_88 >> 7) & 1)) goto L_9159;
    f_9F13();
    return;
}

void f_9160(void)
{
    DPTR = 0x0698;
    A = RB(7);
    XD(DPTR) = A;
    RB(6) = 0x00;
    A ^= 0x01;
    if (A != 0) goto L_9171;
    RB(0) = 0x9B;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_917F;
    return;
    L_917F:
    A = 0;
    DPTR = 0x0699;
    XD(DPTR) = A;
    L_9171:
    A = RB(7);
    A ^= 0x02;
    A |= RB(6);
    if (A != 0) goto L_917F;
    RB(0) = 0x9C;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_917F;
    f_92C7();
    return;
}

void f_9184(void)
{
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(7) = A;
    RB(5) = A;
    RB(4) = 0x00;
    f_9E97();
    if (C != 0) goto L_9194;
    f_92B5();
    return;
    L_9194:
    f_9F0B();
    if (A == 0) goto L_919C;
    f_92AC();
    return;
    L_919C:
    A = XD(DPTR);
    ADD8(0x88);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x40;
    if (A == 0) goto L_91A8;
    f_92AC();
    return;
    L_91A8:
    A = XD(DPTR);
    ADD8(0x88);
    RB(0) = A;
    A = 0;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(5);
    if (A != 0) goto L_91C1;
    f_9F6A();
    if (A == 0) goto L_91B9;
    f_92AC();
    return;
    L_91B9:
    f_9F71();
    if (A == 0) goto L_91EE;
    f_92AC();
    return;
    L_91EE:
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(7) = A;
    RB(3) = 0x01;
    RB(5) = 0xFF;
    f_8F10();
    A = RB(7);
    if (A == 0) goto L_9200;
    f_929F();
    return;
    L_9200:
    RB(0) = 0x95;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0xFA;
    if (A == 0) goto L_920A;
    f_929F();
    return;
    L_920A:
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x88);
    RB(0) = A;
    A = 0x01;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    f_9E62();
    f_9ED0();
    A = 0x17;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x069A;
    XD(DPTR) = A;
    L_9225:
    f_9ED9();
    if (C == 0) goto L_9237;
    f_92DE();
    if (A == 0) goto L_9237;
    DPTR = 0x069A;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_9225;
    L_9237:
    f_9ED9();
    if (C != 0) goto L_924A;
    DPTR = 0x0699;
    A = XD(DPTR);
    L_924A:
    DPTR = 0x0699;
    A = XD(DPTR);
    f_9E62();
    f_9ED0();
    A = 0x17;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x069A;
    XD(DPTR) = A;
    L_925C:
    f_9ED9();
    if (C == 0) goto L_926E;
    f_92DE();
    if (A == 0) goto L_926E;
    DPTR = 0x069A;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_925C;
    L_926E:
    f_9ED9();
    if (C != 0) goto L_927A;
    f_92C8();
    if (A != 0) { f_929F(); return; }
    f_92B5();
    return;
    L_927A:
    RB(0) = 0x95;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_9298;
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x88);
    RB(0) = A;
    A = 0x80;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_9BDC();
    DPTR = 0x0698;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) { f_929F(); return; }
    f_92B5();
    return;
    L_9298:
    f_92C8();
    if (A == 0) { f_92B5(); return; }
    f_929F();
    return;
    L_91C1:
    RB(6) = 0x00;
    A = RB(7);
    A ^= 0x01;
    if (A != 0) goto L_91D8;
    f_9F78();
    if (A == 0) goto L_91D0;
    f_92AC();
    return;
    L_91D0:
    f_9F7F();
    if (A == 0) goto L_91EE;
    f_92AC();
    return;
    L_91D8:
    A = RB(7);
    A ^= 0x02;
    A |= RB(6);
    if (A != 0) goto L_91EE;
    f_9F86();
    if (A == 0) goto L_91E6;
    f_92AC();
    return;
    L_91E6:
    f_9F8D();
    if (A == 0) goto L_91EE;
    f_92AC();
    return;
}

void f_91DA(void)
{
    f_4E70();
    return;
}

void f_91FE(void)
{
    SFR_98 = (SFR_98 & ~(1 << 7)) | (((C) & 1) << 7);
    RB(0) = 0x95;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0xFA;
    if (A == 0) goto L_920A;
    f_929F();
    return;
    L_920A:
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x88);
    RB(0) = A;
    A = 0x01;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    f_9E62();
    f_9ED0();
    A = 0x17;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x069A;
    XD(DPTR) = A;
    L_9225:
    f_9ED9();
    if (C == 0) goto L_9237;
    f_92DE();
    if (A == 0) goto L_9237;
    DPTR = 0x069A;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_9225;
    L_9237:
    f_9ED9();
    if (C != 0) goto L_924A;
    DPTR = 0x0699;
    A = XD(DPTR);
    L_924A:
    DPTR = 0x0699;
    A = XD(DPTR);
    f_9E62();
    f_9ED0();
    A = 0x17;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x069A;
    XD(DPTR) = A;
    L_925C:
    f_9ED9();
    if (C == 0) goto L_926E;
    f_92DE();
    if (A == 0) goto L_926E;
    DPTR = 0x069A;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_925C;
    L_926E:
    f_9ED9();
    if (C != 0) goto L_927A;
    f_92C8();
    if (A != 0) { f_929F(); return; }
    f_92B5();
    return;
    L_927A:
    RB(0) = 0x95;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_9298;
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x88);
    RB(0) = A;
    A = 0x80;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_9BDC();
    DPTR = 0x0698;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) { f_929F(); return; }
    f_92B5();
    return;
    L_9298:
    f_92C8();
    if (A == 0) { f_92B5(); return; }
    f_929F();
    return;
}

void f_91FF(void)
{
    SUBB8(RB(7));
    RB(0) = 0x95;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0xFA;
    if (A == 0) goto L_920A;
    f_929F();
    return;
    L_920A:
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x88);
    RB(0) = A;
    A = 0x01;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    f_9E62();
    f_9ED0();
    A = 0x17;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x069A;
    XD(DPTR) = A;
    L_9225:
    f_9ED9();
    if (C == 0) goto L_9237;
    f_92DE();
    if (A == 0) goto L_9237;
    DPTR = 0x069A;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_9225;
    L_9237:
    f_9ED9();
    if (C != 0) goto L_924A;
    DPTR = 0x0699;
    A = XD(DPTR);
    L_924A:
    DPTR = 0x0699;
    A = XD(DPTR);
    f_9E62();
    f_9ED0();
    A = 0x17;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x069A;
    XD(DPTR) = A;
    L_925C:
    f_9ED9();
    if (C == 0) goto L_926E;
    f_92DE();
    if (A == 0) goto L_926E;
    DPTR = 0x069A;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_925C;
    L_926E:
    f_9ED9();
    if (C != 0) goto L_927A;
    f_92C8();
    if (A != 0) { f_929F(); return; }
    f_92B5();
    return;
    L_927A:
    RB(0) = 0x95;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_9298;
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x88);
    RB(0) = A;
    A = 0x80;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_9BDC();
    DPTR = 0x0698;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) { f_929F(); return; }
    f_92B5();
    return;
    L_9298:
    f_92C8();
    if (A == 0) { f_92B5(); return; }
    f_929F();
    return;
}

void f_9240(void)
{
    ADD8(0x88);
    RB(0) = A;
    A = 0xFE;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_929F();
    return;
}

void f_929F(void)
{
    DPTR = 0x0699;
    A = XD(DPTR);
    f_9E62();
    f_9ED0();
    f_9EED();
}

void f_92AC(void)
{
    DPTR = 0x0699;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    f_9184();
    return;
}

void f_92B5(void)
{
    RB(0) = 0x9B;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_92C7;
    RB(0) = 0x9C;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_92C7;
    f_9E2B();
    A = 0;
    RB(7) = A;
    f_9E26();
    L_92C7:
    return;
}

void f_92C8(void)
{
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x88);
    RB(0) = A;
    A = 0x40;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_9BCC();
    DPTR = 0x0698;
    A = XD(DPTR);
    A ^= 0x02;
    return;
}

void f_92DE(void)
{
    DPTR = 0x0699;
    A = XD(DPTR);
    RB(7) = A;
    RB(5) = 0x02;
    f_97FC();
    A = RB(7);
    return;
}

void f_93B5(void)
{
    RB(0)++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0) = 0x9E;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(0xC0);
    goto L_93DE;
    L_93DE:
    RB(1) = 0x8C;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    f_90F9();
    return;
}

void f_93F0(void)
{
    f_9E2B();
    A = 0;
    RB(7) = A;
    f_9E26();
    RB(0) = 0x9E;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(0x88);
    f_9E8C();
    A = 0;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0) = 0xAE;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    BIT_SET(0x60, 0);
    BIT_SET(0x61, 0);
    f_9FCF();
    RB(0) = 0x9B;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= RB(7);
    if (A != 0) goto L_9413;
    A = RB(6);
    L_9413:
    if (A != 0) goto L_9439;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x069C;
    XD(DPTR) = A;
    L_941A:
    DPTR = 0x069C;
    A = XD(DPTR);
    RB(7) = A;
    f_9E97();
    if (C == 0) goto L_9439;
    f_9F0B();
    if (A == 0) goto L_9431;
    A = XD(DPTR);
    ADD8(0x88);
    f_9FA8();
    goto L_9439;
    L_9439:
    f_9FCF();
    RB(0) = 0x9C;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= RB(7);
    if (A != 0) goto L_9443;
    A = RB(6);
    L_9443:
    if (A != 0) goto L_946F;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPTR = 0x069C;
    XD(DPTR) = A;
    L_944A:
    DPTR = 0x069C;
    A = XD(DPTR);
    RB(7) = A;
    f_9E97();
    if (C == 0) goto L_946F;
    f_9F2B();
    if (A == 0) goto L_9467;
    A = XD(DPTR);
    ADD8(0x88);
    RB(0) = A;
    A = 0x10;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    A++;
    RB(0) = 0x9C;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
    L_9467:
    DPTR = 0x069C;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_944A;
    L_946F:
    return;
    L_9431:
    DPTR = 0x069C;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_941A;
}

void f_94B2(void)
{
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    C = 0;
    SUBB8(0x04);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_94C3;
    f_954C();
    return;
    L_94C3:
    f_9FD9();
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(5) = A;
    RB(4) = 0x00;
    tmp = A; A = RB(0); RB(0) = tmp;
    A = RB(7);
    tmp = A; A = RB(0); RB(0) = tmp;
    RB(6) = 0x00;
    A = 0x01;
    RB(0)++;
    goto L_94D9;
    L_94D9:
    if (--RB(0)) goto L_94D4;
    RB(7) = A;
    A = RB(6);
    A &= RB(4);
    RB(6) = A;
    A = RB(7);
    A &= RB(5);
    A |= RB(6);
    if (A == 0) goto L_9543;
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    DPTR++;
    A = XD(DPTR);
    DPTR = 0x6BDE;
    A = CD(DPTR + A);
    RB(5) = A;
    RB(3) = 0x01;
    f_8F10();
    A = RB(7);
    if (A != 0) goto L_9543;
    DPTR = 0x0694;
    A = XD(DPTR);
    DPTR = 0x6BDE;
    A = CD(DPTR + A);
    A ^= 0xF3;
    if (A != 0) goto L_950E;
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    RB(0) = 0x96;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    goto L_9523;
    L_9523:
    RB(5) = A;
    RB(3) = 0x01;
    f_8F10();
    L_9529:
    f_9FD9();
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(0);
    tmp = A; A = RB(1); RB(1) = tmp;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    tmp = A; A = RB(0); RB(0) = tmp;
    A = RB(7);
    tmp = A; A = RB(0); RB(0) = tmp;
    A = 0x01;
    RB(0)++;
    goto L_953E;
    L_953E:
    if (--RB(0)) goto L_953C;
    A = ~A;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    L_9543:
    DPTR = 0x0694;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    f_94B2();
    return;
    L_953C:
    C = 0;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    L_950E:
    DPTR = 0x0694;
    A = XD(DPTR);
    DPTR = 0x6BDE;
    A = CD(DPTR + A);
    A ^= 0xED;
    if (A != 0) goto L_9529;
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    A = DIR(0x28);
    A &= 0x07;
    L_94D4:
    C = 0;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(6); RB(6) = tmp;
}

void f_94D7(void)
{
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(6); RB(6) = tmp;
    if (--RB(0)) goto L_94D4;
    RB(7) = A;
    A = RB(6);
    A &= RB(4);
    RB(6) = A;
    A = RB(7);
    A &= RB(5);
    A |= RB(6);
    if (A == 0) goto L_9543;
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    DPTR++;
    A = XD(DPTR);
    DPTR = 0x6BDE;
    A = CD(DPTR + A);
    RB(5) = A;
    RB(3) = 0x01;
    f_8F10();
    A = RB(7);
    if (A != 0) goto L_9543;
    DPTR = 0x0694;
    A = XD(DPTR);
    DPTR = 0x6BDE;
    A = CD(DPTR + A);
    A ^= 0xF3;
    if (A != 0) goto L_950E;
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    RB(0) = 0x96;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    goto L_9523;
    L_9523:
    RB(5) = A;
    RB(3) = 0x01;
    f_8F10();
    L_9529:
    f_9FD9();
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(0);
    tmp = A; A = RB(1); RB(1) = tmp;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    tmp = A; A = RB(0); RB(0) = tmp;
    A = RB(7);
    tmp = A; A = RB(0); RB(0) = tmp;
    A = 0x01;
    RB(0)++;
    goto L_953E;
    L_953E:
    if (--RB(0)) goto L_953C;
    A = ~A;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    L_9543:
    DPTR = 0x0694;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    f_94B2();
    return;
    L_953C:
    C = 0;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    L_950E:
    DPTR = 0x0694;
    A = XD(DPTR);
    DPTR = 0x6BDE;
    A = CD(DPTR + A);
    A ^= 0xED;
    if (A != 0) goto L_9529;
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    A = DIR(0x28);
    A &= 0x07;
    L_94D4:
    C = 0;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(6); RB(6) = tmp;
}

void f_9653(void)
{
    DPTR = 0x0687;
    A = XD(DPTR);
    RB(7) = A;
    f_9E97();
    if (C == 0) goto L_96C7;
    A = 0x8D;
    ADD8(RB(7));
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x01;
    if (A == 0) goto L_9682;
    RB(3) = 0x01;
    RB(5) = 0xF5;
    f_8F10();
    A = RB(7);
    if (A != 0) { f_96BE(); return; }
    f_9F57();
    A = 0xFE;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = 0x8D;
    ADD8(RB(7));
    RB(0) = A;
    A = 0x02;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_96BE();
    return;
    L_9682:
    f_9F57();
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x10;
    if (A == 0) { f_96BE(); return; }
    RB(3) = 0x01;
    RB(5) = 0xF4;
    f_8F10();
    A = RB(7);
    if (A != 0) { f_96BE(); return; }
    f_9F57();
    A = 0xEF;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = 0x8D;
    ADD8(RB(7));
    RB(0) = A;
    A = 0x20;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_9E30();
    f_9ED0();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0687;
    A = XD(DPTR);
    f_9E75();
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    L_96C7:
    return;
}

void f_968F(void)
{
    DIR(0x10) = RB(7);
    A = RB(7);
    if (A != 0) { f_96BE(); return; }
    f_9F57();
    A = 0xEF;
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = 0x8D;
    ADD8(RB(7));
    RB(0) = A;
    A = 0x20;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_9E30();
    f_9ED0();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0687;
    A = XD(DPTR);
    f_9E75();
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
}

void f_9698(void)
{
    A = RB(7);
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = 0x8D;
    ADD8(RB(7));
    RB(0) = A;
    A = 0x20;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    f_9E30();
    f_9ED0();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0687;
    A = XD(DPTR);
    f_9E75();
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
}

void f_96BE(void)
{
    DPTR = 0x0687;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    f_9653();
    return;
}

void f_96C8(void)
{
    if (BIT_RAM(0x63)) goto L_96CE;
    f_9769();
    return;
    L_96CE:
    BIT_SET(0x63, 0);
    RB(0) = 0xAD;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0x33;
    if (A != 0) goto L_96DA;
    f_9769();
    return;
    L_96DA:
    f_97E9();
    RB(0) = 0x80;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_96E5;
    f_9769();
    return;
    L_96E5:
    RB(0) = 0xA1;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    return;
}

void f_97E9(void)
{
    RB(0) = 0x80;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_97F5;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_97F5;
    f_90F9();
    L_97F5:
    RB(0) = 0xA1;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A == 0) goto L_97FB;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    L_97FB:
    return;
}

void f_97FC(void)
{
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(5);
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(6) = 0x01;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    f_9F9D();
}

void f_980C(void)
{
    A = RB(7);
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xBB);
    DPL = A;
    A = 0;
    ADDC8(0x6B);
    f_9EC3();
    A = XD(DPTR);
    A &= 0x08;
    if (A != 0) goto L_9823;
    f_98AF();
    return;
    L_9823:
    A = RB(1);
    A ^= 0x01;
    if (A != 0) goto L_9870;
    DPTR = 0x004D;
    XD(DPTR) = A;
    L_982C:
    DPTR = 0x004D;
    A = XD(DPTR);
    C = 0;
    f_9F42();
    if (C == 0) goto L_9870;
    A = RB(7);
    RB(5) = A;
    RB(4) = 0x00;
    A ^= 0x02;
    if (A != 0) goto L_9848;
    DPTR = 0x1606;
    A = XD(DPTR);
    A &= 0x20;
    if (A == 0) goto L_9863;
    goto L_9870;
    L_9870:
    A = RB(7);
    f_9E62();
    f_9EC7();
    A = 0x11;
    XD(DPTR) = A;
    A = RB(7);
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xBD);
    DPL = A;
    A = 0;
    ADDC8(0x6B);
    f_9EC3();
    A = XD(DPTR);
    RB(0) = 0x95;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = 0;
    RB(6) = A;
    f_9E74();
    RB(5) = A;
    A = RB(7);
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xC1);
    DPL = A;
    A = 0;
    ADDC8(0x6B);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(2) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(2);
    A = RB(5);
    XD(DPTR) = A;
    goto L_98B5;
    L_98B5:
    f_9F13();
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    return;
    L_9863:
    A = 0;
    DPTR = 0x200B;
    XD(DPTR) = A;
    DPTR = 0x004D;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_982C;
    L_9848:
    A = RB(5);
    A ^= 0x01;
    A |= RB(4);
    if (A != 0) goto L_9858;
    DPTR = 0x1606;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_9863;
    goto L_9870;
    L_9858:
    A = RB(7);
    if (A != 0) goto L_9863;
    DPTR = 0x1606;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_9870;
}

void f_98AF(void)
{
    if (((SFR_88 >> 7) & 1)) goto L_98B5;
    f_980C();
    return;
    L_98B5:
    f_9F13();
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    return;
}

void f_9A57(void)
{
    RB(6) = 0x01;
    RB(5) = DIR(0x32);
    A = RB(5);
    A ^= 0xF0;
    if (A != 0) goto L_9A69;
    BIT_SET(0x11, 1);
    BIT_SET(0x12, 0);
    RB(6)--;
    RB(7) = 0xF0;
    goto L_9A9E;
    L_9A9E:
    A = RB(6);
    if (A == 0) goto L_9AA5;
    BIT_SET(0x11, 0);
    BIT_SET(0x12, 0);
    L_9AA5:
    return;
    L_9A69:
    RB(5) = DIR(0x32);
    A = RB(5);
    A ^= 0x56;
    if (A != 0) goto L_9A7C;
    if (!BIT_RAM(0x11)) goto L_9A9E;
    BIT_SET(0x11, 0);
    BIT_SET(0x12, 1);
    RB(6) = A;
    RB(7) = 0x56;
    goto L_9A9E;
    L_9A7C:
    RB(5) = DIR(0x32);
    A = RB(5);
    A ^= 0xA4;
    if (A != 0) goto L_9A8C;
    if (!BIT_RAM(0x12)) goto L_9A9E;
    BIT_SET(0x13, 1);
    RB(7) = 0x11;
    goto L_9A9E;
    L_9A8C:
    RB(5) = DIR(0x32);
    A = RB(5);
    A ^= 0xA5;
    if (A != 0) goto L_9A9C;
    if (!BIT_RAM(0x12)) goto L_9A9E;
    BIT_SET(0x13, 0);
    RB(7) = 0x11;
    goto L_9A9E;
    L_9A9C:
    RB(7) = DIR(0x32);
}

void f_9B1B(void)
{
    A = 0;
    RB(6) = A;
    L_9B1D:
    A = RB(6);
    RB(5) = A;
    RB(4) = 0x00;
    f_9E97();
    if (C == 0) goto L_9B8D;
    A = 0x88;
    ADD8(RB(6));
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x40;
    if (A == 0) goto L_9B8A;
    A = RB(5);
    ADD8(0x01);
    RB(5) = A;
    A = RB(4);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(4) = A;
    RB(0) = 0x9C;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= RB(5);
    if (A != 0) goto L_9B3D;
    A = RB(4);
    L_9B3D:
    if (A == 0) goto L_9B8A;
    A = 0x88;
    ADD8(RB(6));
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x08;
    if (A != 0) goto L_9B8A;
    A = RB(7);
    RB(5) = A;
    RB(4) = 0x00;
    A ^= 0xED;
    if (A != 0) goto L_9B5A;
    A = 0xA2;
    ADD8(RB(6));
    RB(0) = A;
    A = 0x08;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    goto L_9B8A;
    L_9B8A:
    RB(6)++;
    goto L_9B1D;
    L_9B5A:
    A = RB(5);
    A ^= 0xF3;
    A |= RB(4);
    if (A != 0) goto L_9B6A;
    A = 0xA2;
    ADD8(RB(6));
    RB(0) = A;
    A = 0x04;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    goto L_9B8A;
    L_9B6A:
    A = RB(7);
    RB(5) = A;
    RB(4) = 0x00;
    A ^= 0xF4;
    if (A != 0) goto L_9B7C;
    A = 0xA2;
    ADD8(RB(6));
    RB(0) = A;
    A = 0x02;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    goto L_9B8A;
    L_9B7C:
    A = RB(5);
    A ^= 0xF5;
    A |= RB(4);
    if (A != 0) goto L_9B8A;
    A = 0xA2;
    ADD8(RB(6));
    RB(0) = A;
    A = 0x01;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    L_9B8D:
    return;
}

void f_9B8E(void)
{
    BIT_SET(0x63, 1);
    return;
}

void f_9BC2(void)
{
    RB(0) = 0xAD;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A ^= 0x33;
    if (A != 0) goto L_9BCB;
    BIT_SET(0x33, 1);
    L_9BCB:
    return;
}

void f_9BCC(void)
{
    RB(0) = 0x9C;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_9BDB;
    A = 0x88;
    f_9F96();
    A = RB(7);
    A++;
    RB(0) = 0x9C;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    L_9BDB:
    return;
}

void f_9BDC(void)
{
    RB(0) = 0x9B;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_9BE7;
    A = 0x88;
    ADD8(RB(7));
    f_9FA8();
    L_9BE7:
    return;
}

void f_9BE8(void)
{
    RB(0) = 0xAD;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x88;
    BIT_SET(0x33, 0);
    return;
}

void f_9CDD(void)
{
    RB(0) = 0x85;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
}

void f_9CE2(void)
{
    DPTR = 0x069C;
    A = RB(7);
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x069C;
    A = XD(DPTR);
    ADD8(0x88);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (A != 0) goto L_9CF8;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    return;
    L_9CF8:
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    A = 0;
    SFR_8D = A;
    SFR_8B = 0x01;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    L_9D0A:
    if (((SFR_88 >> 7) & 1)) goto L_9D51;
    if (!BIT_RAM(0x34)) goto L_9D0A;
    if (!BIT_RAM(0x60)) goto L_9D3E;
    BIT_SET(0x34, 0);
    BIT_SET(0x60, 0);
    RB(0) = 0x84;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xFF;
    DPTR = 0x069C;
    f_9E30();
    f_9ED0();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x069C;
    A = XD(DPTR);
    f_9E75();
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_9E2B();
    goto L_9D0A;
    L_9D3E:
    RB(0) = 0x84;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    BIT_SET(0x34, 0);
    BIT_SET(0x61, 0);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xFF;
    A = 0;
    RB(5) = A;
    f_8C90();
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    L_9D51:
    if (!((SFR_88 >> 7) & 1)) goto L_9D5A;
    DPTR = 0x069D;
    A = 0x01;
    XD(DPTR) = A;
    L_9D5A:
    f_9F13();
    DPTR = 0x069D;
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void f_9D63(void)
{
    DPTR = 0x069C;
    A = RB(7);
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    SFR_8D = 0x88;
    SFR_8B = 0x4F;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    L_9D7A:
    if (((SFR_88 >> 7) & 1)) goto L_9DAE;
    if (!BIT_RAM(0x34)) goto L_9D7A;
    if (!BIT_RAM(0x60)) goto L_9DAE;
    BIT_SET(0x34, 0);
    BIT_SET(0x60, 0);
    RB(0) = 0x84;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xFF;
    DPTR = 0x069C;
    f_9E30();
    f_9ED0();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x069C;
    A = XD(DPTR);
    f_9E75();
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_9E2B();
    goto L_9D7A;
    L_9DAE:
    f_9F13();
    return;
}

void f_9DB2(void)
{
    A = 0;
    RB(7) = A;
    DPTR = 0x170A;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_9DDA;
    DPTR = 0x1106;
    A = XD(DPTR);
    A &= 0x04;
    if (A == 0) goto L_9E25;
    DPTR = 0x1102;
    A = XD(DPTR);
    A &= 0x04;
    if (A != 0) goto L_9E25;
    DPTR = 0x1702;
    A = XD(DPTR);
    A ^= 0x17;
    if (A != 0) goto L_9E25;
    f_0169();
    RB(7) = 0x01;
    return;
    L_9E25:
    return;
    L_9DDA:
    DPTR = 0x1709;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_9E00;
    DPTR = 0x1106;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_9E25;
    DPTR = 0x1102;
    A = XD(DPTR);
    A &= 0x08;
    if (A != 0) goto L_9E25;
    DPTR = 0x1701;
    A = XD(DPTR);
    A ^= 0x17;
    if (A != 0) goto L_9E25;
    f_0290();
    RB(7) = 0x01;
    return;
    L_9E00:
    DPTR = 0x1708;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_9E25;
    DPTR = 0x1106;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_9E25;
    DPTR = 0x1102;
    A = XD(DPTR);
    A &= 0x10;
    if (A != 0) goto L_9E25;
    DPTR = 0x1700;
    A = XD(DPTR);
    A ^= 0x17;
    if (A != 0) goto L_9E25;
    f_02E9();
    RB(7) = 0x01;
}

void f_9E26(void)
{
    RB(0) = 0x9F;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
}

void f_9E2B(void)
{
    A = 0;
    RB(0) = 0xA0;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
}

void f_9E30(void)
{
    A = XD(DPTR);
    RB(7) = A;
}

void f_9E32(void)
{
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xB7);
    DPL = A;
    A = 0;
    ADDC8(0x6B);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(4);
    A = 0x17;
}

void f_9E4B(void)
{
    XD(DPTR) = A;
    A = RB(7);
}

void f_9E4D(void)
{
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xBF);
    DPL = A;
    A = 0;
    ADDC8(0x6B);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    return;
}

void f_9E5D(void)
{
    DPTR = 0x069B;
}

void f_9E60(void)
{
    A = XD(DPTR);
    RB(7) = A;
}

void f_9E62(void)
{
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xB7);
    DPL = A;
    A = 0;
    ADDC8(0x6B);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    return;
}

void f_9E72(void)
{
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
}

void f_9E75(void)
{
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xC3);
    DPL = A;
    A = 0;
    ADDC8(0x6B);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    return;
}

void f_9E85(void)
{
    A = 0;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
}

void f_9E87(void)
{
    RB(0) = 0x9E;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(0x8D);
}

void f_9E8C(void)
{
    RB(0) = A;
    A = 0;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
}

void f_9E8F(void)
{
    RB(0) = 0x9E;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(0x8D);
    RB(0) = A;
    return;
}

void f_9E97(void)
{
    C = 0;
    SUBB8(0x03);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_9E9F(void)
{
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xBD);
    DPL = A;
    A = 0;
    ADDC8(0x6B);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(2) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(2);
    A = RB(6);
    XD(DPTR) = A;
    DPL = RB(5);
    DPH = RB(4);
    A = 0x1C;
    XD(DPTR) = A;
    return;
}

void f_9EC3(void)
{
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
}

void f_9EC7(void)
{
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(4);
    return;
}

void f_9ED0(void)
{
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(6);
    return;
}

void f_9ED9(void)
{
    DPTR = 0x069A;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x11);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_9EED(void)
{
    A = 0x11;
}

void f_9EEF(void)
{
    XD(DPTR) = A;
    DPTR = 0x1102;
    A = 0x1C;
    XD(DPTR) = A;
    return;
}

void f_9EFE(void)
{
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    RB(5) = A;
    DPL = A;
    DPH = RB(4);
    A = 0x1D;
    XD(DPTR) = A;
    return;
}

void f_9F0B(void)
{
    A = 0x88;
    ADD8(RB(7));
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x80;
    return;
}

void f_9F13(void)
{
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((1) & 1) << 3);
    return;
}

void f_9F2B(void)
{
    A = 0x88;
    ADD8(RB(7));
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A &= 0x40;
    return;
}

void f_9F33(void)
{
    DPTR = 0x0693;
}

void f_9F36(void)
{
    A = XD(DPTR);
    RB(7) = A;
    RB(3) = 0x02;
    RB(5) = DIR(0x32);
    return;
}

void f_9F3D(void)
{
    RB(0) = 0xAE;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    C = 1;
}

void f_9F42(void)
{
    SUBB8(0x05);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_9F49(void)
{
    DPTR = 0x06A0;
    A = XD(DPTR);
    RB(7) = A;
    RB(0) = 0x87;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = 0x97;
    ADD8(RB(7));
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    return;
}

void f_9F57(void)
{
    DPTR = 0x0687;
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x8D);
    RB(0) = A;
    return;
}

void f_9F60(void)
{
    DPTR = 0x069E;
}

void f_9F63(void)
{
    A = XD(DPTR);
    RB(7) = A;
    ADD8(0x88);
    RB(0) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    return;
}

void f_9F6A(void)
{
    DPTR = 0x1638;
    A = XD(DPTR);
    A &= 0xFB;
    return;
}

void f_9F71(void)
{
    DPTR = 0x1639;
    A = XD(DPTR);
    A &= 0xFB;
    return;
}

void f_9F78(void)
{
    DPTR = 0x163A;
    A = XD(DPTR);
    A &= 0xFB;
    return;
}

void f_9F7F(void)
{
    DPTR = 0x163B;
    A = XD(DPTR);
    A &= 0xFB;
    return;
}

void f_9F86(void)
{
    DPTR = 0x163C;
    A = XD(DPTR);
    A &= 0xFB;
    return;
}

void f_9F8D(void)
{
    DPTR = 0x163D;
    A = XD(DPTR);
    A &= 0xFB;
    return;
}

void f_9F96(void)
{
    ADD8(RB(7));
    RB(0) = A;
    A = 0x10;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
}

void f_9F9D(void)
{
    SFR_8D = 0xA6;
    SFR_8B = 0x29;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    return;
}

void f_9FA8(void)
{
    RB(0) = A;
    A = 0x20;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    A = RB(7);
    A++;
    RB(0) = 0x9B;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    return;
}

void f_9FB3(void)
{
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0x01;
    return;
}

void f_9FBA(void)
{
    DPTR = 0x1708;
    A = XD(DPTR);
    A &= 0x04;
    return;
}

void f_9FC1(void)
{
    DPTR = 0x1709;
    A = XD(DPTR);
    A &= 0x04;
    return;
}

void f_9FC8(void)
{
    DPTR = 0x170A;
    A = XD(DPTR);
    A &= 0x04;
    return;
}

void f_9FCF(void)
{
    RB(0) = 0x9E;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(0x01);
    RB(7) = A;
    A = 0;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(6) = A;
    return;
}

void f_9FD9(void)
{
    RB(0) = 0x9E;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(0xA2);
    RB(0) = A;
    return;
}

void f_9FE0(void)
{
    A = 0;
    RB(7) = A;
    L_9FE2:
    A = RB(7);
    C = 0;
    SUBB8(0x69);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_A006;
    DPTR = 0x6BED;
    f_A074();
    RB(6) = A;
    DPTR = 0x6BEB;
    f_A074();
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(4);
    A = RB(6);
    XD(DPTR) = A;
    RB(7)++;
    goto L_9FE2;
    L_A006:
    return;
}

void f_A007(void)
{
    A = RB(7);
    ADD8(0xFE);
    if (A == 0) goto L_A01A;
    A--;
    if (A == 0) goto L_A021;
    ADD8(0x02);
    if (A != 0) goto L_A028;
    DPTR = 0x1807;
    A = 0x66;
    XD(DPTR) = A;
    return;
    L_A028:
    A = 0;
    DPTR = 0x1807;
    XD(DPTR) = A;
    return;
    L_A021:
    DPTR = 0x1807;
    A = 0xFF;
    XD(DPTR) = A;
    return;
    L_A01A:
    DPTR = 0x1807;
    A = 0xB3;
    XD(DPTR) = A;
    return;
}

void f_A032(void)
{
    A = 0;
    DPTR = 0x1D00;
    XD(DPTR) = A;
    DPTR = 0x1D01;
    A = 0x02;
    XD(DPTR) = A;
    DPTR = 0x1D0E;
    A = 0xA5;
    XD(DPTR) = A;
    DPTR = 0x1D0B;
    A = 0x03;
    XD(DPTR) = A;
    DPTR = 0x1D0D;
    A = 0xFF;
    XD(DPTR) = A;
    DPTR = 0x1D0A;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x1D28;
    XD(DPTR) = A;
    DPTR = 0x1D27;
    XD(DPTR) = A;
    return;
}

void f_A05D(void)
{
    A = 0;
    DPTR = 0x1D08;
    XD(DPTR) = A;
    DPTR = 0x1D07;
    A = 0x0F;
    XD(DPTR) = A;
    DPTR = 0x1D06;
    A = 0xFF;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x1D26;
    XD(DPTR) = A;
    return;
}

void f_A074(void)
{
    B = 0x03;
    A = RB(7);
    f_7A15();
    A = 0;
    A = CD(DPTR + A);
    return;
}

void f_A0A6(void)
{
    A++;
    if (A == 0) goto L_A0D3;
    DPTR = 0x1609;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    RB(7) = 0x02;
    f_2335();
    DPTR = 0x1609;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    DPTR = 0x88FA;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    return;
    L_A0D3:
    return;
}

void f_A0D4(void)
{
    f_A2CE();
    if (A != 0) goto L_A107;
    f_A2C7();
    if (A != 0) goto L_A0F3;
    DPTR = 0x8425;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_A0F3;
    DPTR = 0x1609;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x88F9;
    XD(DPTR) = A;
    return;
    L_A0F3:
    f_A2C7();
    if (A == 0) goto L_A107;
    DPTR = 0x8425;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_A107;
    DPTR = 0x1609;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    L_A107:
    return;
}

void f_A108(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    A = XD(DPTR);
    RB(7) = A;
    f_50B9();
    f_61FB();
    f_A772();
    f_57EA();
    f_B552();
    return;
}

void f_A11E(void)
{
    f_B517();
    f_D7B5();
    f_C082();
    f_DEA8();
    f_DE66();
    return;
}

void f_A12D(void)
{
    f_A2CE();
    if (A != 0) goto L_A135;
    f_3DC8();
    L_A135:
    f_2D50();
    f_2D55();
    f_A2CE();
    if (A != 0) goto L_A150;
    DPTR = 0x1603;
    A = XD(DPTR);
    A &= 0x20;
    DPTR = 0x1606;
    if (A == 0) goto L_A153;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    return;
    L_A153:
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    return;
    L_A150:
    DPTR = 0x1606;
}

void f_A158(void)
{
    f_57FE();
    f_582B();
    f_5854();
    f_6275();
    f_62B4();
    DPTR = 0x8490;
    A = XD(DPTR);
    A &= 0x04;
    if (A != 0) goto L_A172;
    f_3FAC();
    L_A172:
    return;
}

void f_A173(void)
{
    f_4AF6();
    return;
}

void f_A176(void)
{
    f_A0D4();
    return;
}

void f_A179(void)
{
    f_2D5A();
    f_2D5F();
    return;
}

void f_A17F(void)
{
    f_2D64();
    f_40F9();
    f_580A();
    return;
}

void f_A189(void)
{
    f_5387();
    f_5452();
    f_53F4();
    f_579F();
    return;
}

void f_A195(void)
{
    f_265A();
    A = RB(7);
    if (A == 0) goto L_A19E;
    f_26D2();
    L_A19E:
    return;
}

void f_A19F(void)
{
    f_2D69();
    return;
}

void f_A1A2(void)
{
    DPTR = 0x84E0;
    A = 0x04;
    XD(DPTR) = A;
    f_2D6E();
    f_2D73();
    return;
}

void f_A1AE(void)
{
    f_2D78();
    return;
}

void f_A1B1(void)
{
    f_2D7D();
    f_60A4();
    f_6363();
    return;
}

void f_A1BA(void)
{
    f_BD37();
    f_A28B();
    return;
}

void f_A1C2(void)
{
    f_C81C();
    return;
}

void f_A1CA(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x60;
    if (A == 0) goto L_A1DC;
    A = XD(DPTR);
    A ^= 0x50;
    if (A == 0) goto L_A1DC;
    A = XD(DPTR);
    A ^= 0x30;
    if (A != 0) goto L_A1DF;
    L_A1DC:
    RB(7) = 0x01;
    return;
    L_A1DF:
    A = 0;
    DPTR = 0x830E;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    RB(7) = A;
    return;
}

void f_A1E8(void)
{
    RB(7) = 0xFF;
    return;
}

void f_A1EB(void)
{
    DPTR = 0x1D0C;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_A1FA;
    DPTR = 0x1D01;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    L_A1FA:
    DPTR = 0x1605;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_A206;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    L_A206:
    return;
}

void f_A207(void)
{
    DPTR = 0x1605;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_A213;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    L_A213:
    return;
}

void f_A214(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x55;
    if (A == 0) goto L_A221;
    A = XD(DPTR);
    A ^= 0x66;
    if (A != 0) goto L_A245;
    L_A221:
    DPTR = 0x84E2;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_A23D;
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_A233;
    goto L_A245;
    L_A245:
    DPTR = 0x83FC;
    L_A248:
    A = 0x01;
    XD(DPTR) = A;
    L_A24B:
    DPTR = 0x83FC;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x83FD;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_A28A;
    DPTR = 0x83FC;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_A270;
    RB(7) = 0x09;
    f_D8B6();
    A = RB(7);
    if (A == 0) goto L_A26D;
    DPTR = 0x83FC;
    A = XD(DPTR);
    goto L_A286;
    L_A286:
    DPTR = 0x83FD;
    XD(DPTR) = A;
    L_A28A:
    return;
    L_A26D:
    A = 0;
    goto L_A286;
    L_A270:
    DPTR = 0x83FC;
    A = XD(DPTR);
    A ^= 0x02;
    if (A != 0) goto L_A28A;
    RB(7) = A;
    f_D8B6();
    A = RB(7);
    if (A == 0) goto L_A285;
    DPTR = 0x83FC;
    A = XD(DPTR);
    goto L_A286;
    L_A285:
    A = 0;
    L_A233:
    f_A2BB();
    DPTR = 0x83FC;
    if (C != 0) goto L_A240;
    goto L_A248;
    L_A240:
    A = 0x02;
    XD(DPTR) = A;
    goto L_A24B;
    L_A23D:
    DPTR = 0x83FC;
}

void f_A28B(void)
{
    f_A214();
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x55;
    if (A == 0) goto L_A29D;
    A = XD(DPTR);
    A ^= 0x66;
    if (A == 0) goto L_A29D;
    goto L_A2B4;
    L_A2B4:
    f_A1EB();
    return;
    L_A29D:
    DPTR = 0x84E2;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_A2B7;
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_A2AF;
    goto L_A2B4;
    L_A2AF:
    f_A2BB();
    if (C != 0) goto L_A2B7;
    L_A2B7:
    f_A207();
    return;
}

void f_A2BB(void)
{
    DPTR = 0x84E7;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x847C;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(7));
    return;
}

void f_A2C7(void)
{
    DPTR = 0x1609;
    A = XD(DPTR);
    A &= 0x02;
    return;
}

void f_A2CE(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    return;
}

void f_A2D5(void)
{
    DPTR = 0x844C;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_A2DF(void)
{
    A = 0x33;
    f_B32D();
    return;
}

void f_A2E5(void)
{
    A = 0x44;
    f_B32D();
    return;
}

void f_A2F0(void)
{
    DPTR = 0x814C;
    A = 0x22;
    XD(DPTR) = A;
    DPTR = 0x814D;
    A = 0x0A;
    XD(DPTR) = A;
    DPTR = 0x814E;
    A = 0x08;
    XD(DPTR) = A;
    return;
}

void f_A303(void)
{
    DPTR = 0x813C;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_A30F;
    XD(DPTR) = A;
    f_AC23();
    L_A30F:
    DPTR = 0x813D;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_A31B;
    XD(DPTR) = A;
    f_AD8D();
    L_A31B:
    DPTR = 0x813E;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_A327;
    XD(DPTR) = A;
    f_AF03();
    L_A327:
    return;
}

void f_A328(void)
{
    DPTR = 0x0694;
    A = RB(7);
    XD(DPTR) = A;
    f_B14B();
    f_B1D1();
    DPH = A;
    f_B0BB();
    A = XD(DPTR);
    DPTR = 0x0695;
    XD(DPTR) = A;
    A = RB(7);
    f_B0C7();
    A = XD(DPTR);
    if (A != 0) goto L_A347;
    f_A413();
    return;
    L_A347:
    f_B148();
    f_B337();
    f_B0BB();
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x32);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_A360;
    f_A400();
    return;
    L_A360:
    f_1904();
    DPTR = 0x0694;
    A = XD(DPTR);
    A--;
    if (A == 0) goto L_A398;
    A--;
    if (A == 0) goto L_A3B7;
    ADD8(0x02);
    if (A != 0) goto L_A3DD;
    f_B0ED();
    f_B2F3();
    f_B169();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    f_B0EB();
    f_B258();
    f_B1F6();
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_B0ED();
    DPTR = 0x6D30;
    f_7A15();
    f_A3DA();
    return;
    L_A3DD:
    f_B148();
    f_B222();
    f_B0BB();
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x0695;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    f_B27B();
    f_B0D2();
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0695;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(7));
    if (C != 0) { f_A400(); return; }
    A = 0;
    XD(DPTR) = A;
    L_A3B7:
    f_B0ED();
    f_B25E();
    f_B167();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    f_B0EB();
    f_B267();
    f_B1F4();
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_B0ED();
    f_B2A7();
    DPH = A;
    L_A398:
    f_B0ED();
    f_B15F();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    f_B0EB();
    f_B1EC();
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    f_B0ED();
    f_B29B();
    DPH = A;
    f_A3DA();
    return;
}

void f_A3DA(void)
{
    f_B1A2();
    f_B148();
    f_B222();
    f_B0BB();
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x0695;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    f_B27B();
    f_B0D2();
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0695;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(7));
    if (C != 0) { f_A400(); return; }
    A = 0;
    XD(DPTR) = A;
}

void f_A400(void)
{
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0694;
    f_B1CC();
    DPH = A;
    f_B0BB();
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_A413(void)
{
    f_B148();
    f_B337();
    f_B0BB();
    A = 0;
    XD(DPTR) = A;
    RB(6) = A;
    A = RB(7);
    A--;
    if (A == 0) goto L_A441;
    A--;
    if (A == 0) goto L_A45C;
    ADD8(0x02);
    if (A != 0) goto L_A473;
    f_B0ED();
    f_B2F3();
    f_B0E1();
    f_B258();
    A = 0;
    A = CD(DPTR + A);
    RB(5) = A;
    A = RB(7);
    A &= RB(5);
    if (A == 0) goto L_A473;
    RB(6) = 0x01;
    goto L_A473;
    L_A473:
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    if (A != 0) goto L_A4A7;
    DPTR = 0x0695;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    f_B148();
    f_B280();
    DPH = A;
    f_B0BB();
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x0695;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(6));
    if (C != 0) goto L_A496;
    A = 0;
    XD(DPTR) = A;
    L_A496:
    DPTR = 0x0695;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    f_B1CD();
    DPH = A;
    f_B0BB();
    A = RB(6);
    XD(DPTR) = A;
    return;
    L_A4A7:
    f_B148();
    f_B222();
    f_B0BB();
    A = 0x01;
    XD(DPTR) = A;
    DPTR = 0x2121;
    f_B0FA();
    f_B0D4();
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x2127;
    f_B0B5();
    A = 0xFE;
    XD(DPTR) = A;
    A = RB(7);
    A--;
    if (A == 0) goto L_A540;
    A--;
    if (A != 0) goto L_A4D6;
    f_A5A3();
    return;
    L_A4D6:
    ADD8(0x02);
    if (A == 0) goto L_A4DD;
    f_A61A();
    return;
    L_A4DD:
    f_B0ED();
    f_B1C3();
    DPTR = 0x069B;
    XD(DPTR) = A;
    f_B0ED();
    DPTR = 0x6D28;
    f_7A15();
    f_B311();
    f_B0ED();
    DPTR = 0x6D27;
    f_7A15();
    f_B31A();
    f_B0ED();
    f_B17B();
    f_B112();
    f_B2CE();
    f_B0ED();
    DPTR = 0x6D32;
    f_7A15();
    f_B241();
    if (A == 0) goto L_A51C;
    f_A61A();
    return;
    L_A51C:
    f_B1D9();
    if (A != 0) goto L_A529;
    DPTR = 0x0050;
    f_B341();
    goto L_A539;
    L_A539:
    XD(DPTR) = A;
    DPTR = 0x0050;
    f_A607();
    return;
    L_A529:
    f_B0ED();
    f_B17B();
    f_B112();
    DPTR = 0x0050;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    L_A540:
    f_B0ED();
    f_B193();
    DPTR = 0x069B;
    XD(DPTR) = A;
    f_B0ED();
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE2);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
    f_B30F();
    f_B0ED();
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE1);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
    f_B318();
    f_B0ED();
    f_B108();
    f_B2CE();
    f_B0ED();
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xEC);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
    f_B23F();
    if (A == 0) goto L_A582;
    f_A61A();
    return;
    L_A582:
    f_B1D9();
    if (A != 0) goto L_A58F;
    DPTR = 0x0052;
    f_B341();
    goto L_A59C;
    L_A59C:
    XD(DPTR) = A;
    DPTR = 0x0052;
    f_A607();
    return;
    L_A58F:
    f_B0ED();
    f_B108();
    DPTR = 0x0052;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    L_A45C:
    f_B0ED();
    f_B25E();
    f_B0DF();
    f_B267();
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(5) = A;
    A = RB(7);
    A &= RB(5);
    if (A == 0) goto L_A473;
    RB(6) = 0x01;
    L_A441:
    f_B0ED();
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE6);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
    f_B0DF();
    f_B303();
    A = CD(DPTR + A);
    RB(5) = A;
    A = RB(7);
    A &= RB(5);
    if (A == 0) goto L_A473;
    RB(6) = 0x01;
    goto L_A473;
}

void f_A5A3(void)
{
    f_B0ED();
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    f_B1FD();
    DPTR = 0x069B;
    XD(DPTR) = A;
    f_B0ED();
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x64);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    f_B30F();
    f_B0ED();
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x63);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    f_B318();
    f_B0ED();
    f_B236();
    f_B110();
    f_B2CE();
    f_B0ED();
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x6E);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    f_B23F();
    if (A != 0) { f_A61A(); return; }
    f_B1D9();
    if (A != 0) goto L_A5F3;
    DPTR = 0x0054;
    f_B341();
    goto L_A603;
    L_A603:
    XD(DPTR) = A;
    DPTR = 0x0054;
    L_A5F3:
    f_B0ED();
    f_B236();
    f_B110();
    DPTR = 0x0054;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
}

void f_A607(void)
{
    f_B22C();
    RB(7) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    B = 0x15;
    DPTR = 0x212D;
    f_B0B8();
    A = RB(7);
    XD(DPTR) = A;
}

void f_A61A(void)
{
    DPTR = 0x069B;
    A = XD(DPTR);
    f_7A4A();
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = DIR(0x71);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = DIR(0x40);
    f_A0A6();
    return;
}

void f_A772(void)
{
    DPTR = 0x813B;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    C = 0;
    SUBB8(0x03);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_A783;
    A = 0;
    XD(DPTR) = A;
    L_A783:
    DPTR = 0x813B;
    A = XD(DPTR);
    RB(7) = A;
    f_A328();
    return;
}

void f_A78B(void)
{
    DPTR = 0x06AC;
    A = RB(7);
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    SFR_8D = 0xA6;
    SFR_8B = 0x29;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    f_B1CC();
    f_B0D2();
    A = XD(DPTR);
    DPTR = 0x06AD;
    XD(DPTR) = A;
}

void f_A7AD(void)
{
    DPTR = 0x06AC;
    f_B14B();
    f_B222();
    f_B0BB();
    A = XD(DPTR);
    if (A != 0) goto L_A7BF;
    f_A921();
    return;
    L_A7BF:
    A = RB(7);
    f_B321();
    f_B0D2();
    A = XD(DPTR);
    A ^= 0x01;
    if (A == 0) goto L_A7ED;
    DPTR = 0x06AC;
    A = XD(DPTR);
    f_B0B2();
    f_B0F5();
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    A = RB(6);
    A &= RB(7);
    if (A == 0) goto L_A836;
    DPTR = 0x06AC;
    A = XD(DPTR);
    B = 0x15;
    DPTR = 0x2131;
    f_B0B8();
    A = XD(DPTR);
    A &= RB(7);
    if (A == 0) goto L_A836;
    L_A7ED:
    DPTR = 0x06AC;
    f_B0B0();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    f_B0F5();
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    A = ~A;
    RB(5) = A;
    A = RB(6);
    A &= RB(5);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    DPTR = 0x06AC;
    A = XD(DPTR);
    RB(6) = A;
    B = 0x15;
    DPTR = 0x2131;
    f_B0B8();
    A = RB(7);
    XD(DPTR) = A;
    A = RB(6);
    f_B321();
    f_B0D2();
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x06AC;
    A = XD(DPTR);
    B = 0x0E;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xD6);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    DPH = A;
    f_B288();
    f_A7AD();
    return;
    L_A836:
    if (((SFR_88 >> 7) & 1)) goto L_A83C;
    f_A7AD();
    return;
    L_A83C:
    DPTR = 0x06AC;
    A = XD(DPTR);
    RB(7) = A;
    f_1904();
    DPTR = 0x06AC;
    A = XD(DPTR);
    A--;
    if (A == 0) goto L_A886;
    A--;
    if (A == 0) goto L_A8B8;
    ADD8(0x02);
    if (A == 0) goto L_A855;
    f_A8E9();
    return;
    L_A855:
    f_B2D7();
    DPTR = 0x6D2C;
    f_B0B8();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(6) = A;
    B = 0x0D;
    A = RB(7);
    f_B258();
    A = 0;
    A = CD(DPTR + A);
    A = ~A;
    RB(7) = A;
    A = RB(6);
    A &= RB(7);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    DPTR = 0x06AD;
    A = XD(DPTR);
    B = 0x0D;
    DPTR = 0x6D30;
    f_7A15();
    f_A8E6();
    return;
    L_A8B8:
    f_B2D7();
    f_B25E();
    DPH = A;
    f_B0BB();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    B = 0x0D;
    f_B267();
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    A = ~A;
    RB(7) = A;
    A = RB(6);
    A &= RB(7);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    DPTR = 0x06AD;
    A = XD(DPTR);
    f_B2A4();
    DPH = A;
    L_A886:
    f_B2D7();
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE6);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
    DPH = A;
    f_B0BB();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    B = 0x0D;
    f_B303();
    A = CD(DPTR + A);
    A = ~A;
    RB(7) = A;
    A = RB(6);
    A &= RB(7);
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    DPTR = 0x06AD;
    A = XD(DPTR);
    f_B298();
    DPH = A;
    f_A8E6();
    return;
}

void f_A8E6(void)
{
    f_B288();
}

void f_A8E9(void)
{
    DPTR = 0x06AC;
    f_B14B();
    f_B222();
    f_B0BB();
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x06AD;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    f_B27B();
    f_B0D2();
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x06AD;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(7));
    if (C != 0) goto L_A90F;
    A = 0;
    XD(DPTR) = A;
    L_A90F:
    DPTR = 0x06AD;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x06AC;
    f_B1CC();
    DPH = A;
    f_B0BB();
    A = RB(7);
    XD(DPTR) = A;
}

void f_A921(void)
{
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((1) & 1) << 3);
    return;
}

void f_A928(void)
{
    A = 0;
    DPTR = 0x1649;
    XD(DPTR) = A;
    DPTR = 0x164A;
    XD(DPTR) = A;
    DPTR = 0x16F1;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    return;
}

void f_A939(void)
{
    A = 0;
    DPTR = 0x0056;
    XD(DPTR) = A;
    DPTR = 0x0059;
    XD(DPTR) = A;
    DPTR = 0x005A;
    XD(DPTR) = A;
    DPTR = 0x005B;
    XD(DPTR) = A;
    DPTR = 0x007C;
    XD(DPTR) = A;
    DPTR = 0x007D;
    XD(DPTR) = A;
    f_A2F0();
    return;
}

void f_AC23(void)
{
    DPTR = 0x8149;
    A = XD(DPTR);
    if (A != 0) goto L_AC2C;
    f_AD2C();
    return;
    L_AC2C:
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0xFC;
    XD(DPTR) = A;
    DPTR = 0x1C00;
    A = XD(DPTR);
    A &= 0x7C;
    if (A == 0) goto L_AC48;
    A = XD(DPTR);
    A &= 0x18;
    if (A == 0) goto L_AC45;
    A = 0;
    RB(7) = A;
    f_1904();
    L_AC45:
    f_ACE8();
    return;
    L_AC48:
    f_B1BC();
    A ^= 0x07;
    if (A != 0) goto L_ACBB;
    DPTR = 0x1C00;
    A = XD(DPTR);
    A &= 0x82;
    if (A == 0) goto L_ACB9;
    DPTR = 0x8140;
    A = XD(DPTR);
    if (A != 0) goto L_AC92;
    f_B174();
    f_B112();
    DPTR = 0x0050;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x1C04;
    A = XD(DPTR);
    DPTR = 0x8140;
    f_B2C4();
    if (C != 0) goto L_AC7A;
    A = 0x20;
    XD(DPTR) = A;
    L_AC7A:
    DPTR = 0x8140;
    A = XD(DPTR);
    DPTR = 0x844C;
    XD(DPTR) = A;
    DPTR = 0x8140;
    A = XD(DPTR);
    DPTR = 0x0058;
    XD(DPTR) = A;
    f_B125();
    f_B348();
    goto L_ACA7;
    L_ACA7:
    DPTR = 0x8140;
    A = XD(DPTR);
    if (A == 0) goto L_ACAF;
    goto L_ACE0;
    L_ACE0:
    DPTR = 0x1C00;
    f_B2FC();
    goto L_AD28;
    L_AD28:
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    L_ACAF:
    DPTR = 0x1C01;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    f_AD1C();
    return;
    L_AC92:
    f_B209();
    f_B125();
    f_B348();
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_ACA7;
    DPTR = 0x1C01;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    L_ACB9:
    f_ACE8();
    return;
    L_ACBB:
    f_B1BC();
    A ^= 0x08;
    if (A != 0) goto L_ACED;
    DPTR = 0x1C00;
    A = XD(DPTR);
    A &= 0x82;
    if (A == 0) { f_ACE8(); return; }
    f_B348();
    A = XD(DPTR);
    if (A != 0) goto L_ACD3;
    f_AD1C();
    return;
    L_ACD3:
    f_B209();
    DPTR = 0x0050;
    f_B22C();
    DPTR = 0x1C06;
    XD(DPTR) = A;
    L_ACED:
    DPTR = 0x1C00;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_AD25;
    DPTR = 0x1C04;
    A = XD(DPTR);
    RB(7) = A;
    f_B174();
    f_B215();
    f_B1BC();
    A ^= 0x05;
    if (A != 0) { f_AD1C(); return; }
    f_B174();
    f_B112();
    f_B270();
    if (A != 0) goto L_AD13;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    L_AD13:
    DPTR = 0x1C05;
    f_B2E0();
    f_B131();
    L_AD25:
    DPTR = 0x814F;
}

void f_ACE8(void)
{
    DPTR = 0x814F;
    goto L_AD28;
    L_AD28:
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
}

void f_AD1C(void)
{
    DPTR = 0x814F;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    f_AD2C();
    return;
}

void f_AD2C(void)
{
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0x03;
    if (A == 0) goto L_AD8C;
    DPTR = 0x1C00;
    A = 0xFE;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8149;
    XD(DPTR) = A;
    DPTR = 0x8146;
    A = XD(DPTR);
    B = 0x0D;
    f_B2F3();
    f_B169();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8146;
    A = XD(DPTR);
    B = 0x0D;
    f_B258();
    f_B1F6();
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0x02;
    DPTR = 0x8146;
    if (A == 0) goto L_AD78;
    A = XD(DPTR);
    B = 0x0D;
    DPTR = 0x6D30;
    goto L_AD7F;
    L_AD7F:
    f_7A15();
    f_B1A2();
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0xFC;
    XD(DPTR) = A;
    L_AD8C:
    return;
    L_AD78:
    A = XD(DPTR);
    B = 0x0D;
    DPTR = 0x6D2E;
}

void f_AD8D(void)
{
    DPTR = 0x814A;
    A = XD(DPTR);
    if (A != 0) goto L_AD96;
    f_AEB3();
    return;
    L_AD96:
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0xF3;
    XD(DPTR) = A;
    DPTR = 0x1C11;
    A = XD(DPTR);
    A &= 0x7C;
    if (A == 0) goto L_ADB2;
    A = XD(DPTR);
    A &= 0x18;
    if (A == 0) goto L_ADAF;
    RB(7) = 0x01;
    f_1904();
    L_ADAF:
    f_AEAC();
    return;
    L_ADB2:
    f_B18C();
    A ^= 0x07;
    if (A == 0) goto L_ADBC;
    f_AE3F();
    return;
    L_ADBC:
    DPTR = 0x1C11;
    A = XD(DPTR);
    A &= 0x82;
    if (A == 0) goto L_AE3C;
    DPTR = 0x8141;
    A = XD(DPTR);
    if (A != 0) goto L_AE03;
    f_B101();
    DPTR = 0x0052;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x1C15;
    A = XD(DPTR);
    DPTR = 0x8141;
    f_B2C4();
    if (C != 0) goto L_ADE4;
    A = 0x20;
    XD(DPTR) = A;
    L_ADE4:
    DPTR = 0x8141;
    A = XD(DPTR);
    DPTR = 0x844C;
    XD(DPTR) = A;
    DPTR = 0x8141;
    A = XD(DPTR);
    DPTR = 0x0058;
    XD(DPTR) = A;
    DPTR = 0x1C17;
    A = XD(DPTR);
    DPTR = 0x0052;
    f_B12C();
    f_B34F();
    goto L_AE23;
    L_AE23:
    DPTR = 0x8141;
    A = XD(DPTR);
    if (A == 0) goto L_AE2F;
    f_B2F9();
    f_AEA6();
    return;
    L_AE2F:
    DPTR = 0x1C12;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    DPTR = 0x814F;
    f_AEA6();
    return;
    L_AE03:
    DPTR = 0x0052;
    f_B20C();
    DPTR = 0x1C17;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0052;
    f_B12D();
    f_B34F();
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_AE23;
    DPTR = 0x1C12;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    L_AE3C:
    f_AEAC();
    return;
}

void f_AE3F(void)
{
    f_B18C();
    A ^= 0x08;
    if (A != 0) goto L_AE71;
    DPTR = 0x1C11;
    A = XD(DPTR);
    A &= 0x82;
    if (A == 0) goto L_AE6E;
    f_B34F();
    A = XD(DPTR);
    if (A != 0) goto L_AE59;
    DPTR = 0x814F;
    goto L_AE6C;
    L_AE6C:
    f_AEA6();
    return;
    L_AE59:
    DPTR = 0x0052;
    f_B20C();
    DPTR = 0x0052;
    f_B22C();
    DPTR = 0x1C17;
    XD(DPTR) = A;
    f_B2F9();
    L_AE6E:
    f_AEAC();
    return;
    L_AE71:
    DPTR = 0x1C11;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) { f_AEAC(); return; }
    DPTR = 0x1C15;
    f_B2E9();
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE3);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
    f_B213();
    f_B18C();
    A ^= 0x05;
    if (A != 0) goto L_AEA3;
    f_B101();
    f_B270();
    if (A != 0) goto L_AE9A;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    L_AE9A:
    DPTR = 0x1C16;
    f_B2E0();
    f_B131();
    L_AEA3:
    DPTR = 0x814F;
}

void f_AEA6(void)
{
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    f_AEB3();
    return;
}

void f_AEAC(void)
{
    DPTR = 0x814F;
    A = XD(DPTR);
    A |= 0x08;
    XD(DPTR) = A;
}

void f_AEB3(void)
{
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0x0C;
    if (A == 0) goto L_AF02;
    DPTR = 0x1C11;
    A = 0xFE;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x814A;
    XD(DPTR) = A;
    f_B2EB();
    f_B15F();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    f_B2E9();
    f_B1EC();
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0x08;
    DPTR = 0x8147;
    if (A == 0) goto L_AEEC;
    A = XD(DPTR);
    f_B298();
    goto L_AEF8;
    L_AEF8:
    f_B1A0();
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0xF3;
    XD(DPTR) = A;
    L_AF02:
    return;
    L_AEEC:
    A = XD(DPTR);
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE8);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
}

void f_AF03(void)
{
    DPTR = 0x814B;
    A = XD(DPTR);
    if (A != 0) goto L_AF0C;
    f_B03C();
    return;
    L_AF0C:
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0xCF;
    XD(DPTR) = A;
    DPTR = 0x1C29;
    A = XD(DPTR);
    A &= 0x7C;
    if (A == 0) goto L_AF28;
    A = XD(DPTR);
    A &= 0x18;
    if (A == 0) goto L_AF25;
    RB(7) = 0x02;
    f_1904();
    L_AF25:
    f_B035();
    return;
    L_AF28:
    f_B183();
    f_B1FD();
    A ^= 0x07;
    if (A == 0) goto L_AF35;
    f_AFB8();
    return;
    L_AF35:
    DPTR = 0x1C29;
    A = XD(DPTR);
    A &= 0x82;
    if (A == 0) goto L_AFB5;
    DPTR = 0x8142;
    A = XD(DPTR);
    if (A != 0) goto L_AF83;
    f_B183();
    f_B237();
    f_B110();
    DPTR = 0x0054;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x1C2D;
    A = XD(DPTR);
    DPTR = 0x8142;
    f_B2C4();
    if (C != 0) goto L_AF63;
    A = 0x20;
    XD(DPTR) = A;
    L_AF63:
    DPTR = 0x8142;
    A = XD(DPTR);
    DPTR = 0x844C;
    XD(DPTR) = A;
    DPTR = 0x8142;
    A = XD(DPTR);
    DPTR = 0x0058;
    XD(DPTR) = A;
    DPTR = 0x1C2F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0054;
    f_B12D();
    f_B356();
    goto L_AFA3;
    L_AFA3:
    DPTR = 0x8142;
    A = XD(DPTR);
    if (A == 0) goto L_AFAB;
    goto L_AFE3;
    L_AFE3:
    DPTR = 0x1C29;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x1106;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    f_B03C();
    return;
    L_AFAB:
    DPTR = 0x1C2A;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    f_B02C();
    return;
    L_AF83:
    DPTR = 0x0054;
    f_B20C();
    DPTR = 0x1C2F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0054;
    f_B12D();
    f_B356();
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_AFA3;
    DPTR = 0x1C2A;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    L_AFB5:
    f_B035();
    return;
}

void f_AFB8(void)
{
    f_B183();
    f_B1FD();
    A ^= 0x08;
    if (A != 0) goto L_AFF6;
    DPTR = 0x1C29;
    A = XD(DPTR);
    A &= 0x82;
    if (A == 0) goto L_AFF3;
    f_B356();
    A = XD(DPTR);
    if (A != 0) goto L_AFD3;
    f_B02C();
    return;
    L_AFD3:
    DPTR = 0x0054;
    f_B20C();
    DPTR = 0x0054;
    f_B22C();
    DPTR = 0x1C2F;
    XD(DPTR) = A;
    DPTR = 0x1C29;
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x1106;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    f_B03C();
    return;
    L_AFF3:
    f_B035();
    return;
    L_AFF6:
    DPTR = 0x1C29;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) { f_B035(); return; }
    DPTR = 0x1C2D;
    f_B181();
    f_B237();
    f_B213();
    f_B183();
    f_B1FD();
    A ^= 0x05;
    if (A != 0) { f_B02C(); return; }
    f_B183();
    f_B237();
    f_B110();
    f_B270();
    if (A != 0) goto L_B023;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    L_B023:
    DPTR = 0x1C2E;
    f_B2E0();
    f_B131();
}

void f_B02C(void)
{
    DPTR = 0x814F;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    f_B03C();
    return;
}

void f_B035(void)
{
    DPTR = 0x814F;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
}

void f_B03C(void)
{
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0x30;
    if (A == 0) goto L_B091;
    DPTR = 0x1C29;
    A = 0xFE;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x814B;
    XD(DPTR) = A;
    f_B183();
    f_B25F();
    f_B167();
    STACK[++SP] = DPH;
    STACK[++SP] = DPL;
    f_B181();
    f_B268();
    f_B1F4();
    DPL = STACK[SP--];
    DPH = STACK[SP--];
    XD(DPTR) = A;
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0x20;
    DPTR = 0x8148;
    if (A == 0) goto L_B07B;
    A = XD(DPTR);
    f_B2A4();
    goto L_B087;
    L_B087:
    f_B1A0();
    DPTR = 0x814F;
    A = XD(DPTR);
    A &= 0xCF;
    XD(DPTR) = A;
    L_B091:
    return;
    L_B07B:
    A = XD(DPTR);
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x6A);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
}

void f_B092(void)
{
    DPTR = 0x813C;
    A = XD(DPTR);
    A ^= 0x01;
    if (A == 0) goto L_B0AA;
    DPTR = 0x813D;
    A = XD(DPTR);
    A ^= 0x01;
    if (A == 0) goto L_B0AA;
    DPTR = 0x813E;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_B0AD;
    L_B0AA:
    RB(7) = 0x01;
    return;
    L_B0AD:
    RB(7) = 0x00;
    return;
}

void f_B0B0(void)
{
    A = XD(DPTR);
    RB(7) = A;
}

void f_B0B2(void)
{
    DPTR = 0x212F;
}

void f_B0B5(void)
{
    B = 0x15;
}

void f_B0B8(void)
{
    f_7A15();
}

void f_B0BB(void)
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

void f_B0C7(void)
{
    B = 0x0E;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xD0);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
}

void f_B0D2(void)
{
    DPH = A;
}

void f_B0D4(void)
{
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(6);
    return;
}

void f_B0DF(void)
{
    DPH = A;
}

void f_B0E1(void)
{
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(4);
}

void f_B0EB(void)
{
    A = XD(DPTR);
    RB(7) = A;
}

void f_B0ED(void)
{
    DPTR = 0x0695;
    A = XD(DPTR);
    B = 0x0D;
    return;
}

void f_B0F5(void)
{
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x2133;
}

void f_B0FA(void)
{
    B = 0x15;
    A = RB(7);
    f_7A15();
    return;
}

void f_B101(void)
{
    DPTR = 0x8147;
    A = XD(DPTR);
    B = 0x0D;
}

void f_B108(void)
{
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE3);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
}

void f_B110(void)
{
    DPH = A;
}

void f_B112(void)
{
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    A = 0x01;
    A = CD(DPTR + A);
    return;
}

void f_B125(void)
{
    DPTR = 0x1C06;
    A = XD(DPTR);
    DPTR = 0x0050;
    RB(7) = A;
}

void f_B12D(void)
{
    A = XD(DPTR);
    RB(4) = A;
    DPTR++;
    A = XD(DPTR);
}

void f_B131(void)
{
    DPL = A;
    DPH = RB(4);
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_B148(void)
{
    DPTR = 0x0694;
}

void f_B14B(void)
{
    A = XD(DPTR);
    RB(7) = A;
    B = 0x0E;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    return;
}

void f_B15F(void)
{
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE6);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
}

void f_B167(void)
{
    DPH = A;
}

void f_B169(void)
{
    A = 0;
    A = CD(DPTR + A);
    RB(6) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(6);
    return;
}

void f_B174(void)
{
    DPTR = 0x8146;
    A = XD(DPTR);
    B = 0x0D;
}

void f_B17B(void)
{
    DPTR = 0x6D29;
    f_7A15();
    return;
}

void f_B181(void)
{
    A = XD(DPTR);
    RB(7) = A;
}

void f_B183(void)
{
    DPTR = 0x8148;
    A = XD(DPTR);
    B = 0x0D;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    return;
}

void f_B18C(void)
{
    DPTR = 0x8147;
    A = XD(DPTR);
    B = 0x0D;
}

void f_B193(void)
{
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE0);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    return;
}

void f_B1A0(void)
{
    DPH = A;
}

void f_B1A2(void)
{
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

void f_B1BC(void)
{
    DPTR = 0x8146;
    A = XD(DPTR);
    B = 0x0D;
}

void f_B1C3(void)
{
    DPTR = 0x6D26;
    f_7A15();
    A = 0;
    A = CD(DPTR + A);
    return;
}

void f_B1CD(void)
{
    B = 0x0E;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
}

void f_B1D1(void)
{
    ADD8(0xCA);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    return;
}

void f_B1D9(void)
{
    DPTR = 0x0697;
    A = XD(DPTR);
    A ^= 0x01;
    return;
}

void f_B1EC(void)
{
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE5);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
}

void f_B1F4(void)
{
    DPH = A;
}

void f_B1F6(void)
{
    A = 0;
    A = CD(DPTR + A);
    A = ~A;
    RB(6) = A;
    A = RB(7);
    A &= RB(6);
    return;
}

void f_B1FD(void)
{
    ADD8(0x62);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    return;
}

void f_B209(void)
{
    DPTR = 0x0050;
}

void f_B20C(void)
{
    A = 0;
    B = 0x01;
    f_77E5();
    return;
}

void f_B213(void)
{
    DPH = A;
}

void f_B215(void)
{
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(4);
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_B222(void)
{
    ADD8(0xD0);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    DPH = A;
    return;
}

void f_B22C(void)
{
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    DPL = A;
    DPH = RB(6);
    A = XD(DPTR);
    return;
}

void f_B237(void)
{
    ADD8(0x65);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    return;
}

void f_B23F(void)
{
    DPH = A;
}

void f_B241(void)
{
    A = 0;
    A = CD(DPTR + A);
    DPTR = 0x069A;
    XD(DPTR) = A;
    DPTR++;
    A = XD(DPTR);
    A ^= 0x08;
    return;
}

void f_B258(void)
{
    DPTR = 0x6D2B;
    f_7A15();
    return;
}

void f_B25F(void)
{
    ADD8(0x68);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    return;
}

void f_B268(void)
{
    ADD8(0x67);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    return;
}

void f_B270(void)
{
    RB(0) = 0xB7;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(0)--;
    return;
}

void f_B27B(void)
{
    A = RB(7);
    B = 0x0E;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
}

void f_B280(void)
{
    ADD8(0xD2);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    return;
}

void f_B288(void)
{
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

void f_B298(void)
{
    B = 0x0D;
}

void f_B29B(void)
{
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xEA);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
    return;
}

void f_B2A4(void)
{
    B = 0x0D;
}

void f_B2A7(void)
{
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x6C);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    return;
}

void f_B2C4(void)
{
    XD(DPTR) = A;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x20);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_B2CE(void)
{
    DPTR = 0x0698;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_B2D7(void)
{
    DPTR = 0x06AD;
    A = XD(DPTR);
    RB(7) = A;
    B = 0x0D;
    return;
}

void f_B2E0(void)
{
    A = XD(DPTR);
    RB(7) = A;
    RB(0) = 0xB7;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4) = A;
    RB(0)++;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    return;
}

void f_B2E9(void)
{
    A = XD(DPTR);
    RB(7) = A;
}

void f_B2EB(void)
{
    DPTR = 0x8147;
    A = XD(DPTR);
    B = 0x0D;
    return;
}

void f_B2F3(void)
{
    DPTR = 0x6D2C;
    f_7A15();
    return;
}

void f_B2F9(void)
{
    DPTR = 0x1C11;
}

void f_B2FC(void)
{
    A = 0xFE;
    XD(DPTR) = A;
    DPTR = 0x1105;
    return;
}

void f_B303(void)
{
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xE5);
    DPL = A;
    A = 0;
    ADDC8(0x6E);
    DPH = A;
    A = 0;
    return;
}

void f_B30F(void)
{
    DPH = A;
}

void f_B311(void)
{
    A = 0;
    A = CD(DPTR + A);
    DPTR = 0x0696;
    XD(DPTR) = A;
    return;
}

void f_B318(void)
{
    DPH = A;
}

void f_B31A(void)
{
    A = 0;
    A = CD(DPTR + A);
    DPTR = 0x0697;
    XD(DPTR) = A;
    return;
}

void f_B321(void)
{
    B = 0x0E;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xD4);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    return;
}

void f_B32D(void)
{
    DPTR = 0x007C;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x0056;
    XD(DPTR) = A;
    return;
}

void f_B337(void)
{
    ADD8(0xCC);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
    DPH = A;
    return;
}

void f_B341(void)
{
    A = 0x00;
    XD(DPTR) = A;
    DPTR++;
    A = 0x5C;
    return;
}

void f_B348(void)
{
    DPTR = 0x8140;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    return;
}

void f_B34F(void)
{
    DPTR = 0x8141;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    return;
}

void f_B356(void)
{
    DPTR = 0x8142;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    return;
}

void f_B36D(void)
{
    f_B622();
    if (A == 0) goto L_B37C;
    DPTR = 0x1500;
    A = XD(DPTR);
    A &= 0x10;
    if (A != 0) goto L_B37C;
    BIT_SET(0x6D, 1);
    L_B37C:
    return;
}

void f_B3E5(void)
{
    A = RB(7);
    f_7A4A();
    if (A != 0x0E) { C = (A < 0x0E); goto L_B36C; }
    if (A != 0x11) { C = (A < 0x11); goto L_B370; }
    if (A != 0x14) { C = (A < 0x14); goto L_B374; }
    if (A != 0x17) { C = (A < 0x17); goto L_B378; }
    if (A != 0x1A) { C = (A < 0x1A); goto L_B37C; }
    if (A != 0x1D) { C = (A < 0x1D); goto L_B381; }
    if (A != 0x20) { C = (A < 0x20); goto L_B385; }
    if (A != 0x23) { C = (A < 0x23); goto L_B38F; }
    if (A != 0x26) { C = (A < 0x26); goto L_B393; }
    if (A != 0x29) { C = (A < 0x29); goto L_B3DF; }
    if (A != 0x2C) { C = (A < 0x2C); goto L_B3E7; }
    if (A != 0x2F) { C = (A < 0x2F); goto L_B411; }
    C = !C;
    A &= RB(5);
    L_B411:
    f_B36D();
    return;
    L_B3E7:
    RB(2) = 0x4A;
    L_B3DF:
    RB(7) = 0xF0;
    return;
    L_B393:
    ADD8(0xD2);
    DPL = A;
    A = 0;
    ADDC8(0x85);
    DPH = A;
    A = XD(DPTR);
    DIR(0x69) = A;
    DPTR = 0x85D1;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x09);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_B3B1;
    A = 0;
    XD(DPTR) = A;
    L_B3B1:
    f_B631();
    if (A != 0) goto L_B3B9;
    f_B629();
    L_B3B9:
    RB(7) = DIR(0x69);
    f_08CB();
    return;
    L_B38F:
    EC_UNSUPPORTED();
    if (A == 0) goto L_B3BE;
    A = XD(DPTR);
    L_B3BE:
    f_B629();
    return;
    L_B385:
    XD(DPTR) = A;
    return;
    L_B381:
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    A = XD(DPTR);
    A |= 0x01;
    L_B37C:
    return;
    L_B378:
    if (A != 0) goto L_B37C;
    BIT_SET(0x6D, 1);
    L_B374:
    A = XD(DPTR);
    A &= 0x10;
    L_B370:
    if (A == 0) goto L_B37C;
    DPTR = 0x1500;
    L_B36C:
    return;
}

void f_B431(void)
{
    RB(7) = 0x01;
    f_098A();
    return;
}

void f_B436(void)
{
    A = 0;
    DPTR = 0x85D0;
    XD(DPTR) = A;
    DPTR = 0x85D1;
    XD(DPTR) = A;
    DPTR = 0x85E0;
    XD(DPTR) = A;
    DPTR = 0x85E1;
    XD(DPTR) = A;
    f_B629();
    BIT_SET(0x6D, 0);
    return;
}

void f_B44D(void)
{
    DPTR = 0x069B;
    A = RB(7);
    XD(DPTR) = A;
    DPTR++;
    A = RB(5);
    XD(DPTR) = A;
    f_B622();
    if (A != 0) goto L_B45D;
    f_B4EF();
    return;
    L_B45D:
    DPTR = 0x069C;
    A = XD(DPTR);
    RB(7) = A;
    RB(6) = 0x00;
    if (A == 0) goto L_B46A;
    A ^= 0x01;
    if (A != 0) goto L_B4AD;
    L_B46A:
    A = RB(7);
    A |= RB(6);
    if (A != 0) goto L_B47C;
    DPTR = 0x85E1;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x85E0;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_B47C;
    goto L_B4A5;
    L_B4A5:
    DPTR = 0x069B;
    A = XD(DPTR);
    RB(7) = A;
    f_B4F0();
    return;
    L_B47C:
    DPTR = 0x1500;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_B48C;
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_B4AD;
    L_B48C:
    DPTR = 0x069C;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_B4A5;
    DPTR = 0x85E1;
    A = XD(DPTR);
    if (A != 0) goto L_B49E;
    A = 0x07;
    XD(DPTR) = A;
    return;
    L_B49E:
    DPTR = 0x85E1;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    return;
    L_B4AD:
    DPTR = 0x85D0;
    A = XD(DPTR);
    DIR(0x69) = A;
    DPTR = 0x069B;
    A = XD(DPTR);
    RB(7) = A;
    RB(6) = DIR(0x69);
    A = 0xD2;
    ADD8(RB(6));
    DPL = A;
    A = 0;
    ADDC8(0x85);
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    DIR(0x69)++;
    RB(7) = DIR(0x69);
    C = 0;
    A = RB(7);
    SUBB8(0x09);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_B4D7;
    A = 0;
    DIR(0x69) = A;
    L_B4D7:
    DPTR = 0x85D1;
    A = XD(DPTR);
    A ^= DIR(0x69);
    if (A == 0) goto L_B4E5;
    DPTR = 0x85D0;
    A = DIR(0x69);
    XD(DPTR) = A;
    L_B4E5:
    DPTR = 0x1500;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    f_B431();
    return;
}

void f_B4F0(void)
{
    DPTR = 0x85E0;
    A = XD(DPTR);
    RB(6) = A;
    f_B63C();
    A = RB(7);
    XD(DPTR) = A;
    RB(6)++;
    A = RB(6);
    C = 0;
    SUBB8(0x08);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_B507;
    A = 0;
    RB(6) = A;
    L_B507:
    DPTR = 0x85E1;
    A = XD(DPTR);
    A ^= RB(6);
    if (A == 0) goto L_B516;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    DPTR = 0x85E0;
    A = RB(7);
    XD(DPTR) = A;
    L_B516:
    return;
}

void f_B517(void)
{
    f_B622();
    if (A == 0) goto L_B545;
    DPTR = 0x85E0;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x85E1;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_B545;
    A = XD(DPTR);
    f_B63C();
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x85E1;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x08);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_B540;
    A = 0;
    XD(DPTR) = A;
    L_B540:
    RB(5) = 0x01;
    f_B44D();
    L_B545:
    return;
}

void f_B546(void)
{
    f_B614();
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void f_B54C(void)
{
    f_B614();
    A = RB(5);
    XD(DPTR) = A;
    return;
}

void f_B552(void)
{
    DPTR = 0x8428;
    A = XD(DPTR);
    if (A == 0) goto L_B59A;
    DPTR = 0x842A;
    A = XD(DPTR);
    A ^= 0x16;
    if (A != 0) goto L_B59A;
    DPTR = 0x8429;
    XD(DPTR) = A;
    DPTR = 0x8428;
    A = XD(DPTR);
    A &= 0x0F;
    XD(DPTR) = A;
    A = XD(DPTR);
    ADD8((A));
    ADD8(0xF4);
    DPL = A;
    A = 0;
    ADDC8(0x6F);
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
    A = RB(7);
    DPTR = 0x8429;
    if (A == 0) goto L_B592;
    A = 0x80;
    XD(DPTR) = A;
    goto L_B595;
    L_B595:
    A = 0;
    DPTR = 0x8428;
    XD(DPTR) = A;
    L_B59A:
    return;
    L_B592:
    A = 0x5A;
    XD(DPTR) = A;
}

void f_B59B(void)
{
    f_B646();
    DPTR = 0x06A3;
    f_B608();
    DPTR = 0x844C;
    A = XD(DPTR);
    DPTR = 0x06A6;
    XD(DPTR) = A;
    DPTR++;
    A = 0x01;
    XD(DPTR) = A;
    RB(5) = 0x94;
    A = 0;
    RB(7) = A;
    f_1D49();
    return;
}

void f_B5B7(void)
{
    f_B646();
    DPTR = 0x06A3;
    f_B608();
    RB(5) = 0x14;
    A = 0;
    RB(7) = A;
    f_1C14();
    return;
}

void f_B5C7(void)
{
    f_B5FC();
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(5) = 0x08;
    RB(7) = A;
    f_1A4C();
    return;
}

void f_B5D3(void)
{
    f_B5FC();
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(5) = 0x0C;
    RB(7) = A;
    f_1A4C();
    return;
}

void f_B5DF(void)
{
    f_B5FC();
    DPTR++;
    A = 0x01;
    XD(DPTR) = A;
    RB(5) = 0x88;
    A = 0;
    RB(7) = A;
    f_1A4C();
    return;
}

void f_B5ED(void)
{
    f_B5FC();
    DPTR++;
    A = 0x01;
    XD(DPTR) = A;
    RB(5) = 0x8C;
    A = 0;
    RB(7) = A;
    f_1A4C();
    return;
}

void f_B5FC(void)
{
    DPTR = 0x842A;
    A = XD(DPTR);
    RB(3) = A;
    DPTR = 0x842B;
    A = XD(DPTR);
    DPTR = 0x069D;
}

void f_B608(void)
{
    XD(DPTR) = A;
    RB(6) = 0x84;
    DPTR++;
    A = 0x84;
    XD(DPTR) = A;
    DPTR++;
    A = 0x2C;
    XD(DPTR) = A;
    return;
}

void f_B614(void)
{
    A = 0x84;
    RB(0) = 0xB7;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(0)++;
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    DPL = A;
    DPH = 0x84;
    return;
}

void f_B622(void)
{
    DPTR = 0x83F3;
    A = XD(DPTR);
    A &= 0x01;
    return;
}

void f_B629(void)
{
    DPTR = 0x1500;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    return;
}

void f_B631(void)
{
    DPTR = 0x85D0;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x85D1;
    A = XD(DPTR);
    A ^= RB(7);
    return;
}

void f_B63C(void)
{
    ADD8(0xE2);
    DPL = A;
    A = 0;
    ADDC8(0x85);
    DPH = A;
    return;
}

void f_B646(void)
{
    DPTR = 0x842A;
    A = XD(DPTR);
    RB(3) = A;
    DPTR = 0x842B;
    A = XD(DPTR);
    return;
}

void f_B95E(void)
{
    A = 0;
    RB(7) = A;
    f_8968();
    DPTR = 0x1033;
    A = 0x03;
    XD(DPTR) = A;
    RB(3) = 0x4D;
    A = 0;
    RB(5) = A;
    RB(7) = A;
    f_8A24();
    A = RB(7);
    if (A == 0) goto L_B981;
    DPTR = 0x06B6;
    A = 0x4D;
    XD(DPTR) = A;
    A = 0;
    RB(3) = A;
    RB(5) = A;
    RB(7) = A;
    f_B91E();
    L_B981:
    DPTR = 0x1063;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_B98D;
    A = XD(DPTR);
    A &= 0xEF;
    XD(DPTR) = A;
    L_B98D:
    DPTR = 0x1063;
    A = XD(DPTR);
    A &= 0x80;
    if (A == 0) goto L_B999;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    L_B999:
    DPTR = 0x1058;
    A = XD(DPTR);
    A |= 0x40;
    XD(DPTR) = A;
    DPTR = 0x1063;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    return;
}

void f_B9A8(void)
{
    DPTR = 0x8525;
    A = XD(DPTR);
    if (A == 0) goto L_B9B1;
    f_BA81();
    return;
    L_B9B1:
    DPTR = 0x83BB;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_B9BC;
    f_BA81();
    return;
    L_B9BC:
    DPTR = 0x8520;
    A = XD(DPTR);
    ADD8((A));
    ADD8((A));
    ADD8(0xE0);
    RB(6) = A;
    DPTR = 0x8521;
    A = XD(DPTR);
    ADD8(RB(6));
    RB(3) = A;
    DPTR = 0x8522;
    A = XD(DPTR);
    DPTR = 0x06B6;
    XD(DPTR) = A;
    RB(5) = 0x01;
    f_B91E();
    DPTR = 0x8522;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A != 0) goto L_BA0A;
    DPTR = 0x8520;
    A = XD(DPTR);
    ADD8((A));
    ADD8((A));
    ADD8(0xE0);
    RB(3) = A;
    DPTR = 0x8521;
    A = XD(DPTR);
    A++;
    DPTR = 0x06B6;
    XD(DPTR) = A;
    RB(5) = 0x01;
    RB(7) = 0xF0;
    f_B91E();
    DPTR = 0x8521;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    DPTR = 0x8522;
    A = 0x08;
    XD(DPTR) = A;
    L_BA0A:
    DPTR = 0x8521;
    A = XD(DPTR);
    A ^= 0x04;
    if (A != 0) goto L_BA81;
    DPTR = 0x8520;
    A = XD(DPTR);
    ADD8((A));
    ADD8((A));
    ADD8(0xE0);
    RB(3) = A;
    A = 0;
    DPTR = 0x06B6;
    XD(DPTR) = A;
    RB(5) = 0x01;
    RB(7) = 0xF0;
    f_B91E();
    DPTR = 0x8520;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8521;
    XD(DPTR) = A;
    DPTR = 0x8520;
    A = XD(DPTR);
    A ^= 0x04;
    if (A != 0) goto L_BA3D;
    XD(DPTR) = A;
    L_BA3D:
    f_891E();
    DPTR = 0x8520;
    A = XD(DPTR);
    ADD8((A));
    ADD8((A));
    ADD8(0xE0);
    RB(3) = A;
    A = 0;
    DPTR = 0x06B6;
    XD(DPTR) = A;
    RB(5) = 0x01;
    RB(7) = 0xD7;
    f_8827();
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BA64;
    RB(7) = 0xB4;
    f_DB85();
    L_BA64:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BA71;
    RB(7) = 0x06;
    f_DB85();
    L_BA71:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BA81;
    DPTR = 0x8520;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_BA81:
    return;
}

void f_BA82(void)
{
    DPTR = 0x06B0;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    A = RB(3);
    XD(DPTR) = A;
    f_B9A8();
    DPTR = 0x06B0;
    A = XD(DPTR);
    RB(7) = A;
    f_B9A8();
    DPTR = 0x06B1;
    A = XD(DPTR);
    RB(7) = A;
    f_B9A8();
    DPTR = 0x06B2;
    A = XD(DPTR);
    RB(7) = A;
    f_B9A8();
    return;
}

void f_BAA6(void)
{
    A = 0;
    RB(7) = A;
    f_8968();
    A = 0;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A = 0x08;
    XD(DPTR) = A;
    RB(6) = 0x85;
    RB(7) = 0x00;
    DPTR++;
    A = 0x85;
    XD(DPTR) = A;
    DPTR++;
    A = 0x00;
    XD(DPTR) = A;
    A = 0;
    RB(3) = A;
    RB(5) = 0xE0;
    RB(7) = 0x01;
    f_8979();
    A = 0;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A = 0x08;
    XD(DPTR) = A;
    RB(6) = 0x85;
    RB(7) = 0x08;
    DPTR++;
    A = 0x85;
    XD(DPTR) = A;
    DPTR++;
    A = 0x08;
    XD(DPTR) = A;
    A = 0;
    RB(3) = A;
    RB(5) = 0xE4;
    RB(7) = 0x01;
    f_8979();
    A = 0;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A = 0x08;
    XD(DPTR) = A;
    RB(6) = 0x85;
    RB(7) = 0x10;
    DPTR++;
    A = 0x85;
    XD(DPTR) = A;
    DPTR++;
    A = 0x10;
    XD(DPTR) = A;
    A = 0;
    RB(3) = A;
    RB(5) = 0xE8;
    RB(7) = 0x01;
    f_8979();
    A = 0;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A = 0x08;
    XD(DPTR) = A;
    RB(6) = 0x85;
    RB(7) = 0x18;
    DPTR++;
    A = 0x85;
    XD(DPTR) = A;
    DPTR++;
    A = 0x18;
    XD(DPTR) = A;
    A = 0;
    RB(3) = A;
    RB(5) = 0xEC;
    RB(7) = 0x01;
    f_8979();
    A = 0;
    DPTR = 0x8520;
    XD(DPTR) = A;
    L_BB30:
    DPTR = 0x8520;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x04);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_BB57;
    A = XD(DPTR);
    B = 0x08;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x00);
    DPL = A;
    A = 0;
    ADDC8(0x85);
    DPH = A;
    A = XD(DPTR);
    A = ~A;
    if (A == 0) goto L_BB57;
    DPTR = 0x8520;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_BB30;
    L_BB57:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BB64;
    RB(7) = 0xB4;
    f_DB85();
    L_BB64:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BB71;
    RB(7) = 0x01;
    f_DB85();
    L_BB71:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BB81;
    DPTR = 0x8520;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_BB81:
    DPTR = 0x8520;
    A = XD(DPTR);
    A ^= 0x04;
    if (A != 0) goto L_BBE5;
    XD(DPTR) = A;
    f_891E();
    A = 0;
    DPTR = 0x06B6;
    XD(DPTR) = A;
    RB(3) = 0xE0;
    RB(5) = 0x01;
    RB(7) = 0xD7;
    f_8827();
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BBA8;
    RB(7) = 0xB4;
    f_DB85();
    L_BBA8:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BBB5;
    RB(7) = 0x02;
    f_DB85();
    L_BBB5:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BBC5;
    DPTR = 0x8520;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_BBC5:
    A = 0;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A = 0x08;
    XD(DPTR) = A;
    RB(6) = 0x85;
    RB(7) = 0x00;
    DPTR++;
    A = 0x85;
    XD(DPTR) = A;
    DPTR++;
    A = 0x00;
    XD(DPTR) = A;
    A = 0;
    RB(3) = A;
    RB(5) = 0xE0;
    RB(7) = 0x01;
    f_8979();
    L_BBE5:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BBF2;
    RB(7) = 0xB4;
    f_DB85();
    L_BBF2:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BBFF;
    RB(7) = 0x03;
    f_DB85();
    L_BBFF:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BC0F;
    DPTR = 0x8520;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_BC0F:
    A = 0;
    DPTR = 0x8521;
    XD(DPTR) = A;
    L_BC14:
    DPTR = 0x8521;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x04);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_BC4A;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8520;
    A = XD(DPTR);
    B = 0x08;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x01);
    DPL = A;
    A = 0;
    ADDC8(0x85);
    DPH = A;
    A = DPL;
    ADD8(RB(7));
    DPL = A;
    A = 0;
    ADDC8((DPH));
    DPH = A;
    A = XD(DPTR);
    A = ~A;
    if (A == 0) goto L_BC4A;
    DPTR = 0x8521;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_BC14;
    L_BC4A:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BC57;
    RB(7) = 0xB4;
    f_DB85();
    L_BC57:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BC64;
    RB(7) = 0x04;
    f_DB85();
    L_BC64:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BC74;
    DPTR = 0x8521;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_BC74:
    DPTR = 0x8520;
    A = XD(DPTR);
    ADD8((A));
    ADD8((A));
    ADD8(0xE0);
    RB(7) = A;
    DPTR = 0x8521;
    A = XD(DPTR);
    ADD8(RB(7));
    RB(5) = A;
    A = 0;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPTR++;
    A++;
    XD(DPTR) = A;
    DPTR++;
    A = 0;
    XD(DPTR) = A;
    RB(6) = 0x82;
    RB(7) = 0x00;
    DPTR++;
    A = 0x82;
    XD(DPTR) = A;
    DPTR++;
    A = 0x00;
    XD(DPTR) = A;
    A = 0;
    RB(3) = A;
    RB(7) = 0x01;
    f_8979();
    DPTR = 0x8522;
    A = 0x08;
    XD(DPTR) = A;
    L_BCA9:
    DPTR = 0x8522;
    A = XD(DPTR);
    if (A == 0) goto L_BCC5;
    A = XD(DPTR);
    ADD8(0x00);
    DPL = A;
    A = 0;
    ADDC8(0x82);
    DPH = A;
    A = XD(DPTR);
    A = ~A;
    if (A == 0) goto L_BCC5;
    DPTR = 0x8522;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_BCA9;
    L_BCC5:
    DPTR = 0x8522;
    A = XD(DPTR);
    A &= 0x03;
    DPTR = 0x8525;
    XD(DPTR) = A;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_BCE6;
    XD(DPTR) = A;
    RB(7) = 0x55;
    f_B9A8();
    RB(7) = 0x55;
    f_B9A8();
    RB(7) = 0x55;
    f_B9A8();
    goto L_BD09;
    L_BD09:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BD16;
    RB(7) = 0xB4;
    f_DB85();
    L_BD16:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BD23;
    RB(7) = 0x05;
    f_DB85();
    L_BD23:
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_BD33;
    DPTR = 0x8522;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_BD33:
    f_BD75();
    return;
    L_BCE6:
    DPTR = 0x8525;
    A = XD(DPTR);
    A ^= 0x02;
    if (A != 0) goto L_BCFB;
    XD(DPTR) = A;
    RB(7) = 0x55;
    f_B9A8();
    RB(7) = 0x55;
    f_B9A8();
    goto L_BD09;
    L_BCFB:
    DPTR = 0x8525;
    A = XD(DPTR);
    A ^= 0x03;
    if (A != 0) goto L_BD09;
    XD(DPTR) = A;
    RB(7) = 0x55;
    f_B9A8();
}

void f_BD37(void)
{
    DPTR = 0x8525;
    A = XD(DPTR);
    A ^= 0xAA;
    if (A != 0) goto L_BD74;
    DPTR = 0x8523;
    A = XD(DPTR);
    ADD8((A));
    ADD8((A));
    ADD8(0xE0);
    RB(7) = A;
    DPTR = 0x8524;
    A = XD(DPTR);
    ADD8(RB(7));
    RB(5) = A;
    A = 0;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPTR++;
    A++;
    XD(DPTR) = A;
    DPTR++;
    A = 0;
    XD(DPTR) = A;
    RB(6) = 0x82;
    RB(7) = 0x00;
    DPTR++;
    A = 0x82;
    XD(DPTR) = A;
    DPTR++;
    A = 0x00;
    XD(DPTR) = A;
    A = 0;
    RB(3) = A;
    RB(7) = 0x01;
    f_8979();
    DPTR = 0x8525;
    A = 0x55;
    XD(DPTR) = A;
    L_BD74:
    return;
}

void f_BD75(void)
{
    A = 0;
    DPTR = 0x0696;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A = 0x20;
    XD(DPTR) = A;
    RB(6) = 0x93;
    RB(7) = 0x00;
    DPTR++;
    A = 0x93;
    XD(DPTR) = A;
    DPTR++;
    A = 0x00;
    XD(DPTR) = A;
    A = 0;
    RB(3) = A;
    RB(5) = 0xF0;
    RB(7) = 0x01;
    f_8979();
    return;
}

void f_BDEC(void)
{
    A = 0;
    DPTR = 0x16F9;
    XD(DPTR) = A;
    DPTR = 0x16F7;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    DPTR = 0x201C;
    A = XD(DPTR);
    DPTR = 0x0693;
    XD(DPTR) = A;
    A = XD(DPTR);
    return;
}

void f_BE02(void)
{
    f_9FE0();
    f_A032();
    f_A05D();
    f_2DD2();
    f_BE47();
    f_A928();
    f_BE6F();
    f_A939();
    f_53BE();
    f_BF05();
    f_BF0E();
    f_C05A();
    f_B436();
    f_BDEC();
    RB(7) = 0x20;
    RB(6) = 0x4E;
    RB(5) = 0x00;
    RB(4) = 0x00;
    f_2CE2();
    f_BF0F();
    f_DBEE();
    DPTR = 0x91A2;
    A = XD(DPTR);
    A |= 0x40;
    XD(DPTR) = A;
    f_314B();
    return;
}

void f_BE47(void)
{
    A = 0;
    RB(7) = A;
    L_BE49:
    A = RB(7);
    C = 0;
    SUBB8(0x30);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_BE6E;
    A = RB(7);
    B = 0x03;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x14);
    DPL = A;
    A = 0;
    ADDC8(0x70);
    f_BFB4();
    ADD8(0x16);
    DPL = A;
    A = 0;
    ADDC8(0x70);
    f_BFD9();
    goto L_BE49;
    L_BE6E:
    return;
}

void f_BE6F(void)
{
    A = 0;
    RB(7) = A;
    L_BE71:
    A = RB(7);
    C = 0;
    SUBB8(0x1C);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_BE96;
    A = RB(7);
    B = 0x03;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xA4);
    DPL = A;
    A = 0;
    ADDC8(0x70);
    f_BFB4();
    ADD8(0xA6);
    DPL = A;
    A = 0;
    ADDC8(0x70);
    f_BFD9();
    goto L_BE71;
    L_BE96:
    return;
}

void f_BE97(void)
{
    DPTR = 0x8100;
    L_BE9A:
    RB(6) = DPH;
    C = 0;
    A = RB(6);
    SUBB8(0x98);
    if (C == 0) goto L_BEA7;
    A = 0;
    XD(DPTR) = A;
    DPTR++;
    goto L_BE9A;
    L_BEA7:
    return;
}

void f_BEBF(void)
{
    DPTR = 0x06B7;
    A = RB(4);
    XD(DPTR) = A;
    DPTR++;
    A = RB(5);
    XD(DPTR) = A;
    tmp = A; A = RB(3); RB(3) = tmp;
    A = RB(7);
    tmp = A; A = RB(3); RB(3) = tmp;
    A = RB(3);
    f_BF9C();
    A = 0x80;
    XD(DPTR) = A;
    DPTR = 0x06B7;
    A = XD(DPTR);
    RB(7) = A;
    A = RB(3);
    B = 0x06;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xFA);
    DPL = A;
    A = 0;
    ADDC8(0x70);
    f_BFCA();
    DPTR = 0x06B7;
    A = XD(DPTR);
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    A = RB(3);
    B = 0x06;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xFC);
    DPL = A;
    A = 0;
    ADDC8(0x70);
    f_BFCA();
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(3);
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    f_BF9C();
    A = 0;
    XD(DPTR) = A;
    return;
}

void f_BF0F(void)
{
    DPTR = 0x8300;
    A = 0x66;
    XD(DPTR) = A;
    f_BAA6();
    DPTR = 0x227C;
    A = XD(DPTR);
    A ^= 0x55;
    if (A != 0) goto L_BF55;
    DPTR++;
    A = XD(DPTR);
    A ^= 0xAA;
    if (A != 0) goto L_BF55;
    DPTR++;
    A = XD(DPTR);
    A ^= 0x55;
    if (A != 0) goto L_BF55;
    DPTR++;
    A = XD(DPTR);
    A ^= 0xAA;
    if (A != 0) goto L_BF55;
    DPTR = 0x227C;
    A = 0xEE;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    BIT_SET(0x02, 0);
    DPTR = 0x8303;
    A = 0;
    XD(DPTR) = A;
    DPTR++;
    A = 0xFA;
    XD(DPTR) = A;
    RB(7) = 0x03;
    f_5CF7();
    L_BF55:
    f_C3E2();
    DPTR = 0x83D8;
    A = 0x64;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x83D9;
    XD(DPTR) = A;
    DPTR = 0x83B3;
    A = XD(DPTR);
    A |= 0x08;
    XD(DPTR) = A;
    DPTR = 0x8421;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    DPTR = 0x83B0;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    RB(3) = A;
    RB(5) = 0x01;
    RB(7) = 0x70;
    f_BA82();
    DPTR = 0x8310;
    A = XD(DPTR);
    RB(3) = A;
    A = 0;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    RB(5) = 0x02;
    RB(7) = 0x70;
    f_BA82();
    return;
}

void f_BF96(void)
{
    f_BF05();
    f_A939();
    return;
}

void f_BF9C(void)
{
    B = 0x06;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xF8);
    DPL = A;
    A = 0;
    ADDC8(0x70);
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

void f_BFB4(void)
{
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
    return;
}

void f_BFCA(void)
{
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    RB(4) = A;
    A = 0x01;
    A = CD(DPTR + A);
    DPL = A;
    DPH = RB(4);
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_BFD9(void)
{
    DPH = A;
    A = 0;
    A = CD(DPTR + A);
    DPL = RB(5);
    DPH = RB(4);
    XD(DPTR) = A;
    RB(7)++;
    return;
}

void f_BFE4(void)
{
    DPTR = 0x1202;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    DPTR = 0x1204;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    DPTR = 0x1205;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    A = 0;
    RB(7) = A;
    RB(4) = 0x71;
    RB(5) = 0x10;
    L_BFFF:
    A = RB(7);
    C = 0;
    SUBB8(0x19);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_C044;
    A = 0;
    DPTR = 0x1200;
    XD(DPTR) = A;
    DPL = RB(5);
    DPH = RB(4);
    A = CD(DPTR + A);
    DPTR = 0x1201;
    XD(DPTR) = A;
    L_C017:
    DPTR = 0x1205;
    A = XD(DPTR);
    A &= 0x04;
    if (A != 0) goto L_C017;
    RB(5)++;
    if (RB(5) != 0x00) { C = (RB(5) < 0x00); goto L_C024; }
    RB(4)++;
    L_C024:
    DPTR = 0x1200;
    A = 0x01;
    XD(DPTR) = A;
    DPL = RB(5);
    DPH = RB(4);
    A = 0;
    A = CD(DPTR + A);
    DPTR = 0x1201;
    XD(DPTR) = A;
    L_C034:
    DPTR = 0x1205;
    A = XD(DPTR);
    A &= 0x04;
    if (A != 0) goto L_C034;
    RB(5)++;
    if (RB(5) != 0x00) { C = (RB(5) < 0x00); goto L_C041; }
    RB(4)++;
    L_C041:
    RB(7)++;
    goto L_BFFF;
    L_C044:
    DPTR = 0x1202;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    DPTR = 0x1204;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    DPTR = 0x1205;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    return;
}

void f_C05A(void)
{
    DPTR = 0x105B;
    A = 0x40;
    XD(DPTR) = A;
    DPTR = 0x105D;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    DPTR = 0x105A;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    DPTR = 0x105C;
    A = 0xA0;
    XD(DPTR) = A;
    DPTR = 0x105E;
    A = 0x04;
    XD(DPTR) = A;
    DPTR = 0x105A;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    return;
}

void f_C082(void)
{
    DPTR = 0x8180;
    A = XD(DPTR);
    f_7A4A();
    STACK[++SP] = SFR_AB;
    if (A == 0) goto L_C04D;
    EC_UNSUPPORTED();
    f_C3C0();
    return;
    L_C04D:
    A++;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    DPTR = 0x1205;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    return;
}

void f_C2D4(void)
{
    RB(7) = DIR(0x32);
    f_B546();
    f_14BF();
    return;
}

void f_C2DC(void)
{
    RB(7) = DIR(0x31);
    A = RB(7);
    A ^= 0x02;
    if (A != 0) goto L_C2E7;
    DIR(0x33) = DIR(0x32);
    return;
    L_C2E7:
    RB(5) = DIR(0x32);
    RB(7) = DIR(0x33);
    f_B54C();
    return;
}

void f_C2EF(void)
{
    DPTR = 0x0694;
    A = RB(6);
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    L_C2FA:
    f_C3D3();
    if (A != 0x24) { C = (A < 0x24); goto L_C303; }
    f_0A41();
    return;
    L_C303:
    f_C3D3();
    f_0A64();
    DPTR = 0x0694;
    A = 0;
    B = 0x01;
    f_77E5();
    DPTR = 0x0696;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x20);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_C2FA;
    return;
}

void f_C324(void)
{
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    A = DIR(0x32);
    ADD8(0xFE);
    if (A == 0) goto L_C33F;
    A--;
    if (A == 0) goto L_C345;
    A--;
    if (A == 0) goto L_C34C;
    ADD8(0x03);
    if (A != 0) goto L_C35E;
    RB(6) = 0x80;
    RB(7) = 0x2C;
    goto L_C349;
    L_C349:
    f_C2EF();
    return;
    L_C35E:
    return;
    L_C34C:
    DPTR = 0x803F;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    f_0A64();
    DPTR = 0x8040;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    f_0A41();
    L_C345:
    RB(6) = 0x80;
    RB(7) = 0x44;
    L_C33F:
    RB(6) = 0x80;
    RB(7) = 0x1D;
    goto L_C349;
}

void f_C35F(void)
{
    A = RB(7);
    ADD8(0x7F);
    if (A == 0) goto L_C36F;
    ADD8(0xA8);
    if (A == 0) goto L_C372;
    ADD8(0x59);
    if (A != 0) goto L_C375;
    f_C2D4();
    return;
    L_C375:
    return;
    L_C372:
    f_C324();
    L_C36F:
    f_C2DC();
    return;
}

void f_C376(void)
{
    A = RB(7);
    f_7A4A();
    C = 0;
    A = CD(DPTR + A);
    goto L_C341;
    L_C341:
    RB(7) = 0x1D;
    goto L_C349;
    L_C349:
    f_C2EF();
    return;
}

void f_C3A9(void)
{
    DPTR = 0x0698;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_C3AF(void)
{
    DPTR = 0x0698;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_C3B5(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_C3BB(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_C3C1(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_C3C7(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_C3CD(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_C3D3(void)
{
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    DPL = A;
    DPH = RB(6);
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    return;
}

void f_C3E2(void)
{
    DPTR = 0x803F;
    A = 0;
    A = CD(DPTR + A);
    DPTR = 0x8410;
    XD(DPTR) = A;
    DPTR = 0x8040;
    A = 0;
    A = CD(DPTR + A);
    DPTR = 0x8411;
    XD(DPTR) = A;
    DPTR = 0x8041;
    A = 0;
    A = CD(DPTR + A);
    DPTR = 0x8412;
    XD(DPTR) = A;
    DPTR = 0x8042;
    A = 0;
    A = CD(DPTR + A);
    DPTR = 0x8413;
    XD(DPTR) = A;
    return;
}

void f_C40F(void)
{
    DPTR = 0x1105;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    DPTR = 0x1101;
    A = 0x02;
    XD(DPTR) = A;
    DPTR = 0x813C;
    A--;
    XD(DPTR) = A;
    return;
}

void f_C422(void)
{
    DPTR = 0x1105;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    DPTR = 0x1101;
    A = 0x04;
    XD(DPTR) = A;
    DPTR = 0x813D;
    A = 0x01;
    XD(DPTR) = A;
    return;
}

void f_C43A(void)
{
    DPTR = 0x1105;
    A = XD(DPTR);
    A &= 0x7F;
    XD(DPTR) = A;
    DPTR = 0x1101;
    A = 0x80;
    XD(DPTR) = A;
    BIT_SET(0x3A, 1);
    return;
}

void f_C44A(void)
{
    DPTR = 0x1106;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    DPTR = 0x1102;
    A = 0x01;
    XD(DPTR) = A;
    DPTR = 0x813E;
    XD(DPTR) = A;
    return;
}

void f_C48E(void)
{
    DPTR = 0x1125;
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    DPTR = 0x1124;
    A = 0x08;
    XD(DPTR) = A;
    BIT_SET(0x3B, 1);
    return;
}

void f_C4CE(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    if (A != 0) goto L_C4E4;
    RB(7) = 0x32;
    f_5816();
    RB(7) = 0x32;
    f_583F();
    DPTR = 0x885C;
    A = XD(DPTR);
    L_C4E4:
    return;
}

void f_C4FB(void)
{
    RB(7) = 0xAA;
    f_DB85();
    RB(7) = 0x55;
    f_DB85();
    f_63BD();
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    if (A != 0) goto L_C57D;
    DPTR = 0x160A;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_C57D;
    DPTR = 0x1605;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    DPTR = 0x1608;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    DPTR = 0x1606;
    A = XD(DPTR);
    A &= 0xEF;
    XD(DPTR) = A;
    DPTR = 0x1605;
    A = XD(DPTR);
    A &= 0xEF;
    XD(DPTR) = A;
    DPTR = 0x1604;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    DPTR = 0x1605;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    DPTR = 0x1603;
    A = XD(DPTR);
    A &= 0x40;
    RB(7) = 0xAA;
    if (A == 0) goto L_C55C;
    f_DB85();
    RB(7) = 0x33;
    f_C57E();
    A = 0x03;
    XD(DPTR) = A;
    DPTR = 0x8300;
    goto L_C56B;
    L_C56B:
    XD(DPTR) = A;
    DPTR = 0x8310;
    A = XD(DPTR);
    RB(3) = A;
    A = 0;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    RB(5) = 0x01;
    RB(7) = 0x80;
    f_BA82();
    L_C57D:
    return;
    L_C55C:
    f_DB85();
    RB(7) = 0x34;
    f_C57E();
    A++;
    XD(DPTR) = A;
    DPTR = 0x8300;
    A = 0x05;
}

void f_C57E(void)
{
    f_DB85();
    DPTR = 0x8301;
    A = 0x01;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8305;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8310;
    return;
}

void f_C5A9(void)
{
    f_2B61();
    RB(7) = 0x02;
    f_8785();
    return;
}

void f_C5B2(void)
{
    A = RB(7);
    ADD8(0x24);
    if (A != 0) goto L_C5BA;
    f_C5A9();
    L_C5BA:
    return;
}

void f_C5BB(void)
{
    DPTR = 0x1510;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_C5ED;
    A = XD(DPTR);
    if (!((A >> 3) & 1)) goto L_C5D8;
    A = 0;
    DIR(0x3B) = A;
    DPTR = 0x1514;
    A = XD(DPTR);
    DIR(0x3A) = A;
    f_0612();
    RB(7) = DIR(0x3A);
    f_C5B2();
    return;
    L_C5D8:
    DPTR = 0x1514;
    A = XD(DPTR);
    DIR(0x3C) = A;
    f_0612();
    RB(7) = DIR(0x3B);
    A = RB(7);
    if (A == 0) goto L_C5ED;
    RB(7) = DIR(0x3A);
    f_C5B1();
    DIR(0x3B)--;
    L_C5ED:
    return;
}

void f_C5F4(void)
{
    DPTR = 0x069E;
    A = RB(7);
    XD(DPTR) = A;
    DPTR++;
    A = RB(5);
    XD(DPTR) = A;
    return;
}

void f_C7D5(void)
{
    SFR_D8 |= 0x01;
    SFR_D8 |= 0x02;
    L_C7DB:
    goto L_C7DB;
}

void f_C81C(void)
{
    DPTR = 0x1057;
    A = XD(DPTR);
    A ^= 0x18;
    if (A != 0) goto L_C896;
    DPTR = 0x1120;
    A = 0x08;
    XD(DPTR) = A;
    DPTR = 0x1058;
    A = 0x0F;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x85F2;
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((0) & 1) << 3);
    SFR_8D = A;
    SFR_8B = 0x01;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((1) & 1) << 6);
    L_C846:
    DPTR = 0x1120;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_C865;
    A = 0x08;
    XD(DPTR) = A;
    DPTR = 0x1058;
    A = 0x0F;
    XD(DPTR) = A;
    A = 0;
    SFR_8D = A;
    SFR_8B = 0x01;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    DPTR = 0x85F2;
    XD(DPTR) = A;
    goto L_C846;
    L_C865:
    if (!((SFR_88 >> 7) & 1)) goto L_C846;
    DPTR = 0x85F2;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    C = 0;
    SUBB8(0x23);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_C87C;
    A = 0xFF;
    XD(DPTR) = A;
    goto L_C886;
    L_C886:
    DPTR = 0x0045;
    A = 0x33;
    XD(DPTR) = A;
    SFR_88 = (SFR_88 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    SFR_A8 = (SFR_A8 & ~(1 << 3)) | (((1) & 1) << 3);
    f_0200();
    return;
    L_C87C:
    A = 0;
    SFR_8D = A;
    SFR_8B = 0x01;
    SFR_88 = (SFR_88 & ~(1 << 7)) | (((0) & 1) << 7);
    goto L_C846;
    L_C896:
    DPTR = 0x1120;
    A = 0x08;
    XD(DPTR) = A;
    DPTR = 0x1058;
    A = 0x0F;
    XD(DPTR) = A;
    DPTR = 0x1121;
    A = XD(DPTR);
    A |= 0x08;
    XD(DPTR) = A;
    return;
}

void f_C8CF(void)
{
    if (A != 0) goto L_C8D7;
    DPTR = 0x1511;
    A = 0xFA;
    XD(DPTR) = A;
    L_C8D7:
    DPTR = 0x0046;
    A = XD(DPTR);
    A ^= 0x64;
    if (A != 0) goto L_C8F6;
    DPTR = 0x1304;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_C8D7;
    A = XD(DPTR);
    A &= 0x08;
    if (A != 0) goto L_C8F1;
    DPTR = 0x130A;
    goto L_C92D;
    L_C92D:
    A = XD(DPTR);
    DPTR = 0x0083;
    XD(DPTR) = A;
    goto L_C8D7;
    L_C8F1:
    DPTR = 0x130A;
    goto L_C937;
    L_C937:
    A = XD(DPTR);
    DPTR = 0x0083;
    XD(DPTR) = A;
    L_C93C:
    DPTR = 0x0083;
    A = XD(DPTR);
    A ^= 0x55;
    if (A != 0) goto L_C94C;
    DPTR = 0x0045;
    A = 0x33;
    XD(DPTR) = A;
    goto L_C984;
    L_C984:
    A = 0;
    DPTR = 0x1648;
    XD(DPTR) = A;
    f_0200();
    return;
    L_C94C:
    DPTR = 0x0083;
    A = XD(DPTR);
    A ^= 0xAF;
    if (A != 0) goto L_C8D7;
    DPTR = 0x1036;
    XD(DPTR) = A;
    DPTR = 0x1121;
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    DPTR = 0x1120;
    A = 0x08;
    XD(DPTR) = A;
    DPTR = 0x164B;
    A = 0x80;
    XD(DPTR) = A;
    DPTR = 0x164C;
    XD(DPTR) = A;
    DPTR = 0x164D;
    XD(DPTR) = A;
    DPTR = 0x164E;
    XD(DPTR) = A;
    DPTR = 0x2011;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    SFR_D8 = (SFR_D8 & ~(1 << 0)) | (((1) & 1) << 0);
    SFR_D8 = (SFR_D8 & ~(1 << 1)) | (((1) & 1) << 1);
    L_C982:
    goto L_C982;
    L_C8F6:
    DPTR = 0x0046;
    A = XD(DPTR);
    A ^= 0x66;
    if (A != 0) goto L_C915;
    DPTR = 0x1500;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_C8D7;
    A = XD(DPTR);
    A &= 0x08;
    if (A != 0) goto L_C910;
    DPTR = 0x1504;
    goto L_C92D;
    L_C910:
    DPTR = 0x1504;
    goto L_C937;
    L_C915:
    DPTR = 0x0046;
    A = XD(DPTR);
    A ^= 0x6C;
    if (A != 0) goto L_C93C;
    DPTR = 0x1510;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_C8D7;
    A = XD(DPTR);
    A &= 0x08;
    if (A != 0) goto L_C934;
    DPTR = 0x1514;
    L_C934:
    DPTR = 0x1514;
}

void f_C98E(void)
{
    tmp = A; A = RB(5); RB(5) = tmp;
    A = RB(7);
    tmp = A; A = RB(5); RB(5) = tmp;
    DPTR = 0x2006;
    A = XD(DPTR);
    A &= 0x3F;
    XD(DPTR) = A;
    DPTR = 0x1E06;
    A = XD(DPTR);
    A ^= RB(5);
    if (A == 0) goto L_C9BD;
    tmp = A; A = RB(7); RB(7) = tmp;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x1E03;
    A = 0x01;
    XD(DPTR) = A;
    f_0600();
    SFR_87 = 0x02;
    L_C9BD:
    return;
}

void f_CA27(void)
{
    f_DA73();
    return;
}

void f_CA2B(void)
{
    DPTR = 0x8AD0;
    A = XD(DPTR);
    A ^= 0x05;
    if (A != 0) goto L_CA49;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A = XD(DPTR);
    RB(5) = A;
    RB(2) = 0x8A;
    RB(3) = 0xD4;
    RB(7) = 0x01;
    f_1F70();
    A = RB(7);
    DPTR = 0x8AD1;
    if (A == 0) goto L_CAA1;
    goto L_CA9C;
    L_CA9C:
    A = 0x80;
    XD(DPTR) = A;
    goto L_CAA4;
    L_CAA4:
    A = 0;
    DPTR = 0x8AD0;
    XD(DPTR) = A;
    return;
    L_CAA1:
    A = 0x5A;
    XD(DPTR) = A;
    L_CA49:
    DPTR = 0x8AD0;
    A = XD(DPTR);
    A ^= 0x0A;
    if (A != 0) goto L_CA7A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A = XD(DPTR);
    RB(3) = A;
    DPTR++;
    A = XD(DPTR);
    DPTR = 0x06A3;
    f_DB1D();
    DPTR = 0x8AF6;
    A = XD(DPTR);
    DPTR = 0x06A6;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(5) = 0x94;
    RB(7) = 0x01;
    f_1D49();
    A = RB(7);
    DPTR = 0x8AD1;
    if (A == 0) goto L_CA78;
    goto L_CA9C;
    L_CA78:
    goto L_CAA1;
    L_CA7A:
    DPTR = 0x8AD0;
    A = XD(DPTR);
    A ^= 0x0B;
    if (A != 0) goto L_CAA4;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A = XD(DPTR);
    RB(3) = A;
    DPTR++;
    A = XD(DPTR);
    DPTR = 0x06A3;
    f_DB1D();
    RB(5) = 0x14;
    RB(7) = 0x01;
    f_1C14();
    A = RB(7);
    DPTR = 0x8AD1;
    if (A == 0) goto L_CAA1;
}

void f_CEC3(void)
{
    DPTR = 0x8A98;
    A = XD(DPTR);
    f_7A4A();
    tmp = A; A = RB(7); RB(7) = tmp;
    A++;
    f_C8CF();
    return;
}

void f_CF88(void)
{
    f_DA73();
    DPTR = 0x83B3;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0x20;
    if (A == 0) goto L_CF9F;
    DPTR = 0x8A90;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_CF9F:
    f_D9DB();
    if (A == 0) goto L_CFAD;
    DPTR = 0x8A90;
    DPTR++;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_CFAD:
    f_D9DB();
    if (A == 0) goto L_CFBA;
    DPTR = 0x8A82;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_CFBA:
    f_D9DB();
    if (A == 0) goto L_CFC4;
    RB(7) = 0xAA;
    f_DB85();
    L_CFC4:
    return;
}

void f_CFC5(void)
{
    f_DB35();
    if (A != 0) goto L_CFCF;
    f_DB40();
    if (A == 0) goto L_D03F;
    L_CFCF:
    C = 0;
    DPTR = 0x8A8C;
    A = XD(DPTR);
    SUBB8(0x64);
    DPTR = 0x8A8B;
    A = XD(DPTR);
    SUBB8(0x00);
    if (C == 0) goto L_D03F;
    A = 0;
    B = 0x01;
    f_77E5();
    DPTR = 0x8A8B;
    A = XD(DPTR);
    if (A != 0) goto L_CFEF;
    DPTR++;
    A = XD(DPTR);
    A ^= 0x64;
    L_CFEF:
    if (A != 0) goto L_D03F;
    DPTR = 0x8A94;
    f_79E4();
    DPTR = 0x8A94;
    A = XD(DPTR);
    A &= 0x01;
    A |= 0x02;
    XD(DPTR) = A;
    f_D9DB();
    if (A == 0) goto L_D011;
    DPTR = 0x8A94;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_D011:
    f_D9DB();
    if (A == 0) goto L_D01E;
    DPTR = 0x8A95;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_D01E:
    f_D9DB();
    if (A == 0) goto L_D02B;
    DPTR = 0x8A96;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_D02B:
    f_D9DB();
    if (A == 0) goto L_D038;
    DPTR = 0x8A97;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_D038:
    RB(5) = 0x02;
    RB(7) = 0x79;
    f_B44D();
    L_D03F:
    return;
}

void f_D002(void)
{
    f_F012();
    return;
}

void f_D040(void)
{
    DPTR = 0x83F3;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_D04E;
    DPTR = 0x8A82;
    A++;
    XD(DPTR) = A;
    return;
    L_D04E:
    DPTR = 0x8A80;
    A = XD(DPTR);
    A ^= 0xE0;
    if (A != 0) goto L_D090;
    XD(DPTR) = A;
    DPTR = 0x8A98;
    A = XD(DPTR);
    RB(7) = A;
    if (A == 0) goto L_D090;
    f_D9DB();
    if (A == 0) goto L_D066;
    f_DB85();
    L_D066:
    f_D9DB();
    if (A == 0) goto L_D073;
    DPTR = 0x8A9A;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_D073:
    f_D9DB();
    if (A == 0) goto L_D080;
    DPTR = 0x8A9B;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    L_D080:
    f_D9DB();
    if (A == 0) goto L_D08A;
    RB(7) = 0xCD;
    f_DB85();
    L_D08A:
    DPTR = 0x8A82;
    A = 0x02;
    XD(DPTR) = A;
    L_D090:
    DPTR = 0x8A82;
    A = XD(DPTR);
    if (A == 0) goto L_D0BA;
    ADD8(0xFE);
    if (A == 0) goto L_D0A4;
    A--;
    if (A == 0) goto L_D0AE;
    ADD8(0x02);
    if (A != 0) goto L_D0BD;
    f_CF88();
    return;
    L_D0BD:
    return;
    L_D0AE:
    DPTR = 0x8A81;
    A = XD(DPTR);
    A ^= 0xE1;
    if (A != 0) goto L_D0BD;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    return;
    L_D0A4:
    f_CEC3();
    DPTR = 0x8A82;
    A = 0x03;
    XD(DPTR) = A;
    return;
    L_D0BA:
    f_CFC5();
}

void f_D0BE(void)
{
    A = 0;
    DPTR = 0x9100;
    XD(DPTR) = A;
    f_D986();
    f_1D49();
    RB(7) = 0x0A;
    f_230B();
    f_D9D2();
    f_1F70();
    return;
}

void f_D0D4(void)
{
    DPTR = 0x0695;
    f_DB5C();
    f_D986();
    f_1D49();
    A = RB(7);
    if (A != 0) goto L_D0E5;
    RB(7) = A;
    return;
    L_D0E5:
    A = 0;
    DPTR = 0x0695;
    XD(DPTR) = A;
    L_D0EA:
    DPTR = 0x0695;
    f_DAB4();
    if (C == 0) goto L_D11B;
    RB(7) = 0x05;
    f_230B();
    f_D9D2();
    f_1F70();
    A = RB(7);
    if (A == 0) goto L_D113;
    f_DA1A();
    A ^= 0x01;
    if (A != 0) goto L_D10A;
    RB(7) = 0x01;
    return;
    L_D10A:
    f_DA1A();
    A ^= 0x03;
    if (A != 0) goto L_D113;
    RB(7) = A;
    return;
    L_D113:
    DPTR = 0x0695;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_D0EA;
    L_D11B:
    RB(7) = 0x00;
    return;
}

void f_D11E(void)
{
    DPTR = 0x9053;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x32);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_D14E;
    DPTR = 0x9050;
    A = XD(DPTR);
    A |= 0x08;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    RB(7) = 0x01;
    f_1904();
    RB(7) = 0x14;
    f_230B();
    f_D0BE();
    A = 0;
    DPTR = 0x9053;
    XD(DPTR) = A;
    A = 0x64;
    f_DAE9();
    return;
    L_D14E:
    DPTR = 0x9053;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    DPTR = 0x9052;
    A = 0x0A;
    XD(DPTR) = A;
    return;
}

void f_D15B(void)
{
    f_D9D2();
    f_1F70();
    A = RB(7);
    if (A == 0) goto L_D182;
    f_DA1A();
    A ^= 0x01;
    if (A != 0) goto L_D172;
    f_DA0F();
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    return;
    L_D172:
    f_DA1A();
    A ^= 0x03;
    if (A != 0) goto L_D180;
    DPTR = 0x9051;
    A++;
    XD(DPTR) = A;
    goto L_D182;
    L_D182:
    f_D11E();
    return;
    L_D180:
    goto L_D182;
}

void f_D186(void)
{
    DPTR = 0x9051;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_D1AE;
    DPTR = 0x9100;
    A = 0xDA;
    XD(DPTR) = A;
    DPTR++;
    A = 0x0B;
    XD(DPTR) = A;
    DPTR++;
    A = 0x01;
    XD(DPTR) = A;
    f_D98D();
    f_1D49();
    A = RB(7);
    if (A == 0) goto L_D1AB;
    f_DA0F();
    DPTR++;
    XD(DPTR) = A;
    return;
    L_D1AB:
    f_D11E();
    L_D1AE:
    DPTR = 0x9051;
    A = XD(DPTR);
    A ^= 0x02;
    if (A != 0) goto L_D1B9;
    f_D15B();
    L_D1B9:
    return;
}

void f_D1BA(void)
{
    DPTR = 0x9051;
    A = XD(DPTR);
    A ^= 0x03;
    if (A != 0) goto L_D1DD;
    f_DAC7();
    DPTR++;
    A = 0x14;
    XD(DPTR) = A;
    A = 0x3A;
    f_D98D();
    f_1D49();
    A = RB(7);
    if (A == 0) goto L_D1DA;
    f_DA0F();
    DPTR++;
    XD(DPTR) = A;
    return;
    L_D1DA:
    f_D11E();
    L_D1DD:
    DPTR = 0x9051;
    A = XD(DPTR);
    A ^= 0x04;
    if (A != 0) goto L_D1E8;
    f_D15B();
    L_D1E8:
    DPTR = 0x9051;
    A = XD(DPTR);
    A ^= 0x05;
    if (A != 0) goto L_D206;
    f_D9A9();
    f_1C14();
    A = RB(7);
    if (A == 0) goto L_D203;
    f_DA5A();
    f_DA0F();
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    return;
    L_D203:
    f_D11E();
    L_D206:
    return;
}

void f_D2AB(void)
{
    DPTR = 0x9084;
    A = XD(DPTR);
    A &= 0x80;
    DPTR = 0x91A2;
    if (A == 0) goto L_D2BC;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    goto L_D2C0;
    L_D2C0:
    f_DB70();
    if (A == 0) goto L_D2F8;
    DPTR = 0x908B;
    A = XD(DPTR);
    A &= 0x20;
    DPTR = 0x91A2;
    if (A == 0) goto L_D2D6;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    goto L_D2DA;
    L_D2DA:
    DPTR = 0x9084;
    A = XD(DPTR);
    A &= 0x40;
    DPTR = 0x91A2;
    if (A == 0) goto L_D2EB;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    goto L_D2EF;
    L_D2EF:
    DPTR = 0x9089;
    A = XD(DPTR);
    A = (A << 4) | (A >> 4);
    A &= 0x07;
    goto L_D30D;
    L_D30D:
    DPTR = 0x91A0;
    XD(DPTR) = A;
    return;
    L_D2EB:
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    L_D2D6:
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    L_D2F8:
    f_DB77();
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x9180;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x9184;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x9188;
    XD(DPTR) = A;
    L_D2BC:
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
}

void f_D312(void)
{
    f_DB70();
    if (A != 0) goto L_D31A;
    f_D4B5();
    return;
    L_D31A:
    A = 0x83;
    f_DB16();
    XD(DPTR) = A;
    DPTR = 0x91A2;
    A = XD(DPTR);
    A &= 0x04;
    DPTR = 0x91A0;
    if (A != 0) goto L_D334;
    A = XD(DPTR);
    A = (A << 4) | (A >> 4);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    A &= 0xE0;
    A |= 0x03;
    goto L_D33B;
    L_D33B:
    DPTR = 0x9102;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x069F;
    XD(DPTR) = A;
    L_D344:
    DPTR = 0x069F;
    f_DABD();
    if (C == 0) goto L_D362;
    f_D98B();
    f_1D49();
    A = RB(7);
    if (A != 0) goto L_D362;
    RB(7) = 0x02;
    f_230B();
    DPTR = 0x069F;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_D344;
    L_D362:
    A = 0;
    DPTR = 0x069F;
    XD(DPTR) = A;
    L_D367:
    DPTR = 0x069F;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x19);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_D3A6;
    RB(7) = 0x04;
    f_230B();
    f_D9D2();
    f_1F70();
    RB(2) = 0x91;
    RB(1) = 0x40;
    tmp = A; A = RB(6); RB(6) = tmp;
    A = 0x91;
    tmp = A; A = RB(6); RB(6) = tmp;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = 0x40;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    A ^= 0x01;
    A |= RB(6);
    if (A == 0) goto L_D3A6;
    tmp = A; A = RB(6); RB(6) = tmp;
    tmp = A; A = RB(6); RB(6) = tmp;
    tmp = A; A = RB(7); RB(7) = tmp;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    A ^= 0x03;
    A |= RB(6);
    if (A != 0) goto L_D39E;
    f_D4B5();
    return;
    L_D39E:
    DPTR = 0x069F;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_D367;
    L_D3A6:
    RB(7) = 0x01;
    f_230B();
    f_D9A9();
    f_1C14();
    A = RB(7);
    if (A != 0) goto L_D3B7;
    f_D4B5();
    return;
    L_D3B7:
    f_DAAB();
    ADD8(0x3C);
    DPL = A;
    A = 0;
    ADDC8(0x91);
    DPH = A;
    A = XD(DPTR);
    DPTR = 0x9090;
    f_DAAA();
    ADD8(0x3D);
    DPL = A;
    A = 0;
    ADDC8(0x91);
    DPH = A;
    A = XD(DPTR);
    DPTR = 0x9091;
    f_DAAA();
    ADD8(0x3E);
    DPL = A;
    A = 0;
    ADDC8(0x91);
    DPH = A;
    A = XD(DPTR);
    DPTR = 0x9092;
    f_DAAA();
    ADD8(0x3F);
    DPL = A;
    A = 0;
    ADDC8(0x91);
    DPH = A;
    A = XD(DPTR);
    DPTR = 0x9093;
    XD(DPTR) = A;
    DPTR = 0x9091;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x9090;
    A = XD(DPTR);
    RB(5) = A;
    A = RB(5);
    RB(7) = A;
    A = RB(6);
    A &= 0x03;
    RB(6) = A;
    A = 0;
    RB(4) = A;
    RB(5) = A;
    DPTR = 0x0697;
    f_79D8();
    DPTR = 0x0697;
    f_79B0();
    A = 0;
    RB(3) = 0x0A;
    RB(2) = A;
    RB(1) = A;
    RB(0) = A;
    f_7808();
    DPTR = 0x0697;
    f_79D8();
    DPTR = 0x9092;
    A = XD(DPTR);
    A &= 0x0F;
    B = 0x40;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    RB(7) = A;
    RB(6) = B;
    DPTR = 0x9091;
    A = XD(DPTR);
    A &= 0xFC;
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    A &= 0x3F;
    RB(5) = A;
    A = RB(7);
    A |= RB(5);
    RB(7) = A;
    A = RB(6);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    SUBB8((A));
    RB(5) = A;
    RB(4) = A;
    f_DADD();
    A = 0;
    RB(3) = 0x32;
    RB(2) = A;
    RB(1) = A;
    RB(0) = A;
    f_7808();
    f_DADD();
    DPTR = 0x0697;
    f_79CC();
    f_7808();
    A = 0;
    RB(3) = 0xE8;
    RB(2) = 0x03;
    RB(1) = A;
    RB(0) = A;
    f_7893();
    DPTR = 0x0693;
    f_79D8();
    A = 0;
    RB(3) = 0xE8;
    RB(2) = 0x03;
    RB(1) = A;
    RB(0) = A;
    DPTR = 0x0693;
    f_79B0();
    f_7893();
    DPTR = 0x9188;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x91A2;
    A = XD(DPTR);
    A |= 0x40;
    XD(DPTR) = A;
    DPTR = 0x0697;
    f_79B0();
    DPTR = 0x9184;
    A = RB(6);
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    f_DAE3();
    DPTR = 0x9180;
    A = RB(6);
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x91A2;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    DPTR = 0x838A;
    A = 0x17;
    XD(DPTR) = A;
    DPTR++;
    A = 0x6F;
    XD(DPTR) = A;
    return;
    L_D334:
    A = XD(DPTR);
    A = (A << 4) | (A >> 4);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    A &= 0xE0;
    A |= 0x01;
}

void f_D4B6(void)
{
    f_DB70();
    if (A != 0) goto L_D4C3;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xEF;
    XD(DPTR) = A;
    L_D4C3:
    return;
}

void f_D4C4(void)
{
    DPTR = 0x1D0C;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_D4D5;
    DPTR = 0x9050;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    goto L_D4D8;
    L_D4D8:
    DPTR = 0x9050;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_D4E9;
    DPTR++;
    A = XD(DPTR);
    A ^= 0x0C;
    if (A != 0) goto L_D4E9;
    f_D5BB();
    return;
    L_D4E9:
    DPTR = 0x9052;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x00);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_D4FA;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    return;
    L_D4FA:
    DPTR = 0x9051;
    A = XD(DPTR);
    f_7A4A();
    if (--DIR(0x29)) goto L_D505;
    if (--DIR(0x29)) goto L_D509;
    if (--DIR(0x43)) goto L_D50D;
    if (--DIR(0x43)) goto L_D511;
    L_D50D:
    if (--DIR(0x43)) goto L_D515;
    if (--DIR(0x59)) goto L_D519;
    if (--DIR(0x59)) goto L_D51D;
    if (--DIR(0x6F)) goto L_D521;
    L_D519:
    if (--DIR(0x6F)) goto L_D525;
    if (--DIR(0x6F)) goto L_D529;
    if (--SFR_85) goto L_D52D;
    if (--SFR_BB) goto L_D531;
    L_D525:
    if (--SFR_AD) goto L_D53C;
    EC_UNSUPPORTED();
    DIR(0x12) = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    L_D52D:
    if (--RB(2)) goto L_D56B;
    if (A == 0) goto L_D536;
    L_D531:
    RB(7) = 0xB5;
    f_DB85();
    L_D536:
    f_DA3C();
    if (A != 0) goto L_D53E;
    f_D5BB();
    return;
    L_D53E:
    RB(7) = 0x01;
    f_D5AA();
    return;
    L_D56B:
    RB(7) = 0x03;
    f_D5AA();
    return;
    L_D53C:
    if (--SFR_BB) goto L_D5BE;
    f_D002();
    return;
    L_D5BE:
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_D5EF;
    DPTR = 0x83FB;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x28);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_D5E8;
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x66;
    if (A != 0) goto L_D5F4;
    DPTR = 0x1D01;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    DPTR = 0x1608;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    return;
    L_D5F4:
    return;
    L_D5E8:
    DPTR = 0x83FB;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    return;
    L_D5EF:
    A = 0;
    DPTR = 0x83FB;
    XD(DPTR) = A;
    L_D529:
    f_D186();
    f_DA3C();
    L_D521:
    RB(3)++;
    L_D51D:
    A ^= RB(7);
    RB(2)++;
    L_D515:
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    L_D511:
    A &= RB(1);
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    L_D509:
    A = (A >> 1) | (A << 7);
    L_D505:
    ADD8(RB(1));
    f_D543();
    return;
    L_D4D5:
    f_D5AD();
    return;
}

void f_D543(void)
{
    f_D1BA();
    f_DA3C();
    if (A == 0) goto L_D550;
    RB(7) = 0xB5;
    f_DB85();
    L_D550:
    f_DA3C();
    if (A == 0) goto L_D5BB;
    RB(7) = 0x02;
    f_D5AA();
    return;
    L_D5BB:
    return;
}

void f_D5AA(void)
{
    f_DB85();
    return;
}

void f_D5AD(void)
{
    f_DAED();
    DPTR++;
    A = 0x64;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x9050;
    XD(DPTR) = A;
    return;
}

void f_D5BC(void)
{
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_D5EF;
    DPTR = 0x83FB;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x28);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_D5E8;
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x66;
    if (A != 0) goto L_D5F4;
    DPTR = 0x1D01;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    DPTR = 0x1608;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    return;
    L_D5F4:
    return;
    L_D5E8:
    DPTR = 0x83FB;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    return;
    L_D5EF:
    A = 0;
    DPTR = 0x83FB;
    XD(DPTR) = A;
}

void f_D5F5(void)
{
    RB(5) = 0x18;
    f_D9D4();
    f_1F70();
    A = RB(7);
    if (A == 0) goto L_D60B;
    DPTR = 0x9140;
    A = XD(DPTR);
    A ^= 0xCC;
    if (A != 0) goto L_D60B;
    RB(7) = 0x01;
    return;
    L_D60B:
    RB(7) = 0x00;
    return;
}

void f_D60E(void)
{
    f_DAC6();
    f_DB66();
    f_D990();
    f_1D49();
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    L_D61F:
    DPTR = 0x0693;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x19);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_D643;
    RB(7) = 0x02;
    f_230B();
    f_D9D2();
    f_1F70();
    f_DA1A();
    A ^= 0x01;
    if (A == 0) goto L_D643;
    f_DB7E();
    goto L_D61F;
    L_D643:
    DPTR = 0x0693;
    A = XD(DPTR);
    A ^= 0x19;
    if (A != 0) goto L_D64D;
    RB(7) = A;
    return;
    L_D64D:
    RB(7) = 0x01;
    f_230B();
    f_D9A9();
    f_1C14();
    A = RB(7);
    if (A == 0) goto L_D67B;
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    L_D660:
    DPTR = 0x0693;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x0D);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_D67B;
    f_DB29();
    DPTR = 0x0693;
    f_DAF4();
    f_DB7E();
    goto L_D660;
    L_D67B:
    DPTR = 0x8A85;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x9080;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    DPTR = 0x8A85;
    XD(DPTR) = A;
    DPTR = 0x8A87;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x9081;
    A = XD(DPTR);
    RB(6) = A;
    A = RB(7);
    A |= RB(6);
    DPTR = 0x8A87;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8A8B;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    RB(7) = 0x01;
    f_230B();
    f_DAC6();
    DPTR = 0x9080;
    A = XD(DPTR);
    DPTR = 0x9102;
    XD(DPTR) = A;
    DPTR = 0x9081;
    A = XD(DPTR);
    DPTR = 0x9103;
    XD(DPTR) = A;
    DPTR = 0x9082;
    A = XD(DPTR);
    DPTR = 0x9104;
    XD(DPTR) = A;
    DPTR = 0x9083;
    A = XD(DPTR);
    DPTR = 0x9105;
    XD(DPTR) = A;
    DPTR++;
    A = 0x01;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x0694;
    XD(DPTR) = A;
    L_D6D3:
    DPTR = 0x0694;
    A = XD(DPTR);
    f_DABE();
    if (C == 0) goto L_D724;
    A = 0x0A;
    f_D9E5();
    A = 0x07;
    f_D99E();
    f_1D49();
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    L_D6EE:
    DPTR = 0x0693;
    A = XD(DPTR);
    C = 0;
    SUBB8(0xC8);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_D71C;
    RB(7) = 0x05;
    f_230B();
    f_D9D2();
    f_1F70();
    f_DA1A();
    A ^= 0x01;
    if (A != 0) goto L_D710;
    RB(7) = 0x01;
    return;
    L_D710:
    f_DA1A();
    A ^= 0x03;
    if (A == 0) goto L_D71C;
    f_DB7E();
    goto L_D6EE;
    L_D71C:
    DPTR = 0x0694;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_D6D3;
    L_D724:
    RB(7) = 0x00;
    return;
}

void f_D728(void)
{
    A = 0x99;
    f_DB16();
    f_D9E2();
    A = 0x02;
    f_D99E();
    f_1D49();
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    L_D73D:
    DPTR = 0x0693;
    A = XD(DPTR);
    f_DAB5();
    if (C == 0) goto L_D760;
    RB(7) = 0x05;
    f_230B();
    f_D9D2();
    f_1F70();
    f_DA1A();
    A ^= 0x01;
    if (A == 0) goto L_D760;
    DPTR = 0x0693;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_D73D;
    L_D760:
    RB(7) = 0x01;
    f_230B();
    f_D9A9();
    f_1C14();
    A = RB(7);
    if (A == 0) goto L_D771;
    f_D727();
    L_D771:
    return;
}

void f_D772(void)
{
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    L_D777:
    DPTR = 0x0693;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x03);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_D7B4;
    f_DAC6();
    DPTR++;
    A = 0x14;
    XD(DPTR) = A;
    DPTR = 0x06A3;
    A = 0x3A;
    f_D990();
    f_1D49();
    RB(7) = 0x05;
    f_230B();
    f_D9A9();
    f_1C14();
    A = RB(7);
    if (A == 0) goto L_D7A7;
    f_DA5A();
    L_D7A7:
    RB(7) = 0x05;
    f_230B();
    DPTR = 0x0693;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_D777;
    L_D7B4:
    return;
}

void f_D7B5(void)
{
    DPTR = 0x8AF7;
    A = XD(DPTR);
    if (A == 0) goto L_D7C9;
    f_CA2B();
    A = 0;
    DPTR = 0x9050;
    XD(DPTR) = A;
    A = 0xC8;
    f_DAE9();
    return;
    L_D7C9:
    f_D5BC();
    f_D4C4();
    DPTR = 0x9050;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_D81C;
    DPTR = 0x1609;
    A = XD(DPTR);
    A &= 0x40;
    if (A != 0) goto L_D807;
    f_D5F5();
    A = RB(7);
    if (A == 0) goto L_D807;
    f_D60E();
    A = RB(7);
    if (A == 0) goto L_D807;
    f_D2AB();
    f_D4B6();
    DPTR = 0x9080;
    A = XD(DPTR);
    A &= 0x40;
    if (A == 0) goto L_D7FC;
    f_D312();
    L_D7FC:
    DPTR = 0x9083;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_D807;
    f_D728();
    L_D807:
    f_D040();
    DPTR = 0x91A4;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_D81C;
    f_D772();
    DPTR = 0x91A4;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    L_D81C:
    return;
}

void f_D81D(void)
{
    A = RB(7);
    if (A == 0) goto L_D83D;
    f_DB77();
    if (A != 0) goto L_D863;
    f_DA43();
    DPTR++;
    A = 0x43;
    f_D98A();
    f_1D49();
    A = RB(7);
    if (A == 0) goto L_D858;
    DPTR = 0x91A2;
    A = XD(DPTR);
    A |= 0x40;
    XD(DPTR) = A;
    goto L_D858;
    L_D858:
    RB(7) = 0x06;
    f_230B();
    f_D9D2();
    f_1F70();
    L_D863:
    return;
    L_D83D:
    f_DB77();
    if (A == 0) goto L_D863;
    f_DA43();
    DPTR++;
    A = 0x40;
    f_D98A();
    f_1D49();
    A = RB(7);
    if (A == 0) goto L_D858;
    DPTR = 0x91A2;
    A = XD(DPTR);
    A &= 0xBF;
    XD(DPTR) = A;
}

void f_D864(void)
{
    A = 0;
    DPTR = 0x0697;
    XD(DPTR) = A;
    DPTR = 0x9100;
    A = 0xDD;
    XD(DPTR) = A;
    DPTR++;
    A = 0xDF;
    XD(DPTR) = A;
    DPTR++;
    A = 0x01;
    XD(DPTR) = A;
    A ^= RB(7);
    if (A != 0) goto L_D880;
    DPTR++;
    A = 0x04;
    XD(DPTR) = A;
    goto L_D885;
    L_D885:
    A = 0;
    DPTR = 0x0697;
    XD(DPTR) = A;
    L_D88A:
    DPTR = 0x0697;
    f_DABD();
    if (C == 0) goto L_D8B5;
    DPTR = 0x06A3;
    A = 0x18;
    f_D9E8();
    A = 0x04;
    f_D99E();
    f_1D49();
    A = RB(7);
    if (A != 0) goto L_D8B5;
    RB(7) = 0x05;
    f_230B();
    DPTR = 0x0697;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_D88A;
    L_D8B5:
    return;
    L_D880:
    A = 0;
    DPTR = 0x9103;
    XD(DPTR) = A;
}

void f_D8B6(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x9100;
    A = 0x1D;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x0693;
    A = XD(DPTR);
    DPTR = 0x9102;
    f_D98A();
    f_1D49();
    A = RB(7);
    if (A != 0) goto L_D8D9;
    RB(7) = A;
    return;
    L_D8D9:
    A = 0;
    DPTR = 0x0694;
    XD(DPTR) = A;
    L_D8DE:
    DPTR = 0x0694;
    f_DAB4();
    if (C == 0) goto L_D90F;
    RB(7) = 0x05;
    f_230B();
    f_D9D2();
    f_1F70();
    A = RB(7);
    if (A == 0) goto L_D907;
    f_DA1A();
    A ^= 0x01;
    if (A != 0) goto L_D8FE;
    f_D0D4();
    return;
    L_D8FE:
    f_DA1A();
    A ^= 0x03;
    if (A != 0) goto L_D907;
    RB(7) = A;
    return;
    L_D907:
    DPTR = 0x0694;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_D8DE;
    L_D90F:
    RB(7) = 0x00;
    return;
}

void f_D912(void)
{
    DPTR = 0x0697;
    f_DB5C();
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A++;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x0697;
    XD(DPTR) = A;
    L_D922:
    DPTR = 0x0697;
    f_DABD();
    if (C == 0) goto L_D943;
    f_D98B();
    f_1D49();
    A = RB(7);
    if (A != 0) goto L_D943;
    RB(7) = 0x05;
    f_230B();
    DPTR = 0x0697;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_D922;
    L_D943:
    A = 0;
    DPTR = 0x0697;
    XD(DPTR) = A;
    L_D948:
    DPTR = 0x0697;
    f_DAB4();
    if (C == 0) goto L_D985;
    RB(7) = 0x05;
    f_230B();
    f_D9D2();
    f_1F70();
    f_DA1A();
    A ^= 0x01;
    if (A != 0) goto L_D96C;
    RB(7) = 0x11;
    f_DB85();
    RB(7) = 0x12;
    f_DB85();
    return;
    L_D96C:
    f_DA1A();
    A ^= 0x03;
    if (A != 0) goto L_D97D;
    RB(7) = 0x11;
    f_DB85();
    RB(7) = 0x13;
    f_DB85();
    L_D97D:
    DPTR = 0x0697;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_D948;
    L_D985:
    return;
}

void f_D986(void)
{
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    A++;
    XD(DPTR) = A;
}

void f_D98B(void)
{
    A = 0x08;
}

void f_D98D(void)
{
    DPTR = 0x06A3;
}

void f_D990(void)
{
    XD(DPTR) = A;
    RB(6) = 0x91;
    DPTR++;
    A = 0x91;
    XD(DPTR) = A;
    A = 0x00;
    DPTR++;
    XD(DPTR) = A;
    A = 0x03;
    DPTR++;
}

void f_D99E(void)
{
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = 0xCC;
    RB(5) = 0x94;
    RB(7) = 0x01;
    return;
}

void f_D9A9(void)
{
    DPTR = 0x06A3;
    A = 0x80;
    XD(DPTR) = A;
    RB(6) = 0x91;
    DPTR++;
    A = 0x91;
    XD(DPTR) = A;
    A = 0x40;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = 0xCC;
    RB(5) = 0x14;
    RB(7) = 0x01;
    return;
}

void f_D9D2(void)
{
    RB(5) = 0xCC;
}

void f_D9D4(void)
{
    RB(2) = 0x91;
    RB(3) = 0x40;
    RB(7) = 0x01;
    return;
}

void f_D9DB(void)
{
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x20;
    return;
}

void f_D9E2(void)
{
    XD(DPTR) = A;
    A = 0x08;
}

void f_D9E5(void)
{
    DPTR = 0x06A3;
}

void f_D9E8(void)
{
    XD(DPTR) = A;
    RB(6) = 0x91;
    DPTR++;
    A = 0x91;
    XD(DPTR) = A;
    DPTR++;
    A = 0x00;
    XD(DPTR) = A;
    DPTR++;
    return;
}

void f_DA0F(void)
{
    DPTR = 0x9051;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    DPTR++;
    A = 0x01;
    XD(DPTR) = A;
    return;
}

void f_DA1A(void)
{
    DPTR = 0x9140;
    A = XD(DPTR);
    A &= 0x03;
    return;
}

void f_DA3C(void)
{
    DPTR = 0x83B3;
    A = XD(DPTR);
    A &= 0x10;
    return;
}

void f_DA43(void)
{
    A = 0x21;
    DPTR = 0x9100;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    return;
}

void f_DA5A(void)
{
    DPTR = 0x9143;
    A = XD(DPTR);
    DPTR = 0x9040;
    XD(DPTR) = A;
    DPTR = 0x9144;
    A = XD(DPTR);
    DPTR = 0x9041;
    XD(DPTR) = A;
    DPTR = 0x9145;
    A = XD(DPTR);
    DPTR = 0x9042;
    XD(DPTR) = A;
    return;
}

void f_DA73(void)
{
    A = 0x01;
    DPTR = 0x8A90;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8AC0;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8A82;
    XD(DPTR) = A;
    DPTR = 0x8A89;
    XD(DPTR) = A;
    return;
}

void f_DAAB(void)
{
    DPTR = 0x91A0;
    A = XD(DPTR);
    ADD8((A));
    ADD8((A));
    return;
}

void f_DAB5(void)
{
    C = 0;
    SUBB8(0x0A);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_DABE(void)
{
    C = 0;
    SUBB8(0x05);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_DAC7(void)
{
    DPTR = 0x9100;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    return;
}

void f_DADD(void)
{
    DPTR = 0x069B;
    f_79D8();
}

void f_DAE3(void)
{
    DPTR = 0x069B;
    f_79B0();
    return;
}

void f_DAE9(void)
{
    DPTR = 0x9052;
    XD(DPTR) = A;
}

void f_DAED(void)
{
    DPTR = 0x9051;
    A = 0x01;
    XD(DPTR) = A;
    return;
}

void f_DAF4(void)
{
    RB(7) = A;
    A = XD(DPTR);
    ADD8(0x80);
    DPL = A;
    A = 0;
    ADDC8(0x90);
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_DB16(void)
{
    DPTR = 0x9100;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    return;
}

void f_DB1D(void)
{
    XD(DPTR) = A;
    RB(6) = 0x8A;
    DPTR++;
    A = 0x8A;
    XD(DPTR) = A;
    DPTR++;
    A = 0xD4;
    XD(DPTR) = A;
    return;
}

void f_DB29(void)
{
    A = XD(DPTR);
    ADD8(0x40);
    DPL = A;
    A = 0;
    ADDC8(0x91);
    DPH = A;
    A = XD(DPTR);
    return;
}

void f_DB35(void)
{
    DPTR = 0x8AC0;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8A85;
    A = XD(DPTR);
    A &= RB(7);
    return;
}

void f_DB40(void)
{
    DPTR = 0x8AC1;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8A87;
    A = XD(DPTR);
    A &= RB(7);
    return;
}

void f_DB5C(void)
{
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x9100;
    A = 0x1F;
    XD(DPTR) = A;
    A = 0;
    return;
}

void f_DB66(void)
{
    DPTR++;
    A = 0x0D;
    XD(DPTR) = A;
    DPTR = 0x06A3;
    A = 0x09;
    return;
}

void f_DB70(void)
{
    DPTR = 0x91A2;
    A = XD(DPTR);
    A &= 0x01;
    return;
}

void f_DB77(void)
{
    DPTR = 0x91A2;
    A = XD(DPTR);
    A &= 0x40;
    return;
}

void f_DB7E(void)
{
    DPTR = 0x0693;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    return;
}

void f_DB85(void)
{
    RB(5) = 0xFF;
    RB(4) = 0x8F;
    DPL = RB(5);
    DPH = RB(4);
    A = XD(DPTR);
    RB(6) = A;
    tmp = A; A = RB(1); RB(1) = tmp;
    A = RB(6);
    tmp = A; A = RB(1); RB(1) = tmp;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    A = ~A;
    if (A != 0) goto L_DBC7;
    XD(DPTR) = A;
    DPTR = 0x06B3;
    A = 0x8F;
    XD(DPTR) = A;
    DPTR++;
    A = 0;
    XD(DPTR) = A;
    RB(6) = A;
    L_DBA4:
    A = RB(6);
    C = 0;
    SUBB8(0xFF);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_DBC7;
    DPTR = 0x06B3;
    A = XD(DPTR);
    RB(2) = A;
    DPTR++;
    A = XD(DPTR);
    DPL = A;
    DPH = RB(2);
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x06B3;
    B = 0x01;
    f_77E5();
    RB(6)++;
    goto L_DBA4;
    L_DBC7:
    tmp = A; A = RB(6); RB(6) = tmp;
    A = RB(1);
    tmp = A; A = RB(6); RB(6) = tmp;
    A = RB(6);
    ADD8(0x00);
    RB(5) = A;
    A = 0;
    ADDC8(0x8F);
    DPL = RB(5);
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void f_DBEE(void)
{
    DPTR = 0x8191;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    f_E4F3();
    DPTR = 0x8191;
    if (A != 0) goto L_DC03;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    goto L_DC07;
    L_DC07:
    A = 0;
    DPTR = 0x84EC;
    XD(DPTR) = A;
    DPTR = 0x8193;
    XD(DPTR) = A;
    DPTR = 0x8197;
    XD(DPTR) = A;
    DPTR = 0x81A4;
    A = 0xFF;
    XD(DPTR) = A;
    return;
    L_DC03:
    A = XD(DPTR);
    A &= 0x7F;
    XD(DPTR) = A;
}

void f_DC1B(void)
{
    f_E4FA();
    DPTR = 0x8420;
    A = XD(DPTR);
    A &= 0x08;
    DPTR = 0x8191;
    if (A == 0) goto L_DC2F;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    goto L_DC33;
    L_DC33:
    f_E474();
    DPTR = 0x8191;
    if (A == 0) goto L_DC46;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8424;
    XD(DPTR) = A;
    goto L_DC4A;
    L_DC4A:
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    if (A == 0) goto L_DC5C;
    A = XD(DPTR);
    A ^= 0x50;
    if (A == 0) goto L_DC5C;
    A = XD(DPTR);
    A ^= 0x30;
    if (A != 0) goto L_DC64;
    L_DC5C:
    DPTR = 0x8191;
    A = XD(DPTR);
    A |= 0x04;
    goto L_DC84;
    L_DC84:
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    L_DC89:
    DPTR = 0x8420;
    A = XD(DPTR);
    A &= 0x01;
    DPTR = 0x8191;
    if (A == 0) goto L_DCA0;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    DPTR = 0x8197;
    A = 0x01;
    XD(DPTR) = A;
    goto L_DCA9;
    L_DCA9:
    DPTR = 0x84E4;
    A = XD(DPTR);
    if (A != 0) goto L_DCB7;
    DPTR = 0x8191;
    A = XD(DPTR);
    A &= 0xDF;
    goto L_DCC5;
    L_DCC5:
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xBF;
    XD(DPTR) = A;
    goto L_DCD4;
    L_DCD4:
    f_E4F3();
    if (A != 0) goto L_DCFB;
    DPTR = 0x8191;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    DPTR = 0x0698;
    A = XD(DPTR);
    if (A != 0) goto L_DD05;
    f_DDCC();
    f_E4FA();
    DPTR = 0x83B4;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_DD05;
    RB(7) = 0x10;
    f_DB85();
    goto L_DD05;
    L_DD05:
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x01;
    DPTR = 0x8193;
    if (A == 0) goto L_DD16;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    goto L_DD1A;
    L_DD1A:
    DPTR = 0x8425;
    A = XD(DPTR);
    A &= 0x20;
    if (A == 0) goto L_DD29;
    DPTR = 0x8195;
    A = 0x01;
    XD(DPTR) = A;
    return;
    L_DD29:
    A = 0;
    DPTR = 0x8195;
    XD(DPTR) = A;
    return;
    L_DD16:
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    L_DCFB:
    DPTR = 0x8191;
    A = XD(DPTR);
    A &= 0x7F;
    XD(DPTR) = A;
    f_E4FA();
    L_DCB7:
    DPTR = 0x84E4;
    A = XD(DPTR);
    A ^= 0x01;
    DPTR = 0x8191;
    if (A != 0) goto L_DCCC;
    A = XD(DPTR);
    A |= 0x20;
    L_DCCC:
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    A = XD(DPTR);
    A |= 0x40;
    XD(DPTR) = A;
    L_DCA0:
    A = XD(DPTR);
    A &= 0xEF;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8197;
    XD(DPTR) = A;
    L_DC64:
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x33;
    if (A == 0) goto L_DC71;
    A = XD(DPTR);
    A ^= 0x03;
    if (A != 0) goto L_DC7E;
    L_DC71:
    DPTR = 0x8191;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    A = XD(DPTR);
    A |= 0x08;
    XD(DPTR) = A;
    goto L_DC89;
    L_DC7E:
    DPTR = 0x8191;
    A = XD(DPTR);
    A &= 0xFB;
    L_DC46:
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    L_DC2F:
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
}

void f_DD37(void)
{
    A = 0;
    DPTR = 0x0697;
    XD(DPTR) = A;
    f_DC1B();
    A = 0;
    DPTR = 0x0697;
    XD(DPTR) = A;
    L_DD44:
    DPTR = 0x0697;
    f_E48D();
    if (C == 0) goto L_DD62;
    f_E45A();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_DD62;
    RB(7) = 0x05;
    f_230B();
    DPTR = 0x0697;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_DD44;
    L_DD62:
    return;
}

void f_DD63(void)
{
    DPTR = 0x81A0;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_DDA2;
    f_E501();
    if (A == 0) goto L_DD7A;
    A = XD(DPTR);
    A ^= 0x10;
    if (A != 0) goto L_DD88;
    f_E474();
    if (A != 0) goto L_DD88;
    L_DD7A:
    DPTR = 0x8420;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    DPTR = 0x81A0;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    L_DD88:
    DPTR = 0x819F;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x00);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_DDA2;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    A = XD(DPTR);
    if (A != 0) goto L_DDA2;
    DPTR = 0x81A0;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    L_DDA2:
    f_E474();
    if (A == 0) goto L_DDAE;
    DPTR = 0x8420;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    L_DDAE:
    return;
}

void f_DDAF(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    if (A != 0) goto L_DDCB;
    DPTR = 0x8425;
    A = XD(DPTR);
    A &= 0x01;
    DPTR = 0x1609;
    if (A == 0) goto L_DDC7;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    return;
    L_DDC7:
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    L_DDCB:
    return;
}

void f_DDCC(void)
{
    A = 0;
    DPTR = 0x0699;
    XD(DPTR) = A;
    L_DDD1:
    f_E48A();
    if (C == 0) goto L_DDE9;
    f_E4DF();
    A = 0xE9;
    f_E468();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_DDE9;
    f_DE24();
    goto L_DDD1;
    L_DDE9:
    f_DE30();
    L_DDEC:
    f_E48A();
    if (C == 0) goto L_DE02;
    f_E4AF();
    f_E469();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_DE02;
    f_DE24();
    goto L_DDEC;
    L_DE02:
    f_DE30();
    L_DE05:
    f_E48A();
    if (C == 0) goto L_DE23;
    f_E4BF();
    f_E469();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_DE23;
    RB(7) = 0x05;
    f_230B();
    DPTR = 0x0699;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_DE05;
    L_DE23:
    return;
}

void f_DE24(void)
{
    RB(7) = 0x05;
    f_230B();
    DPTR = 0x0699;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    return;
}

void f_DE30(void)
{
    RB(7) = 0x05;
    f_230B();
    A = 0;
    DPTR = 0x0699;
    XD(DPTR) = A;
    return;
}

void f_DE3B(void)
{
    A = 0;
    DPTR = 0x0694;
    XD(DPTR) = A;
    L_DE40:
    DPTR = 0x0694;
    f_E48D();
    if (C == 0) goto L_DE61;
    f_E4CF();
    f_E469();
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_DE61;
    RB(7) = 0x05;
    f_230B();
    DPTR = 0x0694;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_DE40;
    L_DE61:
    RB(7) = 0x05;
    f_230B();
    return;
}

void f_DE66(void)
{
    DPTR = 0x81B6;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_DEA7;
    RB(7) = 0xD9;
    f_DB85();
    RB(7) = 0xD3;
    f_DB85();
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    L_DE7D:
    DPTR = 0x0693;
    f_E48D();
    if (C == 0) goto L_DEA0;
    RB(7) = 0x05;
    f_230B();
    f_E45A();
    f_1A4C();
    A = RB(7);
    if (A == 0) goto L_DE98;
    RB(7) = 0x05;
    f_230B();
    L_DE98:
    DPTR = 0x0693;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_DE7D;
    L_DEA0:
    DPTR = 0x81B6;
    A = XD(DPTR);
    A &= 0xF7;
    XD(DPTR) = A;
    L_DEA7:
    return;
}

void f_DEA8(void)
{
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    DPTR = 0x1607;
    A = XD(DPTR);
    A &= 0x40;
    if (A != 0) goto L_DEBC;
    DPTR = 0x81A8;
    A = 0x14;
    XD(DPTR) = A;
    return;
    L_DEBC:
    DPTR = 0x81A8;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x00);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_DECD;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    return;
    L_DECD:
    f_DDAF();
    f_DC1B();
    DPTR = 0x81B6;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_DEE5;
    f_DDCC();
    DPTR = 0x81B6;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    L_DEE5:
    DPTR = 0x81B6;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_DEF7;
    f_DE3B();
    DPTR = 0x81B6;
    A = XD(DPTR);
    A &= 0xFD;
    XD(DPTR) = A;
    L_DEF7:
    f_E508();
    if (A == 0) goto L_DEFF;
    f_E22C();
    return;
    L_DEFF:
    A = XD(DPTR);
    A &= 0x40;
    if (A == 0) goto L_DF08;
    RB(7) = 0x01;
    goto L_DF0A;
    L_DF0A:
    DPTR = 0x819A;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_DF14;
    f_E22C();
    return;
    L_DF14:
    DPTR = 0x069D;
    A++;
    XD(DPTR) = A;
    RB(6) = 0x81;
    DPTR++;
    A = 0x81;
    XD(DPTR) = A;
    DPTR++;
    A = 0x90;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = 0xCC;
    RB(5) = 0x08;
    RB(7) = 0x03;
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_DF35;
    f_E23C();
    return;
    L_DF35:
    DPTR = 0x8190;
    A = XD(DPTR);
    f_7A4A();
    if (--RB(7)) goto L_DED2;
    f_DFB1();
    return;
    L_DED2:
    RB(3)--;
    L_DF08:
    RB(7) = 0x00;
}

void f_DFB1(void)
{
    f_E474();
    f_E21F();
    return;
}

void f_E21F(void)
{
    f_E508();
    if (A != 0) goto L_E228;
    RB(7) = 0x01;
    goto L_E237;
    L_E237:
    DPTR = 0x819A;
    A = RB(7);
    XD(DPTR) = A;
    L_E228:
    RB(7) = 0x00;
    goto L_E237;
}

void f_E22C(void)
{
    f_E508();
    if (A != 0) goto L_E235;
    RB(7) = 0x01;
    goto L_E237;
    L_E237:
    DPTR = 0x819A;
    A = RB(7);
    XD(DPTR) = A;
    L_E235:
    RB(7) = 0x00;
}

void f_E23C(void)
{
    f_DD63();
    DPTR = 0x8191;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8192;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_E26D;
    f_E45A();
    f_1A4C();
    A = RB(7);
    if (A == 0) goto L_E260;
    DPTR = 0x8191;
    A = XD(DPTR);
    DPTR = 0x8192;
    f_E4EC();
    goto L_E26D;
    L_E26D:
    DPTR = 0x84E9;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x81D1;
    A = XD(DPTR);
    A ^= RB(7);
    if (A != 0) goto L_E291;
    DPTR = 0x84EA;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x81D3;
    A = XD(DPTR);
    A ^= RB(7);
    if (A != 0) goto L_E291;
    DPTR = 0x84EB;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x81D5;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_E2DC;
    L_E291:
    RB(7) = 0xEE;
    f_DB85();
    f_E4DF();
    DPTR++;
    A = 0xE9;
    f_E469();
    f_1A4C();
    A = RB(7);
    if (A == 0) goto L_E2D4;
    f_E4AF();
    f_E469();
    f_1A4C();
    A = RB(7);
    if (A == 0) goto L_E2DC;
    f_E4BF();
    f_E469();
    f_1A4C();
    A = RB(7);
    if (A == 0) goto L_E2DC;
    f_E496();
    A = 0;
    DPTR = 0x81A2;
    XD(DPTR) = A;
    DPTR = 0x84E8;
    A = 0x02;
    XD(DPTR) = A;
    DPTR = 0x8191;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    goto L_E2DC;
    L_E2DC:
    DPTR = 0x8195;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8196;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_E328;
    DPTR = 0x8195;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_E301;
    RB(3) = 0x31;
    f_E43E();
    A = RB(7);
    if (A == 0) goto L_E2FA;
    goto L_E30F;
    L_E30F:
    DPTR = 0x8195;
    A = XD(DPTR);
    DPTR = 0x8196;
    f_E4EC();
    goto L_E328;
    L_E328:
    DPTR = 0x8197;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8198;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_E374;
    DPTR = 0x8197;
    A = XD(DPTR);
    if (A != 0) goto L_E34B;
    RB(3) = 0x33;
    f_E452();
    A = RB(7);
    if (A == 0) goto L_E344;
    goto L_E35B;
    L_E35B:
    DPTR = 0x8197;
    A = XD(DPTR);
    DPTR = 0x8198;
    f_E4EC();
    goto L_E374;
    L_E374:
    DPTR = 0x8199;
    A = XD(DPTR);
    if (A == 0) goto L_E39F;
    A = XD(DPTR);
    DPTR = 0x8199;
    A = XD(DPTR);
    RB(3) = A;
    RB(5) = 0xCC;
    RB(7) = 0x03;
    f_1EB3();
    A = RB(7);
    if (A == 0) goto L_E395;
    A = 0;
    DPTR = 0x8199;
    XD(DPTR) = A;
    DPTR = 0x81A2;
    XD(DPTR) = A;
    goto L_E39F;
    L_E39F:
    DPTR = 0x84EC;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x81D8;
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_E3E0;
    f_E4CF();
    f_E469();
    f_1A4C();
    A = RB(7);
    if (A == 0) goto L_E3D3;
    DPTR = 0x84EC;
    A = XD(DPTR);
    DPTR = 0x81D8;
    f_E4EC();
    DPTR = 0x83B4;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_E3E0;
    DPTR = 0x84EC;
    A = XD(DPTR);
    RB(7) = A;
    f_DB85();
    goto L_E3E0;
    L_E3E0:
    DPTR = 0x81B6;
    A = XD(DPTR);
    A &= 0x04;
    if (A == 0) goto L_E414;
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    L_E3ED:
    DPTR = 0x0693;
    f_E48D();
    if (C == 0) goto L_E40D;
    RB(7) = 0x05;
    f_230B();
    f_E415();
    A = RB(7);
    if (A == 0) goto L_E405;
    RB(7) = 0x05;
    f_230B();
    L_E405:
    DPTR = 0x0693;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    goto L_E3ED;
    L_E40D:
    DPTR = 0x81B6;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    L_E414:
    return;
    L_E3D3:
    f_E47B();
    if (C != 0) goto L_E3E0;
    DPTR = 0x84EC;
    A = XD(DPTR);
    DPTR = 0x81D8;
    XD(DPTR) = A;
    L_E395:
    f_E47B();
    if (C != 0) goto L_E39F;
    A = 0;
    DPTR = 0x8199;
    XD(DPTR) = A;
    L_E344:
    f_E47B();
    if (C != 0) goto L_E374;
    goto L_E36C;
    L_E36C:
    DPTR = 0x8197;
    A = XD(DPTR);
    DPTR = 0x8198;
    XD(DPTR) = A;
    L_E34B:
    DPTR = 0x8197;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_E374;
    RB(3) = 0x32;
    f_E452();
    A = RB(7);
    if (A == 0) goto L_E367;
    L_E367:
    f_E47B();
    if (C != 0) goto L_E374;
    L_E2FA:
    f_E47B();
    if (C != 0) goto L_E328;
    goto L_E320;
    L_E320:
    DPTR = 0x8195;
    A = XD(DPTR);
    DPTR = 0x8196;
    XD(DPTR) = A;
    L_E301:
    DPTR = 0x8195;
    A = XD(DPTR);
    if (A != 0) goto L_E328;
    RB(3) = 0x30;
    f_E43E();
    A = RB(7);
    if (A == 0) goto L_E31B;
    L_E31B:
    f_E47B();
    if (C != 0) goto L_E328;
    L_E2D4:
    f_E47B();
    if (C != 0) goto L_E2DC;
    f_E496();
    L_E260:
    f_E47B();
    if (C != 0) goto L_E26D;
    DPTR = 0x8191;
    A = XD(DPTR);
    DPTR = 0x8192;
    XD(DPTR) = A;
}

void f_E415(void)
{
    DPTR = 0x069D;
    A = 0x40;
    XD(DPTR) = A;
    RB(6) = 0x81;
    DPTR++;
    A = 0x81;
    XD(DPTR) = A;
    DPTR++;
    A = 0x9D;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = 0xCC;
    RB(5) = 0x0C;
    RB(7) = 0x03;
    f_1A4C();
    return;
}

void f_E43E(void)
{
    RB(5) = 0xCC;
    RB(7) = 0x03;
    f_1EB3();
    return;
}

void f_E452(void)
{
    RB(5) = 0xCC;
    RB(7) = 0x03;
    f_1EB3();
    return;
}

void f_E45A(void)
{
    DPTR = 0x069D;
    A = 0x02;
    XD(DPTR) = A;
    RB(6) = 0x81;
    DPTR++;
    A = 0x81;
    XD(DPTR) = A;
    A = 0x91;
    DPTR++;
}

void f_E469(void)
{
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = 0xCC;
    RB(5) = 0x88;
    RB(7) = 0x03;
    return;
}

void f_E474(void)
{
    DPTR = 0x83F3;
    A = XD(DPTR);
    A &= 0x01;
    return;
}

void f_E47B(void)
{
    DPTR = 0x81A2;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x0A);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_E48A(void)
{
    DPTR = 0x0699;
}

void f_E48D(void)
{
    A = XD(DPTR);
    C = 0;
    SUBB8(0x03);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void f_E496(void)
{
    DPTR = 0x84E9;
    A = XD(DPTR);
    DPTR = 0x81D1;
    XD(DPTR) = A;
    DPTR = 0x84EA;
    A = XD(DPTR);
    DPTR = 0x81D3;
    XD(DPTR) = A;
    DPTR = 0x84EB;
    A = XD(DPTR);
    DPTR = 0x81D5;
    XD(DPTR) = A;
    return;
}

void f_E4AF(void)
{
    DPTR = 0x069D;
    A = 0x05;
    XD(DPTR) = A;
    RB(6) = 0x84;
    DPTR++;
    A = 0x84;
    XD(DPTR) = A;
    DPTR++;
    A = 0xEA;
    return;
}

void f_E4BF(void)
{
    DPTR = 0x069D;
    A = 0x06;
    XD(DPTR) = A;
    RB(6) = 0x84;
    DPTR++;
    A = 0x84;
    XD(DPTR) = A;
    DPTR++;
    A = 0xEB;
    return;
}

void f_E4CF(void)
{
    DPTR = 0x069D;
    A = 0x07;
    XD(DPTR) = A;
    RB(6) = 0x84;
    DPTR++;
    A = 0x84;
    XD(DPTR) = A;
    DPTR++;
    A = 0xEC;
    return;
}

void f_E4DF(void)
{
    DPTR = 0x069D;
    A = 0x04;
    XD(DPTR) = A;
    RB(6) = 0x84;
    DPTR++;
    A = 0x84;
    XD(DPTR) = A;
    return;
}

void f_E4EC(void)
{
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x81A2;
    XD(DPTR) = A;
    return;
}

void f_E4F3(void)
{
    DPTR = 0x84E8;
    A = XD(DPTR);
    A ^= 0x02;
    return;
}

void f_E4FA(void)
{
    DPTR = 0x0698;
    A = 0x01;
    XD(DPTR) = A;
    return;
}

void f_E501(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x50;
    return;
}

void f_E508(void)
{
    DPTR = 0x1D0C;
    A = XD(DPTR);
    A &= 0x40;
    return;
}

void f_E50F(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    if (A != 0) goto L_E540;
    DPTR = 0x069D;
    A++;
    XD(DPTR) = A;
    DPTR++;
    A = 0x06;
    XD(DPTR) = A;
    DPTR++;
    A = 0x93;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = 0x98;
    RB(5) = 0x08;
    RB(7) = 0x02;
    f_1A4C();
    A = RB(7);
    if (A != 0) goto L_E538;
    RB(7) = 0x02;
    f_1904();
    return;
    L_E538:
    DPTR = 0x0693;
    A = XD(DPTR);
    DPTR = 0x841C;
    XD(DPTR) = A;
    L_E540:
    return;
}

void f_FE00(void)
{
    DPTR = 0x1511;
    A = 0x33;
    XD(DPTR) = A;
    f_FEB1();
    return;
}

void f_FE09(void)
{
    L_FE09:
    DPTR = 0x0046;
    A = XD(DPTR);
    A ^= 0x02;
    if (A != 0) goto L_FE20;
    DPTR = 0x1510;
    A = XD(DPTR);
    A &= 0x0A;
    A ^= 0x0A;
    if (A != 0) goto L_FE09;
    DPTR = 0x1514;
    goto L_FE2D;
    L_FE2D:
    A = XD(DPTR);
    DPTR = 0x0083;
    XD(DPTR) = A;
    DPTR = 0x0084;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_FE49;
    DPTR = 0x0083;
    A = XD(DPTR);
    DPTR = 0x103F;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x0084;
    XD(DPTR) = A;
    goto L_FE09;
    L_FE49:
    DPTR = 0x0083;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_FE6F;
    DPTR = 0x009F;
    A = XD(DPTR);
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x103D;
    A = 0xFF;
    XD(DPTR) = A;
    DPTR = 0x103C;
    A--;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x103B;
    XD(DPTR) = A;
    DPTR = 0x103F;
    XD(DPTR) = A;
    goto L_FE09;
    L_FE6F:
    DPTR = 0x0083;
    A = XD(DPTR);
    A ^= 0x02;
    if (A != 0) goto L_FE85;
    DPTR = 0x103C;
    A = 0xFD;
    XD(DPTR) = A;
    DPTR = 0x0084;
    A = 0x01;
    XD(DPTR) = A;
    goto L_FE09;
    L_FE85:
    DPTR = 0x0083;
    A = XD(DPTR);
    A ^= 0x03;
    if (A != 0) goto L_FE95;
    DPTR = 0x0084;
    A++;
    XD(DPTR) = A;
    f_FE09();
    return;
    L_FE95:
    DPTR = 0x0083;
    A = XD(DPTR);
    A ^= 0x04;
    if (A != 0) goto L_FEB8;
    DPTR = 0x0046;
    A = XD(DPTR);
    A ^= 0x02;
    DPTR = 0x103F;
    if (A != 0) goto L_FEB0;
    A = XD(DPTR);
    DPTR = 0x1511;
    XD(DPTR) = A;
    f_FE09();
    return;
    L_FEB0:
    A = XD(DPTR);
    L_FEB8:
    DPTR = 0x0083;
    A = XD(DPTR);
    A ^= 0x05;
    if (A != 0) goto L_FECB;
    DPTR = 0x103E;
    XD(DPTR) = A;
    DPTR = 0x103D;
    XD(DPTR) = A;
    f_FE09();
    return;
    L_FECB:
    DPTR = 0x0083;
    A = XD(DPTR);
    A ^= 0xFC;
    if (A != 0) goto L_FEDF;
    DPTR = 0x0045;
    A = 0x33;
    XD(DPTR) = A;
    f_0200();
    f_FE09();
    return;
    L_FEDF:
    DPTR = 0x0083;
    A = XD(DPTR);
    A ^= 0xFE;
    if (A == 0) goto L_FEEA;
    f_FE09();
    return;
    L_FEEA:
    DPTR = 0x0045;
    A = 0x55;
    XD(DPTR) = A;
    f_0200();
    f_FE09();
    return;
    L_FE20:
    DPTR = 0x1500;
    A = XD(DPTR);
    A &= 0x0A;
    A ^= 0x0A;
    if (A != 0) goto L_FE09;
    DPTR = 0x1504;
}

void f_FEB1(void)
{
    DPTR = 0x1501;
    XD(DPTR) = A;
    f_FE09();
    return;
}


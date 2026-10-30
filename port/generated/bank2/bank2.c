#include "ec_globals.h"

void h_8001(void)
{
    DPTR = 0x0693;
    h_79D8();
    RB(7) = 0xE8;
    RB(6) = 0x03;
    h_80E7();
    C = 0;
    h_7959();
    if (C == 0) goto L_8017;
    h_80D1();
    return;
    L_8017:
    RB(7) = 0x40;
    RB(6) = 0x77;
    RB(5) = 0x1B;
    RB(4) = 0x00;
    h_80EA();
    C = 1;
    h_7959();
    if (C != 0) goto L_802B;
    h_80D1();
    return;
    L_802B:
    RB(7) = 0x60;
    RB(6) = 0xEA;
    h_80E7();
    C = 1;
    h_7959();
    if (C != 0) goto L_804F;
    DPTR = 0x0697;
    A = 0x02;
    XD(DPTR) = A;
    RB(3) = 0x35;
    RB(2) = 0x0C;
    h_80F0();
    RB(3) = 0x64;
    RB(2) = A;
    RB(1) = A;
    RB(0) = A;
    h_7808();
    goto L_808C;
    L_808C:
    DPTR = 0x0698;
    h_79D8();
    DPTR = 0x0697;
    A = XD(DPTR);
    DPTR = 0x1F02;
    XD(DPTR) = A;
    DPTR = 0x1F03;
    A = 0xFF;
    XD(DPTR) = A;
    DPTR = 0x1F04;
    XD(DPTR) = A;
    DPTR = 0x1F01;
    A = XD(DPTR);
    A |= 0x30;
    XD(DPTR) = A;
    DPTR = 0x1F05;
    A = XD(DPTR);
    A |= 0x10;
    XD(DPTR) = A;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
    DPTR = 0x0698;
    h_79B0();
    RB(0) = 0x08;
    h_796A();
    DPTR = 0x1F09;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x0698;
    h_79B0();
    DPTR = 0x1F06;
    A = RB(7);
    XD(DPTR) = A;
    return;
    L_804F:
    A = 0;
    RB(7) = 0x08;
    RB(6) = 0x07;
    h_80E8();
    C = 1;
    h_7959();
    if (C != 0) goto L_8074;
    DPTR = 0x0697;
    A = 0x01;
    XD(DPTR) = A;
    RB(3) = 0xE8;
    RB(2) = 0x03;
    h_80F0();
    RB(3) = A;
    RB(2) = 0x04;
    RB(1) = A;
    RB(0) = A;
    h_7808();
    goto L_808C;
    L_8074:
    A = 0;
    DPTR = 0x0697;
    XD(DPTR) = A;
    RB(7) = 0xCC;
    RB(6) = 0x0C;
    h_80E8();
    h_7808();
    A = 0;
    RB(3) = 0x64;
    RB(2) = A;
    RB(1) = A;
    RB(0) = A;
    h_7893();
}

void h_80E8(void)
{
    RB(5) = A;
    RB(4) = A;
}

void h_80EA(void)
{
    DPTR = 0x0693;
    h_79CC();
    return;
}

void h_80F0(void)
{
    A = 0;
    RB(1) = A;
    RB(0) = A;
    DPTR = 0x0693;
    h_79B0();
    h_7893();
    A = 0;
    return;
}

void h_E402(void)
{
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
    goto L_E40B;
    L_E40B:
    goto L_E40F;
    L_E40F:
    DIR(0x3D) = RB(1);
    DIR(0x32) = RB(2);
    DIR(0x2F) = RB(3);
    DIR(0x2F) = RB(4);
    DIR(0x44) = RB(5);
    DIR(0x34) = RB(6);
    DIR(0x36) = RB(7);
    DIR(0x1C) = DIR(0x08);
    goto L_E434;
    L_E434:
    goto L_E437;
    L_E437:
    DIR(0x45) = RB(1);
    DIR(0x33) = RB(2);
    DIR(0x2D) = RB(3);
    DIR(0x2D) = RB(4);
    DIR(0x58) = RB(5);
    DIR(0x37) = RB(6);
    DIR(0x34) = RB(7);
    DIR(0x1C) = DIR(0x08);
    goto L_E45C;
    L_E45C:
    goto L_E45F;
    L_E45F:
    DIR(0x3F) = RB(1);
    DIR(0x33) = RB(2);
    DIR(0x31) = RB(3);
    DIR(0x2E) = RB(4);
    DIR(0x4A) = RB(5);
    DIR(0x38) = RB(6);
    DIR(0x36) = RB(7);
    DIR(0x1D) = DIR(0x08);
    goto L_E484;
    L_E484:
    goto L_E487;
    L_E487:
    DIR(0x3F) = RB(1);
    DIR(0x33) = RB(2);
    DIR(0x30) = RB(3);
    DIR(0x2E) = RB(4);
    DIR(0x4E) = RB(5);
    DIR(0x37) = RB(6);
    DIR(0x36) = RB(7);
    DIR(0x1F) = DIR(0x08);
    goto L_E4AC;
    L_E4AC:
    goto L_E4AF;
    L_E4AF:
    DIR(0x40) = RB(1);
    DIR(0x2D) = RB(2);
    DIR(0x2D) = RB(3);
    DIR(0x2C) = RB(4);
    DIR(0x51) = RB(5);
    DIR(0x33) = RB(6);
    DIR(0x32) = RB(7);
    DIR(0x1F) = DIR(0x08);
    goto L_E4D4;
    L_E4D4:
    goto L_E4D7;
    L_E4D7:
    DIR(0x42) = RB(1);
    DIR(0x30) = RB(2);
    DIR(0x31) = RB(3);
    DIR(0x2F) = RB(4);
    DIR(0x4F) = RB(5);
    DIR(0x38) = RB(6);
    DIR(0x35) = RB(7);
    DIR(0x21) = DIR(0x08);
    goto L_E4FC;
    L_E4FC:
    goto L_E4FF;
    L_E4FF:
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
}

void h_E801(void)
{
    XD(DPTR) = A;
    XD(DPTR) = A;
    XD(DPTR) = A;
    XD(DPTR) = A;
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
    DIR(0x2E) = RB(4);
    DIR(0x5F) = RB(5);
    DIR(0x3E) = RB(6);
    DIR(0x36) = RB(7);
    DIR(0x17) = DIR(0x08);
    goto L_E820;
    L_E820:
    goto L_E823;
    L_E823:
    DIR(0x3A) = RB(1);
    DIR(0x2D) = RB(2);
    DIR(0x2A) = RB(3);
    DIR(0x28) = RB(4);
    DIR(0x58) = RB(5);
    DIR(0x32) = RB(6);
    DIR(0x2F) = RB(7);
    DIR(0x17) = DIR(0x08);
    goto L_E848;
    L_E848:
    goto L_E84B;
    L_E84B:
    DIR(0x3B) = RB(1);
    DIR(0x2E) = RB(2);
    DIR(0x2A) = RB(3);
    DIR(0x29) = RB(4);
    DIR(0x59) = RB(5);
    DIR(0x33) = RB(6);
    DIR(0x30) = RB(7);
    DIR(0x17) = DIR(0x08);
    goto L_E870;
    L_E870:
    goto L_E873;
    L_E873:
    DIR(0x3E) = RB(1);
    DIR(0x30) = RB(2);
    DIR(0x2C) = RB(3);
    DIR(0x2A) = RB(4);
    DIR(0x4E) = RB(5);
    DIR(0x35) = RB(6);
    DIR(0x32) = RB(7);
    DIR(0x18) = DIR(0x08);
    goto L_E898;
    L_E898:
    goto L_E89B;
    L_E89B:
    DIR(0x3E) = RB(1);
    DIR(0x30) = RB(2);
    DIR(0x2C) = RB(3);
    DIR(0x2A) = RB(4);
    DIR(0x51) = RB(5);
    DIR(0x37) = RB(6);
    DIR(0x32) = RB(7);
    DIR(0x16) = DIR(0x08);
    goto L_E8C0;
    L_E8C0:
    RB(2) = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    goto L_E8C4;
    L_E8C4:
    DIR(0x46) = RB(1);
    DIR(0x42) = RB(2);
    DIR(0x3B) = RB(3);
    DIR(0x31) = RB(4);
    DIR(0x54) = RB(5);
    DIR(0x4D) = RB(6);
    DIR(0x43) = RB(7);
    DIR(0x1A) = DIR(0x08);
    if (B == 0) { C = 0; } else { tmp = A % B; A = A / B; B = tmp; C = 0; }
    RB(6)++;
    RB(0) ^= 0x80;
    h_E801();
    return;
}

void h_EC02(void)
{
    XD(DPTR) = A;
    XD(DPTR) = A;
    XD(DPTR) = A;
    RB(7) = A;
    RB(7) = A;
    RB(7) = A;
    DIR(0x36) = RB(6);
    DIR(0x34) = RB(7);
    DIR(0x19) = DIR(0x08);
    h_EC02();
    return;
}


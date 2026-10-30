#include "ec_globals.h"

void g_8001(void)
{
    DPTR = 0x0693;
    A = RB(7);
    XD(DPTR) = A;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(5);
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    A ^= 0x01;
    if (A != 0) goto L_8013;
    RB(7) = 0xF0;
    g_825E();
    L_8013:
    DPTR = 0x0693;
    A = XD(DPTR);
    RB(7) = A;
    g_825E();
    return;
}

void g_801B(void)
{
    A = RB(7);
    RB(5) = A;
    A ^= 0x70;
    if (A == 0) goto L_804E;
    A = RB(5);
    A ^= 0x71;
    if (A == 0) goto L_804E;
    A = RB(5);
    A ^= 0x6B;
    if (A == 0) goto L_804E;
    A = RB(5);
    A ^= 0x6C;
    if (A == 0) goto L_804E;
    A = RB(5);
    A ^= 0x69;
    if (A == 0) goto L_804E;
    A = RB(5);
    A ^= 0x75;
    if (A == 0) goto L_804E;
    A = RB(5);
    A ^= 0x72;
    if (A == 0) goto L_804E;
    A = RB(5);
    A ^= 0x7D;
    if (A == 0) goto L_804E;
    A = RB(5);
    A ^= 0x7A;
    if (A == 0) goto L_804E;
    A = RB(5);
    A ^= 0x74;
    if (A != 0) goto L_8051;
    L_804E:
    RB(7) = 0x01;
    return;
    L_8051:
    A = RB(7);
    A ^= 0x4A;
    if (A != 0) goto L_8059;
    RB(7) = 0x02;
    return;
    L_8059:
    RB(7) = 0x00;
    return;
}

void g_8070(void)
{
    A ^= RB(3);
    if (A == 0) goto L_80E1;
    DPTR++;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_809F;
    if (!BIT_RAM(0x48)) goto L_8086;
    if (BIT_RAM(0x49)) goto L_80E1;
    if (BIT_RAM(0x4A)) goto L_80E1;
    RB(7) = 0xE0;
    goto L_80C8;
    L_80C8:
    g_825E();
    RB(7) = 0x12;
    goto L_80DE;
    L_80DE:
    g_825E();
    L_80E1:
    RB(7) = 0xE0;
    g_825E();
    g_816B();
    if (A != 0) goto L_80F0;
    RB(7) = 0xF0;
    g_825E();
    L_80F0:
    DPTR = 0x0697;
    A = XD(DPTR);
    RB(7) = A;
    g_825E();
    g_816B();
    if (A != 0) goto L_816A;
    DPTR++;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_8135;
    if (!BIT_RAM(0x48)) goto L_8115;
    if (BIT_RAM(0x49)) goto L_816A;
    if (BIT_RAM(0x4A)) goto L_816A;
    RB(7) = 0xE0;
    g_825E();
    RB(7) = 0xF0;
    goto L_8156;
    L_8156:
    g_825E();
    RB(7) = 0x12;
    goto L_8167;
    L_8167:
    g_825E();
    L_816A:
    return;
    L_8115:
    if (!BIT_RAM(0x49)) goto L_8129;
    if (!BIT_RAM(0x4A)) goto L_8129;
    RB(7) = 0xE0;
    g_825E();
    RB(7) = 0x59;
    g_825E();
    RB(7) = 0xE0;
    goto L_8156;
    L_8129:
    if (!BIT_RAM(0x49)) goto L_8130;
    RB(7) = 0xE0;
    goto L_8156;
    L_8130:
    if (!BIT_RAM(0x4A)) goto L_816A;
    goto L_8160;
    L_8160:
    RB(7) = 0xE0;
    g_825E();
    RB(7) = 0x59;
    L_8135:
    DPTR = 0x0699;
    A = XD(DPTR);
    A ^= 0x02;
    if (A != 0) goto L_816A;
    if (!BIT_RAM(0x49)) goto L_8151;
    if (!BIT_RAM(0x4A)) goto L_8151;
    RB(7) = 0xE0;
    g_825E();
    RB(7) = 0x59;
    g_825E();
    RB(7) = 0xE0;
    goto L_8156;
    L_8151:
    if (!BIT_RAM(0x49)) goto L_815D;
    RB(7) = 0xE0;
    L_815D:
    if (!BIT_RAM(0x4A)) goto L_816A;
    L_8086:
    if (!BIT_RAM(0x49)) goto L_808E;
    if (!BIT_RAM(0x4A)) goto L_808E;
    goto L_80AD;
    L_80AD:
    RB(7) = 0xE0;
    g_825E();
    RB(7) = 0xF0;
    g_825E();
    RB(7) = 0x12;
    g_825E();
    goto L_80D2;
    L_80D2:
    RB(7) = 0xE0;
    g_825E();
    RB(7) = 0xF0;
    g_825E();
    RB(7) = 0x59;
    L_808E:
    if (!BIT_RAM(0x49)) goto L_809A;
    RB(7) = 0xE0;
    g_825E();
    RB(7) = 0xF0;
    goto L_80C8;
    L_809A:
    if (!BIT_RAM(0x4A)) goto L_80E1;
    goto L_80D2;
    L_809F:
    DPTR = 0x0699;
    A = XD(DPTR);
    A ^= 0x02;
    if (A != 0) goto L_80E1;
    if (!BIT_RAM(0x49)) goto L_80BE;
    if (!BIT_RAM(0x4A)) goto L_80BE;
    L_80BE:
    if (!BIT_RAM(0x49)) goto L_80CF;
    RB(7) = 0xE0;
    g_825E();
    RB(7) = 0xF0;
    L_80CF:
    if (!BIT_RAM(0x4A)) goto L_80E1;
}

void g_8100(void)
{
    g_8070();
    return;
}

void g_816B(void)
{
    DPTR = 0x0698;
    A = XD(DPTR);
    A ^= 0x01;
    return;
}

void g_825E(void)
{
    DPTR = 0x06A2;
    A = 0x01;
    XD(DPTR) = A;
    g_82F6();
    RB(6) = A;
    g_82E0();
    A = RB(7);
    XD(DPTR) = A;
    A = DIR(0x4A);
    A &= 0x0F;
    RB(7) = A;
    A = RB(6);
    A++;
    A &= 0x0F;
    A = (A << 4) | (A >> 4);
    A &= 0xF0;
    A |= RB(7);
    DIR(0x4A) = A;
    A = (A << 4) | (A >> 4);
    g_82EC();
    if (C != 0) goto L_8285;
    DIR(0x4A) &= 0x0F;
    L_8285:
    A = DIR(0x4A);
    A &= 0x0F;
    RB(7) = A;
    g_82F6();
    A ^= RB(7);
    if (A != 0) goto L_82A9;
    A = DIR(0x4B);
    A &= 0x0F;
    A = (A << 4) | (A >> 4);
    A &= 0xF0;
    RB(7) = A;
    A = DIR(0x4A);
    A &= 0x0F;
    A |= RB(7);
    DIR(0x4A) = A;
    A = (A << 4) | (A >> 4);
    g_82E0();
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x06A2;
    XD(DPTR) = A;
    L_82A9:
    DPTR = 0x06A2;
    A = XD(DPTR);
    RB(7) = A;
    return;
}

void g_8346(void)
{
    A = RB(7);
    g_7A4A();
    A = CD(0x834B + A);
    C = C || (BIT_RAM(0x00));
    A = CD(0x834E + A);
    RB(2) = 0x01;
    A = CD(0x8351 + A);
    RB(7) = 0x02;
    A = CD(0x8354 + A);
    RB(3) = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    A = CD(0x8357 + A);
    RB(4) = RB(7);
    A = CD(0x835A + A);
    SUBB8(RB(3));
    DPH++;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = RB(6);
    A = CD(0x8360 + A);
    if (XD(((unsigned int)SFR_A0 << 8) | 0) != 0x07) { C = (XD(((unsigned int)SFR_A0 << 8) | 0) < 0x07); goto L_82E6; }
    tmp = A; A = DIR(0x08); DIR(0x08) = tmp;
    A = CD(0x8366 + A);
    A = da_a(A);
    RB(1)++;
    A = CD(0x8369 + A);
    A = XD(DPTR);
    RB(2)++;
    A = CD(0x836C + A);
    A = RB(4);
    RB(3)++;
    A = CD(0x8371 + A);
    A = ~A;
    DPTR = 0x1D08;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    return;
    L_82E6:
    A = 0;
    ADDC8(0x00);
    DPH = A;
    return;
}

void g_83F5(void)
{
    A = RB(7);
    g_7A4A();
    if (B == 0) { C = 0; } else { tmp = A % B; A = A / B; B = tmp; C = 0; }
    g_8100();
    return;
}

void g_84D0(void)
{
    RB(7) = A;
    g_84D5();
    RB(7)++;
}

void g_84D5(void)
{
    A = RB(7);
    A--;
    if (A == 0) goto L_84EE;
    A++;
    if (A != 0) goto L_8501;
    DPTR = 0x1610;
    A = XD(DPTR);
    if (A != 0) goto L_8501;
    DPTR = 0x1850;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    DPTR = 0x1610;
    goto L_84FE;
    L_84FE:
    A = 0x40;
    XD(DPTR) = A;
    L_8501:
    return;
    L_84EE:
    DPTR = 0x1611;
    A = XD(DPTR);
    if (A != 0) goto L_8501;
    DPTR = 0x1853;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    DPTR = 0x1611;
}

void g_859F(void)
{
    DPTR = 0x1609;
    A = XD(DPTR);
    A &= 0x20;
    if (A != 0) goto L_85B8;
    DPTR = 0x84E2;
    A = XD(DPTR);
    A &= 0x04;
    if (A != 0) goto L_85B8;
    DPTR = 0x1609;
    A = XD(DPTR);
    A |= 0x20;
    XD(DPTR) = A;
    goto L_85CF;
    L_85CF:
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_85E6;
    DPTR = 0x84E4;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_85E6;
    XD(DPTR) = A;
    DPTR = 0x84D0;
    A = 0x55;
    XD(DPTR) = A;
    L_85E6:
    g_8915();
    if (A != 0) goto L_860D;
    g_84D0();
    DPTR = 0x84E4;
    A = XD(DPTR);
    if (A != 0) goto L_85FC;
    RB(7) = 0x03;
    g_83F5();
    RB(7)--;
    goto L_860A;
    L_860A:
    g_8346();
    return;
    L_85FC:
    DPTR = 0x84E4;
    A = XD(DPTR);
    A ^= 0x02;
    RB(7) = 0x02;
    if (A != 0) goto L_8648;
    g_83F5();
    RB(7)++;
    L_8648:
    g_83F5();
    RB(7)++;
    g_83F5();
    return;
    L_860D:
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x33;
    if (A != 0) goto L_8644;
    DPTR = 0x84E4;
    A = XD(DPTR);
    if (A != 0) goto L_8628;
    RB(7) = 0x03;
    g_83F5();
    RB(7)--;
    g_8346();
    A = 0;
    RB(7) = A;
    goto L_863B;
    L_863B:
    g_8493();
    return;
    L_8628:
    DPTR = 0x84E4;
    A = XD(DPTR);
    A ^= 0x02;
    if (A != 0) goto L_863E;
    RB(7) = 0x02;
    g_83F5();
    RB(7)++;
    g_8346();
    RB(7) = 0x01;
    L_863E:
    g_84CF();
    RB(7)++;
    goto L_8648;
    L_8644:
    g_84CF();
    RB(7)++;
    L_85B8:
    DPTR = 0x1609;
    A = XD(DPTR);
    A &= 0x20;
    if (A == 0) goto L_85CF;
    DPTR = 0x84E2;
    A = XD(DPTR);
    A &= 0x04;
    if (A == 0) goto L_85CF;
    DPTR = 0x1609;
    A = XD(DPTR);
    A &= 0xDF;
    XD(DPTR) = A;
}

void g_8650(void)
{
    DPTR = 0x8392;
    A = XD(DPTR);
    A &= 0x02;
    if (A == 0) goto L_8690;
    DPTR = 0x8914;
    A = XD(DPTR);
    A &= 0x20;
    if (A == 0) goto L_8662;
    goto L_868A;
    L_868A:
    g_8941();
    L_868D:
    g_83F5();
    return;
    L_8662:
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_868A;
    DPTR = 0x847C;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x06);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_867D;
    g_8941();
    g_8346();
    return;
    L_867D:
    RB(3) = 0x1E;
    RB(5) = 0x1E;
    A = 0;
    RB(7) = A;
    g_8502();
    RB(7) = 0x01;
    goto L_868D;
    L_8690:
    g_8941();
    g_83F5();
    DPTR = 0x83B2;
    A = XD(DPTR);
    A &= 0x10;
    if (A == 0) goto L_86A3;
    RB(7) = 0x33;
    g_2B52();
    L_86A3:
    return;
}

void g_86AF(void)
{
    g_8915();
    if (A != 0) goto L_86DC;
    DPTR = 0x849A;
    A = XD(DPTR);
    if (A == 0) goto L_86D7;
    ADD8(0xFE);
    if (A == 0) goto L_86CC;
    A--;
    if (A == 0) goto L_86D3;
    ADD8(0x02);
    if (A != 0) goto L_86D7;
    DPTR = 0x1807;
    A = 0x66;
    XD(DPTR) = A;
    return;
    L_86D7:
    A = 0;
    DPTR = 0x1807;
    XD(DPTR) = A;
    L_86DC:
    return;
    L_86D3:
    g_891C();
    return;
    L_86CC:
    DPTR = 0x1807;
    A = 0xB3;
    XD(DPTR) = A;
    return;
}

void g_8767(void)
{
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    DPTR = 0x882A;
    A = 0x0F;
    XD(DPTR) = A;
    DPTR = 0x882B;
    A = 0x3E;
    XD(DPTR) = A;
    DPTR = 0x882C;
    A = 0x03;
    XD(DPTR) = A;
    DPTR = 0x882D;
    A = 0x0F;
    XD(DPTR) = A;
    DPTR = 0x069D;
    A = 0x01;
    XD(DPTR) = A;
    RB(6) = 0x88;
    DPTR++;
    A = 0x88;
    XD(DPTR) = A;
    A = 0x2A;
    g_88F3();
    g_1A4C();
    A = RB(7);
    if (A != 0) goto L_879E;
    g_893A();
    L_879E:
    DPTR = 0x069D;
    A = 0x02;
    XD(DPTR) = A;
    RB(6) = 0x88;
    DPTR++;
    A = 0x88;
    XD(DPTR) = A;
    A = 0x2B;
    g_88F3();
    g_1A4C();
    A = RB(7);
    if (A != 0) goto L_87B8;
    g_893A();
    L_87B8:
    DPTR = 0x069D;
    A = 0x03;
    XD(DPTR) = A;
    RB(6) = 0x88;
    DPTR++;
    A = 0x88;
    XD(DPTR) = A;
    DPTR++;
    A = 0x2C;
    g_88F4();
    g_1A4C();
    A = RB(7);
    if (A != 0) goto L_87D3;
    g_893A();
    L_87D3:
    DPTR = 0x069D;
    A = 0x04;
    XD(DPTR) = A;
    RB(6) = 0x88;
    DPTR++;
    A = 0x88;
    XD(DPTR) = A;
    DPTR++;
    A = 0x2D;
    g_88F4();
    g_1A4C();
    A = RB(7);
    if (A == 0) goto L_87EE;
    g_893A();
    L_87EE:
    DPTR = 0x0693;
    A = XD(DPTR);
    DPTR = 0x882F;
    if (A != 0) goto L_87FC;
    A = XD(DPTR);
    A |= 0x01;
    XD(DPTR) = A;
    return;
    L_87FC:
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    return;
}

void g_8801(void)
{
    DPTR = 0x069D;
    A = 0x21;
    XD(DPTR) = A;
    RB(6) = 0x88;
    DPTR++;
    A = 0x88;
    XD(DPTR) = A;
    DPTR++;
    A = 0xF8;
    g_88F4();
    g_1A4C();
    DPTR = 0x88F8;
    A = XD(DPTR);
    A = (A << 4) | (A >> 4);
    A &= 0x0F;
    DPTR = 0x88FC;
    XD(DPTR) = A;
    DPTR = 0x069D;
    A = 0x20;
    XD(DPTR) = A;
    RB(6) = 0x88;
    DPTR++;
    A = 0x88;
    XD(DPTR) = A;
    DPTR++;
    A = 0xFC;
    g_88F4();
    g_1A4C();
    return;
}

void g_8843(void)
{
    A = XD(DPTR);
    A ^= RB(7);
    if (A == 0) goto L_8887;
    DPTR = 0x2031;
    A = XD(DPTR);
    DPTR = 0x88F8;
    XD(DPTR) = A;
    DPTR = 0x882F;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_885A;
    g_8767();
    L_885A:
    g_8801();
    DPTR = 0x88F7;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    A ^= 0x07;
    if (A != 0) goto L_8869;
    XD(DPTR) = A;
    L_8869:
    DPTR = 0x88F8;
    A = XD(DPTR);
    A = ~A;
    if (A != 0) goto L_8873;
    A = 0xFE;
    XD(DPTR) = A;
    L_8873:
    DPTR = 0x88F8;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x88F7;
    A = XD(DPTR);
    ADD8(0xF0);
    DPL = A;
    A = 0;
    ADDC8(0x88);
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    L_8887:
    DPTR = 0x83B0;
    A = XD(DPTR);
    A &= 0x01;
    if (A == 0) goto L_88B9;
    A = XD(DPTR);
    A &= 0xFE;
    XD(DPTR) = A;
    DPTR = 0x88F0;
    g_892C();
    g_2CE7();
    DPTR = 0x88F3;
    g_892C();
    g_2CE7();
    DPTR = 0x88F6;
    A = XD(DPTR);
    RB(5) = A;
    DPTR = 0x88F7;
    A = XD(DPTR);
    RB(3) = A;
    A = 0;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    RB(7) = 0x83;
    g_2CE7();
    L_88B9:
    return;
}

void g_88BA(void)
{
    g_88EC();
    if (A != 0) goto L_88EB;
    DPTR = 0x84E8;
    A = XD(DPTR);
    if (A != 0) goto L_88CA;
    DPTR = 0x81D6;
    goto L_88E8;
    L_88E8:
    A = 0x45;
    XD(DPTR) = A;
    L_88EB:
    return;
    L_88CA:
    DPTR = 0x84E8;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_88D9;
    DPTR = 0x81D6;
    A = 0x46;
    XD(DPTR) = A;
    return;
    L_88D9:
    DPTR = 0x84E8;
    A = XD(DPTR);
    A ^= 0x02;
    DPTR = 0x81D6;
    if (A != 0) goto L_88E8;
    A = 0x47;
    XD(DPTR) = A;
    return;
}

void g_88EC(void)
{
    DPTR = 0x83C1;
    A = XD(DPTR);
    A &= 0x04;
    return;
}

void g_88FF(void)
{
    A = 0x00;
    ADD8(RB(6));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    DPH = A;
    return;
}

void g_890A(void)
{
    A = 0x10;
    ADD8(RB(6));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    DPH = A;
    return;
}

void g_8915(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
}

void g_8919(void)
{
    A ^= 0x10;
    return;
}

void g_891C(void)
{
    DPTR = 0x1807;
    A = 0xFF;
    XD(DPTR) = A;
    return;
}

void g_8923(void)
{
    A = 0;
    DPTR = 0x1807;
    XD(DPTR) = A;
    DPTR = 0x8199;
    return;
}

void g_893A(void)
{
    DPTR = 0x0693;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    return;
}

void g_8941(void)
{
    A = 0;
    RB(7) = A;
    g_83F5();
    RB(7)++;
    return;
}

void g_8948(void)
{
    DPTR = 0x0695;
    A = RB(7);
    XD(DPTR) = A;
    DPTR++;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    g_7A41();
    A = 0;
    DPTR = 0x069A;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x84E0;
    A = XD(DPTR);
    if (A == 0) goto L_8968;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_896C;
    L_8968:
    RB(7) = 0x08;
    goto L_8977;
    L_8977:
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(6) = A;
    DPTR = 0x069A;
    XD(DPTR) = A;
    A = RB(7);
    A--;
    RB(7) = A;
    A = RB(6);
    C = 0;
    SUBB8(RB(7));
    if (C == 0) goto L_89A3;
    DPTR = 0x0696;
    g_96B1();
    DPTR = 0x0002;
    g_7751();
    RB(7) = A;
    DPTR = 0x0695;
    A = XD(DPTR);
    C = 1;
    SUBB8(RB(7));
    if (C != 0) goto L_89A3;
    DPTR = 0x069A;
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    L_89A3:
    DPTR = 0x0696;
    A = XD(DPTR);
    RB(7) = A;
    g_9827();
    if (C != 0) goto L_89C6;
    A = RB(7);
    g_96B2();
    DPTR = 0x0001;
    g_7751();
    RB(7) = A;
    DPTR = 0x0695;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(7));
    if (C == 0) goto L_89C6;
    DPTR = 0x069A;
    A = XD(DPTR);
    A--;
    XD(DPTR) = A;
    L_89C6:
    DPTR = 0x069A;
    A = XD(DPTR);
    RB(7) = A;
    return;
    L_896C:
    g_981F();
    if (A != 0) goto L_8975;
    RB(7) = 0x0C;
    goto L_8977;
    L_8975:
    RB(7) = 0x09;
}

void g_89CC(void)
{
    DPTR = 0x0696;
    A = RB(5);
    XD(DPTR) = A;
    DPTR++;
    g_7A41();
    DPTR = 0x0695;
    A = RB(7);
    XD(DPTR) = A;
    if (A != 0) goto L_89E4;
    g_96B0();
    DPTR = 0x0003;
    goto L_89F2;
    L_89F2:
    g_7751();
    RB(7) = A;
    return;
    L_89E4:
    DPTR = 0x0695;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_89F7;
    g_96B0();
    DPTR = 0x0004;
    L_89F7:
    RB(7) = 0x00;
    return;
}

void g_89FA(void)
{
    A = 0;
    RB(3) = A;
    DPTR = 0x8896;
    A = XD(DPTR);
    A &= 0x02;
    if (A != 0) goto L_8A56;
    L_8A04:
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(3);
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(7);
    C = 0;
    SUBB8(0x06);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_8A4F;
    tmp = A; A = RB(7); RB(7) = tmp;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = 0x70;
    ADD8(RB(7));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    g_97E4();
    A = 0x76;
    ADD8(RB(7));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    g_97E4();
    A = 0x7C;
    ADD8(RB(7));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    g_97E4();
    A = 0x82;
    ADD8(RB(7));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    g_97E4();
    A = 0x90;
    ADD8(RB(7));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    DPH = A;
    A = 0x19;
    XD(DPTR) = A;
    RB(3)++;
    goto L_8A04;
    L_8A4F:
    DPTR = 0x8896;
    A = XD(DPTR);
    A |= 0x02;
    XD(DPTR) = A;
    L_8A56:
    DPTR = 0x8874;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8873;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8872;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8871;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8870;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x841C;
    A = XD(DPTR);
    DPTR = 0x8870;
    XD(DPTR) = A;
    DPTR = 0x887A;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8879;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8878;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8877;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8876;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x841D;
    A = XD(DPTR);
    DPTR = 0x8876;
    XD(DPTR) = A;
    DPTR = 0x8880;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x887F;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x887E;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x887D;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x887C;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8418;
    A = XD(DPTR);
    DPTR = 0x887C;
    XD(DPTR) = A;
    DPTR = 0x8886;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8885;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8884;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8883;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8882;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8419;
    A = XD(DPTR);
    DPTR = 0x8882;
    XD(DPTR) = A;
    DPTR = 0x8894;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8893;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8892;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8891;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8890;
    A = XD(DPTR);
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x841E;
    A = XD(DPTR);
    DPTR = 0x8890;
    XD(DPTR) = A;
    A = 0;
    DPTR = 0x8860;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8862;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8864;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x8866;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    DPTR = 0x888D;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = A;
    L_8B34:
    A = RB(3);
    C = 0;
    SUBB8(0x06);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_8B99;
    A = 0x70;
    ADD8(RB(3));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    DPH = A;
    A = XD(DPTR);
    DPTR = 0x8860;
    g_97AE();
    A = 0x76;
    ADD8(RB(3));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    DPH = A;
    A = XD(DPTR);
    DPTR = 0x8862;
    g_97AE();
    A = 0x7C;
    ADD8(RB(3));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    DPH = A;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8864;
    g_97AF();
    A = 0x82;
    ADD8(RB(3));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    DPH = A;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8866;
    g_97AF();
    A = 0x90;
    ADD8(RB(3));
    DPL = A;
    A = 0;
    ADDC8(0x88);
    DPH = A;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x888D;
    g_97AF();
    RB(3)++;
    goto L_8B34;
    L_8B99:
    DPTR = 0x8860;
    g_9718();
    DPTR = 0x885C;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x8862;
    g_9718();
    DPTR = 0x885D;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x8864;
    g_9718();
    DPTR = 0x885E;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x8866;
    g_9718();
    DPTR = 0x885F;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x888D;
    g_9718();
    DPTR = 0x888C;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void g_8BD1(void)
{
    DPTR = 0x8836;
    A = XD(DPTR);
    DPTR = 0x0694;
    XD(DPTR) = A;
    g_89FA();
    DPTR = 0x84E4;
    A = XD(DPTR);
    A--;
    if (A != 0) goto L_8BE6;
    g_8C6E();
    return;
    L_8BE6:
    A--;
    if (A != 0) goto L_8BEC;
    g_8D70();
    return;
    L_8BEC:
    ADD8(0x02);
    if (A == 0) goto L_8BF3;
    g_8E6D();
    return;
    L_8BF3:
    g_981F();
    if (A == 0) goto L_8BFB;
    g_8E6D();
    return;
    L_8BFB:
    DPTR = 0x885C;
    g_9729();
    RB(5) = A;
    RB(3) = 0xFF;
    RB(2) = 0x73;
    RB(1) = 0x5D;
    g_8948();
    g_96C3();
    RB(2) = 0x73;
    RB(1) = 0x99;
    g_8948();
    g_9724();
    C = 1;
    SUBB8(RB(7));
    if (C != 0) goto L_8C20;
    A = XD(DPTR);
    RB(7) = A;
    goto L_8C25;
    L_8C25:
    g_96D5();
    RB(2) = 0x73;
    RB(1) = 0xD5;
    g_8948();
    g_96A1();
    if (C != 0) goto L_8C39;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    goto L_8C3E;
    L_8C3E:
    g_96E7();
    RB(2) = 0x74;
    RB(1) = 0x11;
    g_8948();
    DPTR = 0x885B;
    g_96A4();
    if (C != 0) goto L_8C55;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    goto L_8C5A;
    L_8C5A:
    g_96F9();
    RB(2) = 0x73;
    RB(1) = 0xD5;
    g_8ECD();
    RB(2) = 0x74;
    RB(1) = 0x11;
    g_8EDF();
    g_8D66();
    return;
    L_8C55:
    DPTR = 0x885B;
    A = XD(DPTR);
    RB(7) = A;
    L_8C39:
    DPTR = 0x885A;
    A = XD(DPTR);
    RB(7) = A;
    L_8C20:
    DPTR = 0x8859;
    A = XD(DPTR);
    RB(7) = A;
}

void g_8C6E(void)
{
    g_981F();
    if (A == 0) goto L_8C76;
    g_8E6D();
    return;
    L_8C76:
    DPTR = 0x84F3;
    A = XD(DPTR);
    A ^= 0x09;
    if (A != 0) goto L_8CEE;
    DPTR = 0x885C;
    g_9729();
    RB(5) = A;
    RB(3) = 0xFF;
    RB(2) = 0x71;
    RB(1) = 0x7D;
    g_8948();
    g_96C3();
    RB(2) = 0x71;
    RB(1) = 0xB9;
    g_8948();
    g_9724();
    C = 1;
    SUBB8(RB(7));
    if (C != 0) goto L_8CA3;
    A = XD(DPTR);
    RB(7) = A;
    goto L_8CA8;
    L_8CA8:
    g_96D5();
    RB(2) = 0x71;
    RB(1) = 0xF5;
    g_8948();
    g_96A1();
    if (C != 0) goto L_8CBC;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    goto L_8CC1;
    L_8CC1:
    g_96E7();
    RB(2) = 0x72;
    RB(1) = 0x31;
    g_8948();
    DPTR = 0x885B;
    g_96A4();
    if (C != 0) goto L_8CD8;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    goto L_8CDD;
    L_8CDD:
    g_96F9();
    RB(2) = 0x71;
    RB(1) = 0xF5;
    g_8ECD();
    RB(2) = 0x72;
    RB(1) = 0x31;
    g_8D63();
    return;
    L_8CD8:
    DPTR = 0x885B;
    A = XD(DPTR);
    RB(7) = A;
    L_8CBC:
    DPTR = 0x885A;
    A = XD(DPTR);
    RB(7) = A;
    L_8CA3:
    DPTR = 0x8859;
    A = XD(DPTR);
    RB(7) = A;
    L_8CEE:
    DPTR = 0x885C;
    g_9729();
    RB(5) = A;
    RB(3) = 0xFF;
    RB(2) = 0x72;
    RB(1) = 0x6D;
    g_8948();
    g_96C3();
    RB(2) = 0x72;
    RB(1) = 0xA9;
    g_8948();
    g_9724();
    C = 1;
    SUBB8(RB(7));
    if (C != 0) goto L_8D13;
    A = XD(DPTR);
    RB(7) = A;
    g_8D18();
    return;
    L_8D13:
    DPTR = 0x8859;
    A = XD(DPTR);
    RB(7) = A;
}

void g_8D18(void)
{
    g_96D5();
    RB(2) = 0x72;
    RB(1) = 0xE5;
    g_8948();
    g_96A1();
    if (C != 0) goto L_8D2C;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    goto L_8D31;
    L_8D31:
    g_96E7();
    RB(2) = 0x73;
    RB(1) = 0x21;
    g_8948();
    DPTR = 0x885B;
    g_96A4();
    if (C != 0) goto L_8D48;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    goto L_8D4D;
    L_8D4D:
    g_96F9();
    RB(2) = 0x72;
    RB(1) = 0xE5;
    A = 0;
    RB(7) = A;
    g_89CC();
    DPTR = 0x8834;
    g_989A();
    RB(2) = 0x73;
    RB(1) = 0x21;
    L_8D48:
    DPTR = 0x885B;
    A = XD(DPTR);
    RB(7) = A;
    L_8D2C:
    DPTR = 0x885A;
    A = XD(DPTR);
    RB(7) = A;
}

void g_8D63(void)
{
    g_8EDF();
}

void g_8D66(void)
{
    DPTR = 0x8847;
    A = XD(DPTR);
    A &= 0x7F;
    XD(DPTR) = A;
    g_8E6D();
    return;
}

void g_8D70(void)
{
    g_981F();
    if (A == 0) goto L_8D78;
    g_8E6D();
    return;
    L_8D78:
    DPTR = 0x885C;
    g_9729();
    RB(5) = A;
    RB(3) = 0xFF;
    RB(2) = 0x74;
    RB(1) = 0x4D;
    g_8948();
    g_96C3();
    RB(2) = 0x74;
    RB(1) = 0x89;
    g_8948();
    g_9724();
    C = 1;
    SUBB8(RB(7));
    if (C != 0) goto L_8D9D;
    A = XD(DPTR);
    RB(7) = A;
    goto L_8DA2;
    L_8DA2:
    g_96D5();
    RB(2) = 0x74;
    RB(1) = 0xC5;
    g_8948();
    g_96A1();
    if (C != 0) goto L_8DB6;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    goto L_8DBB;
    L_8DBB:
    g_96E7();
    RB(2) = 0x75;
    RB(1) = 0x01;
    g_8948();
    DPTR = 0x885B;
    g_96A4();
    if (C != 0) goto L_8DD2;
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(6);
    tmp = A; A = RB(7); RB(7) = tmp;
    goto L_8DD7;
    L_8DD7:
    g_96F9();
    RB(2) = 0x74;
    RB(1) = 0xC5;
    A = 0;
    RB(7) = A;
    g_89CC();
    DPTR = 0x888A;
    g_989A();
    RB(2) = 0x75;
    RB(1) = 0x01;
    RB(7) = 0x01;
    g_89CC();
    DPTR = 0x888B;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x753F;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    DPTR = 0x888C;
    A = XD(DPTR);
    C = 1;
    SUBB8(RB(7));
    if (C != 0) goto L_8E19;
    DPTR = 0x7540;
    A = 0;
    A = CD(DPTR + A);
    DPTR = 0x8888;
    XD(DPTR) = A;
    DPTR = 0x7541;
    A = 0;
    A = CD(DPTR + A);
    DPTR = 0x8889;
    XD(DPTR) = A;
    goto L_8E30;
    L_8E30:
    DPTR = 0x8888;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x888A;
    A = XD(DPTR);
    C = 1;
    SUBB8(RB(7));
    if (C != 0) goto L_8E41;
    A = XD(DPTR);
    RB(7) = A;
    goto L_8E46;
    L_8E46:
    DPTR = 0x8834;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x8889;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x888B;
    A = XD(DPTR);
    C = 1;
    SUBB8(RB(7));
    if (C != 0) goto L_8E5C;
    A = XD(DPTR);
    RB(7) = A;
    goto L_8E61;
    L_8E61:
    DPTR = 0x8835;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x8847;
    A = XD(DPTR);
    A |= 0x80;
    XD(DPTR) = A;
    L_8E5C:
    DPTR = 0x8889;
    A = XD(DPTR);
    RB(7) = A;
    L_8E41:
    DPTR = 0x8888;
    A = XD(DPTR);
    RB(7) = A;
    L_8E19:
    DPTR = 0x753E;
    A = 0;
    A = CD(DPTR + A);
    RB(7) = A;
    DPTR = 0x888C;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(7));
    if (C == 0) goto L_8E30;
    A = 0;
    DPTR = 0x8889;
    XD(DPTR) = A;
    DPTR = 0x8888;
    XD(DPTR) = A;
    L_8DD2:
    DPTR = 0x885B;
    A = XD(DPTR);
    RB(7) = A;
    L_8DB6:
    DPTR = 0x885A;
    A = XD(DPTR);
    RB(7) = A;
    L_8D9D:
    DPTR = 0x8859;
    A = XD(DPTR);
    RB(7) = A;
}

void g_8E6D(void)
{
    DPTR = 0x883C;
    A = XD(DPTR);
    if (A == 0) goto L_8E9D;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x0A);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_8E80;
    A = 0;
    goto L_8E99;
    L_8E99:
    DPTR = 0x8834;
    XD(DPTR) = A;
    L_8E9D:
    DPTR = 0x883D;
    A = XD(DPTR);
    if (A == 0) goto L_8ECC;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x0A);
    A = 0x80;
    SUBB8(0x80);
    if (C == 0) goto L_8EB0;
    A = 0;
    goto L_8EC8;
    L_8EC8:
    DPTR = 0x8835;
    XD(DPTR) = A;
    L_8ECC:
    return;
    L_8EB0:
    DPTR = 0x883D;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x46);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_8EC4;
    DPTR = 0x8835;
    A = 0x46;
    XD(DPTR) = A;
    return;
    L_8EC4:
    DPTR = 0x883D;
    A = XD(DPTR);
    L_8E80:
    DPTR = 0x883C;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x46);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_8E95;
    DPTR = 0x8834;
    A = 0x46;
    XD(DPTR) = A;
    goto L_8E9D;
    L_8E95:
    DPTR = 0x883C;
    A = XD(DPTR);
}

void g_8ECD(void)
{
    A = 0;
    RB(7) = A;
    g_89CC();
    DPTR = 0x8834;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(5) = A;
    RB(3) = 0xFF;
    return;
}

void g_8EDF(void)
{
    RB(7) = 0x01;
    g_89CC();
    DPTR = 0x8835;
    A = RB(7);
    XD(DPTR) = A;
    return;
}

void g_8EEA(void)
{
    DPTR = 0x181F;
    A = XD(DPTR);
    DPTR = 0x181E;
    g_970B();
    if (A != 0) goto L_8F1F;
    A = RB(7);
    if (A != 0) goto L_8EFC;
    A = RB(5);
    if (A == 0) goto L_8F1F;
    L_8EFC:
    g_9740();
    DPTR = 0x8830;
    A = RB(6);
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    C = 1;
    DPTR = 0x8831;
    A = XD(DPTR);
    SUBB8(0x58);
    DPTR = 0x8830;
    A = XD(DPTR);
    SUBB8(0x1B);
    if (C != 0) goto L_8F26;
    A = 0x1B;
    XD(DPTR) = A;
    DPTR++;
    A = 0x58;
    XD(DPTR) = A;
    goto L_8F26;
    L_8F26:
    DPTR = 0x8830;
    A = XD(DPTR);
    RB(7) = A;
    DPTR++;
    A = XD(DPTR);
    DPTR = 0x849B;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    return;
    L_8F1F:
    A = 0;
    DPTR = 0x8830;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
}

void g_900D(void)
{
    A = XD(DPTR);
    A++;
    XD(DPTR) = A;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x02);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_901F;
    A = 0;
    XD(DPTR) = A;
    g_8BD1();
    L_901F:
    DPTR = 0x84E2;
    A = XD(DPTR);
    A &= 0x08;
    if (A == 0) goto L_9031;
    DPTR = 0x8834;
    A = 0x46;
    XD(DPTR) = A;
    DPTR = 0x8835;
    XD(DPTR) = A;
    L_9031:
    DPTR = 0x84E2;
    A = XD(DPTR);
    A &= 0x20;
    if (A != 0) goto L_903C;
    g_90E5();
    return;
    L_903C:
    DPTR = 0x84E4;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_9071;
    DPTR = 0x8834;
    A = XD(DPTR);
    C = 0;
    g_97F0();
    if (C != 0) goto L_909C;
    DPTR = 0x845F;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x3A);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_9064;
    DPTR = 0x0693;
    A = 0x3A;
    XD(DPTR) = A;
    g_90D5();
    return;
    L_9064:
    C = 0;
    g_97EC();
    if (C != 0) goto L_906C;
    goto L_90D0;
    L_90D0:
    A = XD(DPTR);
    DPTR = 0x0693;
    XD(DPTR) = A;
    L_906C:
    DPTR = 0x8834;
    goto L_90D0;
    L_909C:
    goto L_90CD;
    L_90CD:
    DPTR = 0x8834;
    L_9071:
    DPTR = 0x84E4;
    A = XD(DPTR);
    if (A != 0) goto L_909E;
    DPTR = 0x8834;
    A = XD(DPTR);
    C = 0;
    g_97FB();
    if (C != 0) goto L_909C;
    C = 1;
    g_97EC();
    if (C != 0) goto L_908F;
    DPTR = 0x0693;
    A = 0x32;
    XD(DPTR) = A;
    g_90D5();
    return;
    L_908F:
    C = 0;
    g_97F7();
    if (C != 0) goto L_9097;
    goto L_909A;
    L_909A:
    goto L_90D0;
    L_9097:
    DPTR = 0x8834;
    L_909E:
    DPTR = 0x8834;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x16);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_90CD;
    C = 1;
    g_97F7();
    if (C != 0) goto L_90B9;
    DPTR = 0x0693;
    A = 0x23;
    XD(DPTR) = A;
    g_90D5();
    return;
    L_90B9:
    DPTR = 0x845F;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x16);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_90C8;
    goto L_90CB;
    L_90CB:
    goto L_90D0;
    L_90C8:
    DPTR = 0x8834;
}

void g_90D5(void)
{
    DPTR = 0x0693;
    A = XD(DPTR);
    DPTR = 0x8834;
    XD(DPTR) = A;
    DPTR = 0x0693;
    A = XD(DPTR);
    DPTR = 0x8835;
    XD(DPTR) = A;
}

void g_90E5(void)
{
    DPTR = 0x8834;
    A = XD(DPTR);
    if (A == 0) goto L_90EE;
    g_8F36();
    return;
    L_90EE:
    DPTR = 0x883E;
    A = XD(DPTR);
    if (A == 0) goto L_9104;
    g_983C();
    if (C != 0) goto L_90FE;
    DPTR = 0x1841;
    goto L_9101;
    L_9101:
    A = XD(DPTR);
    goto L_9105;
    L_9105:
    DPTR = 0x1805;
    XD(DPTR) = A;
    return;
    L_90FE:
    DPTR = 0x883E;
    L_9104:
    A = 0;
}

void g_910A(void)
{
    DPTR = 0x1821;
    A = XD(DPTR);
    DPTR = 0x1820;
    g_970B();
    if (A != 0) goto L_913F;
    A = RB(7);
    if (A != 0) goto L_911C;
    A = RB(5);
    if (A == 0) goto L_913F;
    L_911C:
    g_9740();
    DPTR = 0x8832;
    A = RB(6);
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    C = 1;
    DPTR = 0x8833;
    A = XD(DPTR);
    SUBB8(0x58);
    DPTR = 0x8832;
    A = XD(DPTR);
    SUBB8(0x1B);
    if (C != 0) goto L_9146;
    A = 0x1B;
    XD(DPTR) = A;
    DPTR++;
    A = 0x58;
    XD(DPTR) = A;
    goto L_9146;
    L_9146:
    DPTR = 0x8832;
    A = XD(DPTR);
    RB(7) = A;
    DPTR++;
    A = XD(DPTR);
    DPTR = 0x849D;
    tmp = A; A = RB(7); RB(7) = tmp;
    XD(DPTR) = A;
    DPTR++;
    A = RB(7);
    XD(DPTR) = A;
    return;
    L_913F:
    A = 0;
    DPTR = 0x8832;
    XD(DPTR) = A;
    DPTR++;
    XD(DPTR) = A;
}

void g_9281(void)
{
    DPTR = 0x84E4;
    A = XD(DPTR);
    DPTR = 0x84E0;
    A = XD(DPTR);
    if (A == 0) goto L_9290;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_92A3;
    L_9290:
    g_9854();
    if (C != 0) goto L_929C;
    DPTR = 0x8846;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    L_929C:
    g_9860();
    if (C == 0) goto L_92BB;
    goto L_92B4;
    L_92B4:
    DPTR = 0x8846;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    L_92BB:
    return;
    L_92A3:
    g_9854();
    if (C != 0) goto L_92AF;
    DPTR = 0x8846;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    L_92AF:
    g_9860();
    if (C == 0) goto L_92BB;
}

void g_92BC(void)
{
    DPTR = 0x84E4;
    A = XD(DPTR);
    DPTR = 0x84E0;
    A = XD(DPTR);
    if (A == 0) goto L_92CB;
    A = XD(DPTR);
    A ^= 0x01;
    if (A != 0) goto L_92DE;
    L_92CB:
    g_986C();
    if (C != 0) goto L_92D7;
    DPTR = 0x8847;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    L_92D7:
    g_9878();
    if (C == 0) goto L_92F6;
    goto L_92EF;
    L_92EF:
    DPTR = 0x8847;
    A = XD(DPTR);
    A &= 0xFB;
    XD(DPTR) = A;
    L_92F6:
    return;
    L_92DE:
    g_986C();
    if (C != 0) goto L_92EA;
    DPTR = 0x8847;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    L_92EA:
    g_9878();
    if (C == 0) goto L_92F6;
}

void g_94C8(void)
{
    A = 0;
    DPTR = 0x0692;
    XD(DPTR) = A;
    return;
}

void g_94DF(void)
{
    A = 0;
    DPTR = 0x0693;
    XD(DPTR) = A;
    g_9711();
    if (A == 0) goto L_94F7;
    A = 0;
    DPTR = 0x8417;
    XD(DPTR) = A;
    DPTR = 0x8418;
    A = 0x19;
    g_9762();
    return;
    L_94F7:
    DPTR = 0x069D;
    A = 0x01;
    XD(DPTR) = A;
    RB(6) = 0x84;
    DPTR++;
    A = 0x84;
    XD(DPTR) = A;
    A = 0x18;
    g_957A();
    A = 0;
    DPTR = 0x069D;
    XD(DPTR) = A;
    RB(6) = 0x84;
    DPTR++;
    A = 0x84;
    XD(DPTR) = A;
    A = 0x19;
    g_957A();
    A = 0;
    DPTR = 0x069D;
    XD(DPTR) = A;
    RB(6) = 0x84;
    DPTR++;
    A = 0x84;
    XD(DPTR) = A;
    A = 0x1A;
    g_9589();
    DPTR = 0x069D;
    A = 0x01;
    XD(DPTR) = A;
    RB(6) = 0x84;
    DPTR++;
    A = 0x84;
    XD(DPTR) = A;
    A = 0x1B;
    g_9589();
    DPTR = 0x069D;
    A = 0x23;
    XD(DPTR) = A;
    RB(6) = 0x84;
    DPTR++;
    A = 0x84;
    XD(DPTR) = A;
    DPTR++;
    A = 0x1E;
    XD(DPTR) = A;
    A = 0;
    DPTR++;
    XD(DPTR) = A;
    RB(3) = 0x9A;
    RB(5) = 0x08;
    RB(7) = 0x03;
    g_1A4C();
    A = 0;
    DPTR = 0x069D;
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
    RB(3) = 0x9E;
    RB(5) = 0x08;
    RB(7) = 0x03;
    g_1A4C();
    A = RB(7);
    if (A == 0) goto L_9579;
    DPTR = 0x0693;
    A = XD(DPTR);
    DPTR = 0x841D;
    XD(DPTR) = A;
    L_9579:
    return;
}

void g_9598(void)
{
    DPTR = 0x83F0;
    A = XD(DPTR);
    A &= 0x01;
    if (A != 0) goto L_95B2;
    g_9711();
    if (A == 0) goto L_95B2;
    DPTR = 0x8417;
    A = 0x19;
    XD(DPTR) = A;
    DPTR = 0x8418;
    g_9762();
    return;
    L_95B2:
    A = 0;
    RB(5) = A;
}

void g_95B4(void)
{
    A = RB(5);
    C = 0;
    SUBB8(0x08);
    A = 0x80;
    SUBB8(0x80);
    if (C != 0) goto L_95C1;
    g_968E();
    return;
    L_95C1:
    tmp = A; A = RB(0); RB(0) = tmp;
    A = RB(5);
    tmp = A; A = RB(0); RB(0) = tmp;
    RB(6) = 0x00;
    A = 0x01;
    RB(0)++;
    goto L_95D0;
    L_95D0:
    if (--RB(0)) goto L_95CB;
    RB(7) = A;
    DPTR = 0x8C40;
    A = XD(DPTR);
    RB(3) = A;
    A = RB(7);
    A &= RB(3);
    if (A != 0) goto L_95DF;
    g_968A();
    return;
    L_95DF:
    A = RB(5);
    ADD8((A));
    ADD8(0x00);
    DPL = A;
    A = 0;
    ADDC8(0x8C);
    DPH = A;
    RB(0) = 0x02;
    A = XD(DPTR);
    RB(6) = A;
    DPTR++;
    A = XD(DPTR);
    L_95F1:
    tmp = A; A = RB(6); RB(6) = tmp;
    C = 0;
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    tmp = A; A = RB(6); RB(6) = tmp;
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    if (--RB(0)) goto L_95F1;
    g_9730();
    A = XD(DPTR);
    if (A == 0) goto L_9610;
    g_9781();
    A = XD(DPTR);
    if (A == 0) goto L_9610;
    g_9790();
    A = XD(DPTR);
    if (A == 0) goto L_9610;
    g_979F();
    A = XD(DPTR);
    if (A != 0) goto L_962A;
    L_9610:
    g_97DD();
    g_9731();
    g_97DB();
    g_9781();
    g_97DB();
    g_9790();
    g_97DB();
    g_979F();
    A = RB(6);
    XD(DPTR) = A;
    L_962A:
    g_97D0();
    A = XD(DPTR);
    A++;
    A &= 0x03;
    RB(6) = A;
    g_97D0();
    A = RB(6);
    XD(DPTR) = A;
    A = RB(7);
    DPTR = 0x7542;
    A = CD(DPTR + A);
    RB(7) = A;
    g_97D0();
    A = XD(DPTR);
    RB(6) = A;
    g_9731();
    A = DPL;
    ADD8(RB(6));
    DPL = A;
    A = 0;
    ADDC8((DPH));
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    g_9781();
    A = XD(DPTR);
    g_9730();
    A = XD(DPTR);
    ADD8(RB(7));
    RB(7) = A;
    A = 0;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    RB(6) = A;
    g_9790();
    A = XD(DPTR);
    RB(2) = 0x00;
    ADD8(RB(7));
    RB(7) = A;
    A = RB(2);
    ADDC8(RB(6));
    RB(6) = A;
    g_979F();
    A = XD(DPTR);
    ADD8(RB(7));
    RB(7) = A;
    A = RB(2);
    ADDC8(RB(6));
    RB(6) = A;
    RB(0) = 0x02;
    A = RB(7);
    L_9675:
    tmp = A; A = RB(6); RB(6) = tmp;
    C = ((A >> 7) & 1);
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    tmp = A; A = RB(6); RB(6) = tmp;
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    if (--RB(0)) goto L_9675;
    RB(7) = A;
    A = 0x38;
    ADD8(RB(5));
    DPL = A;
    A = 0;
    ADDC8(0x8C);
    DPH = A;
    A = RB(7);
    XD(DPTR) = A;
    L_95CB:
    C = 0;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(6); RB(6) = tmp;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    tmp = A; A = RB(6); RB(6) = tmp;
}

void g_968A(void)
{
    RB(5)++;
    g_95B4();
    return;
}

void g_96A1(void)
{
    DPTR = 0x885A;
}

void g_96A4(void)
{
    A = RB(7);
    XD(DPTR) = A;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(6) = A;
    C = 1;
    SUBB8(RB(7));
    return;
}

void g_96B2(void)
{
    B = 0x05;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    RB(7) = A;
    DPTR++;
    g_7A21();
    A = RB(1);
    ADD8(RB(7));
    RB(1) = A;
    A = RB(2);
    ADDC8((B));
    RB(2) = A;
    return;
}

void g_96C3(void)
{
    DPTR = 0x8858;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x885D;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8859;
    A = XD(DPTR);
    RB(5) = A;
    RB(3) = 0xFF;
    return;
}

void g_96D5(void)
{
    DPTR = 0x0694;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x885E;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x885A;
    A = XD(DPTR);
    RB(5) = A;
    RB(3) = 0xFF;
    return;
}

void g_96E7(void)
{
    DPTR = 0x0694;
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x885F;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x885B;
    A = XD(DPTR);
    RB(5) = A;
    RB(3) = 0xFF;
    return;
}

void g_96F9(void)
{
    DPTR = 0x0694;
    A = RB(7);
    XD(DPTR) = A;
    A = XD(DPTR);
    RB(5) = A;
    DPTR = 0x8836;
    XD(DPTR) = A;
    DPTR = 0x8837;
    XD(DPTR) = A;
    RB(3) = 0xFF;
    return;
}

void g_970B(void)
{
    RB(7) = A;
    A = XD(DPTR);
    RB(6) = A;
    tmp = A; A = RB(5); RB(5) = tmp;
    A = RB(6);
    tmp = A; A = RB(5); RB(5) = tmp;
}

void g_9711(void)
{
    DPTR = 0x8300;
    A = XD(DPTR);
    A ^= 0x10;
    return;
}

void g_9724(void)
{
    DPTR = 0x8859;
    A = RB(7);
    XD(DPTR) = A;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x8858;
    A = XD(DPTR);
    return;
}

void g_9731(void)
{
    A = RB(5);
    ADD8((A));
    ADD8((A));
    ADD8(0x18);
    DPL = A;
    A = 0;
    ADDC8(0x8C);
    DPH = A;
    return;
}

void g_9740(void)
{
    A = RB(7);
    RB(6) = A;
    RB(4) = 0x00;
    A = 0;
    ADD8(RB(5));
    DIR(0x6C) = A;
    A = RB(4);
    ADDC8(RB(6));
    DIR(0x6B) = A;
    RB(6) = DIR(0x6B);
    RB(7) = DIR(0x6C);
    tmp = A; A = RB(3); RB(3) = tmp;
    A = RB(7);
    tmp = A; A = RB(3); RB(3) = tmp;
    tmp = A; A = RB(2); RB(2) = tmp;
    A = RB(6);
    tmp = A; A = RB(2); RB(2) = tmp;
    A = 0;
    RB(1) = A;
    RB(0) = A;
    RB(7) = 0xDA;
    RB(6) = 0xE6;
    RB(5) = 0x20;
    g_7A8E();
    return;
}

void g_9781(void)
{
    A = RB(5);
    ADD8((A));
    ADD8((A));
    ADD8(0x19);
    DPL = A;
    A = 0;
    ADDC8(0x8C);
    DPH = A;
    return;
}

void g_9790(void)
{
    A = RB(5);
    ADD8((A));
    ADD8((A));
    ADD8(0x1A);
    DPL = A;
    A = 0;
    ADDC8(0x8C);
    DPH = A;
    return;
}

void g_979F(void)
{
    A = RB(5);
    ADD8((A));
    ADD8((A));
    ADD8(0x1B);
    DPL = A;
    A = 0;
    ADDC8(0x8C);
    DPH = A;
    return;
}

void g_97AF(void)
{
    A = 0;
    B = RB(7);
    g_77E5();
    return;
}

void g_97B5(void)
{
    B = 0x64;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0xCE);
    RB(7) = A;
    A = B;
    ADDC8(0xFF);
    RB(6) = A;
    C = 0;
    A = XD(DPTR);
    SUBB8(RB(7));
    return;
}

void g_97C5(void)
{
    DPTR = 0x8908;
    A = XD(DPTR);
    RB(3) = A;
    A = 0;
    DPTR = 0x06B2;
    XD(DPTR) = A;
    return;
}

void g_97D0(void)
{
    A = 0x10;
    ADD8(RB(5));
    DPL = A;
    A = 0;
    ADDC8(0x8C);
    DPH = A;
    return;
}

void g_97DB(void)
{
    A = RB(6);
    XD(DPTR) = A;
}

void g_97DD(void)
{
    A = RB(7);
    DPTR = 0x7542;
    A = CD(DPTR + A);
    RB(6) = A;
    return;
}

void g_97EC(void)
{
    DPTR = 0x845F;
    A = XD(DPTR);
    SUBB8(0x32);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void g_97F7(void)
{
    DPTR = 0x845F;
    A = XD(DPTR);
    SUBB8(0x23);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void g_9800(void)
{
    goto L_9824;
    L_9824:
    A++;
    return;
}

void g_9802(void)
{
    B = 0x64;
    tmp16 = (unsigned int)A * B; A = tmp16 & 0xFF; B = tmp16 >> 8; C = 0;
    ADD8(0x32);
    RB(7) = A;
    A = 0;
    ADDC8((B));
    RB(6) = A;
    C = 1;
    A = XD(DPTR);
    SUBB8(RB(7));
    return;
}

void g_981F(void)
{
    DPTR = 0x84E0;
    A = XD(DPTR);
    A ^= 0x04;
    return;
}

void g_983C(void)
{
    DPTR = 0x1841;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x883E;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(7));
    return;
}

void g_9848(void)
{
    DPTR = 0x1841;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x883F;
    A = XD(DPTR);
    C = 0;
    SUBB8(RB(7));
    return;
}

void g_9854(void)
{
    DPTR = 0x885C;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x69);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void g_9860(void)
{
    DPTR = 0x885C;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x64);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void g_986C(void)
{
    DPTR = 0x885D;
    A = XD(DPTR);
    C = 1;
    SUBB8(0x5F);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void g_9878(void)
{
    DPTR = 0x885D;
    A = XD(DPTR);
    C = 0;
    SUBB8(0x5A);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void g_9884(void)
{
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(7) = A;
    DPTR = 0x885F;
    A = XD(DPTR);
    SUBB8(RB(7));
    return;
}

void g_988F(void)
{
    DPTR = 0x888C;
    A = XD(DPTR);
    SUBB8(0x55);
    A = 0x80;
    SUBB8(0x80);
    return;
}

void g_989A(void)
{
    A = RB(7);
    XD(DPTR) = A;
    DPTR = 0x0694;
    A = XD(DPTR);
    RB(5) = A;
    RB(3) = 0xFF;
    return;
}

void g_98A4(void)
{
    A = 0;
    XD(DPTR) = A;
    DPTR = 0x83B1;
    A = XD(DPTR);
    A |= 0x04;
    XD(DPTR) = A;
    return;
}

void g_B800(void)
{
    g_B800();
    return;
}

void g_B827(void)
{
    DIR(0x45) |= 0x4C;
    RB(7) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    g_1204();
    return;
}

void g_C021(void)
{
    if (RB(7) != 0x0C) { C = (RB(7) < 0x0C); goto L_C024; }
    L_C024:
    RB(5) = RB(6);
    ADDC8(0x02);
}

void g_C028(void)
{
    STACK[++SP] = DIR(0x30);
    A ^= 0x41;
    g_2000();
    return;
}

void g_C02B(void)
{
    if (!BIT_RAM(0x64)) goto L_C06F;
    g_2000();
    return;
    L_C06F:
    RB(0) = 0xA3;
    A = 0x40;
    RB(0) = 0xE0;
    A = 0x1F;
    if (BIT_RAM(0x40)) goto L_C07B;
    RB(0)++;
    L_C07B:
    RB(0)--;
    return;
}

void g_C040(void)
{
    RB(0) = A;
    if (A != 0x06) { C = (A < 0x06); goto L_C08A; }
    DIR(0x48) = RB(2);
    DIR(0x49) = RB(3);
    if (A != 0) goto L_C08D;
    g_C218();
    return;
    L_C08D:
    A = (A << 1) | (A >> 7);
    SUBB8(RB(3));
    g_C0CB();
    return;
    L_C08A:
    RB(7)++;
    DIR(0x33) = STACK[SP--];
}

void g_C062(void)
{
    return;
}

void g_C078(void)
{
    if (C != 0) goto L_C07B;
    RB(0)++;
    L_C07B:
    RB(0)--;
    return;
}

void g_C0CB(void)
{
    RB(0)--;
    ADDC8(RB(1));
    A &= RB(4);
    g_2319();
    return;
}

void g_C0D1(void)
{
    DIR(0x39) |= 0x54;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    A = XD(DPTR);
    ADD8(RB(3));
    if (((SFR_80 >> 0) & 1)) goto L_C0DB;
    RB(0)++;
    L_C0DB:
    RB(0)--;
    RB(3) = 0x01;
    ADD8(RB(0));
    g_C0D1();
    return;
}

void g_C108(void)
{
    g_2807();
    return;
}

void g_C119(void)
{
    RB(4) = A;
    RB(0) = A;
    if (RB(5) != 0x22) { C = (RB(5) < 0x22); goto L_C193; }
    RB(0) = A;
    if (RB(5) != 0x20) { C = (RB(5) < 0x20); goto L_C19E; }
    g_2806();
    return;
    L_C19E:
    g_C02B();
    return;
    L_C193:
    if (((SFR_C8 >> 3) & 1)) goto L_C213;
    if (A == 0) goto L_C1DB;
    g_2700();
    return;
    L_C1DB:
    XD(DPTR) = A;
    A = RB(5);
    RB(3) = A;
    RB(0) = A;
    if (RB(5) != 0x5B) { C = (RB(5) < 0x5B); goto L_C25A; }
    A = RB(0);
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    tmp = A; A = RB(6); RB(6) = tmp;
    RB(3) = 0x7D;
    A &= RB(3);
    RB(4)--;
    if (--RB(3)) goto L_C19E;
    A = (A >> 1) | (A << 7);
    RB(2) = 0x2B;
    RB(7)++;
    C = 1;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    if (((SFR_C0 >> 0) & 1)) goto L_C1F7;
    DIR(0x75) = RB(6);
    if (BIT_RAM(0x18)) { BIT_SET(0x18, 0); goto L_C17B; }
    A ^= RB(3);
    goto L_C1FF;
    L_C1FF:
    if (--DIR(0x2B)) goto L_C222;
    L_C222:
    A ^= RB(3);
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(0)--;
    if (A != 0) goto L_C281;
    return;
    L_C281:
    g_C202();
    return;
    L_C17B:
    return;
    L_C1F7:
    DIR(0x10) = 0x18;
    goto L_C267;
    L_C267:
    if (A != 0) goto L_C26B;
    XD(DPTR) = A;
    if (RB(6) != 0xFB) { C = (RB(6) < 0xFB); goto L_C272; }
    C = C && (!BIT_RAM(0x00));
    if (RB(5) != 0xCC) { C = (RB(5) < 0xCC); goto L_C281; }
    L_C272:
    C = C || (!BIT_RAM(0x13));
    g_20E4();
    return;
    L_C26B:
    RB(3) = A;
    SFR_B0++;
    L_C25A:
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    DIR(0x09) = STACK[SP--];
    A |= RB(0);
    g_C078();
    return;
    L_C213:
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    A--;
    RB(7) = A;
}

void g_C202(void)
{
    goto L_C205;
    L_C205:
    RB(0)--;
    RB(3) = 0x01;
    ADD8(RB(0));
    g_D120();
    return;
}

void g_C218(void)
{
    RB(0) = A;
    if (RB(5) != 0xCF) { C = (RB(5) < 0xCF); goto L_C291; }
    RB(1) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    if (A != 0x85) { C = (A < 0x85); goto L_C1D2; }
    A ^= RB(3);
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(0)--;
    if (A != 0) goto L_C281;
    return;
    L_C281:
    g_C202();
    return;
    L_C1D2:
    ADD8(RB(3));
    A |= RB(3);
    EC_UNSUPPORTED();
    return;
    L_C291:
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    RB(1)++;
    RB(6)++;
    SUBB8(RB(1));
    if (C != 0) goto L_C297;
    L_C297:
    ADD8(RB(0));
    RB(3)++;
    if (--RB(2)) goto L_C29B;
    L_C29B:
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    RB(7)++;
    RB(0)++;
    ADDC8(RB(0));
    A = CD(0xC2A1 + A);
    RB(0)++;
    STACK[++SP] = DIR(0x48);
    SUBB8(RB(3));
    RB(0)--;
    RB(0)--;
    C = 0;
    A ^= RB(1);
    A = CD(DPTR + A);
    DIR(0x0B) |= 0x43;
    C = 0;
    g_C370();
    return;
}

void g_C261(void)
{
    ADD8(RB(1));
    A = (A >> 1) | (A << 7);
    EC_UNSUPPORTED();
    g_C021();
    return;
}

void g_C302(void)
{
    ADDC8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    g_8919();
    return;
}

void g_C318(void)
{
    A = RB(5);
    C = 1;
    g_C108();
    return;
}

void g_C36A(void)
{
    RB(2) = DIR(0x43);
    RB(2)++;
    if (A == 0) goto L_C3D0;
    A ^= RB(2);
    L_C3D0:
    DPTR = 0x4D8F;
    A |= RB(2);
    SUBB8((DIR(0x2A)));
    SFR_FF ^= A;
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    DIR(0x4A) = RB(7);
    g_C633();
    return;
}

void g_C370(void)
{
    EC_UNSUPPORTED();
    RB(4) |= 0xE0;
    RB(2)++;
    A ^= RB(0);
    ADD8(RB(2));
    DIR(0x0A) |= 0x60;
    g_C36A();
    return;
}

void g_C38A(void)
{
    SUBB8((DIR(0x48)));
    A = CD(DPTR + A);
    A |= RB(1);
    g_C661();
    return;
}

void g_C3B8(void)
{
    tmp = A; A = RB(5); RB(5) = tmp;
    RB(7)--;
    RB(1) = A;
    ADDC8(RB(5));
    EC_UNSUPPORTED();
    A |= RB(2);
    A++;
    SUBB8((DIR(0x2A)));
    RB(3) ^= 0x46;
    DPTR = 0x4A40;
    ADDC8(RB(3));
    SUBB8(RB(2));
    SFR_90 ^= A;
    A |= RB(2);
    goto L_C401;
    L_C401:
    A |= RB(3);
    A = CD(DPTR + A);
    if (A == 0) goto L_C390;
    A |= RB(3);
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    g_C302();
    return;
    L_C390:
    SUBB8(0x49);
    g_C062();
    return;
}

void g_C633(void)
{
    if (BIT_RAM(0x5D)) goto L_C685;
    g_2061();
    return;
    L_C685:
    A ^= RB(2);
    if (((SFR_B0 >> 7) & 1)) goto L_C6EF;
    g_2051();
    return;
    L_C6EF:
    if (BIT_RAM(0x7C)) goto L_C6F8;
    g_206D();
    return;
    L_C6F8:
    ADDC8(RB(1));
    RB(2) ^= 0x20;
    EC_UNSUPPORTED();
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_20F8();
    return;
}

void g_C661(void)
{
    A |= RB(7);
    g_20CF();
    return;
}

void g_C828(void)
{
    SUBB8(RB(6));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
}

void g_C82A(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = 0x4B;
}

void g_C82D(void)
{
    ADD8(0x5D);
    SFR_ED |= 0x19;
    RB(2)++;
    ADD8(XD(((unsigned int)SFR_A0 << 8) | RB(1)));
    A |= RB(7);
    SFR_EB |= 0x19;
    A &= RB(4);
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    g_C893();
    return;
}

void g_C843(void)
{
    A |= RB(7);
    g_C823();
    return;
}

void g_C893(void)
{
    SUBB8(RB(2));
    g_5C00();
    ADD8(RB(2));
    RB(1) = STACK[SP--];
    ADD8(0x40);
    RB(4)--;
    RB(2)++;
    ADD8(RB(0));
    A = RB(5);
    C = 1;
    g_9800();
    return;
}

void g_C896(void)
{
    ADD8(RB(2));
    RB(1) = STACK[SP--];
    ADD8(0x40);
    RB(4)--;
    RB(2)++;
    ADD8(RB(0));
    A = RB(5);
    C = 1;
    g_9800();
    return;
}

void g_C89A(void)
{
    g_C824();
    return;
}

void g_C8C9(void)
{
    XD(DPTR) = A;
    A = (A << 4) | (A >> 4);
    RB(0) = A;
    A++;
    DPTR = 0x0922;
    g_CB1C();
    return;
}

void g_C8D2(void)
{
    A ^= RB(0);
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_F076();
    return;
}

void g_C8F0(void)
{
    RB(7) = 0xE0;
    RB(7)++;
    if (BIT_RAM(0x44)) goto L_C940;
    goto L_C8F9;
    L_C8F9:
    A |= RB(7);
    RB(3)++;
    RB(0)--;
    A ^= RB(2);
    SFR_D2 |= 0x19;
    ADD8(RB(3));
    if (((SFR_80 >> 0) & 1)) goto L_C905;
    ec_jump_bank1((unsigned int)DPTR + A);
    return;
    L_C905:
    ADD8(XD(((unsigned int)SFR_A0 << 8) | RB(1)));
    if (--RB(6)) goto L_C983;
    L_C983:
    ADD8(RB(1));
    g_D007();
    return;
    L_C940:
    A ^= RB(1);
    A &= RB(0);
    ADD8(RB(1));
    RB(4)--;
    EC_UNSUPPORTED();
    EC_UNSUPPORTED();
    RB(1) = 0x01;
    ADD8(RB(1));
    RB(1)++;
    RB(2) = STACK[SP--];
    ADD8(RB(1));
    RB(5)++;
    DIR(0x69) = STACK[SP--];
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A |= RB(1);
    DIR(0x0A) = RB(0);
}

void g_C908(void)
{
    if (BIT_RAM(0x18)) { BIT_SET(0x18, 0); goto L_C98A; }
    g_C8D2();
    return;
    L_C98A:
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    A = XD(DPTR);
    A ^= RB(2);
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    EC_UNSUPPORTED();
    SFR_C9 = RB(0);
    A++;
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(4)++;
    EC_UNSUPPORTED();
    goto L_C997;
    L_C997:
    RB(3) = 0x01;
    ADD8(RB(0));
    g_C8D1();
    return;
}

void g_C918(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    RB(7) = STACK[SP--];
    return;
}

void g_C920(void)
{
    A |= RB(1);
    A ^= RB(3);
    tmp = A; A = RB(1); RB(1) = tmp;
    A |= RB(1);
    RB(7)++;
    A = (A >> 1) | (A << 7);
    EC_UNSUPPORTED();
}

void g_C928(void)
{
    ADD8(RB(2));
    A = XD(DPTR);
    EC_UNSUPPORTED();
    RB(1) = 0x03;
    ADD8(RB(1));
    ADD8(XD(((unsigned int)SFR_A0 << 8) | RB(1)));
    C = 1;
    A ^= RB(2);
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    EC_UNSUPPORTED();
    SFR_C9 = RB(0);
    RB(0)++;
    tmp = A; A = RB(1); RB(1) = tmp;
    ADD8(RB(1));
    DIR(0x20) |= 0xE0;
    RB(1) = RB(0);
    A |= RB(1);
    A |= RB(5);
    A ^= RB(1);
    A &= RB(0);
    ADD8(RB(1));
    RB(4)--;
    EC_UNSUPPORTED();
    EC_UNSUPPORTED();
    RB(1) = 0x01;
    ADD8(RB(1));
    RB(1)++;
    RB(2) = STACK[SP--];
    ADD8(RB(1));
    RB(5)++;
    DIR(0x69) = STACK[SP--];
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A |= RB(1);
    DIR(0x0A) = RB(0);
}

void g_C955(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    RB(7)++;
    if (--SFR_C9) goto L_C962;
    tmp = A; A = RB(1); RB(1) = tmp;
    A |= RB(1);
    RB(4)--;
    RB(5)++;
    A = XD(DPTR);
    A ^= RB(2);
    L_C962:
    EC_UNSUPPORTED();
    SFR_C9 = RB(0);
    RB(0)++;
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(1)++;
    RB(5)--;
    RB(0)++;
    A = XD(DPTR);
    A ^= RB(2);
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    EC_UNSUPPORTED();
}

void g_C959(void)
{
    RB(0)++;
    tmp = A; A = RB(1); RB(1) = tmp;
    A |= RB(1);
    RB(4)--;
    RB(5)++;
    A = XD(DPTR);
    A ^= RB(2);
}

void g_C961(void)
{
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    EC_UNSUPPORTED();
    SFR_C9 = RB(0);
    RB(0)++;
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(1)++;
    RB(5)--;
    RB(0)++;
    A = XD(DPTR);
    A ^= RB(2);
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    EC_UNSUPPORTED();
}

void g_C96F(void)
{
    SFR_C9 = RB(0);
    RB(0)++;
    tmp = A; A = RB(1); RB(1) = tmp;
    A |= RB(1);
    RB(5)--;
    g_E0C9();
    return;
}

void g_C979(void)
{
    RB(0)++;
    tmp = A; A = RB(1); RB(1) = tmp;
    A ^= RB(2);
}

void g_C97D(void)
{
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    EC_UNSUPPORTED();
    goto L_C9DA;
    L_C9DA:
    DIR(0x18) = RB(1);
    RB(1)++;
    RB(1) = 0x02;
    ADD8(RB(1));
    EC_UNSUPPORTED();
    A = (A >> 1) | (A << 7);
    if (((SFR_98 >> 1) & 1)) { g_C96F(); return; }
    g_C843();
    return;
}

void g_C9FF(void)
{
    RB(0) = A;
    g_F034();
    return;
}

void g_CA78(void)
{
    g_CC76();
    return;
}

void g_CB1C(void)
{
    A = (A >> 1) | (A << 7);
    RB(1) = STACK[SP--];
    g_C9FF();
    return;
}

void g_CC76(void)
{
    g_2070();
    return;
}

void g_D001(void)
{
    RB(0)--;
    goto L_D07C;
    L_D07C:
    A |= RB(3);
    RB(5) = A;
    ADDC8(RB(4));
    A |= RB(0);
    if (C != 0) goto L_D0DF;
    RB(0) = A;
    if (RB(5) != 0x70) { C = (RB(5) < 0x70); goto L_D03B; }
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADDC8(RB(3));
    A |= RB(0);
    ADDC8(RB(2));
    A |= RB(1);
    if (A != 0) goto L_D0D1;
    A |= DIR(0x18);
    L_D0D1:
    RB(3) = 0x00;
    ADD8(RB(0));
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    EC_UNSUPPORTED();
    SUBB8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    ADD8(0xE5);
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    ADD8(0xE3);
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    if (A != 0) goto L_D095;
    L_D095:
    RB(0)--;
    STACK[++SP] = DIR(0x7A);
    RB(7) = A;
    ADD8(0x01);
    L_D03B:
    RB(5) = A;
    ADD8(RB(0));
    g_D0D0();
    return;
    L_D0DF:
    if (A != 0x0B) { C = (A < 0x0B); goto L_D06A; }
    A++;
    L_D06A:
    ADDC8(RB(0));
    RB(0)--;
    RB(0) = 0x80;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    g_D081();
    return;
}

void g_D003(void)
{
    RB(0) = 0x00;
    ADD8(RB(0));
    g_D0D0();
    return;
}

void g_D010(void)
{
    ADDC8(RB(4));
    RB(0)--;
    A = XD(DPTR);
    RB(2) = 0x00;
    ADD8(RB(0));
    A++;
    EC_UNSUPPORTED();
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_D0F0();
    return;
}

void g_D021(void)
{
    EC_UNSUPPORTED();
    A &= DIR(0x49);
    DIR(0x4B) &= 0x07;
    if (BIT_RAM(0x69)) goto L_D06D;
    L_D06D:
    RB(0) = 0x80;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    g_D081();
    return;
}

void g_D026(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    if (BIT_RAM(0x69)) goto L_D06D;
    L_D06D:
    RB(0) = 0x80;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    g_D081();
    return;
}

void g_D029(void)
{
    SFR_E2 |= 0x7A;
    STACK[++SP] = RB(1);
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(0)--;
    RB(6)++;
    RB(0)--;
    g_D02A();
    return;
}

void g_D02A(void)
{
    A = XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(2) = 0xC0;
    g_D0C9();
    return;
}

void g_D040(void)
{
    ADDC8(XD(((unsigned int)SFR_A0 << 8) | RB(1)));
    g_D119();
    return;
}

void g_D056(void)
{
    g_D0E0();
    return;
}

void g_D081(void)
{
    A &= RB(5);
    RB(0) = A;
    if (RB(5) != 0x70) { C = (RB(5) < 0x70); goto L_D03B; }
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADDC8(RB(3));
    A |= RB(0);
    ADDC8(RB(2));
    A |= RB(1);
    if (A != 0) goto L_D0D1;
    A |= DIR(0x18);
    L_D0D1:
    RB(3) = 0x00;
    ADD8(RB(0));
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    EC_UNSUPPORTED();
    SUBB8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    ADD8(0xE5);
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    ADD8(0xE3);
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    if (A != 0) goto L_D095;
    L_D095:
    RB(0)--;
    STACK[++SP] = DIR(0x7A);
    RB(7) = A;
    ADD8(0x01);
    L_D03B:
    RB(5) = A;
    ADD8(RB(0));
    g_D0D0();
    return;
}

void g_D090(void)
{
    ADD8(RB(3));
    if (((SFR_80 >> 0) & 1)) goto L_D095;
    ADD8(RB(0));
    L_D095:
    RB(0)--;
    STACK[++SP] = DIR(0x7A);
    RB(7) = A;
    ADD8(0x01);
}

void g_D09B(void)
{
    ADD8(RB(0));
    PSW++;
    if (!BIT_RAM(0x46)) goto L_D0A2;
    XD(DPTR) = A;
    L_D0A2:
    SUBB8(RB(0));
    RB(5) = A;
    A++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    if (BIT_RAM(0x46)) { g_D119(); return; }
    if (RB(5) != 0x2D) { C = (RB(5) < 0x2D); goto L_D0CC; }
    goto L_D0AF;
    L_D0AF:
    RB(0)--;
    STACK[++SP] = DIR(0x7B);
    ADD8(RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    DIR(0x30) = STACK[SP--];
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_D0F0();
    return;
    L_D0CC:
    if (C != 0) goto L_D0CF;
    ADD8(RB(0));
    L_D0CF:
    RB(0)--;
}

void g_D0AA(void)
{
    ADD8(RB(5));
    if (((SFR_80 >> 0) & 1)) goto L_D0AF;
    ADD8(RB(0));
    L_D0AF:
    RB(0)--;
    STACK[++SP] = DIR(0x7B);
    ADD8(RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    DIR(0x30) = STACK[SP--];
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_D0F0();
    return;
}

void g_D0C9(void)
{
    DIR(0x67) = STACK[SP--];
    if (BIT_RAM(0x40)) goto L_D0CF;
    ADD8(RB(0));
    L_D0CF:
    RB(0)--;
}

void g_D0D0(void)
{
    STACK[++SP] = DIR(0x7B);
    ADD8(RB(0));
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    EC_UNSUPPORTED();
    SUBB8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    ADD8(0xE5);
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    ADD8(0xE3);
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    if (A != 0) goto L_D095;
    L_D095:
    RB(0)--;
    STACK[++SP] = DIR(0x7A);
    RB(7) = A;
    ADD8(0x01);
}

void g_D0E0(void)
{
    RB(3)++;
    RB(4) = RB(0);
}

void g_D0E3(void)
{
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_D026();
    return;
}

void g_D0F0(void)
{
    if (--RB(3)) goto L_D0FD;
    g_4635();
    return;
    L_D0FD:
    RB(0) = STACK[SP--];
    ADD8(RB(3));
    PSW--;
    g_D1E0();
    return;
}

void g_D119(void)
{
    A |= RB(0);
    if (BIT_RAM(0x18)) goto L_D153;
    ADD8(RB(1));
    g_D056();
    return;
    L_D153:
    RB(5) = A;
    ADD8(RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    DIR(0x1C) = STACK[SP--];
    g_D14C();
    return;
}

void g_D120(void)
{
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8(RB(1));
    g_D010();
    return;
}

void g_D128(void)
{
    RB(6)++;
    A = XD(DPTR);
    tmp = A; A = DIR(0x72); DIR(0x72) = tmp;
    RB(4)++;
    A = XD(DPTR);
    g_D029();
    return;
}

void g_D14C(void)
{
    if (((SFR_B0 >> 5) & 1)) { SFR_B0 = (SFR_B0 & ~(1 << 5)) | (((0) & 1) << 5); goto L_D153; }
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_D0F0();
    return;
    L_D153:
    RB(5) = A;
    ADD8(RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    DIR(0x1C) = STACK[SP--];
    g_D14C();
    return;
}

void g_D17D(void)
{
    ADDC8(0x02);
    if (BIT_RAM(0x70)) goto L_D1C7;
    RB(1)++;
    return;
    L_D1C7:
    if (A != 0x04) { C = (A < 0x04); goto L_D210; }
    A = ~A;
    A |= RB(6);
    RB(0)++;
    SUBB8(RB(7));
    ADDC8((DIR(0x5D)));
    RB(1)++;
    SUBB8(RB(0));
    ADD8(RB(1));
    ADD8(0xD1);
    g_D090();
    return;
    L_D210:
    tmp = A; A = RB(1); RB(1) = tmp;
    g_D040();
    return;
}

void g_D180(void)
{
    if (A != 0) goto L_D1C7;
    RB(1)++;
    return;
    L_D1C7:
    if (A != 0x04) { C = (A < 0x04); goto L_D210; }
    A = ~A;
    A |= RB(6);
    RB(0)++;
    SUBB8(RB(7));
    ADDC8((DIR(0x5D)));
    RB(1)++;
    SUBB8(RB(0));
    ADD8(RB(1));
    ADD8(0xD1);
    g_D090();
    return;
    L_D210:
    tmp = A; A = RB(1); RB(1) = tmp;
    g_D040();
    return;
}

void g_D189(void)
{
    if (A == 0) goto L_D18D;
    if (BIT_RAM(0x10)) goto L_D143;
    A++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    L_D143:
    DIR(0x11) = RB(2);
    RB(1) |= 0x82;
    if (!BIT_RAM(0x46)) goto L_D1BB;
    if (RB(5) != 0x10) { C = (RB(5) < 0x10); goto L_D103; }
    A++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_D0F0();
    return;
    L_D103:
    A = XD(DPTR);
    if (BIT_RAM(0x29)) { BIT_SET(0x29, 0); goto L_D126; }
    EC_UNSUPPORTED();
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(1));
    g_D120();
    return;
    L_D126:
    DIR(0x0E) = DIR(0x72);
    A = XD(DPTR);
    tmp = A; A = DIR(0x72); DIR(0x72) = tmp;
    RB(4)++;
    A = XD(DPTR);
    g_D029();
    return;
    L_D1BB:
    ADD8(RB(0));
    g_D0D0();
    return;
    L_D18D:
    if (A != 0x04) { C = (A < 0x04); goto L_D1D6; }
    L_D1D6:
    g_D090();
    return;
}

void g_D190(void)
{
    g_D0F0();
    return;
}

void g_D193(void)
{
    RB(5) = A;
    ADD8(RB(0));
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    DIR(0x1C) = STACK[SP--];
    g_D14C();
    return;
}

void g_D1C9(void)
{
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A = ~A;
    A |= RB(6);
    RB(0)++;
    SUBB8(RB(7));
    ADDC8((DIR(0x5D)));
    RB(1)++;
    SUBB8(RB(0));
    ADD8(RB(1));
    ADD8(0xD1);
    g_D090();
    return;
}

void g_D1E0(void)
{
    A = RB(7);
    A |= RB(0);
    XD(DPTR) = A;
    A |= RB(1);
    if (A == 0) goto L_D229;
    if (C != 0) goto L_D200;
    ADD8(RB(5));
    g_D189();
    return;
    L_D200:
    RB(6)++;
    if (--RB(1)) goto L_D20E;
    g_D109();
    return;
    L_D20E:
    RB(5)--;
    g_D1C9();
    return;
    L_D229:
    RB(4) = A;
    if (--RB(5)) goto L_D274;
    if (--RB(5)) goto L_D277;
    if (A == 0) goto L_D273;
    g_D218();
    return;
    L_D273:
    DIR(0x08) |= 0x82;
    ADD8((DIR(0x21)));
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_D0F0();
    return;
    L_D277:
    g_D128();
    return;
    L_D274:
    RB(0)++;
    C = C && (BIT_RAM(0x25));
}

void g_D218(void)
{
    g_D020();
    return;
}

void g_D243(void)
{
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_D0F0();
    return;
}

void g_D318(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    SUBB8(RB(0));
    g_D0F0();
    return;
}

void g_D36C(void)
{
    g_D0D0();
    return;
}

void g_D400(void)
{
    if (C != 0) goto L_D403;
    if (BIT_RAM(0x18)) goto L_D385;
    DIR(0x41) = RB(1);
    A++;
    BIT_SET(0x06, 0);
    ADD8(RB(1));
    if (((SFR_80 >> 0) & 1)) goto L_D40F;
    A |= RB(3);
    L_D40F:
    RB(7)++;
    if (BIT_RAM(0x18)) goto L_D414;
    RB(3) = 0xD2;
    RB(6)++;
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_D0F0();
    return;
    L_D414:
    BIT_SET(0x0E, 1);
    L_D385:
    g_D040();
    return;
    L_D403:
    RB(0)--;
    goto L_D38F;
    L_D38F:
    ADD8(RB(7));
    g_D988();
    return;
}

void g_D440(void)
{
    EC_UNSUPPORTED();
    RB(4) = A;
}

void g_D442(void)
{
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A |= RB(0);
    if (C != 0) goto L_D4A3;
    ADDC8(RB(0));
    if (RB(5) != 0xFF) { C = (RB(5) < 0xFF); goto L_D3FF; }
    A = CD(0xD44B + A);
    C = C && (!((SFR_88 >> 0) & 1));
    RB(7)++;
    SFR_9A++;
    A = (A >> 1) | (A << 7);
    ADD8(RB(0));
    g_D190();
    return;
    L_D3FF:
    if (BIT_RAM(0x40)) goto L_D403;
    if (BIT_RAM(0x18)) goto L_D385;
    DIR(0x41) = RB(1);
    A++;
    BIT_SET(0x06, 0);
    ADD8(RB(1));
    if (((SFR_80 >> 0) & 1)) goto L_D40F;
    A |= RB(3);
    L_D40F:
    RB(7)++;
    if (BIT_RAM(0x18)) goto L_D414;
    RB(3) = 0xD2;
    RB(6)++;
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_D0F0();
    return;
    L_D414:
    BIT_SET(0x0E, 1);
    L_D385:
    g_D040();
    return;
    L_D403:
    RB(0)--;
    goto L_D38F;
    L_D38F:
    ADD8(RB(7));
    g_D988();
    return;
    L_D4A3:
    A++;
    RB(6)++;
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    RB(6)++;
    SUBB8(RB(0));
    DIR(0x10) |= A;
    C = 1;
    ADDC8(RB(4));
    A |= RB(2);
    A = (A >> 1) | (A << 7);
    SUBB8(RB(0));
    ADDC8(RB(4));
    A |= RB(4);
    if (C == 0) goto L_D4F7;
    ADD8(RB(3));
    return;
    L_D4F7:
    RB(0)--;
    ADD8(RB(3));
    if (((SFR_80 >> 0) & 1)) goto L_D4FD;
    if (BIT_RAM(0x18)) goto L_D4BF;
    RB(2) = 0x00;
    ADD8(RB(0));
    A = (A >> 1) | (A << 7);
    EC_UNSUPPORTED();
    g_D128();
    return;
    L_D4BF:
    RB(5) |= A;
    if (--RB(0)) goto L_D456;
    RB(3) |= A;
    if (--RB(0)) goto L_D4CD;
    SUBB8(RB(3));
    SUBB8(RB(2));
    SUBB8(RB(2));
    RB(1) |= A;
    L_D4CD:
    if (--RB(1)) goto L_D4D2;
    if (BIT_RAM(0x7C)) goto L_D4B9;
    L_D4D2:
    DIR(0x42) = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    C = 1;
    if (BIT_RAM(0x58)) goto L_D459;
    g_D081();
    return;
    L_D459:
    RB(6) = STACK[SP--];
    SUBB8(RB(3));
    A = (A >> 1) | (A << 7);
    SUBB8(RB(0));
    g_D0F0();
    return;
    L_D4B9:
    g_D0AA();
    return;
    L_D456:
    A = (A >> 1) | (A << 7);
    ADD8(RB(0));
    A++;
    L_D4FD:
    RB(0)--;
    STACK[++SP] = DIR(0x7A);
}

void g_D47B(void)
{
    RB(4) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    SFR_98++;
    g_D090();
    return;
}

void g_D500(void)
{
    ADD8(RB(0));
    A = (A >> 1) | (A << 7);
    EC_UNSUPPORTED();
    g_D128();
    return;
}

void g_D564(void)
{
    if (!BIT_RAM(0x46)) goto L_D5D7;
    if (RB(5) != 0x70) { C = (RB(5) < 0x70); goto L_D51F; }
    DIR(0x46)++;
    g_D021();
    return;
    L_D51F:
    RB(3) = A;
    if (A != 0) goto L_D4DF;
    if (A != 0) goto L_D4D9;
    DIR(0x46)++;
    g_D0F0();
    return;
    L_D4D9:
    g_D081();
    return;
    L_D4DF:
    RB(5)++;
    if (RB(0) != 0x42) { C = (RB(0) < 0x42); goto L_D4E4; }
    if (--RB(1)) goto L_D4E6;
    if (BIT_RAM(0x71)) goto L_D4CF;
    if (BIT_RAM(0x6F)) goto L_D4D3;
    if (A != 0) goto L_D4A3;
    DIR(0x46)++;
    ADD8(RB(3));
    A |= RB(0);
    ADD8(RB(4));
    A |= RB(1);
    A ^= RB(0);
    DIR(0x44) |= 0x18;
    ADD8(RB(3));
    if (((SFR_80 >> 0) & 1)) goto L_D4FD;
    if (BIT_RAM(0x18)) goto L_D4BF;
    RB(2) = 0x00;
    ADD8(RB(0));
    A = (A >> 1) | (A << 7);
    EC_UNSUPPORTED();
    g_D128();
    return;
    L_D4BF:
    RB(5) |= A;
    if (--RB(0)) goto L_D456;
    RB(3) |= A;
    if (--RB(0)) goto L_D4CD;
    SUBB8(RB(3));
    SUBB8(RB(2));
    SUBB8(RB(2));
    RB(1) |= A;
    L_D4CD:
    if (--RB(1)) goto L_D4D2;
    L_D4CF:
    if (BIT_RAM(0x7C)) goto L_D4B9;
    L_D4D2:
    DIR(0x42) = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    C = 1;
    if (BIT_RAM(0x58)) goto L_D459;
    L_D459:
    RB(6) = STACK[SP--];
    SUBB8(RB(3));
    A = (A >> 1) | (A << 7);
    SUBB8(RB(0));
    g_D0F0();
    return;
    L_D4B9:
    g_D0AA();
    return;
    L_D456:
    A = (A >> 1) | (A << 7);
    ADD8(RB(0));
    A++;
    L_D4FD:
    RB(0)--;
    STACK[++SP] = DIR(0x7A);
    L_D4A3:
    A++;
    RB(6)++;
    tmp = (A & 1); A = (A >> 1) | (C << 7); C = tmp;
    RB(6)++;
    SUBB8(RB(0));
    DIR(0x10) |= A;
    C = 1;
    ADDC8(RB(4));
    A |= RB(2);
    A = (A >> 1) | (A << 7);
    SUBB8(RB(0));
    ADDC8(RB(4));
    A |= RB(4);
    if (C == 0) goto L_D4F7;
    ADD8(RB(3));
    return;
    L_D4F7:
    RB(0)--;
    L_D4D3:
    RB(6) |= A;
    L_D4E6:
    EC_UNSUPPORTED();
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    L_D4E4:
    g_D020();
    return;
    L_D5D7:
    g_D128();
    return;
}

void g_D5CF(void)
{
    g_D003();
    return;
}

void g_D820(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    SUBB8(RB(3));
}

void g_D822(void)
{
    RB(4)--;
    ADD8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    ec_jump_bank1((unsigned int)DPTR + A);
    return;
}

void g_D828(void)
{
    RB(7) = A;
    ADD8(0x9B);
    RB(1)--;
    DIR(0x46)--;
    DIR(0x34)--;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    A = CD(DPTR + A);
    g_D820();
    return;
}

void g_D82A(void)
{
    SUBB8(RB(3));
    RB(1)--;
    DIR(0x46)--;
    DIR(0x34)--;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    A = CD(DPTR + A);
    g_D820();
    return;
}

void g_D839(void)
{
    DIR(0x7D) |= A;
    RB(7) = STACK[SP--];
    if (--RB(4)) goto L_D7D0;
    L_D7D0:
    g_D0F0();
    return;
}

void g_D83F(void)
{
    RB(4)--;
    g_D8D0();
    return;
}

void g_D891(void)
{
    EC_UNSUPPORTED();
    A--;
    if (BIT_RAM(0x60)) goto L_D8D9;
    ADDC8(RB(0));
    RB(0)--;
    A--;
    g_D901();
    return;
    L_D8D9:
    SUBB8(RB(0));
    g_D8F0();
    return;
}

void g_D8D0(void)
{
    if (BIT_RAM(0x46)) goto L_D936;
    if (!((SFR_C0 >> 1) & 1)) goto L_D888;
    return;
    L_D888:
    ADD8(RB(1));
    RB(5)++;
    EC_UNSUPPORTED();
    A ^= RB(0);
    RB(0) = 0x40;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    RB(2)++;
    L_D936:
    g_D8E0();
    return;
}

void g_D8D1(void)
{
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DIR(0x30) ^= 0xC1;
    BIT_SET(0x00, !BIT_RAM(0x00));
    return;
}

void g_D8E0(void)
{
    g_D8F0();
    return;
}

void g_D8F0(void)
{
    if (--RB(2)) goto L_D8C5;
    SFR_98++;
    ADD8(RB(0));
    ADD8(0xD0);
    A ^= RB(0);
    RB(0) = 0xC0;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    L_D8C5:
    DIR(0x10) |= A;
    EC_UNSUPPORTED();
    A--;
    return;
}

void g_D8FC(void)
{
    A = (A >> 1) | (A << 7);
    RB(4) = STACK[SP--];
    g_D907();
    return;
}

void g_D901(void)
{
    SUBB8(RB(0));
    g_D8F0();
    return;
}

void g_D907(void)
{
    RB(0) = 0x40;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    goto L_D91B;
    L_D91B:
    g_3018();
    return;
}

void g_D920(void)
{
    ADD8(RB(0));
    if (((PSW >> 1) & 1)) { PSW = (PSW & ~(1 << 1)) | (((0) & 1) << 1); goto L_D934; }
    if (((SFR_80 >> 0) & 1)) goto L_D929;
    if (!BIT_RAM(0x18)) goto L_D92B;
    L_D92B:
    SFR_C0 = RB(0);
    RB(3)++;
    RB(2)++;
    RB(6) = STACK[SP--];
    SUBB8(RB(1));
    if (BIT_RAM(0x48)) goto L_D9AC;
    g_D8E0();
    return;
    L_D9AC:
    A++;
    ADD8(RB(1));
    RB(5)++;
    RB(5) = STACK[SP--];
    ADD8(RB(1));
    RB(2) = 0xD0;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    ADD8(RB(1));
    RB(1)--;
    DIR(0x10) = STACK[SP--];
    ADD8(RB(1));
    RB(6) = 0xD1;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    A = XD(DPTR);
    RB(3)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xD0;
    RB(4)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xD0;
    RB(6)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = 0xD1;
    EC_UNSUPPORTED();
    A = XD(DPTR);
    g_D82A();
    return;
    L_D929:
    RB(0)--;
    L_D934:
    A |= RB(0);
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x01;
    A = XD(DPTR);
    RB(1)++;
    A = XD(DPTR);
    A++;
    A = XD(DPTR);
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    SUBB8(RB(0));
    g_D8F0();
    return;
}

void g_D930(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    SUBB8(RB(1));
    if (BIT_RAM(0x48)) goto L_D9AC;
    g_D8E0();
    return;
    L_D9AC:
    A++;
    ADD8(RB(1));
    RB(5)++;
    RB(5) = STACK[SP--];
    ADD8(RB(1));
    RB(2) = 0xD0;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    ADD8(RB(1));
    RB(1)--;
    DIR(0x10) = STACK[SP--];
    ADD8(RB(1));
    RB(6) = 0xD1;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    A = XD(DPTR);
    RB(3)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xD0;
    RB(4)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xD0;
    RB(6)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = 0xD1;
    EC_UNSUPPORTED();
    A = XD(DPTR);
    g_D82A();
    return;
}

void g_D946(void)
{
    EC_UNSUPPORTED();
    SUBB8(RB(1));
    A = (A >> 1) | (A << 7);
    if (BIT_RAM(0x08)) goto L_D9AC;
    RB(1) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    SUBB8(RB(1));
    tmp = A; A = RB(3); RB(3) = tmp;
    C = C || (BIT_RAM(0x7A));
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    RB(4)--;
    g_D9B3();
    return;
    L_D9AC:
    A++;
    ADD8(RB(1));
    RB(5)++;
    RB(5) = STACK[SP--];
    ADD8(RB(1));
    RB(2) = 0xD0;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    ADD8(RB(1));
    RB(1)--;
    DIR(0x10) = STACK[SP--];
    ADD8(RB(1));
    RB(6) = 0xD1;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    A = XD(DPTR);
    RB(3)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xD0;
    RB(4)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xD0;
    RB(6)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = 0xD1;
    EC_UNSUPPORTED();
    A = XD(DPTR);
    g_D82A();
    return;
}

void g_D95D(void)
{
    RB(0)--;
    g_D822();
    return;
}

void g_D97F(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x70;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(1));
    RB(0) = A;
    if (A != 0x06) { C = (A < 0x06); goto L_D9CC; }
    g_D820();
    return;
    L_D9CC:
    g_D82A();
    return;
}

void g_D988(void)
{
    DPTR = 0xA948;
    RB(1) = DIR(0x4C);
    RB(4) = DIR(0x4B);
    if (A != 0) goto L_D9D5;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    RB(1)--;
    RB(0) = A;
    RB(0)--;
    L_D996:
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    A = (A << 1) | (A >> 7);
    SUBB8(RB(3));
    g_D8FC();
    return;
    L_D9D5:
    RB(7) = A;
    if (!BIT_RAM(0x46)) goto L_D9DA;
    XD(DPTR) = A;
    L_D9DA:
    if (--RB(2)) goto L_D9D5;
    if (!BIT_RAM(0x46)) goto L_D9E0;
    XD(DPTR) = A;
    L_D9E0:
    if (--RB(5)) goto L_D9DB;
    A++;
    if (BIT_RAM(0x60)) goto L_DA5D;
    if (BIT_RAM(0x00)) goto L_D97A;
    A ^= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A = XD(DPTR);
    g_D82A();
    return;
    L_D97A:
    RB(2) = DIR(0x4A);
    goto L_D996;
    L_DA5D:
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = 0x10;
    A = XD(DPTR);
    g_20E0();
    return;
    L_D9DB:
    RB(1) = A;
}

void g_D9B3(void)
{
    RB(6) = STACK[SP--];
    ADD8(RB(1));
    RB(1)--;
    DIR(0x10) = STACK[SP--];
    ADD8(RB(1));
    RB(6) = 0xD1;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    A = XD(DPTR);
    RB(3)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xD0;
    RB(4)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0xD0;
    RB(6)--;
    ADD8(RB(1));
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = 0xD1;
    EC_UNSUPPORTED();
    A = XD(DPTR);
    g_D82A();
    return;
}

void g_D9F1(void)
{
    A ^= RB(0);
    A = XD(DPTR);
    RB(6) = 0x00;
    ADD8(RB(0));
    A = (A >> 1) | (A << 7);
    SFR_88 = STACK[SP--];
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    g_D8D1();
    return;
}

void g_DA18(void)
{
    RB(1) = 0x18;
    EC_UNSUPPORTED();
    A ^= RB(0);
    A |= RB(0);
    if (A == 0) goto L_DA5F;
    g_D930();
    return;
    L_DA5F:
    A = XD(DPTR);
    g_20E0();
    return;
}

void g_DA43(void)
{
    RB(2) = 0x40;
    RB(6)--;
    A = (A >> 1) | (A << 7);
    ADD8(RB(0));
    RB(3)--;
    BIT_SET(0x0D, 1);
    if (BIT_RAM(0x04)) goto L_DA6F;
    g_2972();
    return;
    L_DA6F:
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x28;
    RB(2) = 0x04;
    ADD8(RB(0));
    SFR_D1++;
    ADD8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    g_D930();
    return;
}

void g_DB46(void)
{
    g_D8F0();
    return;
}

void g_DD1C(void)
{
    g_D828();
    return;
}

void g_E009(void)
{
    XD(DPTR) = A;
    ADDC8(RB(2));
    RB(7) = A;
    if (((SFR_B8 >> 5) & 1)) { SFR_B8 = (SFR_B8 & ~(1 << 5)) | (((0) & 1) << 5); goto L_E007; }
    if (A != 0x04) { C = (A < 0x04); goto L_E058; }
    RB(4)--;
    if (BIT_RAM(0x4E)) goto L_E05F;
    ADD8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    if (A == 0) goto L_E05D;
    if (C != 0) goto L_E034;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    C = C || (((SFR_E8 >> 7) & 1));
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    L_E034:
    if (C != 0) goto L_E04E;
    RB(1) = 0x01;
    ADD8(RB(0));
    XD(((unsigned int)SFR_A0 << 8) | RB(1))--;
    EC_UNSUPPORTED();
    g_E120();
    return;
    L_E04E:
    if (BIT_RAM(0x46)) goto L_E050;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    tmp = A; A = RB(6); RB(6) = tmp;
    RB(7) = A;
    ADDC8(RB(0));
    A &= RB(5);
    g_2808();
    return;
    L_E050:
    RB(7) = A;
    L_E05D:
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    L_E05F:
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    tmp = A; A = XD(((unsigned int)SFR_A0 << 8) | RB(1)); XD(((unsigned int)SFR_A0 << 8) | RB(1)) = tmp;
    RB(7) = A;
    A++;
    g_E120();
    return;
    L_E058:
    RB(0)++;
    EC_UNSUPPORTED();
    g_2120();
    return;
    L_E007:
    if (RB(5) != 0x00) { C = (RB(5) < 0x00); goto L_DFFA; }
    L_DFFA:
    if (BIT_RAM(0x32)) goto L_DFCF;
    RB(3) = 0x52;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    g_D500();
    return;
    L_DFCF:
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4)++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    RB(7) = A;
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4)--;
    g_D95D();
    return;
}

void g_E020(void)
{
    if (((SFR_80 >> 0) & 1)) { SFR_80 = (SFR_80 & ~(1 << 0)) | (((0) & 1) << 0); goto L_DFE8; }
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    A = RB(5);
    RB(7)++;
    C = C || (((SFR_B0 >> 6) & 1));
    L_DFE8:
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(DPTR) = A;
    ADDC8(RB(5));
    RB(7) = A;
    if (A != 0) goto L_DFAD;
    A &= DIR(0x4A);
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A |= RB(3);
    DIR(0x43) |= A;
    if (((SFR_B0 >> 5) & 1)) { SFR_B0 = (SFR_B0 & ~(1 << 5)) | (((0) & 1) << 5); goto L_DFCB; }
    RB(0)--;
    if (BIT_RAM(0x32)) goto L_DFCF;
    RB(3) = 0x52;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    g_D500();
    return;
    L_DFCF:
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4)++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    RB(7) = A;
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4)--;
    g_D95D();
    return;
    L_DFCB:
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(1));
    if (A != 0) goto L_DF83;
    DIR(0x46)++;
    L_DF83:
    ADD8(XD(((unsigned int)SFR_A0 << 8) | RB(1)));
    if (BIT_RAM(0x36)) goto L_DFB8;
    RB(7) = 0x25;
    SFR_C9 |= 0x07;
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(6)++;
    RB(3)++;
    DIR(0x2B) |= 0x43;
    g_DB46();
    return;
    L_DFB8:
    RB(2)--;
    A &= 0xCA;
    RB(1)++;
    if (--RB(2)) goto L_DFE1;
    g_E009();
    return;
    L_DFE1:
    RB(2) = 0x00;
    ADD8(RB(0));
    A = (A >> 1) | (A << 7);
    EC_UNSUPPORTED();
    g_D946();
    return;
    L_DFAD:
    ADD8(RB(2));
    A++;
    RB(7) = STACK[SP--];
    A = XD(DPTR);
    RB(2)++;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    if (--RB(1)) goto L_DFDA;
    L_DFDA:
    A &= RB(5);
    A |= RB(2);
    A |= RB(0);
    SFR_80 |= 0x18;
    if (C != 0) goto L_E05C;
    L_E05C:
    if (BIT_RAM(0x46)) goto L_E05E;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    tmp = A; A = XD(((unsigned int)SFR_A0 << 8) | RB(1)); XD(((unsigned int)SFR_A0 << 8) | RB(1)) = tmp;
    RB(7) = A;
    A++;
    g_E120();
    return;
    L_E05E:
    RB(7) = A;
}

void g_E021(void)
{
    goto L_DFE8;
    L_DFE8:
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(DPTR) = A;
    ADDC8(RB(5));
    RB(7) = A;
    if (A != 0) goto L_DFAD;
    A &= DIR(0x4A);
    A &= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A |= RB(3);
    DIR(0x43) |= A;
    if (((SFR_B0 >> 5) & 1)) { SFR_B0 = (SFR_B0 & ~(1 << 5)) | (((0) & 1) << 5); goto L_DFCB; }
    RB(0)--;
    if (BIT_RAM(0x32)) goto L_DFCF;
    RB(3) = 0x52;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    g_D500();
    return;
    L_DFCF:
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4)++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(7) = A;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    RB(7) = A;
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    RB(4)--;
    g_D95D();
    return;
    L_DFCB:
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(1));
    if (A != 0) goto L_DF83;
    DIR(0x46)++;
    L_DF83:
    ADD8(XD(((unsigned int)SFR_A0 << 8) | RB(1)));
    if (BIT_RAM(0x36)) goto L_DFB8;
    RB(7) = 0x25;
    SFR_C9 |= 0x07;
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(6)++;
    RB(3)++;
    DIR(0x2B) |= 0x43;
    g_DB46();
    return;
    L_DFB8:
    RB(2)--;
    A &= 0xCA;
    RB(1)++;
    if (--RB(2)) goto L_DFE1;
    g_E009();
    return;
    L_DFE1:
    RB(2) = 0x00;
    ADD8(RB(0));
    A = (A >> 1) | (A << 7);
    EC_UNSUPPORTED();
    g_D946();
    return;
    L_DFAD:
    ADD8(RB(2));
    A++;
    RB(7) = STACK[SP--];
    A = XD(DPTR);
    RB(2)++;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    if (--RB(1)) goto L_DFDA;
    L_DFDA:
    A &= RB(5);
    A |= RB(2);
    A |= RB(0);
    SFR_80 |= 0x18;
    if (C != 0) goto L_E05C;
    L_E05C:
    if (BIT_RAM(0x46)) goto L_E05E;
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    tmp = A; A = XD(((unsigned int)SFR_A0 << 8) | RB(1)); XD(((unsigned int)SFR_A0 << 8) | RB(1)) = tmp;
    RB(7) = A;
    A++;
    g_E120();
    return;
    L_E05E:
    RB(7) = A;
}

void g_E022(void)
{
    tmp = A; A = RB(7); RB(7) = tmp;
    A = RB(5);
    RB(7)++;
    C = C || (((SFR_B0 >> 6) & 1));
}

void g_E028(void)
{
    L_E028:
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(1));
    A |= RB(0);
    A |= RB(0);
    A |= RB(1);
    if (A == 0) goto L_E071;
    if (C != 0) goto L_E048;
    RB(7)--;
    L_E031:
    g_E149();
    return;
    L_E048:
    g_E028();
    return;
    L_E071:
    if (XD(((unsigned int)SFR_A0 << 8) | 0) != 0xF8) { C = (XD(((unsigned int)SFR_A0 << 8) | 0) < 0xF8); goto L_E031; }
    EC_UNSUPPORTED();
    if (A != 0x84) { C = (A < 0x84); goto L_E028; }
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    A |= RB(1);
    A++;
    SUBB8(RB(0));
    A |= RB(0);
    DIR(0x33) |= 0x49;
    A |= 0x18;
    DIR(0x20)--;
    STACK[++SP] = RB(1);
    if (BIT_RAM(0x18)) goto L_E049;
    A ^= RB(1);
    DPTR = 0x0498;
    RB(4)--;
    g_E148();
    return;
    L_E049:
    ADD8(RB(0));
    A = (A >> 1) | (A << 7);
    EC_UNSUPPORTED();
    g_2120();
    return;
}

void g_E02D(void)
{
    DIR(0x40) |= 0x18;
    RB(7)--;
    g_E149();
    return;
}

void g_E069(void)
{
    RB(7) = A;
    ADDC8(RB(6));
    A &= RB(0);
    ADD8(RB(5));
    EC_UNSUPPORTED();
    SFR_B6 ^= A;
    RB(0) = A;
    if (RB(5) != 0xF1) { C = (RB(5) < 0xF1); goto L_E02B; }
    if (B == 0) { C = 0; } else { tmp = A % B; A = A / B; B = tmp; C = 0; }
    C = C && (!BIT_RAM(0x33));
    A |= RB(1);
    A++;
    SUBB8(RB(0));
    A |= RB(0);
    DIR(0x33) |= 0x49;
    A |= 0x18;
    DIR(0x20)--;
    STACK[++SP] = RB(1);
    if (BIT_RAM(0x18)) goto L_E049;
    A ^= RB(1);
    DPTR = 0x0498;
    RB(4)--;
    g_E148();
    return;
    L_E049:
    ADD8(RB(0));
    A = (A >> 1) | (A << 7);
    EC_UNSUPPORTED();
    g_2120();
    return;
    L_E02B:
    A |= RB(1);
    if (A == 0) goto L_E071;
    if (C != 0) goto L_E048;
    RB(7)--;
    L_E031:
    g_E149();
    return;
    L_E048:
    g_E028();
    return;
    L_E071:
    if (XD(((unsigned int)SFR_A0 << 8) | 0) != 0xF8) { C = (XD(((unsigned int)SFR_A0 << 8) | 0) < 0xF8); goto L_E031; }
    EC_UNSUPPORTED();
    if (A != 0x84) { C = (A < 0x84); g_E028(); return; }
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
}

void g_E090(void)
{
    A |= RB(0);
    DIR(0x2F) |= 0x49;
    A |= DIR(0x18);
    ADDC8(RB(1));
    if (((SFR_80 >> 0) & 1)) goto L_E09B;
    ADD8(RB(1));
    L_E09B:
    RB(6) = 0x20;
    RB(0)--;
    g_900D();
    return;
}

void g_E098(void)
{
    goto L_E09B;
    L_E09B:
    RB(6) = 0x20;
    RB(0)--;
    g_900D();
    return;
}

void g_E0C9(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x1B;
    if (((SFR_C0 >> 0) & 1)) goto L_E0CF;
    if (BIT_RAM(0x18)) { g_E0D1(); return; }
    L_E0CF:
    RB(0)--;
}

void g_E0D1(void)
{
    RB(5) = 0x80;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    RB(7)++;
    g_E400();
    return;
}

void g_E101(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = 0x05;
    C = C && (!((B >> 0) & 1));
    if (RB(5) != 0x04) { C = (RB(5) < 0x04); goto L_E0A0; }
    RB(7) = A;
    L_E0A0:
    RB(5)++;
    if (BIT_RAM(0x00)) goto L_E0A6;
    if (BIT_RAM(0x18)) goto L_E0A8;
    DPTR = 0x0F20;
    goto L_E0AD;
    L_E0AD:
    RB(0)--;
    ADD8(RB(1));
    EC_UNSUPPORTED();
    RB(0) = STACK[SP--];
    if (BIT_RAM(0x28)) goto L_E12C;
    SUBB8(RB(1));
    RB(7) = RB(1);
    ADD8(RB(0));
    EC_UNSUPPORTED();
    tmp = (A >> 7); A = (A << 1) | C; C = tmp;
    g_E189();
    return;
    L_E12C:
    RB(7)--;
    if (BIT_RAM(0x40)) goto L_E131;
    L_E131:
    RB(0)--;
    RB(1) = 0x01;
    ADD8(RB(0));
    A = 0;
    EC_UNSUPPORTED();
    L_E0A8:
    RB(7)++;
    if (((SFR_80 >> 0) & 1)) goto L_E0AD;
    ADD8(XD(((unsigned int)SFR_A0 << 8) | RB(1)));
    L_E0A6:
    g_E090();
    return;
}

void g_E109(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    A = 0xFE;
    RB(1) = A;
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    A++;
    SUBB8(RB(0));
}

void g_E110(void)
{
    XD(DPTR) = A;
    SFR_F8 = (SFR_F8 & ~(1 << 6)) | (((0) & 1) << 6);
    SFR_E7 = A;
    A++;
    SUBB8(RB(0));
    XD(DPTR) = A;
    if (RB(6) != 0xFE) { C = (RB(6) < 0xFE); goto L_E11F; }
    SUBB8(RB(0));
    L_E11F:
    SFR_80 = RB(4);
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    A = (A >> 1) | (A << 7);
    RB(0) = STACK[SP--];
    SUBB8(RB(0));
    goto L_E12F;
    L_E12F:
    g_E020();
    return;
}

void g_E120(void)
{
    goto L_E129;
    L_E129:
    EC_UNSUPPORTED();
    A = RB(2);
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    RB(7)--;
    if (BIT_RAM(0x40)) goto L_E131;
    L_E131:
    RB(0)--;
    RB(1) = 0x01;
    ADD8(RB(0));
    A = 0;
    EC_UNSUPPORTED();
}

void g_E128(void)
{
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    EC_UNSUPPORTED();
    A = RB(2);
    A = XD(((unsigned int)SFR_A0 << 8) | RB(1));
    RB(7)--;
    if (BIT_RAM(0x40)) goto L_E131;
    L_E131:
    RB(0)--;
    RB(1) = 0x01;
    ADD8(RB(0));
    A = 0;
    EC_UNSUPPORTED();
}

void g_E130(void)
{
    if (BIT_RAM(0x18)) goto L_E133;
    L_E133:
    RB(1) = 0x01;
    ADD8(RB(0));
    A = 0;
    EC_UNSUPPORTED();
}

void g_E138(void)
{
    g_E098();
    return;
}

void g_E146(void)
{
    if (--RB(2)) goto L_E12F;
    tmp = A; A = RB(4); RB(4) = tmp;
    L_E12F:
    g_E020();
    return;
}

void g_E149(void)
{
    RB(7)++;
    C = C || (!BIT_RAM(0x13));
    g_20E4();
    return;
}

void g_E189(void)
{
    if (((SFR_80 >> 0) & 1)) goto L_E18D;
    RB(0)++;
    L_E18D:
    RB(0)--;
    RB(0) = 0x80;
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    SFR_D1++;
    RB(7)++;
    if (BIT_RAM(0x00)) goto L_E19A;
    RB(0)++;
    RB(0)--;
    L_E19A:
    RB(3) = 0x00;
    ADD8(RB(0));
    A = (A >> 1) | (A << 7);
    DIR(0x20) = STACK[SP--];
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(DPTR) = A;
    RB(7) = 0xFE;
    if (((SFR_B8 >> 5) & 1)) { SFR_B8 = (SFR_B8 & ~(1 << 5)) | (((0) & 1) << 5); goto L_E1C9; }
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(DPTR) = A;
    g_E4FE();
    return;
    L_E1C9:
    EC_UNSUPPORTED();
    RB(7)++;
    ADD8((SFR_AD));
    g_E04D();
    return;
}

void g_E218(void)
{
    RB(4)--;
    if (BIT_RAM(0x29)) goto L_E262;
    g_E243();
    return;
    L_E262:
    if (BIT_RAM(0x46)) goto L_E265;
    L_E265:
    XD(DPTR) = A;
    ADDC8(XD(((unsigned int)SFR_A0 << 8) | RB(0)));
    RB(6) = A;
    if (((SFR_B8 >> 5) & 1)) { SFR_B8 = (SFR_B8 & ~(1 << 5)) | (((0) & 1) << 5); goto L_E263; }
    if (A != 0x38) { C = (A < 0x38); goto L_E2BA; }
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8((DIR(0x7B)));
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    if (((SFR_80 >> 0) & 1)) { SFR_80 = (SFR_80 & ~(1 << 0)) | (((0) & 1) << 0); goto L_E23D; }
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(7)++;
    C = C || (((SFR_B0 >> 6) & 1));
    A++;
    if (BIT_RAM(0x20)) goto L_E2F3;
    ADD8(RB(6));
    A |= RB(0);
    ADD8(RB(7));
    A |= RB(1);
    RB(0) = 0x43;
    if (C != 0) goto L_E2A0;
    RB(7)++;
    g_E189();
    return;
    L_E2A0:
    ADDC8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(DPTR) = A;
    RB(5)--;
    RB(6) = A;
    ADD8((DIR(0x73)));
    ADD8(RB(6));
    EC_UNSUPPORTED();
    SFR_B6 ^= A;
    return;
    L_E2F3:
    XD(DPTR) = A;
    SFR_FD = A;
    ADD8((DIR(0x73)));
    L_E2F9:
    ADD8(RB(6));
    EC_UNSUPPORTED();
    SFR_B6 ^= A;
    g_E022();
    return;
    L_E23D:
    DIR(0x42) = RB(0);
    A++;
    if (--RB(1)) goto L_E243;
    L_E243:
    g_E128();
    return;
    L_E2BA:
    RB(0) = A;
    if (A != 0x24) { C = (A < 0x24); goto L_E30A; }
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    ADD8((DIR(0x7B)));
    A = RB(7);
    XD(((unsigned int)SFR_A0 << 8) | RB(1)) = A;
    if (((SFR_80 >> 0) & 1)) { SFR_80 = (SFR_80 & ~(1 << 0)) | (((0) & 1) << 0); goto L_E28D; }
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    XD(((unsigned int)SFR_A0 << 8) | RB(0)) = A;
    RB(7)++;
    C = C || (((SFR_B0 >> 6) & 1));
    A++;
    if (BIT_RAM(0x20)) goto L_E343;
    RB(2)--;
    A |= RB(0);
    RB(3)--;
    A |= RB(1);
    RB(0) = 0x43;
    if (C != 0) goto L_E2F0;
    RB(7)++;
    g_E189();
    return;
    L_E2F0:
    ADDC8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    L_E343:
    if (BIT_RAM(0x5C)) goto L_E34A;
    A = 0;
    ADDC8(0x02);
    if (BIT_RAM(0x39)) goto L_E3B1;
    g_20D8();
    return;
    L_E3B1:
    EC_UNSUPPORTED();
    ADD8(RB(0));
    g_E148();
    return;
    L_E34A:
    g_2039();
    return;
    L_E28D:
    RB(0)--;
    RB(1)++;
    RB(2) = 0x00;
    ADD8(RB(1));
    RB(0)++;
    DIR(0x0F) = STACK[SP--];
    g_E109();
    return;
    L_E30A:
    if (A != 0) goto L_E2C1;
    RB(4)++;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    DIR(0x46)++;
    XD(DPTR) = A;
    A = RB(4);
    RB(5) = A;
    ADD8(RB(4));
    if (((PSW >> 0) & 1)) { PSW = (PSW & ~(1 << 0)) | (((0) & 1) << 0); goto L_E321; }
    A |= RB(1);
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    A |= RB(0);
    DIR(0x08) |= 0x49;
    if (C != 0) goto L_E33A;
    RB(7)++;
    g_E109();
    return;
    L_E33A:
    if (A != 0) goto L_E2F9;
    tmp = A; A = RB(4); RB(4) = tmp;
    RB(7)++;
    C = C || (!BIT_RAM(0x13));
    g_205C();
    return;
    L_E321:
    RB(0)--;
    L_E2C1:
    RB(3) = 0xEF;
    L_E263:
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
}

void g_E400(void)
{
    A |= 0x48;
    if (B == 0) { C = 0; } else { tmp = A % B; A = A / B; B = tmp; C = 0; }
    RB(1) |= A;
    EC_UNSUPPORTED();
    RB(1)--;
    if (BIT_RAM(0x00)) goto L_E3EA;
    RB(5)--;
    if (BIT_RAM(0x01)) goto L_E42F;
    g_E440();
    return;
    L_E42F:
    ADD8(0x3A);
    A |= RB(0);
    g_E146();
    return;
    L_E3EA:
    g_20F8();
    return;
}

void g_E440(void)
{
    SFR_C0 = RB(0);
    RB(3)++;
    XD(((unsigned int)SFR_A0 << 8) | RB(0))--;
    DIR(0x3D) = STACK[SP--];
    if (((SFR_80 >> 0) & 1)) goto L_E44B;
    ADD8(RB(0));
    L_E44B:
    RB(0)--;
    RB(7) = 0x40;
    L_E44F:
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    if (C != 0) goto L_E460;
    if (RB(0) != 0x42) { C = (RB(0) < 0x42); goto L_E463; }
    EC_UNSUPPORTED();
    if (BIT_RAM(0x21)) goto L_E479;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(DPTR) = A;
    EC_UNSUPPORTED();
    RB(4) = A;
    RB(5)++;
    if (BIT_RAM(0x00)) goto L_E464;
    A = (A >> 1) | (A << 7);
    L_E463:
    g_E128();
    return;
    L_E464:
    ADD8(RB(0));
    RB(0)--;
    g_E475();
    return;
    L_E479:
    ADD8(RB(4));
    if (--RB(1)) goto L_E44F;
    ADD8(RB(1));
    A |= RB(1);
    g_E020();
    return;
    L_E460:
    g_0321();
    return;
}

void g_E475(void)
{
    RB(4)--;
    A = 0;
    BIT_SET(0x02, !BIT_RAM(0x02));
    L_E479:
    ADD8(RB(4));
    if (--RB(1)) goto L_E44F;
    ADD8(RB(1));
    A |= RB(1);
    g_E020();
    return;
    L_E44F:
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    if (C != 0) goto L_E460;
    if (RB(0) != 0x42) { C = (RB(0) < 0x42); goto L_E463; }
    EC_UNSUPPORTED();
    if (BIT_RAM(0x21)) goto L_E479;
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    XD(DPTR) = A;
    EC_UNSUPPORTED();
    RB(4) = A;
    RB(5)++;
    if (BIT_RAM(0x00)) goto L_E464;
    A = (A >> 1) | (A << 7);
    L_E463:
    g_E128();
    return;
    L_E464:
    ADD8(RB(0));
    RB(0)--;
    g_E475();
    return;
    L_E460:
    g_0321();
    return;
}

void g_E4FE(void)
{
    ADD8(RB(0));
    A |= XD(((unsigned int)SFR_A0 << 8) | RB(0));
    g_9A00();
    return;
}

void g_E800(void)
{
    g_D17D();
    return;
}

void g_E802(void)
{
    RB(5) = 0x23;
    if (--RB(3)) goto L_E806;
    L_E806:
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(2)--;
    XD(DPTR) = A;
    A = RB(6);
    RB(3) = A;
    if (((SFR_B8 >> 5) & 1)) { SFR_B8 = (SFR_B8 & ~(1 << 5)) | (((0) & 1) << 5); goto L_E80F; }
    L_E80F:
    tmp = A; A = RB(4); RB(4) = tmp;
    RB(7)++;
    C = C || (!BIT_RAM(0x13));
    g_20D0();
    return;
}

void g_E820(void)
{
    A &= RB(4);
    ADDC8(0x02);
    if (BIT_RAM(0x48)) goto L_E85A;
    g_2068();
    return;
    L_E85A:
    RB(1)++;
    if (C != 0) goto L_E85D;
    L_E85D:
    goto L_E860;
    L_E860:
    ADDC8(RB(0));
    if (A != 0x04) { C = (A < 0x04); goto L_E8AA; }
    if (BIT_RAM(0x49)) { BIT_SET(0x49, 0); goto L_E867; }
    L_E867:
    g_4518();
    return;
    L_E8AA:
    RB(1)++;
    if (C != 0) goto L_E8AD;
    L_E8AD:
    RB(1)++;
    if (C != 0) goto L_E895;
    ADDC8(0x02);
    if (BIT_RAM(0x00)) goto L_E898;
    A = XD(DPTR);
    if (A != 0) goto L_E86F;
    RB(3)++;
    A |= RB(2);
    g_E802();
    return;
    L_E86F:
    A = (A >> 1) | (A << 7);
    RB(1)++;
    A = da_a(A);
    RB(6)++;
    A |= RB(1);
    if (C != 0) goto L_E88E;
    if (C != 0) goto L_E8E1;
    RB(4)++;
    g_E908();
    return;
    L_E8E1:
    g_E9E1();
    return;
    L_E88E:
    DPTR = 0x8003;
    g_D400();
    return;
    L_E898:
    SFR_D5++;
    g_EF06();
    return;
    L_E895:
    SUBB8(RB(0));
    if (C != 0) goto L_E89B;
    L_E89B:
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(6)++;
    g_E820();
    return;
}

void g_E848(void)
{
    XD(DPTR) = A;
    A = da_a(A);
    RB(3) = A;
    if (((SFR_B8 >> 5) & 1)) { SFR_B8 = (SFR_B8 & ~(1 << 5)) | (((0) & 1) << 5); goto L_E85B; }
    g_FAD5();
    return;
    L_E85B:
    if (C != 0) goto L_E85D;
    L_E85D:
    goto L_E860;
    L_E860:
    ADDC8(RB(0));
    if (A != 0x04) { C = (A < 0x04); goto L_E8AA; }
    if (BIT_RAM(0x49)) { BIT_SET(0x49, 0); goto L_E867; }
    L_E867:
    g_4518();
    return;
    L_E8AA:
    RB(1)++;
    if (C != 0) goto L_E8AD;
    L_E8AD:
    RB(1)++;
    if (C != 0) goto L_E895;
    ADDC8(0x02);
    if (BIT_RAM(0x00)) goto L_E898;
    A = XD(DPTR);
    if (A != 0) goto L_E86F;
    RB(3)++;
    A |= RB(2);
    g_E802();
    return;
    L_E86F:
    A = (A >> 1) | (A << 7);
    RB(1)++;
    A = da_a(A);
    RB(6)++;
    A |= RB(1);
    if (C != 0) goto L_E88E;
    if (C != 0) goto L_E8E1;
    RB(4)++;
    g_E908();
    return;
    L_E8E1:
    g_E9E1();
    return;
    L_E88E:
    DPTR = 0x8003;
    g_D400();
    return;
    L_E898:
    SFR_D5++;
    g_EF06();
    return;
    L_E895:
    SUBB8(RB(0));
    if (C != 0) goto L_E89B;
    L_E89B:
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(6)++;
    g_E820();
    return;
}

void g_E890(void)
{
    goto L_E895;
    L_E895:
    SUBB8(RB(0));
    if (C != 0) goto L_E89B;
    SFR_D5++;
    g_EF06();
    return;
    L_E89B:
    XD(((unsigned int)SFR_A0 << 8) | RB(0))++;
    tmp = A; A = RB(1); RB(1) = tmp;
    RB(6)++;
    g_E820();
    return;
}

void g_E8BD(void)
{
    g_8D18();
    return;
}

void g_E908(void)
{
    ADD8(RB(1));
    A = (A >> 1) | (A << 7);
    EC_UNSUPPORTED();
    ec_jump_bank1((unsigned int)DPTR + A);
    return;
}

void g_E944(void)
{
    A |= RB(1);
    A = (A >> 1) | (A << 7);
    if (--DIR(0x41)) goto L_E9B3;
    ADD8(RB(2));
    XD(((unsigned int)SFR_A0 << 8) | RB(1))++;
    EC_UNSUPPORTED();
    DIR(0x41) |= 0x61;
    g_EA69();
    return;
    L_E9B3:
    if (RB(5) != 0x55) { C = (RB(5) < 0x55); goto L_E99A; }
    g_E800();
    return;
    L_E99A:
    g_E8BD();
    return;
}

void g_E9E1(void)
{
    DPTR = 0x01BD;
    g_EDE3();
    return;
}

void g_EA69(void)
{
    ADD8(RB(0));
    A = (A >> 1) | (A << 7);
    if (A != 0x01) { C = (A < 0x01); goto L_EAB8; }
    g_E890();
    return;
    L_EAB8:
    g_E890();
    return;
}

void g_EDE3(void)
{
    A = (A >> 1) | (A << 7);
    if (A != 0x01) { C = (A < 0x01); goto L_EE30; }
    g_E890();
    return;
    L_EE30:
    g_E890();
    return;
}

void g_EF06(void)
{
    g_E848();
    return;
}

void g_F000(void)
{
    A = (A >> 1) | (A << 7);
    if (A != 0x01) { C = (A < 0x01); goto L_F04C; }
    g_F090();
    return;
    L_F04C:
    SFR_A8 |= 0x71;
    g_20FF();
    return;
}

void g_F028(void)
{
    g_F090();
    return;
}

void g_F034(void)
{
    g_F090();
    return;
}

void g_F06B(void)
{
    g_F087();
    return;
}

void g_F076(void)
{
    A ^= RB(5);
    g_F000();
    return;
}

void g_F087(void)
{
    if (BIT_RAM(0x09)) goto L_F08C;
    DIR(0x34) = STACK[SP--];
    L_F08C:
    g_2013();
    return;
}


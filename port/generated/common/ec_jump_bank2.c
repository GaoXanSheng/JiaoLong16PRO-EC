#include "ec_globals.h"

void ec_jump_bank2(unsigned int addr)
{
    switch (addr) {
    case 0x8001: h_8001(); break;
    case 0x80E8: h_80E8(); break;
    case 0x80EA: h_80EA(); break;
    case 0x80F0: h_80F0(); break;
    case 0xE402: h_E402(); break;
    case 0xE801: h_E801(); break;
    case 0xEC02: h_EC02(); break;
    default: break;
    }
}

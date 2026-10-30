#include "ec_crc.h"

__idata __at (0xAF) unsigned char crc_state;

unsigned char crc_update(unsigned char v)
{
    unsigned char s = crc_state ^ v;

    crc_state = s;
    v = s;
    if (v & 0x80) {
        v = v << 1;
        crc_state ^= 0x09;
        crc_state ^= v;
    } else {
        v = v << 1;
        crc_state ^= v;
    }
    if (v & 0x80) {
        v = v << 1;
        crc_state ^= 0x07;
        crc_state ^= v;
    } else {
        crc_state ^= (unsigned char)(v << 1);
    }
    return v;
}

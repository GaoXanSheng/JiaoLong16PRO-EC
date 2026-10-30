#include "ec_globals.h"

unsigned char A, B, C, PSW, SP;
unsigned int DPTR;
__xdata unsigned char RBANKS[4][8];
unsigned char tmp;
unsigned int tmp16;
__xdata unsigned char STACK[256];
__xdata unsigned char IRAM[256];

unsigned char da_a(unsigned char v)
{
    unsigned char lo = v & 0x0F;
    unsigned char hi = v >> 4;
    if (lo > 9) { lo += 6; hi++; }
    if (hi > 9) hi += 6;
    return (hi << 4) | (lo & 0x0F);
}

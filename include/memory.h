#ifndef MEMORY_H
#define MEMORY_H
#define XDATA8(a) (*(volatile unsigned char __xdata *)(a))
#define XDATA16(a) (*(volatile unsigned int __xdata *)(a))
#define CODE8(a) (*(const unsigned char __code *)(a))
#endif

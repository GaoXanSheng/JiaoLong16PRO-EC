.module CRC_HOOK_TEST
.area CSEG (CODE)
.globl _crc_hook_test
_crc_hook_test:
    mov r0,#0xAF
    mov @r0,#0x5A
    mov r7,#0x00
    lcall 0x203A
    mov a,r7
    mov dptr,#0xFC00
    movx @dptr,a
    inc dptr
    mov r0,#0xAF
    mov a,@r0
    movx @dptr,a

    mov r0,#0xAF
    mov @r0,#0x5A
    mov r7,#0x01
    lcall 0x203A
    mov a,r7
    mov dptr,#0xFC02
    movx @dptr,a
    inc dptr
    mov r0,#0xAF
    mov a,@r0
    movx @dptr,a

    mov r0,#0xAF
    mov @r0,#0x5A
    mov r7,#0x80
    lcall 0x203A
    mov a,r7
    mov dptr,#0xFC04
    movx @dptr,a
    inc dptr
    mov r0,#0xAF
    mov a,@r0
    movx @dptr,a

    mov r0,#0xAF
    mov @r0,#0x5A
    mov r7,#0xFF
    lcall 0x203A
    mov a,r7
    mov dptr,#0xFC06
    movx @dptr,a
    inc dptr
    mov r0,#0xAF
    mov a,@r0
    movx @dptr,a

    mov dptr,#0xFBFF
    mov a,#0x5A
    movx @dptr,a
crc_done:
    sjmp crc_done

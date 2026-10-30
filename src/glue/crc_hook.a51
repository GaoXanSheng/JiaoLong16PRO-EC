.module CRC_HOOK
.area CSEG (CODE)
.globl _crc_entry
_crc_entry:
    mov a,psw
    anl a,#0x18
    jz crc_bank0
    push 0x00
    push 0x01
    push 0x02
    push 0x03
    push 0x04
    push 0x05
    push 0x06
    push 0x07
    mov a,r7
    mov dpl,a
    lcall _crc_update
    mov a,dpl
    mov r7,a
    pop 0x07
    pop 0x06
    pop 0x05
    pop 0x04
    pop 0x03
    pop 0x02
    pop 0x01
    pop 0x00
    ret
crc_bank0:
    mov a,r7
    mov dpl,a
    lcall _crc_update
    mov a,dpl
    mov r7,a
    ret

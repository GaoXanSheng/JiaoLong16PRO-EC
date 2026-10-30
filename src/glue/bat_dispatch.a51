.module BAT_GLUE
.area CSEG (CODE)
.globl _bat_task_entry
_bat_task_entry:
    push 0x00
    push 0x01
    push 0x02
    push 0x03
    push 0x04
    push 0x05
    push 0x06
    push 0x07
    lcall _bat_status_task
    pop 0x07
    pop 0x06
    pop 0x05
    pop 0x04
    pop 0x03
    pop 0x02
    pop 0x01
    pop 0x00
    ret

.globl _bat_dispatch
_bat_dispatch:
    mov r5,#0x8C
    mov r3,#0x12
    clr a
    mov r7,a
    lcall 0x1A4C
    mov a,r7
    mov dpl,a
    ret

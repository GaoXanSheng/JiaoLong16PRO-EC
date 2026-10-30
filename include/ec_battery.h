#ifndef EC_BATTERY_H
#define EC_BATTERY_H

#define BAT_REG_ERRCOUNT    0x0693
#define BAT_REG_MAILBOX     0x069D

#define BAT_REG_STATE       0x8998
#define BAT_REG_MODEL_SRC   0x898A
#define BAT_REG_CMD         0x89A4
#define BAT_REG_ARG         0x89A5
#define BAT_REG_MODEL       0x89A6
#define BAT_REG_SYNC        0x89A7

#define BAT_REG_CHG_READ_HI 0x89CB
#define BAT_REG_CHG_READ_LO 0x89CC
#define BAT_REG_CHG_SET_HI  0x89D2
#define BAT_REG_CHG_SET_LO  0x89D3
#define BAT_REG_LAST        0x89D6

#define BAT_REG_CFG_A       0x83C0
#define BAT_REG_CFG_B       0x83C3
#define BAT_REG_CFG_C       0x83F0
#define BAT_REG_TIMER       0x847C

#define BAT_REG_STAGE       0x1603
#define BAT_REG_STAGE_A     0x837A
#define BAT_REG_STAGE_B     0x837B

#define BAT_REG_PARAM_A     0x89CD
#define BAT_REG_PARAM_B     0x89CE
#define BAT_REG_PARAM_C     0x89D0
#define BAT_REG_PARAM_D     0x89D1

#define BAT_CMD_REFRESH     0x8B
#define BAT_ARG_REFRESH_STD 0x28
#define BAT_ARG_REFRESH_ALT 0x2C

#define BAT_PUB_MODEL       0x3B
#define BAT_PUB_CHG_CURRENT 0x3C
#define BAT_PUB_COMMAND     0x3D
#define BAT_PUB_STAGE       0x3F
#define BAT_PUB_PARAM_A     0x16
#define BAT_PUB_PARAM_C     0x17

#define BAT_MBOX_CLASS      0x8C
#define BAT_MBOX_OP         0x12

#define BAT_MODEL_PRIMARY   0x14
#define BAT_MODEL_ALTERNATE 0x16
#define BAT_SYNC_VALUE      0x08

#define BAT_CHG_CURRENT_HI  0xD4
#define BAT_CHG_CURRENT_LO  0x05

#define BAT_PARAM_DEFAULT   0x0F
#define BAT_STAGE_A_HIGH    0x80
#define BAT_STAGE_B_HIGH    0x0D
#define BAT_STAGE_A_LOW     0x00
#define BAT_STAGE_B_LOW     0x0B
#define BAT_STAGE_FLAG      0x08

#define BAT_STATE_READY     0x01
#define BAT_CFG_A_HOLD      0x20
#define BAT_CFG_B_HOLD      0x10
#define BAT_CFG_C_MODEL_SEL 0x01
#define BAT_TIMER_THRESHOLD 0x1E

void bat_init_sequence(void);
void bat_status_task(void);
void bat_model_select(void);

#endif

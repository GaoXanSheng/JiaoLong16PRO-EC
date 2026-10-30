#include "ec_battery.h"

#define XD(a) (*(volatile unsigned char __xdata *)(a))

#define SNAP_BASE 0xF400
#define LOG_CMD   0xF600
#define LOG_ARG   0xF700
#define LOG_PUB   0xF800
#define LOG_HI    0xF900
#define LOG_LO    0xFA00

unsigned char send_count;
unsigned char cmd_status;
unsigned char log_slot;

unsigned char bat_dispatch(void)
{
    unsigned char i = send_count;
    unsigned int b = ((unsigned int)log_slot << 3) + i;
    XD(LOG_CMD + b) = XD(BAT_REG_CMD);
    XD(LOG_ARG + b) = XD(BAT_REG_ARG);
    XD(LOG_PUB + b) = XD(BAT_REG_MAILBOX);
    XD(LOG_HI + b) = XD(BAT_REG_MAILBOX + 1);
    XD(LOG_LO + b) = XD(BAT_REG_MAILBOX + 2);
    send_count = i + 1;
    return cmd_status;
}

static void snapshot(unsigned char slot)
{
    unsigned int b = SNAP_BASE + ((unsigned int)slot << 5);

    XD(b + 0) = XD(BAT_REG_ERRCOUNT);
    XD(b + 1) = XD(BAT_REG_STATE);
    XD(b + 2) = XD(BAT_REG_MODEL);
    XD(b + 3) = XD(BAT_REG_SYNC);
    XD(b + 4) = XD(BAT_REG_CMD);
    XD(b + 5) = XD(BAT_REG_ARG);
    XD(b + 6) = XD(BAT_REG_CHG_READ_HI);
    XD(b + 7) = XD(BAT_REG_CHG_READ_LO);
    XD(b + 8) = XD(BAT_REG_CHG_SET_HI);
    XD(b + 9) = XD(BAT_REG_CHG_SET_LO);
    XD(b + 10) = XD(BAT_REG_LAST);
    XD(b + 11) = XD(BAT_REG_TIMER);
    XD(b + 12) = XD(BAT_REG_STAGE_A);
    XD(b + 13) = XD(BAT_REG_STAGE_B);
    XD(b + 14) = XD(BAT_REG_PARAM_A);
    XD(b + 15) = XD(BAT_REG_PARAM_B);
    XD(b + 16) = XD(BAT_REG_PARAM_C);
    XD(b + 17) = XD(BAT_REG_PARAM_D);
    XD(b + 18) = XD(BAT_REG_MAILBOX);
    XD(b + 19) = XD(BAT_REG_MAILBOX + 1);
    XD(b + 20) = XD(BAT_REG_MAILBOX + 2);
    XD(b + 21) = XD(BAT_REG_MAILBOX + 3);
    XD(b + 22) = send_count;
}

static void reset_registers(void)
{
    XD(BAT_REG_ERRCOUNT) = 0;
    XD(BAT_REG_MAILBOX) = 0;
    XD(BAT_REG_MAILBOX + 1) = 0;
    XD(BAT_REG_MAILBOX + 2) = 0;
    XD(BAT_REG_MAILBOX + 3) = 0;
    XD(BAT_REG_STATE) = 0;
    XD(BAT_REG_MODEL_SRC) = 0;
    XD(BAT_REG_CMD) = 0;
    XD(BAT_REG_ARG) = 0;
    XD(BAT_REG_MODEL) = 0;
    XD(BAT_REG_SYNC) = 0;
    XD(BAT_REG_CHG_READ_HI) = 0;
    XD(BAT_REG_CHG_READ_LO) = 0;
    XD(BAT_REG_CHG_SET_HI) = 0;
    XD(BAT_REG_CHG_SET_LO) = 0;
    XD(BAT_REG_LAST) = 0;
    XD(BAT_REG_CFG_A) = 0;
    XD(BAT_REG_CFG_B) = 0;
    XD(BAT_REG_CFG_C) = 0;
    XD(BAT_REG_TIMER) = 0;
    XD(BAT_REG_STAGE) = 0;
    XD(BAT_REG_STAGE_A) = 0;
    XD(BAT_REG_STAGE_B) = 0;
    XD(BAT_REG_PARAM_A) = 0;
    XD(BAT_REG_PARAM_B) = 0;
    XD(BAT_REG_PARAM_C) = 0;
    XD(BAT_REG_PARAM_D) = 0;
    send_count = 0;
    cmd_status = 1;
}

static void scenario_model_primary(void)
{
    reset_registers();
    log_slot = 0;
    XD(BAT_REG_CFG_C) = 1;
    XD(BAT_REG_MODEL_SRC) = 0;
    XD(BAT_REG_MODEL) = 0xAA;
    XD(BAT_REG_SYNC) = 0xAA;
    XD(BAT_REG_MAILBOX) = 0xEE;
    bat_model_select();
    snapshot(0);
}

static void scenario_model_alternate(void)
{
    reset_registers();
    log_slot = 1;
    XD(BAT_REG_CFG_C) = 0;
    XD(BAT_REG_MODEL_SRC) = 0;
    XD(BAT_REG_MODEL) = 0xAA;
    XD(BAT_REG_SYNC) = 0xAA;
    bat_model_select();
    snapshot(1);
}

static void scenario_model_keep(void)
{
    reset_registers();
    log_slot = 2;
    XD(BAT_REG_CFG_C) = 1;
    XD(BAT_REG_MODEL_SRC) = BAT_MODEL_PRIMARY;
    XD(BAT_REG_MODEL) = 0xAA;
    XD(BAT_REG_SYNC) = 0;
    bat_model_select();
    snapshot(2);
}

static void scenario_gate_a(void)
{
    reset_registers();
    log_slot = 3;
    XD(BAT_REG_CFG_A) = BAT_CFG_A_HOLD;
    XD(BAT_REG_STATE) = 0x40;
    bat_status_task();
    snapshot(3);
}

static void scenario_gate_b(void)
{
    reset_registers();
    log_slot = 4;
    XD(BAT_REG_CFG_B) = BAT_CFG_B_HOLD;
    XD(BAT_REG_STATE) = 0x40;
    bat_status_task();
    snapshot(4);
}

static void prepare_init(unsigned char slot, unsigned char stage, unsigned char status, unsigned char state)
{
    reset_registers();
    log_slot = slot;
    cmd_status = status;
    XD(BAT_REG_STATE) = state;
    XD(BAT_REG_ERRCOUNT) = 0xEE;
    XD(BAT_REG_STAGE) = stage;
    XD(BAT_REG_PARAM_A) = 0xAA;
    XD(BAT_REG_PARAM_B) = 0xAA;
    XD(BAT_REG_PARAM_C) = 0xAA;
    XD(BAT_REG_PARAM_D) = 0xAA;
    XD(BAT_REG_CHG_READ_HI) = BAT_CHG_CURRENT_HI;
    XD(BAT_REG_CHG_READ_LO) = BAT_CHG_CURRENT_LO;
    XD(BAT_REG_CMD) = 0xAA;
    XD(BAT_REG_ARG) = 0xAA;
    XD(BAT_REG_MODEL) = 0;
    XD(BAT_REG_SYNC) = 0;
    XD(BAT_REG_MAILBOX) = 0xEE;
    bat_init_sequence();
}

static void scenario_init_low_success(void)
{
    prepare_init(5, BAT_STAGE_FLAG, 1, 0x40);
    snapshot(5);
}

static void scenario_init_low_failure(void)
{
    prepare_init(6, BAT_STAGE_FLAG, 0, 0x40);
    snapshot(6);
}

static void scenario_init_high_success(void)
{
    prepare_init(7, 0, 1, 0);
    snapshot(7);
}

static void scenario_status_standard(void)
{
    reset_registers();
    log_slot = 8;
    XD(BAT_REG_STATE) = BAT_STATE_READY;
    XD(BAT_REG_TIMER) = 0x10;
    XD(BAT_REG_CMD) = BAT_CMD_REFRESH;
    XD(BAT_REG_ARG) = BAT_ARG_REFRESH_ALT;
    XD(BAT_REG_CHG_READ_HI) = BAT_CHG_CURRENT_HI;
    XD(BAT_REG_CHG_READ_LO) = BAT_CHG_CURRENT_LO;
    XD(BAT_REG_CFG_C) = BAT_CFG_C_MODEL_SEL;
    XD(BAT_REG_MODEL_SRC) = BAT_MODEL_PRIMARY;
    XD(BAT_REG_MODEL) = 0xAA;
    bat_status_task();
    snapshot(8);
}

static void scenario_status_alternate(void)
{
    reset_registers();
    log_slot = 9;
    XD(BAT_REG_STATE) = BAT_STATE_READY;
    XD(BAT_REG_TIMER) = 0x20;
    XD(BAT_REG_CMD) = BAT_CMD_REFRESH;
    XD(BAT_REG_ARG) = BAT_ARG_REFRESH_STD;
    XD(BAT_REG_CHG_READ_HI) = BAT_CHG_CURRENT_HI;
    XD(BAT_REG_CHG_READ_LO) = BAT_CHG_CURRENT_LO;
    XD(BAT_REG_CFG_C) = 0;
    XD(BAT_REG_MODEL_SRC) = BAT_MODEL_ALTERNATE;
    XD(BAT_REG_MODEL) = 0xAA;
    XD(BAT_REG_MAILBOX) = 0xEE;
    XD(BAT_REG_MAILBOX + 1) = 0xEE;
    XD(BAT_REG_MAILBOX + 2) = 0xEE;
    bat_status_task();
    snapshot(9);
}

static void scenario_status_charge(void)
{
    reset_registers();
    log_slot = 10;
    XD(BAT_REG_STATE) = BAT_STATE_READY;
    XD(BAT_REG_TIMER) = 0x10;
    XD(BAT_REG_CMD) = BAT_CMD_REFRESH;
    XD(BAT_REG_ARG) = BAT_ARG_REFRESH_STD;
    XD(BAT_REG_CFG_C) = BAT_CFG_C_MODEL_SEL;
    XD(BAT_REG_MODEL_SRC) = BAT_MODEL_PRIMARY;
    XD(BAT_REG_MODEL) = BAT_MODEL_PRIMARY;
    bat_status_task();
    snapshot(10);
}

void main(void)
{
    scenario_model_primary();
    scenario_model_alternate();
    scenario_model_keep();
    scenario_gate_a();
    scenario_gate_b();
    scenario_init_low_success();
    scenario_init_low_failure();
    scenario_init_high_success();
    scenario_status_standard();
    scenario_status_alternate();
    scenario_status_charge();
    XD(0xF000) = 0x5A;
    for (;;) {
    }
}

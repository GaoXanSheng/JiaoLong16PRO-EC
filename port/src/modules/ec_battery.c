#include "ec_battery.h"

#define XD(a) (*(volatile unsigned char __xdata *)(a))

extern unsigned char bat_dispatch(void);

static unsigned char bat_send(void)
{
    return bat_dispatch();
}

static void bat_count_failure(unsigned char status)
{
    if (status == 0) {
        XD(BAT_REG_ERRCOUNT) = XD(BAT_REG_ERRCOUNT) + 1;
    }
}

#define BAT_NOTIFY(id, addr) do { \
    XD(BAT_REG_MAILBOX) = (id); \
    XD(BAT_REG_MAILBOX + 1) = (unsigned char)((addr) >> 8); \
    XD(BAT_REG_MAILBOX + 2) = (unsigned char)(addr); \
    XD(BAT_REG_MAILBOX + 3) = 0; \
} while (0)

static unsigned char bat_publish_model(void)
{
    BAT_NOTIFY(BAT_PUB_MODEL, BAT_REG_MODEL);
    return bat_send();
}

static unsigned char bat_publish_charge(void)
{
    BAT_NOTIFY(BAT_PUB_CHG_CURRENT, BAT_REG_CHG_SET_HI);
    return bat_send();
}

static unsigned char bat_publish_command(void)
{
    BAT_NOTIFY(BAT_PUB_COMMAND, BAT_REG_CMD);
    return bat_send();
}

static unsigned char bat_publish_stage(void)
{
    BAT_NOTIFY(BAT_PUB_STAGE, BAT_REG_STAGE_A);
    return bat_send();
}

static unsigned char bat_publish_param_a(void)
{
    BAT_NOTIFY(BAT_PUB_PARAM_A, BAT_REG_PARAM_A);
    return bat_send();
}

static unsigned char bat_publish_param_c(void)
{
    BAT_NOTIFY(BAT_PUB_PARAM_C, BAT_REG_PARAM_C);
    return bat_send();
}

static void bat_write_model(unsigned char model)
{
    XD(BAT_REG_MODEL) = model;
    XD(BAT_REG_SYNC) = BAT_SYNC_VALUE;
}

static void bat_write_stage(void)
{
    if (XD(BAT_REG_STAGE) & BAT_STAGE_FLAG) {
        XD(BAT_REG_STAGE_A) = BAT_STAGE_A_LOW;
        XD(BAT_REG_STAGE_B) = BAT_STAGE_B_LOW;
    } else {
        XD(BAT_REG_STAGE_A) = BAT_STAGE_A_HIGH;
        XD(BAT_REG_STAGE_B) = BAT_STAGE_B_HIGH;
    }
}

static unsigned char bat_refresh_standard(void)
{
    XD(BAT_REG_CMD) = BAT_CMD_REFRESH;
    XD(BAT_REG_ARG) = BAT_ARG_REFRESH_STD;
    return bat_publish_command();
}

static unsigned char bat_refresh_alternate(void)
{
    XD(BAT_REG_CMD) = BAT_CMD_REFRESH;
    XD(BAT_REG_ARG) = BAT_ARG_REFRESH_ALT;
    XD(BAT_REG_MODEL) = 0;
    return bat_send();
}

void bat_model_select(void)
{
    unsigned char src = XD(BAT_REG_MODEL_SRC);

    if (XD(BAT_REG_CFG_C) & BAT_CFG_C_MODEL_SEL) {
        if (src != BAT_MODEL_PRIMARY) {
            XD(BAT_REG_MODEL) = BAT_MODEL_PRIMARY;
        }
    } else {
        if (src != BAT_MODEL_ALTERNATE) {
            XD(BAT_REG_MODEL) = BAT_MODEL_ALTERNATE;
        }
    }
    XD(BAT_REG_SYNC) = BAT_SYNC_VALUE;
    bat_publish_model();
}

void bat_init_sequence(void)
{
    XD(BAT_REG_ERRCOUNT) = 0;

    bat_count_failure(bat_refresh_standard());

    bat_write_model(BAT_MODEL_PRIMARY);
    bat_count_failure(bat_publish_model());

    XD(BAT_REG_CHG_SET_HI) = BAT_CHG_CURRENT_HI;
    XD(BAT_REG_CHG_SET_LO) = BAT_CHG_CURRENT_LO;
    bat_count_failure(bat_publish_charge());

    bat_write_stage();
    bat_count_failure(bat_publish_stage());

    XD(BAT_REG_PARAM_A) = 0;
    XD(BAT_REG_PARAM_B) = BAT_PARAM_DEFAULT;
    bat_count_failure(bat_publish_param_a());

    XD(BAT_REG_PARAM_C) = 0;
    XD(BAT_REG_PARAM_D) = BAT_PARAM_DEFAULT;
    bat_count_failure(bat_publish_param_c());

    XD(BAT_REG_LAST) = XD(BAT_REG_ERRCOUNT);
    if (XD(BAT_REG_ERRCOUNT) == 0) {
        XD(BAT_REG_STATE) = XD(BAT_REG_STATE) | BAT_STATE_READY;
    }
}

void bat_status_task(void)
{
    if (XD(BAT_REG_CFG_A) & BAT_CFG_A_HOLD) {
        return;
    }
    if (XD(BAT_REG_CFG_B) & BAT_CFG_B_HOLD) {
        return;
    }
    if ((XD(BAT_REG_STATE) & BAT_STATE_READY) == 0) {
        bat_init_sequence();
    }

    if (XD(BAT_REG_TIMER) < BAT_TIMER_THRESHOLD) {
        if (!(XD(BAT_REG_CMD) == BAT_CMD_REFRESH && XD(BAT_REG_ARG) == BAT_ARG_REFRESH_STD)) {
            bat_refresh_standard();
        }
    } else {
        if (!(XD(BAT_REG_CMD) == BAT_CMD_REFRESH && XD(BAT_REG_ARG) == BAT_ARG_REFRESH_ALT)) {
            bat_refresh_alternate();
        }
    }

    if (!(XD(BAT_REG_CHG_READ_HI) == BAT_CHG_CURRENT_HI && XD(BAT_REG_CHG_READ_LO) == BAT_CHG_CURRENT_LO)) {
        XD(BAT_REG_CHG_SET_HI) = BAT_CHG_CURRENT_HI;
        XD(BAT_REG_CHG_SET_LO) = BAT_CHG_CURRENT_LO;
        bat_publish_charge();
    }

    if (XD(BAT_REG_CFG_A) != 0) {
        return;
    }
    if ((XD(BAT_REG_STATE) & BAT_STATE_READY) == 0) {
        return;
    }
    bat_model_select();
}

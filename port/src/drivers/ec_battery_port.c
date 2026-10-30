#include "ec_battery.h"
#include "ec_command.h"

unsigned char ec_cmd_execute(unsigned char arg, unsigned char cmd)
{
    return ec_command_run(cmd, arg, 0);
}

#include "ec_globals.h"
#include "ec_command.h"

unsigned char ec_command_run(unsigned char cmd, unsigned char arg, unsigned char status)
{
    RB(5) = cmd;
    RB(3) = arg;
    RB(7) = status;
    f_1A4C();
    return RB(7);
}

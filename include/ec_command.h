#ifndef EC_COMMAND_H
#define EC_COMMAND_H

#define EC_MAILBOX_STATUS 0x069A
#define EC_MAILBOX_HI     0x069B
#define EC_MAILBOX_LO     0x069C
#define EC_MAILBOX_DATA   0x069D
#define EC_MAILBOX_AUX    0x06A0

unsigned char ec_command_run(unsigned char cmd, unsigned char arg, unsigned char status);

#endif

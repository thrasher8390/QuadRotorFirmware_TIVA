/*
*  File - Protocol
*  Author - Derek Thrasher
*  Date Created - 2/21/215
*/




#ifndef PROTOCOL_H
#define PROTOCOL_H

//Includes
#include "HC05.h"

//Commands!
#define COMMAND_UP      (0x05)
#define COMMAND_DOWN    (0x06)
#define COMMAND_LEFT    (0x07)
#define COMMAND_RIGHT   (0x08)
#define COMMAND_OFF     (0x09)
#define COMMAND_ON      (0x0A)
#define COMMAND_DELAY   (0x0B)

//Global Functions
extern void Protocol__ReceivedCommand(BLUETOOTH_CMD nextCommand);
#endif

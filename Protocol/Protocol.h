/*
*  File - Protocol
*  Author - Derek Thrasher
*  Date Created - 2/21/215
*/




#ifndef PROTOCOL_H
#define PROTOCOL_H

//Includes
#include "HC05.h"

//Commands
#define COMMAND_0 (0x00)

//Global Functions
extern void Protocol__ReceivedCommand(BLUETOOTH_CMD nextCommand);
#endif

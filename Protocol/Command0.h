/*
 * Command0.h
 *
 *  Created on: Apr 16, 2016
 *      Author: DLThrasher
 */

#ifndef PROTOCOL_COMMAND0_H_
#define PROTOCOL_COMMAND0_H_

#include "Protocol.h"
#include "HC05.h"

//Commands!
#define COMMAND_UP      (0x05)
#define COMMAND_DOWN    (0x06)
#define COMMAND_LEFT    (0x07)
#define COMMAND_RIGHT   (0x08)
#define COMMAND_OFF     (0x09)
#define COMMAND_ON      (0x0A)
#define COMMAND_DELAY   (0x0B)
#define COMMAND_LEVEL   (0x0C)
//Global Functions
void Command0__Process(BLUETOOTH_CMD);

#endif /* PROTOCOL_COMMAND0_H_ */

/*
 * SoftwareWatchdog.h
 *
 *  Created on: May 2, 2016
 *      Author: DLThrasher
 */

#ifndef TIVA_HARDWARE_SOFTWAREWATCHDOG_H_
#define TIVA_HARDWARE_SOFTWAREWATCHDOG_H_

//*****************************************************************************
//    Includes
//*****************************************************************************
#include "Project.h"
//*****************************************************************************
//    Data Types & Enums
//*****************************************************************************
typedef UINT8 SWWATCH_TAG_TYPE;
//*****************************************************************************
//    Defines
//*****************************************************************************
static const SWWATCH_TAG_TYPE SWWATCHDOG_INVALID_TAG = 0xFF;
//*****************************************************************************
//    Global Functions Prototypes
//*****************************************************************************
void SoftwareWatchdog__Run(void);
SWWATCH_TAG_TYPE SoftwareWatchdog__GetTag(UINT32,  void (*)(void));
void SoftwareWatchdog__Update(SWWATCH_TAG_TYPE);

#endif /* TIVA_HARDWARE_SOFTWAREWATCHDOG_H_ */

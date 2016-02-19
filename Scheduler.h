/*
 * Scheduler.h
 *
 *  Created on: Feb 14, 2016
 *      Author: DLThrasher
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

//*****************************************************************************
//    Includes
//*****************************************************************************
#include "Project.h"

//*****************************************************************************
//    MACROS
//*****************************************************************************
#define SCHEDULER_SECONDS(x)     (x*1000)
//*****************************************************************************
//    ENUMS
//*****************************************************************************
typedef enum
{
   SCHEDULER_STATE__NOT_INITIALIZED,
   SCHEDULER_STATE__RUNNING,
   SCHEDULER_STATE__EXPIRED
}SCHEDULER_STATE_ENUM;

typedef enum
{
   SCHEDULER__SERVO,
   SCHEDULER_FLAG_MAX
}SCHEDULER_ENUM;

//*****************************************************************************
//    GLOBAL FUNCTIONS
//*****************************************************************************
extern SCHEDULER_STATE_ENUM Scheduler__GetTimerState(SCHEDULER_ENUM flag);
extern void Scheduler__Initialize(void);
extern BOOLEAN Scheduler__ResetCount(SCHEDULER_ENUM flag);
extern void Scheduler__Run(void);
extern void Scheduler__SetResetCountValue(SCHEDULER_ENUM flag, UINT32 resetCount);

#endif /* SCHEDULER_H_ */

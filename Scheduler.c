/*
 * Scheduler.c
 *
 *  Created on: Feb 14, 2016
 *      Author: DLThrasher
 */


//*****************************************************************************
//    Includes
//*****************************************************************************
#include "Scheduler.h"
#include "ADXL345.h" //So that we can process the Data as fast as we can!

//*****************************************************************************
//    LOCAL STATIC
//*****************************************************************************
static volatile SCHEDULER_STATE_ENUM SchedulerFlagArray[SCHEDULER_FLAG_MAX];
static UINT32  SchedulerCountArray[SCHEDULER_FLAG_MAX];
static UINT32  SchdulerResetCountArray[SCHEDULER_FLAG_MAX];

//*****************************************************************************
//    GLOBAL FUNCTIONS
//*****************************************************************************

/*
* \brief initialize everything to not initialized
*/
void Scheduler__Initialize(void)
{
   UINT32 i;
   for(i = 0; i < SCHEDULER_FLAG_MAX; i++)
   {
      SchedulerFlagArray[i] = SCHEDULER_STATE__NOT_INITIALIZED;
   }
}

/*
* \brief Determines what functions will run at different frequencies
*/
void Scheduler__Run(void)
{
   UINT32 i;
   for(i = 0; i < SCHEDULER_FLAG_MAX; i++)
   {
      //Decrement Counter if it isn't expired
      if(SchedulerCountArray[i])
      {
         SchedulerCountArray[i]--;
      }

      //Timer expired, SET THE FLAG
      if(!SchedulerCountArray[i])
      {
         if(SchedulerFlagArray[i] == SCHEDULER_STATE__RUNNING)
         {
            SchedulerFlagArray[i] = SCHEDULER_STATE__EXPIRED;
            //Reset the timer
            SchedulerCountArray[i] = SchdulerResetCountArray[i];
         }
         //If expired or not initialized
         else
         {
            //TODO Error condition. We did not service the flag before it was set again.
            SchedulerFlagArray[i] = SCHEDULER_STATE__NOT_INITIALIZED;
         }
      }
   }

}

BOOLEAN Scheduler__ResetCount(SCHEDULER_ENUM flag)
{
   BOOLEAN countWasReset = FALSE;

   if(SchedulerFlagArray[(UINT32)flag] != SCHEDULER_STATE__NOT_INITIALIZED)
   {
      SchedulerFlagArray[(UINT32)flag] = SCHEDULER_STATE__RUNNING;
      SchedulerCountArray[(UINT32)flag] = SchdulerResetCountArray[(UINT32)flag];
      countWasReset = TRUE;
   }

   return countWasReset;
}

void Scheduler__SetResetCountValue(SCHEDULER_ENUM flag, UINT32 resetCount)
{
   SchedulerFlagArray[(UINT32)flag] = SCHEDULER_STATE__RUNNING;
   SchdulerResetCountArray[(UINT32)flag] = resetCount;
   Scheduler__ResetCount(flag);
}

SCHEDULER_STATE_ENUM Scheduler__GetTimerState(SCHEDULER_ENUM flag)
{
   SCHEDULER_STATE_ENUM timerState = SchedulerFlagArray[(UINT32)flag];
   if(SchedulerFlagArray[(UINT32)flag] == SCHEDULER_STATE__EXPIRED)
   {
      //Set the flag back to False since we serviced it
      SchedulerFlagArray[(UINT32)flag] = SCHEDULER_STATE__RUNNING;
   }

   return timerState;
}


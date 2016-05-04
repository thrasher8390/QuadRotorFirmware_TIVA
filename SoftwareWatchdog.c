/*
 * SoftwareWatchdog.c
 *
 *  Created on: May 2, 2016
 *      Author: DLThrasher
 */

//*****************************************************************************
//    Includes
//*****************************************************************************
#include "SoftwareWatchdog.h"
//*****************************************************************************
//    Data Types & Enums
//*****************************************************************************
typedef struct
{
   SWWATCH_TAG_TYPE tag;
   UINT32 detectionTime;
   UINT32 counter;
   int (*callBackFunction)(void);
}SOFTWARE_WATCHDOG_STRUCT;
//*****************************************************************************
//    Defines
//*****************************************************************************
#define MAX_NUMBER_OF_SUBSCRIBERS (12)
//*****************************************************************************
//    Variables
//*****************************************************************************
SOFTWARE_WATCHDOG_STRUCT SoftwareWatchDogDataBase[MAX_NUMBER_OF_SUBSCRIBERS];
static SWWATCH_TAG_TYPE TotalSubscribers = 0;
//*****************************************************************************
//    Local Function Prototypes
//*****************************************************************************

//*****************************************************************************
//    Global Functions
//*****************************************************************************

/*
 * \brief This runs periodically and will run a callback function if the class times out.
 * \details This is called every 1ms. Relies on PERIOD_OF_TIMER_0_US
 */
void SoftwareWatchdog__Run(void)
{
   SWWATCH_TAG_TYPE index;

   for(index = 0; index < TotalSubscribers; index++)
   {
      SOFTWARE_WATCHDOG_STRUCT * tempWathdog = &SoftwareWatchDogDataBase[index];

      if(tempWathdog->counter-- == 0)
      {
         SoftwareWatchdog__Update(index);
         tempWathdog->callBackFunction();
      }
   }

}

/*
 *  \brief if their are still Software Watchdogs available we will subscribe it out to a user
 */
SWWATCH_TAG_TYPE SoftwareWatchdog__GetTag(UINT32 detectionTime,  void (*watchdogCallback)(void))
{
   if(TotalSubscribers <= MAX_NUMBER_OF_SUBSCRIBERS)
   {
      SOFTWARE_WATCHDOG_STRUCT * tempWathdog = &SoftwareWatchDogDataBase[TotalSubscribers];
      tempWathdog->tag = TotalSubscribers;
      TotalSubscribers++;
      tempWathdog->detectionTime = detectionTime;
      tempWathdog->counter = detectionTime;
      tempWathdog->callBackFunction = watchdogCallback;

      return tempWathdog->tag;
   }
   else
   {
      return SWWATCHDOG_INVALID_TAG;
   }
}

/*
 * \brief This is called when the task runs that we are watching
 */
void SoftwareWatchdog__Update(SWWATCH_TAG_TYPE tag)
{
   SOFTWARE_WATCHDOG_STRUCT * tempWathdog = &SoftwareWatchDogDataBase[tag];
   tempWathdog->counter = tempWathdog->detectionTime;
}
//*****************************************************************************
//    Local Functions
//*****************************************************************************

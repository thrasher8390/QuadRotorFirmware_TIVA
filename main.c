/*
 * main.c
 */
//*****************************************************************************
//		Includes
//*****************************************************************************
#include "main.h"
#include "Project.h"
#include "LED.h"
#include "HelperFunctions.h"
#include "Timers.h"
#include "GPIO.h"
#include "Ultrasonic.h"
#include "UART.h"
#include "Sensors.h"
#include "HC05.h"
#include "Protocol.h"
#include "MotorControl.h"
#include "Scheduler.h"
//*****************************************************************************
//		GLOBAL DATA VARIABLES
//*****************************************************************************
int main(void)
{
   IntMasterDisable();
   //
   // Enable lazy stacking for interrupt handlers.  This allows floating-point
   // instructions to be used within interrupt handlers, but at the expense of
   // extra stack usage.
   //
   FPULazyStackingEnable();

   //PLL Runs at 400MHz
   SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); // We are running at 50MHz

   //Init the scheduler routine
   Scheduler__Initialize();
   Timers_Initialize();

   GPIO_Initialize();
   HC05_Initialize();

   //This needs to be called last since we instantly start running the accelerometer.
   Sensors_Initialize();

   IntMasterEnable();
   MotorControl__Initialize();
   //Get ready to read ADXL345
   while(1)
   {
      Protocol__ReceivedCommand(HC05__GetCommand());
   }
}

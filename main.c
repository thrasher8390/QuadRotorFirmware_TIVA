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
#include "Servo.h"
#include "PWM.h"
//*****************************************************************************
//		GLOBAL DATA VARIABLES
//*****************************************************************************
int main(void)
{
   //
   // Enable lazy stacking for interrupt handlers.  This allows floating-point
   // instructions to be used within interrupt handlers, but at the expense of
   // extra stack usage.
   //
   FPULazyStackingEnable();

   //PLL Runs at 400MHz
   SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); // We are running at 160MHz
   //
   // Set up and enable the SysTick timer.  It will be used as a reference
   // for delay loops in the interrupt handlers.  The SysTick timer period
   // will be set up for one second.
   //
   //SysTickPeriodSet(SysCtlClockGet());
   //SysTickEnable();

   GPIO_Initialize();
   HC05_Initialize();
   Sensors_Initialize();
   Timers_Initialize();
   /* Init the servo control module */
   ServoModule_Init();

   IntMasterEnable();

   //////End of Init ADXL345

   //Get ready to read ADXL345
   while(1)
   {
      Protocol__ReceivedCommand(HC05__GetCommand());
   }
}

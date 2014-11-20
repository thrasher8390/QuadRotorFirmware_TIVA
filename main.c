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

		//
		// Set the clocking to run directly from the crystal.
		//
		SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN| SYSCTL_XTAL_16MHZ);

		//
		// Set up and enable the SysTick timer.  It will be used as a reference
		// for delay loops in the interrupt handlers.  The SysTick timer period
		// will be set up for one second.
		//
		SysTickPeriodSet(SysCtlClockGet());
		SysTickEnable();

		GPIO_Initialize();

		//
		// Initialize the UART.
		//
		UART_Initialize();

		Sensors_Init();

		//////End of Init ADXL345

		//Get ready to read ADXL345

	while(1)
	{
		//This should be in main and run periodically
		Sensors_Run();
		LED_ChangeColor(LED_GREEN);
		DelayMS(1);
	}

}

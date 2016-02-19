/*
 * QuadRotorFirmware.h
 *
 *  Created on: Nov 16, 2014
 *      Author: DLThrasher
 */

#ifndef QUADROTORFIRMWARE_H_
#define QUADROTORFIRMWARE_H_


//*****************************************************************************
//		Includes
//*****************************************************************************
#include "inc/tm4c123gh6pm.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "driverlib/timer.h"
#include "driverlib/pwm.h"


//*****************************************************************************
//		Global Enums
//*****************************************************************************
/*!
 * \brief lets make an led blink every 2 seconds
 */
typedef enum
{
	FALSE,
	TRUE
}BOOLEAN;

//*****************************************************************************
//		Global Defines
//*****************************************************************************
#define SYSTEM_CLOCK_FREQUENCY_HZ   (50000000)
#define SYSTEM_CLOCK_FREQUENCY_MHZ  (SYSTEM_CLOCK_FREQUENCY_HZ/1000000)
#define PLL_FREQUENCY_HZ            (400000000)
#define PLL_FREQUENCY_MHZ           (400)
#define CLEAR	(0)
#define SET		(1)

//TYPE DEFS
typedef uint32_t UINT32 ;
typedef uint16_t UINT16 ;
typedef uint8_t UINT8 ;

//Interrupt Pin For SENSORS
#define SENSORS_INT_PORT   (GPIO_PORTD_BASE)
#define SENSORS_INT_PIN    (GPIO_PIN_6)

//TESTPOINTS

#define TESTPOINT_0_PORT      (GPIO_PORTD_BASE)
#define TESTPOINT_0_PIN       (GPIO_PIN_3)
#define SET_TESTPOINT_0()     (GPIOPinWrite(TESTPOINT_0_PORT, TESTPOINT_0_PIN, TESTPOINT_0_PIN))
#define CLEAR_TESTPOINT_0()   (GPIOPinWrite(TESTPOINT_0_PORT, TESTPOINT_0_PIN, CLEAR))

#define TESTPOINT_1_PORT      (GPIO_PORTA_BASE)
#define TESTPOINT_1_PIN       (GPIO_PIN_2)
#define SET_TESTPOINT_1()     (GPIOPinWrite(TESTPOINT_1_PORT, TESTPOINT_1_PIN, TESTPOINT_1_PIN))
#define CLEAR_TESTPOINT_1()   (GPIOPinWrite(TESTPOINT_1_PORT, TESTPOINT_1_PIN, CLEAR))

//*****************************************************************************
//    Interrupt Priorities
//*****************************************************************************
#define I2C_INTERRUPT_PRIORITY               (0x00)
#define GPIO_INTERRUPT_PRIORITY__SENSOR_PIN  (0x01)
#define TIMER_INTERRUPT_PRIORITY__FOREGROUND (0x01)

#endif /* QUADROTORFIRMWARE_H_ */

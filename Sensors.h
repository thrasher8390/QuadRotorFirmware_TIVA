/*
 * Sensors.h
 *
 *  Created on: Nov 19, 2014
 *      Author: DLThrasher
 */

#ifndef SENSORS_H_
#define SENSORS_H_
//*****************************************************************************
//		Includes
//*****************************************************************************
#include "Project.h"
#include "ADXL345.h"
#include "Gyroscope_L3GD20H.h"
//*****************************************************************************
//		Defines
//*****************************************************************************
//Interrupt Pin For SENSORS
#define SENSORS_INT_PORT   (GPIO_PORTD_BASE)
#define ADXL_INT_PIN       (GPIO_PIN_6)
#define GYRO_INT_PIN       (0)
#define SENSORS_INT_PINS   (ADXL_INT_PIN | GYRO_INT_PIN)
//*****************************************************************************
//		Global Functions
//*****************************************************************************
extern void Sensors_Initialize();
extern void Sensors_Run();
extern void Sensors__InterruptIRQ(UINT32);
#endif /* SENSORS_H_ */

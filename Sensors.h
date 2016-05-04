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
//    Data Types
//*****************************************************************************
typedef enum
{
   INTERRUPT_GYRO,
   INTERRUPT_ACCEL
}SENSOR_INTERRUPT;
//*****************************************************************************
//		Defines
//*****************************************************************************
//Interrupt Pin For SENSORS
#define ADXL_INT_PORT      (GPIO_PORTD_BASE)
#define ADXL_INT_PIN       (GPIO_PIN_6)

#define GYRO_INT_PORT      (GPIO_PORTD_BASE)
#define GYRO_INT_PIN       (GPIO_PIN_2)
//*****************************************************************************
//		Global Functions
//*****************************************************************************
void Sensors_Initialize();
void Sensors_Run();
void Sensors__InterruptIRQ(SENSOR_INTERRUPT);
#endif /* SENSORS_H_ */

/*
 * Sensors.c
 *
 *  Created on: Nov 19, 2014
 *      Author: DLThrasher
 */
//*****************************************************************************
//		Includes
//*****************************************************************************
#include "Sensors.h"
#include "LED.h"
//*****************************************************************************
//		Defines
//*****************************************************************************

//*****************************************************************************
//		Variables
//*****************************************************************************
//*****************************************************************************
//		Global Functions
//*****************************************************************************
void Sensors_Initialize()
{
   //Lets initialize the I2C module that will be used for the ADXL345
   //Init I2C Module 0
   I2C_Init0();

	ADXL345_Init();
	Gyro_Init();

	//This is needed to clear out the interrupt.
   ADXL345_Read();
   Gyro_Read();
}

void Sensors_Run()
{
   //Get Accel and Gyrow data and call the filter function.
	//ADXL345_GetData();
	//Gyro_GetData();
   //Filter(accelData, gyroData);
}

void Sensors__InterruptIRQ(UINT32 intStatus)
{
   if((intStatus & ADXL_INT_PIN) == ADXL_INT_PIN)
   {
      ADXL345__InterruptIRQ();
   }
   if((intStatus & GYRO_INT_PIN) == GYRO_INT_PIN)
   {
      Gyro__InterruptIRQ();
   }
}
//*****************************************************************************
//		Local Functions
//*****************************************************************************

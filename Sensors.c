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
#include "SoftwareWatchdog.h"
#include "LED.h"
#include "I2C.h"
//*****************************************************************************
//		Defines
//*****************************************************************************

//*****************************************************************************
//		Variables
//*****************************************************************************
SWWATCH_TAG_TYPE AccelSWWatchTag;
SWWATCH_TAG_TYPE GyroSWWatchTag;
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

   //Subscrib to SWWatchDog
   AccelSWWatchTag = SoftwareWatchdog__GetTag(4, ADXL345__InterruptIRQ);
   GyroSWWatchTag = SoftwareWatchdog__GetTag(4, Gyro__InterruptIRQ);
}

void Sensors_Run()
{
   //Get Accel and Gyrow data and call the filter function.
	//ADXL345_GetData();
	//Gyro_GetData();
   //Filter(accelData, gyroData);
}

void Sensors__InterruptIRQ(SENSOR_INTERRUPT intStatus)
{
   if(intStatus == INTERRUPT_ACCEL)
   {
      ADXL345__InterruptIRQ();
      SoftwareWatchdog__Update(AccelSWWatchTag);
   }
   if(intStatus == INTERRUPT_GYRO)
   {
      Gyro__InterruptIRQ();
      SoftwareWatchdog__Update(GyroSWWatchTag);
   }
}
//*****************************************************************************
//		Local Functions
//*****************************************************************************

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
	ADXL345_Init();
	//Gyro_Init();
}

void Sensors_Run()
{
	ADXL345_Read();
	//Gyro_Read();
}
//*****************************************************************************
//		Local Functions
//*****************************************************************************

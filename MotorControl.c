/*
 * MotorControl.cpp
 *
 *  Created on: Feb 17, 2016
 *      Author: DLThrasher
 */

#include "MotorControl.h"
#include "Servo.h"




void  MotorControl__Initialize(void)
{
   /* Init the servo control module */
   ServoModule_Init();
}



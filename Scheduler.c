/*
 * Scheduler.c
 *
 *  Created on: Feb 14, 2016
 *      Author: DLThrasher
 */


//*****************************************************************************
//    Includes
//*****************************************************************************
#include "Scheduler.h"
#include "ADXL345.h" //So that we can process the Data as fast as we can!

/*
* \brief Determines what functions will run at different frequencies
*/
void Scheduler__Run(void)
{
   ADXL345__ProcessReadings();
}


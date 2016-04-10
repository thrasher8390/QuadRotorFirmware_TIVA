/*
*  File - Protocol
*  Author - Derek Thrasher
*  Date Created - 2/21/215
*/

//Includes
#include "Protocol.h"
#include "LED.h"
#include "HelperFunctions.h"
#include "Servo.h"

/*
* \brief Process received Commands
*/
void Protocol__ReceivedCommand(BLUETOOTH_CMD nextCommand)
{
  switch(nextCommand.CMD)
    {
       case COMMAND_DELAY:
      {
         LED_ChangeColor(LED_RED);
         uint32_t delay = (uint32_t)(((uint16_t)nextCommand.DATA[0] << 8) | nextCommand.DATA[1]);
         DelayMS(delay);
        break;
      }
      case COMMAND_UP:
      {
         ServoModule_SetServoPower(1,ServoModule_GetServoPower(1) + 10);
         ServoModule_SetServoPower(2,ServoModule_GetServoPower(2) + 10);
         ServoModule_SetServoPower(3,ServoModule_GetServoPower(3) + 10);
         ServoModule_SetServoPower(0,ServoModule_GetServoPower(0) + 10);
         LED_ChangeColor(LED_RED_GREEN);
         break;
      }
      case COMMAND_DOWN:
      {
         LED_ChangeColor(LED_BLUE);
         break;
      }
      case COMMAND_LEFT:
      {
         LED_ChangeColor(LED_GREEN);
         break;
      }
      case COMMAND_RIGHT:
      {
         LED_ChangeColor(LED_GREEN_BLUE);
         break;
      }
      case COMMAND_OFF:
      {
         ServoModule_SetServoPower(0,0);
         ServoModule_SetServoPower(1,0);
         ServoModule_SetServoPower(2,0);
         ServoModule_SetServoPower(3,0);

         break;
      }
      case COMMAND_ON:
      {
         break;
      }
      case COMMAND_LEVEL:
      {
         uint32_t level = (uint32_t)(((uint16_t)nextCommand.DATA[0] << 8) | nextCommand.DATA[1]);
         level = (level * MAX_POWER_US)/0xFFFF;
         ServoModule_SetServoPower(0,level);
         ServoModule_SetServoPower(1,level);
         ServoModule_SetServoPower(2,level);
         ServoModule_SetServoPower(3,level);
         break;
      }
      default:
      {
         break;
      }
    }
}

/*
*  File - Command0
*  Author - Derek Thrasher
*  Date Created - 4/16/2016
*/

//Includes
#include "Command0.h"
#include "LED.h"
#include "HelperFunctions.h"
#include "Servo.h"
/*
 * @brief This will process command0 types
 */
void Command0__Process(BLUETOOTH_CMD commandType0)
{
   switch(commandType0.CMD_SUB)
      {
         case COMMAND_DELAY:
        {
           LED_ChangeColor(LED_RED);
           uint32_t delay = (uint32_t)(((uint16_t)commandType0.DATA[0] << 8) | commandType0.DATA[1]);
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
           uint32_t level = (uint32_t)(((uint16_t)commandType0.DATA[0] << 8) | commandType0.DATA[1]);
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

/*
*  File - Protocol
*  Author - Derek Thrasher
*  Date Created - 2/21/215
*/

//Includes
#include "Protocol.h"
#include "LED.h"
#include "HelperFunctions.h"

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
      case COMMAND_DOWN:
      {
         LED_ChangeColor(LED_BLUE);
         Delay(1000);
        break;
      }
      case COMMAND_LEFT:
      {
        break;
      }
      case COMMAND_RIGHT:
      {
        break;
      }
      case COMMAND_OFF:
      {
        break;
      }
      case COMMAND_ON:
      {
        break;
      }
      default:
      {
        break;
      }
    }
}

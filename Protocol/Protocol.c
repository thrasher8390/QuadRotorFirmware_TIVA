/*
*  File - Protocol
*  Author - Derek Thrasher
*  Date Created - 2/21/215
*/

//Includes
#include "Protocol.h"
#include "Command0.h"



/*
* \brief Process received Commands
*/
void Protocol__ReceivedCommand(BLUETOOTH_CMD nextCommand)
{
  switch(nextCommand.CMD)
    {
      case COMMAND_0:
      {
         Command0__Process(nextCommand);
         break;
      }
      default:
      {
         break;
      }
    }
}

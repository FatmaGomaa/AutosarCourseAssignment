/********************************
*Author: Mohanad Fawzy Sallam   *
*Version: v01                   *
*Date: 25/02/2020               *
*********************************/
#include "STD_Types.h"
#include "DoorSensor.h"

error_status DoorSensor_Init (u8 doorChannel)
{
  u8 localError=E_OK;
  if (DoorChannel == DOOR1)
  {
    localError=GPIO_Init (DOOR1_PORT,DOOR1_PIN,DOOR1_OPERATION_MODE);
  }
  else if (DoorChannel == DOOR2)
  {
    localError=GPIO_Init (DOOR1_PORT,DOOR1_PIN,DOOR2_OPERATION_MODE);
  }
  else
  {
    localError=E_NOK;
  }
  return localError;
}
error_status DoorSensor_ReadStatus (u8 doorChannel,u8 * status)
{
    u8 localError=E_OK;
  if (DoorChannel == DOOR1)
  {
    localError=GPIO_GetPinValue (DOOR1_PORT,DOOR1_PIN,status);
  }
  else if (DoorChannel == DOOR2)
  {
    localError=GPIO_GetPinValue (DOOR1_PORT,DOOR1_PIN,status);
  }
  else
  {
    localError=E_NOK;
  }
  return localError;
}

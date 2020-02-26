/********************************
*Author: Mohanad Fawzy Sallam   *
*Version: v1.1                   *
*Date: 26/02/2020               *
*********************************/
#include "STD_Types.h"
#include "SysClk.h"
#include "GPIO.h"
#include "DoorSensor.h"

error_status DoorSensor_Init (u8 doorChannel)
{
  error_status localError=E_OK;
  if (doorChannel == DOOR1)
  {
    if (DOOR1_PORT == PORT_A)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R0);
    else if (DOOR1_PORT == PORT_B)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R1);
    else if (DOOR1_PORT == PORT_C)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R2);
    else if (DOOR1_PORT == PORT_D)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R3);
    else if (DOOR1_PORT == PORT_E)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R4);
    else if (DOOR1_PORT == PORT_F)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R5);
    
    localError=GPIO_Init (DOOR1_PORT,DOOR1_PIN,DOOR1_OPERATION_MODE);
  }
  else if (doorChannel == DOOR2)
  {
        if (DOOR2_PORT == PORT_A)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R0);
    else if (DOOR2_PORT == PORT_B)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R1);
    else if (DOOR2_PORT == PORT_C)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R2);
    else if (DOOR2_PORT == PORT_D)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R3);
    else if (DOOR2_PORT == PORT_E)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R4);
    else if (DOOR2_PORT == PORT_F)
      localError=RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R5);
    localError=GPIO_Init (DOOR2_PORT,DOOR2_PIN,DOOR2_OPERATION_MODE);
  }
  else
  {
    localError=E_NOK;
  }
  return localError;
}
error_status DoorSensor_ReadStatus (u8 doorChannel,u8 * status)
{
    error_status localError=E_OK;
  if (doorChannel == DOOR1)
  {
    localError=GPIO_ReadPin (DOOR1_PORT,DOOR1_PIN,status);
  }
  else if (doorChannel == DOOR2)
  {
    localError=GPIO_ReadPin (DOOR2_PORT,DOOR2_PIN,status);
  }
  else
  {
    localError=E_NOK;
  }
  return localError;
}

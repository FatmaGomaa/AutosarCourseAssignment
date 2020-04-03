/************************************************************************
 * File name: DoorSensor.c
 *
 *
 * Description: This file contains the implementatoins of the doorSensor functionalities
 *
 * owner: Mohanad Fawzy Sallam        
 * date: 26/2/2020
 * version 1.1
 ***************************************************************************/
#include "STD_Types.h"
#include "SysClk.h"
#include "GPIO.h"
#include "DoorSensor.h"
/************************************************************************
 * Function name: DoorSensor_Init
 *
 * parameters:  Input:
 *                 doorChannel
 *                     type: u8
 *                     Description: DoorSensor number  (DOOR1,DOOR2)
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to initialize the specified door sensor based on the given initial configuraton
 ***************************************************************************/
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
/************************************************************************
 * Function name: DoorSensor_ReadStatus
 *
 * parameters:  Input:
 *                 doorChannel
 *                     type: u8
 *                     Description: DoorSensor number  (DOOR1,DOOR2)
 *              Output: 
 *                     status
 *                     type: pointer to u8
 *                     Description: address of u8 variable that will store the state of the door sensor.
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to get the state of the door sensor
 ***************************************************************************/
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

/************************************************************************
 * File name: GPIO.C
 *
 *
 * Description: This file contains the implementations  of the GPIO driver functionalities
 *
 * owner: Mostafa Ghareeb
 *        Mohanad Fawzy Sallam
 * date: 26/2/2020
 * version 1.1
 *
 ***************************************************************************/
#include "STD_Types.h"
#include "GPIO.h"
 /*Macros to check the passed port and pin arguments are valid*/
#define CHECK_PORT(PORT) (PORT == PORT_A || PORT == PORT_B ||PORT == PORT_C ||PORT == PORT_D||PORT == PORT_E||PORT == PORT_F)
#define CHECK_PIN(PIN) (PIN == PIN_0 ||PIN == PIN_1 || PIN == PIN_2 ||PIN == PIN_3 ||PIN == PIN_4 ||PIN == PIN_5 ||PIN == PIN_6 ||PIN == PIN_7)

/*Lock key is used to allow configuration of port F pins*/
#define GPIO_LOCK_KEY 0x4C4F434B
/*offset of the GPIO registers from the base address of each port */
#define GPIO_O_DATA             0x00000000  /* GPIO Data              */
#define GPIO_O_DIR              0x00000400  /* GPIO Direction         */
#define GPIO_O_PUR              0x00000510  /* GPIO Pull-Up Select    */
#define GPIO_O_PDR              0x00000514  /* GPIO Pull-Down Select  */
#define GPIO_O_DEN              0x0000051C  /* GPIO Digital Enable    */
#define GPIO_O_LOCK             0x00000520  /* GPIO Lock              */
#define GPIO_O_CR               0x00000524  /* GPIO Commit            */
/************************************************************************
 * Function name: GPIO_Init
 *
 * parameters:  Input:
 *                 Port
 *                     type: u32
                        Description: GPIO port number (PORT_A,PORT_B,PORT_C,PORT_D,PORT_E,PORT_F)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN_0 .. PIN_7)
 *                 Mode
 *                     type: u8
 *                     Description: GPIO pin mode (IP_PULL_UP,IP_PULL_DOWN,OP_PUSH_PULL)
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to initialize all the GPIO Groups in the configurations
 ***************************************************************************/
error_status GPIO_Init (u32 Port, u8 Pin, u8 Mode)
{
  error_status localError = E_OK;
  if (CHECK_PORT(Port))
  {
    if (CHECK_PIN(Pin))
    {
      if (Port == PORT_F)
      {
        *((u32 *)(Port + GPIO_O_LOCK)) = GPIO_LOCK_KEY;
        *((u32 *)(Port + GPIO_O_CR)) |=  1<<Pin;
        *((u32 *)(Port + GPIO_O_DEN)) |=  1<<Pin;
      }
        if (Mode== OP_PUSH_PULL)
        {
            *((u32 *)(Port + GPIO_O_DIR)) |=  1<<Pin;
        }
        else if (Mode == IP_PULL_UP)
        {
          *((u32 *)(Port + GPIO_O_DIR)) &=  ~(1<<Pin);
          *((u32 *)(Port + GPIO_O_PUR)) |=  1<<Pin;
        }
        else if (Mode == IP_PULL_DOWN)
        {
          *((u32 *)(Port + GPIO_O_DIR)) &=  ~(1<<Pin);
          *((u32 *)(Port + GPIO_O_PDR)) |=  1<<Pin;
        }
        else
        {
          localError = E_NOK;
        }
    
    }
    else
    {
      localError = E_NOK;
    }
  }
  else
  {
    localError = E_NOK;
  }
  return localError;
}
/************************************************************************
 * Function name: GPIO_WritePin
 *
 * parameters:  Input:
 *                 Port
 *                     type: u32
                        Description: GPIO port number (PORT_A,PORT_B,PORT_C,PORT_D,PORT_E,PORT_F)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN_0 .. PIN_7)
 *                 Value
 *                     type: u8
 *                     Description: GPIO pin output value (IP_PULL_UP,IP_PULL_DOWN,OP_PUSH_PULL)
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to set value of the specified pin
 ***************************************************************************/

error_status GPIO_WritePin (u32 Port, u8 Pin, u8 Value)
{
  error_status localError = E_OK;
  if (CHECK_PORT(Port))
  {
    if (CHECK_PIN(Pin))
    {
        *((u32 *)(Port + GPIO_O_DATA+0x3FC)) &= ~( 1<<Pin);
        *((u32 *)(Port + GPIO_O_DATA+0x3FC)) |=  Value<<Pin;

    }
    else
    {
      localError = E_NOK;
    }
  }
  else
  {
    localError = E_NOK;
  }
  return localError;
}
/************************************************************************
 * Function name: GPIO_ReadPin
 *
 * parameters:  Input:
 *                 Port
 *                     type: u32
 *                     Description: GPIO port number (PORT_A,PORT_B,PORT_C,PORT_D,PORT_E,PORT_F)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN_0 .. PIN_7)
 *              Output: 
 *                     Data
 *                     type: pointer to u8
 *                     Description: address of u8 variable that will store the specified pin reading.
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to get reading of the GPIO pin value
 ***************************************************************************/
error_status GPIO_ReadPin (u32 Port, u8 Pin, u8 * Data)
{
  error_status localError = E_OK;
  if (CHECK_PORT(Port))
  {
    if (CHECK_PIN(Pin))
    {
        *Data = (*((u32 *)(Port + GPIO_O_DATA+0x3FC)) >> Pin)&1;
    }
    else
    {
      localError = E_NOK;
    }
  }
  else
  {
    localError = E_NOK;
  }
  return localError;
}

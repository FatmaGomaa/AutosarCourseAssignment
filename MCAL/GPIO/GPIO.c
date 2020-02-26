/********************************
*Author: Mostafa Ghareeb        *
*        Mohanad Fawzy Sallam   * 
*Version: v1.1                  *
*Date: 26/02/2020               *
*********************************/
#include "STD_Types.h"
#include "GPIO.h"

#define CHECK_PORT(PORT) (PORT == PORT_A || PORT == PORT_B ||PORT == PORT_C ||PORT == PORT_D||PORT == PORT_E||PORT == PORT_F)
#define CHECK_PIN(PIN) (PIN == PIN_0 ||PIN == PIN_1 || PIN == PIN_2 ||PIN == PIN_3 ||PIN == PIN_4 ||PIN == PIN_5 ||PIN == PIN_6 ||PIN == PIN_7)

#define GPIO_LOCK_KEY 0x4C4F434B

#define GPIO_O_DATA             0x00000000  // GPIO Data
#define GPIO_O_DIR              0x00000400  // GPIO Direction
#define GPIO_O_PUR              0x00000510  // GPIO Pull-Up Select
#define GPIO_O_PDR              0x00000514  // GPIO Pull-Down Select
#define GPIO_O_DEN              0x0000051C  // GPIO Digital Enable
#define GPIO_O_LOCK             0x00000520  // GPIO Lock
#define GPIO_O_CR               0x00000524  // GPIO Commit

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

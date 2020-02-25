/********************************
*Author: Mostafa Ghareeb        *
*        Mohanad Fawzy Sallam   * 
*Version: v01                   *
*Date: 25/02/2020               *
*********************************/
#include "STD_Types.h"
#include "GPIO.h"

#define CHECK_PORT(PORT) (PORT == PORT_A || PORT == PORT_B ||PORT == PORT_C ||PORT == PORT_D||PORT == PORT_E||PORT == PORT_F)
#define CHECK_PIN(PIN) (PIN == PIN_0 ||PIN == PIN_1 || PIN == PIN_2 ||PIN == PIN_3 ||PIN == PIN_4 ||PIN == PIN_5 ||PIN == PIN_6 ||PIN == PIN_7)

/*
#define GPIO_O_DATA             0x00000000  // GPIO Data
#define GPIO_O_DIR              0x00000400  // GPIO Direction
#define GPIO_O_IS               0x00000404  // GPIO Interrupt Sense
#define GPIO_O_IBE              0x00000408  // GPIO Interrupt Both Edges
#define GPIO_O_IEV              0x0000040C  // GPIO Interrupt Event
#define GPIO_O_IM               0x00000410  // GPIO Interrupt Mask
#define GPIO_O_RIS              0x00000414  // GPIO Raw Interrupt Status
#define GPIO_O_MIS              0x00000418  // GPIO Masked Interrupt Status
#define GPIO_O_ICR              0x0000041C  // GPIO Interrupt Clear
#define GPIO_O_AFSEL            0x00000420  // GPIO Alternate Function Select
#define GPIO_O_DR2R             0x00000500  // GPIO 2-mA Drive Select
#define GPIO_O_DR4R             0x00000504  // GPIO 4-mA Drive Select
#define GPIO_O_DR8R             0x00000508  // GPIO 8-mA Drive Select
#define GPIO_O_ODR              0x0000050C  // GPIO Open Drain Select
#define GPIO_O_PUR              0x00000510  // GPIO Pull-Up Select
#define GPIO_O_PDR              0x00000514  // GPIO Pull-Down Select
#define GPIO_O_SLR              0x00000518  // GPIO Slew Rate Control Select
#define GPIO_O_DEN              0x0000051C  // GPIO Digital Enable
#define GPIO_O_LOCK             0x00000520  // GPIO Lock
#define GPIO_O_CR               0x00000524  // GPIO Commit
#define GPIO_O_AMSEL            0x00000528  // GPIO Analog Mode Select
#define GPIO_O_PCTL             0x0000052C  // GPIO Port Control
#define GPIO_O_ADCCTL           0x00000530  // GPIO ADC Control
#define GPIO_O_DMACTL           0x00000534  // GPIO DMA Control
#define GPIO_O_SI               0x00000538  // GPIO Select Interrupt
#define GPIO_O_DR12R            0x0000053C  // GPIO 12-mA Drive Select
#define GPIO_O_WAKEPEN          0x00000540  // GPIO Wake Pin Enable
#define GPIO_O_WAKELVL          0x00000544  // GPIO Wake Level
#define GPIO_O_WAKESTAT         0x00000548  // GPIO Wake Status
#define GPIO_O_PP               0x00000FC0  // GPIO Peripheral Property
#define GPIO_O_PC               0x00000FC4  // GPIO Peripheral Configuration
*/
typedef struct 
{
  u32 DATA;
  u32 DIR;
  u32 IS;
  u32 IBE;
  u32 IEV;
  u32 IM;
  u32 RIS;
  u32 MIS;
  u32 ICR;
  u32 AFSEL;
  u32 DR2R;
  u32 DR4R;
  u32 DR8R;
  u32 ODR;
  u32 PUR;
  u32 PDR;
  u32 SLR;
  u32 DEN;
  u32 LOCK;
  u32 CR;
  u32 AMSEL;
  u32 PCTL;
  u32 ADCCTL;
  u32 DMACTL;
  u32 SI;
  u32 DR12R;
  u32 WAKEPEN;
  u32 WAKELVL;
  u32 WAKESTAT;
  u32 PP;
  u32 PC;
}GPIO_t;
#define PORTA_BASE_ADDRESS 0x40010800


error_status GPIO_Init (u32 Port, u8 Pin, u8 Mode)
{
  GPIO_t * MyPort = ((GPIO_t *)Port); 
  error_status localError = E_OK;
  if (CHECK_PORT(Port))
  {
    if (CHECK_PIN(Pin))
    {
        if (Mode== OP_PUSH_PULL)
        {
          MyPort->DIR|=(u32)(1<<Pin);
        }
        else if (Mode == IP_PULL_UP)
        {
          MyPort->DIR &= ~(u32)(1<<Pin);
          MyPort->PUR = (u32)(1<<Pin);
        }
        else if (Mode == IP_PULL_DOWN)
        {
          MyPort->DIR &= ~(u32)(1<<Pin);
          MyPort->PDR = (u32)(1<<Pin);
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
    GPIO_t * MyPort = ((GPIO_t *)Port); 
  error_status localError = E_OK;
  if (CHECK_PORT(Port))
  {
    if (CHECK_PIN(Pin))
    {
      MyPort->DATA=(u32)(Value<<Pin) ;
    
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
      GPIO_t * MyPort = ((GPIO_t *)Port); 
  error_status localError = E_OK;
  if (CHECK_PORT(Port))
  {
    if (CHECK_PIN(Pin))
    {
      *Data=(u8)(MyPort->DATA<<Pin) ;
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
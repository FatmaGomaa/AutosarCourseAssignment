/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 08-04-2020       */
/******************************/
#include "./LIB/STD_TYPES/STD_Types.h"
#include "./LIB/BIT_MATH/BIT_MATH.h"
#include "./MCAL/DIO/DIO.h"
#include "MCAL/UART/UART.h"
#include "./MCAL/TIMER0/TIMER0.h"
#include "./OS/OS_interface.h"
#include "./APP/DoorContact/DoorContact.h"
#include "./APP/LeftDoor/LeftDoor.h"
#include "./APP/RightDoor/RightDoor.h"
#include "./RTE/RTE.h"

void main(void)
{
    /*Initializing used pins*/
    DIO_SetPinDir(RIGHT_DOOR_PORT,RIGHT_DOOR_PIN,RIGHT_DOOR_DIR);
    DIO_SetPinValue(RIGHT_DOOR_PORT,RIGHT_DOOR_PIN,RIGHT_DOOR_MODE);
    DIO_SetPinDir(LEFT_DOOR_PORT,LEFT_DOOR_PIN,LEFT_DOOR_DIR);
    DIO_SetPinValue(LEFT_DOOR_PORT,LEFT_DOOR_PIN,LEFT_DOOR_MODE);
    DIO_SetPinDir(PORT_D,PIN1,OUTPUT_PIN);
    UART_Init();
    /*Initializing app components*/
    LeftDoor_Init();
    RightDoor_Init();
    DoorContact_Init();
    /*Creating OS tasks*/
    RTOS_CreateTask(0,2,TASK_ACCESSIBLE, RTE_Task_02MS);
    RTOS_CreateTask(0,10,TASK_ACCESSIBLE, RTE_Task_10MS);
    /*Starting the OS*/
    RTOS_START();
    while(1)
    {

    }
}



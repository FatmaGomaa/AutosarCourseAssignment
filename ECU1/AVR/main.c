/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 08-04-2020       */
/******************************/
#include "./LIB/STD_TYPES/STD_Types.h"
#include "./LIB/BIT_MATH/BIT_MATH.h"
#include "./MCAL/DIO/DIO.h"
#include "./OS/OS_interface.h"
#include "./APP/DoorContact/DoorContact.h"
#include "./APP/LeftDoor/LeftDoor.h"
#include "./APP/RightDoor/RightDoor.h"
#include "./RTE/RTE.h"


#define TASK_PERIODICITY_10MS					10
#define TASK_FIRST_DELAY_10MS					0

#define TASK_PERIODICITY_02MS					2
#define TASK_FIRST_DELAY_02MS					0
void main(void)
{
    /*Initializing used pins*/
    DIO_SetPinDir(RIGHT_DOOR_PORT,RIGHT_DOOR_PIN,RIGHT_DOOR_DIR);
    DIO_SetPinValue(RIGHT_DOOR_PORT,RIGHT_DOOR_PIN,RIGHT_DOOR_MODE);
    DIO_SetPinDir(LEFT_DOOR_PORT,LEFT_DOOR_PIN,LEFT_DOOR_DIR);
    DIO_SetPinValue(LEFT_DOOR_PORT,LEFT_DOOR_PIN,LEFT_DOOR_MODE);
    DIO_SetPinDir(PORT_D,PIN1,OUTPUT_PIN);
    /*Initializing app components*/
    LeftDoor_Init();
    RightDoor_Init();
    DoorContact_Init();
    /*Creating OS tasks*/
    RTOS_CreateTask(TASK_FIRST_DELAY_02MS,TASK_PERIODICITY_02MS,TASK_ACCESSIBLE, RTE_Task_02MS);
    RTOS_CreateTask(TASK_FIRST_DELAY_10MS,TASK_PERIODICITY_10MS,TASK_ACCESSIBLE, RTE_Task_10MS);
    /*Starting the OS*/
    RTOS_START();
    while(1)
    {

    }
}



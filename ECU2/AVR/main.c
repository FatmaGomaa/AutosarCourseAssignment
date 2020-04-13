/*******************************************************************************************************
 * File name: main.c                                                                                   *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the implementation of the Dimmer Application driver                 *
 *                                                                                                     *
 * Author: Fatima Gomaa                                                                                *
 * Date:   April 3, 2020                                                                               *
 * Version 1.0 : Initial Creation 					                                                   *
 * Version 1.1 : Adding OS to the project															   *
 *******************************************************************************************************/

#include "./LIB/STD_TYPES/STD_Types.h"
#include "./LIB/BIT_MATH/BIT_MATH.h"
#include "./MCAL/DIO/DIO.h"
#include "./MCAL/TIMER0/TIMER0.h"
#include "./MCAL/UART/UART.h"
#include "./OS/OS_interface.h"
#include "./APP/Light/Light.h"
#include "./APP/Dimmer/Dimmer.h"
#include "./RTE/RTE.h"

#define TASK_PERIODICITY_10MS					10
#define TASK_FIRST_DELAY_10MS					0
void main(void)
{
    /*Initializing used pins*/
    DIO_SetPinDir(LIGHT_PORT,LIGHT_PIN,LIGHT_DIR);
    DIO_SetPinDir(PORT_D,PIN0,INPUT_FLOATING);
    /*Initializing app components*/
	UART_Init();
    Dimmer_Init();
    Light_Init();
    /*Creating OS tasks*/
    RTOS_CreateTask(TASK_FIRST_DELAY_10MS,TASK_PERIODICITY_10MS,TASK_ACCESSIBLE, RTE_Task_10MS);
    /*Starting the OS*/
    RTOS_START();
    while(1)
    {

    }
}

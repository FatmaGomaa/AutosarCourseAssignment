/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 08-04-2020       */
/******************************/
#include "../LIB/STD_TYPES/STD_TYPES.h"
#include "../LIB/BIT_MATH/BIT_MATH.h"

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/UART/UART.h"

#include "../APP/DoorContact/DoorContact.h"
#include "../APP/LeftDoor/LeftDoor.h"
#include "../APP/RightDoor/RightDoor.h"

#include "../Service/COM/COM.h"

#include "RTE.h"

#define DOOR_STATUS_SIGNAL_ID	0

static u8 Rte_RightDoorStatus ;
static u8 Rte_LeftDoorStatus  ;

/*Send-Rec*/

error_status RTE_WriteRightDoorStatus(u8 status)
{
	error_status local_error = E_OK;
	Rte_RightDoorStatus = status;
	return local_error;
}

error_status RTE_WriteLeftDoorStatus(u8 status)
{
	error_status local_error = E_OK;
	Rte_LeftDoorStatus = status;
	return local_error;
}

error_status RTE_WriteDoorStatus(u8 status)
{
	error_status local_error = E_OK;
	local_error = COMM_Send(DOOR_STATUS_SIGNAL_ID, status);
	return local_error;
}

error_status RTE_ReadRightDoorStatus(u8* status)
{
	error_status local_error = E_OK;
	*status = Rte_RightDoorStatus;
	return local_error;
}

error_status RTE_ReadLeftDoorStatus(u8* status)
{
	error_status local_error = E_OK;
	*status = Rte_LeftDoorStatus;
	return local_error;
}


/*Client - Server*/

error_status RTE_CallGetRightDoorStatus(u8* status)
{
	error_status local_error = E_OK;
	local_error = DIO_GetPinValue(RIGHT_DOOR_PORT,RIGHT_DOOR_PIN,status);
	return local_error;
}

error_status RTE_CallGetLeftDoorStatus(u8* status)
{
	error_status local_error = E_OK;
	local_error = DIO_GetPinValue(LEFT_DOOR_PORT,LEFT_DOOR_PIN,status);
	return local_error;
}


void RTE_Task_02MS(void)
{
	RightDoor_GetStatus();
	LeftDoor_GetStatus();
}

void RTE_Task_10MS(void)
{
	DoorContact_UpdateStatus();
	COMM_TXMainFunction();
}

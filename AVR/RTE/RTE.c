/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 03-04-2020       */
/******************************/
#include "../LIB/STD_TYPES/STD_TYPES.h"
#include "../LIB/BIT_MATH/BIT_MATH.h"

#include "../MCAL/DIO/DIO.h"
#include "RTE.h"

#define DOOR_OPEN   	0
#define	DOOR_CLOSED  	1
#define	LIGHT_OFF  		0
#define LIGHT_ON   		1


static u8 Rte_RightDoorStatus ;
static u8 Rte_LeftDoorStatus  ;
static u8 Rte_DoorStatus      ;
static u8 Rte_LightStatus     ;

/*RTE Init*/

error_status RTE_RightDoorInit(void)
{
	error_status local_error = E_OK;
	local_error  = DIO_SetPinDir(RIGHT_DOOR_PORT,RIGHT_DOOR_PIN,RIGHT_DOOR_DIR);
	local_error |= DIO_SetPinValue(RIGHT_DOOR_PORT,RIGHT_DOOR_PIN,RIGHT_DOOR_MODE);
	return local_error;
}

error_status RTE_LeftDoorInit(void)
{
	error_status local_error = E_OK;
	local_error  = DIO_SetPinDir(LEFT_DOOR_PORT,LEFT_DOOR_PIN,LEFT_DOOR_DIR);
	local_error |= DIO_SetPinValue(LEFT_DOOR_PORT,LEFT_DOOR_PIN,LEFT_DOOR_MODE);
	return local_error;
}

error_status RTE_LightInit(void)
{
	error_status local_error = E_OK;
	local_error  = DIO_SetPinDir(LIGHT_PORT,LIGHT_PIN,LIGHT_DIR);
	return local_error;
}

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
	Rte_DoorStatus = status;
	return local_error;
}

error_status RTE_WriteLightStatus(u8 status)
{
	error_status local_error = E_OK;
	Rte_LightStatus = status;
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

error_status RTE_ReadDoorStatus(u8* status)
{
	error_status local_error = E_OK;
	*status = Rte_DoorStatus;
	return local_error;
}

error_status RTE_ReadLightStatus(u8* status)
{
	error_status local_error = E_OK;
	*status = Rte_LightStatus;
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

error_status RTE_CallLightON(void)
{
	error_status local_error = E_OK;
	local_error = DIO_SetPinValue(LIGHT_PORT,LIGHT_PIN,LIGHT_ON);
	return local_error;
}

error_status RTE_CallLightOFF(void)
{
	error_status local_error = E_OK;
	local_error = DIO_SetPinValue(LIGHT_PORT,LIGHT_PIN,LIGHT_OFF);
	return local_error;
}

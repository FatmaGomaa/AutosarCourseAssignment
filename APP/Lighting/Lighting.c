/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.1             */
/* Date    : 26-2-2020        */
/******************************/
#include "STD_Types.h"
#include "Lamp.h"
#include "LeftDoor.h"
#include "RightDoor.h"
#include "Lighting.h"

void lighting (void)
{
	u8 rightDoor_status = 1;
    u8 leftDoor_status  = 1;
    RightDoor_GetStatus(&rightDoor_status);
    LeftDoor_GetStatus(&leftDoor_status);
    if(rightDoor_status || leftDoor_status)	
    /*Check if one of the doors is open*/
    {
        Lamp_Update(lAMP1_CHANNEL,LAMP_ON);
    }
    else
    {
        Lamp_Update(lAMP1_CHANNEL,LAMP_OFF);
    }
}
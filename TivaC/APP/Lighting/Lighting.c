/**************************************************************************************
 * File name: Lighting.c
 *
 * Description: This file contains the implementatoins of the Lighting functionalities
 *
 * Author:  Moustafa Ghareeb        
 * Date:    26-2-2020  
 * Version: 1.1
 *************************************************************************************/
#include "STD_Types.h"
#include "Lamp.h"
#include "LeftDoor.h"
#include "RightDoor.h"
#include "Lighting.h"
/***********************************************************************************************
 * Function name: lighting
 *
 * parameters:  Input:  NA
 *              Output: NA
 *              In/out: NA
 * return: NA
 * Description: This function Turns the light on and off depending on the doors sensors status
 **********************************************************************************************/
void Lighting (void)
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
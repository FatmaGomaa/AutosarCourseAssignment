/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 03-04-2020       */
/******************************/
#include "./LIB/STD_TYPES/STD_Types.h"
#include "./LIB/BIT_MATH/BIT_MATH.h"
#include "./MCAL/DIO/DIO.h"
#include "./APP/DoorContact/DoorContact.h"
#include "./APP/LeftDoor/LeftDoor.h"
#include "./APP/RightDoor/RightDoor.h"
#include "./APP/Light/Light.h"
#include "./APP/Dimmer/Dimmer.h"

void main(void)
{
    /*Initialize the Left door sensor*/
    LeftDoor_Init();
    /*Initialize the Right door sensor*/
    RightDoor_Init();
    /*Initialize the door contacts*/
    DoorContact_Init();
    /*Initialize the dimmer*/
    Dimmer_Init();
    /*Initialize the light*/
    Light_Init();
    while(1)
    {
        RightDoor_GetStatus();
        LeftDoor_GetStatus();
        DoorContact_UpdateStatus();
        Dimmer_UpdateStatus();
        Light_UpdateLight();
    }
}

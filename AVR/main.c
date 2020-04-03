#include "./LIB/STD_TYPES/STD_Types.h"
#include "./MCAL/SYSCLK/SysClk.h"
#include "./MCAL/GPIO/GPIO.h"
#include "./ECUAL/DoorSensor/DoorSensor.h"
#include "./ECUAL/Lamp/Lamp.h"
#include "./APP/LeftDoor/LeftDoor.h"
#include "./APP/RightDoor/RightDoor.h"
#include "./APP/Lighting/Lighting.h"

void main(void)
{
    /*Enable Clock on Port F*/
    RCGCGPIO_EnablePeripheralClock(SYSCTL_RCGCGPIO_R5);
    /*Initialize the Lamp*/
    Lamp_Init();
    /*Initialize the Left door sensor*/
    LeftDoor_Init();
    /*Initialize the Right door sensor*/
    RightDoor_Init();
    while(1)
    {
        Lighting();
    }
}

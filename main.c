#include "STD_Types.h"
#include "SysClk.h"
#include "GPIO.h"
#include "DoorSensor.h"
#include "Lamp.h"
#include "LeftDoor.h"
#include "RightDoor.h"
#include "Lighting.h"

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
        lighting();
    }
}

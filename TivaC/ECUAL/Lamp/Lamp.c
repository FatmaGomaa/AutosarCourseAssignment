#include"STD_Types.h"
#include"GPIO.h"
#include"Lamp.h"

typedef struct {
	u32 LAMP_PORT;
	u8 LAMP_PIN;
	u8 LAMP_MODE;
} LAMP_t;

LAMP_t LAMP_CHANNELS[NUMBER_OF_LAMPS]={{LAMP_1_PORT,LAMP_1_PIN,LAMP_1_MODE}};

error_status Lamp_Init(void) {
	error_status Local_ReturnValue = E_OK;
	u8 LocalIterator = 0;
	for (LocalIterator = 0; LocalIterator < NUMBER_OF_LAMPS; LocalIterator++) {
		Local_ReturnValue = GPIO_Init(LAMP_CHANNELS[LocalIterator].LAMP_PORT,
				LAMP_CHANNELS[LocalIterator].LAMP_PIN,
				LAMP_CHANNELS[LocalIterator].LAMP_MODE);
		if (Local_ReturnValue == E_NOK) {
			LocalIterator = NUMBER_OF_LAMPS + 1;
		}
	}
	return Local_ReturnValue;
}

error_status Lamp_Update(u8 lampChannel, u8 lampState) {
	error_status Local_ReturnValue = E_OK;
		if (lampState == LAMP_ON) {
			Local_ReturnValue = GPIO_WritePin(LAMP_CHANNELS[lampChannel].LAMP_PORT,LAMP_CHANNELS[lampChannel].LAMP_PIN, LAMP_ON);
		} else if (lampState == LAMP_OFF) {
			Local_ReturnValue = GPIO_WritePin(LAMP_CHANNELS[lampChannel].LAMP_PORT,LAMP_CHANNELS[lampChannel].LAMP_PIN, LAMP_OFF);
		}
		else{
			Local_ReturnValue=E_NOK;
		}
	return Local_ReturnValue;
}


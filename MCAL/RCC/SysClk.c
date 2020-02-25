#include "STD_TYPES.h"
#include "SysClk.h"

error_status RCGCGPIO_EnablePeripheralClock(u32 Copy_u32GPIO_Peripheral){
	error_status Local_ErrorStatus = NOT_OK;
	SYSCTL_RCGCGPIO |= Copy_u32GPIO_Peripheral;
	
	if((SYSCTL_RCGCGPIO & Copy_u32GPIO_Peripheral) == Copy_u32GPIO_Peripheral){
		Local_ErrorStatus = OK;
		return Local_ErrorStatus;
	}
	return Local_ErrorStatus;
}

error_status RCGCGPIO_DisablePeripheralClock(u32 Copy_u32GPIO_Peripheral){
	error_status Local_ErrorStatus = NOT_OK;
	SYSCTL_RCGCGPIO &=~ Copy_u32GPIO_Peripheral;
	
	if((SYSCTL_RCGCGPIO & Copy_u32GPIO_Peripheral) == Copy_u32GPIO_Peripheral){
		Local_ErrorStatus = OK;
		return Local_ErrorStatus;
	}
	return Local_ErrorStatus;
}

extern error_status RCC_CrystalOscillatorInit(u32 Copy_u32OscillatorSource, u32 Copy_u32CrystalValue){
	u32 SYSCTL_RCC_temp;
	error_status Local_ErrorStatus = NOT_OK;
	SYSCTL_RCC |= SYSCTL_RCC_BYPASS;
	SYSCTL_RCC_temp = SYSCTL_RCC;
	SYSCTL_RCC_temp &= ~(SYSCTL_RCC_OSCSRC_M);
	SYSCTL_RCC_temp |= Copy_u32OscillatorSource;
	SYSCTL_RCC_temp &= ~(SYSCTL_RCC_XTAL_M);
	SYSCTL_RCC_temp |= Copy_u32CrystalValue;
	SYSCTL_RCC = SYSCTL_RCC_temp;
	
	if( ((SYSCTL_RCC & SYSCTL_RCC_XTAL_M) == Copy_u32CrystalValue) && ((SYSCTL_RCC & SYSCTL_RCC_OSCSRC_M) == Copy_u32OscillatorSource) ){
		Local_ErrorStatus = OK;
		return Local_ErrorStatus;
	}
	return Local_ErrorStatus;

}

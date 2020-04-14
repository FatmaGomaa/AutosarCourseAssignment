/*******************************************************************************************************
 * File name: Timer0.c                   	                                                            *
 *                                                                                                      *
 *                                                                                                      *
 * Description: This file contains the implementation of Timer 0						  		  	    *
 *                                                                                                      *
 * Author: Fatima Gomaa	                                                            			   	    *
 * Date:   April 7, 2020                                                                                *
 * Version 1.0 : Initial Creation 					                                                    *
 *******************************************************************************************************/
#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

error_status TIMER0_Init(void);
error_status TIMER0_SetTimeus(u32 Time_us);
error_status TIMER0_SetCallBack(void(*Copy_CallBackPtr)(void));

#endif

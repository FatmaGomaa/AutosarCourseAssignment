/*******************************************************************************************************
 * File name: BIT_MATH.h                                                                               *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the implementation of the BIT Math file 							   *
 *                                                                                                     *
 * Author: Basma AbdelHakim                                                            				   *
 * Date:   April 3, 2020                                                                               *
 * Version 1.0 : Initial Creation 					                                                   *
 *******************************************************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT_NO)	(VAR|=(1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO)	(VAR&=(~(1<<BIT_NO)))
#define TOG_BIT(VAR,BIT_NO)	(VAR^=(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO)	((VAR>>BIT_NO)&0x01)

#endif
/*******************************************************************************************************
 * File name: STD_TYPES.h                                                                              *
 *                                                                                                     *
 *                                                                                                     *
 * Description: This file contains the implementation of the STD Types library 						   *
 *                                                                                                     *
 * Author: Fatima Gomaa	                                                            				   *
 * Date:   April 3, 2020                                                                               *
 * Version 1.0 : Initial Creation 					                                                   *
 *******************************************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*Types*/
/*Unsigned*/
typedef unsigned	char u8;
typedef unsigned	short int u16;
typedef unsigned	long int u32;
/*Signed*/
typedef signed	char s8;
typedef signed	short int s16;
typedef signed	long int s32;
/*Float*/
typedef float f32;
typedef double f64;
typedef long double f96;

/*Pointers*/
/*Unsigned*/
typedef u8*  Pu8;
typedef u16* Pu16;
typedef u32* Pu32;
/*Signed*/
typedef s8*	 Ps8;
typedef s16* Ps16;
typedef s32* Ps32;
/*Float*/
typedef f32* Pf32;
typedef f64* Pf64;
typedef f96* P96;

/*Error*/
typedef u8 error_status;
#define	E_OK	0
#define	E_NOK	1

#endif

/*****************************************************************/
/* Author    : Ahmed Assaf                                       */
/* Date      : 9 March 2020                                      */
/* Version   : V01                                               */
/*****************************************************************/
#ifndef _UART_CONFIG_H
#define _UART_CONFIG_H


/* Options: UART_PARITY_DISABLED
            UART_PARITY_EVEN
			UART_PARITY_ODD      */
#define UART_u8_PARTIY     UART_PARITY_DISABLED

/* Options: UART_BUAD_4800
            UART_BUAD_9600
			UART_BUAD_115200 */
#define UART_u8_BUAD_RATE  UART_BUAD_9600

/* Options: UART_STOP_1_BIT
            UART_STOP_2_BIT  */
#define UART_u8_STOP_BITS  UART_STOP_1_BIT

/* Options: UART_SYS_FREQ_8M
            UART_SYS_FREQ_12M
			UART_SYS_FREQ_16M */
#define UART_u8_SYS_FREQ   UART_SYS_FREQ_8M


#define UART_u32_TIME_OUT_TH   10000UL

#endif

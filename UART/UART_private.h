/*****************************************************************/
/* Author    : Ahmed Assaf                                       */
/* Date      : 9 March 2020                                      */
/* Version   : V01                                               */
/*****************************************************************/
#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H

#define UART_PARITY_DISABLED    0U
#define UART_PARITY_EVEN        2U
#define UART_PARITY_ODD         3U

#define UART_BUAD_4800          0U  
#define UART_BUAD_9600          1U
#define UART_BUAD_115200        2U

#define UART_STOP_1_BIT         0U
#define UART_STOP_2_BIT         1U

#define UART_SYS_FREQ_8M        0U
#define UART_SYS_FREQ_12M       1U
#define UART_SYS_FREQ_16M       2U

#define UCSRB_TXCIE 			6U
#define UCSRB_RXCIE 			7U

#endif

#define SYSCTL_RCC              *(volatile u32*)0x400FE060  // Run-Mode Clock Configuration

#define SYSCTL_RCC_BYPASS       0x00000800  // PLL Bypass
#define SYSCTL_RCC_XTAL_M       0x000007C0  // Crystal Value
#define SYSCTL_RCC_XTAL_4MHZ    0x00000180  // 4 MHz
#define SYSCTL_RCC_XTAL_4_09MHZ 0x000001C0  // 4.096 MHz
#define SYSCTL_RCC_XTAL_4_91MHZ 0x00000200  // 4.9152 MHz
#define SYSCTL_RCC_XTAL_5MHZ    0x00000240  // 5 MHz
#define SYSCTL_RCC_XTAL_5_12MHZ 0x00000280  // 5.12 MHz
#define SYSCTL_RCC_XTAL_6MHZ    0x000002C0  // 6 MHz
#define SYSCTL_RCC_XTAL_6_14MHZ 0x00000300  // 6.144 MHz
#define SYSCTL_RCC_XTAL_7_37MHZ 0x00000340  // 7.3728 MHz
#define SYSCTL_RCC_XTAL_8MHZ    0x00000380  // 8 MHz
#define SYSCTL_RCC_XTAL_8_19MHZ 0x000003C0  // 8.192 MHz
#define SYSCTL_RCC_XTAL_10MHZ   0x00000400  // 10 MHz
#define SYSCTL_RCC_XTAL_12MHZ   0x00000440  // 12 MHz
#define SYSCTL_RCC_XTAL_12_2MHZ 0x00000480  // 12.288 MHz
#define SYSCTL_RCC_XTAL_13_5MHZ 0x000004C0  // 13.56 MHz
#define SYSCTL_RCC_XTAL_14_3MHZ 0x00000500  // 14.31818 MHz
#define SYSCTL_RCC_XTAL_16MHZ   0x00000540  // 16 MHz
#define SYSCTL_RCC_XTAL_16_3MHZ 0x00000580  // 16.384 MHz
#define SYSCTL_RCC_XTAL_18MHZ   0x000005C0  // 18.0 MHz (USB)
#define SYSCTL_RCC_XTAL_20MHZ   0x00000600  // 20.0 MHz (USB)
#define SYSCTL_RCC_XTAL_24MHZ   0x00000640  // 24.0 MHz (USB)
#define SYSCTL_RCC_XTAL_25MHZ   0x00000680  // 25.0 MHz (USB)
#define SYSCTL_RCC_OSCSRC_M     0x00000030  // Oscillator Source
#define SYSCTL_RCC_OSCSRC_MAIN  0x00000000  // MOSC
#define SYSCTL_RCC_OSCSRC_INT   0x00000010  // IOSC
#define SYSCTL_RCC_OSCSRC_INT4  0x00000020  // IOSC/4
#define SYSCTL_RCC_OSCSRC_30    0x00000030  // LFIOSC

#define SYSCTL_RCGCGPIO         *(volatile u32*)0x400FE608  // General-Purpose Input/Output Run
                                            // Mode Clock Gating Control
/*Peripherals clock masks*/
#define SYSCTL_RCGCGPIO_R5      0x00000020  // GPIO Port F Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R4      0x00000010  // GPIO Port E Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R3      0x00000008  // GPIO Port D Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R2      0x00000004  // GPIO Port C Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R1      0x00000002  // GPIO Port B Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCGPIO_R0      0x00000001  // GPIO Port A Run Mode Clock
                                            // Gating Control
											
/* Enables a peripheral.                                                               */
/*                                                                                     */
/* \param Copy_u32GPIO_Peripheral is the peripheral to enable.                         */
/* The Copy_u32GPIO_Peripheral parameter must be only one of the following values:     */
/*SYSCTL_RCGCGPIO_R5  for GPIO Port F Run Mode Clock                                   */
/*SYSCTL_RCGCGPIO_R4  for GPIO Port E Run Mode Clock                                   */
/*SYSCTL_RCGCGPIO_R3  for GPIO Port D Run Mode Clock                                   */
/*SYSCTL_RCGCGPIO_R2  for GPIO Port C Run Mode Clock                                   */
/*SYSCTL_RCGCGPIO_R1  for GPIO Port B Run Mode Clock                                   */
/*SYSCTL_RCGCGPIO_R0  for GPIO Port A Run Mode Clock                                   */
/* This function enables a peripheral.  At power-up, all peripherals are               */
/* disabled; they must be enabled in order to operate or respond to register           */
/* reads/writes.                                                                       */
/*	and it returns a std error whether this peripheral clock was enabled or not        */
extern ERROR_STATUS RCGCGPIO_EnablePeripheralClock(u32 Copy_u32GPIO_Peripheral);

											
/* Enables a peripheral.                                                               */
/*                                                                                     */
/* \param Copy_u32GPIO_Peripheral is the peripheral to disable.                        */
/* The Copy_u32GPIO_Peripheral parameter must be only one of the following values:     */
/*SYSCTL_RCGCGPIO_R5  for GPIO Port F Run Mode Clock                                   */
/*SYSCTL_RCGCGPIO_R4  for GPIO Port E Run Mode Clock                                   */
/*SYSCTL_RCGCGPIO_R3  for GPIO Port D Run Mode Clock                                   */
/*SYSCTL_RCGCGPIO_R2  for GPIO Port C Run Mode Clock                                   */
/*SYSCTL_RCGCGPIO_R1  for GPIO Port B Run Mode Clock                                   */
/*SYSCTL_RCGCGPIO_R0  for GPIO Port A Run Mode Clock                                   */
/*	and it returns a std error whether this peripheral clock was disabled or not       */
extern ERROR_STATUS RCGCGPIO_DisablePeripheralClock(u32 Copy_u32GPIO_Peripheral);

/*Configure the external clock source and value                                        */
/*param Copy_u32OscillatorSource is the oscillator source.                             */
/*The Copy_u32OscillatorSource parameter must be only one of the following values:     */
/*SYSCTL_RCC_OSCSRC_MAIN                                                               */
/*SYSCTL_RCC_OSCSRC_INT                                                                */
/*SYSCTL_RCC_OSCSRC_INT4                                                               */
/*SYSCTL_RCC_OSCSRC_30                                                                 */
/*                                                                                     */
/*param Copy_u32CrystalValue is the oscillator source.                                 */
/*The Copy_u32CrystalValue parameter must be only one of the following values:         */
/*SYSCTL_RCC_XTAL_4MHZ                                                                 */
/*SYSCTL_RCC_XTAL_4_09MHZ                                                              */
/*SYSCTL_RCC_XTAL_4_91MHZ                                                              */
/*SYSCTL_RCC_XTAL_5MHZ                                                                 */
/*SYSCTL_RCC_XTAL_5_12MHZ                                                              */
/*SYSCTL_RCC_XTAL_6MHZ                                                                 */
/*SYSCTL_RCC_XTAL_6_14MHZ                                                              */
/*SYSCTL_RCC_XTAL_7_37MHZ                                                              */
/*SYSCTL_RCC_XTAL_8MHZ                                                                 */
/*SYSCTL_RCC_XTAL_8_19MHZ                                                              */
/*SYSCTL_RCC_XTAL_10MHZ                                                                */
/*SYSCTL_RCC_XTAL_12MHZ                                                                */
/*SYSCTL_RCC_XTAL_12_2MHZ                                                              */
/*SYSCTL_RCC_XTAL_13_5MHZ                                                              */
/*SYSCTL_RCC_XTAL_14_3MHZ                                                              */
/*SYSCTL_RCC_XTAL_16MHZ                                                                */
/*SYSCTL_RCC_XTAL_16_3MHZ                                                              */
/*SYSCTL_RCC_XTAL_18MHZ                                                                */
/*SYSCTL_RCC_XTAL_20MHZ                                                                */
/*SYSCTL_RCC_XTAL_24MHZ                                                                */
/*SYSCTL_RCC_XTAL_25MHZ                                                                */

extern ERROR_STATUS RCC_CrystalOscillatorInit(u32 Copy_u32OscillatorSource, u32 Copy_u32CrystalValue);

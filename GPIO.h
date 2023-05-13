/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *               -this Driver is customized for the use of the project(not fully developed)
 *               -the Driver doesn't allow to commit to pins P0-P3 to prevent disabling the JTAG
 *               -the driver allow to use AHB or APB
 *
 * Author: Ahmed Hamed
 ******************************************************************************/
/*
 *   Author: Ahmed Hamed
 *   File Name: GPIO.h
 *   Description:-This is a header for the GPIO driver
 *               -this Driver is customized for the use of the project(not fully developed)
 *               -the Driver doesn't allow to commit to pins P0-P3 to prevent disabling the JTAG
 *               -the driver allow to use AHB or APB
 *               -
 */
#ifndef GPIO_H_
#define GPIO_H_
#include "std_types.h"


/*STATIC CONFIGURATION*/
#define GPIOA_BUS                AH
#define GPIOB_BUS                AH
#define GPIOC_BUS                AB
#define GPIOD_BUS                AH
#define GPIOE_BUS                AH
#define GPIOF_BUS                AH

#define GPIO_PORTA_APB_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_APB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_APB_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_APB_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_APB_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_APB_BASE_ADDRESS           0x40025000

#define GPIO_PORTA_AHB_BASE_ADDRESS           0x40058000
#define GPIO_PORTB_AHB_BASE_ADDRESS           0x40059000
#define GPIO_PORTC_AHB_BASE_ADDRESS           0x4005A000
#define GPIO_PORTD_AHB_BASE_ADDRESS           0x4005B000
#define GPIO_PORTE_AHB_BASE_ADDRESS           0x4005C000
#define GPIO_PORTF_AHB_BASE_ADDRESS           0x4005D000

#define NUM_OF_PORTS            6
#define NUM_OF_PINS_PER_PORTA   8
#define NUM_OF_PINS_PER_PORTB   8
#define NUM_OF_PINS_PER_PORTC   8
#define NUM_OF_PINS_PER_PORTD   8
#define NUM_OF_PINS_PER_PORTE   6
#define NUM_OF_PINS_PER_PORTF   5

/*USED MASKS AND DEFINETIONS AND ENUMs*/
#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3
#define PORTE_ID               4
#define PORTF_ID               5

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7



/* Symbolic names for MCU Pin Modes */
/* Default DIO MODE */
#define PIN_DEFAULT_DIO_MODE    (0U)
/*****************************************PORTA*****************************************/
#define PORT_A_PIN_0_U0RX_MODE  (1U)
#define PORT_A_PIN_0_CAN1RX_MODE  (8U)

#define PORT_A_PIN_1_U0TX_MODE  (1U)
#define PORT_A_PIN_1_CCAN1TX_MODE  (8U)

#define PORT_A_PIN_2_SSI0CLK_MODE  (2U)

#define PORT_A_PIN_3_SSI0FSS_MODE  (2U)

#define PORT_A_PIN_4_SSI0RX_MODE  (2U)

#define PORT_A_PIN_5_SSI0TX_MODE  (2U)

#define PORT_A_PIN_6_I2C1SCL_MODE  (3U)
#define PORT_A_PIN_6_M1PWM2_MODE  (5U)

#define PORT_A_PIN_7_I2C1SDA_MODE  (3U)
#define PORT_A_PIN_7_M1PWM3_MODE  (5U)
/*****************************************PORTB*****************************************/
#define PORT_B_PIN_0_U1RX_MODE  (1U)
#define PORT_B_PIN_0_T2CCP0_MODE  (7U)

#define PORT_B_PIN_1_U1TX_MODE  (1U)
#define PORT_B_PIN_1_T2CCP1_MODE  (7U)

#define PORT_B_PIN_2_I2C0SCL_MODE  (3U)
#define PORT_B_PIN_2_T3CCP0_MODE  (7U)

#define PORT_B_PIN_3_I2C0SDA_MODE  (3U)
#define PORT_B_PIN_3_T3CCP1_MODE  (7U)

#define PORT_B_PIN_4_SSI2CLK_MODE  (2U)
#define PORT_B_PIN_4_M0PWM2_MODE  (4U)
#define PORT_B_PIN_4_T1CCP0_MODE  (7U)
#define PORT_B_PIN_4_CAN0R_MODE  (8U)

#define PORT_B_PIN_5_SSI2FSS_MODE  (2U)
#define PORT_B_PIN_5_M0PWM3_MODE  (4U)
#define PORT_B_PIN_5_T1CCP1_MODE  (7U)
#define PORT_B_PIN_5_CAN0TX_MODE  (8U)

#define PORT_B_PIN_6_SSI2RX_MODE  (2U)
#define PORT_B_PIN_6_M0PWM0_MODE  (4U)
#define PORT_B_PIN_6_T0CCP0_MODE  (7U)

#define PORT_B_PIN_7_SSI2TX_MODE  (2U)
#define PORT_B_PIN_7_M0PWM1_MODE  (4U)
#define PORT_B_PIN_7_T0CCP1_MODE  (7U)
/*****************************************PORTC*****************************************/
#define PORT_C_PIN_0_TCKSWCLK_MODE  (1U)
#define PORT_C_PIN_0_T4CCP0_MODE  (7U)

#define PORT_C_PIN_1_TMSSWDIO_MODE  (1U)
#define PORT_C_PIN_1_T4CCP1_MODE  (7U)

#define PORT_C_PIN_2_TDI_MODE  (1U)
#define PORT_C_PIN_2_T5CCP0_MODE  (7U)

#define PORT_C_PIN_2_TDOSWO_MODE  (1U)
#define PORT_C_PIN_2_T5CCP1_MODE  (7U)

#define PORT_C_PIN_4_U4RX_MODE  (1U)
#define PORT_C_PIN_4_U1RX_MODE  (2U)
#define PORT_C_PIN_4_M0PWM6_MODE  (4U)
#define PORT_C_PIN_4_IDX1_MODE  (6U)
#define PORT_C_PIN_4_WT0CCP0_MODE  (7U)
#define PORT_C_PIN_4_U1RTS_MODE  (8U)

#define PORT_C_PIN_5_U4TX_MODE  (1U)
#define PORT_C_PIN_5_U1X_MODE  (2U)
#define PORT_C_PIN_5_M0PWM7_MODE  (4U)
#define PORT_C_PIN_5_PHA1_MODE  (6U)
#define PORT_C_PIN_5_WT0CCP1_MODE  (7U)
#define PORT_C_PIN_5_U1CTS_MODE  (8U)

#define PORT_C_PIN_6_U3RX_MODE  (1U)
#define PORT_C_PIN_6_PHB1_MODE  (6U)
#define PORT_C_PIN_6_WT1CCP0_MODE  (7U)
#define PORT_C_PIN_6_USB0EPEN_MODE  (8U)

#define PORT_C_PIN_7_U3TX_MODE  (1U)
#define PORT_C_PIN_7_WT1CCP1_MODE  (7U)
#define PORT_C_PIN_7_USB0PFLT_MODE  (8U)
/*****************************************PORTD*****************************************/
#define PORT_D_PIN_0_SSI3CLK_MODE  (1U)
#define PORT_D_PIN_0_SSI1CLK_MODE  (2U)
#define PORT_D_PIN_0_I2C3SCL_MODE  (3U)
#define PORT_D_PIN_0_M0PWM6_MODE  (4U)
#define PORT_D_PIN_0_M1PWM0_MODE  (5U)
#define PORT_D_PIN_0_WT2CCP0_MODE  (7U)

#define PORT_D_PIN_1_SSI3FSS_MODE  (1U)
#define PORT_D_PIN_1_SSI1FSS_MODE  (2U)
#define PORT_D_PIN_1_I2C3SDA_MODE  (3U)
#define PORT_D_PIN_1_M0PWM7_MODE  (4U)
#define PORT_D_PIN_1_M1PWM1_MODE  (5U)
#define PORT_D_PIN_1_WT2CCP1_MODE  (7U)

#define PORT_D_PIN_2_SSI3RX_MODE  (1U)
#define PORT_D_PIN_2_SSI1RX_MODE  (2U)
#define PORT_D_PIN_2_M0FAULT0_MODE  (4U)
#define PORT_D_PIN_2_WT3CCP0_MODE  (7U)
#define PORT_D_PIN_2_USB0EPEN_MODE  (8U)

#define PORT_D_PIN_3_SSI3TX_MODE  (1U)
#define PORT_D_PIN_3_SSI1TX_MODE  (2U)
#define PORT_D_PIN_3_IDX0_MODE  (6U)
#define PORT_D_PIN_3_WT3CCP1_MODE  (7U)
#define PORT_D_PIN_3_USB0PFLT_MODE  (8U)

#define PORT_D_PIN_4_U6RX_MODE  (1U)
#define PORT_D_PIN_4_WT4CCP0_MODE  (7U)

#define PORT_D_PIN_5_U6TX_MODE  (1U)
#define PORT_D_PIN_5_WT4CCP1_MODE  (7U)

#define PORT_D_PIN_6_U2RX_MODE  (1U)
#define PORT_D_PIN_6_M0FAULT0_MODE  (4U)
#define PORT_D_PIN_6_PHA0_MODE  (6U)
#define PORT_D_PIN_6_WT5CCP0_MODE  (7U)

#define PORT_D_PIN_7_U2TX_MODE  (1U)
#define PORT_D_PIN_7_PHB0_MODE  (6U)
#define PORT_D_PIN_7_WT5CCP1_MODE  (7U)
#define PORT_D_PIN_7_NMI_MODE  (8U)
/*****************************************PORTE*****************************************/
#define PORT_E_PIN_0_U7RX_MODE  (1U)

#define PORT_E_PIN_1_U7TX_MODE  (1U)

#define PORT_E_PIN_4_U5RX_MODE  (1U)
#define PORT_E_PIN_4_I2C2SCL_MODE  (3U)
#define PORT_E_PIN_4_M0PWM4_MODE  (4U)
#define PORT_E_PIN_4_M1PWM2_MODE  (5U)
#define PORT_E_PIN_4_CAN0RX_MODE  (8U)

#define PORT_E_PIN_5_U5TX_MODE  (1U)
#define PORT_E_PIN_5_I2C2SDA_MODE  (3U)
#define PORT_E_PIN_5_M0PWM5_MODE  (4U)
#define PORT_E_PIN_5_M1PWM3_MODE  (5U)
#define PORT_E_PIN_5_CAN0TX_MODE  (8U)
/*****************************************PORTF*****************************************/
#define PORT_F_PIN_0_U1RTS_MODE  (1U)
#define PORT_F_PIN_0_SSI1RX_MODE  (2U)
#define PORT_F_PIN_0_CAN0RX_MODE  (3U)
#define PORT_F_PIN_0_M1PWM4_MODE  (5U)
#define PORT_F_PIN_0_PHA0_MODE  (6U)
#define PORT_F_PIN_0_T0CCP0_MODE  (7U)
#define PORT_F_PIN_0_NMI_MODE  (8U)
#define PORT_F_PIN_0_C0O_MODE  (9U)

#define PORT_F_PIN_1_U1CTS_MODE  (1U)
#define PORT_F_PIN_1_SSI1TX_MODE  (2U)
#define PORT_F_PIN_1_M1PWM5_MODE  (5U)
#define PORT_F_PIN_1_PHB0_MODE  (6U)
#define PORT_F_PIN_1_T0CCP1_MODE  (7U)
#define PORT_F_PIN_1_C1O_MODE  (9U)
#define PORT_F_PIN_1_TRD1_MODE  (14U)

#define PORT_F_PIN_2_SSI1Clk_MODE  (2U)
#define PORT_F_PIN_2_M0FAULT0_MODE  (4U)
#define PORT_F_PIN_2_M1PWM6_MODE  (5U)
#define PORT_F_PIN_2_T1CCP0_MODE  (7U)
#define PORT_F_PIN_2_TRD0_MODE  (14U)

#define PORT_F_PIN_3_SSI1FSS_MODE  (2U)
#define PORT_F_PIN_3_CAN0TX_MODE  (3U)
#define PORT_F_PIN_3_M1PWM7_MODE  (5U)
#define PORT_F_PIN_3_T1CCP1_MODE  (7U)
#define PORT_F_PIN_3_TRCLK_MODE  (14U)

#define PORT_F_PIN_4_M1FAULT0_MODE  (5U)
#define PORT_F_PIN_4_IDX0_MODE  (6U)
#define PORT_F_PIN_4_T2CCP0_MODE  (7U)
#define PORT_F_PIN_4_USB0EPEN_MODE  (8U)


typedef enum
{
    INPUT,OUTPUT
}PinDirection;

typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}InternalResistor;

typedef uint8 PinMode;

typedef enum
{
    Analog,Digital
}PinModeType;
/*FUNCTIONS PROTOTYPES AND DOCUMENTATION*/

/*
 *   Definition: This function is used to enable a port clock
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: the port to be enabled
 */
static void GPIO_EnablePortClock(uint8 port_ID);

/*
 *   Definition: This function is used to configure a pin with the given function
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID : Port unique number (0-5)
 *           @pin_ID : Port PIN no. (0-7)
 *           @direction : Pin data direction (INPUT ,OUTPUT)
 *           @resistor : Internal resistor type (OFF,PULL_UP,PULL_DOWN)
 *           @pin_mode : Pin mode and Alternative function (Pre-defined symbolic name)
 *           @mode_type : Pin mode type (Analog,Digital)
 *           @pin_level_init_value : initial value (STD_HIGH ,STD_LOW )
 */
void GPIO_SetPinFunc(uint8 port_ID, uint8 pin_ID, PinDirection direction,InternalResistor resistor,
                     PinMode pin_mode, PinModeType mode_type,uint8 pin_level_init_value);

/*
 *   Definition: This function is used to initialize a digital port
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID : Port unique number (0-5)
 *           @direction : Pin data direction (INPUT ,OUTPUT)
 *           @resistor : Internal resistor type (OFF,PULL_UP,PULL_DOWN)
 *           @port_level_init_value : initial value for all pins at port (STD_HIGH ,STD_LOW )
 *   Notes: this function configure all the port to digital i/o
 */
void GPIO_SetPortDir(uint8 port_ID, PinDirection direction,InternalResistor resistor
                     ,uint8 port_level_init_value);

/*
 *   Definition: This function is used to initialize a digital pin
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID : Port unique number (0-5)
 *           @pin_ID : Port PIN no. (0-7)
 *           @direction : Pin data direction (INPUT ,OUTPUT)
 *           @resistor : Internal resistor type (OFF,PULL_UP,PULL_DOWN)
 *           @pin_level_init_value : initial value (STD_HIGH ,STD_LOW )
 */
void GPIO_SetPinDir(uint8 port_ID, uint8 pin_ID, PinDirection direction,InternalResistor resistor
                    ,uint8 pin_level_init_value);

/*
 *   Definition: This function is used to write data to an entire port
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: the ID of the port
 *           @data: the data to be written on the port
 */
void GPIO_WritePort(uint8 port_ID, uint8 data);

/*
 *   Definition: This function is used to read an entire port
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: the ID of the port to read from
 */
uint8 GPIO_ReadPort(uint8 port_ID);

/*
 *   Definition: This function is used to write on a specific pin
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: the ID of the pin port
 *           @pin_ID: the ID of the pin to write on
 *           @data: the data to be written on the pin
 */
void GPIO_WritePin(uint8 port_ID, uint8 pin_ID, uint8 data);

/*
 *   Definition: This function is used to toggle s specific pin
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: the ID of the pin port
 *           @pin_ID: the ID of the pin to toggle
 */
void GPIO_TogglePin(uint8 port_ID, uint8 pin_ID);

/*
 *   Definition: This function is used to read a specific pin
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: this is the row to write on
 *           @pin_ID: this is the column to write on
 */
uint8 GPIO_ReadPin(uint8 port_ID, uint8 pin_ID);

#endif /* GPIO_H_ */

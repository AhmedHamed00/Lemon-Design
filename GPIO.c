/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Ahmed Hamed
 ******************************************************************************/

#include "GPIO.h"
#include "common_macros.h"
#include "TM4C123GH6PM.h"

static GPIOA_Type* PORTS[]=
{
#if (GPIOA_BUS==AHB)
 (GPIOA_Type*)GPIO_PORTA_AHB_BASE_ADDRESS,
#elif
 (GPIOA_Type*)GPIO_PORTA_APB_BASE_ADDRESS,
#endif
#if (GPIOB_BUS==AHB)
 (GPIOA_Type*)GPIO_PORTB_AHB_BASE_ADDRESS,
#elif
 (GPIOA_Type*)GPIO_PORTB_APB_BASE_ADDRESS,
#endif
#if (GPIOC_BUS==AHB)
 (GPIOA_Type*)GPIO_PORTC_AHB_BASE_ADDRESS,
#elif
 (GPIOA_Type*)GPIO_PORTC_APB_BASE_ADDRESS,
#endif
#if (GPIOD_BUS==AHB)
 (GPIOA_Type*)GPIO_PORTD_AHB_BASE_ADDRESS,
#elif
 (GPIOA_Type*)GPIO_PORTD_APB_BASE_ADDRESS,
#endif
#if (GPIOE_BUS==AHB)
 (GPIOA_Type*)GPIO_PORTE_AHB_BASE_ADDRESS,
#elif
 (GPIOA_Type*)GPIO_PORTE_APB_BASE_ADDRESS,
#endif
#if (GPIOF_BUS==AHB)
 (GPIOA_Type*)GPIO_PORTF_AHB_BASE_ADDRESS
#elif
 (GPIOA_Type*)GPIO_PORTF_APB_BASE_ADDRESS
#endif
};





/*FUNCTIONS DEFINITIONS*/

/*
 *   Definition: This function is used to enable a port clock
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: the port to be enabled
 */
static void GPIO_EnablePortClock(uint8 port_ID)
{
    switch(port_ID)
    {
    case PORTA_ID:
#if(GPIOA_BUS==AHB)
        SET_BIT(SYSCTL->GPIOHBCTL, port_ID);
#endif
        break;
    case PORTB_ID:
#if(GPIOB_BUS == AHB)
        SET_BIT(SYSCTL->GPIOHBCTL, port_ID);
#endif
        break;
    case PORTC_ID:
#if(GPIOC_BUS == AHB)
        SET_BIT(SYSCTL->GPIOHBCTL, port_ID);
#endif
        break;
    case PORTD_ID:
#if(GPIOD_BUS == AHB)
        SET_BIT(SYSCTL->GPIOHBCTL, port_ID);
#endif
        break;
    case PORTE_ID:
#if(GPIOE_BUS == AHB)
        SET_BIT(SYSCTL->GPIOHBCTL, port_ID);
#endif
        break;
    case PORTF_ID:
#if(GPIOF_BUS == AHB)
        SET_BIT(SYSCTL->GPIOHBCTL, port_ID);
#endif
        break;
    default:
        break;
    }
    SET_BIT(SYSCTL->RCGCGPIO, port_ID);
    port_ID = 0;
}

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
                     PinMode pin_mode, PinModeType mode_type,uint8 pin_level_init_value)
{
    if ((port_ID > NUM_OF_PORTS)
            | (pin_ID > NUM_OF_PINS_PER_PORTA && port_ID == PORTA_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTB && port_ID == PORTB_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTC && port_ID == PORTC_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTD && port_ID == PORTD_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTE && port_ID == PORTE_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTF && port_ID == PORTF_ID)) //check that port and pin ID are valid
    {
        while (1)
        {
        } //Halt the program

    }
    else
    {
        GPIO_EnablePortClock(port_ID);
        GPIOA_Type* GPIO_PTR=PORTS[port_ID];
        if( ((port_ID == PORTD_ID) && (pin_ID == PIN7_ID))
                || ((port_ID == PORTF_ID) && (pin_ID == PIN0_ID)) )
        {
            GPIO_PTR->LOCK = 0x4C4F434B; /*unlock port */
            SET_BIT(GPIO_PTR->CR , pin_ID); /*commit to values*/
        }
        else if((port_ID == PORTC_ID)&&((pin_ID == PIN0_ID)||(pin_ID == PIN1_ID)||(pin_ID == PIN2_ID)||(pin_ID == PIN3_ID)))
        {
            /* Halt if the JTAG pins are selected to protect them*/
        }
        else
        {
            /* do nothing if other pins are selected as the are not locked */
        }

        PLACE_VAL(GPIO_PTR->DIR , pin_ID, direction);/*Configure direction in case Dio*/

        if(PIN_DEFAULT_DIO_MODE == pin_mode)
        {
            CLEAR_BIT(GPIO_PTR->AFSEL , pin_ID);/*Disable alternative function*/
        }
        else
        {
            SET_BIT(GPIO_PTR->AFSEL , pin_ID); /*Enable alternative function*/
        }
        GPIO_PTR->PCTL |= (pin_mode << ((pin_ID) * 4)); /*Alternative function configuration*/
        if(OFF == resistor)
        {
            /*Disable both Pull-up and Pull-dwn*/
            CLEAR_BIT(GPIO_PTR->PUR , pin_ID);
            CLEAR_BIT(GPIO_PTR->PDR , pin_ID);
        }
        else if(PULL_UP == resistor)
        {
            /*Disable Pull-dwn and Enable Pull-up */
            SET_BIT(GPIO_PTR->PUR , pin_ID);
            CLEAR_BIT(GPIO_PTR->PDR , pin_ID);
        }
        else
        {
            /*Disable Pull-up and Enable Pull-dwn */
            SET_BIT(GPIO_PTR->PDR , pin_ID);
            CLEAR_BIT(GPIO_PTR->PUR , pin_ID);
        }
        PLACE_VAL(GPIO_PTR->AMSEL , pin_ID , (mode_type^1)); /*Configure analog if mode type is analog */
        PLACE_VAL(GPIO_PTR->DEN, pin_ID , mode_type); /*Configure digital if mode type is digital */

        PLACE_VAL(GPIO_PTR->DATA , pin_ID , pin_level_init_value);/*Configure initial value in case Dio*/

    }
}

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
                     ,uint8 port_level_init_value)
{
    if (port_ID > NUM_OF_PORTS)
    {
        while (1)
        {
        } /*Halt the program*/

    }
    else
    {
        GPIO_EnablePortClock(port_ID);
        GPIOA_Type* GPIO_PTR=PORTS[port_ID];
        if((port_ID == PORTD_ID)
                || (port_ID == PORTF_ID)  )
        {
            GPIO_PTR->LOCK = 0x4C4F434B; /*unlock port */
            SET_REG(GPIO_PTR->CR); /*commit to values*/
        }
        else if(port_ID == PORTC_ID)
        {
            /* Halt if the JTAG pins are selected to protect them*/
        }
        else
        {
            /* do nothing if other pins are selected as the are not locked */
        }
        PLACE_PORT_VAL(GPIO_PTR->DIR, direction); /*set direction*/
        CLEAR_FIRST_8(GPIO_PTR->AFSEL); /*Disable alternative function*/
        CLEAR_REG(GPIO_PTR->PCTL); /*enable gpio*/
        if(OFF == resistor)
        {
            /*Disable both Pull-up and Pull-dwn*/
            CLEAR_REG(GPIO_PTR->PUR);
            CLEAR_REG(GPIO_PTR->PDR);
        }
        else if(PULL_UP == resistor)
        {
            /*Disable Pull-dwn and Enable Pull-up */
            SET_REG(GPIO_PTR->PUR);
            CLEAR_REG(GPIO_PTR->PDR);
        }
        else
        {
            /*Disable Pull-up and Enable Pull-dwn */
            SET_REG(GPIO_PTR->PDR);
            CLEAR_REG(GPIO_PTR->PUR);
        }
        CLEAR_REG(GPIO_PTR->AMSEL); /*disable analog*/
        SET_REG(GPIO_PTR->DEN);/*enable digital*/
        PLACE_PORT_VAL(GPIO_PTR->DATA ,port_level_init_value);/*place initail value to all pins*/
    }
}

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
                    ,uint8 pin_level_init_value)
{

    GPIO_SetPinFunc(port_ID, pin_ID, direction, resistor, PIN_DEFAULT_DIO_MODE, Digital, pin_level_init_value);
}

/*
 *   Definition: This function is used to write data to an entire port
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: the ID of the port
 *           @data: the data to be written on the port
 */
void GPIO_WritePort(uint8 port_ID, uint8 data)
{
    if (port_ID > NUM_OF_PORTS)
    {
        while (1)
        {
        } /*Halt the program*/

    }
    else
    {
        GPIOA_Type* GPIO_PTR=PORTS[port_ID];
        GPIO_PTR->DATA = data;/*SET PORT VALUE*/
    }
}

/*
 *   Definition: This function is used to read an entire port
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: the ID of the port to read from
 */
uint8 GPIO_ReadPort(uint8 port_ID)
{
    if (port_ID > NUM_OF_PORTS)
    {
        while (1)
        {
        } /*Halt the program*/

    }
    else
    {
        GPIOA_Type* GPIO_PTR=PORTS[port_ID];
        return GPIO_PTR->DATA ;/*GET PORT VALUE*/
    }
}

/*
 *   Definition: This function is used to write on an specific pin
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: the ID of the pin port
 *           @pin_ID: the ID of the pin to write on
 *           @data: the data to be written on the pin
 */
void GPIO_WritePin(uint8 port_ID, uint8 pin_ID, uint8 data)
{
    if ((port_ID > NUM_OF_PORTS)
            | (pin_ID > NUM_OF_PINS_PER_PORTA && port_ID == PORTA_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTB && port_ID == PORTB_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTC && port_ID == PORTC_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTD && port_ID == PORTD_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTE && port_ID == PORTE_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTF && port_ID == PORTF_ID)) /*check that port and pin ID are valid*/
    {
        while (1)
        {
        } /*Halt the program*/

    }
    else
    {
        GPIOA_Type* GPIO_PTR=PORTS[port_ID];
        PLACE_VAL(GPIO_PTR->DATA, pin_ID, data); /*SET BIT VALUE*/
    }
}

/*
 *   Definition: This function is used to toggle s specific pin
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: the ID of the pin port
 *           @pin_ID: the ID of the pin to toggle
 */
void GPIO_TogglePin(uint8 port_ID, uint8 pin_ID)
{
    if ((port_ID > NUM_OF_PORTS)
                | (pin_ID > NUM_OF_PINS_PER_PORTA && port_ID == PORTA_ID)
                | (pin_ID > NUM_OF_PINS_PER_PORTB && port_ID == PORTB_ID)
                | (pin_ID > NUM_OF_PINS_PER_PORTC && port_ID == PORTC_ID)
                | (pin_ID > NUM_OF_PINS_PER_PORTD && port_ID == PORTD_ID)
                | (pin_ID > NUM_OF_PINS_PER_PORTE && port_ID == PORTE_ID)
                | (pin_ID > NUM_OF_PINS_PER_PORTF && port_ID == PORTF_ID)) /*check that port and pin ID are valid*/
        {
            while (1)
            {
            } /*Halt the program*/

        }
        else
        {
            GPIOA_Type* GPIO_PTR=PORTS[port_ID];
            TOGGLE_BIT(GPIO_PTR->DATA, pin_ID); /*SET BIT VALUE*/
        }
}


/*
 *   Definition: This function is used to read a specific pin
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @port_ID: this is the row to write on
 *           @pin_ID: this is the column to write on
 */
uint8 GPIO_ReadPin(uint8 port_ID, uint8 pin_ID)
{
    if ((port_ID > NUM_OF_PORTS)
            | (pin_ID > NUM_OF_PINS_PER_PORTA && port_ID == PORTA_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTB && port_ID == PORTB_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTC && port_ID == PORTC_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTD && port_ID == PORTD_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTE && port_ID == PORTE_ID)
            | (pin_ID > NUM_OF_PINS_PER_PORTF && port_ID == PORTF_ID)) /*check that port and pin ID are valid*/
    {
        while (1)
        {
        } /*Halt the program*/

    }
    else
    {
        GPIOA_Type* GPIO_PTR=PORTS[port_ID];
        return (uint8) GET_BIT(GPIO_PTR->DATA, pin_ID); /*GET BIT VALUE*/
    }
}

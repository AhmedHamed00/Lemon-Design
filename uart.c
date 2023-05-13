******************************************************************************
 *
 * Module: UART
/ *
 * File Name: UART.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - UART driver
 *
 * Author: Noha Adel
 ******************************************************************************/

#include "uart.h"
#include "GPIO.h"

UART0_Type * UART_STR_ARR[]=
{
 UART0,
 UART1,
 UART2,
 UART3,
 UART4,
 UART5,
 UART6,
 UART7
};

uint8 UART_STATUS_ARR[]=
{
 STD_IDLE,
 STD_IDLE,
 STD_IDLE,
 STD_IDLE,
 STD_IDLE,
 STD_IDLE,
 STD_IDLE,
 STD_IDLE
};



void UART_Init(const UART_ConfigType* Config_Ptr , uint8 UARTx_ID)
{
    UART_STATUS_ARR[UARTx_ID]=STD_ACTIVE;
    SET_BIT(SYSCTL->RCGCUART, UARTx_ID); //enable clk
    switch(UARTx_ID)
    {
    case UART0_ID:
        //PA 0-1
        GPIO_SetPinFunc(PORTA_ID, PIN0_ID, OUTPUT, OFF, PORT_A_PIN_0_U0RX_MODE, Digital, STD_LOW);
        GPIO_SetPinFunc(PORTA_ID, PIN1_ID, OUTPUT, OFF, PORT_A_PIN_1_U0TX_MODE, Digital, STD_LOW);
        break;
    case UART1_ID:
        //PB 0-1
        GPIO_SetPinFunc(PORTB_ID, PIN0_ID, OUTPUT, OFF, PORT_B_PIN_0_U1RX_MODE, Digital, STD_LOW);
        GPIO_SetPinFunc(PORTB_ID, PIN1_ID, OUTPUT, OFF, PORT_B_PIN_1_U1TX_MODE, Digital, STD_LOW);
        break;
    case UART2_ID:
        //PD 6-7
        GPIO_SetPinFunc(PORTD_ID, PIN6_ID, OUTPUT, OFF, PORT_D_PIN_6_U2RX_MODE, Digital, STD_LOW);
        GPIO_SetPinFunc(PORTD_ID, PIN7_ID, OUTPUT, OFF, PORT_D_PIN_7_U2TX_MODE, Digital, STD_LOW);
        break;
    case UART3_ID:
        //PC 6-7
        GPIO_SetPinFunc(PORTC_ID, PIN6_ID, OUTPUT, OFF, PORT_C_PIN_6_U3RX_MODE, Digital, STD_LOW);
        GPIO_SetPinFunc(PORTC_ID, PIN7_ID, OUTPUT, OFF, PORT_C_PIN_7_U3TX_MODE, Digital, STD_LOW);
        break;
    case UART4_ID:
        //PC 4-5
        GPIO_SetPinFunc(PORTC_ID, PIN4_ID, OUTPUT, OFF, PORT_C_PIN_4_U4RX_MODE, Digital, STD_LOW);
        GPIO_SetPinFunc(PORTC_ID, PIN5_ID, OUTPUT, OFF, PORT_C_PIN_5_U4TX_MODE, Digital, STD_LOW);
        break;
    case UART5_ID:
        //PE 4-5
        GPIO_SetPinFunc(PORTE_ID, PIN4_ID, OUTPUT, OFF, PORT_E_PIN_4_U5RX_MODE, Digital, STD_LOW);
        GPIO_SetPinFunc(PORTE_ID, PIN5_ID, OUTPUT, OFF, PORT_E_PIN_5_U5TX_MODE, Digital, STD_LOW);
        break;
    case UART6_ID:
        //PD 4-5
        GPIO_SetPinFunc(PORTD_ID, PIN4_ID, OUTPUT, OFF, PORT_D_PIN_4_U6RX_MODE, Digital, STD_LOW);
        GPIO_SetPinFunc(PORTD_ID, PIN5_ID, OUTPUT, OFF, PORT_D_PIN_5_U6TX_MODE, Digital, STD_LOW);
        break;
    case UART7_ID:
        //PE 0-1
        GPIO_SetPinFunc(PORTE_ID, PIN0_ID, OUTPUT, OFF, PORT_E_PIN_0_U7RX_MODE, Digital, STD_LOW);
        GPIO_SetPinFunc(PORTE_ID, PIN1_ID, OUTPUT, OFF, PORT_E_PIN_1_U7TX_MODE, Digital, STD_LOW);
        break;
    default:
        break;
    }
    GPIO_SetPinFunc(1, 0, OUTPUT, OFF, 1, Digital, 0);
    GPIO_SetPinFunc(1, 1, OUTPUT, OFF, 1, Digital, 0);

    UART0_Type * General_UART=UART_STR_ARR[UARTx_ID];
    CLEAR_BIT(General_UART->CTL,0 ); //disable uart first

    General_UART->IBRD=Config_Ptr->IBRD;//integer part of the divisor
    General_UART->FBRD=Config_Ptr->FBRD;//fractional part of the divisor
    General_UART->LCRH |= ((Config_Ptr->Parity) <<1);//set parity bit
    General_UART->LCRH |= (Config_Ptr->StopBits << 3); //set stop bit
    General_UART->LCRH |=(Config_Ptr->FIFOStatus << 4); //UART Enable FIFOs
    General_UART->LCRH = (Config_Ptr->WordLength << 5) ;//set word length
    PLACE_VAL(General_UART->IM ,4,Config_Ptr->int_EN); //configure interrupts
    General_UART->CC |= Config_Ptr->clock_Source; //configure clock source

    SET_BIT(General_UART->CTL ,0);  //UART Enable
}

void UART_ClearIntrupt(uint8 UARTx_ID)
{
    if(UART_STATUS_ARR[UARTx_ID]==STD_IDLE)
    {
        while(1)
        {

        }
    }else
    {
        UART0_Type * General_UART=UART_STR_ARR[UARTx_ID];
        SET_REG(General_UART->ICR);
    }
}

void UART_IEN(uint8 UARTx_ID)
{
    if(UART_STATUS_ARR[UARTx_ID]==STD_IDLE)
    {
        while(1)
        {

        }
    }else
    {
        UART0_Type * General_UART=UART_STR_ARR[UARTx_ID];
        SET_BIT(General_UART->IM ,4);
    }
}


void UART_IDIS(uint8 UARTx_ID)
{
    if(UART_STATUS_ARR[UARTx_ID]==STD_IDLE)
    {
        while(1)
        {

        }
    }else
    {
        UART0_Type * General_UART=UART_STR_ARR[UARTx_ID];
        CLEAR_BIT(General_UART->IM ,4);
    }
}

void UART_SendByte(const uint8 Data , uint8 UARTx_ID)
{
    if(UART_STATUS_ARR[UARTx_ID]==STD_IDLE)
    {
        while(1)
        {

        }
    }else
    {
        UART0_Type * General_UART=UART_STR_ARR[UARTx_ID];
        while(BIT_IS_SET(General_UART->FR,5));   //UART Transmit FIFO Full?
        General_UART->DR = Data;
    }
}



uint8 UART_RecieveByte(uint8 UARTx_ID)
{
    if(UART_STATUS_ARR[UARTx_ID]==STD_IDLE)
    {
        while(1)
        {

        }
    }else
    {

        UART0_Type * General_UART=UART_STR_ARR[UARTx_ID];
        while(BIT_IS_SET(General_UART->FR,4)); //UART Receive FIFO Empty
        return  (General_UART->DR);

    }
}

void UART_SendString(const uint8* Str, uint8 UARTx_ID)
{
    if(UART_STATUS_ARR[UARTx_ID]==STD_IDLE)
    {
        while(1)
        {

        }
    }else
    {

        uint8 i =0;
        while(Str[i] != '\0')
        {
            UART_SendByte(Str[i], UARTx_ID);
            i++;
        }
    }
}

void UART_ReceiveString(uint8* Str, uint8 UARTx_ID)
{
    if(UART_STATUS_ARR[UARTx_ID]==STD_IDLE)
    {
        while(1)
        {

        }
    }else
    {
        uint8 i=0;
        Str[i] = UART_RecieveByte(UARTx_ID);

        while(Str[i] != '\n')
        {
            i++;
            Str[i] = UART_RecieveByte(UARTx_ID);
        }
    }
}










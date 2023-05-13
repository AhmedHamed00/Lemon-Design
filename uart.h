******************************************************************************
 *
 * Module: UART
/ *
 * File Name: UART.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - UART driver
 *
 * Author: Noha Adel
 ******************************************************************************/

#ifndef UART_H_
#define UART_H_

 /*******************************************************************************
  *                      Inclusions                                  *
  *******************************************************************************/


#include "std_types.h"
#include "TM4C123GH6PM.h"
#include "common_macros.h"


/*******************************************************************************
 *                      Definitions                                   *
 *******************************************************************************/

#define CHOSEN_UART_ID 0         //choose here a UART id from 0 to 7

#define  UART0_ID 0
#define  UART1_ID 1
#define  UART2_ID 2
#define  UART3_ID 3
#define  UART4_ID 4
#define  UART5_ID 5
#define  UART6_ID 6
#define  UART7_ID 7

#define SYSCTL_RCGCUART_REG   (*((volatile uint32 *)0x400FE618))


/*******************************************************************************
 *                      Custom Data Types                                    *
 *******************************************************************************/

typedef enum {
    FIVE_BITS=0x0, SIX_BITS=0x1, SEVEN_BITS=0x2,EIGHT_BITS=0x3
}UART_WordLength;

typedef enum{
    NO_PARITY=0x0, ODD_PARITY=0x1, EVEN_PARITY=0x3
}UART_Parity;

typedef enum{
    ONE=0x0,TWO=0x1
}UART_StopBit;

typedef enum
{
    System_Clock=0x0,PIOSCC=0x5
}UART_Clock_sorce_type;

typedef struct{
    UART_WordLength WordLength; //
    UART_Parity Parity; //
    UART_StopBit StopBits; //
    UART_Clock_sorce_type clock_Source;
    uint8 IBRD;
    uint8 FBRD;
    uint8 FIFOStatus; //
    uint8 int_EN;
}UART_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void UART_Init(const UART_ConfigType* Config_Ptr , uint8 UARTx_ID); //
/*
  *   Definition: This function is used to initialize the uart peripheral
  *   Author: Noha Adel
  *   Parameters:
  *          @Config_Ptr: a pointer to the configuration structure holding the required initialization values for the UART
  *          @UARTx_ID: the UART no. required to be initialized
 �*/

void UART_ClearIntrupt(uint8 UARTx_ID);
/*
  *   Definition: This function is used to clear the interrupts for the UART
  *   Author: Ahmed Hamed
  *   Parameters:
  *           @UARTx_ID: the chosen UART peripheral
 �*/

void UART_IEN(uint8 UARTx_ID);
/*
  *   Definition: This function is used to enable interrupt for the UART
  *   Author: Ahmed Hamed
  *   Parameters:
  *           @UARTx_ID: the chosen UART peripheral
 �*/

void UART_IDIS(uint8 UARTx_ID);
/*
  *   Definition: This function is used to disable interrupt for the UART
  *   Author: Ahmed Hamed
  *   Parameters:
  *           @UARTx_ID: the chosen UART peripheral
 �*/


void UART_SendByte(const uint8 Data , uint8 UARTx_ID);
/*
  *   Definition: This function is used to send a byte
  *   Author: Noha Adel
  *   Parameters:
  *          @Data: the variable holding the data to be sent
  *          @UARTx_ID: the chosen UART peripheral
 �*/


uint8 UART_RecieveByte(uint8 UARTx_ID);
/*
  *   Definition: This function is used to receive a byte
  *   Author: Noha Adel
  *   Parameters:
  *          @UARTx_ID: the chosen UART peripheral
  *
  *   Return value:
  *          @returns a uint8 variable holding the received byte
 �*/


void UART_SendString(const uint8* Str, uint8 UARTx_ID);
/*
  *   Definition: This function is used to send a string
  *   Author: Noha Adel
  *   Parameters:
  *          @Str:a pointer to the char array holding the string to be sent
  *          @UARTx_ID: the chosen UART peripheral
 �*/


void UART_ReceiveString(uint8* Str, uint8 UARTx_ID);
/*
  *   Definition: This function is used to receive a string
  *   Author: Noha Adel
  *   Parameters:
  *          @Str:a pointer to a char array to hold the received string
  *          @UARTx_ID: the chosen UART peripheral
 �*/


#endif /* UART_H_ */

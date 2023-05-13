 /******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - SysTick Timer Driver.
 *
 * Author: Donia
 ******************************************************************************/

#ifndef GPT_H
#define GPT_H

#include "Std_Types.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: SysTick_Start
*
* Return value: None
*
* Description: Function to Setup the SysTick Timer configuration to count n miliseconds:
*              - Set the Reload value
*              - Enable SysTick Timer with System clock 16Mhz
*              - Enable SysTick Timer Interrupt and set its priority
************************************************************************************/
void SysTick_Start(uint16 Tick_Time);

/************************************************************************************
* Service Name: SysTick_Stop
*
* Return value: None
*
* Description: Function to Stop the SysTick Timer.
************************************************************************************/
void SysTick_Stop(void);

/************************************************************************************
* Service Name: SysTick_wait
*
* Return value: None
*
* Description: Function to Stop the SysTick Timer.
************************************************************************************/
void SysTick_wait(uint32 i);

#endif /* GPT_H */

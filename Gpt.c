 /******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - SysTick Timer Driver.
 *
 * Author: Donia
 ******************************************************************************/

#include "Gpt.h"
#define SYSTICK_CTRL_REG          (*((volatile uint32 *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile uint32 *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile uint32 *)0xE000E018))
#define NVIC_SYSTEM_PRI3_REG      (*((volatile uint32 *)0xE000ED20))
#define SYSTICK_PRIORITY_MASK  0x1FFFFFFF
#define SYSTICK_INTERRUPT_PRIORITY  3
#define SYSTICK_PRIORITY_BITS_POS   29


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
void SysTick_Start(uint16 Tick_Time)
{
    SYSTICK_CTRL_REG    = 0;              /* Disable the SysTick Timer by Clear the ENABLE Bit */
        SYSTICK_RELOAD_REG  = 15999999;        /* Set the Reload value with 7999999 to count half Second */
        SYSTICK_CURRENT_REG = 0;              /* Clear the Current Register value */
        /* Configure the SysTick Control Register
         * Enable the SysTick Timer (ENABLE = 1)
         * Disable SysTick Interrupt (INTEN = 0)
         * Choose the clock source to be System Clock (CLK_SRC = 1) */
        SYSTICK_CTRL_REG   |= 0x05;
}

/************************************************************************************
* Service Name: SysTick_Stop
*
* Return value: None
*
* Description: Function to Stop the SysTick Timer.
************************************************************************************/
void SysTick_Stop(void)
{
    SYSTICK_CTRL_REG = 0; /* Disable the SysTick Timer by Clear the ENABLE Bit */
}


/************************************************************************************
* Service Name: SysTick_wait
*
* Return value: None
*
* Description: Function to Stop the SysTick Timer.
************************************************************************************/
void SysTick_wait(uint32 x)
{
    int i;
        for(i=0;i<x;i++)
        {
            while(!(SYSTICK_CTRL_REG & (1<<16)));
        }
}

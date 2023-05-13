******************************************************************************
 *
 * Module: LEDs
/ *
 * File Name: LEDS.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - LEDS driver
 *
 * Author: Youssef
 ******************************************************************************/


#include "LEDS.h"
#include "GPIO.h"
#include "common_macros.h"


void LEDS_init(void)
{
    GPIO_SetPinDir(PORTF_ID, PIN1_ID, OUTPUT, OFF, STD_LOW);
    GPIO_SetPinDir(PORTF_ID, PIN2_ID, OUTPUT, OFF, STD_LOW);
    GPIO_SetPinDir(PORTF_ID, PIN3_ID, OUTPUT, OFF, STD_LOW);
}

void LEDS_ON(Color selection)
{
    GPIO_WritePort(PORTF_ID,selection);
}

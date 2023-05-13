/******************************************************************************
 *
 * Module: main
 *
 * File Name: main.c
 *
 * Description: main function source file for gps project.
 *
 * Author: Ahmed, Noha, Merna, Donia, Youssef
 ******************************************************************************/
#include "GPIO.h"
#include "TM4C123GH6PM.h"
#include "uart.h"
#include "neo6_m.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "LEDS.h"


/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm("     CPSIE I")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm("     CPSID I")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm("     CPSIE F")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm("     CPSID F")

#define NVIC_EN0_REG              (*((volatile unsigned long *)0xE000E100))
void _delay_ms(unsigned long long n);

void reverse(uint8 str[], uint32 length);
uint8* citoa(uint32 num, uint8* str, uint32 base);


int main(void)
{}
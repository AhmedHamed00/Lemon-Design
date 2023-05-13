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
{
    
}

void reverse(uint8 str[], uint32 length)
{
    uint32 start = 0;
    uint32 end = length - 1;
    while (start < end)
    {
        uint8 temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

uint8* citoa(uint32 num, uint8* str, uint32 base)
{
    uint32 i = 0;
    uint8 isNegative = 0;

    /* Handle 0 explicitly, otherwise empty string is
     * printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled
    // only with base 10. Otherwise numbers are
    // considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        uint32 rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}

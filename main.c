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
    float64 total_distance = 0;
    float64 target_latetude = 30.0380278;
    float64 target_long = 31.1674545;

    NEO6_init();
    Enable_Faults();
    NVIC_EN0_REG |= (1 << 6);
    Enable_Exceptions();
    LEDS_init();
    UART_ConfigType config_one = { EIGHT_BITS, NO_PARITY, ONE, PIOSCC, 0x68, 0xB, STD_ON, STD_OFF };
    UART_Init(&config_one, 0);


    while (NEO6_status == STD_IDLE);


    float64 old_lat;
    float64 old_long;
    old_lat = NEO6_data[0] / 100;
    old_long = NEO6_data[1] / 100;

    float64 new_lat;
    float64 new_long;
    uartflag = 0;

    float64 distancee;
    uint8 buff[16]; /* String to hold the ascii result */
    while (1)
    {

        if (uartflag == 1 && NEO6_status == STD_ACTIVE)
        {
            uartflag = 0;
            new_lat = NEO6_data[0] / 100;
            new_long = NEO6_data[1] / 100;
            distancee = NEO6_distance(old_lat, old_long, new_lat, new_long, 'K') * 1000;
            if (distancee > 0.7)
            {
                total_distance += distancee;
                old_lat = new_lat;
                old_long = new_long;
                citoa(total_distance, buff, 10);
            }

            citoa(total_distance, buff, 10);
            UART_SendString("total dist\n\r", UART0_ID);
            UART_SendString(buff, UART0_ID);
            UART_SendString("\n\r", UART0_ID);
            if ((NEO6_distance(target_latetude, target_long, new_lat, new_long, 'K') * 1000) < 5)
            {
                LEDS_ON(GREEN);
                UART_SendString("Green Led ON \n\r", UART0_ID);
            }
            else if ((NEO6_distance(target_latetude, target_long, new_lat, new_long, 'K') * 1000) < 10)
            {
                LEDS_ON(YELLOW);
                UART_SendString("Yellow Led ON \n\r", UART0_ID);
            }
            else
            {
                LEDS_ON(RED);
                UART_SendString("Red Led ON \n\r", UART0_ID);
            }

        }

    }
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

******************************************************************************
 *
 * Module: LEDs
/ *
 * File Name: LEDS.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - LEDS driver
 *
 * Author: Youssef

 ******************************************************************************/

#ifndef LEDS_H_
#define LEDS_H_

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*enumeration to define the color to be selected */
typedef enum
{
    RED=0x2,BLUE=0x4,GREEN=0x8,WHITE=0xE,YELLOW=0xA,PINK=0x6,sky=0XC,LEDS_OFF=0x0
}Color;

/*******************************************************************************
  *                      Function Prototypes                                    *
  *******************************************************************************/

void LEDS_init(void);
/*
  *   Definition: This function is used to initialize the three pins connected to the 3 leds on the tiva board
  *   Author: Ahmed Hamed
  *   Parameters:
  *          @none
  */
void LEDS_ON(Color selection);
/*
  *   Definition: This function is used to turn on the required led color
  *   Author: Ahmed Hamed
  *   Parameters:
  *          @selection: the led color required to turn on, chosen from the enum @Color
  */


#endif /* LEDS_H_ */

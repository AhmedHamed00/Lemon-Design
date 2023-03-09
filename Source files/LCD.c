/*
*   Author: Ahmed Hamed
*   File Name: LCD.h
*   Description: This is a source for LCD driver
*/


#include "LCD.h"
#include "GPIO.h"
#include "common_macros.h"

/*FUNCTIONS DEFINITIONS*/


/*
 *   Definition: This function is used to initialize the LCD
 *   Author: -------
 *   Parameters:------
 */
void LCD_Init(void)
{

}


/*
 *   Definition: This function is used to send a command to LCD
 *   Author: ----
 *   Parameters:
 *           @Command: this is the commmand code to be sent
 */
void LCD_SendCommand(uint8 Command)
{

}


/*
 *   Definition: This function is used to display character on LCD
 *   Author: ------
 *   Parameters:
 *           @Data: this is the data("ASCII code") of the character to be displayed on the LCD
 */
void LCD_Displaycharacter(uint8 Data)
{

}


/*
 *   Definition: This function is used to display string ("Array of characters") on LCD
 *   Author: ------
 *   Parameters:
 *           @Data: this is the data("pointer to a char") of the string to be displayed
 */
void LCD_DisplayString(uint8 *Data)
{

}


/*
 *   Definition: This function is used to move the LCD cursor to the required position
 *   Author: ------
 *   Parameters:
 *           @Row: this is the row to write on
 *           @Col: this is the column to write on
 */
void LCD_MoveCursor(uint8 Row,uint8 Col)
{

}


/*
 *   Definition: This function is used to clear the LCD
 *   Author: -----
 *   Parameters: NA
 */
void LCD_ClearScreen(void)
{

}


/*
 *   Definition: This function is used to Display intger on the LCD
 *   Author: -----
 *   Parameters:
 *           @Data: this is the intger value to be displayed of the LCD
 */
void LCD_DisplayInt(uint16 Data)
{

}



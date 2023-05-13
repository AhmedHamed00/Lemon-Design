/******************************************************************************
 *
 *      File Name: Common_Macros.h
 *      Description: Commonly used Macros
 *      Author: Ahmed Hamed
 *
 *******************************************************************************/

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/* Set first 8 bits at any register */
#define SET_FIRST_8(REG) (REG|=0xFF)

/* clear first 8 bits at any register */
#define CLEAR_FIRST_8(REG) (REG&=0x00)

/* Set any register */
#define SET_REG(REG) (REG|=0XFFFFFFFF)

/* clear any register */
#define CLEAR_REG(REG) (REG&=0X00000000)

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/* Return the value of a specific bit  */
#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )

/* PLave a specific value at a specific bit */
#define PLACE_VAL(REG,BIT,VAL) (REG=(REG&(~(1<<BIT)))|(VAL<<BIT))

/* Assign a value (1 or 0) to a Register */
#define PLACE_PORT_VAL(REG,VAL)  (REG=(REG&0X00000000) |(VAL*0XFFFFFFFF))
#endif /* COMMON_MACROS_H_ */

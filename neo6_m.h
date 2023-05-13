/******************************************************************************
 *
 * Module: neo6_m
 *
 * File Name: neo6_m.c
 *
 * Description: Header file for neo6m gps module
 *
 * Author: Merna
 ******************************************************************************/


#ifndef NEO6_M_H_
#define NEO6_M_H_
#include "uart.h"
#include "std_types.h"
#include <math.h>


#define UART_USED   UART1_ID
extern float64 NEO6_data[3];
extern uint8 NEO6_status;
extern uint8 Raw_data[];
extern uint8 uartflag;
extern uint8 arr0[10];
extern uint8 arr1[11];
extern uint8 arr2[5];



/*FUNCTIONS DEFINITIONS*/

/*
 *   Definition: This function is used to init a gps module
 *   Author: Ahmed Hamed
 *   Parameters:
 *
 */
void NEO6_init(void);

/*
 *   Definition: This function is used to parse a gps module raw data into lat&long&speed
 *   Author: Ahmed Hamed
 *   Parameters:
 *
 */
void NEO6_parse(void);

/*
 *   Definition: This function is used to convert radians to degrees
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @rad: the angle to be converted
 */
float64 NEO6_rad2deg(float64 rad);


/*
 *   Definition: This function is used to convert degrees to radians
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @degree: the angle to be converted
 */
float64  NEO6_deg2rad(const float64  degree);

/*
 *   Definition: This function is used to get distance between two points
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @lat1:latitude of first point
 *           @lon1:longitude of first point
 *           @lat2:latitude of second point
 *           @lon2:longitude of second point
 *           @uint: the unit of the output distance
 */
float64 NEO6_distance(float64 lat1, float64 lon1, float64 lat2, float64 lon2, uint8 unit) ;
#endif /* NEO6_M_H_ */

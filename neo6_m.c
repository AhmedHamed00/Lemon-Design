/******************************************************************************
 *
 * Module: neo6_m
 *
 * File Name: neo6_m.c
 *
 * Description: Source file for neo6m gps module
 *
 * Author: Merna
 ******************************************************************************/


#include "neo6_m.h"
#include <stdlib.h>
float64 NEO6_data[3];
uint8 arr0[10]={0};
uint8 arr1[11]={0};
uint8 arr2[5]={0};
uint8 Raw_data[70];
uint8 NEO6_status=STD_IDLE;
uint8 uartflag=0;


/*FUNCTIONS DEFINITIONS*/

/*
 *   Definition: This function is the ISR of the UART used to receive from gps
 *   Author: Ahmed Hamed
 *   Parameters:
 *
 */
void UART_Handler(void)
{
    uartflag=1;
    if( UART_RecieveByte(UART_USED) == '$')
    {

        UART_IDIS(UART_USED);//disable interrupt
        UART_ReceiveString(Raw_data, UART_USED);
    }
    UART_ClearIntrupt(UART_USED);//clear interrupt flag
    NEO6_parse();
    UART_IEN(UART_USED);//enable interrupt
}


/*
 *   Definition: This function is used to init a gps module
 *   Author: Ahmed Hamed
 *   Parameters:
 *
 */
void NEO6_init(void)
{
    UART_ConfigType UartConfigStruct={EIGHT_BITS, NO_PARITY, ONE, PIOSCC, 0x68, 0xB, STD_ON, STD_ON};
    UART_Init(&UartConfigStruct, UART_USED);

}



/*
 *   Definition: This function is used to parse a gps module raw data into lat&long&speed
 *   Author: Ahmed Hamed
 *   Parameters:
 *
 */
void NEO6_parse(void)
{

    uint8 x=0,y=0,z=0,flag=0;
    uint8 Raw_data_index;
    for (Raw_data_index=0;Raw_data_index<70;Raw_data_index++)
    {
        if (Raw_data[Raw_data_index]==',')
        {
            flag++;//not declared
        }
        else if(flag==2)
        {
            if(Raw_data[Raw_data_index]=='A')
            {
                NEO6_status=STD_ACTIVE;
                uartflag=1;
            }
            else
            {
                NEO6_status=STD_IDLE;
            }
        }
        else if(flag==3)
        {
            arr0[x]=Raw_data[Raw_data_index];
            x++;
        }
        else if(flag==5)
        {
            arr1[y]=Raw_data[Raw_data_index];
            y++;
        }
        else if(flag==7)
        {
            arr2[z]=Raw_data[Raw_data_index];
            z++;
        }
    }
    NEO6_data[0]  = atof(arr0);
    NEO6_data[1]  = atof(arr1);
    NEO6_data[2]  = atof(arr2);
    NEO6_data[2] *= 1.852;
}
/*
 *   Definition: This function is used to convert radians to degrees
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @rad: the angle to be converted
 */
float64 NEO6_rad2deg(float64 rad) {
    return (rad * 180 / 22.0*7);
}

/*
 *   Definition: This function is used to convert degrees to radians
 *   Author: Ahmed Hamed
 *   Parameters:
 *           @degree: the angle to be converted
 */
float64  NEO6_deg2rad(const float64  degree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    float64  one_deg = (22/7.0) / 180;
    return (one_deg * degree);
}


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
float64 NEO6_distance(float64 lat1, float64 lon1, float64 lat2, float64 lon2, uint8 unit)
{
    float64 theta, dist;
    if ((lat1 == lat2) && (lon1 == lon2))
    {
        return 0;
    }
    else
    {
        theta = lon1 - lon2;
        dist = sin(NEO6_deg2rad(lat1)) * sin(NEO6_deg2rad(lat2)) + cos(NEO6_deg2rad(lat1)) * cos(NEO6_deg2rad(lat2)) * cos(NEO6_deg2rad(theta));
        dist = acos(dist);
        dist = NEO6_rad2deg(dist);
        dist = dist * 60 * 1.1515;
        switch(unit)
        {
        case 'M':
            break;
        case 'K':
            dist = dist * 1.609344;
            break;
        case 'N':
            dist = dist * 0.8684;
            break;
        case 'm':
            dist = dist * 1.609344*1000;
            break;
        }
        return (dist);
    }
}

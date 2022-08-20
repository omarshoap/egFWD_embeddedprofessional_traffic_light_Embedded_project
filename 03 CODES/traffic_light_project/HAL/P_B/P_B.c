/*
 * P_B.c
 *
 * Created: 8/18/2022 12:45:20 PM
 *  Author: omar
 */ 



#include "P_B.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../UTIL/STD_TYPES.h"


void P_B_INIT(void)
{
    DIO_PIN_DIRECTION(P_B_PORT, P_B_PIN ,INPUT);
}
u8 P_B_READ(void)
{
	u8 value = 0;
	value = DIO_PIN_READ(P_B_PORT,P_B_PIN);
	return value;
}

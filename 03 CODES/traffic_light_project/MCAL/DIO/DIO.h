/*
 * DIO.h
 *
 * Created: 8/18/2022 11:27:02 AM
 *  Author: omar
 */ 


#ifndef DIO_H_
#define DIO_H_



#include "../../UTIL/STD_TYPES.h"

#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

#define INPUT    0
#define OUTPUT   1

#define HIGH     1
#define LOW      0

void DIO_PIN_DIRECTION(u8 port,u8 pin,u8 status);
void DIO_PIN_WRITE(u8 port,u8 pin,u8 status);
u8 DIO_PIN_READ(u8 port,u8 pin);
void DIO_PIN_TOG(u8 port,u8 pin);





#endif /* DIO_H_ */
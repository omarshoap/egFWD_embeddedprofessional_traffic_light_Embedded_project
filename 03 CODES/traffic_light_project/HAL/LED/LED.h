/*
 * LED.h
 *
 * Created: 8/18/2022 12:40:48 PM
 *  Author: omar
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../UTIL/REG.h"
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"

#define	CAR_LEDS_PORT	DIO_PORTA
#define	CAR_LED_G_PIN	0
#define	CAR_LED_Y_PIN	1
#define	CAR_LED_R_PIN	2

#define	WALKER_LEDS_PORT	DIO_PORTB
#define	WALKER_LED_G_PIN	0
#define	WALKER_LED_Y_PIN	1
#define	WALKER_LED_R_PIN	2

void LED_INIT(u8 LED_PORT, u8 LED_PIN);
void LED_ON(u8 LED_PORT, u8 LED_PIN);
void LED_OFF(u8 LED_PORT, u8 LED_PIN);
void LED_TOG(u8 LED_PORT, u8 LED_PIN);





#endif /* LED_H_ */
/*
 * LED.c
 *
 * Created: 8/18/2022 12:38:56 PM
 *  Author: omar
 */ 

#include "../../MCAL/DIO/DIO.h"

void LED_INIT(u8 LED_PORT, u8 LED_PIN)
{

	DIO_PIN_DIRECTION(LED_PORT,LED_PIN,OUTPUT);

}
void LED_ON(u8 LED_PORT, u8 LED_PIN)
{

	DIO_PIN_WRITE(LED_PORT,LED_PIN,HIGH);

}
void LED_OFF(u8 LED_PORT, u8 LED_PIN)
{

	DIO_PIN_WRITE(LED_PORT,LED_PIN,LOW);

}
void LED_TOG(u8 LED_PORT, u8 LED_PIN)
{
	DIO_PIN_TOG(LED_PORT,LED_PIN);
}

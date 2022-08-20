/*
 * TIMER.c
 *
 * Created: 8/18/2022 4:46:15 PM
 *  Author: omar
 */ 

#include "TIMER.h"
#include "../../UTIL/REG.h"
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"


void TIMER_1_INIT(void)
{
	/*to select ctc mode in timer 1*/
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

	/*_to enable global interrupt and timer 1 interrupt */
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,4);
	
	 // initialize counter
	 TCNT1 = 0;
}
/*
the following function is built for F_CPU 8000000 HZ 
and we took prescaler 1024 
*/
void TIMER_1_SET_TIME(u32 desired_time) // desired_time in milli seconds 
{
	if (desired_time <= 8000)
	{
		u8  tick_time  = 1024 / 8;      // result will be in micro second
		u32 total_ticks = desired_time*1000 / tick_time;
		OCR1A = total_ticks - 1; // we substitute "-1" as the compare match in hardware take one tick to execute 

	}
}
void TIMER_1_START(void)
{
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
}
void TIMER_1_STOP(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}

void delayINmilliSec(u32 TIME)
{
	TIMER_1_SET_TIME(TIME);
	TIMER_1_START();
	while((TIFR & (1<< 4)) == 0);// wait till the timer Output Compare Match  flag is SET
	TIMER_1_STOP();
	TCNT1 = 0;
	SET_BIT(TIFR,4); //clear timer1 overflow flag	
}

/*
		TIMER_1_SET_TIME(1000);
		TIMER_1_START();
		while((TIFR & (1<< 4)) == 0);// wait till the timer Output Compare Match  flag is SET
		DIO_PIN_TOG(DIO_PORTA,0); // function after desired delay
		TIMER_1_STOP();
		TCNT1 = 0;
		SET_BIT(TIFR,4); //clear timer1 overflow flag
*/


/*
//If flag is set toggle the led

while((TIFR & (1<< 4)) == 0);// wait till the timer Output Compare Match  flag is SET
LED_TOG();// function after desired delay 
TCNT1 = 0;
SET_BIT(TIFR,4); //clear timer1 overflow flag
*/

/*
ISR(TIMER1_OVF_vect)

{
	LED_TOG();
}
*/
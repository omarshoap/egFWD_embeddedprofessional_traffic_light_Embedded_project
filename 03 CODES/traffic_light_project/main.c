/*
 * traffic_light_project.c
 *
 * Created: 8/18/2022 10:27:25 AM
 * Author : omar
 */ 

#include "avr/interrupt.h"

#define F_CPU 8000000UL
#include "UTIL/STD_TYPES.h"
#include "UTIL/REG.h"
#include "UTIL/BIT_MATH.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/EXT_INT/EXT_INT.h"
#include "MCAL/TIMER/TIMER.h"
#include "HAL/LED/LED.h"
#include "HAL/P_B/P_B.h"
#include <avr/wdt.h>

volatile u8 INT_COUNTER = 0 ; 
u8 car_IS_red_flag = 0 ;
u8 car_IS_green_flag = 0 ;
u8 car_IS_yellow_flag = 0 ;


int main(void)
{
 
	LED_INIT(CAR_LEDS_PORT,CAR_LED_G_PIN);
	LED_INIT(CAR_LEDS_PORT,CAR_LED_Y_PIN);
	LED_INIT(CAR_LEDS_PORT,CAR_LED_R_PIN);
	LED_INIT(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
	LED_INIT(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
	LED_INIT(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
	P_B_INIT();
	EXT_INT_0_INIT();
	TIMER_1_INIT();
		
  
  
    while (1) 
    {
	
			//** turn off all leds 
			LED_OFF(CAR_LEDS_PORT,CAR_LED_G_PIN);
			LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
			LED_OFF(CAR_LEDS_PORT,CAR_LED_R_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
			/************************************************************************/
			/******************** Normal mode start *********************************/
			/************************************************************************/
			/////////////////////////////////////
			LED_ON(CAR_LEDS_PORT,CAR_LED_G_PIN);
			car_IS_green_flag = 1 ;
			delayINmilliSec(5000);
			car_IS_yellow_flag = 1 ; 
			for (u8 i=0 ; i <= 4 ; i++)
			{
				LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				delayINmilliSec(500);
				LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				delayINmilliSec(500);
			}
			car_IS_yellow_flag = 0 ; 
			car_IS_green_flag = 0 ;
			LED_OFF(CAR_LEDS_PORT,CAR_LED_G_PIN);
			///////////////////////////////////////
			LED_ON(CAR_LEDS_PORT,CAR_LED_R_PIN);
			car_IS_red_flag = 1 ;
			delayINmilliSec(5000);
			car_IS_yellow_flag = 1 ; 
			for (u8 i=0 ; i <= 4 ; i++)
			{
				LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				delayINmilliSec(500);
				LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				delayINmilliSec(500);
			}
			car_IS_yellow_flag = 0 ; 
			car_IS_red_flag = 0 ;
			LED_OFF(CAR_LEDS_PORT,CAR_LED_R_PIN);
			///////////////////////////////////////
			
		
		
    }
}



ISR(INT0_vect)
{
	
			//** turn off all leds 
			LED_OFF(CAR_LEDS_PORT,CAR_LED_G_PIN);
			LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
			LED_OFF(CAR_LEDS_PORT,CAR_LED_R_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
			
		/************************************************************************/
		/******************** Pedestrian mode [case1] start *********************/
		/************************************************************************/		
		if (car_IS_red_flag == 1)
		{			


			//////////////////stage2/////////////////////
			/*-------------------------------------*/
			LED_ON(CAR_LEDS_PORT,CAR_LED_R_PIN);
			LED_ON(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
			delayINmilliSec(5000);
			//////////////////stage4/////////////////////
			for (u8 i=0 ; i <= 4 ; i++)
			{
				LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				LED_ON(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
				delayINmilliSec(500);
				LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				LED_OFF(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
				delayINmilliSec(500);
			}
			LED_OFF(CAR_LEDS_PORT,CAR_LED_R_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
			////////////////////stage5///////////////////
			LED_ON(CAR_LEDS_PORT,CAR_LED_G_PIN);
			LED_ON(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
			delayINmilliSec(5000);
			
		}	
		
		/************************************************************************/
		/******************** Pedestrian mode [case2,case3] start ***************/
		/************************************************************************/		
		else if (car_IS_green_flag == 1 || car_IS_yellow_flag == 1 )
		{
			//////////////////stage3/////////////////////
			LED_ON(CAR_LEDS_PORT,CAR_LED_G_PIN);
			LED_ON(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
			delayINmilliSec(2000);
			for (u8 i=0 ; i <= 4 ; i++)
			{
				LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				LED_ON(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
				delayINmilliSec(500);
				LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				LED_OFF(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
				delayINmilliSec(500);
			}
			LED_OFF(CAR_LEDS_PORT,CAR_LED_G_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
			/*-------------------------------------*/
			LED_ON(CAR_LEDS_PORT,CAR_LED_R_PIN);
			LED_ON(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
			delayINmilliSec(5000);
			////////////////////stage4///////////////////
			for (u8 i=0 ; i <= 4 ; i++)
			{
				LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				LED_ON(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
				delayINmilliSec(500);
				LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				LED_OFF(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
				delayINmilliSec(500);
			}
			LED_OFF(CAR_LEDS_PORT,CAR_LED_R_PIN);
			LED_OFF(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
			////////////////////stage5///////////////////
			LED_ON(CAR_LEDS_PORT,CAR_LED_G_PIN);
			LED_ON(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
			delayINmilliSec(5000);
			
		}

		
			
		
		 /* 
	* Resetting the uC to restart the NormalMode.
	* Jumping to the reset vector doesn't clear the pins and
	* thus needs to be cleared manually.
	 */
	
	//__asm__ __volatile__ ("jmp 0x00");
	//__asm__ __volatile__("jmp 0x00 \n");
	wdt_enable(WDTO_15MS); // self reset after 15 milliseconds



		
}
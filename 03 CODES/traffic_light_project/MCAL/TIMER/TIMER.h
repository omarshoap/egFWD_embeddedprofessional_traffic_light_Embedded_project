/*
 * TIMER.h
 *
 * Created: 8/18/2022 4:46:28 PM
 *  Author: omar
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "../../UTIL/STD_TYPES.h"


void TIMER_1_INIT(void);
void TIMER_1_SET_TIME(u32 desired_time);
void TIMER_1_START(void);
void TIMER_1_STOP(void);
void delayINmilliSec(u32 TIME);




#endif /* TIMER_H_ */
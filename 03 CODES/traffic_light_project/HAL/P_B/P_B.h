/*
 * P_B.h
 *
 * Created: 8/18/2022 12:46:05 PM
 *  Author: omar
 */ 


#ifndef P_B_H_
#define P_B_H_

#include "../../UTIL/REG.h"
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"


/* P_B_CFG */
#define P_B_PORT     DIO_PORTD
#define P_B_PIN       2			// INT0 input


void P_B_INIT(void);
u8 P_B_READ(void);




#endif /* P_B_H_ */
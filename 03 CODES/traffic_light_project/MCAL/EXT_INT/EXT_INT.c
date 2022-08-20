/*
 * EXT_INT.c
 *
 * Created: 8/18/2022 11:53:35 AM
 *  Author: omar
 */ 


#include "../../UTIL/REG.h"
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"


void EXT_INT_0_INIT(void)
{
	SET_BIT(SREG,7);        /*_TO_ENABLE_THE_GLOBAL_INT_*/
	SET_BIT(GICR,6);        /*_TO_ENABLE_INT_0_*/
	CLR_BIT(MCUCR,0);       /* to make interrupt with FALLING edge*/
	SET_BIT(MCUCR,1);       /*                //                  */

}

/*
 * BIT_MATH.h
 *
 * Created: 8/18/2022 11:19:44 AM
 *  Author: omar
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT)       (REG = REG  | (1 << BIT))
#define CLR_BIT(REG,BIT)       (REG = REG   & (~(1 << BIT)))
#define TOG_BIT(REG,BIT)       (REG =  REG ^ (1 << BIT))
#define GET_BIT(REG,BIT)       ((REG>>BIT)  &1    )



#endif /* BIT_MATH_H_ */
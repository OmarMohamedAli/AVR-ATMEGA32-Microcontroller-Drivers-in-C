
/*
 * File        : Bit_Math.h
 * Description : This file includes macros for Bit manipulation
 * Author      : Omar Mohamed Embedded SW Engineer 
 * Date        : 2/3/20201
 * Git account : https://github.com/OmarMohamedAli
 * mail        : om1565580@gmail.com
 */


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(reg,bit)        (reg|=(1<<bit))
#define reset_bit(reg,bit)      (reg&=(~1<<bit))
#define Toggle_bit(reg,bit)     (reg^=(1<<bit))

#endif // MACROS_H_
/*
 * Compute 2 * f. If f is NaN, then return f. 
 */

#include<stdio.h>
#include"float_bit.h"

/*
 * Three condition:
 * 1) the f is denormailized
 * 2) the f is close to largest normailized
 * 3) normalized value
 */
float_bits float_twice(float_bits f){
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    if(!(~exp) && frac){
        return f;
    }

    if(exp == 0){
        /* Denormailized value */
        exp = frac >> 22;
        frac <<= 1;
    }else if(exp == 0xff - 1){
        /* Infinity value */
        exp = 0xff;
        frac = 0;
    }else{
        exp += 1;
    }
    /* Reassemble bits */
    return (sign << 31) | (exp << 23) | frac;
}

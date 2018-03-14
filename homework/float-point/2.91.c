/*
 * Compute -f. If f is NaN, then return f. 
 */

#include<stdio.h>
#include"float_bit.h"

float_bits float_negate(float_bits f){
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    /* if the any bits of exp equal to 1 and frac not equals to 0, then f is NaN */
    unsigned sign = (f >> 31) ^ (~exp || !frac);
    /* Reassemble bits */
    printf("the f = %x\n", f);
    printf("sign = %x\n", sign);
    printf("exp = %x\n", exp);
    printf("frac = %x\n", frac);
    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char* argv[]){
    printf("%x\n", float_negate(0x4640E400));
    return 0;
}

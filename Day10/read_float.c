#include<stdio.h>
#include<inttypes.h>

#define CHECK_BIT(a, i) (!!a&(1ULL << i))

typedef struct float_components{
    unsigned int mantissa : 23;
    unsigned int exp : 8;
    unsigned int sign : 1;
    

}float_components;

typedef union F{
    float f;
    float_components c;
}F;

int main(){
    F f1;
    f1.f = -3.0;
    scanf("%f", &(f1.f));
    printf("SIGN: %u\n EXPONENT: %u\n MANTISSA: %u\n", f1.c.sign, f1.c.exp, f1.c.mantissa);
    f1.f = -3.0;
}
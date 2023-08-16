#include<stdio.h>
#include<inttypes.h>

#define CHECK_BIT(a, i) (!!a&(1ULL << i))

typedef struct char_bits{
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int b8 : 1;
    

}char_bits;

typedef union C{
    char c;
    char_bits bits;
    

}C;

int main(){
    signed char c = -7;
  //  for(size_t i = 8; i > 0; i--){
 //       printf("%llu ", CHECK_BIT(c ,(i-1)));
//}

    C c1;
    c1.c = -7;
    printf("%u ", c1.bits.b8);
    printf("%u ", c1.bits.b7);
    printf("%u ", c1.bits.b6);
    printf("%u ", c1.bits.b5);
    printf("%u ", c1.bits.b4);
    printf("%u ", c1.bits.b3);
    printf("%u ", c1.bits.b2);
    printf("%u ", c1.bits.b1);
    return 0;
}
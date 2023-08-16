#include<stdio.h>
#include<inttypes.h>


typedef struct double_bits{
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int b8 : 1;
    unsigned int b9 : 1;
    unsigned int b10 : 1;
    unsigned int b11 : 1;
    unsigned int b12 : 1;
    unsigned int b13 : 1;
    unsigned int b14 : 1;
    unsigned int b15 : 1;
    unsigned int b16: 1;
    unsigned int b17 : 1;
    unsigned int b18 : 1;
    unsigned int b19 : 1;
    unsigned int b20 : 1;
    unsigned int b21 : 1;
    unsigned int b22 : 1;
    unsigned int b23 : 1;
    unsigned int b24 : 1;
    unsigned int b25 : 1;
    unsigned int b26 : 1;
    unsigned int b27 : 1;
    unsigned int b28 : 1;
    unsigned int b29 : 1;
    unsigned int b30 : 1;
    unsigned int b31 : 1;
    unsigned int b32 : 1;
    unsigned int b33 : 1;
    unsigned int b34 : 1;
    unsigned int b35 : 1;
    unsigned int b36 : 1;
    unsigned int b37 : 1;
    unsigned int b38: 1;
    unsigned int b39 : 1;
    unsigned int b40 : 1;
    unsigned int b41 : 1;
    unsigned int b42 : 1;
    unsigned int b43 : 1;
    unsigned int b44 : 1;
    unsigned int b45 : 1;
    unsigned int b46 : 1;
    unsigned int b47 : 1;
    unsigned int b48 : 1;
    unsigned int b49 : 1;
    unsigned int b50 : 1;
    unsigned int b51 : 1;
    unsigned int b52 : 1;
    unsigned int b53 : 1;
    unsigned int b54 : 1;
    unsigned int b55 : 1;
    unsigned int b56 : 1;
    unsigned int b57 : 1;
    unsigned int b58 : 1;
    unsigned int b59 : 1;
    unsigned int b60 : 1;
    unsigned int b61 : 1;
    unsigned int b62 : 1;
    unsigned int b63 : 1;
    unsigned int b64 : 1;
    

}double_bits;

typedef struct double_components{
    uint64_t mantissa : 52;
    unsigned int exp : 11;
    unsigned int sign : 1;
    

}double_components;

typedef union D{
    double d;
    double_bits bits;
    

}D;

typedef union D1{
    double d;
    double_components bits;
    

}D1;

void print_bits(D d){
    
        printf("%u ", d.bits.b64);
        printf("%u ", d.bits.b63);
        printf("%u ", d.bits.b62);
        printf("%u ", d.bits.b61);
        printf("%u ", d.bits.b60);
        printf("%u ", d.bits.b59);
        printf("%u ", d.bits.b58);
        printf("%u ", d.bits.b57);
        printf("%u ", d.bits.b56);
        printf("%u ", d.bits.b55);
        printf("%u ", d.bits.b54);
        printf("%u ", d.bits.b53);
        printf("%u ", d.bits.b52);
        printf("%u ", d.bits.b51);
        printf("%u ", d.bits.b50);
        printf("%u ", d.bits.b49);
        printf("%u ", d.bits.b48);
        printf("%u ", d.bits.b47);
        printf("%u ", d.bits.b46);
        printf("%u ", d.bits.b45);
        printf("%u ", d.bits.b44);
        printf("%u ", d.bits.b43);
        printf("%u ", d.bits.b42);
        printf("%u ", d.bits.b41);
        printf("%u ", d.bits.b40);
        printf("%u ", d.bits.b39);
        printf("%u ", d.bits.b38);
        printf("%u ", d.bits.b37);
        printf("%u ", d.bits.b36);
        printf("%u ", d.bits.b35);
        printf("%u ", d.bits.b34);
        printf("%u ", d.bits.b33);
        printf("%u ", d.bits.b32);
        printf("%u ", d.bits.b31);
        printf("%u ", d.bits.b30);
        printf("%u ", d.bits.b29);
        printf("%u ", d.bits.b28);
        printf("%u ", d.bits.b27);
        printf("%u ", d.bits.b26);
        printf("%u ", d.bits.b25);
        printf("%u ", d.bits.b24);
        printf("%u ", d.bits.b23);
        printf("%u ", d.bits.b22);
        printf("%u ", d.bits.b21);
        printf("%u ", d.bits.b20);
        printf("%u ", d.bits.b19);
        printf("%u ", d.bits.b18);
        printf("%u ", d.bits.b17);
        printf("%u ", d.bits.b16);
        printf("%u ", d.bits.b15);
        printf("%u ", d.bits.b14);
        printf("%u ", d.bits.b13);
        printf("%u ", d.bits.b12);
        printf("%u ", d.bits.b11);
        printf("%u ", d.bits.b10);
        printf("%u ", d.bits.b9);
        printf("%u ", d.bits.b8);
        printf("%u ", d.bits.b7);
        printf("%u ", d.bits.b6);
        printf("%u ", d.bits.b5);
        printf("%u ", d.bits.b4);
        printf("%u ", d.bits.b3);
        printf("%u ", d.bits.b2);
        printf("%u ", d.bits.b1);

    

}


int main(){
    D d;
    D1 d1;
    printf("Input double:\n");
    scanf("%lf %lf", &(d1.d),  &(d.d));
    print_bits(d);
    printf("\n");
    printf("SIGN: %u\n EXPONENT: %u\n MANTISSA: %lu\n", d1.bits.sign, d1.bits.exp, d1.bits.mantissa);
    return 0;
}
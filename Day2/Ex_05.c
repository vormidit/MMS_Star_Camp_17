#include<stdio.h>
#include<stdint.h>


int main(int argc, char* argv[]){


    char c;
    int  i;
    short s;
    long l;
    long long ll;
    float f;
    double d;

    printf("Size of char: %lu bytes\n", sizeof(c));
    printf("Size of short: %lu bytes\n", sizeof(s));
    printf("Size of int: %lu bytes\n", sizeof(i));
    printf("Size of long: %lu bytes\n", sizeof(l));
    printf("Size of long long: %lu bytes\n", sizeof(ll));
    printf("Size of float: %lu bytes\n", sizeof(f));
    printf("Size of double: %lu bytes\n", sizeof(d));

    printf("\n");

    //Additional data types

    printf("Size of void int8_t: %lu bytes\n", sizeof(int8_t));
    printf("Size of void uint8_t: %lu bytes\n", sizeof(uint8_t));
    printf("Size of void int16_t: %lu bytes\n", sizeof(int16_t));
    printf("Size of void int32_t: %lu bytes\n", sizeof(int32_t));
    printf("Size of void int64_t: %lu bytes\n", sizeof(int64_t));

    return 0;
}
#include<stdio.h>
#include<inttypes.h>

typedef struct A{
    unsigned int a : 3;
    signed int b : 7;
    int c : 5;
   // unsigned int d : 20;
}A;




int main(){
    A a;
    a.a = 4;
    a.b = -63;
    a.c = 2;
    printf("%ld\n", sizeof(A));
    return 0;
}
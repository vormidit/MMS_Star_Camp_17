#include <limits.h>
#include<stdio.h>
#include<inttypes.h>

typedef union A{
    unsigned int ui;;
    char bytes[4];
    

}A;

void printBytes(A a){

    for(size_t i = 0; i < 4; i++){
        printf("%02x  ", a.bytes[i]);
    }
    printf("\n");
}

int main(){
    A u1;

    u1.ui = 254;
    printBytes(u1);
    u1.ui = UINT_MAX - 2;
    printBytes(u1);
    u1.ui = 9;
    printBytes(u1);

    return 0;
}
#include<stdio.h>
#include<string.h>
#include<inttypes.h>



int main(){

    double a = -3.141516;
    uint64_t b;
    memcpy(&b, &a, 8);
    for(size_t i = 64; i >= 0; i-- ){
        printf("%d", !!(b & (1ULL << (i-1))));
    }
    b = b & !(1ULL << 63);
    memcpy(&a ,&b, 8);
    printf("\n");
    for(size_t i = 64; i > 1; i-- ){
        printf("%d", !!(b & (1ULL << (i-1))));
    }

    return 0;
}
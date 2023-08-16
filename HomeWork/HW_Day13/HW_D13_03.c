#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define MAX(x, y, z)  ((x > y)?x:y) > z?((x > y)?x:y): z

#define MIN(x, y, z)  ((x < y)?x:y) < z?((x < y)?x:y): z

#define SETBIT(mask, bit)   (mask |= (1ULL << bit))

#define CLEARBIT(mask, bit)  (mask &= ~(1ULL << bit))

#define INVERSEBIT(mask, bit)  (mask ^= (1ULL << bit))

#define CHECKBIT(mask, bit)  !!(mask & (1ULL << bit))

#define SWAP(a, b) {a=a+b; b=a-b; a=a-b;}


int main(){
    int a=4, b=5;
    SWAP(a,b);
    printf("%d   %d\n", a, b);
    printf("%d\n", CHECKBIT(128, 7));
    uint8_t mask =64, mask1 = 255, mask2=128;
    INVERSEBIT(mask, 6);
    printf("%d\n", mask);
    CLEARBIT(mask1, 1);
    printf("%d\n", mask1);
    SETBIT(mask2, 5);
    printf("%d\n", mask2);
    printf("%d\n",  MAX(12,21,10));
    printf("%d\n",  MIN(12,21,10));
    return 0;
}
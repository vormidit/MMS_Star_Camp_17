/*2.1 (3т.) Създайте следната функция:

unsigned onesCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);

Функцията връща общия брой на битовете, които са ‘1’ във всички маски. 
Направете примерно извикване на функцията.*/

#include<stdio.h>
#include<inttypes.h>
unsigned onesCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4) {
    unsigned cnt = 0;
    // while(mask1) {
    //     cnt += mask1&1;
    //     mask1 >>= 1;
    // }

    for(size_t i = 0; i < 64; i++) {
        cnt += !!(mask1 & (1ULL << i));
        cnt += !!(mask2 & (1ULL << i));
        cnt += !!(mask3 & (1ULL << i));
        cnt += !!(mask4 & (1ULL << i));
    }
    return cnt;
}
int main() {
    printf("%u", onesCount(1ULL << 38, 7, 0, 255));
    return 0;
}
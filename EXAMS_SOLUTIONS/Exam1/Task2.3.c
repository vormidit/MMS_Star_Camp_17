/* Създайте следната функция:

void mirrorBits(uint16_t* mask);

Функцията обръща огледално битовете на маската mask. Направете примерно извикване на функцията.
Напр.   0b1111111100000000  -> 0b0000000011111111*/

#include<stdio.h>
#include<inttypes.h>
void swap_bits(uint16_t * mask, size_t i, size_t j) {
    int i_val = !!(*mask & (1ULL << i)),
        j_val = !!(*mask & (1ULL << j));
    if((i_val && j_val) || (!i_val && !j_val)) return;
    if(i_val && !j_val) {
        *mask = *mask|(1ULL << j); // setbit(*mask, j)
        *mask = *mask&(~(1ULL << i)); // clearbit(*mask, i)
    }
    if(!i_val && j_val) {
        *mask = *mask|(1ULL << i); // setbit(*mask, i)
        *mask = *mask&(~(1ULL << j)); // clearbit(*mask, j)
    }
}
void mirror_bits(uint16_t *mask) {
    for(size_t i = 0; i < 8; i++) {
        swap_bits(mask, i, 15-i);
                    //  0  15
                    //  1  14
                    //  2  13
                    //  3  12
                    //  4  11
    }
}
int main () {
    uint16_t A = 0b1111111100000000;
    mirror_bits(&A);
    printf("%d", A);
    // 255 = 0b0000000011111111
    return 0;
}


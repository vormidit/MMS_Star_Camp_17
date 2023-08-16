/*Създайте следната функция:

void flipOddBits(uint64_t* mask);

Функцията инвертира (преобръща) всеки нечетен бит от маската mask. 
Броенето на битовете да се брои като най-младшия бит се приеме за номер 0. 
Направете примерно извикване на функцията.
Напр. 0b0000000000000000000000000000000000000000000000000000000000000000 -> 
0b101010101010101010101010101010101010101010101010101010101010*/

#include<stdio.h>
#include<inttypes.h>
#define flip_bit(X, i) X = X ^ (1ULL<<i)

// flip_bit(255, 4)
// 1ULL << 4 
// 00010000
//
// 255 = 11111111
// 
// 11111111
// ^
// 00010000
// 11101111

// flip_bit(0, 4)
// 0 = 00000000
// 00000000
// ^
// 00010000
// 00010000

// uint8_t X
// ^
// 10101010
// същото като да извикаме
// flip_bits(X, 1)
// flip_bits(X, 3)
// flip_bits(X, 5)
// flip_bits(X, 7)

// 11111111
// ^
// 10101010
// =
// 01010101
void flip_odd_bits(uint8_t *mask) {
    // *mask ^= 0b10101010; // solution 1

    // solution 2
    for(size_t i = 0; i < 8; i++) {
        if(i%2 == 1) {
            flip_bit(*mask, i);
        }
    }


}
int main() {
    uint8_t A = 255;
    flip_odd_bits(&A);
    printf("%u", A);
    return 0;
}
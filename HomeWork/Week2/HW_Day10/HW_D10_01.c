#include<stdio.h>
#include<stdint.h>

void swapBytes(uint16_t* word){
    if(((*word & (1ULL << 15)) && (*word & 1ULL)) || (!(*word & (1ULL << 15)) && !(*word & 1ULL))){
        return;
    }
    if(*word & (1ULL << 15)){
        *word &= ~(1ULL<<15);
        *word |= 1ULL;
    }else{
        *word |= (1ULL<<15);
        *word &= ~(1ULL);
    }
}


int main(){

    uint16_t word = 0b0000011101110001;
    printf("%x\n", word);
    swapBytes(&word);
    printf("%x\n", word);



    return 0;
}
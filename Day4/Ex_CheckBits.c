#include<stdio.h>
#include<stdint.h>


//Прототипи на функциите
uint16_t SetBit(uint16_t mask, int bit);
uint16_t CheckBit(uint16_t mask, int bit);
uint16_t ClearBit(uint16_t mask, int bit);
void PrintBits(uint16_t mask);

//Главна функция
int main(int argc, char* argv[]){

    uint16_t mask = 0xffff;//Нашата маска 1111 1111 1111 1111
   
   
    PrintBits(mask);
    printf("\n");
    printf("Clear Bit 15\n");
    mask = ClearBit(mask, 15);
    
    PrintBits(mask);
    printf("\n");
    printf("Set again 15 bit\n");
    mask = SetBit(mask, 15);
    
    PrintBits(mask);
    printf("\n");
    printf("Clear Bit 8\n");
    mask = ClearBit(mask, 8);
    
    PrintBits(mask);



    





    return 0;  
}//end of main

//SetBit function
uint16_t SetBit(uint16_t mask, int bit){

    return mask | (1 << bit);
}

//CheckBit function
uint16_t CheckBit(uint16_t mask, int bit){

    return (mask & (1 << bit))? 1 : 0;
}

//ClearBit function
uint16_t ClearBit(uint16_t mask, int bit){

    return mask & ~(1 << bit);
}

//PrintBits function
void PrintBits(uint16_t mask){

    for(int i = 16 - 1; i >= 0; i--){
        printf("%d ", CheckBit(mask, i));
    }
}


#include<stdio.h>
#include<stdint.h>


unsigned onesCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);
void flipOddBits(uint64_t* mask);
void mirrorBits(uint16_t* mask);

unsigned onesCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4){

         unsigned count = 0;
         for(int i = 0; i < 64; i++){

            if((mask1 & (1 << i))? 1 : 0) count++;

         }
         for(int i = 0; i < 32; i++){

            if((mask2 & (1 << i))? 1 : 0) count++;
            

         }
         for(int i = 0; i < 16; i++){

            if((mask3 & (1 << i))? 1 : 0) count++;

         }
         for(int i = 0; i < 8; i++){

            if((mask4 & (1 << i))? 1 : 0) count++;

         }

    return count;     

     
  

}


void flipOddBits(uint64_t* mask){

  for(int i = 1; i < 65 ; i++){

    if((i % 2) == 0 && (*mask & (1 << i))? 1 : 0){

        *mask = *mask & (0ULL << i);


    }
    else if((i % 2) == 0 && (*mask & (0 << i))? 1 : 0){

        *mask = *mask & (1ULL << i);
    }
}




}

void mirrorBits(uint16_t* mask){
    char bit_arr[16];

    int i =0;
    for(; i < 8; i++){

        if (*mask & (1 << i)) {

            bit_arr[i] = 1;
         

        }
        else{
            bit_arr[i] = 0;
        }
    }
    for(; i <16; i++){

        if (*mask & (1 << i)) {

            bit_arr[i] = 1;
         

        }
        else{
            bit_arr[i] = 0;
        }

    }
    i = 0;
    int j = 15;
    for(; i <16 & j > 0; i++, j--){

        if (bit_arr[i] == 1) {

            *mask = 1 << j;
         

        }
        else{
            *mask = 0 << j;
        }

    }



}

int main(){

uint64_t mask1 = 0xffffffffffffffff;
uint32_t mask2 = 0xffffffff;
uint16_t mask3 = 0xffff;
uint8_t mask4 = 0xff;

uint16_t *mask = &mask3;
mirrorBits(mask);
printf("%d\n", mask3);

//printf("Броя на сетнатите битове общо е %u\n",onesCount(mask1, mask2, mask3,  mask4));


//uint64_t num = 0ULL;

//uint64_t *pnum = &num;
//flipOddBits( pnum);






}
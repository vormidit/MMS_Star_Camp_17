#include<stdio.h>
#include<stdint.h>



unsigned onesCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4){
    unsigned cnt;

//    while(mask1){
 //       cnt += mask1&1;
 //       mask1 >>= 1;
 //   }

    for(size_t i =0; i < 64; i++){
        cnt += !!(mask1&(1ULL<<i));
        cnt += !!(mask1&(1ULL<<i));
        cnt += !!(mask1&(1ULL<<i));
        cnt += !!(mask1&(1ULL<<i));
    }
  return cnt;
}








int main(){

   printf("%d\n", onesCount(1ULL<<38, 7, 0, 255));
   return 0;

}
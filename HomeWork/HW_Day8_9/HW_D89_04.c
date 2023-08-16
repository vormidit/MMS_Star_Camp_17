#include<stdio.h>
#include<stdint.h>


int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    if(*maskArr && nitems > 0){

    
        for(size_t i = 0; i < nitems; i++){
        maskArr[i] &=  ~(1U << bit_index);
        }

        return 0;
    }
    return -1;
}
int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    if(*maskArr && nitems > 0){

    
        for(size_t i = 0; i < nitems; i++){
        maskArr[i] |=  (1U << bit_index);
        }

        return 0;
    }
    return -1;



}
int checkBits(uint32_t* maskArr, size_t len, size_t bit_index){
    size_t cnt0 = 0, cnt1 = 0;
    if(*maskArr && len > 0){

    
        for(size_t i = 0; i < len; i++){
            if((maskArr[i] & (1U << bit_index))? 1 : 0){
                cnt1++;
            }else{
                cnt0++;
            }
        
        
        }

        if(cnt0 == len){
            return 0;
        }
        return (cnt1 == len)? 1 : -1;
    }
    
    

   return -1;

}

int main(){

    uint32_t maskArr[]={0xfffffff8, 0xfffffff8, 0xfffffff8};
    size_t N = sizeof(maskArr)/sizeof(maskArr[0]), 
          bit = 2;
    int res = checkBits(maskArr, N, bit);
    printf("Check bits result for bit %lu: %d\t", bit, res);
    printf("\n");
    for(size_t i = 0; i < N; i++){
        printf("%x\t", maskArr[i]);
    }
    printf("\n");
    res = clearBits(maskArr, N,  3);
    printf("Clear bits result for bit %d: %d\n",3, res);
    for(size_t i = 0; i < N; i++){
        printf("%x\t", maskArr[i]);
    }
    printf("\n");
    res = setBits(maskArr, N,  3);
    printf("Set bits result for bit %d: %d\n",3, res);
    for(size_t i = 0; i < N; i++){
        printf("%x\t", maskArr[i]);
    }
    printf("\n");

    return 0;
}
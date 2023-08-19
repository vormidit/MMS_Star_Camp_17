#include <stdint.h>
#include<stdio.h>


typedef struct Point {
    double x;
    double y;
    double z;
} Point;


typedef struct Human {
    double weight_kg;
    uint16_t height_cm;
} Human;


typedef struct float_bits{
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int b8 : 1;
    

}float_bits;

typedef union F{
    float c;
    float_bits bits;
    

}F;


int cmpUint64(const void *elem1, const void *elem2){

    return *(uint64_t*)elem1 > *(uint64_t*)elem2 ? -1 : 1;

}
int cmpChar(const void *elem1, const void *elem2){

    return *(int*)elem1 > *(int*)elem2 ? -1 : 1;

}

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)){

     void *temp_max = arr;
    for(size_t i = 0; i < n; i++){
        
        if(cmp((char*)arr+i*elem_s, temp_max) == -1){
            	
            temp_max = (char*)arr+i*elem_s;
            
        } 
    }

    return temp_max;
}



int main(){

    uint64_t arr[] = {1,2,1,3,5,11,12,13,2,100,22};
	uint64_t* max_uint64 = findMax(arr, sizeof(arr)/sizeof(uint64_t), sizeof(uint64_t), cmpUint64);
	printf("Max elem UINT_64: %lu\n", *max_uint64);
	return 0;


    return 0;
}
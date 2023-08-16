#include<stdio.h>


int get_value_offset(int* , int offset);//Prototype


int get_value_offset(int* pa, int offset){

    int* new_ptr = pa + offset;

    return *new_ptr;
   
}


int main(int argc, char* argv[]){
    
    int array[] = {2,4,6,23,45,67,12,34};
    int* arr_ptr = array; 
    int offset = 3;

    int offset_value = get_value_offset(arr_ptr, offset);

    printf("Value at index %d is %d\n", offset, offset_value);
    
    

    return 0;
}
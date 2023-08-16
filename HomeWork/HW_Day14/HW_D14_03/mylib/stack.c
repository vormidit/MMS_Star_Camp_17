#include<stdio.h>
#include<stdlib.h>
#include"stack.h"



size_t capacity, cur_elem_count;

Data* init_stack_arr(size_t max_elem_count){   
    capacity = max_elem_count;
    Data *pD = malloc(sizeof(Data)*max_elem_count);
    cur_elem_count = 0;
    return pD;

}

int push(Data elem, Data *pData){
    if(cur_elem_count == capacity){
        return -1;
    }else{

        *(pData + cur_elem_count) = elem;
        cur_elem_count++;
        return 0;
    }
    

}

int pop(Data *result, Data *pData){
    if(cur_elem_count == 0){
        return -1;
    }else{

        *result = *(pData + cur_elem_count -1);
        (pData+cur_elem_count-1)->data = 0;
        cur_elem_count--;
        return 0;
    }

}

void print_elems(Data *pData){

    for(size_t i = 0; i < capacity; i++){
        printf("%d  ", pData[i].data);
    }
}
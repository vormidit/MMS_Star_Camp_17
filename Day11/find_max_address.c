#include<stdio.h>


void find_max_address(int arr[], size_t n, int *max_elem, int **max_ptr){

    for(size_t i = 0; i < n; i++){
        if(arr[i] > *max_elem){
            *max_elem = arr[i];
            *max_ptr = arr + i;
        }
    }
    

}

int main(){

    int arr[] = {1,2,3,4,5,6};
    int *max_ptr;
    int max_elem = 0;
    find_max_address(arr, 6, &max_elem, &max_ptr);
    printf("MAX VALUE %d\n", max_elem);
    printf("MAX ADDRESS %p\n", max_ptr);
    printf("MAX VALUE %d\n", *max_ptr);

}
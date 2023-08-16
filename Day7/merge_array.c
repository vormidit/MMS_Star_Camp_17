#include<stdio.h>

void merge(int *arr1, int n1, int *arr2, int n2, int *dest);


void merge(int *arr1, int n1, int *arr2, int n2, int *dest){

    size_t i1 = 0, i2 = 0;

    while(i1 < n1 && i2 < n2){

        if(arr1[i1] < arr2[i2]){
            *(dest++) = arr1[i1];
            i1++;
        }else{
            *(dest++) = arr2[i2];
            i2++;
        }
    }
    
    if(i1 < n1){
        for(size_t i = i1; i < n1; i++){
            *(dest++) = arr1[i];
        } 

    }else{
        for(size_t i = i2; i < n2; i++){
            *(dest++) = arr2[i];
        } 

    }


    



}


int main(){

    int arr1[]= {1,5,8};
    int arr2[]= {3,5,10,14, 18};

    int dest[20];
    merge(arr1, 3, arr2, 5, dest);
    
    for(size_t i = 0 ; i < 8; i++){
        printf("%d ", dest[i]);
    }
    






    return 0;
}
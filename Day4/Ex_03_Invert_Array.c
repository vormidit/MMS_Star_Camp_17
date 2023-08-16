#include<stdio.h>

 void invertArray(int [], int);
 void swapArray(int [], int, int);

void swapArray(int arr[], int start, int end){

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = arr[temp];
   
}




void invertArray(int arr[], int size){
    int start = 0; 
    int end = size - 1;

    while(start < end){

        swapArray(arr, start, end);
        start++;
        end--;
    }
}

//Главна функция
int main(int argc, char* argv[]){
    
    
    int myarr[] = {1,2,3,4,5, 6};
    
    int size = sizeof(myarr)/sizeof(myarr[0]);
    printf("Normal array is:\n");
    for(int i=0; i < size; i++){
        printf(" %d\n", myarr[i]);

    }

    invertArray(myarr, size);


    printf("Inverted array is:\n");
    for(int i=0; i < size; i++){
        printf(" %d\n", myarr[i]);

    }


    return 0;
}
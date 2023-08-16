#include<stdio.h>

int binarySearch(int arr[], int low, int high, int key);


int binarySearch(int arr[], int low, int high, int key){

    while(low <= high){
        int middle = low + (high - low) / 2;

        if(arr[middle] == key) return key;

        if(arr[middle] < key){
            low = middle +1;
        }else{
            high = middle -1;
        }
    }

    return -1;
}

int main(int argc, char* argv[]){

    int my_arr[] = {3, 7,14,19,21,81};
    int size = sizeof(my_arr)/sizeof(my_arr[0]);

    int key;
    printf("Input your element to find in array:\n");
    scanf("%d", &key);


    int result = binarySearch(my_arr, 0, size-1, key);

    if(result == -1){
        printf("Element not found!\n");
    }else{
        printf("Element %d found!\n", result);
    }


    return 0;
}//end of main
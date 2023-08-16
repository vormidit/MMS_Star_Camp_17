#include<stdio.h>

int linearSearch(int arr[], int size, int key);


int linearSearch(int arr[], int size, int key){

    for(int i=0; i < size; i++){

        if(arr[i] == key) return i;
    }
    return -1;
}

int main(int argc, char* argv[]){

    int my_arr[] = {3, 7,4,19,21,81};
    int size = sizeof(my_arr)/sizeof(my_arr[0]);

    int key;
    printf("Input your element to find in array:\n");
    scanf("%d", &key);

    int result = linearSearch(my_arr, size, key);

    if(result == -1){
        printf("Element not found!\n");
    }else{
        printf("Element found at index %d!\n", result);
    }


    return 0;
}//end of main
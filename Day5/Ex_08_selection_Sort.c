#include<stdio.h>
void selectionSort(int arr[], int size);


void selectionSort(int arr[], int size){

    for(int i =0 ; i < size - 1; i++){

        int min_index = i;
        for(int j = i +1; j < size; j++){

            if(arr[j] < arr[min_index]) min_index = j;
        }

        if(min_index != i){
            arr[i] = arr[i] + arr[min_index];
            arr[min_index] = arr[i] - arr[min_index];
            arr[i] = arr[i] - arr[min_index];

        }
    }
}

int main(int argc, char* argv[]){

    int my_arr[] = {54, 7,66,1,21,3, 23,122,44,
    65,18,34,22};
    
    int size = sizeof(my_arr)/sizeof(my_arr[0]);

    printf("Before sort\n");
    for(int i = 0 ; i < size; i++){

        printf("Index %d element %d\n", i, my_arr[i]);
    } 

    selectionSort(my_arr, size);//Sorting function

    printf("After sort\n");
    for(int i = 0 ; i < size; i++){

        printf("Index %d element %d\n", i, my_arr[i]);
    }
    

    return 0;
}//end of main
#include<stdio.h>
void bubbleSort(int arr[], int size);


void bubbleSort(int arr[], int size){

    int swapped, counter = 0;

    do{

       swapped = 0;//Initialize swapp to false

       for(int i = 0; i < size -1 - counter; i++){

            if(arr[i] > arr[i+1]){

                arr[i] = arr[i] + arr[i+1];
                arr[i+1] = arr[i] - arr[i+1];//Swapping 
                arr[i] = arr[i] - arr[i+1];

                swapped = 1;//Initialize swapp to true
                
            }
        
          
        }
        ++counter;

        
    }while(swapped);
}

int main(int argc, char* argv[]){

    int my_arr[] = {54, 7,66,1,21,3, 23,122,44,
    65,18,34,22};
    int size = sizeof(my_arr)/sizeof(my_arr[0]);

    printf("Before sort\n");
    for(int i = 0 ; i < size; i++){

        printf("Index %d element %d\n", i, my_arr[i]);
    } 

    bubbleSort(my_arr, size);//Sorting function

    printf("After sort\n");
    for(int i = 0 ; i < size; i++){

        printf("Index %d element %d\n", i, my_arr[i]);
    }
    

    return 0;
}//end of main
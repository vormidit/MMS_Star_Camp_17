#include<stdio.h>

void myMap(int arr[], int n, int (*f)(int));
int  arrPow(int);

int arrPow(int num){

    return num * num;
}

int inputArr(int a){

     scanf("%d", &a);
     return a;

}
int printArr(int a){

     printf("%d", a);
     return a;

}

void myMap(int arr[], int n, int (*f)(int)){

     for(size_t i =0; i < n; i++){
        arr[i] = f(arr[i]);
     }

}

int main(){

    int arr[100];
    

    myMap(arr, 5, inputArr);
    myMap(arr, 3, printArr);
    myMap(arr, 5, arrPow);



    return 0;
}
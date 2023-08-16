#include<stdio.h>

void subseq(int arr[], int n, int dest[], int *new_n);

void subseq(int arr[], int n, int dest[], int *new_n){

    for(int i=0 ; i < n; i++){

        if(arr[i] > arr[i+1]);

    }




}

int main(){

int arr[100];
int n;
int new;
int dest[100];
int *new_n = &new;

printf("Въведте N:\n");
scanf("%d", &n);




for(int i =0 ; i<n; i++){
   printf("Въведте число:\n");
   scanf("%d", &arr[i]);


}

subseq(arr, n, dest, new_n);
printf("Броя на новия масив е  %d:\n", *new_n);
for(int i =0 ; i<n; i++){
   printf("Arr[%d]: = %d\n", i, dest[i] );
   


}





}


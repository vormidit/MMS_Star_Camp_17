#include<stdio.h>


int mult(int a, int b){

     return a*b;

}
int add(int a, int b){
     return a + b;

}

int aggregate(int *arr, int n, int init, int (*f)(int, int)){
    int res = init;
    size_t i =0 ;
    while(i < n){
        res = f(res, arr[i]);

        i++;
    }
    

    return res;
}

int main(){

    int arr[]= {1,2,3,4,5};

    printf("%d\n", aggregate(arr, 5, 15, add));
    printf("%d\n", aggregate(arr, 5, 9, mult));




    return 0;
}
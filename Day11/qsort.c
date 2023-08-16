#include<stdio.h>
#include<stdlib.h>

int cmp_int(const void *p1, const void *p2){

   return *(int*)p1 - *(int*)p2;

}


int main(){

    int arr[] = {5,6,3,78,23,56,2,4,7};
    qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), cmp_int);

    for(size_t i = 0; i < 9; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}
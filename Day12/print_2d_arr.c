#include<stdio.h>
#include<stdint.h>

void print_row(int (*arr)[4]){
    for(size_t i = 0; i<3*4; i++){
        printf("%d\n", *(arr)[i]);
    }
    printf("\n");
}

int main(){

    int arr[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int *p = arr[0];
    for(size_t i = 0; i<3*4; i++){
        printf("%d\n", p[i]);
    }
}
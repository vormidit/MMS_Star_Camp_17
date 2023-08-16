#include<stdio.h>

void swap_pointers(int*, int*);


//Swap  функция
void swap_pointers(int* ptr1, int* ptr2){
   
   int temp_ptr = *ptr1;

   *ptr1 = *ptr2;

   *ptr2 = temp_ptr;


}

//Главна функция
int main(int argc, char* argv[]){

    int a = 5, b =10;

    int* pa = &a;
    int* pb = &b;

    printf("Before swapping: a: %d, b: %d\n", *pa, *pb);

    swap_pointers(pa, pb);

    printf("After swapping: a: %d, b: %d\n", *pa, *pb);

return 0;

}
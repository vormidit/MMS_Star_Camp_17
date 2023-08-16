#include<stdio.h>

//Прототипи на функциите
void print_myname();
int devide2num(int a, int b);

//Без параметри и връщана ст-ст
void print_myname(){

    printf("Angel\n");
}



//С параметри, но без връщана ст-ст
void mult2num(int a, int b){

    int res = a * b;
    printf("Result: %d\n", res);
}


//С параметри и връщана стойност
int devide2num(int a, int b){

    return  a / b;
    
}


int main(int argc, char* argv[]){

    print_myname();
    mult2num(12,21);
    int result = devide2num(21,7);
    printf("Result from devide: %d\n", result);

   
}
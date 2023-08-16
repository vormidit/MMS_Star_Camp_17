#include<stdio.h>


//Главна функция
int main(int argc, char* argv[]){
    
    
    int *pc, c;

    c  = 22;

    printf("Our address for num c is: %p\n", &c); 
    printf("Value c is: %d\n", c);             
    
    pc = &c;

    printf("Address of pointer is: %p\n", pc); 
    printf("Content of pointer is: %d\n", *pc); 

    c  = 11;

    printf("Address of pointer is: %p\n", pc); 
    printf("Content of pointer is: %d\n", *pc);

    *pc = 7;

    printf("Value of c: %p\n", &c); 
    printf("Content of c: %d\n", c);


    return 0;
}
#include<stdio.h>

void printHeight(int a){
    printf("My heght is %d", a);
}

void printMsg(void (*f)(int)){

    printf("Hello");
    f(10);
}

int main(){

    void (*f)(int) = printHeight;
    printf("%p\n", f);
    printf("%lu\n", sizeof(f));
    f(20);
    printMsg(printHeight);

    return 0;
}
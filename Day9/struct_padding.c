#include <stdio.h>
#include <string.h>



typedef struct A{
    char a;//1byte
    //3 bytes padding
    int b;//4 bytes
}A;


typedef struct B{
    int a;//1byte
    char b;//4 bytes
    //3 bytes padd
}B;


typedef struct C{
    double a;//8 bytes
    int b;//4 bytes
    //4 bytes padding
}C;

typedef struct D{
    char a;
    double b;
}D;


int main(){
    printf("Sizeof A: %lu", sizeof(A));

    return 0;
}
#include <stdio.h>

int add(int,int);
int mult(int,int);

int add(int a, int b){
    return a + b;
}

int mult(int c, int d){

    return c * d;
}

int main(int argc, char* argv[]){

    int (*addptr)(int,int);//Дефиниране на указател към функция
    int (*multptr)(int,int);

    addptr = add;//Присвояване на адреса на функцията на указателя към нея
    multptr = mult;

    int a, b;
    printf("Въведете a: \n");
    scanf("%d", &a);
    printf("Въведете b: \n");
    scanf("%d", &b);

    printf("Извикване без указател: %d\n", add(a, b));

    printf("Извикване чрез указател: %d\n", (*addptr)(a,b));

    printf("Извикване чрез указател (кратък запис): %d\n", addptr(a,b));

    printf("Извикване чрез указател (умножение): %d\n", (*multptr)(a,b));







    return 0;
}

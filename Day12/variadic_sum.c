#include<stdio.h>
#include<stdarg.h>

int sum_variadic(int count, ...){
    va_list args;
    int sum = 0;
    va_start(args, count);
    for(size_t i =0; i < count; i++){
        sum += va_arg(args, int);
    }
   



    va_end(args);
    return 0;
}

int main(){
    printf("%d\n", sum_variadic(5, 10, 20,30,40,50));
    printf("%d\n", sum_variadic(3, 10, 20,30));

}
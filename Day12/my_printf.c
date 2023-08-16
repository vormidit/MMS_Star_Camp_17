#include<stdio.h>
#include<stdarg.h>


int my_printf(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    va_list args2;
    va_copy(args2, args);
    printf("[CUSTOM PRINTF]");
    vprintf(fmt, args);

    va_end(args);
    return 0;
}

int main(){
    
    my_printf("%d %d %d\n", 30,40,50);
    my_printf("%s %x\n", "HELLO",12);
    return 0;
}
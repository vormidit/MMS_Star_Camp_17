#include<stdio.h>
#include<stdarg.h>
#include<time.h>

int printf_time(const char *format, ...){
    va_list args;
    va_start(args, format);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("[%d.%02d.%02d - %02d:%02d:%02d]\n",tm.tm_mday  , tm.tm_mon + 1,tm.tm_year+ 1900 , tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    vprintf(format, args);

    va_end(args);
    return 0;
}

int main(){

    printf_time("%d %d\n", 10, 20);

    return 0;
}
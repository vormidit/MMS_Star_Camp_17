#include<stdio.h>
#include<string.h>
#include<stdarg.h>


int my_printf(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    size_t i = 0, sym_cnt = 0;
    size_t slen = strlen(fmt);
   
    for(;i < slen; i++){
        if(fmt[i] == '%'){
            if(fmt[i+1] == 'd'){
                putc(va_arg(args,int), stdout);
                 i += 1;
                sym_cnt++;
            }else if(fmt[i+1] == 'f'){
                putc(va_arg(args,double), stdout);
                i += 1;
                sym_cnt++;
            }else if(fmt[i+1] == 'c'){
                putc(va_arg(args,int), stdout);
                i += 1;
                sym_cnt++;
            }
        }else{
            putc(*(fmt+i), stdout);
            sym_cnt++;
        }
        

    }
    return sym_cnt;

}

int main(){
    int a = 1;
    float f = 3.14;

    my_printf("This is %d time %c symbol to be %f!", a, 'A', f);
    printf("\n");
    



    return 0;
}
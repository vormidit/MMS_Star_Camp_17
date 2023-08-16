#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* toUpper(const char* str){

    void *mem = malloc(sizeof(char)*(strlen(str)+1));
    char *pc = mem;
    while(*str){
        if(*str >= 'a' && *str <= 'z'){
            *pc = (*str) - 'a' + 'A';

        }else{
            *pc = *str;
        }

        pc += 1;
        str += 1;
        

    }

    return mem;

}

int main(){

    char *p_c  = toUpper("hello world1234");
    printf("%s\n", p_c);
    free(p_c);

    return 0;
}
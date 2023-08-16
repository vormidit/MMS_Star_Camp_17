#include <limits.h>
#include<stdio.h>
#include<string.h>

typedef struct A{
    
    char c;
    int i;
    
}A;


void print_bytes(const void *pm, int numBytes){
    char buff[numBytes];
    memcpy(buff, pm, numBytes);
    for(size_t i = 0; i < numBytes; i++){
        printf("%x ",(unsigned char) buff[i]);
    }
    printf("\n");
}

int main(){
    A a = {UCHAR_MAX, UINT_MAX-1};
    print_bytes(&a, sizeof(a));
    return 0;
}
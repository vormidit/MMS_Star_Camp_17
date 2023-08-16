#include <stdio.h>

void process(int,int (*)(int));
int mult(int);

void process(int data, int (*callback)(int)){
    int result = callback(data);
    printf("Резултат: %d\n", result);
}

int mult(int num){

    return num * 2;
}

int main(int argc, char* argv[]){
    

    process(17, mult);
    
    return 0;
}
#include<stdio.h>
#include <stdlib.h>
#include<string.h>


char * mallocHelloStr(){
    char *c = malloc(6*sizeof(char));
    strcpy(c, "Hello");

    return c;

}

int main(){
    char *str1 = mallocHelloStr();
    double *p = malloc(sizeof(double));
    *p = 13.8;
    printf("%lf", *p);

    free(p);
    free(str1);
}
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int triangle(double a, double b, double c, double *area, double *perimeter){

    if(a <= 0 || b <= 0 || c <= 0 || a+b < c || b+c <=a || c+a <= b){
        return -1;
    } 

    *perimeter = a + b + c;
    double HP = *perimeter / 2;
    *area = sqrt(HP * (HP - a) * (HP - b) * (HP - c) );

    return 0;
}



int main(int argc, char *argv[]){
    if(argc != 4){
        fprintf(stderr, "Invalid arguments!\n");
        return EXIT_FAILURE;
    }

    double a, b, c, A, P;

    sscanf(argv[1], "%lf", &a);
    sscanf(argv[2], "%lf", &b);
    sscanf(argv[3], "%lf", &c);

    if(triangle(a,b,c,&A, &P) == -1){
        printf("Невалидни данни!\n");

    }else{
        printf("Area:%lf  \n Perimeter:%lf\n", A, P);
    }


    return 0;
}
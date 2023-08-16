#include<stdio.h>
#include<stdlib.h>

int main(){

    void *p = malloc(sizeof(double));
    double *p_d = p;
    *p_d = 12.5;
    printf("%lf\n", *p_d);
    free(p_d);

    void *p2 = calloc(sizeof(double), sizeof(double));
    double *p_d2 = p2;
    printf("%lf\n", *p_d2);
    free(p2);

    void *p3 = malloc(sizeof(int)*100); 
    int *pi = p2;
    pi[0] = 123;
    pi[1] = 124;
    pi[3] = 125;
    void *pr = realloc(pi, sizeof(int)*50);
    int *pi2 = pr;
    printf("%d %d %d\n", pi2[0], pi2[1], pi2[3]);
    free(p3);
    free(pr);
    return 0;
}
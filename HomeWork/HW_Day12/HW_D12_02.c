#include<stdio.h>
#include<stdlib.h>


int main(){
 
        printf("Input n for elem count:\n");
        size_t n;
        scanf("%lu", &n);
        double *pd;
        pd = (double*) calloc(n, sizeof(double));
        if (pd == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
        }
        for (size_t i = 0; i < n; i++) {
            pd[i] = (double)(rand()%1000)/1000.;
        }
        printf("Input m:\n");
        size_t m;
        scanf("%lu", &m);
        pd = (double*) realloc(pd, (m+n) * sizeof(double));
        if (pd == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
        }
        for (size_t i = n; i < m; i++) {
            pd[i] = (double)(rand()%1000 + 1000)/1000.;
        }
        printf("Input p:\n");
        size_t p;
        scanf("%lu", &p);
        pd = (double*) realloc(pd, (p+m+n) * sizeof(double));
        if (pd == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
        }
        for (size_t i = m; i < p; i++) {
            pd[i] = (double)(rand()%1000 + 2000)/1000.;
        }

        printf("Your Array is:\n");
        for (size_t i = 0; i < n+m+p; i++) {
            printf("%.2lf ", pd[i]);
        }
        printf("\n");

        free(pd);

        return 0;

}
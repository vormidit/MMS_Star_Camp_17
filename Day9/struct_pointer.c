#include <stdio.h>
#include <string.h>



typedef struct Point{
    double x;
    double y;
}P;

void print(P *p){

    double *x_p = p;
    printf("%p  %p", x_p, p);
    printf("%lf\t", p->x);
    printf("%lf\n", p->y);

}



int main(){

    P p1 = {4.35, 7.34};

    print(&p1);

    return 0;
}
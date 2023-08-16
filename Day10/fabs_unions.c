#include<stdio.h>
#include<inttypes.h>

typedef union A{
    double d;
    uint64_t u;

}A;

int main(){
    A a;
    a.d = scanf("%lf", &(a.d));
    a.u = a.u & ~(1ULL << 63);
    printf("%lf\n", a.d);
    return 0;
}
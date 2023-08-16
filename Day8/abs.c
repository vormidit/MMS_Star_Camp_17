#include<stdio.h>
#include<stdint.h>

uint64_t my_abs(int64_t n){
    
    return n * !(!!(n&(1ULL << 63))) + ~(n-1)*!!(n&(1ULL << 63));//Ако числото е полож. то то ще се умножи с 1ца
    //   n>0 * 1                     +    нещо   *       0  = същото число
    //   n<0 * 0                     +  ч-то в прав код * 1 = ч. в прав код 

}

double my_fabs(double n){
    
    uint64_t l = *(uint64_t*)&n;
    l = l & ~(1ULL << 63);

   return *(double*)&l;


}




int main(){

    int64_t a;
    //scanf("%lu", &a);
    double b;
    scanf("%lf", &b);
    //printf("%lu", my_abs(a));
    printf("%.3lf\n", my_fabs(b));
}
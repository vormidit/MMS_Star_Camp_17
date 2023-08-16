#include<stdio.h>

int main(int argc, char* argv[]){

    
    unsigned int a, b;

    printf("Моля въведете числото a:\n");
    scanf("%d", &a);
    printf("Моля въведете числото b:\n");
    scanf("%d", &b);

    
    printf("a = %d, b = %d\n", a, b);
    printf("a&b = %d\n", a & b);//AND

    
    printf("a|b = %d\n", a | b);//OR

    printf("a^b = %d\n", a ^ b);//XOR

   
    printf("~a = %d\n", a = ~a);//NOT

    printf("~b = %d\n", b = ~b);//NOT

   
    printf("a<<1 = %d\n", a << 1);//LEFT SHIFT
    printf("b<<1 = %d\n", b << 1);//LEFT SHIFT

    printf("a>>1 = %d\n", a >> 1);//RIGHT SHIFT
    printf("b>>1 = %d\n", b >> 1);//RIGHT SHIFT

    


   
    return 0;
}

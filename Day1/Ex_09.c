#include <stdio.h>

int main(int argc, char* argv[]){
 int num1, num2, sum;
 
 printf("Enter first num:");
 scanf("%d", &num1);
 
 printf("Enter second num:");
 scanf("%d", &num2);
 
 sum = num1 + num2;
 printf("Sum of the two number: %d", sum);
    
 return 0;
}
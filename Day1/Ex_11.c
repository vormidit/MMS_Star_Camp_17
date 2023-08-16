#include <stdio.h>

int main(int argc, char* argv[]){
 double num1, num2, num3, average;
 
 printf("Enter first num:");
 scanf("%lf", &num1);
 
 printf("Enter second num:");
 scanf("%lf", &num2);
 
 printf("Enter third num:");
 scanf("%lf", &num3);

 average = (num1 + num2 + num3) / 3 ;
 printf("The average of %.2lf, %.2lf and %.2lf is %.2lf\n", num1, num2, num3, average);
    
 return 0;
}
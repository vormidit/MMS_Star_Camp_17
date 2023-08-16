#include <stdio.h>

double fahr_to_cels(double);//Protoype

int main(int argc, char* argv[]){
 double fahrenheit;
 
 printf("Enter temperature in fahrenheit:");
 scanf("%lf", &fahrenheit);
 printf("%.2lf°F is equal to %.2lf°C\n", fahrenheit, fahr_to_cels(fahrenheit));

    
 return 0;
}

double fahr_to_cels(double fahrenheit){
    
    double celsius = (fahrenheit - 32) * 5 / 9;

    return celsius;
}
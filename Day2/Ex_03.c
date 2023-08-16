#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[]){

    int number = 27;
    int base = 8;// Base in decimal 
    int result = 0;
    int placeValue = 0;//It is the position of digit in number

    while(number >0){

        int digit = number % base;
        result += digit * pow(base, placeValue);
        placeValue++;
        number /= base;
    }
    //printf("Result in decimal is: %d \n", result);
     printf("Result in octal is: %d  \n", result);
    return 0;
}
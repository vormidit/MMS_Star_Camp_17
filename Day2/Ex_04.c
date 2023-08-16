#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[]){

    int number = 48;
    int base = 2;// Base in decimal 


    while(number > 0){
       int bin_num;
       bin_num = number % base;
       printf("Binary: %d  \n", bin_num);//Pechatim ostatycite
       number /= base;
     }
   
    return 0;

}
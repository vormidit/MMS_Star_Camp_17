#include <stdio.h>

//Prototype of
int square(int num);

//Main
int main(int argc, char* argv[]){


    int num;
    printf("Input Number: ");
    scanf("%d", &num);//Read number from keyboard
    int result = square(num);

    printf("%d squared is %d \n", num, result);

}

//Declare and Define function
int square(int num){

    return num * num;
}
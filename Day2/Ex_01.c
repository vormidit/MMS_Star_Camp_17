#include <stdio.h>

int main(int argc, char* argv[]){
    char MyChar = 'a';
    int MyInt = 3;
    float MyFloat = 3.1415;
    double MyDouble = 0.656;
    _Bool MyBool = 1;
     
    printf("MyChar: %c \n", MyChar);
    printf("MyInt: %d \n", MyInt);
    printf("MyFloat : %f \n", MyFloat);
    printf("MyDouble : %lf \n", MyDouble);
    printf("MyBool : %d \n",   MyBool);

    //binary number 

    int binary_num = 0b1011;
    printf("MyBinary number: %d \n",   binary_num);

    //octal number
    int octal_num1 = 031;
    printf("MyOctal1 number: %d \n",   octal_num1); 
   
    return 0;
}
#include<stdio.h>


//Главна функция
int main(int argc, char* argv[]){

    char grade = 'A';

    switch (grade)
    {
    case 'A':
        printf("Excellent!\n");
        break;

    case 'B':
        printf("Very well!\n");
        break;

    case 'C':
        printf("Well done!\n");
        break;

    case 'D':
        printf("Good!\n");
        break; 

    case 'E':
        printf("Not Good!\n");
        break;

    case 'F':
        printf("Fail!\n");
        break;       
    
    default:{

        printf("Your grade is %c", grade);
    }

        break;
    }




}//end of main
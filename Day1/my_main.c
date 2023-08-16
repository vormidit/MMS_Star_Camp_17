// main.c
#include <stdio.h>
#include "my_math.h"


int main(int argc, char* argv[]) {

double num = 5.0;
double sq = square(num);
double cu = cube(num);


printf("The square of %f is %f.\n", num, sq);

printf("The cube of %f is %f.\n", num, cu);

return 0;
}//end of main

//Компилираме с команда: gcc  my_math.c my_main.c -lm -o my_program -Wall -Wextra -Werror
//Чрез процес на линкване
/*
gcc -c my_main.c -o my_main.o
gcc - c my_math.c -o my_math.o
gcc my_main.o my_math.o -lm -o my_program
*/
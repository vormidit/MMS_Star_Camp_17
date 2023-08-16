#include <stdio.h>


#define DEBUG

int main(int argc, char* argv[]) {
    #ifdef DEBUG

     printf("DEBUG mode is on \n");
    #else
    printf("DEBUG mode is off \n");
    #endif
return 0;
}
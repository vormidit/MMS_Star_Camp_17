#include <stdio.h>

//Prototype of
void myFunction(void);

void myFunction(void){
    int myVar = 5;//Local var
    printf("The value of myVar inside the myFunction() is %d \n", myVar);


}


//Main
int main(int argc, char* argv[]){
    myFunction();
    printf("The value of myVar inside the myFunction() is %d \n", myVar);


    return 0;

}
#include<stdio.h>


//Главна функция
int main(int argc, char* argv[]){
    
    
    int myarr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int myarr2[] = {3,67,24,18,44};

    //myarr
    for(int i = 0; i < 10; i++){
        printf("Value of index %d: %d\n", i,  *(myarr + i));
    }
     
    //myarr2
    printf("\n");
    for(int i = 0; i < sizeof(myarr2) / sizeof(myarr2[0]); i++){
        printf("Value of index %d: %d\n", i,  *(myarr2 + i));
    }
    


    return 0;
}
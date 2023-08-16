#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
//Създайте програма, която записва числа в бинарен файл. 
//Програмата приема filename и N като аргументи от командния ред. 
//Ако файлът с име filename съществува - съдържанието му се трие, 
//иначе - файлът се създава. Програмата записва N на брой числа от тип int във файла.


int main(){
    int curNum;
    unsigned long long sum = 0;
    int num_read;
    do{
        curNum = 0;
        num_read = read(STDIN_FILENO, &curNum, sizeof(curNum));
        printf("num_read: %3d, curNum(HEX): %10x, curNum(DEC): %d\n", num_read, curNum, curNum);
        sum += curNum;
    
    }while(num_read == sizeof(curNum));

    printf("Sum: %llu\n", sum);
    
   
    return 0;
}
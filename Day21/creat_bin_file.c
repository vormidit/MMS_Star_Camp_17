#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
//Създайте програма, която записва числа в бинарен файл. 
//Програмата приема filename и N като аргументи от командния ред. 
//Ако файлът с име filename съществува - съдържанието му се трие, 
//иначе - файлът се създава. Програмата записва N на брой числа от тип int във файла.


int main(int agrc, char *argv[]){
    if(agrc != 3){
        perror("No CL Args!");
        exit(-1);
    }
    char *s = argv[1];
    FILE *f1 = fopen(s, "w");
    if(!f1){
        perror("Error open file!");
        exit(-1);
    }
    long int N = strtol(argv[2], NULL, 10);
    if(N == 0) {
        perror("First arg must be number\n");
        exit(-1);
    }
    for(int i =0; i < N; i++){
        fwrite(&i, 1, sizeof(int), f1);
    }
    
    fclose(f1);
   
    return 0;
}
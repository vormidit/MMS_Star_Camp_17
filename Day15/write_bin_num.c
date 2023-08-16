#include<stdio.h>
#include<stdlib.h>


int main(int agrc, char *argv[]){
    if(agrc != 3){
        perror("No CL Args!");
        exit(-1);
    }
    char *s = argv[1];
    FILE *f1 = fopen(s, "w");
    if(!f1){
        perror("Error!");
        exit(-1);
    }
    int N = atoi(argv[2]);
    for(size_t i =0; i < N; i++){
        fwrite(&i, sizeof(size_t), 1, f1);
    }
    
    fclose(f1);
   
    return 0;
}
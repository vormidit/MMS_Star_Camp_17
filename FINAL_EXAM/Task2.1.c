#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>


int main(int argc, char *argv[]){

   if(argc != 3) {
        fprintf(stderr, "Argc invalid\n");
        exit(-1);
    }
    FILE* f1 = fopen(argv[1], "w");
    if(!f1) {
        perror("fopen error");
        exit(-1);
    }
    size_t N = atoi(argv[2]);
    unsigned long long i = 0;
    
    for(; i < N; i++) {
        fwrite(&i, sizeof(i), 1, f1);//Write numbers like binary 
    }
    fclose(f1);
    return 0;

}
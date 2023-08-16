#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argp) {
    // ./write_numbers numbers.txt 10000
    if(argc != 3) {
        fprintf(stderr, "Argc invalid\n");
        exit(-1);
    }
    FILE* f1 = fopen(argp[1], "w");
    if(!f1) {
        perror("fopen error");
        exit(-1);
    }
    size_t N = atoi(argp[2]);
    for(size_t i = 0; i < N; i++) {
        fwrite(&i, sizeof(i), 1, f1);//Write numbers like binary 
    }
    fclose(f1);
    return 0;
}
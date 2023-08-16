#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argp) {
    // ./write_numbers numbers.txt 10000
    if(argc != 3) {
        fprintf(stderr, "Argc invalid\n");
    }
    FILE* f1 = fopen(argp[1], "w");
    if(!f1) {
        perror("fopen error");
    }
    size_t N = atoi(argp[2]);
    for(size_t i = 0; i < N; i++) {
        fprintf(f1, "%lu ", i);//Write cur i to file but not binary
    }
    fclose(f1);
    return 0;
}
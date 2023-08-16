#include<stdio.h>
#include<stdlib.h>

int main(int agrc, char *argv[]){
    if(agrc != 2){
        perror("No CL Args!");
        exit(-1);
    }
    char *s = argv[1];
    FILE *f1 = fopen(s, "r");
    if(!f1){
        perror("Error!");
        exit(-1);
    }
    char c;
    int d = 0;
    size_t l;
    size_t sum =0;
    
    while(fscanf(f1, "%lu", &l) == 1){
        sum += l;
    }
    rewind(f1);
    while( (c = fgetc(f1)) != EOF){
        if(c == ' '){
            continue;
        }
        d += atoi(&c);
    }
    printf("Sum: %d\n", d);
    printf("Sum: %lu\n", sum);
    fclose(f1);
    return 0;
}
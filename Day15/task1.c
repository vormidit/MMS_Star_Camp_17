#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *f1 = fopen("test.txt", "r");
    if(!f1){
        perror("Error!");
        exit(-1);
    }
    char buf[100], c;
    size_t i =0;

    while((c = fgetc(f1)) != EOF){
        buf[i++] = c;
    };
    puts(buf);
    fclose(f1);
    return 0;

}
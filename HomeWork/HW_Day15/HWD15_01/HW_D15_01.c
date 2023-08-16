#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(int argc, char *argv[]){
    //0 arguments
    if(argc == 1){//Because name of function its 1st arg
        char buff[255];
        size_t i =0;
        while((buff[i++] = fgetc(stdin)) != '\n'){};
        puts(buff);
    }
    //1 argument
    else if(argc == 2){
        char *s = argv[1];
        FILE *f = fopen(s, "r");
        if(!f){
        perror("Error!");
        exit(-1);
        }
        char buf[255], c;
        size_t i =0;

        while((c = fgetc(f)) != EOF){
        buf[i++] = c;
        };
        puts(buf);
        fclose(f);

    //2 or more arguments
    }else{

        for(int i = 1; i < argc; i++){
            char *s = argv[i];
            FILE *f = fopen(s, "r");
            if(!f){
                perror("Error with opening files!");
                exit(-1);
            }
            char buf[500], c;
            size_t i =0;

            while((c = fgetc(f)) != EOF){
            buf[i++] = c;
            }
            fprintf(stdout, "%s", buf);
            fclose(f);
        }
        


    }



    return 0;
}
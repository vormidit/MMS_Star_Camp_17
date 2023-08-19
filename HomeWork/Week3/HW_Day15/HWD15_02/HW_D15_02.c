#include <errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


int cmp(const void *str1, const void *str2){
    return strcmp(*(const char**)str1,*(const char**)str2);
}

int main(int argc, char *argv[]){

    char s[50];
    printf("Input/create/ file name:\n");
    fscanf(stdin, "%s", s);
    if(!access(s, F_OK )){
        printf("File exist!, Create another!\n");
        exit(-1);
    }
    FILE *f = fopen(s, "w");
    if(!f){
        perror("Error opening file!");
        exit(-1);
    
    }else{
        int cnt = argc-1;
        qsort((argv+1), cnt, sizeof(char*), cmp);
        printf("\n");
         
        for(int i =1; i <= cnt; i++){
            fprintf(f, "%s\n", *(argv+i));
        }
        // char *buf[cnt];
        // for(int i =1; i <= cnt; i++){
        //     buf[i-1] = (char*)malloc(sizeof(char)*strlen(argv[i])+1);
        //     strcpy(buf[i-1], argv[i]);
        // }

        // qsort(buf, cnt, sizeof(char*), cmp);

        // for(int i =0; i < cnt; i++){
        //     fprintf(f, "%s\n", buf[i]);
        // }

        // for(int i =0; i < cnt; i++){
        //     free(buf[i]);
        // }

    
    }
    
    fclose(f);


    return 0;
}
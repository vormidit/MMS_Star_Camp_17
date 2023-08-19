#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<inttypes.h>
#include<sys/stat.h>



int main(int argc, char **argp){
    FILE *f;
    char s[50];
    sscanf(*(argp+1), "%s", s);
    
    if(!access(s, F_OK )){
        f = fopen(s, "r+");
        if(!f){
            perror("Error opening file!");
            exit(-1);
        }
    }else{
        f = fopen(s, "w+");
        if(!f){
        perror("Error opening file!");
        exit(-1);
        }
    }

    char input_string[30];
    char *pc_arr[3];
    uint8_t hex, text;
    printf("Input command to edit binary file:\n");
    while(fgets(input_string, 30, stdin)){
        
        printf("\n");
        
        
        char *ss = strtok(input_string, " ");
        pc_arr[0] = ss;
        int i = 1;
        while(ss != NULL){
            ss = strtok(NULL, " ");
            pc_arr[i++] = ss;
        }

        if(!strcmp(pc_arr[0], "d")){
            while(fread(&hex, sizeof(uint8_t), 1, f) == 1){
                printf("%x ", hex);
            }
            printf("\n");
        }
        rewind(f);
        
        if(!strcmp(pc_arr[0], "t")){
            while(fread(&text, sizeof(uint8_t), 1, f) == 1){
                printf("%c ", text);
            }
            printf("\n");
        }
        rewind(f);

        if(!strcmp(pc_arr[0], "a")){
            
            unsigned char new_byte;
            sscanf(pc_arr[1], "%2hhx", &new_byte);
            fseek(f, 0, SEEK_END);
            fwrite(&new_byte, sizeof(unsigned char), 1, f);
                
            printf("\n");
        }
        rewind(f);

        if(!strcmp(pc_arr[0], "c")){
            
            unsigned int s_index, e_index;
            sscanf(pc_arr[1], "%d", &s_index);
            sscanf(pc_arr[2], "%d", &e_index);
            printf("Start:%d End:%d", s_index, e_index);

            int to_trunc = e_index - (s_index+1);
            
            struct stat file_info;

            stat(*(argp+1), &file_info);
            unsigned int file_size = file_info.st_size;
            printf("File size:%d", file_size);

            
            for(size_t i = s_index+1; i < file_size-(e_index-(s_index+1) && e_index <= file_size); i++){
                uint8_t cur_read;
                fseek(f, e_index, SEEK_CUR);
                fread(&cur_read, sizeof(uint8_t), 1, f);
                rewind(f);
                fseek(f, i, SEEK_CUR);
                fwrite(&cur_read, sizeof(uint8_t), 1, f);
                rewind(f);
                e_index++;

            }

            truncate(*(argp+1), file_size-to_trunc);
              
            printf("\n");
            
        }
        rewind(f);

        if(!strcmp(pc_arr[0], "e")){
            
            int index;
            uint8_t new_byte;

            sscanf(pc_arr[1], "%d", &index);
            sscanf(pc_arr[2], "%2hhx", &new_byte);

            fseek(f, index, SEEK_CUR);
            fwrite(&new_byte, sizeof(uint8_t), 1, f);
                
            printf("\n");
        }
        rewind(f);

      
        
    }

    fclose(f);
    return 0;
}
#include <signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(){
    while(1){
    char line_buf[200];
    int char_c = 0;
    char cur_sym = '\0';
    while(cur_sym != '\n'){
        cur_sym = getc(stdin);
        line_buf[char_c++] = cur_sym;
    }
    line_buf[char_c -1] = '\0'; 
    fwrite(line_buf, sizeof(char), char_c, stdout);
    char *exec_argvp[10];
    
    exec_argvp[0] = strtok(line_buf, " ");

    for(int i = 1;exec_argvp[i-1] != NULL; i++){
        exec_argvp[i] = strtok(NULL, " ");
    }

    int pid = fork();
    
    if(pid == -1){
        perror("Could not work!\n");
        exit(-1);

    }else if(pid == 0){
        //cild
        execvp(exec_argvp[0], exec_argvp);
        perror("Exec failed!\n");
        exit(1);

    }else{

        //parent wait to child and print status code
        int wstatus;
        pid_t child_pid = wait(&wstatus);

        if(!WIFEXITED(wstatus)){
            perror("Not exit normally!\n");
        }else
        {
            printf("Child return code %d\n", WEXITSTATUS(wstatus));
        }
    }
    
    }
}
#include <signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>





int main(){

    int pid = fork();

    if(pid == -1){
        exit(-1);
    }else if(pid == 0){
        printf("Child proc\n");
        *((char*)0)= 12;
    }else{
        int wstatus;
        pid_t cild_pid =  wait(&wstatus);
        printf("Child pid: %d", cild_pid);
        printf("Wstatus: %d\n", wstatus);
        if(WIFEXITED(wstatus)){
            printf("Child exited normally");
            printf("Child exited normally", WEXITSTATUS(wstatus));
        }else{
            printf("Child did not exited normally");
        }
        printf("Parent proc\n");
    }
    


    return 0;
}
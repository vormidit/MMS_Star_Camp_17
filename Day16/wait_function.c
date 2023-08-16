#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/time.h>

int main(int argc, char *argv[]){

    //{1}----------------------------------------------
    int pid = fork();//Create new process

    int n;//number;

    if(pid == 0){ //We are in child process
        n = 1;
        //printf("Hi from the child, n is %d\n", n);
    }else{
        n = 6; //We are in parent process
        //printf("Hi from the parent, n is %d\n", n);
    }

    //{2}----------------------------------------------

    if(pid != 0){
        wait(NULL);
    }

    int i;
      for(i = n; i < n+5; i++){
        printf("%d ", i);
        //fflush(stdout);
      }




return 0;
}//end of main
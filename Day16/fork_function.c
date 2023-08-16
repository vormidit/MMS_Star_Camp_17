#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv[]){

    //{1}
    //fork();
    //printf("Hello World\n");

     //{2}
    //int pid = fork();
    // printf("Hello World from id: %d\n", pid);

    //{3}
/*
    if(pid == 0){
        printf("Hello World from child process\n");//Child process
    }else{
        printf("Hello World from main process\n");//Parent process
    }
*/
    //{4}
 /*  fork();
    fork();
    fork();
    

    printf("Hello World!\n");

*/
    int pid1 = fork();
    printf("Hello World after first fork() id: %d\n", pid1);

    if(pid1 != 0){
        int pid2 = fork();
        printf("Hello World after second fork() id: %d\n", pid2);
    }else{
            //We ar NOT in the main process
    
    //printf("Hello World!\n");
    printf("Hello World from id: %d\n", pid1);
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/time.h>

int main(int argc, char *argv[]){

    //{1}------------------------------------------
    int pid = fork();//Create new process
     //{1}
 //   printf("Print PID: %d\n", pid);

    //{2}--------------------------------------------
 //   printf("Print getpid(): %d\n", getpid());
    //{3}-------------------------------------------------
 //   printf("Print getppid(): %d\n", getppid());
     //{5}---------------------------------------------------
    if(pid == 0){//If the process is child
        printf("SLEEP 5 seconds...\n");
        sleep(5);
    }

    //{4}-----------------------------------------------
    printf("Current pid: %d, parent pid: %d\n",getpid(), getppid());

    


    //{6.1}---------------------------------------------
 //   wait(NULL);

    //{6.2}-----------------------------------------------
    if(pid != 0){//If the process is parent
        printf("SLEEP 5 seconds...\n");
        wait(NULL);
    }

return 0;
}//end of main
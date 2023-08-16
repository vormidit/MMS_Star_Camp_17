#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //Important

#include<sys/wait.h>
#include<sys/errno.h>
#include<sys/types.h>


int main(int argc, char *argv[]){

    //{1}
    int fd[2];
    //fd[0] READ pipe
    //fd[1] WRITE pipe

//    pipe(fd);

    if(pipe(fd) == -1){
        printf("AN error ocured when open pipe!\n");
        return 1;
    }

    int pid = fork();//Create new process

    if(pid == -1){
        printf("AN error ocured whit fork()!\n");
        return 2;
    }

    //Check the process if pid = 0
    if(pid == 0){
        close(fd[0]);//Close for reading
        int A;
        printf("Please input value:\n");
        scanf("%d", &A);
        if(write(fd[1], &A, sizeof(int)) == -1){
            return 3;//Error writing into pipe
        }
        close(fd[1]);//Close for writing 
    }else{
        close(fd[1]);//Close parent proc for writing
        //We are in the parent proc
        int B;
        if(read(fd[0], &B, sizeof(B)) == -1){
            printf("AN error ocured whit reading from pipe!\n");
            return 4;//Error reading from pipe
        }
        printf("Read from Child process: %d\n", B);
        printf("Read from Parent process: %d\n", B*10);
        close(fd[0]);//Closed for Reading
    }



    return 0;
}
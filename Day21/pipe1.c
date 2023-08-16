#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(){
    int pipe_fd[2];
    //pipe_fd[0] open for read
    //pipe_fd[1] open for write 

    pipe(pipe_fd);

    int pid = fork();
    

    if(pid < 0){
        perror("Not work!\n");
    }else if(pid == 0){
        //Child
        close(pipe_fd[0]);
        int n = rand()%1000;
        printf("Will write %d to pipe\n", n);
        if(write(pipe_fd[1], &n, sizeof(n)) != sizeof(n)){
            perror("Write error!\n");
        }
        return 0;

    }else{
        close(pipe_fd[1]);
        int res;
        if(read(pipe_fd[0], &res, sizeof(res)) != sizeof(res)){
            perror("Read error!\n");
        }
        close(pipe_fd[0]);
        printf("Res from child %d\n", res);

    }
}
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
    int pipe_fd[2];
    // pipe_fd[0] е fd, отворен за четене
    // pipe_fd[1] е fd, отворен за писане
    pipe(pipe_fd);

    int pid = fork();
    
    if(pid < 0) {
        perror("Could not fork");
        exit(-1);
    } else if(pid == 0) {
        // close(pipe_fd[0]); // Child does not read from pipe
        // Child
        int n = rand()%1000;
        // Write to pipe
        printf("Will write %d to pipe\n", n);
        if(write(pipe_fd[1], &n, sizeof(n)) != sizeof(n)) {
            perror("Write error");
        };
        // close(pipe_fd[1]); // Child has finished writing to pipe
        return 0;
    } else {
        // close(pipe_fd[1]); // Parent does not write to pipe
        // Parent
        int res;
        if(read(pipe_fd[0], &res, sizeof(res)) != sizeof(res)) {
            perror("read error");
        }
        printf("RES FROM CHILD: %d\n", res);
    }
}
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
        // Child
        close(pipe_fd[0]); // Child does not read from pipe
        int n = rand()%10;
        printf("IN CHILD: will write %d number to pipe\n", n);
        // Write to pipe
        for(int i = 0; i < n; i++) {
            if (write(pipe_fd[1], &i, sizeof(i)) != sizeof(n))
            {
                perror("Write error");
            };
        }
        // Remove this and start program
        close(pipe_fd[1]); // Child has finished writing to pipe
        printf("CHILD BUSY WAIT\n");
        while(1) {
            printf("");
        }
        return 0;
    } else {
        // Remove this and start program
        close(pipe_fd[1]); // Parent does not write to pipe
        // Parent
        int res, numBytes;
        printf("In parent - reading numbers from pipe\n");
        while((numBytes = read(pipe_fd[0], &res, sizeof(res))) > 0) {
            printf("%d \n", res);
        }
        close(pipe_fd[0]); // Parent has finished reading from child
        return 0;
    }
}
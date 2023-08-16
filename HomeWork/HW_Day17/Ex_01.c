#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    int fd[3][2];

    for(size_t i = 0; i < 3; i++){
        if (pipe(fd[i]) < 0) {return 1;}
    }
    
    int myValue = 7;

    if(write(fd[0][1], &myValue, sizeof(int)) == -1){
        exit(1);//Error writing into pipe2
    }
    
    close(fd[0][1]);


    int pid1 = fork();

    if (pid1 < 0) { return 2;} // CHECK IF EVERYTHING IS OK

    if (pid1 == 0) {
        //Child1
        close(fd[0][1]);
        close(fd[1][0]);
        close(fd[2][0]);
        close(fd[2][1]);

        int value_from_parent;
        if(read(fd[0][0], &value_from_parent, sizeof(int)) != sizeof(int)){
            exit(1);//Error writing into pipe2
         }
        close(fd[0][0]);
        value_from_parent *= 3;

        if(write(fd[1][1], &value_from_parent, sizeof(int)) == -1){
            exit(1);//Error writing into pipe2
         }
        close(fd[1][1]);


    }

    int pid2 = fork();

    if (pid2 < 0) { return 3;} // CHECK IF EVERYTHING IS OK

    if (pid2 == 0) {
    
        close(fd[0][0]);
        close(fd[0][1]);
        close(fd[1][1]);
        close(fd[2][0]);

        int value_from_child1;
        if(read(fd[1][0], &value_from_child1, sizeof(int)) != sizeof(int)){
            exit(1);//Error writing into pipe2
         }
        close(fd[1][0]);

        if(value_from_child1 % 2 == 0){
            value_from_child1 *= value_from_child1;
        }else{
            value_from_child1 /= 2;
        }
        
        if(write(fd[2][1], &value_from_child1, sizeof(int)) == -1){
            exit(1);//Error writing into pipe2
         }
        close(fd[2][1]);
    
    
    }

    //Parent
    close(fd[0][0]);
    close(fd[1][0]);
    close(fd[1][1]);
    close(fd[2][1]);

    int value_from_child2;
    if(read(fd[2][0], &value_from_child2, sizeof(int)) != sizeof(int)){
        exit(1);//Error writing into pipe2
    }
    
    close(fd[2][0]);

    printf("Result from Child2 is: %d\n", value_from_child2);

    return 0;
}//End main
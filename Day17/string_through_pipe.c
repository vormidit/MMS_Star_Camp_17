#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h> //Important
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
    //Create FD and pipe
    int fd[2];//[0]-read, [1]-write

   if( pipe(fd) == -1){
    return 1;
   }

    //Create new process fork()
    int pid = fork();
    if(pid == -1){return 2;}
    

    //Switching between  proceses and string
    if(pid == 0){//Child process
        close(fd[0]);//close for read

        char myString[255];
        
        printf("Input string:\n");
        fgets(myString, 50, stdin);
        myString[strlen(myString)-1] = '\0';

        int size = strlen(myString);

        if(write(fd[1], &myString, size) == -1){
            return 3;
        }
        printf("Sizeof string: %d\n", size);
        printf("String in array to be sent: %s\n", myString);

        close(fd[1]);
    
    }else{//Parent process
        wait(NULL);
        close(fd[1]);
        char myString[255];

        printf("Recieved from child process!:\n");
        if(read(fd[0], &myString, sizeof(myString)) == -1){
            return 4;
        }
        printf("%s\n", myString);

        close(fd[0]);

        
       
    }


return 0;
}
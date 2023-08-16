#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(){
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND);
    if(fd < 0){
        perror("Error open file!\n");
    }
    int fd2;
   if((fd2 = dup2(STDOUT_FILENO, fd)) == -1){
     perror("DUP2 error\n");
   }
   printf("FD2 : %d", fd2);
    close(fd);
    printf("Hello World\n");
    printf("Hello World2\n");
    return 0;
}
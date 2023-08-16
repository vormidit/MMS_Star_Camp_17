#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h> //Important
#include<sys/errno.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <fcntl.h>


int main(int argc, char *argv[]){

    if(mkfifo("myFIFO", 0777) == -1){
        if(errno != EEXIST){
        printf("Couldnn't create FIFO file :%s \n", strerror((errno)));
        return 1;
        }
    }

    printf("Opening...\n");
    int fd = open("myFIFO", O_RDWR);
    printf("Opened.\n");

    int myValue = 67;
    if(write(fd, &myValue, sizeof(myValue)) == -1){
        printf("Problem with writing.\n");
        return 2;
    }
    printf("Written.\n");
    close(fd);
    printf("Closed.\n");

}
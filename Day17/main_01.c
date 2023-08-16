#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h> //Important
#include<sys/errno.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <fcntl.h>
#include <time.h>


int main(){
//Make FIOF file 
    if(mkfifo("myFIFO", 0777) == -1){
        if(errno != EEXIST){
        printf("Couldnn't create FIFO file :%s \n", strerror((errno)));
        return 1;
        }
    }
//Generate rand int in array
    int myArray[10];
    srand(time(NULL));
    for(size_t i = 0; i < 10; i++){
        myArray[i] = rand()%100;
        printf("Generated value: %d\n", myArray[i]);
    }

//Open FIFO file to write only
    int fd = open("myFIFO", O_WRONLY);

//Check if error to open 
    if(fd == -1){
        printf("Failed to open file.\n");
        return 2;
    }

//Writing into FIFO with file descriptor and check for failed
    if(write(fd, &myArray, sizeof(myArray)) == -1){
        printf("PFailed with write.\n");
        return 3;
    }
    
//Close file descriptor
    close(fd);
    return 0;
}//End of main()
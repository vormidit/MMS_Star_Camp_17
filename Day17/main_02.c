#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h> //Important
#include<sys/errno.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <fcntl.h>


int main(){

//Create array
    int myArray[10];

//Open FIFO file to read only
    int fd = open("myFIFO", O_RDONLY);

//Check if error to open 
    if(fd == -1){
        printf("Failed to open file.\n");
        return 1;
    }

//Writing into FIFO with file descriptor and check for failed
    if(read(fd, &myArray, sizeof(myArray)) == -1){
        printf("PFailed with write.\n");
        return 2;
    }
 
    
//Close file descriptor
    close(fd);

//Print read values from FIFO   
    for(size_t i = 0; i < 10; i++){
        printf("Recieved value: %d\n", myArray[i]);
    }


    
    return 0;
}//End of main()
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //Important

#include<sys/wait.h>
#include<sys/errno.h>
#include<sys/types.h>


int main(int argc, char *argv[]){

    int arr[]={10,20,30,40,50,60};
//Child sum = 60;
//parent sum = 110;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int start, end;
    int fd[2];
    
   
    
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
        start = 0;
        end = arrSize/2;
    }else{
        start = arrSize/2+1;
        end = arrSize;
    
    }

    int i, sum =0;
    for(i = start; i < end; i++){
            sum += arr[i];
    }

    if(pid == 0){
        printf("Sum of the number in arr from CHILD is: %d\n", sum);
    }else{
        printf("Sum of the number in arr from PARENT is: %d\n", sum);
    }

    if(pid == 0){

        close(fd[0]);//Close for reading
        if(write(fd[1], &sum, sizeof(int)) == -1){
            return 3;//Error writing into pipe
        }
        close(fd[1]);//Close for writing
    }else{
        int sum_from_child;
        close(fd[1]);//Close parent proc for writing
        if(read(fd[0], &sum_from_child, sizeof(int)) == -1){
            printf("AN error ocured whit reading from pipe!\n");
            return 4;//Error reading from pipe
        }
        close(fd[0]);//Closed for Reading
        int total_sum = sum + sum_from_child;
        printf("Total sum is: %d\n", total_sum);
    }
    
    return 0;
}
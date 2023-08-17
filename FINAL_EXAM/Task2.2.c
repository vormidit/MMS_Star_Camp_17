#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>

int fd;
unsigned long long file_size_bytes;
char *fname;
int pipes_fd_list[10][2];//How to recognize how much files is input to make pipes for k process

void child_fun(int child_index, char *fname) {
    unsigned int file_size;
    unsigned long long sum = 0;
    int fd = open(fname, O_RDONLY);
    if(fd < 0) {
        perror("Could not open");
        exit(1);
    }
    struct stat file_info;
    stat(fname, &file_info);
    file_size = file_info.st_size;


    for(int i = 0; i < file_size; i+= 1) {
        unsigned long long curNum = 0;
        read(fd, &curNum, sizeof(unsigned long long));
        sum += curNum;
    }
    
    // Write result to pipe for current child
    write(pipes_fd_list[child_index][1], &sum, sizeof(sum));
}



int main(int argc, char *argv[]){

    int K = argc -1;

    // Create K children
    int pid;
    for(int i = 0; i < K; i++) {
       
       pipe(pipes_fd_list[i]);
       
        pid = fork();
        if(pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if(pid == 0) {
            // CHILD
            child_fun(i, argv[i+1]);
            return 0;
        }
    }
    //PARENT
    
    for(int i = 0; i < K; i++) {
        wait(NULL);
    }


    // Sum partial sums stored in child pipes
    unsigned long long sum_total = 0;
    unsigned long long cur_partial_sum;
    for(int i = 0; i < K; i++) {
        printf("WAITING FOR INPUT IN PIPE OF CHILD: %d\n", i);
        read(pipes_fd_list[i][0], &cur_partial_sum, sizeof(cur_partial_sum));

        printf("READ ONE INT FROM PIPE OF CHILD: %d\n", i);
        sum_total += cur_partial_sum;
    }
    printf("PARENT IS ENDING. SUM: %lld\n", sum_total);


}
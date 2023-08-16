#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#define K 10
#define ELEM_SIZE sizeof(int)
int fd;
unsigned long long file_size_bytes;
unsigned long long child_byte_count;
char *fname;
// One pipe for each child
int pipes_fd_list[K][2];

void child_fun(int child_index) {
    printf("STARTED CHILD with child_index: %d\n", child_index);
    unsigned long long sum = 0;

    // Open file in child
    fd = open(fname, O_RDONLY);
    if(fd < 0) {
        perror("Could not open");
        exit(1);
    }
    lseek(fd, child_index*child_byte_count, SEEK_SET);
    for(int i = 0; i < child_byte_count/ELEM_SIZE; i+= 1) {
        int curNum = 0;
        read(fd, &curNum, sizeof(int));
        // printf("%d\n", curNum);
        sum += curNum;
    }
    close(fd);
    printf("ENDING CHILD with child_index: %d, SUM: %llu\n", child_index, sum);

    //Write to write end to cur pipe, send to parent cur sum
    write(pipes_fd_list[child_index][1], &sum, sizeof(sum));
}
// ./program numbers.bin
int main(int argc, char *argv[]) {
    
    return 0;
}
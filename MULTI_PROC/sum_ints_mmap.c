#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/mman.h>
#define K 10
#define ELEM_SIZE sizeof(int)
int fd;
unsigned long long file_size_bytes;
unsigned long long child_byte_count;
char *fname;
int *file_mem;
// One pipe for each child
int pipes_fd_list[K][2];

void child_fun(int child_index) {
    printf("STARTED CHILD with child_index: %d\n", child_index);
    unsigned long long sum = 0;

    // Sum numbers from file
    // malloc failed
    for(int i = (child_byte_count/ELEM_SIZE)*child_index;
            i < (child_byte_count/ELEM_SIZE)*(child_index+1); i+= 1) {
        sum += file_mem[i];//Filemem is mmaped file
    }
    printf("ENDING CHILD with child_index: %d, SUM: %llu\n", child_index, sum);

    // Write result to pipe for current child
    write(pipes_fd_list[child_index][1], &sum, sizeof(sum));
}
// ./program numbers.bin
int main(int argc, char *argv[]) {
    if(argc != 2) {
        perror("Invalid argc");
        exit(1);
    }
    // Open file
    fname = argv[1];
    fd = open(fname, O_RDONLY);
    if(fd < 0) {
        perror("Could not open");
        exit(1);
    }

    // get file size
    file_size_bytes = lseek(fd, 0, SEEK_END);
    child_byte_count = file_size_bytes/K;
    printf("FILE SIZE IS: %lld\n", file_size_bytes);
    printf("CHILD BYTE COUNT IS: %lld\n", child_byte_count);

    file_mem = mmap(NULL, file_size_bytes, PROT_READ, MAP_PRIVATE, fd, 0);
    if(file_mem == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    // Close file - open file later in each child
    close(fd);
    

    // Create K children
    int pid;
    for(int i = 0; i < K; i++) {
        // Create pipe for each child
        // TODO: Check for errors
        pipe(pipes_fd_list[i]);

        // Only the parent calls fork
        pid = fork();
        if(pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if(pid == 0) {
            // CHILD
            child_fun(i);
            return 0;
        }
    }
    //PARENT
    // Wait for all K children
    for(int i = 0; i < K; i++) {
        wait(NULL);
    }
    // while(wait(NULL) != -1){}


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

    return 0;
}
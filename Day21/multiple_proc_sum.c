#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include<unistd.h>


#define K 3
#define ELEM_SIZE sizeof(int)
// Създайте програма, която създава K на брой детински процеса. K e препроцесорна константа. 
// Всеки детински процес намира сумата само на част от файла. 

// След като приключи да сумира, всеки детински процес:
// печата получената частична сума на стандартния изход.
// предава получената частична сума на родителския процес (temp file, pipe, mmap)

// След това - родителският процес намира цялата сума и я печата на стандартния изход.
int fd;
unsigned long long file_size_bytes;
unsigned long long child_byte_count;
char *fname;
int pipes_fd_list[K][2];


void child_fun(int child_indx){
    unsigned long long sum = 0;

    fd = open(fname, O_RDONLY);//Всяко дете си отваря файла

    if(fd < 0){
        perror("Error with open file!\n");
        exit(1);
    }

    printf("Started Child with index  %d", child_indx);


    lseek(fd, child_indx*child_byte_count,  SEEK_SET);//От къде да започне да работи детето
    for(int i = 0; i < child_byte_count/ELEM_SIZE; i += 1){
        int curNum = 0;
        read(fd, &curNum, sizeof(int));
        printf("%d \n", curNum);
        sum += curNum;
    }
    close(fd);
    printf("ENDING CHILD with child_index: %d, SUM: %llu\n", child_indx, sum);
    write(pipes_fd_list[child_indx][1], &sum, sizeof(sum));
}


int main(int argc, char *argv[]){

    if(argc != 2){
        perror("Invalid args!\n");
        exit(1);
    }
    fname = argv[1];
    fd = open(fname, O_RDONLY);

    if(fd < 0){
        perror("Error with open file!\n");
        exit(1);
    }

    file_size_bytes = lseek(fd, 0, SEEK_END);

    child_byte_count = file_size_bytes/K;
    printf("File size is %lld\n", file_size_bytes);
    printf("CHILD BYTE COUNT IS: %lld\n", child_byte_count);
    close(fd);

    int pid;

    for(int i = 0; i < K; i++){
        //Only parent call fork()
        pipe(pipes_fd_list[i]);

        pid = fork();
        if(pid < 0){
            perror("Error with fork!\n");
            exit(1);
        }else if(pid == 0){
            //CHILD
            child_fun(i);
            return 0;
            
        }
    }
    //Parent
    for(int i = 0; i < K; i++){
        wait(NULL);
    }
    
    unsigned long long sum_total = 0;
    unsigned long long cur_partial_sum;
    
    for(int i = 0; i < K; i++) {
        read(pipes_fd_list[i][0], &cur_partial_sum, sizeof(cur_partial_sum));
        sum_total += cur_partial_sum;
    }
    printf("SUM: %lld\n", sum_total);
    

    return 0;
}


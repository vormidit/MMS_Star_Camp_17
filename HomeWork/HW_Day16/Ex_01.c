#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ARRAY_SIZE 10

void parent_process(int pipe1[2], int pipe2[2], int pipe3[2]) {
    close(pipe1[0]);
    close(pipe2[0]);
    close(pipe2[1]);
    close(pipe3[1]);

    int int_array[ARRAY_SIZE];
    for(size_t i = 0; i < ARRAY_SIZE; i++){
        int_array[i] = 1 + rand()%(100-1);
        printf("%d\n", int_array[i]);
    }
    if(write(pipe1[1], int_array, sizeof(int)*ARRAY_SIZE) == -1){
        exit(1);//Error writing into pipe1
    }
    close(pipe1[1]);

    int pow_sum;

    if(read(pipe3[0], &pow_sum, sizeof(int)) == -1){
        exit(1);//Error reading into pipe3
    }
    close(pipe1[1]);
    printf("Power of Sum is: %d\n", pow_sum);

}


void process_A(int pipe1[2], int pipe2[2]) {
    close(pipe1[1]);
    close(pipe2[0]);

    int arr[ARRAY_SIZE], elem_sum = 0;

    if(read(pipe1[0], &arr, sizeof(int)*ARRAY_SIZE) == -1){
        exit(1);//Error reading into pipe1
    }
    close(pipe1[0]);

    for(size_t i = 0; i < ARRAY_SIZE; i++){
        elem_sum += arr[i];
    }
    if(write(pipe2[1], &elem_sum, sizeof(int)) == -1){
        exit(1);//Error writing into pipe2
    }
    close(pipe2[1]);


}


void process_B(int pipe2[2], int pipe3[2]) {
    close(pipe2[1]);
    close(pipe3[0]);
    
    int sum_from_A, pow_sum;

    if(read(pipe2[0], &sum_from_A, sizeof(int)) == -1){
        exit(1);//Error reading into pipe1
    }
    close(pipe2[0]);

    pow_sum = sum_from_A * sum_from_A;

    if(write(pipe3[1], &pow_sum, sizeof(int)) == -1){
        exit(1);//Error writing into pipe2
    }
    close(pipe3[1]);



}


int main() {
    int pipe1[2], pipe2[2], pipe3[2];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1) {
        exit(1);
    }

    pid_t pid_A = fork();//Fork process A

    if(pid_A == -1){
        printf("AN error ocured whit fork() for Process A!\n");
        exit(1);
    }

    if (pid_A == 0) {
        process_A(pipe1, pipe2);
    } else if (pid_A > 0) {
    
        // Fork process B ::
        pid_t pid_B = fork();
        if(pid_B == -1){
            printf("AN error ocured whit fork() for Process B!\n");
            exit(1);
        }

        if (pid_B == 0) {
            process_B(pipe2, pipe3);
        } else if (pid_B > 0) {

            // Parent process
            parent_process(pipe1, pipe2, pipe3);

            // Wait for both child processes to finish
            wait(NULL);
            wait(NULL);

        } else {
            perror("Forking process B failed.");
            exit(1);
        }

    } else {
        perror("Forking process A failed.");
        exit(1);
    }

    return 0;
}
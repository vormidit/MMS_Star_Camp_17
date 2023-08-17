#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

unsigned long long sum_total;


pthread_mutex_t lock1;

void* thread_fun(void *args) {
    unsigned long long localSum = 0;
    int fd = open((char*)args, O_RDONLY);
    if(fd < 0) {
        perror("Could not open");
        exit(1);
    }
    struct stat file_info;
    stat((char*)args, &file_info);
    int file_size = file_info.st_size;
    
    for(size_t i = 0; i < file_size/sizeof(unsigned long long); i++) {
        unsigned long long curNum = 0;
        read(fd, &curNum, sizeof(unsigned long long));
        localSum += curNum;
    }
    pthread_mutex_lock(&lock1);
    sum_total += localSum;
    pthread_mutex_unlock(&lock1);

    return NULL;
}



int main(int argc, char *argv[]){

    int K = argc -1;
    if(pthread_mutex_init(&lock1, NULL)) {
        perror("Could not init mutex");
    }
    // Create K threads - pass thread_index as argument
    pthread_t thread_handles[K];
    int i = 0;

    for(;i < K; i++) {
    
        if(pthread_create(thread_handles + i, NULL, thread_fun, argv[i+1]) == -1) {
            perror("could not create thread");
            exit(1);
        }
        
    }

    // Wait for threads to finish
    for(int i = 0; i < K; i++) {
        pthread_join(thread_handles[i], NULL);
    }

    printf("PARENT IS ENDING. SUM: %lld\n", sum_total);


    pthread_mutex_destroy(&lock1);
    return 0;


}
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<fcntl.h>
#define K 10
void child_fun(int i) {

    sem_t *sem1 = sem_open("/my_semaphor", 0);

    printf("Child called sem_wait index_child: %d\n", i);
    // Wait until parent calls sem_post
    sem_wait(sem1);
    printf("Started child: %d\n", i);
    printf("Ending child: %d\n", i);
}
int main() {
    sem_t *sem1 = sem_open("/my_semaphor", O_CREAT, 0777, 0);//Semaphore create open 
    int pid;
    for(int i = 0; i < K; i++) {
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
    sleep(1);
    printf("Parent created %d Children\n", K);
    // Start all children by calling sem_post K times
    for(int i = 0; i < K; i++) {
        sem_post(sem1);
    }

    sem_close(sem1);
    sem_unlink("/my_semaphor");
    return 0;
}
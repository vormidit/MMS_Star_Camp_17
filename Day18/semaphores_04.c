#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>//IMPORTATNT
#include<semaphore.h>//IMPORTATNT

#define THREAD_NUM 16

sem_t mySem;

void *myfunc(void *arg){

    sem_wait(&mySem);//Semaphore lock/wait sem counter dec
    sleep(3);
    printf("Hello from thread %d\n", (*(int*)arg));
    free(arg);

    sem_post(&mySem);//Semaphore unlock sem counter inc
}


int main(){
    pthread_t threads[THREAD_NUM];
    
    sem_init(&mySem, 0, 4);

    for(int i = 0; i < THREAD_NUM; i++){
        int *a = malloc(sizeof(int));
        *a = i;
       
        if(pthread_create(&threads[i], NULL, &myfunc, a) != 0){
            printf("Error creating thread!\n");
            return 1;
        }
    }

    for(int i = 0; i < THREAD_NUM; i++){
        if(pthread_join(threads[i], NULL) != 0){
            printf("Error to join thread!\n");
            return 1;
        }
    }

    sem_destroy(&mySem);
    return 0;
}
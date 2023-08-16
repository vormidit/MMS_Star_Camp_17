#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

#define THREAD_NUM 16

sem_t semaphore;

void* routinee(void *arg){

    int id = *((int*)arg);

    printf("Thread [%d] wait for semaphore!\n", id);

    sem_wait(&semaphore);
    printf("Thread [%d] input!\n", id);
    sleep(1 + rand()%4);
    sem_post(&semaphore);
    printf("Thread [%d] output!\n", id);
    free(arg);
}


int main(){

    pthread_t threads[THREAD_NUM];
    sem_init(&semaphore, 0, 32);

    for(int i =0; i < THREAD_NUM; i++){

        int *id = malloc(sizeof(int));
        *id = i;
       
        if(pthread_create(&threads[i],NULL, &routinee, id) != 0){
            perror("Error create thread!\n");
            return 1;

        }
        
    }
    for(int i =0; i < THREAD_NUM; i++){
         if(pthread_join(threads[i], NULL) != 0){
                perror("Error with join!");
                return 3;
            }
    }

    sem_destroy(&semaphore);

    return 0;
}
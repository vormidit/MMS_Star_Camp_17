#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>//IMPORTATNT

int myCounter = 0;
pthread_mutex_t myMutex;

void* myTask01(){
    printf("Thread ID: %lu\n", pthread_self());
    for(size_t i =0; i < 10000000; i++){
        pthread_mutex_lock(&myMutex);
        myCounter++;
        
        pthread_mutex_unlock(&myMutex);

    }


}

void* myTask02(){
    for(size_t i =0; i < 100000; i++){
        pthread_mutex_lock(&myMutex);
        myCounter++;
        pthread_mutex_unlock(&myMutex);

    }


}
void* myTask03(){
    for(size_t i =0; i < 10000000; i++){
        pthread_mutex_lock(&myMutex);
        myCounter++;
        pthread_mutex_unlock(&myMutex);

    }


}
int main(){

    pthread_t tr1, tr2, tr3, tr4, tr5, tr6;
    pthread_mutex_init(&myMutex, NULL);
//Create Threads
    if(pthread_create(&tr1,NULL, &myTask01, NULL) != 0){
        return 1;
    }
    printf("Thread ID: %lu\n", pthread_self());

    if(pthread_create(&tr2,NULL, &myTask01, NULL) != 0){
         return 2;
    }
    printf("Thread ID: %lu\n", pthread_self());
    if(pthread_create(&tr3,NULL, &myTask01, NULL) != 0){
        return 3;
    }
    printf("Thread ID: %lu\n", pthread_self());
    if(pthread_create(&tr4,NULL, &myTask01, NULL) != 0){
         return 4;
    }
    printf("Thread ID: %lu\n", pthread_self());
    if(pthread_create(&tr5,NULL, &myTask01, NULL) != 0){
        return 5;
    }
    printf("Thread ID: %lu\n", pthread_self());
    if(pthread_create(&tr6,NULL, &myTask01, NULL) != 0){
         return 6;
    }
    printf("Thread ID: %lu\n", pthread_self());


//Join Threads

    if(pthread_join(tr1, NULL) != 0){
        return 7;
    }

    if(pthread_join(tr2, NULL) != 0){
        return 8;
    }
    if(pthread_join(tr1, NULL) != 0){
        return 9;
    }

    if(pthread_join(tr2, NULL) != 0){
        return 10;
    }
    if(pthread_join(tr1, NULL) != 0){
        return 11;
    }

    if(pthread_join(tr2, NULL) != 0){
        return 12;
    }
    
    pthread_mutex_destroy(&myMutex);
    printf("Counter is: %d\n", myCounter);
    
    return 0;
}//end of main
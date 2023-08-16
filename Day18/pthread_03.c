#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>//IMPORTATNT

int myCounter = 0;




void* myTask01(){
    for(size_t i =0; i < 10000000; i++){
        
        myCounter++;

    }


}

void* myTask02(){

    for(size_t i = 0; i < 10000; i++)
    printf("%lu\n", pthread_self());


}

int main(){

    pthread_t tr1, tr2, tr3, tr4, tr5;
    
//Create Threads
    if(pthread_create(&tr1,NULL, &myTask01, NULL) != 0){
        return 1;
    }

    if(pthread_create(&tr2,NULL, &myTask01, NULL) != 0){
         return 2;
    }
    if(pthread_create(&tr3,NULL, &myTask02, NULL) != 0){
        return 3;
    }
    if(pthread_create(&tr4,NULL, &myTask02, NULL) != 0){
        return 4;
    }
    if(pthread_create(&tr5,NULL, &myTask02, NULL) != 0){
        return 5;
    }


//Join Threads

    if(pthread_join(tr1, NULL) != 0){
        return 6;
    }

    if(pthread_join(tr2, NULL) != 0){
        return 7;
    }
    if(pthread_join(tr3, NULL) != 0){
        return 8;
    }
    if(pthread_join(tr4, NULL) != 0){
        return 9;
    }
    if(pthread_join(tr5, NULL) != 0){
        return 10;
    }
     
    

    printf("Counter is: %d\n", myCounter);
     
    return 0;
}//end of main
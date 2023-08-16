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

int main(){

    pthread_t tr1, tr2;
    
//Create Threads
    if(pthread_create(&tr1,NULL, &myTask01, NULL) != 0){
        return 1;
    }

    if(pthread_create(&tr2,NULL, &myTask01, NULL) != 0){
         return 2;
    }


//Join Threads

    if(pthread_join(tr1, NULL) != 0){
        return 3;
    }

    if(pthread_join(tr2, NULL) != 0){
        return 4;
    }
    
    
    printf("Counter is: %d\n", myCounter);
    
    return 0;
}//end of main
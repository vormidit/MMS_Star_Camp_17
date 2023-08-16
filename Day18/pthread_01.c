#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>//IMPORTATNT



void* myTask01(){
    printf("Hello from myTask01\n");
    sleep(5);
    printf("Ending thread...\n");


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
    
    
    
    
    return 0;
}//end of main
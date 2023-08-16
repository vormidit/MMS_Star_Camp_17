#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>//IMPORTATNT

#define NUM_THREADS 7
#define INIT_BALANCE 1000

typedef struct BankAcc{
    double balance;

}BankAcc;

BankAcc account1 = {INIT_BALANCE};

pthread_mutex_t myMutex;//MUTEX


void* deposit(void *arg){
    pthread_mutex_lock(&myMutex);
    account1.balance += *((double*)arg);
    pthread_mutex_unlock(&myMutex);
}

void* withdraw(void *arg){
    pthread_mutex_lock(&myMutex);
    account1.balance -= *((double*)arg);
    pthread_mutex_unlock(&myMutex);
}

int main(){
    
    double dep_amount = 200, withdr_amount = 100;
    pthread_t threads[NUM_THREADS];
    //MUTEX INIT
    pthread_mutex_init(&myMutex, NULL);

    for(int i =0; i < NUM_THREADS; i++){
        if(i%2 == 0){
            if(pthread_create(&threads[i],NULL, &withdraw, &withdr_amount) != 0){
               return 1;
            }
            printf("[%d]Current balance: %.2lf\n",i, account1.balance);
        }else{
            if(pthread_create(&threads[i],NULL, &deposit, &dep_amount) != 0){
              return 2;
            }
            printf("[%d]Current balance: %.2lf\n",i, account1.balance);
        }
        
    }
    for(int i =0; i < NUM_THREADS; i++){
         if(pthread_join(threads[i], NULL) != 0){
                return 3;
            }
    }

    pthread_mutex_destroy(&myMutex);
    
    printf("Balance in BankAcc: %.2lf\n", account1.balance);

    return 0;
}//end of main
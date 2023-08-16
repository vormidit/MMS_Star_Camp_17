#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>//IMPORTATNT

#define NUM_THREADS 50
#define INIT_BALANCE 1000

typedef struct BankAcc{
    double balance;

}BankAcc;

BankAcc account1 = {INIT_BALANCE};


void* deposit(void *arg){
    account1.balance += *((double*)arg);
}

void* withdraw(void *arg){
    account1.balance -= *((double*)arg);
}

int main(){
    
    double dep_amount = 200, withdr_amount = 100;
    pthread_t threads[NUM_THREADS];

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
    
    printf("Balance in BankAcc: %.2lf\n", account1.balance);

    return 0;
}//end of main
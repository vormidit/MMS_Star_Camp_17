#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

typedef struct thread_args_t {
    int a;
    int b;
} thread_args_t;

void* thread_fun(void* args) {
    printf("%p\n", args);
    printf("%p\n", (thread_args_t*)args);
    int *sum = malloc(sizeof(int));
    *sum = ((thread_args_t*)args)->a + ((thread_args_t*)args)->b;
    return sum;
}
typedef struct thread_args_return_val_t {//Sum into struct for result to not use dynamic mem to return value
    int a;
    int b;
    int sum;
} thread_args_return_val_t;

void* thread_fun2(void* args) {
    thread_args_return_val_t *args_ret_val = args;
    printf("%p\n", args);
    printf("%p\n", (thread_args_return_val_t*)args);
    args_ret_val->sum = args_ret_val->a + args_ret_val->b;
    return NULL;
}
int main() {
    pthread_t th1;
    thread_args_t args1 = {20, 30};
    if(pthread_create(&th1, NULL, thread_fun, &args1) == -1) {
        perror("Could not create thread");
        exit(1);
    }
    int *thread_res;
    pthread_join(th1, (void**)&thread_res);
    printf("Thread result: %d\n", *thread_res);
    free(thread_res);

    pthread_t th2;
    thread_args_return_val_t args2 = {30, 50, -1};
    if(pthread_create(&th2, NULL, thread_fun2, &args2) == -1) {
        perror("Could not create thread");
        exit(1);
    }
    pthread_join(th2, NULL);
    printf("Thread 2 result: %d\n", args2.sum);
    return 0;
}
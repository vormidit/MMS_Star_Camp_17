#include<stdio.h>
#include"queue.h"


void print_buffer(RingBuffer *pQ) {
    for(size_t i = 0; i < pQ->N; i++) {
        if(pQ->si%pQ->N <= i && i < pQ->ei) {
            printf("%.2lf ", pQ->arr[i]);
        } else {
            printf("0 ");
        }
    }
    
}

void enqueue(RingBuffer *pQ, double data){
    if(pQ->ei - pQ->si == pQ->N){
        printf("Queue is full!");
        return;
    }
    pQ->arr[pQ->ei%pQ->N] = data;
    pQ->ei++;
}
void dequeue(RingBuffer *pQ, double *result){
    if(pQ->ei - pQ->si == 0){
        printf("Queue is empty!");
        return;
    }
    *result = pQ->arr[pQ->si%pQ->N];
    pQ->arr[pQ->si%pQ->N] = 0;
    pQ->si++;
}
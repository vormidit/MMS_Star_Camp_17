#include<stdio.h>

#ifndef QUEUE_H
#define QUEUE_H 1


typedef struct RingBuffer{
    double *arr;
    size_t si, ei, N;
}RingBuffer;


void print_buffer(RingBuffer *pQ);

void enqueue(RingBuffer *pQ, double data);
void dequeue(RingBuffer *pQ, double *result);
#endif
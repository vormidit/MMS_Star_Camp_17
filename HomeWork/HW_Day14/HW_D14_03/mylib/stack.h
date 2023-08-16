#include<stdio.h>
#include<stdlib.h>

#ifndef STACK_H
#define STACK_H 1

typedef struct Data{
    int data;
}Data;

Data* init_stack_arr(size_t max_elem_count);

int push(Data elem, Data *pData);

int pop(Data *result, Data *pData);

void print_elems(Data *pData);

#endif
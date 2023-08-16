#include "linked_list.h"

//Include Guards

#ifndef STACK_H
#define STACK_H 1

typedef LL Stack;
 

Stack* init_stack();
void push(Data new_elem, Stack *s);
void pop(Data *result, Stack *s);
void print_stack(Stack s);

void deinit_stack(Stack *s);


#endif
#include "linked_list.h"

//Include Guards

#ifndef QUEUE_H
#define QUEUE_H 1

typedef LL Queue;
 

Queue* init_queue(){
    
    return init_linked_list();
}

void enque(Data new_elem, Queue *q){
    push_back(new_elem, q);
}

void dequeue(Data *result, Queue *q){
    pop_front(q, result);
}

void print_queue(Queue q){
    print_linked_list(&q);
}


void deinit_queue(Queue *q){
    deinit_linked_list(q);
    
}



#endif
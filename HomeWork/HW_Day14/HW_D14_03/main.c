#include <stdio.h>
#include "mylib/stack.h"
#include "mylib/queue.h"

//Създайте програма, в която да тествате функционалностите на стека и на опашката.


int main(){
    
    Data *pS = init_stack_arr(12);
    RingBuffer *pQ = malloc(sizeof(RingBuffer));
    pQ->N = 10;
    pQ->si = 0;
    pQ->ei = 0;
    pQ->arr = malloc(10*sizeof(double));
    
    //Stack 
    Data new = {10}, new2 = {20}, new3 = {40}, new4 = {50}, res;
    push(new, pS);
    print_elems(pS);
    printf("\n");
    push(new2, pS);
    print_elems(pS);
    printf("\n");
    push(new3, pS);
    print_elems(pS);
    printf("\n");
    pop(&res, pS);
    print_elems(pS);
    printf("Result :%d\n", res.data);
    printf("\n");
    pop(&res, pS);
    print_elems(pS);
    printf("Result :%d\n", res.data);
    printf("\n");
    pop(&res, pS);
    print_elems(pS);
    printf("Result :%d\n", res.data);
    printf("\n");

    printf("\n");
    printf("\n");
    
    //Queue

    enqueue(pQ, 12.3);
    print_buffer(pQ);
    printf("\n");
    enqueue(pQ,3.8);
    print_buffer(pQ);
    printf("\n");
    enqueue(pQ,35.89);
    print_buffer(pQ);
    printf("\n");
    enqueue(pQ,125.57);
    print_buffer(pQ);
    printf("\n");
    enqueue(pQ,87.52);
    print_buffer(pQ);
    printf("\n");
    enqueue(pQ,68.35);
    print_buffer(pQ);
    printf("\n");
    double q_res;
    dequeue(pQ, &q_res);
    print_buffer(pQ);
    printf("\n");
    dequeue(pQ, &q_res);
    print_buffer(pQ);
    printf("\n");
    dequeue(pQ, &q_res);
    print_buffer(pQ);
    printf("\n");
    dequeue(pQ, &q_res);
    print_buffer(pQ);
    printf("\n");
    dequeue(pQ, &q_res);
    print_buffer(pQ);
    printf("\n");
    dequeue(pQ, &q_res);
    print_buffer(pQ);
    printf("\n");







    return 0;
}
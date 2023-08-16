#include<stdio.h>
#include<stdlib.h>

typedef struct A{
    int data;
}A;

typedef struct Queue{
    A *arr;
    size_t capacity;
    size_t cur_elem_count;
}Queue;
size_t s, e;


Queue init_queue(size_t capacity){   
    Queue res;
    
    res.capacity = capacity;
    res.arr = calloc(capacity, sizeof(A));
    res.cur_elem_count = 0;
    

    return res;

}

int enqueu(Queue *q, A new_elem){
    if(q->cur_elem_count == q->capacity){
        return -1;
    
    }
    q->arr[q->cur_elem_count++] = new_elem;
        
    return 0;
    

}

int dequeu(Queue *q, A *result){
    if(q->cur_elem_count == 0){
        return -1;
    }
    *result = q->arr[0];
    q->cur_elem_count -= 1;
        
    for(size_t i = 0; i < q->cur_elem_count; i++){
        q->arr[i] = q->arr[i+1];
    }
    
    return 0;

}

void print_elems(Queue q){

    for(size_t i = 0; i < q.capacity; i++){
        if(i < q.cur_elem_count){
            printf("%d\t", q.arr[i].data);
        }else{
            printf("__\t");
        }
        
    }
}

int main(){

    Queue q1 = init_queue(10);

    A a = {3}, b={7}, c={8}, d={12};
    A result;

    printf("Push in Q1:%d\n", d.data);
    enqueu(&q1, d);
    printf("Push in Q1:%d\n", a.data);
    enqueu(&q1,a);
    printf("Push in Q1:%d\n", b.data);
    enqueu(&q1, b);
    printf("Push in S1:%d\n", c.data);
    enqueu(&q1, c);
    printf("Q1:\n");
    print_elems(q1);
    printf("\n");
    dequeu(&q1, &result);
    printf("Poped from Q1:%d\n", result.data);
    printf("\n");
    
    dequeu(&q1, &result);
    printf("Poped from Q1:%d\n", result.data);
    printf("Q1:\n");
    print_elems(q1);


    free(q1.arr);
   


    return 0;
}
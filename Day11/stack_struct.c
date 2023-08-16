#include<stdio.h>
#include<stdlib.h>

typedef struct A{
    int data;
}A;

typedef struct Stack{
    A *arr;
    size_t capacity;
    size_t cur_elem_count;
}Stack;



Stack init_stack(size_t max_elem_count){   
    Stack res;
    
    res.capacity = max_elem_count;
    res.arr = calloc(max_elem_count, sizeof(A));
    res.cur_elem_count = 0;

    return res;

}

int push(Stack *s, A elem){
    if(s->cur_elem_count == s->capacity){
        return -1;
    }else{

        s->arr[s->cur_elem_count] = elem;
        s->cur_elem_count++;
        return 0;
    }
    

}

int pop(Stack *s, A *result){
    if(s->cur_elem_count == 0){
        return -1;
    }else{

        *result = s->arr[s->cur_elem_count-1];
        s->cur_elem_count--;
        return 0;
    }

}

void print_elems(Stack s){

    for(size_t i = 0; i < s.capacity; i++){
        if(i < s.cur_elem_count){
            printf("%d\t", s.arr[i].data);
        }else{
            printf("__\t");
        }
        
    }
}

int main(){

    Stack s1 = init_stack(10);
    Stack s2 = init_stack(20);
    A a = {3}, b={7}, c={8}, d={12};
    A result;
    printf("Push in S2:%d\n", d.data);
    push(&s2, d);
    printf("Push in S1:%d\n", a.data);
    push(&s1,a);
    printf("Push in S2:%d\n", b.data);
    push(&s2, b);
    printf("Push in S1:%d\n", c.data);
    push(&s1, c);
    printf("Stack1:\n");
    print_elems(s1);
    printf("\n");
    pop(&s1, &result);
    printf("Poped from S1:%d\n", result.data);
    printf("\n");
    printf("Push in S2:%d\n", d.data);
    push(&s2, d);
    printf("Stack2:\n");
    print_elems(s2);


    free(s1.arr);
    free(s2.arr);


    return 0;
}
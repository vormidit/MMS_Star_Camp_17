#include<stdio.h>
#include<stdlib.h>

typedef struct A{
    int data;
}A;

A *arr_begin;

size_t capacity, cur_elem_count;

void init_stack_arr(size_t max_elem_count){   
    capacity = max_elem_count;
    arr_begin = malloc(sizeof(A)*max_elem_count);
    cur_elem_count = 0;

}

int push(A elem){
    if(cur_elem_count == capacity){
        return -1;
    }else{

        *(arr_begin + cur_elem_count) = elem;
        cur_elem_count++;
        return 0;
    }
    

}

int pop(A *result){
    if(cur_elem_count == 0){
        return -1;
    }else{

        *result = *(arr_begin + cur_elem_count -1);
        cur_elem_count--;
        return 0;
    }

}

void print_elems(){

    for(size_t i = 0; i < capacity; i++){
        printf("%d\n", arr_begin[i].data);
    }
}

int main(){

    init_stack_arr(10);
    A a = {3}, b={7}, c={8}, d={12};
    A last;
    push(a);
    push(b);
    push(c);
    print_elems();
    printf("\n");
    pop(&last);
    printf("Poped:%d\n", last.data);
    printf("\n");
    printf("Push:%d\n", d.data);
    push(d);
    print_elems();


    return 0;
}
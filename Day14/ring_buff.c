#include<stdio.h>

#define N 8

double arr[N];
size_t start_index=0, end_index=0;

//enqueue dobavqme nov v end index
//dequeue premahwame ot start index

typedef struct RingBuffer{
    double *arr;
    size_t start_index, end_index;
}RingBuffer;


void print_buffer() {
    for(size_t i = 0; i < N; i++) {
        if(start_index%N <= i && i < end_index) {
            printf("%3.2lf ", arr[i]);
        } else {
            printf(" --- ");
        }
    }
    printf("\n");
    for(size_t i = 0; i < N; i++) {
        if(i == start_index) {
            printf("  S  ");
        } else if(i == end_index) {
            printf("  E  ");
        } else {
            printf("     ");
        }
    }
    printf("\n\n");
}

void enqueue(double data){
    if(end_index - start_index == N){
        printf("Queue is full!");
        return;
    }
    arr[end_index%N] = data;
    end_index++;
}
void dequeue(){
    if(end_index - start_index == 0){
        printf("Queue is empty!");
        return;
    }
    //arr[(start_index & (N-1))] = 0;
    arr[start_index%N] = 0;       
    start_index++;
}


int main(){
    enqueue(1);
    enqueue(2);
    print_buffer();
    enqueue(3);
    enqueue(4);



}

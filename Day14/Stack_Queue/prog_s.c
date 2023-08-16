#include"stack.h"

int main(){

    Data data1;
    Stack *s1 = init_stack();
    push((Data){100}, s1);
    print_stack(*s1);
    push((Data){200}, s1);
    print_stack(*s1);
    push((Data){300}, s1);
    print_stack(*s1);
    push((Data){400}, s1);
    print_stack(*s1);
    pop(&data1, s1);
    print_stack(*s1);
    deinit_stack(s1);

    return 0;
}
#include"stack.h"

int main(){

    Data d;
    printf("Init Stack!\n");
    Stack *s = init_stack();
    printf("Push %d\n", 100);
    push((Data){100}, s);
    printf("Print Stack:\n");
    print_stack(*s);
    printf("Push %d\n", 200);
    push((Data){200}, s);
    printf("Print Stack:\n");
    print_stack(*s);
    printf("Push %d\n", 300);
    push((Data){300}, s);
    printf("Print Stack:\n");
    print_stack(*s);
    printf("Push %d\n", 400);
    push((Data){400}, s);
    printf("Print Stack:\n");
    print_stack(*s);
    printf("Pop %d\n", 400);
    pop(&d, s);
    printf("Print Stack:\n");
    print_stack(*s);
    printf("Pop %d\n", 300);
    pop(&d, s);
    printf("Print Stack:\n");
    print_stack(*s);
    printf("Deinit Stack!\n");
    deinit_stack(s);

    return 0;
}
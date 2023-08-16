#include<stdio.h>
#include<stdlib.h>


typedef struct Data{

    int val;
    
}Data;

typedef struct Node{
    Data d;
    struct Node *prev;
    struct Node *next;

}Node;

typedef struct DLL{

     Node *head;
     Node *tail;
    
}DLL;
typedef  DLL Deque;


Deque* init_deque(){
    
    DLL *dll =(DLL*)malloc(sizeof(DLL));

    if(!dll){
        perror("Could not malloc!");
        exit(-1);
    }
    dll->head = NULL;
    dll->tail = NULL;
    return dll;
}

void enque_front(Data new_data, Deque *dq){
    Node **head = &(dq->head);
    Node **tail = &(dq->tail);
    Node *new = malloc(sizeof(Node));
    new->prev = NULL;
    if(!new){
        perror("Could not malloc!");
        exit(-1);
    }
    if(*tail == NULL && *head == NULL){
        new->d = new_data;
        new->prev = NULL;
        new->next = NULL;
        *head = new;
        *tail = *head;
        return;
    }
    if(*head == *tail && *head != NULL){
        (*head)->prev = new;
        *head = new;
        (*head)->next = *tail;
        return;

    }
    new->d = new_data;
    new->next = *head;
    (*head)->prev = new;
    *head = new;
}

void enque_back(Data new_data, Deque *dq){
    Node **head = &(dq->head);
    Node **tail = &(dq->tail);
    Node *new = malloc(sizeof(Node));
    if(!new){
        perror("Could not malloc!");
        exit(-1);
    }
    new->d = new_data;
    new->next = NULL;

    if(!(*head)){
        *head = new;
        *tail = new;
        (*head)->prev = NULL;
        return;
    }

    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;

}
void deque_front(Data *result, Deque *dq){
    Node **head = &(dq->head);
    Node **tail = &(dq->tail);
    if(!(*head)){
        perror("There are no nodes in deque!");
        exit(-1);
    }
    
    if((*head)->next == NULL){
        if(result){
        *result = (*head)->d;
        }
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }
    if(result != NULL){
        *result = (*head)->d;
    }

    
    Node *temp = (*head);
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}

void deque_back(Data *result, Deque *dq){
    Node **tail = &(dq->tail);
    Node **head = &(dq->head);
    if(!(*tail)){
        perror("There are no nodes in deque!");
        exit(-1);
    }
    if(*tail == *head){
        *result = (*tail)->d;
        free(*tail);
        *tail = NULL;
        *head = NULL;
        return;
    }
    *result = (*tail)->d;
    Node *temp = *tail;

    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    free(temp);
    
}

void print_deque(Deque *dq){
    Node *temp = dq->head;
    while(temp != NULL){
        printf("%d ", temp->d.val);
        temp = temp->next;
    }
    printf("\n");
}
void deinit_deque(Deque *dq){

    while(dq->head){
        deque_front(NULL, dq);
    }
    free(dq);
    
}

int main(){
    Deque *dq = init_deque();
    Data new = { 50};
    Data new1 = { 100}, new2={200}, new3={300}, new4={400};//, new5={.val=500}, new6={.val=600};
    enque_front(new, dq);
    enque_front(new1, dq);
    enque_front(new2, dq);
    print_deque(dq);
    Data res;
    deque_back(&res, dq);
    printf("Result from 1st deque_back is %d\n", res.val);
    print_deque(dq);
    deque_back(&res, dq);
    printf("Result from 2nd deque_back is %d\n", res.val);
    print_deque(dq);
    printf("Enque back 300\n");
    enque_back(new3, dq);
    print_deque(dq);
    deque_front(&res, dq);
    printf("Result from 1st deque_front is %d\n", res.val);
    printf("Enque back 400\n");
    enque_back(new4, dq);
    enque_back(new, dq);

 /*   Data res;
    enque_back(new, dq);
    print_deque(dq);
    enque_back(new1, dq);
    print_deque(dq);
    enque_back(new2, dq);
    print_deque(dq);
    deque_front(&res, dq);
    print_deque(dq);
    deque_front(&res, dq);
    print_deque(dq);
*/

    deinit_deque(dq);
    //free(dq);
    return 0;
}
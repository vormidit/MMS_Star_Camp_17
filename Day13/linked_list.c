#include<stdio.h>
#include<stdlib.h>


typedef struct Data{

    int val;
    
}Data;

typedef struct Node{
    Data d;
    struct Node *next;

}Node;

Node *head, *tail;

void print_linked_list(Node *head){
    printf("%d\n", head->d.val);
    printf("%d\n", head->next->d.val);
    printf("%d\n", head->next->next->d.val);

}
void print_linked_list_auto(Node **head){
    while(*head){
        printf("%d\n", (*head)->d.val);
        *head=(*head)->next;
    }
}

void push_back(Data new_data, Node **head){
    Node *new = malloc(sizeof(Node));
    if(!new){
        perror("Could not malloc!");
        exit(-1);
    }
    new->d = new_data;
    new->next = NULL;

    if(!(*head)){
        *head = new;
        return;
    }
    Node *cur_node = *head;
    
    while(!!cur_node->next){
        
        cur_node = cur_node->next;
    }
    
    cur_node->next = new;

}

void push_back_with_tail(Data new_data, Node **tail){
    
    Node *new = malloc(sizeof(Node));
    new->d = new_data;
    new->next = NULL;
    (*tail)->next = new;
    *tail = new;

}

void pop_back(Node **head, Data *result){

    if(!(*head)){
        perror("Could not pop in empty list!");
        exit(-1);
        return;
    }
    if((*head)->next == NULL){
        *result = (*head)->d;
        free(*head);
        *head = NULL;
        return;
    }
    Node *cur_node = *head;
    
    while(cur_node->next->next != NULL){//Find second last node
        
        cur_node = cur_node->next;
        
    }

    *result = cur_node->next->d;//Save data to result from last node
   //free last node
    free(cur_node->next);
    cur_node->next = NULL;



}

void push_front(Data new_data, Node **head){
    Node *new = malloc(sizeof(Node));
    if(!new){
        perror("Could not malloc!");
        exit(-1);
    }
    new->d = new_data;
    new->next = *head;
    *head = new;  
}

void pop_front(Node **head, Data *result){
    if(*head == NULL){
        perror("Could not pop in empty list!");
        exit(-1);
        return;
    }
    if((*head)->next == NULL){
        *result = (*head)->d;
        free(*head);
        *head = NULL;
        return;
    }
    *result = (*head)->d;
    Node *to_free;
    to_free = *head;
    *head = (*head)->next;
    free(to_free);


}



int main(){

    
    Node *head = NULL;

    


   // print_linked_list(&n1);
    print_linked_list_auto(&head);
    printf("\n");
    Data new1 = {.val = 100}, new2={200}, new3={300};
    printf("Push back data %d %d %d\n", new1.val, new2.val, new3.val);
    push_back(new1, &head);
    push_back(new2, &head);
    push_back(new3, &head);
    
   // push_back_with_tail(new1, &tail);
    print_linked_list_auto(&head);

    Data res;
    pop_back(&head, &res);
    printf("Poped back data: %d\n", res.val);
    printf("\n");
    print_linked_list_auto(&head);
    printf("\n");
    printf("Push front data: %d\n", res.val);
    push_front(new3, &head);
    print_linked_list_auto(&head);
    printf("Poped front data: %d\n", res.val);
    pop_front(&head, &res);
    printf("\n");
    print_linked_list_auto(&head);
   // printf("Tail data: %d\n", tail->d.val);

/*    while(head->next != NULL){

        Node *cur_to_free = head;
        head = head->next;
        free(cur_to_free);
    }
*/

}

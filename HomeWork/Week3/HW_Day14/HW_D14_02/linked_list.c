#include"linked_list.h"



void print_linked_list(LL *ll){
    Node *head = ll->head;
    while(head){
        printf("%d\n", head->d.val);
        head=head->next;
    }
    printf("\n");
}

void push_back(Data new_data, LL *ll){
    Node **head = &(ll->head);
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
    
    while(cur_node->next){
        
        cur_node = cur_node->next;
    }
    
    cur_node->next = new;

}


void pop_back(LL *ll, Data *result){
    Node **head = &(ll->head);
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

void push_front(Data new_data, LL *ll){
    Node **head = &(ll->head);
    Node *new = malloc(sizeof(Node));
    if(!new){
        perror("Could not malloc!");
        exit(-1);
    }
    new->d = new_data;
    new->next = *head;
    *head = new;  
}

void pop_front(LL *ll, Data *result){
    Node **head = &(ll->head);
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
    if(result != NULL){
        *result = (*head)->d;
    }
    
    Node *to_free;
    to_free = *head;
    *head = (*head)->next;
    free(to_free);


}

LL* init_linked_list(){
    LL *ll =(LL*)malloc(sizeof(LL));

    if(!ll){
        perror("Could not malloc!");
        exit(-1);
    }
    ll->head = NULL;
    ll->tail = NULL;
    return ll;
}

void deinit_linked_list(LL *ll){

    while(!(ll->head)){
        pop_front(ll, NULL);
    }
    free(ll);
    
}




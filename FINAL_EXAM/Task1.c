#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<string.h>

#define ITEMS_COUNT 10

typedef struct BankAccount{

    uint16_t number;
    char name[100];
    double saldo;
    char currency[4];

}BankAccount;

typedef struct Node{
    BankAccount b;
    struct Node *next;
}Node;

Node *head;
int rand_arr[ITEMS_COUNT] ={10, 20 ,30, 40, 50, 60, 70, 80, 90, 100};

void gen_word_name(char *name_word){
    int word_len = rand()%(20-1) + 1;
    name_word[0] = rand()%26 + 'A';

    size_t i = 1;
    for(; i < word_len; i++ ){
        int cur_let = rand()%52;
        
        if(cur_let <= 25){
                name_word[i] = cur_let + 'a';
                
        }
        if(cur_let > 25 ) {
            
                name_word[i] = cur_let - 26 + 'A';
        }
    }
    name_word[i] = '\0';
}

void insert_back(BankAccount new_b_acc, Node **head){
    Node *new = malloc(sizeof(Node));
    if(!new){
        perror("Could not malloc!");
        exit(-1);
    }
    new->b = new_b_acc;
    new->next = NULL;

    if(!(*head)){
        *head = new;
        return;
    }
    Node *cur_node = *head;
    
    while(cur_node->next != NULL){
        
        cur_node = cur_node->next;
    }
    
    cur_node->next = new;

}

double totalBalance(Node *head){

    double total_bal = 0;

    if(head == NULL){
        printf("No bank acc in LL!\n");
        return -1;
    }
    Node *cur_head = head;
    while(cur_head != NULL){

        total_bal += cur_head->b.saldo;
        cur_head = cur_head->next;
    }

   return total_bal;
 
}

Node *maxBalance(Node* head){

    if(head == NULL){
        printf("No bank acc in LL!\n");
        return NULL;
    }

    Node *cur_head = head, *cur_max_saldo_node = head;

    while(cur_head->next != NULL){
        
        if(cur_head->next->b.saldo > cur_head->b.saldo){
            cur_max_saldo_node = cur_head->next;
        }

        cur_head = cur_head->next;

    }

    return cur_max_saldo_node;

}

void print_linked_list(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        
        printf("\n");
        printf("Number: ");
        printf("%hu ", temp->b.number);
        printf(" ");
        printf("Name: ");
        for(size_t j = 0; j < strlen(temp->b.name)+1; j++){
            printf("%c", temp->b.name[j]);
        }
        printf(" ");
        printf("Saldo: %lf  ", temp->b.saldo);
        printf("Currency: ");
        for(size_t j = 0; j < strlen(temp->b.currency)+1; j++){
            printf("%c", temp->b.currency[j]);
        }
        
        temp = temp->next;
    }
    
 }
 void deinit(Node **head){
    if(*head == NULL){
        perror("Could not pop in empty list!");
        exit(-1);
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    Node *to_free;
    to_free = *head;
    *head = (*head)->next;
    free(to_free);

}





int main(){
    head = NULL;

    char *currency_arr[3] = {"lv", "eu", "dlr"};
    
    for(size_t i = 0; i < ITEMS_COUNT; i++){

        BankAccount new;
        srand(rand_arr[i]);
        new.number = 1000000000 + rand()%(1000000000);
        

        //For Name 
        char name_word[20];

       

        size_t i = 0;
        int len_name = rand()%(5-2) + 2;
        int cur_len_gen_word = 0;
        for(; i < len_name; i++){
            
            gen_word_name(name_word);
            sprintf(new.name + cur_len_gen_word, "%s ", name_word); 
            cur_len_gen_word = strlen(name_word);     
        }
        new.name[i] = '\0';
        
        new.saldo = (rand()%(10000000))/100.;
        
        int cur_currency = rand()%3;

        sprintf(new.currency, "%s", currency_arr[cur_currency]);
        
        insert_back(new, &head);


    }

    print_linked_list(&head);
    printf("\n");
    printf("Total Balance for Bank Acc is: %lf\n", totalBalance(head));

    Node *node_max_saldo = maxBalance(head);

    if(node_max_saldo == NULL){
        printf("Pointer is NULL!\n");
    }
    printf("\n\n");
    printf("Bank acc with high saldo is: ");
    
    printf("Number: ");
    printf("%hu ", node_max_saldo->b.number);
    printf(" ");
    printf("Name: ");
    for(size_t j = 0; j < strlen(node_max_saldo->b.name)+1; j++){
        printf("%c", node_max_saldo->b.name[j]);
    }
    printf(" ");
    printf("Saldo: %lf  ", node_max_saldo->b.saldo);
    printf("Currency: ");
    for(size_t j = 0; j < strlen(node_max_saldo->b.currency)+1; j++){
        printf("%c", node_max_saldo->b.currency[j]);
    }

    deinit(&head);


    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


#define COUNT 10

typedef struct Book{
    char title[150];
    char author[100];
    unsigned int num_page;
    double price;
    
}Book;

typedef struct Node{
    Book book;
    struct Node *next;

}Node;

Node *head;



void print_linked_list(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        
        printf("\n");
        printf("Title: ");
        for(size_t j = 0; j < strlen(temp->book.title); j++){
            printf("%c ", temp->book.title[j]);
        }
        printf("\n");
        printf("Author: ");
        for(size_t j = 0; j < strlen(temp->book.author); j++){
            printf("%c ", temp->book.author[j]);
        }

        printf("\n");
        printf("Pages: %u\n", temp->book.num_page);
        printf("Price: %.2lf\n", temp->book.price);
        
        temp = temp->next;
    }
    
 }


void push_back(Book new_book, Node **head){
    Node *new = malloc(sizeof(Node));
    if(!new){
        perror("Could not malloc!");
        exit(-1);
    }
    new->book = new_book;
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

void pop_front(Node **head, Book *result){
    if(*head == NULL){
        perror("Could not pop in empty list!");
        exit(-1);
        return;
    }
    if((*head)->next == NULL){
        *result = (*head)->book;
        free(*head);
        *head = NULL;
        return;
    }
    *result = (*head)->book;
    Node *to_free;
    to_free = *head;
    *head = (*head)->next;
    free(to_free);


}

int cmp_title(const void *p1, const void *p2){
    Book *b1 = (Book*)p1;
    Book *b2 = (Book*)p2;
    return strcmp(b1->title, b2->title);

}

void sort_ll(Node **head){
    Book arr[COUNT];

    for(size_t i =0; i < COUNT; i++){
        pop_front(head, &arr[i]);
    }
    //Qsort array of books
    qsort(arr, COUNT, sizeof(Book), cmp_title);

    for(size_t j = 0; j < COUNT; j++){
        push_back(arr[j], head);
    }
}




int main(){

    head = NULL;
    
    for(size_t i = 0; i < COUNT; i++){

        Book new;
        size_t n_char_title = 10 + rand()%(20-10);
        size_t n_char_author = 10 + rand()%(20-10);
        

        //For Title 
        size_t j = 0;
        for(; j < n_char_title+1; j++){
            size_t k_title = rand()%52;
            
            if(k_title <= 25){
                new.title[j] = k_title + 'a';
                
            }
            if(k_title > 25 ) {
            
                new.title[j] = k_title - 26 + 'A';
            }
                
        }
        new.title[j] = '\0';//Terminating symbol adding

        //For Author name
        size_t p = 0;
        for(; p < n_char_author+1; p++){
            size_t k_author = rand()%52;

            if(k_author <= 25){
                
                new.author[p] = k_author + 'a';
            }
            if(k_author > 25) { 
                new.author[p] = k_author - 26 + 'A';
            }
                
        }
        new.author[p] = '\0';//Terminating symbol adding


        new.num_page = 5 +  rand()%(2001-5);
        new.price = (100 + rand()%100100)/100.;
        
        push_back(new, &head);
        
    }
    print_linked_list(&head);
    sort_ll(&head);
    printf("\n");
    printf("*********Sorted LL******** \n");
    print_linked_list(&head);
 


    free(head);
    
    return 0;
}
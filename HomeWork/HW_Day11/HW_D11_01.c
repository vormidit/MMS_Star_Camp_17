#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define COUNT 10



typedef struct Book{

    char title[150];
    char author[100];
    size_t pages;
    float price;

}Book;

int cmp_title(const void *p1, const void *p2){
    const Book *b1 = (Book *)p1;
    const Book *b2 = (Book *)p2;
   return strcmp(b1->title ,b2->title);

}
int cmp_author(const void *p1, const void *p2){
    const Book *b1 = (Book *)p1;
    const Book *b2 = (Book *)p2;

   return strcmp(b1->author ,b2->author);

}
int cmp_pages(const void *p1, const void *p2){
    const Book *b1 = (Book *)p1;
    const Book *b2 = (Book *)p2;

   return b1->pages - b2->pages;

}
int cmp_price(const void *p1, const void *p2){
    const Book *b1 = (Book *)p1;
    const Book *b2 = (Book *)p2;

   return b1->price - b2->price;

}


int main(){
    Book arr[COUNT];
    

    
    for(size_t i =0; i < COUNT; i++){
        //srand(time(NULL));
        size_t size_str_title = 10 + rand()%(20 - 10);
        size_t m = 0;
        for( ;m < size_str_title + 1; m++){
            int cur_L = rand()%52;
            if(cur_L <= 25){
                arr[i].title[m] = 'a' + cur_L;
            }else if(cur_L > 25){
                arr[i].title[m] = 'A' + cur_L-26;
            } 
             
            
        }
        arr[i].title[m] = '\0';

        //srand(time(NULL));
        size_t size_str_author = 10 + rand()%(20 - 10);
        size_t n = 0;
        for(; n < size_str_author + 1; n++){
            int cur_L = rand()%52;
            if(cur_L <= 25){
                arr[i].author[n] = 'a' + cur_L;
            }else if(cur_L > 25){
                arr[i].author[n] = 'A' + cur_L-26;
            }
            
        }
        arr[i].author[m] = '\0';
        
        arr[i].pages = 5 + rand()%(2000-5);
        arr[i].price = (100 + rand()%(100000 - 100))/100.;
        
    }


    qsort(arr, COUNT, sizeof(Book), cmp_title);
    printf("\n");
     printf("Сортирания масив по заглавие е:\n");
     printf("\n");
    for(size_t i =0; i < 10; i++){
        printf("Заглавие: ");
        size_t title_size = strlen(arr[i].title);
        for(size_t j = 0; j < title_size; j++){
            printf("%c ", arr[i].title[j]);
        }
        printf("\n");
        printf("Автор: ");
        size_t author_size =  strlen(arr[i].author);
        for(size_t j = 0; j < author_size ;j++){
            printf("%c ", arr[i].author[j]);
        }
        printf("\n");
        printf("Страници: %lu\n", arr[i].pages);
        printf("Цена: %.2lf\n", arr[i].price);
        printf("\n");
         
    }
    printf("\n\n");
    qsort(arr, COUNT, sizeof(Book), cmp_author);
    printf("\n");
     printf("Сортирания масив по автор е:\n");
     printf("\n");
    for(size_t i =0; i < 10; i++){
        printf("Заглавие: ");
        size_t title_size = strlen(arr[i].title);
        for(size_t j = 0; j < title_size; j++){
            printf("%c ", arr[i].title[j]);
        }
        printf("\n");
        printf("Автор: ");
        size_t author_size =  strlen(arr[i].author);
        for(size_t j = 0; j < author_size; j++){
            printf("%c ", arr[i].author[j]);
        }
        printf("\n");
        printf("Страници: %lu\n", arr[i].pages);
        printf("Цена: %.2lf\n", arr[i].price);
        printf("\n");
         
    }
    printf("\n\n");
    qsort(arr, COUNT, sizeof(Book), cmp_pages);
    printf("\n");
     printf("Сортирания масив по старници е:\n");
     printf("\n");
    for(size_t i =0; i < 10; i++){
        printf("Заглавие: ");
        size_t title_size = strlen(arr[i].title);
        for(size_t j = 0; j < title_size; j++){
            printf("%c ", arr[i].title[j]);
        }
        printf("\n");
        printf("Автор: ");
        size_t author_size =  strlen(arr[i].author);
        for(size_t j = 0; j < author_size; j++){
            printf("%c ", arr[i].author[j]);
        }
        printf("\n");
        printf("Страници: %lu\n", arr[i].pages);
        printf("Цена: %.2lf\n", arr[i].price);
        printf("\n");
         
    }
    printf("\n\n");
    qsort(arr, COUNT, sizeof(Book), cmp_price);
    printf("\n");
    printf("Сортирания масив по цена е:\n");
    printf("\n");
    for(size_t i =0; i < 10; i++){
        printf("Заглавие: ");
        size_t title_size = strlen(arr[i].title);
        for(size_t j = 0; j < title_size; j++){
            printf("%c ", arr[i].title[j]);
        }
        printf("\n");
        printf("Автор: ");
        size_t author_size =  strlen(arr[i].author);
        for(size_t j = 0; j < author_size; j++){
            printf("%c ", arr[i].author[j]);
        }
        printf("\n");
        printf("Страници: %lu\n", arr[i].pages);
        printf("Цена: %.2lf\n", arr[i].price);
        printf("\n");
         
    }



    return 0;
}
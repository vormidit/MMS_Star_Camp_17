#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CAP 100
#define PLUS '+'
#define MINUS '-'
#define MULT '*'

typedef struct C{
   int i;
   char c;
}C;

size_t capacity, cur_elem_count;
C *arr_begin;

void init_stack(size_t max_elem_count) {
    capacity = max_elem_count;
    cur_elem_count = 0;
    arr_begin = calloc(max_elem_count, sizeof(C));
}

int push(C elem) {
    
    if(capacity == cur_elem_count) {
        return -1;
    }
    
    arr_begin[cur_elem_count] = elem;
    cur_elem_count++;
    return 0;
}

int pop(C *res) {
    
    if(cur_elem_count == 0) {
        return -1;
    }

    if(res) {
        *res = arr_begin[cur_elem_count - 1];
    }
    cur_elem_count--;
    return 0;
}

int main(){
    char *s = malloc(sizeof(char)*20);
    init_stack(CAP);
    if(!s || !arr_begin){
      printf("Can not malloc mem!\n");
      return -1;
    }
    printf("Input Reverse Polish Notation:\n");
    scanf("%s", s);
    printf("String: %s\n", s);
    size_t size = strlen(s);
    C *arg1 = malloc(sizeof(C));
    C *arg2 = malloc(sizeof(C));
    
    for(size_t i =0; i < size; i++){
      if(s[i] == PLUS){
         pop(arg2);
         pop(arg1);
         arg1->i += arg2->i;
         push(*arg1);
      }else if(s[i] == MINUS){
         pop(arg2);
         pop(arg1);
         arg1->i -= arg2->i;
         push(*arg1);
      }else if(s[i] == MULT){
         pop(arg2);
         pop(arg1);
         arg1->i *= arg2->i;
         push(*arg1);
      }else{
         char c = s[i];
         C new_arg ={ .i=atoi(&c), .c =c};
         push(new_arg);
         
      }
      
    }
    pop(arg1);
    printf("Result: %d\n", arg1->i);
    


   free(arr_begin);
   free(arg1);
   free(arg2);
   return 0;
}
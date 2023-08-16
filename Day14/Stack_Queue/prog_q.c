#include"queue.h"

int main(){

  //  LL *ll = init_linked_list();
   // print_linked_list(&n1);
 //   print_linked_list(ll);
  //  printf("\n");
 //   Data new1 = {.val = 100}, new2={200}, new3={300};
 //   printf("Push back data %d %d %d\n", new1.val, new2.val, new3.val);
 //   push_back(new1, ll);
 //   push_back(new2, ll);
  //  push_back(new3, ll);
    
   // push_back_with_tail(new1, &tail);
    Data data1;
    Queue *q1 = init_queue();
    enque((Data){100}, q1);
    print_queue(*q1);
    enque((Data){200}, q1);
    print_queue(*q1);
    enque((Data){300}, q1);
    print_queue(*q1);
    enque((Data){400}, q1);
    print_queue(*q1);
    dequeue(&data1, q1);
    print_queue(*q1);
    deinit_queue(q1);

    return 0;
}
#include"linked_list.h"

int main(){

    LL *ll = init_linked_list();
    
    

    


   // print_linked_list(&n1);
    print_linked_list(ll);
    printf("\n");
    Data new1 = {.val = 100}, new2={200}, new3={300};
    printf("Push back data %d %d %d\n", new1.val, new2.val, new3.val);
    push_back(new1, ll);
    push_back(new2, ll);
    push_back(new3, ll);
    
   // push_back_with_tail(new1, &tail);
    
}
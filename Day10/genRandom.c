#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* genRandom(size_t elem_c){
    void *mem = malloc(elem_c*sizeof(int));
    int *pi = mem;
    for(size_t i = 0; i < elem_c; i++){
        pi[i] = rand()%200 - 100;
    }
    

    return mem;

}

int main(){
    int *p_i  = genRandom(10);
    for(size_t i = 0; i < 10; i++){
        printf(">%d\n", p_i[i]);
    }
    free(p_i);
    
    return 0;
}
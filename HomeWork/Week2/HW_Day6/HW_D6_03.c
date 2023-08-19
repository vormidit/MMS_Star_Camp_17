#include<stdio.h>

void filter_and_map(const int arr[], 
                    size_t n,
                    int (*filter_f)(int), 
                    int (*map_f)(int), 
                    int dest[],
                    size_t* dest_cnt
                   )
{
size_t cnt = 0;
for(int i = 0; i < n; i++){
    if(filter_f(arr[i])){
        dest[cnt++] = map_f(arr[i]);
    }
}
if(dest != NULL)*dest_cnt = cnt;


}

int isPositive(int a){
    if(a > 0)return 1;
    else return 0;
}

int addOne(int a){
    return ++a;
}




int main(){

    const int arr[8] ={1,2,3,4,-1,-2,11,-100};
    int dest[10];
    size_t new_size;

    filter_and_map(arr, 8, isPositive, addOne, dest, &new_size);
    printf("New size: %lu\n", new_size);
    for(int i =0; i < new_size; i++) printf("Array[%d]: %d\n", i, dest[i]);





    return 0;
}
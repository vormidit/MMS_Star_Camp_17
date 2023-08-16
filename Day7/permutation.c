#include<stdio.h>

int arr[10]={1,2,3, 4, 5};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutations(size_t begin, size_t total_count){
    //Base case
    if(begin == total_count){
        for(size_t i = 0; i < total_count; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");

    }//обхождаме всички кандидати за 1ви елемент
    for(size_t i = begin; i < total_count; i++){
        //arr[i] текущ елемент
        swap(arr + begin, arr + i);
        permutations(begin +1, total_count );
        swap(arr+begin, arr + i);
        

    }  

}


        

int main(){

    permutations(0, 5);

    return 0;
}
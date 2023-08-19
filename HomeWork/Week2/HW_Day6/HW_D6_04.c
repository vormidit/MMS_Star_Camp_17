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

int printNum(int a){
    return printf("%d\t", a);
}


int isPrime(int a){

    if (a == 0 || a == 1) return 0;
    
    for (int i = 2; i <= a / 2; i++) {

        if (a % i == 0) return 0;
        
    }
    return 1;   
}

int isEven(int a){
    if(a % 2 == 0) return 1;
    return 0;
}

int Pow(int a){
    return a * a;
}

int isPositive(int a){
    if(a > 0)return 1;
    else return 0;
}

int bits_1_cnt(int a){
    int cnt = 0;
    for(int i = 0; i < sizeof(int)*8; i++){
       if(a & (1UL << i)) cnt++;
    }
    return cnt;
}


int main(){

    const int arr[8] ={1,2,3,4,-1,-2,11,-100};
    int dest[10];
    size_t new_size;

    printf("Original Array: \n");
    for(int i =0; i < 8; i++) printf("A[%d]:%d ", i, arr[i]);
    printf("\n");
    
    printf("Only even numbers: \n");
    filter_and_map(arr, 8, isEven, printNum, dest, &new_size);
    printf("New size: %lu\n", new_size);
    for(int i =0; i < new_size; i++) printf("Array[%d]: %d\n", i, dest[i]);
    printf("\n");

    printf("Power for prime numbers: \n");
    filter_and_map(arr, 8, isPrime, Pow, dest, &new_size);
    for(int i =0; i < new_size; i++) printf("Array[%d]: %d\n", i, dest[i]);
    printf("\n");

    printf("Set bits to 1 only in positive numbers: \n");
    filter_and_map(arr, 8, isPositive, bits_1_cnt, dest, &new_size);
    for(int i =0; i < new_size; i++) printf("Count to set bits to 1 in dest[%d]: %d\n", i, dest[i]);





    return 0;
}
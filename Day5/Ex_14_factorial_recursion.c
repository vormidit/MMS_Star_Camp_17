#include<stdio.h>
int factorial(int n);
int factorial_rec(int n);


int factorial(int n){
    
    for(int i = n-1; i != 0 ; i--) n *= i;

    return n;
}

int factorial_rec(int n){
     if(n==0||n==1) return 1;
  
  return n * factorial_rec(n-1);
}



int main(int argc, char* argv[]){
   
   int n = 6;

   printf("Factorial For with %d is : %d\n", n, factorial(n));
   printf("Factorial Rec with %d is : %d\n", n, factorial_rec(n));


}
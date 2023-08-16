#include<stdio.h>
#include<signal.h>

void onInterrupt(int sigNum){
    printf("Can not interrupt\n");
}

int main(){

    signal(SIGINT, onInterrupt);

   while(1){
    printf("Hello World!\nq");
   }


    return 0;
}
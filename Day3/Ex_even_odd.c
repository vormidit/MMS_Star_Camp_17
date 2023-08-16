#include<stdio.h>


int main(int argc, char* argv[]){

    int my_num = 0;

    printf("Моля въведете числото:\n");
    scanf("%d", &my_num);


    if((my_num % 2) == 1){
        printf("Числото е НЕЧЕТНО!\n");
    }
    else{
      printf("Числото е ЧЕТНО!\n");          
    }
    return 0;
}

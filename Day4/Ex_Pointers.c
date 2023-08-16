#include<stdio.h>


//Главна функция
int main(int argc, char* argv[]){
    int num = 5;
    int *ptr = &num;

    printf("Our num is: %d\n", num);//Стойността на променливата
    printf("Our pointer to num is: %p\n", ptr);//0x7ffed866b79c  Адреса на променливата записан в указателя

    int value = *ptr;
    printf("Our value from *ptr is: %d\n", value);

    if(num == value){
        printf("Equals!\n");
    }
    //Присвояване на стойност по адрес на променливата
    *ptr = 20;

    printf("Value in  value is: %d\n", value);
    printf("Our new value in num is: %d\n", num);

    return 0;
}
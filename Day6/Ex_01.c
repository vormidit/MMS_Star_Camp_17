#include<stdio.h>

int my_strlen(const char* str);//Връща дължината на стринга
void my_strcat(char* dest,const char* src);//Добавя src към dest
void my_strcpy(char* dest,const char* src);//Копира src в dest
int my_strcmp(char* str1,const char* str2);//Сравнява двата стринга


int my_strlen(const char* str) {
    int counter =0;
    while(str[counter]){
       counter++;
    }
    return counter;
}

void my_strcpy(char* dest, const char* src){
    while(*src){

        *(dest++) = *(src++);
    }
    *dest = '\0';


}

void my_strcat(char* dest, const char* src){

    dest += my_strlen(dest);
    while(*src){
      *(dest++) = *(src++);
    }
    *dest = '\n';
}

//void my_strcat2(char* dest,const char* src){
//    my_strcmp(dest + my_strlen(dest), src);
//}

int my_strcmp(char* str1,const char* str2){

    while(*str1 == *str2 && *str1 ){
        str1++;
        str2++;
    }
    return *str1 - *str2;

}


int main(){

    char str1[100] = "Hello world!";
    char str2[100]= "ABCDKUHLKH", str3[100] = "HELLO";

    printf("Array is: %s\n", str1);
    printf("Lenght of array is: %d\n", my_strlen(str1));

    my_strcat(str1, str3);
    printf("Strcat: %s\n", str1);

    my_strcpy(str3, str1);
    printf("Strcpy: %s\n", str3);

    printf("Strcmp: %d\n", my_strcmp(str1, str2));



    




    return 0;
}
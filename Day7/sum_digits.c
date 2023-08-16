#include<stdio.h>
#include<stdint.h>
#include<string.h>

int atoi_rev(const char *str_rev){
    if(!(*str_rev)){
        return 0;
    }
    
    return (*str_rev - '0') + atoi_rev(str_rev+1)*10;
}

void reverse(const char *str1, char *str2){

    str2 +=  strlen(str1);
    *str2-- = '\0';
    while(*str1){
        *str2-- = *str1++;
    }

}


char* reverse2(const char *str1){
    size_t n = strlen(str1);
    char res[n];//Не може да се прави така, масива се губи
    for(int i =n; i >= 0; i--){
        res[i] = *str1++;    
    }
    return res;

}

uint64_t sumDigits(uint64_t a){

    if(a<10){
        return a;
    }
    return sumDigits(a/10) + a%10;
}

int fact(int n){

    if(n == 0 )return 1;

    return n*fact(n-1);
}

int main(){
    char str1[10]= "1234", str2[10];
    reverse(str1, str2);
    char str3[10] = "1234";
    char *str_rev = reverse2(str3);
    int res = atoi_rev(str_rev);



    return 0;
}
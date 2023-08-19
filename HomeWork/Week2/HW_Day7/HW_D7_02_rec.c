#include<stdio.h>
#include<stdint.h>
#include<string.h>

#define ZNUM '0'
#define PLUS '+'
#define MULT '*'
#define POW '^'
#define L_BRACKET '('
#define R_BRACKET ')'

int f_lb=0, f_rb=0, f_plus=0, f_mult=0, f_pow=0, num;

int parser(char *str){
    if(!(*str)) return 0;

    switch(*str){
        case L_BRACKET:
            f_lb++;
            parser(str+1);
            break;
        case PLUS:
            f_plus++;
            parser(str+1);
            break;
        case MULT:
            f_mult++;
            parser(str+1);
            break;
        case POW:
            f_pow++;
            parser(str+1);
            break;
        case R_BRACKET:
            f_rb++;
            parser(str+1);
            break;
        default:
            num = *str - ZNUM;
            parser(str+1);
            break;


    }
    
}



int main(){
    char str1[]= "152"; 
    char str2[]= "12";
    char str3[] = "1";
    char str4[]= "0"; 
    char str5[]= "(5+3)";
    char str6[] = "(6^21)";
    char str7[]= "(22+(12^3))"; 
    char str8[]= "(13^(2+(1+1)))";
    char str9[] = "(5+(3+(4+2))+(2^10))";

    parser(str9);
    printf("lb:%d rb:%d plus:%d mult:%d num:%d\n",f_lb, f_rb, f_plus, f_mult, num);


    return 0;
}
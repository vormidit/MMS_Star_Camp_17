#include<stdio.h>
#include<inttypes.h>

typedef union A{
    char c;
    double d;
    int i;

}A;


typedef struct Arg{
    A argval;
    int argtype;

}Arg;

void print(Arg a){

    switch(a.argtype){

        case 0:{
            printf("%c\n", a.argval.c);
            break;
        }
        case 1:{
            printf("%lf\n", a.argval.d);
            break;
        }
        case 2:{
            printf("%d\n", a.argval.i);
            break;
        }

    }

}

int main(){
    Arg argchar;
    argchar.argtype = 0;
    argchar.argval.c = 'W';
    print(argchar);
    
    Arg argdouble;
    argdouble.argtype = 1;
    argdouble.argval.d = 3.14;
    print(argdouble);

    Arg argint;
    argint.argtype = 2;
    argint.argval.i = 34;
    print(argint);
    return 0;
}
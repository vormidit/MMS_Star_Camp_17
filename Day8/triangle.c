#include<stdio.h>
#include<math.h>

int triangle(double a, double b, double c, double *area, double *perimeter){

    if(a <= 0 || b <= 0 || c <= 0 || a+b < c || b+c <=a || c+a <= b){
        return -1;
    } 

    *perimeter = a + b + c;
    double HP = *perimeter / 2;
    *area = sqrt(HP * (HP - a) * (HP - b) * (HP - c) );

    return 0;
}



int main(){
 
    double A, P;
    double  a, b, c;
    int scanfRes;//Може и без тази променлива
    //**************************************

     while((scanfRes=scanf("%lf %lf %lf", &a ,&b,&c)) == 3){
        if(triangle(a,b,c,&A, &P) == -1){
            printf("Невалидни данни!\n");

        }else{
            printf("Area:%lf  \n Perimeter:%lf\n", A, P);
        }
     }


    //****************************************

 /*  printf("Въведи a= , b= , c= \n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    
    int res = triangle(a, b, c, Area, Perimeter);
    if(!res){
        printf("Area:%lf   Perimeter:%lf\n", *Area, *Perimeter);
        
        

        return 0;
    }else if(res == -1){
        printf("Невалидни данни!\n");
        return 0;
    }
    */
    
}
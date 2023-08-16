#include<stdio.h>
#include<math.h>

#define PI 3.141592

int cylinder(double r, double h, double* V, double* S);

int cylinder(double r, double h, double* V, double* S){

    if(r <= 0 || h <= 0){
        return -1;
    }else{
       
       *S = 2*PI*r*h;

       *V = PI*pow(r,2)*h;

        return 0;

    }

    

   

}






int main(){

    double r, h, v, s;
    double *V = &v, *S = &s;

    do{
        printf("Въведете радиус R и височина H:");
        scanf("%lf %lf", &r, &h);

        if(cylinder(r, h, V, S) == -1){
            printf("Въведените данни са некоректни!\n");
            
            
        }else{
           cylinder(r, h, V, S);
           printf("Лицето на цилиндъра е %lf, а височината му е %lf\n", *S, *V);

        }
        
    }while(r != 0 && h != 0);

    


}
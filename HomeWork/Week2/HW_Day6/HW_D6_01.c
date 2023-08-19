#include <stdio.h>

float cube_root(float x);

float cube_root(float x){
   

   for(float i = 1.0; i < x; i+= 0.01){
      if(((i*i*i) - x) > -0.1 && ((i*i*i)- x) < 0.1){
         return i;
      }
   } 
   return 0;
}



int main(){
    

    float d;
    printf("Input number for cube root:\n");
    scanf("%f", &d);
    printf("Cube root for %.2f is %.2f\n", d, cube_root(d));

    return 0;
}
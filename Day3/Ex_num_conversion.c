#include<stdio.h>


int main(int argc, char* argv[]){

    int decimal_number;//Desetichoto chislo
    
    printf("Input decimal number:");// Vavejdane na chislo ot potrebitelq
    scanf("%d", &decimal_number);


    while(decimal_number > 0){
      int current_bin_num = decimal_number % 2;//Delim desetichnoto chislo kato vzemame ostatyka
      
      printf("Binary position number: %d  \n", current_bin_num);//Pechatim ostatycite kato chast ot dvoichnoto chislo
      
      decimal_number /= 2;//Delim chisloto na 2 za da prodaljim s ostanalata chast
     }
   
    return 0;

}
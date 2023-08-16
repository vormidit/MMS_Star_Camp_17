#include<stdio.h>

int main(int argc, char* argv[]){
 
    int e_o , number, counter = 0;

    printf("Изберете четно или нечетно число, изберете 1 за четно и 0 за нечетно:\n");
    scanf("%d", &e_o);
    printf("Изберете колко наброй числа да се отпечатат:\n");
    scanf("%d", &number);

    for(int i=0; i<100; i++){

        if(counter == number) break;

        if(e_o == 1 && (i % 2 == 0)){   // Потребителя иска да са четни числа
         
         printf(">%d\n", i);
         counter++;
         continue;

        }
        else if(e_o == 0 && (i % 2 == 1))
        {   // Нечетни числа
                      
          printf(">%d\n", i);
          counter++;
          continue;
        

        }

        


    }




 
return 0;
}//end of main
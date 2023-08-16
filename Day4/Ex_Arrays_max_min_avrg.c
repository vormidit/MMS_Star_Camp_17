#include<stdio.h>

 int max(int []);
 int min(int []);
 int avrg(int []);

//Максимална стойност
int max(int pa[]){
    int curr_max = pa[0];
    for(int i = 0; i < *pa; i++){

        if (pa[i] > curr_max){
            curr_max = pa[i];
        }
    }
 return curr_max;
}
//Минимална стойност
int min(int pa[]){
    int curr_min = pa[0];
    for(int i = 0; i < *pa; i++){

        if (pa[i] < curr_min){
            curr_min = *pa + i;
        }
    }
return curr_min;
}
//Средно аритметично
int avrg(int pa[]){
    int curr_avrg = 0;
    int count = 1;
    for(int i = 0; i < *pa; i++){

        curr_avrg += pa[i];
        count++;

    }
return curr_avrg / count;
}

//Главна функция
int main(int argc, char* argv[]){
    
    
    int myarr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    printf("Max in array is: %d\n", max(myarr));
    printf("Min in array is: %d\n", min(myarr));
    printf("Average in array is: %d\n", avrg(myarr));
    
     


    return 0;
}
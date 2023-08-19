#include<stdio.h>


int cmpInt(const void *elem1, const void *elem2){

    return *((int*)elem1) > *((int*)elem2) ? -1 : 1;

}
int cmpChar(const void *elem1, const void *elem2){

    return *((char*)elem1) > *((char*)elem2) ? -1 : 1;



}
int cmpFloat(const void *elem1, const void *elem2){


    return *((float*)elem1) > *((float*)elem2) ? -1 : 1;


}
int cmpDouble(const void *elem1, const void *elem2){


    return *((double*)elem1) > *((double*)elem2) ? -1 : 1;


}


void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)){

    void *temp_max = arr;
    for(size_t i = 0; i < n; i++){
        
        if(cmp((char*)arr+i*elem_s, temp_max) == -1){
            	
            temp_max = (char*)arr+i*elem_s;
            
        } 
    }

    return temp_max;
}
int main(){

    int arr_i[] = {1,2,-1,3,5,11,12,1};
    char arr_c[] = {'1','2','1','3','5','8','9','1'};
    float arr_f[] = {0.57,8.36,-22.478,45.23,7.123,15.0,0.654,-0.484};
    double arr_d[] = {0.57,8.36,-22.478,45.23,7.123,15.0,0.654,-0.484};
	int *max_i = findMax(arr_i, sizeof(arr_i)/sizeof(int), sizeof(int), cmpInt);
    char *max_c = findMax(arr_c, sizeof(arr_c)/sizeof(char), sizeof(char), cmpChar);
    float *max_f = findMax(arr_f, sizeof(arr_f)/sizeof(float), sizeof(float), cmpFloat);
    double *max_d = findMax(arr_d, sizeof(arr_d)/sizeof(double), sizeof(double), cmpDouble);
	printf("%d\n", *max_i);	
    printf("%c\n", *max_c);	
    printf("%f\n", *max_f);	
    printf("%lf\n", *max_d);	
	return 0;


    return 0;
}
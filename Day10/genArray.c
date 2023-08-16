#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init_int(void *int_adr){
    *((int*) int_adr) = 26;

}

void init_char(void *char_adr){
    *((char*) char_adr) = 'A';

}

void init_float(void *float_adr){
    *((float*) float_adr) = 13.5684;

}
void init_double(void *double_adr){
    *((double*) double_adr) = 26.547896;

}



void* genArray(void (*init_elem)(void*), size_t elem_c, size_t elem_size){
    
    void *mem = malloc(elem_c*elem_size);
    size_t i = 0;
    while(i < elem_c){
        init_elem((char*)mem + i*elem_size);
        i++;
        
    }

    return mem;

}

int main(){
    char *p_c  = genArray(init_char, 5, sizeof(char));
    int *p_i  = genArray(init_int, 5, sizeof(int));
    float *p_f  = genArray(init_float, 5, sizeof(float));
    double *p_d  = genArray(init_double, 5, sizeof(double));
    
    for(size_t i = 0; i < 5; i++){
        printf(">%c\n", p_c[i]);
    }
    printf("\n");
    for(size_t i = 0; i < 5; i++){
        printf(">%d\n", p_i[i]);
    }
    printf("\n");
    for(size_t i = 0; i < 5; i++){
        printf(">%f\n", p_f[i]);
    }
    printf("\n");
    for(size_t i = 0; i < 5; i++){
        printf(">%.10lf\n", p_d[i]);
    }
    printf("\n");

    free(p_i);
    free(p_c);
    free(p_f);
    free(p_d);
    
    return 0;
}
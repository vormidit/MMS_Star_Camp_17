#include <stdio.h>
#include <stdint.h>

#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8_T 5
#define TUINT16_T 6
#define TUINT32_T 7
#define TUINT64_T 8

void printValue(const void* valuePtr, uint8_t flag);

void printValue(const void* valuePtr, uint8_t flag){

    switch(flag){
        case TINT:
            printf("Value: %d\n", *((int*)valuePtr));
            break;
        
        case TCHAR:
            printf("Value: %c\n", *((char*)valuePtr));
            break;
        case TDOUBLE:
            printf("Value: %lf\n", *((double*)valuePtr));
            break;
        case TFLOAT:
            printf("Value: %f\n", *((float*)valuePtr));
            break;
        case TUINT8_T:
            printf("Value: %hu\n", *((uint8_t*)valuePtr));
            break;
        case TUINT16_T:
            printf("Value: %u\n", *((uint16_t*)valuePtr));
            break;
        case TUINT32_T:
            printf("Value: %u\n", *((uint32_t*)valuePtr));
            break;
        case TUINT64_T:
            printf("Value: %lu\n", *((uint64_t*)valuePtr));
            break;
        
        default:
           printf("Flag is undefined!\n");


        break;
     


    }
    

    
}



int main(){
    

    char c = 'A';
    int i = 23;
    float f = 3.14;
    double d = 8.432;
    uint8_t ui8 = UINT8_MAX;
    uint16_t ui16 = UINT16_MAX;
    uint32_t ui32 = UINT32_MAX;
    uint64_t ui64 = UINT64_MAX;

    printValue(&i, TINT);
    printValue(&d, TDOUBLE);
    printValue(&f, TFLOAT);
    printValue(&c, TCHAR);
    printValue(&ui8, TUINT8_T);
    printValue(&ui16, TUINT16_T);
    printValue(&ui32, TUINT32_T);
    printValue(&ui64, TUINT64_T);


    return 0;
}
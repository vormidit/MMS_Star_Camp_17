#include <stdio.h>
#include <limits.h>

int main(){

    int a;

    a = a + 5;//Undefine behavior

    int n = 5;
    int arr[] = {1,2,3,4,5};
    
    arr[5] = 6;//Undefine behavior

    int *p = NULL;

    *p;//Undefine behavior

    int a = INT_MAX;

    a++;
    
}
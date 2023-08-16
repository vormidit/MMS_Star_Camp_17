#include<stdio.h>

struct Point{
    double x;
    double y;
};

int main(){

    struct Point a;

    a.x = 12.5;
    a.y = 16.2;
    
    struct Point b = {3.14, 5.67};


    return 0;
}
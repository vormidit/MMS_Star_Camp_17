#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define N 10

typedef struct Point{

    double x;
    double y;
}Point;

const Point zero = {0., 0.};

double dist(Point a, Point b){
    double dX = a.x - b.x;
    double dY = a.y - b.y;

    return sqrt(dX*dX + dY*dY);
}

int cmp_x_inc(const void *p1, const void *p2){

   
   return (((Point*)p1)->x - ((Point*)p2)->x)*1000;

}

int cmp_y_dec(const void *p1, const void *p2){

   
   return (((Point*)p2)->y - ((Point*)p1)->y)*1000;

}


int compare_dist(const void *p1, const void*p2){
    
    double dist1 = dist(*(Point*)p1, zero);
    double dist2 = dist(*(Point*)p2, zero);
    
    return (dist1 - dist2)*1000;

}



void print_arr(Point arr[], size_t n){
    for(size_t i = 0; i < n; i++){
        printf("%lf  %lf  %lf\t", arr[i].x, arr[i].y, dist(arr[i], zero));
        printf("\n");
    }

}


int main(){
    Point *pm = malloc(sizeof(Point)*N);

    for(size_t i = 0; i < N; i++){
        pm[i].x = (-1000 + rand()%2001)/1000.;
        pm[i].y = (-1000 + rand()%2001)/1000.;
    }

    qsort(pm, N, sizeof(Point), cmp_x_inc);
    print_arr(pm, N);
    printf("\n");
    qsort(pm, N, sizeof(Point), cmp_y_dec);
    print_arr(pm, N);
    printf("\n");
    qsort(pm, N, sizeof(Point), compare_dist);
    print_arr(pm, N);
    
    




 return 0;
}
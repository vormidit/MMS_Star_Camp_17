#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct Point{
    double x;
    double y;
};

double point_dist(struct Point p1, struct Point p2){

    double dX = p1.x - p2.x,
           dY = p1.y - p2.y;
    
    return sqrt(dX*dX + dY*dY);

}


int main(int argc, char *argv[]){

    unsigned  N;

    sscanf(argv[1], "%d", &N);

    struct Point points[N];

    for(size_t i = 0; i < N; i++){
        points[i].x = (double)(rand()%1000)/1000.;//Generate random num [0,1]
        points[i].y = (double)(rand()%1000)/1000.;

    }

    for(size_t i = 0; i < N-1; i++){
        size_t j = i+1;
        while(j < N){
        printf("%lf\n", point_dist(points[i], points[j]));
        j++;
        }
        
    }


    



    return 0;
}
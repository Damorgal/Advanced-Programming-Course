#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 1000000

void funcion1()  {
    short a[n];
    int sum=0, k;
    unsigned t0, t1;
 
    t0 = clock();
    for(int i=0; i<n; i++)  {
        k = random() % n;
        sum += a[k];
    }
    t1 = clock();
    double time = (double)(t1-t0)/CLOCKS_PER_SEC;
    printf("El tiempo de ejecucion con a[k] es: %lf\n", time);
}

void funcion2()  {
    short a[n];
    int sum=0, k;
    unsigned int t0, t1;
 
    t0 = clock();
    for(int i=0; i<n; i++)  {
        k = random() % n;
        sum += a[i];
    }
    t1 = clock();
    double time = (double)(t1-t0)/CLOCKS_PER_SEC;
    printf("El tiempo de ejecucion con a[i] es: %lf\n", time);
}


int main(int narg, char *varg[]) {
    funcion1();
    funcion2();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 1000000
#define m 1000000
double C[n][m], A[n][m], B[n][m];
#define q 1000000
#define p 1000000

int funcion1()  {
    for(int i=0; i<n ; i++)  {
        for(int j=0; j<m; j++)   {
            for(int l=0; l<q; l++) 
                C[i][j+l] = 0.0;
            for(int k=0; k<p; k++) {
                for(int l=0; l<q ; l++) 
                    C[i][j+l] += A[i][k]*B[k][j+l];
            }
        }
    }
}



int main(int narg, char *varg[]) {
    int en=1;
    printf("%d\n",en>>=1);
    return 0;
}

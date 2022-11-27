#include<stdio.h>
#include<stdlib.h>
#include "./implementacionMonticulo3.c"
#include "./median.c"

// Función principal, recibe de STDIN un stream de datos e imprime a STDOUT
// la mediana. 
//
int main(int num_args, char ** args){ 
    int aux; char buf[64];
    median = 0.0;
    // Creación del montículo min
    THeap *th_min = THeap_new();
    // Creación del montículo max
    THeap *th_max = THeap_new();
    printf("A continuación escribe los números que quieres agregar:\n");
    while(fgets(buf, 64, stdin)) {
        if (*buf == '\n') 
            break;
        aux = atoi(buf);
        theap_median(th_min, th_max, aux);
        printf("%.2lf\n", median);
    }
    //Liberamos memoria de los Heap
    free_THeap(&th_max);
    free_THeap(&th_min);
    return 0;
} 

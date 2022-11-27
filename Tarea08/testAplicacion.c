#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "./implementacionMonticulo3.c"
#include "./median.c"

int passed = 0, TOTALTESTS = 0;

double medianHS(THeap *t)  {
    double med;
    //Si tiene un número par de elementos, será el promedio
    if(t->size%2 == 0)  {
        if(t->size == 0) return 0.0;
        int midSize = t->size>>1;
        for(int i=0; i<midSize-1; i++)
            removeMax(t);
        med = (double)removeMax(t);
        med += (double)removeMax(t);
        med /= 2.0;
    }
    //Si es un número impar, será el elemento medio
    else    {
        int midSize = (t->size+1)>>1;
        for(int i=0; i<midSize-1; i++)
            removeMax(t);
        med = (double)removeMax(t);
    }
    return med;
}

int test_median(void)   { 
    /* Se comprobarán distintos casos de test random, para ello se hará 
     * un heapsort para comprobar que es efectivamente la mediana.
     */
    
    double medHS;
    int aux, n;
    
    /*************************** Caso 0 ***************************/
    TOTALTESTS++;
    n = 0;
    median = 0.0;
    // Creación del montículo min
    THeap *th_min = THeap_new();
    // Creación del montículo max
    THeap *th_max = THeap_new();
    // Creación del montículo auxiliar para ordenamiento
    THeap *th_aux = THeap_new();

    //Inserción random
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        aux = rand()%2000 - 1000;
        theap_median(th_min, th_max, aux);
        insert(th_aux, aux);
    }
    //Comprobamos que las medianas son iguales
    medHS = medianHS(th_aux);
    if(median == medHS)
        passed++; 
    else 
        printf("Error en caso n = %d\nMediana = %lf, Mediana HS = %lf\n", n, median, medHS);
    //Liberamos memoria de los Heap
    free_THeap(&th_aux);
    free_THeap(&th_max);
    free_THeap(&th_min);
    
    /*************************** Caso 1 ***************************/
    TOTALTESTS++;
    n = 1;
    median = 0.0;
    // Creación del montículo min
    th_min = THeap_new();
    // Creación del montículo max
    th_max = THeap_new();
    // Creación del montículo auxiliar para ordenamiento
    th_aux = THeap_new();

    //Inserción random
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        aux = rand()%2000 - 1000;
        theap_median(th_min, th_max, aux);
        insert(th_aux, aux);
    }
    //Comprobamos que las medianas son iguales
    medHS = medianHS(th_aux);
    if(median == medHS)
        passed++; 
    else 
        printf("Error en caso n = %d\nMediana = %lf, Mediana HS = %lf\n", n, median, medHS);
    //Liberamos memoria de los Heap
    free_THeap(&th_aux);
    free_THeap(&th_max);
    free_THeap(&th_min);
    
    /*************************** Caso 5 ***************************/
    TOTALTESTS++;
    n = 5;
    median = 0.0;
    // Creación del montículo min
    th_min = THeap_new();
    // Creación del montículo max
    th_max = THeap_new();
    // Creación del montículo auxiliar para ordenamiento
    th_aux = THeap_new();

    //Inserción random
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        aux = rand()%2000 - 1000;
        theap_median(th_min, th_max, aux);
        insert(th_aux, aux);
    }
    //Comprobamos que las medianas son iguales
    medHS = medianHS(th_aux);
    if(median == medHS)
        passed++; 
    else 
        printf("Error en caso n = %d\nMediana = %lf, Mediana HS = %lf\n", n, median, medHS);
    //Liberamos memoria de los Heap
    free_THeap(&th_aux);
    free_THeap(&th_max);
    free_THeap(&th_min);
    
    /*************************** Caso 10 ***************************/
    TOTALTESTS++;
    n = 10;
    median = 0.0;
    // Creación del montículo min
    th_min = THeap_new();
    // Creación del montículo max
    th_max = THeap_new();
    // Creación del montículo auxiliar para ordenamiento
    th_aux = THeap_new();

    //Inserción random
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        aux = rand()%2000 - 1000;
        theap_median(th_min, th_max, aux);
        insert(th_aux, aux);
    }
    //Comprobamos que las medianas son iguales
    medHS = medianHS(th_aux);
    if(median == medHS)
        passed++; 
    else 
        printf("Error en caso n = %d\nMediana = %lf, Mediana HS = %lf\n", n, median, medHS);
    //Liberamos memoria de los Heap
    free_THeap(&th_aux);
    free_THeap(&th_max);
    free_THeap(&th_min);
    
    /*************************** Caso 20 ***************************/
    TOTALTESTS++;
    n = 20;
    median = 0.0;
    // Creación del montículo min
    th_min = THeap_new();
    // Creación del montículo max
    th_max = THeap_new();
    // Creación del montículo auxiliar para ordenamiento
    th_aux = THeap_new();

    //Inserción random
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        aux = rand()%2000 - 1000;
        theap_median(th_min, th_max, aux);
        insert(th_aux, aux);
    }
    //Comprobamos que las medianas son iguales
    medHS = medianHS(th_aux);
    if(median == medHS)
        passed++; 
    else 
        printf("Error en caso n = %d\nMediana = %lf, Mediana HS = %lf\n", n, median, medHS);
    //Liberamos memoria de los Heap
    free_THeap(&th_aux);
    free_THeap(&th_max);
    free_THeap(&th_min);
    
    /*************************** Caso 50 ***************************/
    TOTALTESTS++;
    n = 50;
    median = 0.0;
    // Creación del montículo min
    th_min = THeap_new();
    // Creación del montículo max
    th_max = THeap_new();
    // Creación del montículo auxiliar para ordenamiento
    th_aux = THeap_new();

    //Inserción random
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        aux = rand()%2000 - 1000;
        theap_median(th_min, th_max, aux);
        insert(th_aux, aux);
    }
    //Comprobamos que las medianas son iguales
    medHS = medianHS(th_aux);
    if(median == medHS)
        passed++; 
    else 
        printf("Error en caso n = %d\nMediana = %lf, Mediana HS = %lf\n", n, median, medHS);
    //Liberamos memoria de los Heap
    free_THeap(&th_aux);
    free_THeap(&th_max);
    free_THeap(&th_min);
    
    /*************************** Caso 100 ***************************/
    TOTALTESTS++;
    n = 100;
    median = 0.0;
    // Creación del montículo min
    th_min = THeap_new();
    // Creación del montículo max
    th_max = THeap_new();
    // Creación del montículo auxiliar para ordenamiento
    th_aux = THeap_new();

    //Inserción random
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        aux = rand()%2000 - 1000;
        theap_median(th_min, th_max, aux);
        insert(th_aux, aux);
    }
    //Comprobamos que las medianas son iguales
    medHS = medianHS(th_aux);
    if(median == medHS)
        passed++; 
    else 
        printf("Error en caso n = %d\nMediana = %lf, Mediana HS = %lf\n", n, median, medHS);
    //Liberamos memoria de los Heap
    free_THeap(&th_aux);
    free_THeap(&th_max);
    free_THeap(&th_min);
    
    /*************************** Caso 500 ***************************/
    TOTALTESTS++;
    n = 500;
    median = 0.0;
    // Creación del montículo min
    th_min = THeap_new();
    // Creación del montículo max
    th_max = THeap_new();
    // Creación del montículo auxiliar para ordenamiento
    th_aux = THeap_new();

    //Inserción random
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        aux = rand()%2000 - 1000;
        theap_median(th_min, th_max, aux);
        insert(th_aux, aux);
    }
    //Comprobamos que las medianas son iguales
    medHS = medianHS(th_aux);
    if(median == medHS)
        passed++; 
    else 
        printf("Error en caso n = %d\nMediana = %lf, Mediana HS = %lf\n", n, median, medHS);
    //Liberamos memoria de los Heap
    free_THeap(&th_aux);
    free_THeap(&th_max);
    free_THeap(&th_min);
    
    /*************************** Caso 1000 ***************************/
    TOTALTESTS++;
    n = 1000;
    median = 0.0;
    // Creación del montículo min
    th_min = THeap_new();
    // Creación del montículo max
    th_max = THeap_new();
    // Creación del montículo auxiliar para ordenamiento
    th_aux = THeap_new();

    //Inserción random
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        aux = rand()%2000 - 1000;
        theap_median(th_min, th_max, aux);
        insert(th_aux, aux);
    }
    //Comprobamos que las medianas son iguales
    medHS = medianHS(th_aux);
    if(median == medHS)
        passed++; 
    else 
        printf("Error en caso n = %d\nMediana = %lf, Mediana HS = %lf\n", n, median, medHS);
    //Liberamos memoria de los Heap
    free_THeap(&th_aux);
    free_THeap(&th_max);
    free_THeap(&th_min);
    
    /*************************** Caso 10000 ***************************/
    TOTALTESTS++;
    n = 10000;
    median = 0.0;
    // Creación del montículo min
    th_min = THeap_new();
    // Creación del montículo max
    th_max = THeap_new();
    // Creación del montículo auxiliar para ordenamiento
    th_aux = THeap_new();

    //Inserción random
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        aux = rand()%2000 - 1000;
        theap_median(th_min, th_max, aux);
        insert(th_aux, aux);
    }
    //Comprobamos que las medianas son iguales
    medHS = medianHS(th_aux);
    if(median == medHS)
        passed++; 
    else 
        printf("Error en caso n = %d\nMediana = %lf, Mediana HS = %lf\n", n, median, medHS);
    //Liberamos memoria de los Heap
    free_THeap(&th_aux);
    free_THeap(&th_max);
    free_THeap(&th_min);
    
    return 1;
} 

int main(int num_args, char **args)    {
    int all_tests_ok = 1;
    all_tests_ok &= test_median();
    assert(all_tests_ok); 
    
    printf("\nTotal de pruebas realizadas: %d\n", TOTALTESTS);
    printf("Total de pruebas exitosas: %d\n", passed) ;
    printf("Total de pruebas fallidas: %d\n", TOTALTESTS - passed);
    return 0;
} 

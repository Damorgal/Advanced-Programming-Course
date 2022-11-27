#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

unsigned int tam;
double numMax;
pthread_mutex_t mutex;

void *taskMax(void *data) {
    //Convertimos el apuntador vacío a
    //que sea apuntador de double
    double *v = (double*)data;
    //Inicializamos máximo
    double max = v[0];
    //Buscamos el máximo en los próximos tam=n/3 números
    for(int i=1; i<tam; i++) {
        if(max < v[i])
            max = v[i];
    }
    //Actualizamos la variable global del máximo
    pthread_mutex_lock(&mutex);
    if(max > numMax)
        numMax = max;
    pthread_mutex_unlock(&mutex);
    return NULL;
}


void getMax(double *vec, int n) {
    /* Función que obtiene el máximo usando 3 hilos.
     * Como debiamos pasar el vector (pues no es global),
     * la estategia es determinar un tamño global de búsqueda
     * que aproximadamente es de n/3 y pasar a partir de donde
     * buscar a la función que se paraleliza.
     */
    //Tamaño para los 3 casos
    tam = n%3==0 ? n/3 : n/3+1; 
    pthread_t threads[3];
    //El máximo global inicializado
    numMax = vec[0];
    //Paralelizamos com 3 hilos
    pthread_mutex_init(&mutex, NULL);
    for(int t=0; t<3; t++)    {
        //Modificamos donde buscar en el arreglo 
        //dependiendo de cual tercio corresponda
        double *pos = vec;
        if(t == 1)    {
            if(n%3 != 0)
                pos += tam-1;
            else
                pos += tam;
        }
        else if(t == 2) {
            pos += 2*tam;
            if(n%3 == 1)
                pos -= 2;
            else if(n%3 == 2)
                pos -= 1;
        }
        //Paralelizamos la función pasandole el apuntador 
        //de dónde empiece a buscar
        if(pthread_create(&threads[t], NULL, taskMax, (void *) pos)) {
            fprintf(stderr, "Cannot create thread\n");
            exit(1);
        }
    }
    //Juntamos los hilos
    for(int t=0; t<3;t++) {
        if(pthread_join(threads[t], NULL))    {
            fprintf(stderr ,"Cannot join on %d\n", t);
            exit(1);
        }
    }
    return;
}


int main(int narg, char *varg[]) {
    //Argumentos del programa solo debera ser el tamagno
    if(narg != 2)   {
        printf("Debe colocar el tamagno del vector\n");
        exit(1);
    }
    //Llenamos el vector
    unsigned int n = atoi(varg[1]);
    double *v = (double*)malloc(n*sizeof(double));
    srand(time(NULL));
    for(int i=0; i<n; i++)
        v[i] = (rand()%200 - 100)/50.0;
    //Imprimimos el vector, se puede omitir
    printf("El vector es:\n");
    for(int i=0; i<n; i++)
        printf("%.2lf ",v[i]);
    printf("\n");
    
    //Función de llamada al máximo
    getMax(v,n);
    printf("El maximo del vector es: %.2lf\n", numMax);
    
    //Liberamos memoria
    free(v);
    return 0;
}

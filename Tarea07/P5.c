#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int binarySearchLocMin(int *arr, int a, int b)  {
    int mid = (a+b)>>1;
    //Buscamos a la izquierda
    if(arr[mid] < arr[mid+1])   {
        //Lo hemos encontrado
        if(arr[mid-1] > arr[mid])
            return mid;
        else
            return binarySearchLocMin(arr, a, mid);
    }
    else 
        return binarySearchLocMin(arr, mid, b);
}

int locateLocalMin(int *arr, int n) {
    /* Función en la que se supone que son valores 
     * de una función en la que arr[0] = arr[n-1] = infty
    */
    if(arr[0] != arr[n-1] && arr[0] != INT_MAX) {
        printf("Error, debes cumplir la norma de los extremos en infinito = %d\
        \n",INT_MAX);
        return -1;
    }
    return binarySearchLocMin(arr,0,n-1);
}

int main(int narg, char *varg[]) {
    if(narg < 3)    {
        printf("Error, debes mandar un vector con al menos 3 elementos\n");
        exit(1);
    }
    //Leemos el arreglo
    int *arr = (int*)malloc((narg-1)*sizeof(int));
    for(int i=1; i<narg; i++)
        arr[i-1] = atoi(varg[i]);
    //Localizamos el mínimo
    int aux = locateLocalMin(arr, narg-1);
    printf("Un mínimo local se encuentra en arr[%d] = %d\n",\
    aux, arr[aux]);
    
    free(arr);
    return 0;
}

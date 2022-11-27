#include "./implementacionMonticulo3.c"

/* Implementación del heap-montículo ternario en reversa
* Depende de la implementación original del montículo ternario:
* Las siguientes funciones toman como argumento un montículo
* (predefinido en heap.c) donde las llaves de los nodos padre serán
* menores a las llaves de los nodos hijos.
* Básicamente, se trata de una cola de prioridad, tomando como llave
* de prioridad el dato más pequeño.
*
* Al ser versiones modificadas de las funcioens en heap.c, la complejidad
* de cada operación es igual a la de su análoga. Únicamente se cambia la 
* orientación de ciertas comparaciones.
*/

// Prototipos =================================================================

void    reverseInsert(THeap *h, int data);
int     removeMin(THeap *h);
int     getMin(THeap *h);

void    reverseBottomUpHeapify(int *arr, int k);
void    reverseTopDownHeapify(int * arr, int k, int n);

// Definiciones ===============================================================

// Valor del mínimo / índice el mínimo

void reverseInsert(THeap *h, int data) { 
    //Si el árbol está vacío 
    if(h == NULL)
        h = THeap_new();
    //Si se excede la capacidad
    if(h->capacity == h->size)   {
        printf("Error, excedes la capacidad máxima del árbol\n");
        return;
    }
    //Ponemos el nuevo dato en la entrada dada por el tamaño
    h->vec[h->size] = data;
    //Colocamos el nuevo dato donde debe ir
    reverseBottomUpHeapify(h->vec, h->size);

    //Aumentamos el tamaño
    h->size++;
    return;
} 

int removeMin(THeap *h) { 
    //Si no hay elementos en el montículo
    if(h->size == 0)    {
        printf("Estás tratando de remover de un montículo vacío\n");
        return -1;
    }
    int min_aux = getMin(h);

    //Reemplazamos el mínimo por el último valor del arreglo
    //Notar que también reducimos el tamaño
    h->vec[0] = h->vec[--h->size];

    //Realizamos una corrección del mínimo
    reverseTopDownHeapify(h->vec, 0, h->size);
    return min_aux;
} 

int getMin(THeap *h){ 
    if(h->size == 0)    {
        printf("Error, no hay elementos en el montículo\n");
        return -1;
    }
    return h->vec[0];
} 

void reverseBottomUpHeapify(int *arr, int k)   { 
    int aux, pos;
    //Condición de paro, llegar a la posición 0
    while(k)    {
        //Posicion del padre
        pos = (k-1)/3;
        //Si somos más pequeño que el padre
        //Swap
        if(arr[pos] > arr[k]) {
            aux = arr[pos];
            arr[pos] = arr[k];
            arr[k] = aux;
            k = pos;
        }

        else{
            break;
        }
            
    }
    return;
} 

void reverseTopDownHeapify(int * arr, int k, int n)    {
    //Condición de paro, máximo del arreglo
    while(3*k < n)  {
        int pos, aux;
        pos = aux = 3*k+1;
        //Si hay hasta 2 hojas comparamos
        if(aux+1 < n)   {
            //Nos quedamos con el menor
            if(arr[aux+1] < arr[pos])
                pos = aux+1;
            //Si hay hasta 3 hojas
            if(aux+2 < n)
                //Nos quedamos con el menor
                if(arr[aux+2] < arr[pos])
                    pos = aux+2;
        }
        //Condición de paro, la menor hoja es mayor que el nodo
        if(arr[pos] >= arr[k])
            break;
        //Swap
        aux = arr[pos];
        arr[pos] = arr[k];
        arr[k] = aux;
        
        //Actualizamos posicion
        k = pos;
    }
    return;
} 

void printHeap(THeap *h){

    for(int i = 0; i < h->size; i++){
        printf("%d \t", h->vec[i]);
    }
}

#ifndef HEAP_T08
#define HEAP_T08

#define max_size 10000000

/* Implementación del heap-montículo ternario.
 * La estuctura contiene los siguientes datos:
 *
 * vec      : [int]    -- colección de enteros
 * size     : int      -- tamaño actual del vector
 * capacity : int      -- capacidad total de memoria para el vector
 *
 * Inicializar la estructura THeap como THeap *h = NULL; y después 
 * agregar un elemento cualquiera.
 *
 * Complejidad O(log_3(n)): (n = size = tamaño actual del arreglo)
 * 
 * Se accede trivialmente al máximo. Para el insert, se coloca el
 * nuevo elemento en O(1) y se realiza el heapify que en el peor 
 * caso es hasta el principio, el cual está a distancia log_3(n).
 * Similarmente para el remove, se reemplaza el máximo por el 
 * último en el arreglo en O(1) y se realiza otro heapify hacia
 * abajo que de igual manera, el peor caso se alcanza en log_3(n).
 * 
 * Comparación con montículo binario:
 * A priori, se supera la complejidad respecto al binario debido a 
 * que se necesitan menos pasos para realizar el heapify. Es una 
 * ventaja contar con menos niveles de profundidad por lo anterior.
 * Sin embargo, se ocupa más memoria para tener niveles profundos 
 * en el árbol.
*/

// Prototipos =================================================================

typedef struct _THeap{
  int size;
  int capacity;
  int *vec;
}THeap;

THeap * THeap_new(void);
void    free_THeap(THeap ** hptr);

void    insert(THeap *h, int data);
int     removeMax(THeap *h);
int     getMax(THeap *h);

void    bottomUpHeapify(int *arr, int k);
void    topDownHeapify(int * arr, int k, int n);

// Definiciones ===============================================================

THeap * THeap_new(void) {
    //Pedimos memoria para el árbol
    THeap *h = (THeap*)malloc(sizeof(THeap));
    if(!h) {printf("Error al solicitar memoria (THeap)\n"); exit(1);}
    //Cambiamos sus valores
    h->size = 0;
    h->capacity = max_size;
    h->vec = (int*)malloc(max_size*sizeof(int));
    if(!h) {printf("Error al solicitar memoria (datos)\n"); exit(1);}
    return h;
}

void free_THeap(THeap ** hptr)  {
    //Liberamos el vector
    free((*hptr)->vec);
    //Liberamos la estructura
    free(*hptr);
}

void insert(THeap *h, int data) { 
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
    bottomUpHeapify(h->vec, h->size);
    //Aumentamos el tamaño
    h->size++;
    return;
} 

int removeMax(THeap *h) { 
    //Si no hay elementos en el montículo
    if(h->size == 0)    {
        printf("Estás tratando de remover de un montículo vacío\n");
        return -1;
    }
    int max_aux = getMax(h);
    //Reemplazamos el máximo por el último valor del arreglo
    //Notar que también reducimos el tamaño
    h->vec[0] = h->vec[--h->size];
    //Realizamos una corrección del máximo
    topDownHeapify(h->vec, 0, h->size);
    return max_aux;
} 

int getMax(THeap *h){ 
    if(h->size == 0)    {
        printf("Error, no hay elementos en el montículo\n");
        return -1;
    }
    return h->vec[0];
} 

void bottomUpHeapify(int *arr, int k)   { 
    int aux, pos;
    //Condición de paro, llegar a la posición 0
    while(k)    {
        //Posicion del padre
        pos = (k-1)/3;
        //Si somos más grande que el padre
        //Swap
        if(arr[pos] < arr[k]) {
            aux = arr[pos];
            arr[pos] = arr[k];
            arr[k] = aux;
            k = pos;
        }
        //Sino acabamos
        else
            break;
    }
    return;
} 

void topDownHeapify(int * arr, int k, int n)    {
    //Condición de paro, máximo del arreglo
    while(3*k < n)  {
        int pos, aux;
        pos = aux = 3*k+1;
        //Si hay hasta 2 hojas comparamos
        if(aux+1 < n)   {
            //Nos quedamos con el mayor
            if(arr[aux+1] > arr[pos])
                pos = aux+1;
            //Si hay hasta 3 hojas
            if(aux+2 < n)
                //Nos quedamos con el mayor
                if(arr[aux+2] > arr[pos])
                    pos = aux+2;
        }
        //Condición de paro, la mayor hoja es menor que el nodo
        if(arr[pos] <= arr[k])
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

#endif

#include "./implementacionMonticulo3.c"
#include "./MinHeap3.c"

#ifndef MEDIAN_T8
#define MEDIAN_T8

/* Aplicación para mónticulos: Cálculo de la mediana en streaming
 * La siguiente aplicación tiene las siguientes dependencias:
 * 
 * "heap.c" -> se implementa la estructura de montículo ternario
 * "reverseheap.c" -> modificación de las funciones en heap.c
 *
 * El cálculo de el valor mediano toma como entrada 2 montículos:
 * thmin y thmax, la variable de la mediana "median" está definida
 * como global.
 * 
 * El montículo thmax guarda la mitad inferior de los datos obtenidos,
 * Por otro lado, el montículo thmin almacena la mitad superior de los 
 * datos
 * 
 * Por la forma en la que se implementó, se puede decir que,  
 * la raíz de thmax guarda el valor más grande de los pequeños 
 * y la raíz de thmin guarda el valor más pequeño de los grandes.
 * 
 * Si alguno de los dos montículos es más grande que el otro, 
 * la mediana se encontrará en la raíz del de mayor tamaño.
 * Caso contrario, la mediana será el valor promedio entre las dos
 * raíces
 * 
 * Análisis de complejidad:
 * 
 * En el peor de los casos, se debe remover la raíz de uno de los 
 * montículos para colocarlo sobre el otro, y se debe agregar el 
 * dato de entrada en el montículo con menos elementos.
 * 
 * Suponiendo que el tamaño de thmax es mayor al de thmin,
 * y el dato es menor a la mediana actual, se debe colocar el valor
 * máximo de thmax en thmin, para ello, se utilizan las funciones de
 * remover e insertar.
 * 
 * La acción de remover el valor máximo de thmax, en el peor caso,
 * deberá realizar la función heapify en T(n) = log_3(n). 
 * (recordar que el último dato del arreglo se intercambia por el primero
 * y a partir de ahi, se trata de encontrar el lugar para este elemento).
 * 
 * El nuevo valor insertado en thmin tendrá que estar en la raíz,
 * la cual se encuentra a una distacia  de log_3(n). La función heapify 
 * tiene un tiempo de ejecución de T(n) =  log_3(n).
 * 
 * Se deberá incluír el nuevo dato de entrada en el montículo de menor
 * tamaño (en este caso thmax), por lo que, si este corresponde a la raíz,
 * se encontrará a una distancia de log_3(n), de igual manera T(n) = log_3(n).
 * 
 * Las operaciones para la asignación de variables auxiliares y la modificación
 * de el valor mediano, se realizan en tiempo constante (T(n) = c).
 * 
 * En total, el tiempo de ejecución de este algoritmo es:
 * 
 * T(n) = 3log_{3}(n) + c
 * 
 * Por lo que:
 * 
 * T(n) = O(log(n)).
*/


// Aplicación: Cálculo de mediana en streaming.

// Prototipo ==================================================================

int theap_median(THeap * thmin, THeap * thmax, int data);
 
// Definiciones ===============================================================

// Variable global donde se guardará el valor de la mediana
double median = 0;

int theap_median(THeap * thmin, THeap * thmax, int data){ 
        
        int aux = 0;
        
        // Tamaño del montículo máx superior al del montículo mín
        if(thmax -> size > thmin -> size){
            // Si la entrada es menor al mediano: 
            // Se desplaza el valor máximo de thmax a thmin
            // Se almacena el nuevo dato en thmax
            if(data < median){
                aux = removeMax(thmax);
                reverseInsert(thmin, aux);
                insert(thmax, data);
            }

            // Si la entrada es mayor o igual al mediano
            else{
                reverseInsert(thmin, data);
            }

            median = (getMax(thmax) + getMin(thmin))/2.0;
        }

        // Tamaño del montículo máx inferior al del montículo mín
        else if(thmax -> size < thmin -> size){
            
            // Si la entrada es mayor al mediano: 
            // Se desplaza el valor mínimo de thmin a thmax
            // Se almacena el nuevo dato en thmin
            if(data > median){
                aux = removeMin(thmin);

                insert(thmax, aux);
                reverseInsert(thmin, data);
            }

            // Si la entrada es menor o igual al mediano
            else{
                insert(thmax, data);
            }

            median = (getMax(thmax) + getMin(thmin))/2.0;
        }
        
        // Ambos montículos tienen el mismo tamaño
        else{

            // Si la entrada es menor al mediano
            // Colocar el dato en el la primer posición de thmax
            if(data < median){
                insert(thmax, data);
                median = getMax(thmax);
            }

            // Si la entrada es mayor o igual al mediano
            // Colocar el dato en el la última posición de thmin
            else{
                reverseInsert(thmin, data);
                median = getMin(thmin);
            }

        }
  return -1;
} 

#endif

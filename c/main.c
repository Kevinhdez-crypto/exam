#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Semilla para generar números aleatorios
    srand(time(0));

    // Obtiene el tamaño del arreglo
    int size;
    tamanoArray(&size);

    // Crea el struct arreglo_t y el arreglo
    arreglo_t* array_info = crearArray(size);
    if (array_info == NULL) {
        return 1;
    }

    // Llena el arreglo con números aleatorios entre 0 y 100
    llenarAray(array_info);

    // Imprime el arreglo desordenado
    printf("El arreglo desordenado es:\n");
    printArray(array_info->array, array_info->size);

    // Ordena el arreglo (asumiendo que sortArray es una función existente)
    sortArray(array_info->array, array_info->size);

    // Imprime el arreglo ordenado
    printf("El arreglo ordenado es:\n");
    printArray(array_info->array, array_info->size);

    // Libera la memoria reservada
    liberarMemoria(array_info);

    return 0;
}

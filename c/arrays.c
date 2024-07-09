#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Implementación de funciones
void llenarAray(arreglo_t* arr_struct) {
    if (!arr_struct->arr_full) {
        for (int i = 0; i < arr_struct->size; i++) {
            arr_struct->array[i] = rand() % 101;
        }
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void sortArray(int* arr, int size) {
    qsort(arr, size, sizeof(int), compare);
}
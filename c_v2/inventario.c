//Funciones a implementar
//Kevin Hernandez Umana C33773

#include "inventario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementacion de funciones

// Crear el inventario (deben usar malloc para la memoria dinamica)
inventario_t* crearInventario() {
    inventario_t* inventario = (inventario_t*)malloc(sizeof(inventario_t)); //Creamos la memoria dinamica

    //si falla devolvemos NULL
    if (inventario == NULL){
        return NULL;
    }

    //Ahora vamos a asignar memoria dinamica con capacidad de 10 como se indica
    inventario->productos = (producto_t*)malloc(10 * sizeof(producto_t));

    if (inventario->productos == NULL){
        free(inventario); //si malloc falla liberamos esa memoria
        return NULL;
    }

    //Por ultimo vamos a dar inicio al inventario como se pide
    inventario->tamano = 10;
    inventario->ocupado = 0;
    return inventario;
}

// Agregar un producto al inventario (usar realloc si se llena la capacidad)
void agregarProducto(inventario_t* inventario, const char* nombre, int cantidad, float precio) {
    if (inventario->ocupado == inventario->tamano){ //si no hay espacio, entonces hacmos mas grande la memoria
        inventario->tamano *= 2;
        //asignamos esa memoria con realloc
        inventario->productos = (producto_t*)realloc(inventario->productos, inventario->tamano * sizeof(producto_t));

        if (inventario->productos == NULL){ //En caso de que haya algun problema
            printf("Disculpe, hubo una falla con la memoria.\n");
            exit(1);
        }
    }
    //ahora se va a crear un nuevo produnto de la forma producto_t
    producto_t nuevoProducto; //va a recibir el mismo nombre y el precio, cantidad y demas
    strcpy(nuevoProducto.nombre, nombre);
    nuevoProducto.cantidad = cantidad;
    nuevoProducto.precio = precio;

    inventario->productos[inventario->ocupado] = nuevoProducto;
    inventario->ocupado++; //subimos el contador para indicar que se agrega uno mas
}

//funcion para eliminar el producto
void eliminarProducto(inventario_t* inventario, const char* nombre){
    int i;
    int encontrado = -1;


    //Este for nos indica si hay un elemento encontrado, si es el caso, encontrado se iguala a i
    for(i = 0; i < inventario->ocupado; i++){ 
        if (strcmp(inventario->productos[i].nombre, nombre) == 0){
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1){ //mensaje en caso de que no se encuentre el producto
        printf("Producto no encontrado.\n");
        return;
    }

    for (i = encontrado; i < inventario->ocupado -1; i++){
        inventario->productos[i] = inventario->productos[i + 1]; //eliminamos y movemos para que no queden huecos en el array
    }

    inventario->ocupado--; //Eliminamos el conteo porque se elimina el producto
}

//funcion para imprimir el inventario
void imprimirInventario(inventario_t* inventario){
    //Este if es en caso de que el inventario ya este vacio
    if (inventario->ocupado == 0){
        printf("El inventario esta vacio.\n");
        return;
    }

    //ciclo for para recorrer el inventario uno por uno
    for (int i = 0; i < inventario->ocupado; i++){
        printf("%d. %s - Cantidad: %d - Precio: %.2f\n", i + 1, //mensaje para imprimir el inventario
        inventario->productos[i].nombre,
        inventario->productos[i].cantidad,
        inventario->productos[i].precio);
    }

}

//funcion para vaciar el inventario
void vaciarInventario(inventario_t* inventario){
    //Este if es para  el caso de que productos no sea Null, entonces liberamos esa memoria con free
    if (inventario->productos != NULL){
        free(inventario->productos);
    }

    free(inventario); //liberamos la estructura 'inventario' con free tal y como se solicita.

}


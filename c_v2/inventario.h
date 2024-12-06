//Archivo para declarar las funciones
#ifndef INVENTARIO_H
#define INVENTARIO_H

typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} producto_t;

typedef struct {
    producto_t* productos;
    int tamano;   // Capacidad total del inventario
    int ocupado;  // Numero actual de productos
} inventario_t;

// Declaracion de funciones
inventario_t* crearInventario();

// Funcion para agregar un producto 
void agregarProducto(inventario_t* inventario, const char* nombre, int cantidad, float precio);

// Funcion para eliminar un producto del inventario
void eliminarProducto(inventario_t* inventario, const char* nombre);

// Funcion para imprimir todos los productos del inventario
void imprimirInventario(inventario_t* inventario);

// Funcion para liberar memoria del inventario
void vaciarInventario(inventario_t* inventario);


#endif // INVENTARIO_H

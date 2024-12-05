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
    int ocupado;  // Número actual de productos
} inventario_t;

// Declaración de funciones
inventario_t* crearInventario();
// TODO: Declarar el resto de funciones

#endif // INVENTARIO_H

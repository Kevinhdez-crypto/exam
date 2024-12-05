#include "inventario.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Crear el inventario
    inventario_t* inventario = crearInventario();
    if (inventario == NULL) {
        printf("Error al crear el inventario.\n");
        return 1;
    }

    // Agregar productos al inventario
    agregarProducto(inventario, "Manzanas", 10, 200.0);
    agregarProducto(inventario, "Peras", 5, 250.0);
    agregarProducto(inventario, "Uvas", 2, 300.0);

    // Imprimir el inventario
    printf("Inventario actual:\n");
    imprimirInventario(inventario);

    // Eliminar un producto
    printf("Eliminando 'Peras' del inventario...\n");
    eliminarProducto(inventario, "Peras");

    // Imprimir el inventario actualizado
    printf("Inventario actualizado:\n");
    imprimirInventario(inventario);

    // Liberar memoria
    vaciarInventario(inventario);

    return 0;
}

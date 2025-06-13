#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    struct Libro libros[10];
    int cont = 0, opc;
    char titulo[100];
    int id;
    struct Libro *libro;

    do {
        opc = menu();
        switch (opc) {
            case 1:
                registrarLibro(libros, &cont);
                break;
            case 2:
                listarLibros(libros, cont);
                break;
            case 3:
               int tipo;
                printf("Buscar por ID\n");
                scanf("%d", &tipo);
                    printf("ID: ");
                    scanf("%d", &id);
                    libro = buscarLibro(libros, cont, id, NULL);
                imprimirLibro(libro);
                break;
            case 4:
                actualizarEstado(libros, cont);
                break;
            case 5:
                eliminarLibro(libros, &cont);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Intente denuevo.\n");
        }
    } while (opc != 6);

    return 0;
}

#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int menu() {
    int opc;
    printf("\n--- Menu Biblioteca ---\n");
    printf("1. Registrar Libro\n");
    printf("2. Listar Libros\n");
    printf("3. Buscar Libro\n");
    printf("4. Actualizar estado del Libro\n");
    printf("5. Eliminar Libro\n");
    printf("6. Salir\n");
    printf(">> ");
    scanf("%d", &opc);
    return opc;
}

void leerCadena(char *cadena, int tam) {
    fflush(stdin);
    fgets(cadena, tam, stdin);
    int len = strlen(cadena);
    if (cadena[len - 1] == '\n') cadena[len - 1] = '\0';
}


void registrarLibro(struct Libro *libros, int *cont) {
    if (*cont >= 10) {
        printf("No se pueden registrar mas libros.\n");
        return;
    }

    printf("ID del libro: ");
    scanf("%d", &libros[*cont].id);
    fflush(stdin);
     if (libros[*cont].id<0) {
            printf("ID no puede ser negativo o con letras.\n");
           return;
        }

    for (int i = 0; i < *cont; i++) {
        if (libros[i].id == libros[*cont].id) {
            printf("ID duplicado.\n");
            return;
        }
    }

    printf("Titulo: ");
    leerCadena(libros[*cont].titulo, 100);

    printf("Autor: ");
    leerCadena(libros[*cont].autor, 50);

    printf("Anio de publicacion: ");
    scanf("%d", &libros[*cont].anio);
    fflush(stdin);
      if (libros[*cont].anio <0 || libros[*cont].anio >2025 ) {
            printf("Anio no puede ser negativo, con letras o mayor al anio actual.\n");
           return;
        }

    strcpy(libros[*cont].estado, "Disponible");

    (*cont)++;
    printf("Libro registrado con exito.\n");
}

void listarLibros(struct Libro *libros, int cont) {
    printf("\n%-5s %-30s %-20s %-6s %-12s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    for (int i = 0; i < cont; i++) {
        printf("%-5d %-30s %-20s %-6d %-12s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
    }
}

struct Libro* buscarLibro(struct Libro *libros, int cont, int id, char *titulo) {
    for (int i = 0; i < cont; i++) {
        if (id != -1 && libros[i].id == id) {
            return &libros[i];
        }
    }
    return NULL;
}

void imprimirLibro(struct Libro *libro) {
    if (libro == NULL) {
        printf("Libro no encontrado.\n");
        return;
    }
    printf("\nID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n", libro->id, libro->titulo, libro->autor, libro->anio, libro->estado);
}

void actualizarEstado(struct Libro *libros, int cont) {
    int id;
    printf("Ingrese ID del libro: ");
    scanf("%d", &id);
    struct Libro *libro = buscarLibro(libros, cont, id, NULL);
    if (libro) {
        if (strcmp(libro->estado, "Disponible") == 0)
            strcpy(libro->estado, "Prestado");
        else
            strcpy(libro->estado, "Disponible");
        printf("Estado actualizado.\n");
    } else {
        printf("Libro no encontrado.\n");
    }
}

void eliminarLibro(struct Libro *libros, int *cont) {
    int id;
    printf("Ingrese ID del libro a eliminar: ");
    scanf("%d", &id);
    for (int i = 0; i < *cont; i++) {
        if (libros[i].id == id) {
            for (int j = i; j < *cont - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*cont)--;
            printf("Libro eliminado.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}



struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[15]; 
};

int menu();
void leerCadena(char *cadena, int tam);
void registrarLibro(struct Libro *libros, int *cont);
void listarLibros(struct Libro *libros, int cont);
struct Libro* buscarLibro(struct Libro *libros, int cont, int id, char *titulo);
void imprimirLibro(struct Libro *libro);
void actualizarEstado(struct Libro *libros, int cont);
void eliminarLibro(struct Libro *libros, int *cont);
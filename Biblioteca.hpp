#include <string>

using namespace std;

class Biblioteca{
    private:
        Libro arrayLibros[20];
        //Libro arrayLibros[20];
    public:
        int cuantosEjemplaresHayDisponibles();
        Libro anadirLibro(Libro);
};

/*
Este método obtiene cuantos ejemplares hay disponibles en la biblioteca.
Devolverá el numero de ejemplares disponibles.
*/
int Biblioteca::cuantosEjemplaresHayDisponibles(){
    return sizeof(arrayLibros);
}

/*
Este método añade un libro a la biblioteca.
Devolverá el libro añadido.
*/
Libro Biblioteca::anadirLibro(Libro libro){

    

    return libro;
}

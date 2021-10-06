#include <string>
#include <list>
#include "Libro.hpp"
//#include "Usuario.cpp"

using namespace std;

class Biblioteca{
    private:
        list<Libro> arrayLibros;
        //list<Usuario> arrayUsuarios;
    public:
        //list<Usuario> getArrayUsuarios();
        list<Libro> getArrayLibros();

        int cuantosEjemplaresHayDisponibles();
        Libro anadirLibro(Libro);
};

list<Libro> Biblioteca::getArrayLibros(){
    return arrayLibros;
}

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
    arrayLibros.push_back(libro);
    return libro;
}

#include <list>
#include <ctime> 
#include "Libro.hpp"

class Usuario{
    private:
        int id;
        string nombre;
        string dni;
        list<Libro> historial;
        Libro libroActual;
        //Date FechaAdquisicion
        //Date FechaDevolucion

    public:
        int getId();
        string getNombre();
        string getDni();
        list<Libro> getHistorial();
        Libro getLibroActual();

        void setId(int);
        void setNombre(string);
        void setDni(string);
        void setHistorial(list<Libro>);
        void setLibroActual(Libro);

        void sacarLibro();
        void devolverLibro();
        void visualizarUsuario();
};

int getId(){
    return id;
}
string getNombre(){
    return nombre;
}
string getDni(){
    return dni;
}
list<Libro> getHistorial(){
    return historial;
}
Libro getLibroActual(){
    return libroActual;
}

void setId(int ID){
    id = ID;
}
void setNombre(string NOMBRE){
    nombre = NOMBRE;
}
void setDni(string DNI){
    dni = DNI;
}
void setHistorial(list<Libro> HISTORIAL){
    historial = HISTORIAL;
}
void setLibroActual(Libro LIBRO){
    libro  = LIBRO;
}

void sacarLibro(){
    
}
void devolverLibro(){
    
}
void visualizarUsuario(){
    
}


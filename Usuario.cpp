#include <cstdlib>
#include <iostream>

using namespace std;

class Usuario {
    private:
    int Id;
    string Nombre;
    string DNI;
    //Libro Historial
    //Libro LibroActual
    //Date FechaAdquisicion
    //Date FechaDevolucion
    
    public:
    Usuario(int, string, string);
    //Métodos de la clase
    string verHistorial(); //tecnicamente es una lista
    void verSiTieneLibro();
    void sacarLibro();
    void devolverLibro();
    void visualizarusuario();
};

//Constructor, inicializamos los atributos
    Usuario::Usuario(int _Id, string _Nombre, string _DNI){
        Id = _Id;
        Nombre = _Nombre;
        DNI = _DNI;
    }

    void Usuario::visualizarusuario(){
        cout << Id << ", " << Nombre <<", "<< DNI <<"\n";
    }


/*
int main(int argc, char *argv[]){
        Usuario u1 = Usuario(1,"Álvaro","38283828z");

        u1.visualizarusuario();

return 0;
}
*/
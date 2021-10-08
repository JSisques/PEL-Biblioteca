
#include <iostream>
using namespace std;

class Libro{

    private: 
    //Se definen los parámetros
        int id;
        string nombre;
        string isbn;
        string categoria;
        int numeroPaginas;
        bool disponible;
        Usuario usuarioPoseedor;

    public:
    //Constructor
        Libro(int ID, string name, string ISBN, string cat, int np, bool disp){ 
            id=ID;
            nombre=name;
            isbn=ISBN;
            categoria=cat;
            numeroPaginas=np;
            disponible=disp;
        }

        bool isDisponible(); //Declaración disponibilidad
       
};

//Implementación del método disponibilidad
bool Libro::isDisponible(){ 

    

}

int main(int argc, char *argv[]){



}
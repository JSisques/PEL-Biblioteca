
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

        int getId();
        string getNombre();
        string getIsbn();
        string getCategoria();
        int getNumeroPaginas();
        Usuario getUsuarioPoseedor();
        
        void setId(int);
        void setNombre(string);
        void setIsbn(string);
        void setCategoria(string);
        void setNumeroPaginas(int);
        void setUsuarioPoseedor(Usuario);
};

int Libro::getId(){
    return id;
    }
string Libro::getNombre(){
    return nombre;
    }
string Libro::getIsbn(){
    return isbn;
    }
string Libro::getCategoria(){
    return categoria;
    }
int Libro::getNumeroPaginas(){
    return numeroPaginas;
    }
Usuario Libro::getUsuarioPoseedor(){
    return usuarioPoseedor;
    }

void Libro::setId(int ID){
    id=ID;
    }
void Libro::setNombre(string name){
    nombre=name;
    }
void Libro::setIsbn(string ISBN){
    isbn=ISBN;
    }
void Libro::setCategoria(string cat){
    categoria=cat;
    }
void Libro::setNumeroPaginas(int np){
    numeroPaginas=np;
    }
void Libro::setUsuarioPoseedor(Usuario user){
    usuarioPoseedor=user;
    }

//Implementación del método disponibilidad
bool Libro::isDisponible(){
    return disponible;

}

int main(int argc, char *argv[]){



}
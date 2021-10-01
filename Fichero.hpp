#include <string>
#include <Constants.hpp>

class Fichero{
    private:
        string fileName;
        
    public:
        bool existeDirectorio(string path);
        bool guardarDatosJSON(Usuario);
        bool guardarDatosJSON(Biblioteca);
        Biblioteca leerDatosJSON(string);
        Usuario leerDatosJSON(string);
};

bool Fichero::guardarDatosJSON(Usuario user){

}

bool Fichero::guardarDatosJSON(Biblioteca biblioteca){

}

Biblioteca Fichero::leerDatosJSON(){

}

Usuario Fichero::leerDatosJSON(string dni){

}
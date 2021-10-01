#include <string>
#include <fstream>
#include "Constants.hpp"
#include "Usuario.cpp"
#include <sys/stat.h>

using namespace std;

class Fichero{
    private:
        string fileName;
        
    public:
        string guardarJSON(string, string);
        bool existeDirectorio(string);
        string crearJSON(Usuario);
        //bool crearJSON(Biblioteca);
        //Biblioteca leerDatosJSON(string);
        //Usuario leerDatosJSON(string);
};

/*
Este metodo gardara un string en formato JSON en un fichero indicado por parametro.
Devuelve el propio JSON pasado por parámetro.
*/
string Fichero::guardarJSON(string json, string nombreFichero){
    ofstream out(Constants::DATA_PATH + nombreFichero + Constants::JSON_EXTENSION);
    out << json;
    out.close();
    return json;
}

/*
Este metodo comprobara si existe el directorio pasado por parametro.
Devolverá un 1 si existe o un 0 en caso contrario.
*/
bool Fichero::existeDirectorio(string path){
    struct stat buffer;
    return (stat (path.c_str(), &buffer) == 0);
}

/*
Este método creará un JSON a partir de los datos del usuario pasado como parametro.
Devolverá un String con el JSON creado.
*/
string Fichero::crearJSON(Usuario user){
    string json = "";

    json += "terere";

    return json;
}
/*
bool Fichero::crearJSON(Biblioteca biblioteca){
    return true;
}

Biblioteca Fichero::leerDatosJSON(){

}

Usuario Fichero::leerDatosJSON(string dni){

}
*/
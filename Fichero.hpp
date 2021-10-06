#include <string>
#include <fstream>
#include "Constants.hpp"
#include "Biblioteca.hpp"
#include "Usuario.cpp"
#include <sys/stat.h>

using namespace std;


class Fichero{
    private:
        string fileName;
        
    public:
        string crearJSONBiblioteca(Biblioteca);
        string crearJSONUsuario();
        string crearJSONLibro();
        string guardarJSON(string, string, string);
        bool existeDirectorio(string);
        string leerDatosFichero(string, string, string);
        //Biblioteca leerDatosJSON(string);
        //Usuario leerDatosJSON(string);
};

/*
Este metodo gardara un string en formato JSON en un fichero indicado por parametro.
Devuelve el propio JSON pasado por parámetro.
*/
string Fichero::guardarJSON(string path, string json, string nombreFichero){
    ofstream out(path + nombreFichero + Constants::JSON_EXTENSION);
    out << json;
    out.close();
    return json;
}

/*
Este metodo comprobara si existe el directorio pasado por parametro y en caso de que no exista lo crea.
Devolverá un 1 si existe o un 0 en caso contrario.
*/
bool Fichero::existeDirectorio(string path){
    struct stat buffer;

    bool exist = (stat (path.c_str(), &buffer) == 0);

    if (!exist){
        mkdir(path.c_str());
    }

    return exist;
}

/*
Este método creará un JSON a partir de los datos del usuario pasado como parametro.
Devolverá un String con el JSON creado.
*/
string Fichero::crearJSONUsuario(){
    string json = "{";

    //json += "\"id\": " + user.getId() + ",";
    //json += "\"dni\": " + user.getDni() + ",";
    //json += "\"nombre\": " + user.getNombre() + ",";
    //json += "\"libroActual\": { \"id\": " + user.getLibroActual().getId() + ", \"nombre\": " + user.getLibroActual().getNombre()  + ", \"isbn\": " + user.getLibroActual().getIsbn()  + ", \"categoria\": " + user.getLibroActual().getCategoria()  + ", \"numeroPag\": " + user.getLibroActual().getNumeroPag() + ", \"disponible\": " + user.getLibroActual().getDisponible() + "}";

    json += "\"id\": 1,";
    json += "\"dni\": \"11111111P\",";
    json += "\"nombre\": \"Prueba\",";
    json += "\"libroActual\": " + crearJSONLibro();


    json += "}";

    return json;
}

/*
Este método creará un JSON a partir de los datos del libro pasado como parametro.
Devolverá un String con el JSON creado.
*/
string Fichero::crearJSONLibro(){
    string json = "{";

    json += "\"id\": 1, \"nombre\": \"Caminos\", \"isbn\": \"1231443SFASD\", \"categoria\": \"Horror\", \"numeroPag\": 123, \"disponible\": true";

    json += "}";

    return json;
}

/*
Este método creará un JSON a partir de los datos de la biblioteca pasada como parametro.
Devolverá un String con el JSON creado.
*/
string Fichero::crearJSONBiblioteca(Biblioteca biblioteca){
    string json = "[";
    
    /*
    for(Libro libro: biblioteca.getArrayLibros()){
        json += crearJSONLibro() + ",";
    }
    */

    for (int i = 10 - 1; i >= 0; i--)
    {
        json += crearJSONLibro() + ",";
    }

    //Para quitar la ultima coma
    json.pop_back();

    json += "]";

    return json;
}

/*
Este metodo lee el contenido de un fichero ubicado en una ruta pasado por parámetro.
Devuelve el contenido del propio fichero en forma de string
*/
string Fichero::leerDatosFichero(string path, string nombre, string extension){
    path = path + nombre + extension;
    string json = "";

    //Abrimos el fichero
    ifstream input_file(path);

    if (!input_file.is_open()){
        cerr << "No se ha podido abrir el archivo de la ruta " << path;
    }
    
    //Leemos el fichero
    json = string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());

    cout << json << endl;
    return json;
}

/*
Biblioteca Fichero::leerDatosJSON(){

}

Usuario Fichero::leerDatosJSON(string dni){

}
*/
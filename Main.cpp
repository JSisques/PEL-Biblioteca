#include <string>
#include <list>
#include <iostream>
#include <iostream>
#include <sys/stat.h>
#include <fstream>

using namespace std;

/*****************************************
 * CLASE LIBRO
 *****************************************/
class Libro{

    private:
    //Se definen los parámetros
        int id;
        string nombre;
        string isbn;
        string categoria;
        int numeroPaginas;
        bool disponible;

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
        
        void setId(int);
        void setNombre(string);
        void setIsbn(string);
        void setCategoria(string);
        void setNumeroPaginas(int);
};

int Libro::getId(){
    return id;
};
string Libro::getNombre(){
    return nombre;
};
string Libro::getIsbn(){
    return isbn;
};
string Libro::getCategoria(){
    return categoria;
};
int Libro::getNumeroPaginas(){
    return numeroPaginas;
};

void Libro::setId(int ID){
    id=ID;
};
void Libro::setNombre(string name){
    nombre=name;
};
void Libro::setIsbn(string ISBN){
    isbn=ISBN;
};
void Libro::setCategoria(string cat){
    categoria=cat;
};
void Libro::setNumeroPaginas(int np){
    numeroPaginas=np;
};

//Implementación del método disponibilidad
bool Libro::isDisponible(){
    return disponible;

};

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

int Usuario::getId(){
    return id;
}
string Usuario::getNombre(){
    return nombre;
}
string Usuario::getDni(){
    return dni;
}
/*
list<Libro> Usuario::getHistorial(){
    return historial;
}
Libro Usuario::getLibroActual(){
    return libroActual;
}
*/

void Usuario::setId(int ID){
    id = ID;
}
void Usuario::setNombre(string NOMBRE){
    nombre = NOMBRE;
}
void Usuario::setDni(string DNI){
    dni = DNI;
}
/*
void Usuario::setHistorial(list<Libro> HISTORIAL){
    historial = HISTORIAL;
}
void Usuario::setLibroActual(Libro LIBRO){
    libroActual  = LIBRO;
}
*/

void sacarLibro(){
    
}
void devolverLibro(){
    
}
void visualizarUsuario(){
    
}

class Fichero{
    private:
        string fileName;
        
    public:
        //string crearJSONBiblioteca(Biblioteca);
        string crearJSONUsuario();
        string crearJSONLibro(Libro);
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
    ofstream out(path + nombreFichero + ".json");
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
    json += "\"libroActual\": " + crearJSONLibro(Libro(0,"Prueba", "23424ff", "Horror", 123, true));


    json += "}";

    return json;
}

/*
Este método creará un JSON a partir de los datos del libro pasado como parametro.
Devolverá un String con el JSON creado.
*/
string Fichero::crearJSONLibro(Libro libro){
    string json = "{";

    json += "\"id\": " + std::to_string(libro.getId()) + "\"nombre\":" + libro.getNombre() + "\"isbn\": " + libro.getIsbn() + "\"categoria\": " + libro.getCategoria() + "\"numeroPag\": " + std::to_string(libro.getNumeroPaginas()) + "\"disponible\":" + std::to_string(libro.isDisponible());
    //json += "\"id\": 1, \"nombre\": \"Caminos\", \"isbn\": \"1231443SFASD\", \"categoria\": \"Horror\", \"numeroPag\": 123, \"disponible\": true";

    json += "}";

    return json;
}

/*
Este método creará un JSON a partir de los datos de la biblioteca pasada como parametro.
Devolverá un String con el JSON creado.
*/

/*
string Fichero::crearJSONBiblioteca(Biblioteca biblioteca){
    string json = "[";
    
    /*
    for (int i = 10 - 1; i >= 0; i--)
    {
        json += crearJSONLibro() + ",";
    }
    
    */

   /*
    for(Libro libro: biblioteca.getArrayLibros()){
        json += crearJSONLibro(libro) + ",";
    }

    //Para quitar la ultima coma
    json.pop_back();

    json += "]";

    return json;
} */

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

void pintarMenu();

int main() {

    Fichero f = Fichero();
    //Biblioteca b = Biblioteca();
    //Usuario u = Usuario(0, "Prueba", "11111111J");

    bool response = f.existeDirectorio("./data/library/");
    cout << response;

    string json = f.crearJSONUsuario();
    f.guardarJSON("./data/user/" ,json, "usuarioPrueba");
    f.leerDatosFichero("./data/user/", "usuarioPrueba", ".json");
    //json = f.crearJSONBiblioteca();
    f.guardarJSON("./data/library/", json, "Biblioteca");

    //MENÚ
    int opcion = -1;
    do{

        pintarMenu();
        cin >> opcion;
        switch (opcion){
        case 1:
           /* code */
           break;
       
        default:
           break;
        }

    } while (opcion != 0);
    

    //f.crearJSON(u);
    return 0;
}

void pintarMenu(){
    /*Comprobar qué libros hay disponibles en la biblioteca 
Ver el historial de libros de una persona 
Ver si una persona tiene un libro o no 
Sacar/Devolver un libro */
    cout << "[] -> Comprobar libros disponibles \n";
    cout << "[] -> Ver el historial de libros de una persona \n";
    cout << "[] -> Ver si una persona tiene un libro o no \n";
    cout << "[] -> Sacar un libro \n";
    cout << "[] -> Devolver un libro \n";
    cout << "[0] -> Salir \n";
    cout << "Elige una opción: \n";

}
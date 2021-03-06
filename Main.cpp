#include <string>
#include <list>
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
        Libro();
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
        void setDisponible(bool);

        void visualizarLibro();
};
Libro::Libro(){
    
}

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

void Libro::setDisponible(bool dis){
    disponible  = dis;
}

void Libro::visualizarLibro(){
    cout << nombre << " " << isbn << " " << categoria << " " << numeroPaginas << " " << disponible << endl;
}

/*****************************************
 * CLASE USUARIO
 *****************************************/

class Usuario{
    private:
        string nombre;
        string dni;
        list<Libro> historial;
        Libro libroActual;
        //Date FechaAdquisicion
        //Date FechaDevolucion

    public:
        Usuario();
        Usuario(string, string);
        string getNombre();
        string getDni();
        list<Libro> getHistorial();
        Libro getLibroActual();

        void setNombre(string);
        void setDni(string);
        void setHistorial(list<Libro>);
        void setLibroActual(Libro);

        void sacarLibro();
        void devolverLibro();
        void visualizarUsuario();
        void anadirHistorial(Libro);
};

Usuario::Usuario(){

}

Usuario::Usuario(string NOMBRE, string DNI){
    nombre = NOMBRE;
    dni = DNI;
}

string Usuario::getNombre(){
    return nombre;
}
string Usuario::getDni(){
    return dni;
}

list<Libro> Usuario::getHistorial(){
    return historial;
}
Libro Usuario::getLibroActual(){
    return libroActual;
}


void Usuario::setNombre(string NOMBRE){
    nombre = NOMBRE;
}
void Usuario::setDni(string DNI){
    dni = DNI;
}

void Usuario::setHistorial(list<Libro> HISTORIAL){
    historial = HISTORIAL;
}
void Usuario::setLibroActual(Libro LIBRO){
    libroActual  = LIBRO;
}
void Usuario::sacarLibro(){
}
void Usuario::devolverLibro(){
}
void Usuario::visualizarUsuario(){
    cout << "Nombre: "<< nombre << " DNI:"<<dni<<"\n";
}

void Usuario::anadirHistorial(Libro l){
    historial.push_front(l);
}

/*****************************************
 * CLASE FICHERO
 *****************************************/

class Fichero{
    private:
        string fileName;
        
    public:
        string crearJSONBiblioteca(list<Libro>);
        string crearJSONUsuario(Usuario);
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
string Fichero::crearJSONUsuario(Usuario user){
    string json = "{";

    json += "\"dni\": \"" + user.getDni() + "\",";
    json += "\"nombre\": \"" + user.getNombre() + "\",";
    json += "\"libroActual\": " + crearJSONLibro(user.getLibroActual()) + ",";
    json += "\"historial\": " + crearJSONBiblioteca(user.getHistorial());

    /*
    json += "\"id\": 1,";
    json += "\"dni\": \"11111111P\",";
    json += "\"nombre\": \"Prueba\",";
    json += "\"libroActual\": " + crearJSONLibro(Libro(0,"Prueba", "23424ff", "Horror", 123, true));

    */
    json += "}";

    return json;
}

/*
Este método creará un JSON a partir de los datos del libro pasado como parametro.
Devolverá un String con el JSON creado.
*/
string Fichero::crearJSONLibro(Libro libro){
    string json = "{";

    json += "\"id\": " + std::to_string(libro.getId()) + ", \"nombre\": \"" + libro.getNombre() + "\", \"isbn\": \"" + libro.getIsbn() + "\", \"categoria\": \"" + libro.getCategoria() + "\",\"numeroPag\": " + std::to_string(libro.getNumeroPaginas()) + ", \"disponible\":" + std::to_string(libro.isDisponible());
    //json += "\"id\": 1, \"nombre\": \"Caminos\", \"isbn\": \"1231443SFASD\", \"categoria\": \"Horror\", \"numeroPag\": 123, \"disponible\": true";

    json += "}";

    return json;
}

/*
Este método creará un JSON a partir de los datos de la biblioteca pasada como parametro.
Devolverá un String con el JSON creado.
*/


string Fichero::crearJSONBiblioteca(list<Libro> biblio){
    string json = "[";
    
    /*
    for (int i = 10 - 1; i >= 0; i--)
    {
        json += crearJSONLibro() + ",";
    }
    
    */

   
    for(Libro libro: biblio){
        json += crearJSONLibro(libro) + ",";
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

void pintarMenu();
void Bienvenida();

int main() {

    Fichero f = Fichero();
    //Biblioteca b = Biblioteca();
    //Usuario u = Usuario(0, "Prueba", "11111111J");

    list<Libro> biblioteca = {

    Libro(1, "La Biblia", "123456a", "Ciencia Ficcion", 2585, true),
    Libro(2, "Citas del Presidente Mao Tse-Tung", "123456b", "Politica", 258, true),
    Libro(3, "Harry Potter", "123456c", "Ciencia Ficcion", 358, true),
    Libro(4, "El Señor de los Anillos", "123456d", "Ciencia Ficcion", 593, true),
    Libro(5, "El Alquimista", "123456e", "Drama", 365, true),
    Libro(6, "El Codigo da Vinci", "123456f", "Misterio", 526, true),
    Libro(7, "Crepusculo", "123456g", "Ciencia Ficcion", 487, true),
    Libro(8, "Lo que el viento se llevo", "123456h", "Drama", 224, true),
    Libro(9, "Piense y hagase rico", "123456i", "Comedia", 198, true),
    Libro(10, "El diario de Ana Frank", "123456j", "Historia", 253, true),
    Libro(11, "Luces de Bohemia", "123456k", "Ciencia Ficcion", 298, true),
    Libro(12, "Crimen y castigo", "123456l", "Misterio", 169, true),
    Libro(13, "La casa de los espiritus", "123456m", "Ciencia Ficcion", 255, true),
    Libro(14, "El extranjero", "123456n", "Comedia", 145, true),
    Libro(15, "1984", "123456o", "Ciencia Ficcion", 364, true),
    Libro(16, "La colmena", "123456p", "Ciencia Ficcion", 192, true),
    Libro(17, "Don Quijote de la mancha", "123456q", "Ciencia Ficcion", 1595, true),
    Libro(18, "Al faro", "123456r", "Drama", 364, true),
    Libro(19, "Guerra y paz", "123456s", "Historia", 291, true),
    Libro(20, "La montaña magica", "123456t", "Ciencia Ficcion", 436, true)
    };

    string isbnUsuario;
    list <Libro>::iterator itrLibro;

    bool response = f.existeDirectorio("./data/library/");
    cout << response;
    /*
    string json = f.crearJSONUsuario();
    f.guardarJSON("./data/user/" ,json, "usuarioPrueba");
    f.leerDatosFichero("./data/user/", "usuarioPrueba", ".json");
    //json = f.crearJSONBiblioteca();
    f.guardarJSON("./data/library/", json, "Biblioteca");
    */
    //MENÚ
    int opcion = -1;
    string nombre;
    string DNI;
    
    Bienvenida();
    cout << "Nombre: ";
    cin >> nombre;
    cout << "DNI: ";
    cin >> DNI;

    Usuario u = Usuario(nombre, DNI);

    list<Usuario> listadoUsuarios = {u};
    
    do{
        Bienvenida();
        pintarMenu();
        cin >> opcion;
        switch (opcion){
        case 1:
           for(Libro libro: biblioteca){
               if (libro.isDisponible()){
                   libro.visualizarLibro();
               }
           }
           break;
        case 2:
           for(Libro libro: u.getHistorial()){
               libro.visualizarLibro();
           }
           break;
        case 3:
            u.getLibroActual().visualizarLibro();
           break;
                
        case 4:
            //if (u.getLibroActual() != nullptr)
            cout << "Escribe el ISBN del libro: \n";
            
            cin >> isbnUsuario;

            
            for(itrLibro = biblioteca.begin(); itrLibro != biblioteca.end(); itrLibro++) {
                if((*itrLibro).getIsbn() == isbnUsuario) {
                    u.setLibroActual(*itrLibro);
                    u.anadirHistorial(*itrLibro);
                    (*itrLibro).setDisponible(false);
                }
            }
           
           
           break;

        case 5:
            //biblioteca.push_front(u.getLibroActual());

            for(itrLibro = biblioteca.begin(); itrLibro != biblioteca.end(); itrLibro++) {
                if((*itrLibro).getIsbn() == u.getLibroActual().getIsbn()) {
                    (*itrLibro).setDisponible(true);
                }
            }

           break;

        case 6:
            f.guardarJSON("./data/user/", f.crearJSONUsuario(u), u.getNombre());
            f.guardarJSON("./data/libros/", f.crearJSONBiblioteca(biblioteca), "Biblioteca");

           break;
        
        case 7: {
            cout << "Nombre: ";
            cin >> nombre;
            cout << "DNI: ";
            cin >> DNI;
            Usuario nuevoUsuario = Usuario(nombre, DNI);
            u = nuevoUsuario;
            listadoUsuarios.push_back(nuevoUsuario);
           break;
        }

        case 8: {
            for(Usuario user: listadoUsuarios){
                user.visualizarUsuario();
            }
           break;
        }
       
        case 9: {
            cout << "Escribe el ISBN del libro: \n";
            cin >> isbnUsuario;

            list<Usuario>::iterator itrUsuario;
            for(itrUsuario = listadoUsuarios.begin(); itrUsuario != listadoUsuarios.end(); itrUsuario++) {
                if((*itrUsuario).getLibroActual().getIsbn().compare(isbnUsuario)) {
                    cout << "El libro con ISBN " << isbnUsuario << " lo tiene el usuario " << (*itrUsuario).getNombre() << " y DNI " << (*itrUsuario).getDni() << endl;
                }
            }
           break;
        }
       
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
    cout << "[1] -> Comprobar libros disponibles \n";
    cout << "[2] -> Ver el historial de libros de una persona \n";
    cout << "[3] -> Ver si una persona tiene un libro o no \n";
    cout << "[4] -> Sacar un libro \n";
    cout << "[5] -> Devolver un libro \n";
    cout << "[6] -> Guardar datos \n";
    cout << "[7] -> Cambiar de usuario \n";
    cout << "[8] -> Ver usuarios en la App \n";
    cout << "[9] -> Comrpobar quien tiene un libro \n";
    cout << "[0] -> Salir \n";
    cout << "Elige una opción: \n";
}

void Bienvenida(){
    /*Bienvenida del documento*/
    cout << "\nBienvenido a la Biblioteca Virtual \n";

}
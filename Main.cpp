#include <iostream>
#include "Fichero.hpp"
#include "Constants.hpp"
//#include "Usuario.cpp"

using namespace std;

void pintarMenu();

int main() {

    Fichero f = Fichero();
    Biblioteca b = Biblioteca();
    //Usuario u = Usuario(0, "Prueba", "11111111J");

    bool response = f.existeDirectorio(Constants::DATA_LIBRARY_PATH);
    cout << response;

    string json = f.crearJSONUsuario();
    f.guardarJSON(Constants::DATA_USER_PATH ,json, "usuarioPrueba");
    f.leerDatosFichero(Constants::DATA_USER_PATH, "usuarioPrueba", Constants::JSON_EXTENSION);
    json = f.crearJSONBiblioteca(b);
    f.guardarJSON(Constants::DATA_LIBRARY_PATH, json, "Biblioteca");

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



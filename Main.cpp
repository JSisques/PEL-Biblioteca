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
    cout << "Elige una opción: ";
    cout << "[] -> Comprobar libros disponibles";
    cout << "[] -> Ver el historial de libros de una persona";
    cout << "[] -> Ver si una persona tiene un libro o no";
    cout << "[] -> Sacar un libro";
    cout << "[] -> Devolver un libro";
    cout << "[0] -> Salir";

}



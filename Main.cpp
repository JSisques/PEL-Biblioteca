#include <iostream>
#include "Fichero.hpp"
#include "Constants.hpp"
//#include "Usuario.cpp"

using namespace std;

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

    //f.crearJSON(u);
    return 0;
}

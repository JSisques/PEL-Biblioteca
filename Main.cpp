#include <iostream>
#include "Fichero.hpp"
#include "Constants.hpp"
#include "Usuario.cpp"

using namespace std;

int main() {

    Fichero f = Fichero();
    //Usuario u = Usuario(0, "Prueba", "11111111J");

    bool response = f.existeDirectorio(Constants::DATA_PATH);
    cout << response;

    f.guardarJSON("{\"nombre\": \"Javi\"}", "Prueba");
    //f.crearJSON(u);
    return 0;
}

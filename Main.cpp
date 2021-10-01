#include <iostream>
#include "Fichero.hpp"
#include "Constants.hpp"

using namespace std;

int main() {

    Fichero f = Fichero();

    bool response = f.existeDirectorio(Constants::DATA_PATH);
    cout << response;

    f.guardarJSON("{\"nombre\": \"Javi\"}", "Prueba");
    return 0;
}

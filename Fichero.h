#include <string>

class Fichero{
    private:
        
    public:
        bool guardarDatosJSON(Usuario);
        bool guardarDatosJSON(Biblioteca);
        Biblioteca leerDatosJSON(string);
        Usuario leerDatosJSON(string)
};
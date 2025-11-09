#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <iostream>
#include <cstring>

using namespace std;

class Proveedor {
private:
    int id;
    char nombre[35];
    char telefono[25];
    char direccion[120];
    char rubro[15];
    bool alta;

public:


    // Getters
    int getIdProveedor();
    const string getNombre();
    const string getTelefono();
    const string getDireccion();
    const string getRubro();
    bool getAlta();

    // Setters
    void setIdProveedor(int id);
    void setNombre(const string& nombre);
    void setTelefono(const string& telefono);
    void setDireccion(const string& direccion);
    void setRubro(const string& rubro);
    void setAlta(bool alta);

    // Metodos

};

#endif // PROVEEDOR_H

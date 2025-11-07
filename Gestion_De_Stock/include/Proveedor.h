#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <iostream>
#include <cstring>

using namespace std;

class Proveedor
{

    private:
        int idProveedor;
        string nombre;
        string telefono;
        string direccion;
        string rubro;
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
    void cargar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
    
        
};

#endif // PROVEEDOR_H

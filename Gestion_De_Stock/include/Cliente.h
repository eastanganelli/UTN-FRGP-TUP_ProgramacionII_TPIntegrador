#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

#include <iostream>
#include <cstring>

using namespace std;

class Cliente : public Persona {
private:
    int idCliente;
    int idTipoResponsable;
    string correo;
    string cuilCuit;
    bool alta;

public:
    // Getters
    int getIDCliente();
    const string getCorreo();
    const string getCuilCuit();
    bool getAlta();
    int getIDTipoResponsable();

    // Setters
    void setIDCliente(int id);
    void setCorreo(const char* c);
    void setCorreo(const string& c);
    void setCuilCuit(const char* c);
    void setCuilCuit(const string& c);
    void setAlta(bool a);
    void setIDTipoResponsable(int id);

    // Métodos
    void cargar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
};

std::ostream& operator<<(std::ostream& os, const Cliente& obj);

#endif // CLIENTE_H```
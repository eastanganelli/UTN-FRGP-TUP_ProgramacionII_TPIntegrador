#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Cliente : public Persona {
private:
    const unsigned int id;
    unsigned int idTipoResponsable;
    char cuilCuit[11];

public:
    Cliente(unsigned int _id, unsigned int _);
    ~Cliente();

    // Getters
    int getID();
    const string getCuilCuit();
    int getIDTipoResponsable();

    // Setters
    void setCuilCuit(const string& cuilCuit);
    void setIDTipoResponsable(int id);

    // Métodos
    //void cargar();
    //bool escribirDisco(int pos);
    //bool leerDisco(int pos);
};

std::ostream& operator<<(std::ostream& os, const Cliente& obj);

#endif // CLIENTE_H```

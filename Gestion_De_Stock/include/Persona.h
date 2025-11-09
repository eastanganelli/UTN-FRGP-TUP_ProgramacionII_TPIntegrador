#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Persona {
protected:
    char nombre[20];
    char apellido[25];
    char telefono[2][15];

public:
    Persona();
    ~Persona();

    // Getters
    string getNombre();
    string getApellido();
    string getTelefono(int posicion);

    // Setters
    void setNombre(const string& n);
    void setApellido(const string& a);
    void setTelefono(const string& t, int posicion);
};

#endif // PERSONA_H

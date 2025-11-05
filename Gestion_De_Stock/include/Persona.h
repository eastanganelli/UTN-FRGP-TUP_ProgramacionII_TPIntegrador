#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Persona {
protected:
    string nombre, 
            apellido, 
            telefono, 
            celular;

public:
    Persona();
    ~Persona();

    // Getters
    const string& getNombre();
    const string& getApellido();
    const string& getTelefono();
    const string& getCelular();

    // Setters
    void setNombre(const string& n);
    void setNombre(const char* n);
    void setApellido(const string& a);
    void setApellido(const char* a);
    void setTelefono(const string& t);
    void setTelefono(const char* t);
    void setCelular(const string& c);
    void setCelular(const char* c);
};

#endif // PERSONA_H

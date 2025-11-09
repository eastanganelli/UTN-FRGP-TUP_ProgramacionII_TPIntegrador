#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Persona {
protected:
    char DNI[8];
    char nombre[20];
    char apellido[25];
    char telefono[2][15];
    char correo[120];
    bool alta;

public:
    Persona(string& _nombre, string& _apellido, string& _DNI);
    Persona(string& _nombre, string& _apellido, string& _DNI, string& _telefono_I);
    Persona(string& _nombre, string& _apellido, string& _DNI, string& _telefono_I, string& _telefono_II);
    ~Persona();

    // Getters
    bool getAlta();
    string getDNI();
    string getNombre();
    string getApellido();
    string getCorreo();
    string getTelefono(int posicion);

    // Setters
    void setAlta(bool a);
    void setDNI(const string& dni);
    void setNombre(const string& n);
    void setApellido(const string& a);
    void setCorreo(const string& correo);
    void setTelefono(const string& t, int posicion);
};

#endif // PERSONA_H

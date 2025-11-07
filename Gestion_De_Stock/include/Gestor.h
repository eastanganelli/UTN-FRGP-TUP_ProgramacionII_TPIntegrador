#ifndef GESTOR_H
#define GESTOR_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Gestor {
private:

public:
    // Getters

    // Setters

    // Métodos
    void cargar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
};


std::ostream& operator<<(std::ostream& os, const Gestor& obj);

#endif // GESTOR_H

#include "generator.h"

std::string DataGenerator::generarCodigoAlfaNumerico(int longitud) {
    const char caracteresPosibles[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int numCaracteresPosibles = sizeof(caracteresPosibles) - 1;
    std::string codigoGenerado = "";
    for (int i = 0; i < longitud; ++i) {
        codigoGenerado += caracteresPosibles[rand() % numCaracteresPosibles];
    }
    return codigoGenerado;
}

std::string DataGenerator::generarNumero(unsigned int longitud) {
    std::string numero;
    numero.reserve(longitud);
    for (unsigned int i = 0; i < longitud; ++i) {
        numero.push_back(static_cast<char>('0' + (rand() % 10)));
    }
    return numero;
}
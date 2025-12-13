#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

using namespace std;

namespace Validation {

    /**
     * Helpers (comprobaciones carácter a carácter).
     * Sólo se declaran aquí; las implementaciones pueden permanecer
     * en el .cpp para mantenerlas con enlace interno si se desea.
     */
    /**
     * @brief Comprueba si un carácter es un espacio en blanco (espacio, tab, newline, etc.).
     * @param c Carácter a evaluar.
     * @return true si es un carácter de espacio; false en caso contrario.
     */
    bool IsSpaceChar(char c);

    /**
     * @brief Comprueba si un carácter es un dígito ASCII ('0'..'9').
     * @param c Carácter a evaluar.
     * @return true si es un dígito; false en caso contrario.
     */
    bool IsDigitChar(char c);

    /**
     * @brief Comprueba si un carácter es alfabético ASCII (A-Z, a-z).
     * @param c Carácter a evaluar.
     * @return true si es letra; false en caso contrario.
     */
    bool IsAlphaChar(char c);

    /**
     * @brief Comprueba si un carácter es alfanumérico ASCII (letra o dígito).
     * @param c Carácter a evaluar.
     * @return true si es letra o dígito; false en caso contrario.
     */
    bool IsAlnumChar(char c);


    /**
     * @brief Verifica si un número es positivo (> 0).
     * @tparam T Tipo numérico (int, float, double, etc.).
     * @param number Valor a evaluar.
     * @return true si el número es mayor que cero; false en caso contrario.
     */
    template <typename T>
    bool IsPositiveNumber(T number);

    /**
     * @brief Verifica si un valor está dentro de un rango [min, max].
     * @tparam T Tipo comparable.
     * @param value Valor a evaluar.
     * @param min Límite inferior (incluido).
     * @param max Límite superior (incluido).
     * @return true si min <= value <= max; false en caso contrario.
     */
    template <typename T>
    bool IsInRange(T value, T min, T max);

    /**
     * @brief Comprueba si una cadena está vacía (sin caracteres o solo espacios).
     * @param str Cadena a evaluar.
     * @return true si la cadena está vacía o contiene solo espacios; false en caso contrario.
     */
    bool IsEmpty(const string& str);

    /**
     * @brief Comprueba si una cadena está vacía (sin caracteres o solo espacios).
     * @param str Cadena a evaluar.
     * @return true si la cadena está vacía o contiene solo espacios; false en caso contrario.
     */
    bool IsEmpty(const char* str);

    /**
     * @brief Comprueba si una cadena representa un número (solo dígitos).
     * @param str Cadena a evaluar.
     * @return true si la cadena contiene únicamente caracteres numéricos; false en caso contrario.
     */
    bool IsNumeric(const string& str);

    /**
     * @brief Comprueba si una cadena contiene solo letras (alfabéticas).
     * @param str Cadena a evaluar.
     * @return true si la cadena contiene únicamente letras; false en caso contrario.
     */
    bool IsAlphabetic(const string& str);

    /**
     * @brief Comprueba si una cadena es alfanumérica (letras y/o números).
     * @param str Cadena a evaluar.
     * @return true si la cadena contiene solo letras y/o dígitos; false en caso contrario.
     */
    bool IsAlphanumeric(const string& str);

    /**
     * @brief Comprueba si dos cadenas son iguales.
     * @param str1 Primera cadena.
     * @param str2 Segunda cadena.
     * @return true si las cadenas son iguales; false en caso contrario.
     */
    bool IsEqual(const string& str1, const string& str2);

    /**
     * @brief Comprueba si dos cadenas son iguales.
     * @param str1 Primera cadena.
     * @param str2 Segunda cadena.
     * @return true si las cadenas son iguales; false en caso contrario.
     */
    bool IsEqual(const char* str1, const char* str2);

    /**
     * @brief Convierte una cadena a mayúsculas.
     * @param str Cadena a convertir.
     * @return Cadena en mayúsculas.
     */
    string ToUpper(const string& str);

    /**
     * @brief Convierte un número flotante a una cadena con formato de punto decimal fijo.
     * @param number Número a convertir.
     * @param decimalPlaces Cantidad de decimales deseados.
     * @return Cadena representando el número con el formato especificado.
     */
    string ToFixedDecimal(const float number, const unsigned int decimalPlaces);

    /**
     * @brief Elimina todos los espacios de la cadena (modifica la cadena dada).
     * @param s Cadena que será modificada.
     */
    void RemoveSpaces(string &s);
} // namespace Validation

template <typename T>
bool Validation::IsPositiveNumber(T number) {
    return number > 0;
}

template <typename T>
bool Validation::IsInRange(T value, T min, T max) {
    return value >= min && value <= max;
}

#endif // VALIDATION_H

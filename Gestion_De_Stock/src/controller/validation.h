#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

using namespace std;

namespace Validation {

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

} // namespace Validation

#endif // VALIDATION_H

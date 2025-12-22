#ifndef MENU_UTILS_H
#define MENU_UTILS_H

#include <string>
#include <string>
#include <cstdlib>
#include <iostream>

#include "../../rlutil.h"
#include "../controller/fecha.h"
#include "../controller/validation.h"
#include "../controller/table/table.h"

/** Solicita una cadena mostrando el prompt. */
std::string InputBox(const std::string& prompt);
/** Solicita un entero sin signo mostrando el prompt. */
unsigned int InputNumber(const std::string& prompt);
/** Solicita una fecha validada con el prompt dado. */
Fecha InputDate(const std::string& prompt);
/** Pide confirmacion simple (s/N). */
bool Confirm(const std::string& prompt);
/** Pausa la consola hasta Enter. */
void PauseConsole();
/** Limpia el buffer de entrada estandar. */
void FlushInput();
/** Muestra una tabla y retorna el indice elegido (1-based para el usuario). */
int SelectorIndex(Tabling::Table& table, const std::string& prompt, unsigned int maxExclusive);

#endif // MENU_UTILS_H

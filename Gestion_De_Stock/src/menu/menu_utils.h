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

std::string InputBox(const std::string& prompt);
unsigned int InputNumber(const std::string& prompt);
Fecha InputDate(const std::string& prompt);
bool Confirm(const std::string& prompt);
void PauseConsole();
void FlushInput();
int SelectorIndex(Tabling::Table& table, const std::string& prompt, unsigned int maxExclusive);

#endif // MENU_UTILS_H

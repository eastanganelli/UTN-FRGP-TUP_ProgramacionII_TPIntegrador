#ifndef MENU_UTILS_H
#define MENU_UTILS_H

#include <string>
#include <iostream>
#include <string>

#include "../controller/fecha.h"
#include "../controller/validation.h"

std::string InputBox(const std::string& prompt);
unsigned int InputNumber(const std::string& prompt);
Fecha InputDate(const std::string& prompt);
bool Confirm(const std::string& prompt);
void PauseConsole();
void FlushInput();

#endif // MENU_UTILS_H

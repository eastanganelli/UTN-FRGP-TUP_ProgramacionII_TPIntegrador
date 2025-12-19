#include "report.h"

Report::Report(const string& _title) : title(_title) {}

Report::~Report() = default;

const string& Report::GetTitle() const { return title; }

unsigned int Report::AskYearOrCurrent() {
	const unsigned int anioActual = (unsigned int)Fecha::Hoy().getAnio();
	const string prompt = "Ingrese el anio (Enter = " + to_string(anioActual) + "): ";
	string input = InputBox(prompt);
	if(Validation::IsEmpty(input)) {
		return anioActual;
	}
	if(Validation::IsNumeric(input)) {
		return (unsigned int)atoi(input.c_str());
	}
	return anioActual;
}

void Report::PrintDecoratedTitle(const string& text, char deco) {
	const size_t minWidth = 30;
	size_t width = text.size() + 4;
	if(width < minWidth) {
		width = minWidth;
	}

	string line(width, deco);
	const char fill = '*';
	std::string core = std::string(1, fill) + text + std::string(1, fill);
	if(core.size() < width) {
		const size_t remaining = width - core.size();
		const size_t leftPad = remaining / 2;
		const size_t rightPad = remaining - leftPad;
		core = std::string(leftPad, fill) + core + std::string(rightPad, fill);
	}

	cout << line << endl
		<< core << endl
		<< line << endl;
}

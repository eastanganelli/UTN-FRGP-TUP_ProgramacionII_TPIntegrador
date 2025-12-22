#ifndef REPORT_H
#define REPORT_H


#include "../controller/fecha.h"
#include "../menu/menu_utils.h"
#include "../controller/validation.h"

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Report {
protected:
	string title;

	/** Pregunta anio o usa el actual. */
	unsigned int AskYearOrCurrent();
	/** Imprime un titulo con decoracion. */
	void PrintDecoratedTitle(const string& text, char deco = '=');

public:
	/** Crea un reporte con titulo. */
	explicit Report(const string& _title);
	/** Destructor virtual de reporte. */
	virtual ~Report();

	/** Devuelve el titulo del reporte. */
	const string& GetTitle() const;
	/** Ejecuta el reporte concreto. */
	virtual void Run() = 0;
};

#endif // REPORT_H

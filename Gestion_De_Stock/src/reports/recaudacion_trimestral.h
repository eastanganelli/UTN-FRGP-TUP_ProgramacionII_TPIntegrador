#ifndef RECAUDACION_TRIMESTRAL_REPORT_H
#define RECAUDACION_TRIMESTRAL_REPORT_H

#include <iostream>

using namespace std;

#include "../menu/menu_utils.h"
#include "../controller/validation.h"

#include "../manager/ventas/manager_factura.h"

#include "report.h"

class RecaudacionTrimestralReport : public Report {
private:
    FacturaManager facturas;
    /** Calcula recaudacion de un trimestre especifico. */
    double CalcularRecaudacion(unsigned int anio, unsigned int trimestre);

public:
	/** Inicializa el reporte trimestral. */
	RecaudacionTrimestralReport();
	/** Ejecuta el reporte trimestral. */
	void Run() override;
};

#endif // RECAUDACION_TRIMESTRAL_REPORT_H

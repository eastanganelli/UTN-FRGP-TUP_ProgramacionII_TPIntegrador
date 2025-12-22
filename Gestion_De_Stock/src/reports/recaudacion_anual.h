#ifndef RECAUDACION_ANUAL_REPORT_H
#define RECAUDACION_ANUAL_REPORT_H

#include <iostream>

using namespace std;

#include "../menu/menu_utils.h"
#include "../controller/validation.h"

#include "../manager/ventas/manager_factura.h"

#include "report.h"

class RecaudacionAnualReport : public Report {
private:
    FacturaManager facturas;
    /** Calcula la recaudacion del anio. */
    double CalcularRecaudacion(unsigned int anio);

public:
	/** Inicializa el reporte anual. */
	RecaudacionAnualReport();
	/** Ejecuta el reporte anual. */
	void Run() override;
};

#endif // RECAUDACION_ANUAL_REPORT_H

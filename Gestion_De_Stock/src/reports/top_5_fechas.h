#ifndef TOP_5_FECHAS_REPORT_H
#define TOP_5_FECHAS_REPORT_H

#include "../manager/ventas/manager_factura.h"
#include "../controller/generic_array.h"
#include "../menu/menu_utils.h"

#include "report.h"

#include <string>

using namespace std;

class Top5FechasReport : public Report {
private:
    FacturaManager facturas;

	struct FechaData {
		int dia;
		int mes;
		int anio;
		double total;
		unsigned int comprobantes;
		bool found;
	};

	/** Calcula el top 5 de fechas por facturacion. */
	void CalcularTop(unsigned int anio, GenericArray<FechaData>& lista);

public:
	/** Inicializa el reporte Top 5 fechas. */
	Top5FechasReport();
	/** Ejecuta el reporte Top 5 fechas. */
	void Run() override;
};

#endif // TOP_5_FECHAS_REPORT_H

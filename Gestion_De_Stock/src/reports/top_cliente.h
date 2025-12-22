#ifndef TOP_CLIENTE_REPORT_H
#define TOP_CLIENTE_REPORT_H

#include <iostream>

using namespace std;

#include "../menu/menu_utils.h"
#include "../controller/validation.h"
#include "../controller/generic_array.h"
#include "../controller/modals/warning.h"

#include "../manager/manager_cliente.h"
#include "../manager/ventas/manager_factura.h"

#include "report.h"

class TopClienteReport : public Report {
private:
    ClienteManager clientes;
    FacturaManager facturas;

	struct TopClienteData {
		string dni;
		double total;
		unsigned int compras;
		bool found;
	};

	/** Calcula el cliente con mayor facturacion del anio. */
	TopClienteData CalcularTopCliente(unsigned int anio);

    
public:
	/** Inicializa el reporte de top cliente. */
	TopClienteReport();
	/** Ejecuta el reporte de top cliente. */
	void Run() override;
};

#endif // TOP_CLIENTE_REPORT_H

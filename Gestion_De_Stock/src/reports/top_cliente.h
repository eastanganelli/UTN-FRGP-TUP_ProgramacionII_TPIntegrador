#ifndef TOP_CLIENTE_REPORT_H
#define TOP_CLIENTE_REPORT_H

#include "../manager/ventas/manager_factura.h"
#include "../manager/manager_cliente.h"
#include "../menu/menu_utils.h"
#include "../controller/validation.h"
#include "../controller/generic_array.h"

#include "report.h"

#include <iostream>

using namespace std;

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

	TopClienteData CalcularTopCliente(unsigned int anio);

    
public:
	TopClienteReport();
	void Run() override;
};

#endif // TOP_CLIENTE_REPORT_H

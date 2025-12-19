#include "top_cliente.h"


TopClienteReport::TopClienteReport() : Report("Cliente con mayor volumen de compras") {}

void TopClienteReport::Run() {
	rlutil::cls();
	rlutil::setBackgroundColor(rlutil::BLUE);
	rlutil::setColor(rlutil::WHITE);
	PrintDecoratedTitle(this->GetTitle(), '=');
	rlutil::resetColor();

	unsigned int anio = AskYearOrCurrent();
	TopClienteData top = CalcularTopCliente(anio);

	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::setColor(rlutil::WHITE);
	rlutil::cls();
	PrintDecoratedTitle(this->GetTitle() + " (" + std::to_string(anio) + ")", '=');

	if (!top.found) {
		cout << "No hay facturas con CAE para el anio " << anio << "." << endl;
	} else {
		Cliente* c = clientes[top.dni];
		string nombre = c ? c->getNombre() : "";
		string apellido = c ? c->getApellido() : "";

		cout << "NOMBRE               : " << apellido << ", " << nombre << endl
			<< "DNI                  : " << top.dni << endl
			<< "COMPRAS              : " << top.compras << endl
			<< "GASTO TOTAL          : " << top.total << endl
			<< "==================================" << endl;
		if (c) delete c;
	}
}

TopClienteReport::TopClienteData TopClienteReport::CalcularTopCliente(unsigned int anio) {
	GenericArray<TopClienteData> agregados;
	TopClienteData top{ "", 0.0, 0, false };

	const unsigned int cantidad = facturas.Count();
	for(unsigned int i = 0; i < cantidad; i++) {
		Factura* f = facturas.At(i);
		if(f == nullptr) { continue; }
		
		const string cae = f->getCAE();
		if(cae.empty()) {
			delete f;
			continue;
		}
		
		const int anioFac = f->getFechaEmision().getAnio();
		if((unsigned int)anioFac != anio) {
			delete f;
			continue;
		}

		string dni = f->getClienteDNI();
		double monto = f->TotalSinIVA();

		int idx = -1;
		for(unsigned int j = 0; j < agregados.Size(); j++) {
			if(Validation::IsEqual(agregados[j]->dni, dni)) {
				idx = (int)j;
				break;
			}
		}

		if(idx == -1) {
			TopClienteData nuevo;
			nuevo.dni = dni;
			nuevo.total = monto;
			nuevo.compras = 1;
			nuevo.found = true;
			agregados.Append(nuevo);
			idx = (int)(agregados.Size() - 1);
		} else {
			agregados[(unsigned int)idx]->total += monto;
			agregados[(unsigned int)idx]->compras += 1;
		}

		TopClienteData current = *agregados[(unsigned int)idx];
		if (!top.found || current.total > top.total) {
			top = current;
		}

		delete f;
	}

	return top;
}

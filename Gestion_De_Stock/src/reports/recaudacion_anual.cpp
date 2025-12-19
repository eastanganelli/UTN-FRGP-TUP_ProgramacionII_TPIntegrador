#include "recaudacion_anual.h"

RecaudacionAnualReport::RecaudacionAnualReport() : Report("Recaudacion total anual") {}

void RecaudacionAnualReport::Run() {
	rlutil::cls();
	rlutil::setBackgroundColor(rlutil::BLUE);
	rlutil::setColor(rlutil::WHITE);
	PrintDecoratedTitle(this->GetTitle(), '=');
	rlutil::resetColor();

	unsigned int anio = AskYearOrCurrent();
	double total = CalcularRecaudacion(anio);

	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::setColor(rlutil::WHITE);
	
	rlutil::cls();
	PrintDecoratedTitle(this->GetTitle(), '=');
	cout << "ANIO FISCAL   : " << anio << endl
		<< "TOTAL         : " << total << endl
		<< "==============================" << endl;
}

double RecaudacionAnualReport::CalcularRecaudacion(unsigned int anio) {
	double total = 0.0;
	const unsigned int cantidad = facturas.Count();
	for(unsigned int i = 0; i < cantidad; i++) {
		Factura* f = facturas.At(i);
		if(f == nullptr) { continue; }
		
		const string cae = f->getCAE();
		if(cae.empty()) {
			delete f;
			continue;
		}

		if(f->getFechaEmision().getAnio() == (int)anio) {
			total += f->TotalSinIVA();
		}
		delete f;
	}
	return total;
}

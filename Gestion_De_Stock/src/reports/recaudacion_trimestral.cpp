#include "recaudacion_trimestral.h"

RecaudacionTrimestralReport::RecaudacionTrimestralReport() : Report("Recaudacion trimestral") {}

void RecaudacionTrimestralReport::Run() {
	rlutil::cls();
	rlutil::setBackgroundColor(rlutil::BLUE);
	rlutil::setColor(rlutil::WHITE);
	PrintDecoratedTitle(this->GetTitle(), '=');
	rlutil::resetColor();

	unsigned int anio = AskYearOrCurrent();
	double q1 = CalcularRecaudacion(anio, 1);
	double q2 = CalcularRecaudacion(anio, 2);
	double q3 = CalcularRecaudacion(anio, 3);
	double q4 = CalcularRecaudacion(anio, 4);
	double total = q1 + q2 + q3 + q4;

	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::setColor(rlutil::WHITE);
	rlutil::cls();
	PrintDecoratedTitle(this->GetTitle(), '=');
	cout << "ANIO : " << anio << endl
		<< "------------------------------------------" << endl
		<< "1er Trimestre (Ene-Mar) : " << q1 << endl
		<< "2do Trimestre (Abr-Jun) : " << q2 << endl
		<< "3er Trimestre (Jul-Sep) : " << q3 << endl
		<< "4to Trimestre (Oct-Dic) : " << q4 << endl
		<< "------------------------------------------" << endl
		<< "Total (facturas con CAE)    : " << total << endl
		<< "==========================================" << endl;
}

double RecaudacionTrimestralReport::CalcularRecaudacion(unsigned int anio, unsigned int trimestre) {
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
		
		const int anioFac = f->getFechaEmision().getAnio();
		const int mesFac = f->getFechaEmision().getMes();
		const unsigned int trimestreFac = (mesFac - 1) / 3 + 1;
		if((unsigned int)anioFac == anio && trimestreFac == trimestre) {
			total += f->TotalSinIVA();
		}
		delete f;
	}
	return total;
}

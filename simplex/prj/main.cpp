
/*!
* \file
* \brief Plik zawiera glowna funkcje programu.
*/
#include <iostream>
#include "simplex.h"

using namespace std;

int main() {
	int lFabryk, lProduktow;
	vector<double> czasyPracy;
	vector<vector<double> > czasyProdukcji;
	vector<double> zyskProduktow;

	cout << "Podaj liczbe fabryk: ";
	cin >> lFabryk;

	cout << "Podaj liczbe produktow: ";
	cin >> lProduktow;

	for (int i = 0; i < lProduktow; i++) {
		double zyskProduktu;

		cout << "Podaj zysk z produktu " << i+1 << ": ";
		cin >> zyskProduktu;
		zyskProduktow.push_back(zyskProduktu);
	}

	for (int i = 0; i < lFabryk; i++) {
		double czasPracy;
		vector<double> fabCzasyProdukcji;

		cout << "Fabryka numer " << i+1 << ":\n";
		cout << "Podaj maksymalny czas pracy: ";
		cin >> czasPracy;
		czasyPracy.push_back(czasPracy);
		
		for (int j = 0; j < lProduktow; j++) {
			double czasProdukcji;

			cout << "Podaj czas wyprodukowania produktu " << j+1 << ": ";
			cin >> czasProdukcji;
			fabCzasyProdukcji.push_back(czasProdukcji);
		}
		czasyProdukcji.push_back(fabCzasyProdukcji);
	}

	cout << "\n\n";

	Simplex *smplx = new Simplex(lFabryk, lProduktow, zyskProduktow, czasyPracy, czasyProdukcji);
	
	smplx->Oblicz();

	cout << "Maksymalny mozliwy zysk: " << smplx->MaxZysk() << "\n";
	for (int i = 0; i < lProduktow; i++)
		cout << "Nalezy wyprodukowac " << smplx->Wynik(i) << " produktow numer " << i+1 << ".\n";

	delete smplx;

	return 0;
}

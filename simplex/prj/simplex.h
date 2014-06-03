/*!
*\file
*\brief Plik naglowkowy klasy Simplex.
*/
#ifndef SIMPLEX
	#define SIMPLEX

	#include <vector>
	#include <algorithm>
	using namespace std;

	const double INF = 1000000000;

/*!
*\brief Deklaracja klasy Simplex.
*/
	class Simplex {
		private:
			int lFabryk, lProduktow;
			vector<double> zyskProduktow;
			vector<double> czasyPracy;
			vector<vector<double> > czasyProdukcji;

			double maxZysk;
			vector<double> wynik;
		
		public:
			Simplex(int, int, vector<double>, vector<double>, vector<vector<double> >);
			void Oblicz();
			double MaxZysk();
			double Wynik(int);
	};

#endif

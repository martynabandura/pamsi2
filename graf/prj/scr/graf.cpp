/*!
*\file 
*\brief Definicje poszczegolnych funkcji dla klasy Graf.
*/

#include<list>
#include "graf.h"
//~ class Graf {
		//~ double dane [1000][1000];
	//~ public:
		//~ Graf();
		//~ ~Graf();
		//~ 
		//~ bool dod_wierz (int v);
		//~ bool dod_kraw (int v1, int v2, double c);
		//~ bool usun_kraw (int v1, int v2);
		//~ bool usun_wierz (int v);
		//~ bool czy_sasiad (int v1, int v2);
		//~ std::list<int> sasiedztwo (int v);
//~ };

Graf::Graf(int rozm) : rozm(rozm) { }

Graf::~Graf() {}
bool Graf::dod_wierz (int v) {
	return true;
	}
bool Graf::dod_kraw (int v1, int v2, double c) {
	dane[v1][v2] = c;
	dane[v2][v1] = c; //bo nieskierowany
	return true;
	}
bool Graf::usun_kraw (int v1, int v2) {
	dane[v1][v2] = 0;
	dane[v2][v1] = 0; //bo nieskierowany
	return true;
	}
bool Graf::usun_wierz (int v) {
	return true;
	}
double Graf::czy_sasiad (int v1, int v2) {
	return dane[v1][v2];
	}
std::list<int> Graf::sasiedztwo (int v) {
	std::list<int> ret;
	for(int i = 0; i<rozm; i++)
		if(czy_sasiad(v, i)) ret.push_back(i);
	return ret;
	}

const int Graf::rozmiar() const {
	return rozm;
}

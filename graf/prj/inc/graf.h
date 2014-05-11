#ifndef GRAF_H
#define GRAF_H
#include<list>

class Graf {
		double dane [1000][1000];
		int rozm;
	public:
		Graf(int rozm);
		~Graf();
		
		bool dod_wierz (int v);
		bool dod_kraw (int v1, int v2, double c);
		bool usun_kraw (int v1, int v2);
		bool usun_wierz (int v);
		double czy_sasiad (int v1, int v2);
		std::list<int> sasiedztwo (int v);
		const int rozmiar() const;
};
#endif

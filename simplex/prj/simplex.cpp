/*!
*\file
*\brief Definicje poszczegolnych funkcji dla klasy Simplex.
*/
#include "simplex.h"

// konstruktor - nie robi nic poza zapamiętaniem danych, dla których będziemy wykonywać obliczenia
Simplex::Simplex(
	int lFabryk,
	int lProduktow,
	vector<double> zyskProduktow,
	vector<double> czasyPracy,
	vector<vector<double> > czasyProdukcji
):
	lFabryk(lFabryk),
	lProduktow(lProduktow),
	zyskProduktow(zyskProduktow),
	czasyPracy(czasyPracy),
	czasyProdukcji(czasyProdukcji) 
	{}

void Simplex::Oblicz() {
	maxZysk = 0.0;  // początkowy zysk to 0, bo startujemy od zerowej produkcji
	wynik.resize(lProduktow);
	fill(wynik.begin(), wynik.end(), 0.0);  // tutaj zaznaczamy zerową produkcję

	// tworzymy zmienne prawdziwe (te które mówią o produkcji) i zmienne urojone (dla układów)
	vector<double> wartosciZmiennych;
	wartosciZmiennych.resize(lProduktow + lFabryk);
	for (int i = 0; i < lProduktow; i++)
		wartosciZmiennych[i] = 0.0;  // na razie produkujemy 0 sztuk każdego produktu
	for (int i = lProduktow; i < lProduktow+lFabryk; i++)
		wartosciZmiennych[i] = czasyPracy[i-lProduktow];  // wartość każdej zmiennej jest taka jak prawa strona nierówności 

	// tworzymy współczynniki dla układu (teraz już równań)
	// dla zmiennych prawdziwych najpierw tworzymy same zerowe współczynniki (bo realnie nie istnieje
	// równanie z nimi związane [ale może się pojawić za chwilę w kolejnej iteracji])
	vector<vector<double> > wspolczynniki;
	for (int i = 0; i < lProduktow; i++) {
		vector<double> wekWspolczynnikow;
		for (int j = 0; j < lProduktow+lFabryk; j++)
			wekWspolczynnikow.push_back(0.0);
		wspolczynniki.push_back(wekWspolczynnikow);
	}
	// a dla prawdziwych równań tworzymy tablicę prawdziwych współczynników zgodnie z danymi
	for (int i = lProduktow; i < lProduktow+lFabryk; i++) {
		wspolczynniki.push_back(czasyProdukcji[i-lProduktow]);
		// dopełniamy ją zerami (zmienne urojone nie występują w równaniach)
		for (int j = lProduktow; j < lProduktow+lFabryk; j++) 
			wspolczynniki[i].push_back(0.0);
	}

	// tworzymy też wektor współczynników celu - pierwsze współczynniki są takie jak w danej
	// funkcji celu
	vector<double> wspolczynnikiCelu = zyskProduktow;
	// ale dopełniamy zerami (bo zmienne urojone nie mają wpływu [na razie] na wartość funkcji celu)
	for (int i = lProduktow; i < lProduktow+lFabryk; i++)
		wspolczynnikiCelu.push_back(0.0);

	// zapisujemy które zmienne są prawdziwe (bazowe), a które urojone (niebazowe)
	vector<bool> zmiennaBazowa;
	zmiennaBazowa.resize(lProduktow + lFabryk);
	for (int i = 0; i < lProduktow; i++)  // pierwsze zmienne są prawdziwe
		zmiennaBazowa[i] = true;
	for (int i = lProduktow; i < lProduktow+lFabryk; i++)  // później są urojone
		zmiennaBazowa[i] = false;

	while (true) {  // od tego miejsca zaczyna się algorytm
		int zmiennaWchodzaca = -1, zmiennaWychodzaca = -1;
		double minStosunek = INF;

		// poszukujemy zmiennej wchodzącej (to znaczy zmiennej, którą chcemy zwiększyć, żeby powiększyło
		// to wynik) - musi być to zmienna, która ma dodatni współczynnik celu (to znaczy, że jej zwiększenie
		// rzeczywiście zwiększy wynik) oraz musi być to zmienna bazowa (być w funkcji celu)
		for (int i = 0; i < wspolczynnikiCelu.size(); i++)
			if ((zmiennaBazowa[i]) && (wspolczynnikiCelu[i] > 0.0)) {
				zmiennaWchodzaca = i;
				break;
			}

		if (zmiennaWchodzaca == -1)  // jeśli nie znaleźliśmy żadnej zmiennej do powiększenia to przerywamy
			break;

		// teraz poszukujemy zmiennej wychodzącej (to znaczy takiej która reprezentuje równanie, które właśnie
		// się wyzerowało, bo zwiększyliśmy wartość zmiennej wchodzącej)
		// Przy okazji poszukujemy o ile możemy zwiększyć wartość zmiennej wchodzącej.
		for (int i = 0; i < wspolczynniki.size(); i++)
			if ((!zmiennaBazowa[i]) && (wspolczynniki[i][zmiennaWchodzaca] > 0.0)) {
				if (wartosciZmiennych[i] / wspolczynniki[i][zmiennaWchodzaca] < minStosunek) {
				  // o tyle możemy zwiększyć zmienną wchodzącą
					minStosunek = wartosciZmiennych[i] / wspolczynniki[i][zmiennaWchodzaca];
					// a równanie które zapełniliśmy ma numer i (i zmienna numer i reprezentuje to równanie
					// jako zmienna urojona)
					zmiennaWychodzaca = i;
				}
			}

		// skoro zwiększamy zmienną wchodzącą o minStosunek to wynik rośnie o współczynnik który stoi
		// przy tej zmiennej w funkcji celu razy wartość powiększenia
		maxZysk += minStosunek * wspolczynnikiCelu[zmiennaWchodzaca];

		// teraz zmieniamy równanie związane ze zmienną wchodzącą
		// Dokładniej bierzemy równanie zmiennej wychodzącej i rozwiązujemy je ze względu na
		// zmienną wchodzącą i podstawiamy to do zmiennej wchodzącej (która teraz stanie się urojona)
		wartosciZmiennych[zmiennaWchodzaca] = minStosunek;
		for (int i = 0; i < wspolczynniki[zmiennaWchodzaca].size(); i++)
			wspolczynniki[zmiennaWchodzaca][i] = wspolczynniki[zmiennaWychodzaca][i] / wspolczynniki[zmiennaWychodzaca][zmiennaWchodzaca];
		wspolczynniki[zmiennaWchodzaca][zmiennaWchodzaca] = 0.0;
		wspolczynniki[zmiennaWchodzaca][zmiennaWychodzaca] = 1.0 / wspolczynniki[zmiennaWychodzaca][zmiennaWchodzaca];

		// zerujemy współczynniki dla równania reprezentującego zmienną wychodzącą
		// staje się ona teraz zmienną prawdziwą (a nie urojoną), dlatego nie reprezentuje ona już równania
		wartosciZmiennych[zmiennaWychodzaca] = 0.0;
		for (int i = 0; i < wspolczynniki[zmiennaWychodzaca].size(); i++)
			wspolczynniki[zmiennaWychodzaca][i] = 0.0;

		// teraz zaznaczamy tę zmianę urojenia zmiennych
		zmiennaBazowa[zmiennaWchodzaca] = false;
		zmiennaBazowa[zmiennaWychodzaca] = true;

		// podstawiamy teraz równanie reprezentujące nową zmienną urojoną (wcześniej zmienną wchodzącą)
		// do wszystkich równań, które mamy
		for (int i = 0; i < wspolczynniki.size(); i++)
			if ((!zmiennaBazowa[i]) && (i != zmiennaWchodzaca)) {
				double multiplikator = wspolczynniki[i][zmiennaWchodzaca];

				for (int j = 0; j < wspolczynniki[i].size(); j++)
					wspolczynniki[i][j] -= wspolczynniki[zmiennaWchodzaca][j] * multiplikator;
				wspolczynniki[i][zmiennaWchodzaca] = 0.0;
				wartosciZmiennych[i] -= wartosciZmiennych[zmiennaWchodzaca] * multiplikator;
			}

		// podstawiamy też to samo równanie do funkcji celu
		double multiplikatorCelu = wspolczynnikiCelu[zmiennaWchodzaca];
		for (int i = 0; i < wspolczynnikiCelu.size(); i++)
			wspolczynnikiCelu[i] -= wspolczynniki[zmiennaWchodzaca][i] * multiplikatorCelu;
		wspolczynnikiCelu[zmiennaWchodzaca] = 0.0;
	}

	// gdy już tu jesteśmy, wynik jest znany
	// zmienne bazowe reprezentują wynik
	// a zmienne urojone to zera do wyniku

	for (int i = 0; i < lProduktow; i++) {
		if (!zmiennaBazowa[i])
			wynik[i] = wartosciZmiennych[i];
		else
			wynik[i] = 0.0;
	}
}

double Simplex::MaxZysk() {
	return maxZysk;
}

double Simplex::Wynik(int produkt) {
	return wynik[produkt];
}

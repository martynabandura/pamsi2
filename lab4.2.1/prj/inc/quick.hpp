/*!
* \file
* \brief Plik zawiera definicje szablonu sortowania szybkiego.
*/
#ifndef _QUICK_HPP
#define _QUICK_HPP

using namespace std;

/*! 
* \brief Modeluje pojecie Quick.
* Szablon funkcji sortowania szybkiego
*/

class Quick
{
public:

template <typename T>	void quick_sort(T *Poczatek, T *Koniec);
template <typename T>	void wypelnij(T **tab, int rozmiar, int procent_posortowanych);
template <typename T>	void wypelnij_odwrotnie(T **tab, int rozmiar);
template <typename T>	bool sprawdz_porzadek(T **tab, int rozmiar);
template <typename T>	void wyswietl(T *Poczatek, T *Koniec);
template <typename T>	void wyswietl(T **tab, int rozmiar);	
};

template <typename T>
void Quick::quick_sort(T *Poczatek, T *Koniec) {
	T* Lewy = Poczatek;
	T* Prawy = Koniec;
	size_t Rozmiar = Koniec - Poczatek; //lepszy pivot
	size_t n = rand() % Rozmiar;		//lepszy pivot
	T Pivot = *(Lewy + n);				//lepszy pivot
	//! TODO analiza dla T Pivot = *Lewy;
	bool SunPrawy = true;

	while(Lewy != Prawy) {
		if(SunPrawy == true) {
			if(Pivot > *Prawy) {
				*Lewy = *Prawy;
				SunPrawy = false;
			}
			else
				Prawy--;
		}
		else {
			if(Pivot < *Lewy) {
				*Prawy = *Lewy;
				SunPrawy = true;
			}
			else
				Lewy++;
		}
	}
	*Prawy = Pivot;

	if(Poczatek < Prawy -1)
		quick_sort(Poczatek, Prawy-1);
	if(Prawy+1 < Koniec)
		quick_sort(Prawy+1, Koniec);
}

template <typename T>
void Quick::wypelnij(T **tab, int rozmiar, int procent_posortowanych){
	int ilosc_posortowanych = rozmiar*procent_posortowanych/100;

	int zakres = 10*rozmiar+1;
	srand( time( NULL ) );

	for(int i=0; i<100; i++) {
		for(int j=0; j<ilosc_posortowanych; j++)
		tab[i][j] = j;

		for(int j=ilosc_posortowanych; j<rozmiar; j++)
		tab[i][j] = rand()%(zakres-ilosc_posortowanych) + ilosc_posortowanych;
	}

}

template <typename T>
void Quick::wypelnij_odwrotnie(T **tab, int rozmiar){

	for(int i=0; i<100; i++)
		for(int j=rozmiar-1; j>=0; j--)
			tab[i][j] = rozmiar-j-1;
}

template <typename T>
bool Quick::sprawdz_porzadek(T **tab, int rozmiar){
	for(int i=0; i<100; i++)
		for(int j=0; j<rozmiar-1; j++)
			if(tab[i][j]>tab[i][j+1])
				return 0;
	return 1;
}

template <typename T>
void Quick::wyswietl(T *Poczatek, T *Koniec) {
	for(int i=0; i<= Koniec - Poczatek; i++)
		cout << *(Poczatek+i) << " ";
}

template <typename T>
void Quick::wyswietl(T **tab, int rozmiar) {

	for(int i=0; i<= 100; i++){
		for(int j=0; j<rozmiar; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}

#endif


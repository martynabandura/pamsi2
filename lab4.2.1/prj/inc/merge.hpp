/*
* merge.hh
* \brief Plik zawiera definicje funkcji sortowania przez scalanie dla klasy Array.
*/

#ifndef _MERGE_HPP
#define _MERGE_HPP
using namespace std;


class Merge
{
public:

template <typename T>
void merge(T *tablica1, int pierwszy, int ostatni);

template <typename T>
void merge_sort(T *dane, int pierwszy, int ostatni);

template <typename T>
void wypelnij(T **tab, int rozmiar, int procent_posortowanych);

template <typename T>
void wypelnij_odwrotnie(T **tab, int rozmiar);

template <typename T>
bool sprawdz_porzadek(T **tab, int rozmiar);

template <typename T>
void wyswietl(T *Poczatek, T *Koniec);

template <typename T>
void wyswietl(T **tab, int rozmiar); 

};


template <typename T>
void Merge::merge(T *tablica1, int pierwszy, int ostatni) {
    int srodek = (pierwszy+ostatni)/2;
    int i1 = 0;
    int i2 = pierwszy;
    int i3 = srodek+1;

    int pomocnicza[ostatni-pierwszy];

    while(i2 <= srodek && i3 <= ostatni) {
        if(tablica1[i2] < tablica1[i3])
            pomocnicza[i1++] = tablica1[i2++];
        else
            pomocnicza[i1++] = tablica1[i3++];
    }


    while(i2 <= srodek)
        pomocnicza[i1++] = tablica1[i2++];

    while(i3 <= ostatni)
        pomocnicza[i1++] = tablica1[i3++];


    for(int i=pierwszy; i<=ostatni; i++)
        tablica1[i] = pomocnicza[i-pierwszy];
}


template <typename T>
void Merge::merge_sort(T *dane, int pierwszy, int ostatni) {
    if(pierwszy < ostatni)
    {
        int srodek = (pierwszy+ostatni)/2;
        merge_sort(dane, pierwszy, srodek);
        merge_sort(dane, srodek+1, ostatni);
        merge (dane, pierwszy, ostatni);
    }
}

template <typename T>
void Merge::wypelnij(T **tab, int rozmiar, int procent_posortowanych){
	int ilosc_posortowanych = rozmiar*procent_posortowanych/100;

	int zakres = 10*rozmiar+1;
	srand( time( NULL ) );

	for(int i=0; i<1; i++) {
		for(int j=0; j<ilosc_posortowanych; j++)
		tab[i][j] = j;
	}

	for(int i=0; i<1; i++) {
		for(int j=ilosc_posortowanych; j<rozmiar; j++)
		tab[i][j] = rand()%(zakres-ilosc_posortowanych) + ilosc_posortowanych;
	}

}

template <typename T>
void Merge::wypelnij_odwrotnie(T **tab, int rozmiar){

	for(int i=0; i<100; i++)
		for(int j=rozmiar-1; j>=0; j--)
			tab[i][j] = rozmiar-j-1;
}

template <typename T>
bool Merge::sprawdz_porzadek(T **tab, int rozmiar){
	for(int i=0; i<100; i++) {
		for(int j=1; j<rozmiar; j++) {
			if(tab[i][j]<tab[i][j-1])	{
				return 0;
			}
		}
	}

	return 1;
}

template <typename T>
void Merge::wyswietl(T *Poczatek, T *Koniec) {
	for(int i=0; i<= Koniec - Poczatek; i++)
		cout << *(Poczatek+i) << " ";
}

template <typename T>
void Merge::wyswietl(T **tab, int rozmiar) 
{

	for(int i=0; i< 1; i++)
	{
		for(int j=0; j<rozmiar; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}

#endif


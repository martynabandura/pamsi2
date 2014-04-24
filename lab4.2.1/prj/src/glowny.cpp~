/*! \mainpage Dokumentacja zadania PAMSI LAB 4
 *   
 *  \author Martyna Bandura
 *  \date 19.03.2014
 *  
 */


/** \file main.cpp
* \brief Plik zawiera glowna funkcje programu.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "../inc/quick.hpp"
#include "../inc/tablica.hpp"
#include "../inc/dzialania.hpp"
#include "../inc/merge.hpp"

#define ROZMIAR 20
using namespace std;

/** \brief Glowna funkcja programu
*
* Wyświetla wynik pomiarowy tablicy.
*/



int main(int argc , char ** argv) {

	Quick Q;
	int **tablica;
	tablica = NULL;
	ofstream plik;

	plik.open("szybkie.txt");
	plik << "sortowanie szybkie: " << endl;

	int rozmiar[] = {10000, 50000, 100000, 500000, 1000000};

	for(int j=0; j<5; j++){
		plik << "rozmiar tablicy" << rozmiar[j] << endl;
		//alokuj_tablica(tablica);
		int l_wierszy = 100;
		int l_kolumn = rozmiar[j];

		tablica = new int*[l_wierszy];
		for (int x = 0; x < l_wierszy; x++)
			tablica[x] = new int[l_kolumn];

		int posortowane[] = {0, 25, 50, 75, 95, 99};

		for(int i=0; i<6; i++){
			plik << "posortowane" << posortowane[i] << "% elementow ";
			Q.wypelnij_odwrotnie(tablica, rozmiar[j]);
			cout << Q.sprawdz_porzadek(tablica, rozmiar[j]) << " ";
			//wyswietl(tablica, rozmiar[j]);
			clock_t start, stop;
			start=clock();
			for(int i=0; i<100; i++) {
				Q.quick_sort(tablica[i], tablica[i]+(l_kolumn-1));
			}
			stop=clock();
			float czas = stop - start;
			plik << "czas: " << czas << endl;
			cout << Q.sprawdz_porzadek(tablica, rozmiar[j]) << " ";
		}

		cout << endl;
	}
	plik.close();
	usun_tablica(tablica);
	

	return 0;
}

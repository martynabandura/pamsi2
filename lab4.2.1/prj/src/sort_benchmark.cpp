#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "../inc/quick.hpp"
#include "../inc/merge.hpp"

using namespace std;

/** 
*\file
*\brief Benchmark
* Zawiera najważniejsze fukcje programu jak rozmiar tablicy. 
* Benchmark sortowanie quick i merge
*/

int rozmiar[] = {10000, 50000, 100000, 500000, 1000000};
	//~ int rozmiar[] = {100, 500, 1000, 5000, 10000};

void qsort_benchmark(ofstream& plik) {

	Quick Q;

	plik << "sortowanie szybkie: " << endl;

	for(int j=0; j<5; j++) {
		plik << "rozmiar tablicy" << rozmiar[j] << endl;
		int l_wierszy = 100;
		int l_kolumn = rozmiar[j];

		int **tablica = new int*[l_wierszy];
		for (int x = 0; x < l_wierszy; x++)
			tablica[x] = new int[l_kolumn];

		int posortowane[] = {0, 25, 50, 75, 95, 99};

		for(int i=0; i<6; i++){
			plik << "posortowane" << posortowane[i] << "% elementow ";
			Q.wypelnij(tablica, rozmiar[j], posortowane[i]);
			cout << Q.sprawdz_porzadek(tablica, rozmiar[j]) << " ";
			clock_t start, stop;
			start=clock();
			for(int i=0; i<100; i++) {
				Q.quick_sort(tablica[i], tablica[i]+(l_kolumn-1));
			}
			stop=clock();
			double czas = (double)(stop - start)/CLOCKS_PER_SEC;
			plik << "czas: " << czas << "s\n";
			cout << Q.sprawdz_porzadek(tablica, rozmiar[j]) << " ";
		}
		
		plik << "posortowane odwrotnie ";
		Q.wypelnij_odwrotnie(tablica, rozmiar[j]);
		cout << Q.sprawdz_porzadek(tablica, rozmiar[j]) << " ";
		clock_t start, stop;
		start=clock();
		for(int i=0; i<100; i++) {
			Q.quick_sort(tablica[i], tablica[i]+(l_kolumn-1));
		}
		stop=clock();
		double czas = (double)(stop - start)/CLOCKS_PER_SEC;
		plik << "czas: " << czas << "s\n";
		cout << Q.sprawdz_porzadek(tablica, rozmiar[j]) << " ";

		cout << endl;
		for (int x = 0; x < l_wierszy; x++)
			delete [] tablica[x];
		delete [] tablica;
	}
}

void msort_benchmark(ofstream& plik) {

	Merge M;

	plik << "sortowanie merge: " << endl;

	for(int j=0; j<5; j++){
		plik << "rozmiar tablicy" << rozmiar[j] << endl;
		int l_wierszy = 100;
		int l_kolumn = rozmiar[j];

		int **tablica = new int*[l_wierszy];
		for (int x = 0; x < l_wierszy; x++)
			tablica[x] = new int[l_kolumn];

		int posortowane[] = {0, 25, 50, 75, 95, 99};

		for(int i=0; i<6; i++){
			plik << "posortowane" << posortowane[i] << "% elementow ";
			M.wypelnij(tablica, rozmiar[j], posortowane[i]);
			cout << M.sprawdz_porzadek(tablica, rozmiar[j]) << " ";
			clock_t start, stop;
			start=clock();
			for(int i=0; i<100; i++) {
				M.merge_sort(tablica[i], 0, (l_kolumn-1));
			}
			stop=clock();
			double czas = (double)(stop - start)/CLOCKS_PER_SEC;
			plik << "czas: " << czas << "s\n";
			cout << M.sprawdz_porzadek(tablica, rozmiar[j]) << " ";
		}
		plik << "posortowane odwrotnie ";
		M.wypelnij_odwrotnie(tablica, rozmiar[j]);
		cout << M.sprawdz_porzadek(tablica, rozmiar[j]) << " ";
		clock_t start, stop;
		start=clock();
		for(int i=0; i<100; i++) {
			M.merge_sort(tablica[i], 0, (l_kolumn-1));
		}
		stop=clock();
		double czas = (double)(stop - start)/CLOCKS_PER_SEC;
		plik << "czas: " << czas << "s\n";
		cout << M.sprawdz_porzadek(tablica, rozmiar[j]) << "\n";

		for (int x = 0; x < l_wierszy; x++)
			delete [] tablica[x];
		delete [] tablica;
	}
}


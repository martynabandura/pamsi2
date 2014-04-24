/*! \mainpage Dokumentacja zadania PAMSI LAB 4
 *   
 *  \author Martyna Bandura
 *  \date 19.03.2014
 *  
 */


/** \file main.cpp
* \brief Plik zawiera glowna funkcje programu.
*/

#include <fstream>
#include "../inc/sort_benchmark.hpp"

#define ROZMIAR 20

using namespace std;

/** \brief Glowna funkcja programu
*
* Wyświetla wynik pomiarowy tablicy.
*/

int main(int argc , char ** argv) {

	ofstream plik;
	plik.open("szybkie.txt");
	qsort_benchmark(plik);
	plik.close();
	
	plik.open("merge.txt");
	msort_benchmark(plik);
	plik.close();
	return 0;
}

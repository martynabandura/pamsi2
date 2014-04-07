#include <iostream>
#include <fstream>
#include "../inc/dzialania.hpp"
#include <ctime>

using namespace std;

/*!
*  Najwazniejsze pola funkcji
   

*/

void Dzialania::oblicz()
{
    for (unsigned int i=0; i<tab1.rozmiar() ;i++){
	 tab2[i]=tab1[i]*2;
	}
}
/*!
*  nazwapl zmienna zawierajaca nazwe pliku

*/

bool Dzialania::wczytajplik(char *nazwapl)
{
	ifstream plik;
	plik.open(nazwapl);

	if( !plik.good() ){
		cout << "Plik nie zostal otworzony ";
	    return false;
	}

	unsigned int rozmiar;
	plik >> rozmiar;
	tab1.zmianarozmiaru(rozmiar);
	tab2.zmianarozmiaru(rozmiar);

	for (unsigned int i=0; i<rozmiar; i++) {
		plik >> tab1[i];
	}
	return true;
}

bool Dzialania::porownaj(char* nazwapl)
	{
		ifstream pliks;
		pliks.open(nazwapl);

		if( !pliks.good() ) {

		cout << "Nie został otwarty plik sprawdzajacy ";
		        return false;
		}

		 unsigned int rozmiarek;
		 pliks>>rozmiarek;

		 if(rozmiarek!=tab2.rozmiar()){
		 	cout << "Rozmiary plików sie roznia ";
		 return false; }

		 	for(unsigned int i=0; i<tab2.rozmiar();i++){
		 		int d;
		 	pliks>>d;
		 	if(d!=tab2[i]){
		 		cout <<"Rorownywane wartosci sa  !";
		 		return false; }
	}
		 	return true;}
/*!
*   
*    liczczas - zmienna zawiera ile powtorzen ma wykonac program
*/
	
	

	double Dzialania::liczczas(int iloscpowtorzen)
	{
	    clock_t tmp = clock();
	    for(int i=0;i<iloscpowtorzen;i++){
		    oblicz();
	    }

	    tmp=clock()-tmp;
	 	return ((double)tmp)/CLOCKS_PER_SEC;

	}

void foo()
{
cout<<"dd"<<endl;
}

#ifndef TABLICA_HPP
#define TABLICA_HPP


#include <iostream>
#include <cstdlib>



/*!
\brief Klasa reprezentująca tablicę
*/

template <typename Typ> class Tablica
{
	Typ *T;
	unsigned int dltab;
	

public :
/*!
\brief Zamienia 2 elementy tablicy
*/

	void zmele(int i , int j);
/*!
\brief Dodaje element do tablicy
*/
	void dodele(Typ element);
/*! Odwraca tablice
*/

	void zmienkolejnosc() ;
/*!Laczy 2 tablice.
*/
	void dodele(const Tablica<Typ> &T1);
/*! Konstruktor klasy Tablica.
*/
	Tablica(): T(0) , dltab(0) {} ;
/*! Destruktor klasy Tablica.
*/
	~Tablica () { free(T); };


	unsigned int rozmiar() const {return dltab;} 

	void zmianarozmiaru (unsigned int nowyrozmiar);

/*! Przeciazenie operatora indeksujacego
*/
	Typ& operator[](const unsigned int b) { return T[b]; }
/* Przeciazenie operatora indeksujacego 
*/
	const Typ& operator[](const unsigned int b) const {return T[b]; }

/*! Przeciazenie operatora przypisywania.
*/
	Tablica<Typ>& operator = (const Tablica<Typ> &argument);
/*! Przeciazenie operatora porownania.
*/
	bool operator == (const Tablica<Typ> &argument) const;
	

};

template<typename Typ>
void Tablica<Typ>::zmele(int i, int j) {
	Typ p1; Typ p2;
		p1=T[i];
		p2=T[j];
		T[i]=p2;
		T[j]=p1;
}

template<typename Typ>
void Tablica<Typ>::dodele(Typ element) {
	 zmianarozmiaru(rozmiar()+1);
	 T[dltab-1]=element;
}

template<typename Typ>
void Tablica<Typ>::zmienkolejnosc() {
	for ( unsigned int i=0 ;i<dltab/2 ;i++){
        zmele(i,dltab -1-i);
		  }
	}
template<typename Typ>
void Tablica<Typ>::dodele(const Tablica<Typ>& T1) {

	unsigned int tmp=rozmiar();
	zmianarozmiaru(rozmiar()+T1.rozmiar());
	for(unsigned int i=0;i<T1.rozmiar();i++){
		T[tmp+1]=T[i];
	}
}

template<typename Typ>
void Tablica<Typ>::zmianarozmiaru(unsigned int nowyrozmiar) {
	T=(Typ*)realloc(T,nowyrozmiar * sizeof(Typ));
			dltab=nowyrozmiar;

}

template<typename Typ>
Tablica<Typ>& Tablica<Typ>::operator =(const Tablica<Typ>& argument) {
	zmianarozmiaru(argument.rozmiar());
		for (unsigned int i=0;i<rozmiar(); i++ ){
			T[i]=argument[i];
		}
	 return *this;
}

template<typename Typ>
bool Tablica<Typ>::operator ==(const Tablica<Typ>& argument) const {
	if(rozmiar()!=argument.rozmiar()) return false;

		for (unsigned int i=0;i<rozmiar() ; i++){
			if(T[i]!=argument[i]) return false;
		}
		return true;
}



void foo22();

#endif 
#pragma once
#include "Para.h"
#include <string.h>
/*!
 * \file
 * \brief Definicja szablonu klasy Tablica(tablicab z haszowaniem)
 *
 * Plik zawiera definicje szablonu klasy Tablica.Jest to klasa glowna , ktora 
 * wykorzystuje klase Para.
 */

/*!
* \brief Modeluje pojecie tablicy z haszowaniem.
* Klasa modeluje pojecie tablicy z haszowaniem.
* Jej atrybutami sa pola: klucz i wartosc.
*/
template <typename K, typename W>
class Tablica {
private:
/*!
 *  \brief Tablica par.
 */
	Para<K,W> **tablica;
/*!
 *  \brief Obecna liczba elementow w tablicy.
 */
	int liczbaElementow;
/*!
 *  \brief Maksymalna liczba elementow w tablicy.
 */
	int rozmiar;
/*!
 *  \brief Funkcja haszujaca dla obiektow typu string.
 */
    int haszstring(K key);
public:
/*! 
* \brief Konstruktor klasy Tablica.
* Jego argumentem jest maksymalny rozmiar tablicy.
*/
	Tablica(int rozmiar);
/*! 
* \brief Destruktor klasy Tablica.
* Czysci pamiec.
*/
	~Tablica();
/*! 
* \brief Funkcja dodaj.
* Dodaje krotke do tablicy.
*/
	 void dodaj(Para<K,W> &para);
/*! 
* \brief Funkcja usun.
* Usuwa krotke o podanym kluczu.
*/
	void usun ( K klucz);
/*! 
* \brief Funkcja pobierzWartosc
* \return Zwraca wartosc przypisana do danego klucza.
*/
	W pobierzWartosc(K klucz);
 /*!
  *  \brief Sprawdza zapelnienie tablicy.
  *   \return zwraca prawde, gdy tablica jest pusta
  *   
  */
	bool czypusta(){
		return liczbaElementow==0;
	}
/*!
 * \brief Podaje liczbe elementow w tablicy.
 *  \return zwraca liczbe elementow w tablicy.
 */
	int size(){
		return liczbaElementow;
	}
 
/*!
 * \brief Przeciazenie operatora indeksujacego.
 * \return Zwraca wartosc.
 */
	W& operator[](K klucz);
};

template<typename K , typename W>
int Tablica<K,W>::haszstring(K key){
    	unsigned int h=key[0];
    	for (unsigned int i=0; i< key.size();i++)
    		h= (h<< 4)+key[i];
    	return h % rozmiar;
}


template<typename K , typename W>
Tablica<K,W>::Tablica(int rozmiar){
	tablica = new Para<K,W>*[rozmiar];
	for(int i = 0;i<rozmiar;++i)
		tablica[i] = NULL;
	liczbaElementow = 0;
	this->rozmiar = rozmiar;
}
template<typename K , typename W>
Tablica<K,W>::~Tablica(){
	for(int i;i<rozmiar;++i){
		if(tablica[i]!=NULL){
			delete tablica[i];
		}
	}
	delete []tablica;
}
template<typename K , typename W>
void Tablica<K,W>::dodaj(Para<K,W> &para){
	int pozycja=haszstring(para.pobierzKlucz());
	if(tablica[pozycja] == NULL)
		tablica[pozycja]= new Para<K,W>(para);
	else{
		tablica[pozycja]->ustawKlucz(para.pobierzKlucz());
		tablica[pozycja]->ustawWartosc(para.pobierzWartosc());
	}
	++liczbaElementow;
}

template<typename K , typename W>
void Tablica<K,W>::usun(K klucz){
	if(tablica[haszstring(klucz)]!=NULL){
		delete tablica[haszstring(klucz)];
		tablica [haszstring(klucz)] = NULL;
		--liczbaElementow;
	}
}

template<typename K , typename W>
W Tablica<K,W>::pobierzWartosc(K klucz){
		return tablica[haszstring(klucz)]->pobierzWartosc();
}


template <typename K, typename W>
W& Tablica<K,W>::operator[]( K klucz){
	int hash = haszstring(klucz);
	if (tablica[hash]!=NULL)
		return tablica[hash]->pobierzWartosc();
	delete tablica[hash];
	tablica[hash] = new Para<K,W>();
	tablica[hash]->ustawKlucz(klucz);
	return tablica[hash]->pobierzWartosc();
}

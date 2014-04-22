#pragma once
#include "Wezel.h"
#include <string.h>
#include"Para.h"
/*!
 * \file 
 * \brief Definicja szablonu klasy Drzewo
 * Plik zawiera definicje szablonu klasy Drzewo.
*/

/*! 
* \brief Modeluje pojecie drzewa binarnego.
* Jego atrybutem jest klasa Wezel.
*/
template<typename K , typename W >
class Drzewo
{
private:
/*!
 *  \brief Poczatkowy element drzewa - korzen.
 */
	Wezel<K,W> *korzen;
/*!
 *  \brief Obecna liczba elementow w tablicy.
 */
	int liczbaElementow;
/*! 
* \brief Funkcja dodaj.
* Dodaje wezel do drzewa.
*/
	void dodaj(K klucz,W wartosc,Wezel<K,W> *&wsk);
/*! 
* \brief Funkcja usun.
* Usuwa wezel z drzewa.
*/
	 Wezel<K,W> *&usun(K klucz,Wezel<K,W> *&wezel);
public:
/*! 
* \brief Konstruktor klasy Drzewo.
* Bezargumentowy.
*/
	Drzewo();
/*! 
* \brief Destruktor klasy Drzewo.
* Czysci pamiec po obiekcie.
*/	
	~Drzewo();
/*! 
* \brief Konstruktor kopiujacy klasy Drzewo.
* Kopiuje obiekt.
*/
	Drzewo(const Drzewo& drzewo);
/*! 
* \brief Funkcja dodaj.
* Dodaje wezel do drzewa.
*/
	 void dodaj(K klucz,W wartosc);
/*! 
* \brief Funkcja pobierzWartosc.
* Zwraca wartosc przypisana do klucza.
*/
	 W pobierzWartosc(K klucz);
/*! 
* \brief Funkcja usun.
* Usuwa wezel z drzewa.
*/
	 void usun(K klucz);
/*! 
* \brief Funkcja nastepnik.
* Wyszukuje i wstawia w odpowiednie miejsce nastepnika.
*/
	 Wezel<K,W> *&nastepnik(Wezel<K,W> *&wezel,Wezel<K,W> *&us);
};

template<typename K , typename W >
Drzewo<K,W>::Drzewo(){
	korzen = NULL;
	liczbaElementow = 0;
}

template<typename K , typename W >
Drzewo<K,W>::~Drzewo(){
	if(korzen!=NULL)
		delete korzen;
}

template<typename K , typename W >
Drzewo<K,W>::Drzewo(const Drzewo<K,W>& drzewo){
	if(drzewo.korzen!=NULL)
		this->korzen = new Wezel<K,W>(*drzewo.korzen);
	else
		this->korzen = new Wezel<K,W>(Para<K,W>());
	this->liczbaElementow = drzewo.liczbaElementow;
}

template<typename K , typename W >
void Drzewo<K,W>::dodaj(K klucz,W wartosc){
	dodaj(klucz,wartosc,korzen);
	++liczbaElementow;
}

template<typename K , typename W >
void Drzewo<K,W>::dodaj(K klucz,W wartosc,Wezel<K,W> *&wsk){
	if(wsk==NULL)
		wsk = new Wezel<K,W>(Para<K,W>(klucz,wartosc));
	else if((klucz.compare(wsk->para->pobierzKlucz())<0)){
		dodaj(klucz,wartosc,wsk->lewy);
	}
	else
		dodaj(klucz,wartosc,wsk->prawy);
}

template<typename K , typename W >
W Drzewo<K,W>::pobierzWartosc(K klucz){
	Wezel<K,W> *wezel = korzen;
	int komperator = 0;
	while (wezel != NULL &&(komperator = klucz.compare(wezel->para->pobierzKlucz()))!=0)
		wezel = komperator < 0 ? wezel->lewy : wezel->prawy;
	return wezel->para->pobierzWartosc();
}

template<typename K , typename W >
void Drzewo<K,W>::usun(K klucz){
	korzen = usun(klucz,korzen);
	--liczbaElementow;
}

template<typename K , typename W >
Wezel<K,W> *&Drzewo<K,W>::usun(K klucz,Wezel<K,W> *&wezel){
	if(wezel == NULL){
		++liczbaElementow;
		return wezel;
	}
	else{
		int komperator = klucz.compare(wezel->para->pobierzKlucz());
		if(komperator<0){
			wezel->lewy = usun(klucz,wezel->lewy);
		}else if(komperator>0){
			wezel->prawy = usun(klucz,wezel->prawy);
		}else if(wezel->lewy!=NULL && wezel->prawy!=NULL){
			wezel->prawy = nastepnik(wezel->prawy,wezel);
		}else{ 
			wezel = (wezel->lewy != NULL) ? wezel->lewy : wezel->prawy;
		}
	return wezel;
	}
	
}

template<typename K , typename W >
Wezel<K,W> *&Drzewo<K,W>::nastepnik(Wezel<K,W> *&wezel,Wezel<K,W> *&us){
	if(wezel->lewy!=NULL){
		wezel->lewy = nastepnik(wezel->lewy,us);
	}else{
		us->para->ustawKlucz(wezel->para->pobierzKlucz());
		us->para->ustawWartosc(wezel->para->pobierzWartosc());
		wezel = wezel->prawy;
	}
	return wezel;
}

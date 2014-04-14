#pragma once
/*!
 * \file 
 * \brief Definicja szablonu klasy Para
 * Plik zawiera definicje szablonu klasy Para.
*/

/*! 
* \brief Modeluje poj�cie pary.
* Jej atrybutem s� pola zawieraj�ce klucz i warto��.
*/
template<typename K , typename W >
class Para
{
public:
/*! 
* \brief Konstruktor klasy Para.
* Jego argumentami s� klucz i warto��.
*/
Para(K klucz , W wartosc);
/*! 
* \brief Konstruktor klasy Para.
* Bezargumentowy.
*/
Para(void);
/*! 
* \brief Destruktor klasy Para.
* Czy�ci pami�� po obiekcie.
*/
~Para(void);
/*! 
* \brief Konstruktor kopiujacy klasy Para.
* Kopiuje obiekt.
*/
Para(const Para& para);
/*! 
* \brief Funkcja pobierzKlucz.
* Zwraca klucz.
*/
K& pobierzKlucz(void)const;
/*! 
* \brief Funkcja pobierzWartosc.
* Zwraca warto��.
*/
W& pobierzWartosc(void)const;
/*! 
* \brief Funkcja ustawKlucz.
* Ustawia klucz.
*/
void ustawKlucz(K klucz);
/*! 
* \brief Funkcja ustawWartosc.
* Ustawia wartosc.
*/
void ustawWartosc(W wartosc);
private:
	/*!
	 * \brief Definicja zmiennej klucz.
	 */ 
	K *klucz;
	/*! 
	 * \brief Definicja zmiennej warto��.
	 */
	W *wartosc;
};

template<typename K , typename W >
Para<K,W>::Para(K klucz , W wartosc){
	this->klucz = new K;
	*(this->klucz) = klucz;
	this->wartosc = new W;
	*(this->wartosc) = wartosc;
}

template<typename K , typename W >
Para<K,W>::Para(void){
	this->wartosc = new W;
	this->wartosc = NULL;
	this->klucz = new K;
	this->klucz = NULL;
}

template<typename K , typename W >
Para<K,W>::~Para(void){
	delete klucz;
	delete wartosc;
}

template<typename K , typename W >
Para<K,W>::Para(const Para<K,W>& para){
	this->klucz = new K;
	*(this->klucz) = para.pobierzKlucz();
	this->wartosc = new W;
	*(this->wartosc) = para.pobierzWartosc();
}

template<typename K , typename W >
K& Para<K,W>::pobierzKlucz(void)const{
	return *klucz;
}

template<typename K , typename W >
W& Para<K,W>::pobierzWartosc(void)const{
	return *wartosc;
}

template<typename K , typename W >
void Para<K,W>::ustawKlucz(K klucz){
	*(this->klucz) = klucz;
}

template<typename K , typename W >
void Para<K,W>::ustawWartosc(W wartosc){
	*(this->wartosc) = wartosc;
}
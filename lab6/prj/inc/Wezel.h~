#pragma once
#include"Para.h"
/*!
 * \file 
 * \brief Definicja szablonu klasy Wezel
 * Plik zawiera definicje szablonu klasy Wezel.
*/

/*! 
* \brief Modeluje pojêcie wezla.
* Jego atrybutem jest klasa Para.
*/
template<typename K , typename W >
class Wezel{
public:
	/*!
	 * \brief Definicja zmiennej para.
	 */ 
	Para<K,W> *para;
	/*!
	 * \brief Definicja zmiennej lewy.
	 */ 
	Wezel *lewy;
	/*!
	 * \brief Definicja zmiennej prawy.
	 */ 
	Wezel *prawy;
/*! 
* \brief Konstruktor klasy Wezel.
* Jego argumentem jest klasa Para.
*/
	Wezel(Para<K,W> para);
	Wezel(){this->para = new Para<K,W>;}
/*! 
* \brief Destruktor klasy Wezel.
* Czyœci pamiêæ po obiekcie.
*/	
	~Wezel();
/*! 
* \brief Konstruktor kopiujacy klasy Wezel.
* Kopiuje obiekt.
*/
	Wezel(const Wezel& wezel);

/*! 
* \brief Funkcja osieroc.
* Ustawia wskazniki na dzieci na NULL.
*/
	void osieroc();
};
template<typename K , typename W >
Wezel<K,W>::Wezel(Para<K,W> para){
	this->para = new Para<K,W>(para);
	lewy = NULL;
	prawy = NULL;
}
template<typename K , typename W >
Wezel<K,W>::~Wezel(){
	if(para!=NULL)
		delete para;
	if(lewy!=NULL)
		delete lewy;
	if(prawy!=NULL)
		delete prawy;
}

template<typename K , typename W >
Wezel<K,W>::Wezel(const Wezel<K,W>& wezel){
	this->para = new Para<K,W>(*(wezel.para));
	this->lewy = wezel.lewy;
	this->prawy = wezel.prawy;
}

template<typename K , typename W >
void Wezel<K,W>::osieroc(){
	lewy = NULL;
	prawy = NULL;
}
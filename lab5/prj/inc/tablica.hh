/*
 * TABLICA_HH_
 *
 *  Created on: 6 kwi 2014
 *      Author: Martyna
 */

#ifndef TABLICA_HH_
#define TABLICA_HH_
#define ROZMIAR 100
/*!
 * \file
 * \brief Definicja szablonu klasy Tablica(Tablica asocjacyjna)
 *
 * Plik zawiera definicję szablonu klasy Tablica.Jest to klasa główna , która
 * wykorzystuje klasę para.

*/
#include "para.hh"
#include <iostream>
#include <string>
/*!
* \brief Modeluje pojęcie Tablica.
* Klasa modeluje pojęcie Tablica asocjacyjna .
* Jej atrybutem są pola: klucz i wartość.
*/
template <typename K, typename V>
class Tablica {
public:
/*!
 *  \brief Wykorzystuje pola z klasy para.
 */
	para<K,V> Tab[ROZMIAR];

/*!
 *  \brief Dodaje parę-wartość i klucz.
 *  
 */
	 void dodaj(para<K,V> para);
/*!
 *  \brief Metoda usuwajaca klucz.
 * 
 */
	void usun ( K key);
/*!
 *  \brief Pobiera klucz.
 *  /return Zwraca zmienna o nazwie wartosc.
 */
     V pobierz (K key);
 /*!
  *  \brief Sprawdza zawartość tablicy.
  *   \return Metoda porownuje zmienna i zwraca true jeśli zmienna jest równa 0
  *   
  */
	bool czypusta(){
		return zmienna==0;
	}
/*!
 * \brief Podaje rozmiar.
 *  \return Zwraca zmienna stat.
 */
	int size(){
		return zmienna;
	}
/*!
 *  \brief Pomocnicza zmienna statyczna.
 */
	static int zmienna; 
/*!
 * \brief Przeciążenie operatora indeksującego.
 * \return Zwraca wartosc.
 */
	V& operator[](K key);
/*!
 *  \brief Funkcja haszująca dla obiektów typu string.
 */
    int haszstring(string key)const {
    	unsigned int h=key[0];
    	for (unsigned int i=0; i< key.size();i++)
    		h= (h<< 4)+key[i];
    	return h % ROZMIAR;
    }
};
template<typename K , typename V>
void Tablica<K,V>::dodaj(para<K,V> para){
	int pozycja=haszstring(para.key);
	Tab[pozycja]=para;
	zmienna ++;
	}
template<typename K , typename V>
void Tablica<K,V>::usun(K key){
	int pozycja=haszstring(key);
	Tab[pozycja].wart=NULL;
	zmienna --;

}
template<typename K , typename V>
V Tablica<K,V>::pobierz(K key){
	int pozycja=haszstring(key);
	return *Tab[pozycja].wart;
}


template <typename K, typename V>
V& Tablica<K,V>::operator[]( K key){
int hash = haszstring(key);
if (Tab[hash].key == key)
return *Tab[hash].wart;
Tab[hash].key = key;
Tab[hash].wart = new V;
*Tab[hash].wart = 0;
return *Tab[hash].wart;
}
#endif /* TABLICA_HH_ */

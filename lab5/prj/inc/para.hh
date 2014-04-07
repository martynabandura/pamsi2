/* 
 *  PARA_HH_ 
 *
 *  Created on: 6 kwi 2014
 *      Author: martyna
 */

#ifndef PARA_HH_
#define PARA_HH_


/*!
 * \file 
 * \brief Definicja szablonu klasy Para
 * Plik zawiera definicję szablonu klasy Para.
*/
#include <string>


#include <iostream>

using namespace std;

/*! 
* \brief Modeluje pojęcie para.
* Jej atrybutem są pola zawierające klucz i wartość.
*/

template<typename K , typename V >
class para {
public:
/*!
 * \brief Inicjalizuje wartosc klucz.
*/ 
	K key;
/*! 
 * \brief Inicjalizuje zmienna wartość.
*/
	V *wart;
	para (K _key , V _wart){
		key=_key;
		wart=new V;
		*wart=_wart;

}
	para(){
		wart=new V;
	}

};



#endif /* PARA_HH_ */

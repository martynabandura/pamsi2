/*! \mainpage Dokumentacja zadania Tablica asocjacyjna
 *
 *  \date : 6 kwi 2014
 *  \author: Martyna Bandura
 *  \version: 0.1
 */
#include <iostream>
#include "tablica.hh"

using namespace std;
template<typename K, typename V>

int Tablica<K,V>::zmienna=0;
/*! 
* \file
* \brief Główna funkcja programu
*/

/*!
 *\brief  W funkcji main:
    -tworzy sie tab. asocjacyjna;
    -dodana zosatje para (klucz, wartosc);
    -sprawdza sie dzialanie funkcji pobierz;
    -sprawdza sie dzialania funkcji usun;
    -sprawdza sie zawartosci tablicy.
 */
int main(){
 Tablica <string , int> tab;
 para <string,int> para("napis", 10); //sprawdza poprawnosc metody
 tab.dodaj(para);
cout << tab.pobierz ("napis") <<endl;
tab.usun("napis");
cout << "Tablica:" <<tab.czypusta() <<endl;
}

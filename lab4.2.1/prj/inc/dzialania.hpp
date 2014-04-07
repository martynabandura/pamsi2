#ifndef DZIALANIA_HPP
#define DZIALANIA_HPP



#include "tablica.hpp"
/*! \brief Deklaracja klasy Dzialania.

* Klasa Dzialania posiada funkcje potrzebne do wykonywania dzialan na tablicach .

*/

class Dzialania
{
private:
//! Pole przechowujace tablice  1.
Tablica<int> tab1;
//! Pole przechowujace tablice  2.
Tablica<int> tab2;
//! Funkcja wykonujaca dzialanie mnozenia danych z pliku 2 razy.
void oblicz();

public:
      /*! Funkcja wczytujaca plik. Sprawdza także poprawność wykonania operacji.*/


      bool wczytajplik(char *nazwapl);
/*! Funkcja porownuje dwa pliki :
*  plik wejsciowy i sprawdzajacy.
*/

      bool porownaj(char *nazwapl);
/*! Funkcja mierzy czas działania
      
/*! Funkcja zwraca rozmiar danej tablicy.
*/

      int rozmiartab () { return tab1.rozmiar() ; }
 	
      double liczczas(int iloscpowtorzen);

};
void foo();

#endif

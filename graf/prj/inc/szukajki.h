/*!
*\file
*\brief Plik zawiera definicje funkcji szukajki
*/


#include  "graf.h"
#include <iostream>
#include <list>

std::list<int> depth_first(Graf& cos, int poczatek, int koniec, std::list<int> historia);
std::list<int> depth_first(Graf& cos, int poczatek, int koniec);
std::list<int> breadth_first(Graf& cos, const int poczatek, const int koniec);
double liczKoszt(Graf& cos, std::list<int> droga);
std::list<int> a_star(Graf& cos, int poczatek, int koniec);

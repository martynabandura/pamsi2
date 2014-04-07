#include "../inc/tablica.hpp"
#include <iostream>
using namespace std;

/*
void Tablica::zamienelementy ( int i ,  int j){
	int p1; int p2;
	p1=T[i];
	p2=T[j];
	T[i]=p2;
	T[j]=p1;
	
}
/*!
*  Dlugosc tablicy, nak torej wykonano dzialanie

*/
/*
void Tablica::odwrockolejnosc(){
  for ( unsigned int i=0 ;i<dlugosctab/2 ;i++)	{

	  zamienelementy(i,dlugosctab -1-i);
	  }

}
/*!
*  Nowy rozmiar tablicy.

*/
/*
void Tablica::zmianarozmiaru (unsigned int nowyrozmiar){

	T=(int*)realloc(T,nowyrozmiar * sizeof(int));
		dlugosctab=nowyrozmiar;
	}
/*!
* Zmienna ktora zostala dodana do tablicy

*/
/*
void Tablica::dodajelement(int element) {
 zmianarozmiaru(rozmiar()+1);
 T[dlugosctab-1]=element;
 }
/*!
*  Nowo powstala tablica

*/
/*
void Tablica::dodajelementy(const Tablica &T1){
	unsigned int tmp=rozmiar();
	zmianarozmiaru(rozmiar()+T1.rozmiar());
	for(unsigned int i=0;i<T1.rozmiar();i++){
		T[tmp+1]=T[i];
	}
}
/*!
*  Przeciazenie operatorow- operator przypisania
*/
/*
Tablica& Tablica::operator = (const Tablica &argument){
	zmianarozmiaru(argument.rozmiar());
	for (unsigned int i=0;i<rozmiar(); i++ ){
		T[i]=argument[i];
	}
 return *this;
}

}

/*!
*  Operator porownania

*//*
bool Tablica::operator == (const Tablica &argument) const{
	if(rozmiar()!=argument.rozmiar()) return false;
	
	for (unsigned int i=0;i<rozmiar() ; i++){
		if(T[i]!=argument[i]) return false;
	}
	return true;
}

*/

void foo22()
{
 cout<<""<<endl;
}



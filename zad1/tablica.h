/*!
\file tablica.h
\brief Plik zawierający definicje klasy tablicy
*/
#ifndef TABLICA_H
#define TABLICA_H

/*!
\brief Klasa reprezentująca tablicę
*/
template <typename Typ> 
class tablica {
  int wy;
  Typ* T;
public:
/*!
\brief Funkcja zwracająca wymiar tablicy
*/
  int wymiar() {return wy;};
/*!
\brief Domyślny konstruktor
*/
  tablica(int wymiar=0);
/*!
\brief Zamienia 2 elementy tablicy
*/
  void zam(int i, int j);


/*!
\brief Odwraca tablice
*/
  void odwroc();

/*!
\brief Dodaje element do tablicy
*/
  void dodaj(Typ e);

/*! 
\brief Dodaje tablice elementów
*/

  tablica<Typ> dodaj(tablica<Typ> A);

/*!
\brief Operator przypisania 
*/
  tablica<Typ> operator= (tablica<Typ> A);


    /*!
\brief Operator porównania
*/
  bool operator== (tablica<Typ> A);

/*!
\brief Operator indeksowania
*/
  Typ & operator[](int ind) {return T[ind];}
/*!
\brief Operator indeksowania - zwraca wartości stałe
*/
  const Typ & operator[](int ind) const {return T[ind];}
};

template<typename Typ>
tablica<Typ>::tablica(int wymiar) {
	wy=wymiar;
	  T = new Typ [wy];
}

template<typename Typ>
void tablica<Typ>::zam(int i, int j) {
    Typ tmp;
  tmp = T[i];
  T[i] = T[j];
  T[j] = tmp;
}

template<typename Typ> void tablica<Typ>::odwroc() {
	for (int i=0;i<(wy/2);i++) {
	      zam(i,wy-i-1);
	}
}
template<typename Typ>  void tablica<Typ>::dodaj(Typ e) {
	wy++;
	    int* tmp;
	    tmp=T;
	    T = new int [wy];
	    for (int i=0;i<wy-1;i++) {
	      T[i]=tmp[i];
	    }
	    T[wy-1]=e;
	    delete [] tmp;
}

template<typename Typ>
 tablica<Typ> tablica<Typ>::dodaj(tablica<Typ> A) {
	int w;
	  w=wy+A.wymiar();
	  tablica Tablica(w);
	  for (int i=0;i<wy;i++) {
	    Tablica[i]=T[i];
	  }
	  for (int i=0;i<A.wy;i++) {
	    Tablica[wy+i]=A[i];
	  }
	  return Tablica;}

template<typename Typ>
 tablica<Typ> tablica<Typ>::operator =(tablica<Typ> A) {
	wy=A.wymiar();
	  int* tmp;
	  tmp=T;
	  delete [] tmp;
	  T = new int [wy];
	  for (int i=0;i<wy;i++) {
	    T[i]=A[i];
	  }
	  return *this;  }

template<typename Typ>
 bool tablica<Typ>::operator ==(tablica<Typ> A) {
	if (wy != A.wymiar()) {
	      return false;
	    }
	    for (int i=0;i<wy;i++) {
	      if (T[i] != A[i]) {
	        return false;}
	    }
}


#endif

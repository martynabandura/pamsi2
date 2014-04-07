#ifndef STOS_H_
#define STOS_H_

#include "tablica.h"

template <typname Typ> class stos {
	tablica <Typ> tab;

public:

	unsigned int size() const { return tab.wymiar(); }
	bool isEmpty () const { return ! tab.wymiar(); }
	const Typ& top() const { return tab[tab.wymiar()-1]; }
	void push(const T value);
	void pop ();

	};

template <typname Typ,

};
#endif

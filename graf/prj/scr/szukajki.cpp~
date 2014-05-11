#include  "graf.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <limits>
#include <set>

#define WALLY 15
std::list<int> depth_first(Graf& cos, int poczatek, int koniec, std::list<int> historia) {
	historia.push_back(poczatek);
	for( auto t : cos.sasiedztwo(poczatek) )
		if(std::find(historia.begin(), historia.end(), t) == historia.end() ) {
			//std::cerr << "OD: " << poczatek << ", biore: " << t << "\n";
			auto kopia = depth_first(cos, t, koniec, historia);
			if(kopia.back() == koniec) return kopia;
		}
	return historia;
}

std::list<int> depth_first(Graf& cos, int poczatek, int koniec) {
	return depth_first(cos, poczatek, koniec, std::list<int>() );
}

std::list<int> breadth_first(Graf& cos, const int poczatek, const int koniec) {
	int* kolor = new int [cos.rozmiar()]();
	int* rodzic = new int [cos.rozmiar()]();

	kolor[poczatek] = 1;
	rodzic[poczatek] = -1;

	std::list<int> wiersz = { poczatek };

	while(!wiersz.empty() ) {
		auto w = wiersz.back();
		if(w == koniec) break;
		wiersz.pop_back();
		for(auto ws : cos.sasiedztwo(w) ) {
			if(kolor[ws] == 0) {
				kolor[ws] = 1;
				rodzic[ws] = w;
				wiersz.push_back(ws);
			}
		}
		kolor[w] = 2;
	}

	std::list<int> ret;
	for(int i = koniec; i != -1; i = rodzic[i]) ret.push_front(i);
	delete[] kolor;
	delete[] rodzic;
	return ret;

}

double liczKoszt(Graf& cos, std::list<int> droga) {
	double koszt = 0;
	auto it = droga.begin();
	for(int i = 0; i < droga.size()-1; i++)
		koszt += cos.czy_sasiad( *it, *++it ); 
	return koszt;
}

// -- implementacja A* z biblioteki boost --
// A*(G, s, h)
//   for each vertex u in V
//     d[u] := f[u] := infinity
//     color[u] := WHITE
//     p[u] := u
//   end for
//   color[s] := GRAY
//   d[s] := 0
//   f[s] := h(s)
//   INSERT(Q, s)
//   while (Q != Ø)
//     u := EXTRACT-MIN(Q)
//     for each vertex v in Adj[u]
//       if (w(u,v) + d[u] < d[v])
//         d[v] := w(u,v) + d[u]
// 	f[v] := d[v] + h(v)
// 	p[v] := u
// 	if (color[v] = WHITE)
// 	  color[v] := GRAY
// 	  INSERT(Q, v)
// 	else if (color[v] = BLACK)
// 	  color[v] := GRAY
// 	  INSERT(Q, v)
// 	end if
//       else
//         ...
//     end for
//     color[u] := BLACK
//   end while
 

std::list<int> a_star(Graf& cos, int poczatek, int koniec) {
	int* odleglosc = new int[cos.rozmiar()]; 
		std::fill(odleglosc, odleglosc+cos.rozmiar(), std::numeric_limits<int>::max() );
	int* f = new int[cos.rozmiar()];
		std::fill(f, f+cos.rozmiar(), std::numeric_limits<int>::max() );
	int* kolor = new int[cos.rozmiar()]();
	int* rodzic = new int[cos.rozmiar()]; for(int i = 0; i < cos.rozmiar(); ++i) rodzic[i] = i;
	class heurestic {
		public:
			int operator()(int n) { return 0; }
	} h;
	rodzic[poczatek] = -1;
	kolor[poczatek] = 1;
	odleglosc[poczatek] = 0;
	f[poczatek] = h(poczatek);
	
	std::set<int> Q;
	Q.insert(poczatek);
	while(!Q.empty() ) {
		// prezentacja przebiegu wyszukiwania
		 for( auto it = Q.begin(); it != Q.end(); ++it )
			std::cerr << *it << ", "; std::cerr << "\n";
		auto u = *Q.begin();
		Q.erase(Q.begin());
		for(auto v : cos.sasiedztwo(u) ) {
			if(cos.czy_sasiad(u,v) + odleglosc[u] < odleglosc[v]) {
				odleglosc[v] = cos.czy_sasiad(u,v) + odleglosc[u];
				f[v] = odleglosc[v] + h(v);
				rodzic[v] = u;
				if(kolor[v] == 0) {
					kolor[v] = 1;
					Q.insert(v);
				}
				else if( kolor[v] == 2 ) {
					kolor[v] = 1;
					Q.insert(v);
				}
			} else {
				/* nic nie rób */
			}
		}
		kolor[u] = 2;
	}

	std::list<int> ret;
	//~ std::cerr << odleglosc[koniec] << " <- długość znalezionej ścieżki! \n";
	for(int i = koniec; i != -1; i = rodzic[i]) ret.push_front(i);
	return ret;
}

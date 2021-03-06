/*!
* \file
* \brief Plik naglowkowy klasy Integral.
*/
#ifndef INTEGRAL
	#define INTEGRAL

	#include <cmath>  // moduł potrzebny do różnych funkcji matematycznych typu sinus/pierwiastek itp.

	const int PARTS_INTEGRAL = 1000;  // liczba próbek (argumentów) w których obliczamy wartość funkcji dla całki oznaczonej

/*!
*\brief Deklaracja klasy Integral.
*/


	class Integral {
		private:
			double (*f)(double);  // funkcja, dla której obliczamy całki
		
		public:
			Integral(double (*f)(double));  // konstruktor, który przyjmuje wskaźnik do funkcji i zapamiętuje go (w zmiennej opisanej powyżej)
			double DefiniteIntegral(double from, double to);  // funkcja obliczająca całki oznaczone na przedziale [ from ; to ]
			double IndefiniteIntegral(double from, double to);  // funkcja obliczająca całki nieoznaczone na przedziale [ from ; to] (można wykorzystywać stałą INFINITY)
	};
#endif

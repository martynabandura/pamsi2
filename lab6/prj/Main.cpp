#include<iostream>
#include "Tablica.h"
#include "Drzewo.h"
#include<time.h>
using namespace std;
string gen_random(const int len) {
   string s="";
	static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
return s;
}

int main(){
	int rozmiar;
	double czasTablica,czasDrzewo;
	cout<<"Podaj rozmiar problemu:"<<endl;
	cin>>rozmiar;
	string *tab = new string[rozmiar];
	Drzewo<string,int> drzewo;
	Tablica<string,int>	tablica(rozmiar);
	clock_t t;
	for(int j =0;j<rozmiar;++j){
		tab[j] = gen_random(10);
	}
	/*Dodawanie*/
	t = clock();
	for(int j = 0;j<rozmiar;++j){
		tablica.dodaj(Para<string,int>(tab[j],rand()));
	}
	t = clock() - t;
	czasTablica = static_cast<double>(t)/CLOCKS_PER_SEC;
	t = clock();
	for(int j = 0;j<rozmiar;++j){
		drzewo.dodaj(tab[j],rand());
	}
	t = clock() - t;
	czasDrzewo = static_cast<double>(t)/CLOCKS_PER_SEC;
	cout<<"Czas dodania "<<rozmiar<<" elementow do tablicy wyniosl: "<<czasTablica<<endl;
	cout<<"A do drzewa: "<<czasDrzewo<<endl;
	/*Szukanie*/
	t = clock();
	for(int j = 0;j<rozmiar;++j){
		tablica.pobierzWartosc(tab[rand()%rozmiar]);
	}
	t = clock() - t;
	czasTablica = static_cast<double>(t)/CLOCKS_PER_SEC;
	t = clock();
	for(int j = 0;j<rozmiar;++j){
		drzewo.pobierzWartosc(tab[rand()%rozmiar]);
	}
	t = clock() - t;
	czasDrzewo = static_cast<double>(t)/CLOCKS_PER_SEC;
	cout<<"Czas szukania "<<rozmiar<<" elementow w tablicy wyniosl: "<<czasTablica<<endl;
	cout<<"A w drzewie: "<<czasDrzewo<<endl;
	/*usuwanie*/
	t = clock();
	for(int j = 0;j<rozmiar;++j){
		tablica.usun(tab[j]);
	}
	t = clock() - t;
	czasTablica = static_cast<double>(t)/CLOCKS_PER_SEC;
	t = clock();
	for(int j = 0;j<rozmiar;++j){
		drzewo.usun(tab[j]);
	}
	t = clock() - t;
	czasDrzewo = static_cast<double>(t)/CLOCKS_PER_SEC;
	cout<<"Czas usuwania "<<rozmiar<<" elementow w tablicy wyniosl: "<<czasTablica<<endl;
	cout<<"A w drzewie: "<<czasDrzewo<<endl;


	int i;
	cin>>i;
	return 0;
}
all: graf.o main.o szukajki.o benchmark.o
	clang++ graf.o main.o szukajki.o benchmark.o -Wall -std=c++11
graf.o: graf.h graf.cpp
	clang++ -c graf.cpp -Wall -std=c++11
main.o: main.cpp
	clang++ -c main.cpp -Wall -std=c++11
szukajki.o: szukajki.h szukajki.cpp
	clang++ -c szukajki.cpp -Wall -std=c++11
benchmark.o: benchmark.h benchmark.cpp
	clang++ -c benchmark.cpp -Wall -std=c++11

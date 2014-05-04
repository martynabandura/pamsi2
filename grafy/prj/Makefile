all: graf.o main.o
	clang++ graf.o main.o -Wall -std=c++11
graf.o: graf.h graf.cpp
	clang++ -c graf.cpp -Wall -std=c++11
main.o: main.cpp
	clang++ -c main.cpp -Wall -std=c++11


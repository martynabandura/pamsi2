

__start__: a.out
	./a.out

a.out: obj/glowny.o obj/quick.o obj/tablica.o obj/dzialania.o obj/merge.o
	g++ glowny.o quick.o tablica.o dzialania.o merge.o

obj/glowny.o: src/glowny.cpp inc/quick.hpp src/tablica.cpp inc/merge.hpp
	g++ -c  src/glowny.cpp

obj/quick.o: inc/quick.hpp src/quick.cpp
	g++ -c src/quick.cpp

obj/merge.o: inc/merge.hpp src/merge.cpp
	g++ -c src/merge.cpp

obj/dzialania.o: inc/dzialania.hpp src/dzialania.cpp src/tablica.cpp
	g++ -c src/dzialania.cpp

obj/tablica.o: inc/tablica.hpp src/tablica.cpp
	g++ -c src/tablica.cpp

obj/czas.o: inc/czas.hpp src/czas.cpp
	g++ -c src/czas.cpp

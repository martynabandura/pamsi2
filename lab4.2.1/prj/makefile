__start__: a.out
	./a.out

a.out: obj/glowny.o obj/quick.o obj/merge.o obj/sort_benchmark.o 
	g++ obj/glowny.o obj/quick.o obj/merge.o obj/sort_benchmark.o 

obj/glowny.o: src/glowny.cpp inc/quick.hpp inc/merge.hpp
	g++ -c  src/glowny.cpp -o obj/glowny.o

obj/quick.o: inc/quick.hpp src/quick.cpp
	g++ -c src/quick.cpp -o obj/quick.o

obj/merge.o: inc/merge.hpp src/merge.cpp
	g++ -c src/merge.cpp -o obj/merge.o
	
obj/sort_benchmark.o: inc/sort_benchmark.hpp src/sort_benchmark.cpp
	g++ -c src/sort_benchmark.cpp -o obj/sort_benchmark.o

clean:
	rm obj/* a.out

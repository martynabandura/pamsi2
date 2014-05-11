#include "graf.h"
#include "szukajki.h"
#include <iostream>
#include "benchmark.h"

int main(int argc, char** argv) {
	/*
	Graf cos(6);
	cos.dod_kraw(1, 2, 4);
	cos.dod_kraw(2, 3, 4);
	cos.dod_kraw(1, 4, 3);
	cos.dod_kraw(3, 5, 6);
	cos.dod_kraw(4, 6, 5);
	cos.dod_kraw(0, 1, 3);
	cos.dod_kraw(0, 2, 5);
	*/
	   
	Graf cos(16);
	cos.dod_kraw(0, 1, 1);
	cos.dod_kraw(1, 4, 4);
	cos.dod_kraw(4, 5, 5);
	cos.dod_kraw(4, 6, 6);
	cos.dod_kraw(4, 7, 7);
	cos.dod_kraw(6, 8, 8);
	cos.dod_kraw(7, 2, 9);
	cos.dod_kraw(2, 15, 10);
	cos.dod_kraw(2, 9, 11);
	cos.dod_kraw(2, 10, 12);
	cos.dod_kraw(0, 2, 2);
	cos.dod_kraw(0, 3, 3);
	cos.dod_kraw(3, 11, 13);
	cos.dod_kraw(11, 13, 14);
	cos.dod_kraw(11, 14, 15);
	cos.dod_kraw(3, 12, 16);
	cos.dod_kraw(12, 1, 17);

	benchmark(cos, 0, 15, std::cout);
	return 0;
}

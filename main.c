#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cells.h"
#include "generations.h"
#include "fileread.h"
#include "filewrite.h"

int main( int argc, char* argv[] ) {                     //plik do czytania, liczba generacji, plik do wpisywania
	
	char * in = (argc > 1) ? argv[1] : "readtest.txt"; 
	int gen = (argc > 2) ? atoi(argv[2]) : 4;
	char * out = (argc > 3) ? argv[3] : "writetest.txt";

struct Cells newcells = cellsread (in);                  //czytanie z pliku (fileread.c)
while (gen--) {
	newcells = generation (newcells);                    //nowe generacji (generations.c)
	//<pngcreate>
}
cellswrite (newcells, out);                              //wpisywanie do pliku (filewrite.c)

return 0;

}
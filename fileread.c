#include "cells.h"
#include "fileread.h"

struct Cells cellsread (char * file) {

	int height, width;
	int bin;

	FILE * in = fopen (file, "r");

	fscanf (in, "%d", &width);                        //zapisujemy dlugosc
	fscanf (in, "%d", &height);                       //zapisujemy szerokosc

	struct Cells field = createcells (width, height); //tworzymy macierz dlugosc*szerokosc

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fscanf (in, "%d", &bin);
			field.cells[i][j] = bin;        		  //zapisujemy wartosci z pliku do macierzy
		}
	}

	return field;

}

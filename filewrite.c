#include "cells.h"
#include "filewrite.h"

void cellswrite (struct Cells field, char * file) {

	FILE *out = fopen (file, "w");

	fprintf (out, "%d ", field.width);               //zapisujemy na poczatek pliku go dlugosc
	fprintf (out, "%d \n", field.height);            //i ego wysokosc

	for (int i = 0; i < field.height; i++) {
		for (int j = 0; j < field.width; j++) 
			fprintf (out, "%d ", field.cells[i][j]); //zapisujemy macierz do pliku
		fprintf (out, "\n");
	}

	fclose (out);

}

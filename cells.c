#include "cells.h"

struct Cells createcells (int w, int h) {
	
	struct Cells field;                                         //nowa struktura typu Cells

	field.width = w;                                            //dlugosc macierzy z argumentow
	field.height = h;                                           //wysokosc macirzy z argumentow
	
	field.cells = malloc (w * sizeof field.cells);              //allokujem pamiec dla width
	for (int i = 0; i < w; i++)
		field.cells[i] = malloc (h * sizeof field.cells);       //allokujem pamiec dla calosci (width*height)

	return field;                                               //zwracamy strukture
}
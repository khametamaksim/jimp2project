#include "cells.h"
#include "generations.h"

struct Cells generation (struct Cells field ) {
    struct Cells onemore = createcells (field.width, field.height );                                //tworzymy strukture
    for (int y = 0; y < field.height; y++)
        for (int x = 0; x < field.width; x++)
            onemore.cells[x][y] = rebuild (field, x, y);                                            //sprawdzamy komorke i jej sasiadow
    return onemore;
}

int rebuild (struct Cells field, int x, int y) {
    if ((field.cells[x][y] == 0) && (beside (field, x, y) == 3 ))                                   //jezeli mamy 3ch zywych sasiadow (0->1)
        return 1;
    if ((field.cells[x][y] == 1) && ((beside (field, x, y) < 2) || (beside (field, x, y) > 3)))     //jezeli mamy 2 albo 3 zywych (1->1)
        return 0;
    return field.cells[x][y];
}

int beside (struct Cells field, int x, int y) {

    int neighbours = 0;                                                                             //ilosc zywych sasiadow

	int top = (y != 0) ? field.cells[x][y-1] : -1;                                                  //definiuemy po kolei wszystkie komorki wokol wybranej
	int topright = ((y != 0) && (x+1 != field.width)) ? field.cells[x+1][y-1] : -1;
	int right = (x+1 != field.width) ? field.cells[x+1][y] : -1;
	int bottomright = ((x+1 != field.width) && (y+1 != field.height)) ? field.cells[x+1][y+1] : -1;
	int bottom = (y != field.height) ? field.cells[x][y+1] : -1;
	int bottomleft = (( y!= field.height) && (x != 0)) ? field.cells[x-1][y+1] : -1;
	int left = (x != 0) ? field.cells[x-1][y] : -1;
	int topleft = ((x != 0) && (y != 0)) ? field.cells[x-1][y-1] : -1;

	if (top == 1) neighbours++;                                                                     //sprawdzamy czy sasiad jest zywy
	if (topright == 1) neighbours++;
	if (right == 1) neighbours++;
	if (bottomright == 1) neighbours++;
	if (bottom == 1) neighbours++;
	if (bottomleft == 1) neighbours++;
	if (left == 1) neighbours++;
	if (topleft == 1) neighbours++;
	
	return neighbours;                                                                              //zwracamy ilosc zywych komorek
}


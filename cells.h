#include <stdio.h>
#include <stdlib.h>

struct Cells {
	int width;
	int height;
	int **cells;
};

struct Cells createcells (int, int);
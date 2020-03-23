#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void main (int argc, char *argv[]) {                    //funkcja generujaca losowa macierz danych

	char * in = (argc > 1) ? argv[1] : "readtest.txt";  //domyslnie w pliku readtest.txt 50*50 komorek
	int width = (argc > 2) ? atoi(argv[2]) : 50;
	int height = (argc > 3) ? atoi(argv[3]) : 50;

	srand(time(NULL));
	
	FILE *out = fopen (in, "w");

	fprintf (out, "%d ", width);               
	fprintf (out, "%d \n", height);            

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) 
			fprintf (out, "%d ", rand()%2);             //losowo wstawiamy 1/0
		fprintf (out, "\n");
	}

	fclose (out);
}

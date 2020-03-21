#include "filegen.h"

char * pngname (int n) {                    //generacja nazwy plikow .png
	char str[3];
	sprintf(str, "%d", n+1);            //numer generacji = numer pliku
	char png[4] = ".png";
	char *filename = strcat(str, png);  //funkcja sklejania stringow
        printf ("%s ", filename);
	return filename;
}

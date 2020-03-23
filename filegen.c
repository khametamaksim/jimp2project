#include "filegen.h"

char * pngname (int n) {                                        //generacja nazwy plikow .png
	char *str = malloc(20);
	sprintf(str, "%s%d%s", "png/", n+1, ".png");                //folder, numer generacji = numer pliku, rozszerzenie
        printf ("%s ", str);
	return str;
}

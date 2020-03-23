all: main.c generations.c cells.c fileread.c filewrite.c filegen.c pngfile.c
	gcc main.c generations.c cells.c fileread.c filewrite.c filegen.c pngfile.c -L/path/to/dir_containing/libpng -lpng -o all
#zeby urochomic program > life + (opcjonalnie) [plik_do_czytania] [liczba_generacji] [plik do wypisywania]
gif: 
	ffmpeg -framerate 10 -i png/%d.png png/result.gif
#wszystkie pliki .png od poczatku po 10 na sekunde w result gif
gen: testgen.c
	gcc testgen.c -o gen
#zeby zgenerowac dane > gen + (opcjonalnie) [plik] [width] [height]
clean: 
	rm all gen

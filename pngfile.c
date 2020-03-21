#include "cells.h"
#include "pngfile.h"

png_byte color_type;                                                //zmienne z biblioteki png
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

void process_file(struct Cells field, char *file_name) {            //tworzymy macierz i sprawdzamy wartosc komorki
  
  int width = field.width;
  int height = field.height;
  bit_depth = 8;
  color_type = PNG_COLOR_TYPE_GRAY;

  number_of_passes = 7;
  row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
  for (int y = 0; y < height; y++)
    row_pointers[y] = (png_byte*) malloc(sizeof(png_byte) * width);

  for (int y = 0; y < height; y++) {
    png_byte* row = row_pointers[y];
    for (int x = 0; x < width; x++) {
      row[x] = field.cells[x][y] ? 255 : 0;                         //prupisujemy czarny lub bialy koler
    }
  }
  png (file_name, width, height); 
}

void png (char* file_name, int width, int height) {                 //funkcja zapisywania pikseli do pliku
  
  FILE *fp = fopen(file_name, "wb");
  if (!fp)
    printf("[write_png_file] File %s could not be opened for writing", file_name);

  png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

  if (!png_ptr)
    printf("[write_png_file] png_create_write_struct failed");

  info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr)
    printf("[write_png_file] png_create_info_struct failed");

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during init_io");

  png_init_io(png_ptr, fp);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during writing header");

  png_set_IHDR(png_ptr, info_ptr, width, height,
   bit_depth, color_type, PNG_INTERLACE_NONE,
   PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

  png_write_info(png_ptr, info_ptr);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during writing bytes");

  png_write_image(png_ptr, row_pointers);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during end of write");

  png_write_end(png_ptr, NULL);

  for (int y=0; y < height; y++)
    free(row_pointers[y]);
  free(row_pointers);

  fclose(fp);
}

#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "canvas.h"

void save_canvas(canvas* drawingCanvas, char* file_name) {
  FILE* out_file = NULL;
  out_file = fopen(file_name, "w");
  if (out_file == NULL || out_file == false) {
    printf("Improper save command or file could not be created.\n");
  }

  fprintf(out_file, "%d %d\n", drawingCanvas->numRows, drawingCanvas->numCols);
  for (int i = 0; i < drawingCanvas->numRows; ++i) {
    for (int j = 0; j < drawingCanvas->numCols; ++j) {
      fprintf(out_file, "%c ", (drawingCanvas->array[i][j]));
    }
    fprintf(out_file, "\n");
  }
  fprintf(out_file, "\n");
  fclose(out_file);
}

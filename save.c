#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"

void save_canvas(canvas* drawingCanvas, char* file_name) {
  FILE* out_file = NULL;
  out_file = fopen(file_name, "w");
  if (out_file == NULL) {
    printf("Improper save command or file could not be created.\n");
  }

  fprintf("%d %d\n", drawingCanvas->numRows, drawingCanvas->numCols);
  for (int i = 0; i < drawingCanvas->numRows; ++i) {
    for (int j = 0; j < drawingCanvas->numCols; ++j) {
      fprintf(out_file, " %d", (drawingCanvas->array[i][j]));
    }
    printf("\n");
  }
  printf("\n");
  fclose(out_file);
}

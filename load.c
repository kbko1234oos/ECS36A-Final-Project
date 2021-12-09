#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"

canvas* load_canvas(canvas* input_canvas, char* file_name) {
  FILE* input_file = fopen(file_name, "r");
  if (input_file == NULL) {
    printf("Could not open file %s.\n", file_name);
  }

  input_canvas = (canvas*)calloc(1, sizeof(canvas));
  fscanf(input_file, "%d %d", &input_canvas->numRows, &input_canvas->numCols);
  input_canvas->blankChar = '*';
  makeCanvas(input_canvas);
  for (int i = 0; i < input_canvas->numRows; ++i) {
    for (int j = 0; j < input_canvas->numCols; ++j) {
      fscanf(input_file, " %c", &((input_canvas->array)[i][j]));
    }
  }
  return input_canvas;
}

#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "canvas.h"
#include "free.h"

canvas* load_canvas(canvas* drawingCanvas, char* file_name) {
  FILE* input_file = fopen(file_name, "r");
  if (input_file == NULL) {
    printf("Could not open file %s.\n", file_name);
  }

  free_canvas(drawingCanvas);
  canvas* input_canvas = (canvas*)calloc(1, sizeof(canvas));
  input_canvas->blankChar = '*';
  get_dimensions(input_file, &(input_canvas->numRows), &(input_canvas->numCols));
  makeCanvas(input_canvas);
  for (int i = 0; i < input_canvas->numRows; ++i) {
    for (int j = 0; j < input_canvas->numCols; ++j) {
      fscanf(input_file, " %c", &((input_canvas->array)[i][j]));
    }
  }
  close_txt(input_file);
  return input_canvas;
}

void get_dimensions(FILE* my_txt, int* length, int* width){
  fscanf(my_txt,"%d %d", length, width);
  return;
}

void close_txt(FILE* my_txt){
  fclose(my_txt);
}

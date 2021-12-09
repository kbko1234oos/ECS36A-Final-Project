#ifndef LOAD_H
#define LOAD_H
  #include "canvas.h"
  canvas* load_canvas(canvas* input_canvas, char* file_name);
  void get_dimensions(FILE* my_txt, int* length, int* width){
  void read_txt_into_array(FILE* my_txt, double*** matrix, int dimension);
#endif

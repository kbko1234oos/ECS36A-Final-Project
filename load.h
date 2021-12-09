#ifndef LOAD_H
#define LOAD_H
  #include "canvas.h"
  canvas* load_canvas(canvas* input_canvas, char* file_name);
  void get_dimensions(FILE* my_txt, int* length, int* width);
    void close_txt(FILE* my_txt);
#endif

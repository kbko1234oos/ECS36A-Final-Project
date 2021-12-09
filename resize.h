#ifndef RESIZE_H
#define RESIZE_H
    #include "canvas.h"
    canvas* resize_canvas(canvas* old_canvas, int input_row, int input_col);
    void copy_canvas(canvas* old_canvas, canvas* new_canvas, int input_row, int input_col);
#endif

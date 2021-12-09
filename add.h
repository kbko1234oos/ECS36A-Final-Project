#ifndef ADD_H
#define ADD_H
    #include "canvas.h"
    canvas* add_to_canvas(canvas* old_canvas, int add_index, bool add_row);
    void copy_row(canvas* old_canvas, canvas* new_canvas, int old_canvas_row_index, int new_canvas_row_index);
    void copy_column(canvas* old_canvas, canvas* new_canvas, int old_canvas_col_index, int new_canvas_col_index);
#endif

#ifndef ADD_H
#define ADD_H
    void add_to_canvas(canvas* old_canvas, int add_index, bool add_row);
    void copy_row(matrix* old_canvas, matrix* new_canvas, int old_canvas_row_index, int new_canvas_row_index);
    void copy_column(matrix* old_canvas, matrix* new_canvas, int old_canvas_col_index, int new_canvas_col_index);
#endif

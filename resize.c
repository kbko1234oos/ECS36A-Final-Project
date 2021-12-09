#include <stdlib.h>
#include "resize.h"
#include "canvas.h"
#include "free.h"

canvas* resize_canvas(canvas* old_canvas, int input_row, int input_col) {
    canvas* new_canvas = (canvas*)calloc(1, sizeof(canvas));
    new_canvas->numRows = input_row;
    new_canvas->numCols = input_col;
    new_canvas->blankChar = '*';
    makeCanvas(new_canvas);
    copy_canvas(old_canvas, new_canvas, input_row, input_col);
    free_canvas(old_canvas);
    return new_canvas;
}

void copy_canvas(canvas* old_canvas, canvas* new_canvas, int input_row, int input_col) {
    int row_limit = 0;
    int col_limit = 0;

    //Sets the limit of the row and col index to whatever is smaller when comparing
    //between the input # and the old canvas #.
    if (input_row < old_canvas->numRows) {
        row_limit = input_row;
    } else {
        row_limit = old_canvas->numRows;
    }
    if (input_col < old_canvas->numCols) {
        col_limit = input_row;
    } else {
        col_limit = old_canvas->numCols;
    }

    for (int i = 0; i < row_limit; ++i) {
        for (int j = 0; j < col_limit; ++j) {
            (new_canvas->array)[i][j] = (old_canvas->array)[i][j];
        }
    }
}

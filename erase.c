#include "canvas.h"

void erase_char(canvas* drawing_canvas, int input_row, int input_col) {
  (drawing_canvas->array)[input_row][input_col] = '*';
}
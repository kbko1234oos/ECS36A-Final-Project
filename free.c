#include <stdlib.h>
#include "canvas.h"
#include "write.h"
#include "free.h"

void free_canvas(canvas* old_canvas) {
  for (int i = 0; i < old_canvas->numRows; ++i) {
    free(old_canvas->array[i]);
  }
  free(old_canvas->array);
  free(old_canvas);
}

void free_line(line* old_line) {
  free(old_line);
}
#include <stdlib.h>
#include "write.h"
#include "canvas.h"

void write_line(canvas* drawing_canvas, line* input_line) {
  int y_diff = input_line->p1.y - input_line->p2.y;
  int x_diff = input_line->p1.x - input_line->p2.x;

  if ((input_line->p1.x - input_line->p2.x) == 0) {
    input_line->slope = 420.21;
  }
  input_line->slope = (double)(abs(y_diff)) / abs(x_diff);

  if (input_line->slope > 0) {
    input_line->type = pos_diag;
  } else if (input_line->slope < 0) {
    input_line->type = neg_diag;
  } else if (input_line->slope == 0) {
    input_line->type = horiz;
  } else if (input_line->slope == 420.21) {
    input_line->type = vert;
  }

  switch (input_line->type) {
    case horiz:
      if (input_line->p1.x > input_line->p2.x) {
        switch_coords(input_line);
      }
      for (int i = input_line->p1.x; i < input_line->p2.x; ++i) {
        (drawing_canvas->array)[input_line->p1.y][i] = '-';
      }
      break;
    case vert:
      if (input_line->p1.y > input_line->p2.y) {
        switch_coords(input_line);
      }
      for (int i = input_line->p1.y; i < input_line->p2.y; ++i) {
        (drawing_canvas->array)[i][input_line->p1.x] = '|';
      }
      break;
    case pos_diag:
      if (input_line->p1.x > input_line->p2.x) {
        switch_coords(input_line);
      }
      for (int i = input_line->p1.x; i < input_line->p2.x; ++i) {
        (drawing_canvas->array)[input_line->p1.y + i][input_line->p1.x + i] = '/';
      }
      break;
    case neg_diag:
      if (input_line->p1.x > input_line->p2.x) {
        switch_coords(input_line);
      }
      for (int i = input_line->p1.x; i < input_line->p2.x; ++i) {
        (drawing_canvas->array)[input_line->p1.y - i][input_line->p1.x + i] = '/';
      }
      break;
    default:
      break;
  }
}

void switch_coords(line* input_line) {
  int temp = input_line->p1.x;
  input_line->p1.x = input_line->p2.x;
  input_line->p2.x = temp;

  temp = input_line->p1.y;
  input_line->p1.y = input_line->p2.y;
  input_line->p2.y = temp;
}


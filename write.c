#include <stdlib.h>
#include "write.h"
#include "canvas.h"

void write_line(canvas* drawing_canvas, line* input_line) {
  int y_diff = input_line->p1.y - input_line->p2.y;
  int x_diff = input_line->p1.x - input_line->p2.x;

  if (y_diff == x_diff) {
    input_line->type = pos_diag;
  } else if (y_diff == -(x_diff)) {
    input_line->type = neg_diag;
  } else if (y_diff == 0) {
    input_line->type = horiz;
  } else if (x_diff == 0) {
    input_line->type = vert;
  } else {
    printf("Improper write command.\n");
    return;
  }

  switch (input_line->type) {
    case horiz:
      if (input_line->p1.x > input_line->p2.x) {
        switch_coords(input_line);
      }
      for (int i = 0; i < abs(x_diff) + 1; ++i) {
        char char_check = (drawing_canvas->array)[input_line->p1.y][i + input_line->p1.x];
        if (char_check != '*' && char_check != '-') {
          (drawing_canvas->array)[input_line->p1.y][i + input_line->p1.x] = '+';
        } else {
          (drawing_canvas->array)[input_line->p1.y][i + input_line->p1.x] = '-';
        }
      }
      break;
    case vert:
      if (input_line->p1.y > input_line->p2.y) {
        switch_coords(input_line);
      }
      for (int i = 0; i < abs(y_diff) + 1; ++i) {
        char char_check = (drawing_canvas->array)[input_line->p1.y + i][input_line->p1.x];
        if (char_check != '*' && char_check != '|') {
          (drawing_canvas->array)[input_line->p1.y + i][input_line->p1.x] = '+';
        } else {
          (drawing_canvas->array)[input_line->p1.y + i][input_line->p1.x] = '|';
        }
      }
      break;
    case pos_diag:
      if (input_line->p1.x > input_line->p2.x) {
        switch_coords(input_line);
      }
      for (int i = 0; i < abs(x_diff) + 1; ++i) {
        char char_check = (drawing_canvas->array)[input_line->p1.y + i][input_line->p1.x + i];
        if (char_check != '*' && char_check != '/') {
          (drawing_canvas->array)[input_line->p1.y + i][input_line->p1.x + i] = '+';
        } else {
          (drawing_canvas->array)[input_line->p1.y + i][input_line->p1.x + i] = '/';
        }
      }
      break;
    case neg_diag:
      if (input_line->p1.x > input_line->p2.x) {
        switch_coords(input_line);
      }
      for (int i = 0; i < abs(x_diff) + 1; ++i) {
        char char_check = (drawing_canvas->array)[input_line->p1.y - i][input_line->p1.x + i];
        if (char_check != '*' && char_check != '\\') {
          (drawing_canvas->array)[input_line->p1.y - i][input_line->p1.x + i] = '+';
        } else {
          (drawing_canvas->array)[input_line->p1.y - i][input_line->p1.x + i] = '\\';
        }
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


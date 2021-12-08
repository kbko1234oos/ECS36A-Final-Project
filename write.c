#include <stdlib.h>
#include "write.h"
#include "canvas.h"

void write_line(line* input_line) {
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

  

  if (input_line->type == horiz) {
    //Code for horizontal
  } else if (input_line->type == vert) {
    //Code for vertical
  } else if (input_line->type == pos_diag) {
    //Code for positive diagonal
  } else if (input_line->type == neg_diag) {
    //Code for negative diagonal
  }
}
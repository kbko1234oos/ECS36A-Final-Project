#ifndef WRITE_H
#define WRITE_H
  #include "canvas.h"
  typedef struct point_struct {
    int x;
    int y;
  }point;

  typedef enum {
    pos_diag, neg_diag, horiz, vert
  }line_type;

  typedef struct line_struct {
    point p1;
    point p2;
    double slope;
    line_type type;
  }line;

  void write_line(canvas* drawing_canvas, line* input_line, int input);
  void switch_coords(line* input_line);
#endif
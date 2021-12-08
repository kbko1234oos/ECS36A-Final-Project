#ifndef WRITE_H
#define WRITE_H
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
#endif
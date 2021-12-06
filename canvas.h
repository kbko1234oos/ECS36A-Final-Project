#include <stdbool.h>
#include <stdio.h>

#ifndef CANVAS_H
#define CANVAS_H
	typedef struct canvas_struct {
    double** array;
    int numRows;
		int numCols;
  }canvas;

	canvas makeCanvas(canvas drawingCanvas, int numRows, int numCols, char blankChar);
	void makeArrayBlank(char** array, int numRows, int numCols, char blankChar);

#endif

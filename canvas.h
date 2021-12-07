#include <stdbool.h>
#include <stdio.h>

#ifndef CANVAS_H
#define CANVAS_H
	typedef struct canvas_struct {
    double** array;
    int numRows;
		int numCols;
  }canvas;

	void makeCanvas(canvas* drawingCanvas, int numRows, int numCols, char blankChar);
	char** create_canvas_array(int numRows, int numCols);
	void makeArrayBlank(char** array, int numRows, int numCols, char blankChar);

#endif

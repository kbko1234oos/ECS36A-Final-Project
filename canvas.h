#include <stdbool.h>
#include <stdio.h>

#ifndef CANVAS_H
#define CANVAS_H
	typedef struct canvas_struct {
    char** array;
    int numRows;
		int numCols;
		char blankChar;
  }canvas;
	void makeCanvas(canvas* drawingCanvas);
	char** create_canvas_array(int numRows, int numCols);
	void fillArrayWithChar(char*** array, int numRows, int numCols, char blankChar);
	void printOutCanvas(canvas* drawingCanvas);


#endif

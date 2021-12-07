#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "canvas.h"

void makeCanvas(canvas* drawingCanvas){
		//Allocate space for canvas
		drawingCanvas->array = create_canvas_array(drawingCanvas->numRows, drawingCanvas->numCols);
    fillArrayWithChar(&(drawingCanvas->array), drawingCanvas->numRows, drawingCanvas->numCols, drawingCanvas->blankChar);
}

char** create_canvas_array(int numRows, int numCols){
    char** input_array = (char**)calloc(numRows, sizeof(char*));
    for(int i = 0; i < numRows; ++i){
        input_array[i] = (char*)calloc(numCols, sizeof(char));
    }
    return input_array;
}

void fillArrayWithChar(char*** array, int numRows, int numCols, char blankChar){
	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numCols; ++j) {
			(*array)[i][j] = blankChar;
		}
	}
}

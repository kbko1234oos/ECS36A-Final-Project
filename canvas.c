#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "canvas.h"

void makeCanvas(canvas* drawingCanvas, int numRows, int numCols, char blankChar){

		drawingCanvas->array = create_canvas_array(numRows, numCols);

    makeArrayBlank(&(drawingCanvas->array), numRows, numCols, blankChar);

    drawingCanvas->numRows = numRows;
    drawingCanvas->numCols = numCols;
}

char** create_canvas_array(int numRows, int numCols){
    char** input_array = (char**)calloc(numCols, sizeof(char*));
    for(int i = 0; i < numRows; ++i){
        input_array[i] = (char*)calloc(numRows, sizeof(char));
    }
    return input_array;
}

void makeArrayBlank(char** array, int numRows, int numCols, char blankChar){
	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			(array*)[i][j] = blankChar;
			//printf("%.2f, ", (*matrix)[i][j] );
		}
		//printf("\n");
	}
	//printf("\n");
}

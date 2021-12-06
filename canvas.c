#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "canvas.h"

canvas makeCanvas(canvas drawingCanvas, int numRows, int numCols, char blankChar){
	drawingCanvas = (matrix*)malloc(sizeof(canvas));
    drawingCanvas->array = create_input_matrix(dimension);

    makeArrayBlank(&(drawingCanvas->array), numRows, numCols, blankChar);

    drawingCanvas->numRows = numRows;
    drawingCanvas->numCols = numCols;
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

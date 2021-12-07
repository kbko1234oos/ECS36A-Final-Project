#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "canvas.h"

void makeCanvas(canvas* drawingCanvas, int numRows, int numCols, char blankChar){
		printf("2\n");
		drawingCanvas->array = create_canvas_array(numRows, numCols);
		printf("2\n");
    makeArrayBlank(&(drawingCanvas->array), numRows, numCols, blankChar);

    drawingCanvas->numRows = numRows;
    drawingCanvas->numCols = numCols;
}

char** create_canvas_array(int numRows, int numCols){
		printf("3\n");
    char** input_array = (char**)calloc(numRows, sizeof(char*));
		printf("3\n");
    for(int i = 0; i < numRows; ++i){
				printf("4\n");
        input_array[i] = (char*)calloc(numCols, sizeof(char));
    }
    return input_array;
}

void makeArrayBlank(char*** array, int numRows, int numCols, char blankChar){
	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numCols; ++j) {
			(*array)[i][j] = blankChar;
			printf("%c, ", (*array)[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}

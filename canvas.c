#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "canvas.h"

void makeCanvas(canvas* drawingCanvas) {
  // Allocate space for canvas and set drawingCanvas as empy allocated space
  drawingCanvas->array =
      create_canvas_array(drawingCanvas->numRows, drawingCanvas->numCols);
  // Fill drawingCanvas with it's drawingCanvas
  fillArrayWithChar(&(drawingCanvas->array), drawingCanvas->numRows,
                    drawingCanvas->numCols, drawingCanvas->blankChar);
}

char** create_canvas_array(int numRows, int numCols) {
  char** input_array = (char**)calloc(numRows, sizeof(char*));
  for (int i = 0; i < numRows; ++i) {
    input_array[i] = (char*)calloc(numCols, sizeof(char));
  }
  return input_array;
}

void fillArrayWithChar(char*** array, int numRows, int numCols,
                       char blankChar) {
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      (*array)[i][j] = blankChar;
    }
  }
}

void printOutCanvas(canvas* drawingCanvas) {
  for (int i = drawingCanvas->numRows - 1; i >= 0; --i) {
    printf("%d ", i);
    for (int j = 0; j < drawingCanvas->numCols; ++j) {
      printf("%c ", drawingCanvas->array[i][j]);
    }
    printf("\n");
  }
  printf(" ");
  for (int k = 0; k < drawingCanvas->numCols; ++k) {
    printf(" %d", k);
  }
  printf("\n");
}

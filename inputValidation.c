#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "inputValidation.h"
#include "write.h"
#include "canvas.h"

// COPIED FROM NOTES ON G-DRIVE
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do {
    scanf("%c", &character);    // 45  bob  \n
    if (!isspace(character)) {  // found a non whitespace character on the way
      // to the end of the line
      formatIsGood = false;
    }
  } while (character != '\n');  // read characters until the end of the line
  return formatIsGood;
}

bool eraseValidation(canvas* drawingCanvas, point* erasePoint) {
  const int numArgsNeeded = 2;
  int greaterThanVal = 0;
  int numArgsRead;
  numArgsRead = scanf(" %d %d", &(erasePoint->x), &(erasePoint->y));

  if (!isValidFormat(numArgsRead, numArgsNeeded) ||
      (!(erasePoint->x >= greaterThanVal)) ||
      (!(erasePoint->y >= greaterThanVal)) ||
      (!(erasePoint->x < drawingCanvas->numCols)) ||
      (!(erasePoint->y < drawingCanvas->numRows))) {
    printf("Improper erase command.\n");
    return false;
    exit(0);
  }
  return true;
}

bool resizeValidation(canvas* drawingCanvas, int* resizeX, int* resizeY) {
  const int numArgsNeeded = 2;
  int greaterThanVal = 0;
  int numArgsRead;
  numArgsRead = scanf(" %d %d", (resizeX), (resizeY));

  if (!isValidFormat(numArgsRead, numArgsNeeded) ||
      (!(*resizeX >= greaterThanVal)) ||
      (!(*resizeY >= greaterThanVal)) ||
      (!(*resizeX < drawingCanvas->numCols)) ||
      (!(*resizeY < drawingCanvas->numRows))) {
    printf("Improper erase command.\n");
    return false;
    exit(0);
  }
  return true;
}

bool writeValidation(canvas* drawingCanvas, point* erasePoint) {
  const int numArgsNeeded = 2;
  int greaterThanVal = 0;
  int numArgsRead;
  numArgsRead = scanf(" %d %d", &(erasePoint->x), &(erasePoint->y));

  if (!isValidFormat(numArgsRead, numArgsNeeded) ||
      (!(erasePoint->x >= greaterThanVal)) ||
      (!(erasePoint->y >= greaterThanVal)) ||
      (!(erasePoint->x < drawingCanvas->numCols)) ||
      (!(erasePoint->y < drawingCanvas->numRows))) {
    printf("Improper erase command.\n");
    return false;
    exit(0);
  }
  return true;
}

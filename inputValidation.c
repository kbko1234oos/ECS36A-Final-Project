#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#include "inputValidation.h"
#include "write.h"
#include "canvas.h"
#include "add.h"

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
      (!(*resizeY >= greaterThanVal)) ) {
    printf("Improper resize command.\n");
    return false;
  }

  return true;
}

bool writeValidation(canvas* drawingCanvas, line* writeLine) {
  const int numArgsNeeded = 4;
  int greaterThanVal = 0;
  int numArgsRead;
  numArgsRead = scanf(" %d %d %d %d", &(writeLine->p1.y), &(writeLine->p1.x), &(writeLine->p2.y), &(writeLine->p2.x));

  if (!isValidFormat(numArgsRead, numArgsNeeded) ||
      //(!(abs(writeLine->p1.x-writeLine->p2.x)==abs(writeLine->p1.y-writeLine->p2.y) )) ||
      (!(writeLine->p1.x >= greaterThanVal)) ||
      (!(writeLine->p1.y >= greaterThanVal)) ||
      (!(writeLine->p2.x >= greaterThanVal)) ||
      (!(writeLine->p2.y >= greaterThanVal)) ||
      (!(writeLine->p1.x < drawingCanvas->numCols)) ||
      (!(writeLine->p1.y < drawingCanvas->numRows)) ||
      (!(writeLine->p2.x < drawingCanvas->numCols)) ||
      (!(writeLine->p2.y < drawingCanvas->numRows))) {
    printf("Improper write command.\n");
    return false;
  }
  return true;
}

bool addValidation(canvas* drawingCanvas, char* addChar, int* addInt) {
  const int numArgsNeeded = 2;
  int greaterThanVal = 0;
  int numArgsRead;

  numArgsRead = scanf(" %c %d", (addChar), (addInt));
  if (!isValidFormat(numArgsRead, numArgsNeeded)) {
    printf("Improper add command.\n");
    return false;
  }else{
    if(*addChar== 'r'){
      if ((!(*addInt >= greaterThanVal)) ||
          (!(*addInt < drawingCanvas->numRows))) {
        printf("Improper add command.\n");
        return false;
      }
    }else if(*addChar== 'c'){
      if ((!(*addInt >= greaterThanVal)) ||
          (!(*addInt < drawingCanvas->numCols))) {
        printf("Improper add command.\n");
        return false;
      }
    }else{
      printf("Improper add command.\n");
      return false;
    }
  }
  return true;
}

bool delValidation(canvas* drawingCanvas, char* delChar, int* delInt) {
  const int numArgsNeeded = 2;
  int greaterThanVal = 0;
  int numArgsRead;

  numArgsRead = scanf(" %c %d", (delChar), (delInt));
  if (!isValidFormat(numArgsRead, numArgsNeeded)) {
    printf("Improper delete command.\n");
    return false;
  }else{
    if(*delChar== 'r'){
      if ((!(*delInt >= greaterThanVal)) ||
          (!(*delInt < drawingCanvas->numRows))) {
        printf("Improper delete command.\n");
        return false;
      }
    }else if(*delChar== 'c'){
      if ((!(*delInt >= greaterThanVal)) ||
          (!(*delInt < drawingCanvas->numCols))) {
        printf("Improper delete command.\n");
        return false;
      }
    }else{
      printf("Improper delete command.\n");
      return false;
    }
  }
  return true;
}

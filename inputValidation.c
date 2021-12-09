#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "inputValidation.h"
#include "write.h"

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

bool eraseValidation(point* erasePoint){
  const int numArgsNeeded = 2;
  int greaterThanVal = 0;
  int numArgsRead;
  printf("1\n");
    numArgsRead = scanf(" %d %d", &(point->x), &(point->y);
    printf("1\n");

    if (!isValidFormat(numArgsRead, numArgsNeeded) ||
        (!(point->x >= greaterThanVal)) ||
        (!(point->y >= greaterThanVal))) {
      printf("Invalid formatting. Ending program.\n");
      return false;
      exit(0);
    }
  return true;
}

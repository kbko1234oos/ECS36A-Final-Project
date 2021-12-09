#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

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

// COPIED/INSPIRED BY NOTES ON G-DRIVE | modified to accept just postive numbers
// | (T) Repeats Question
double getDouble(const char* prompt, int greaterThanVal, bool repeatQuestion) {
  double num;
  const int numArgsNeeded = 1;
  int numArgsRead;

  if (repeatQuestion) {
    do {
      printf("%s", prompt);
      numArgsRead = scanf(" %lf", &num);
    } while (!isValidFormat(numArgsRead, numArgsNeeded) ||
             (!(num >= greaterThanVal)));
  } else {
    printf("%s", prompt);
    numArgsRead = scanf(" %lf", &num);
    if (!isValidFormat(numArgsRead, numArgsNeeded) ||
        (!(num >= greaterThanVal))) {
      printf("Invalid formatting. Ending program.\n");
      exit(0);
    }
  }
  return num;
}

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "commands.h"

#include "canvas.h"
#include "erase.h"
#include "inputValidation.h"
#include "write.h"
#include "resize.h"
#include "write.h"
#include "delete.h"
#include "save.h"

bool correctNumArgs(int argc) {
  if (argc == 3) {
    return true;
  }
  return false;
}

bool argvInputIsValid(char c1, char c2) {
  if (isdigit(c1)) {
		if(isdigit(c2)) {
			return true;
		}else{
			printf("The number of columns is not an integer.\n");
			return false;
		}
  }else{
		printf("The number of rows is not an integer.\n");
		return false;
	}
}

void print_help() {
  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
}

void askAndExecute_for_command_type(canvas* drawingCanvas) {
  char commandLetter;

  point* erasePoint;
  line* writeLine;

  int resizeX, resizeY;

  char addChar;
  int addInt;

  char delChar;
  int delInt;

  char* saveFileName = NULL;

  printf("Enter your command: ");
  scanf(" %c", &commandLetter);
  switch (commandLetter) {
    case 'q':
      //(q)uit DONE
      exit(0);
    case 'h':
      //(h)elp DONE
      print_help();
      break;
    case 'w':
			//(w)write
      writeLine = (line*)calloc(1, sizeof(line));
			if(writeValidation(drawingCanvas, writeLine) ){
				write_line(drawingCanvas, writeLine);
			}
      printOutCanvas(drawingCanvas);
      break;
    case 'e':
			//(e)rase
      erasePoint = (point*)calloc(1, sizeof(point));
			if(eraseValidation(drawingCanvas, erasePoint) ){
				erase_char(drawingCanvas, erasePoint->x, erasePoint->y);
			}
			printOutCanvas(drawingCanvas);
      break;
    case 'r':
			//(r)esize
			if(resizeValidation(drawingCanvas, &resizeX, &resizeY) ){
				drawingCanvas = resize_canvas(drawingCanvas, resizeX, resizeY);
			}
      printOutCanvas(drawingCanvas);
      break;
    case 'a':
			//(a)dd
      if(addValidation(drawingCanvas, &addChar, &addInt) ){
				drawingCanvas = add_to_canvas(drawingCanvas, addChar, addInt);
			}
      printOutCanvas(drawingCanvas);
      break;
    case 'd':
			//(d)elete
      if(delValidation(drawingCanvas, &delChar, &delInt) ){
				drawingCanvas = delete_from_canvas(drawingCanvas, delChar, delInt);
			}
      printOutCanvas(drawingCanvas);
      break;
    case 's':
			//(s)ave
      scanf("%s", saveFileName);
      save_canvas(drawingCanvas, saveFileName);
      printOutCanvas(drawingCanvas);
      break;
    case 'l':
			//(l)oad
      printOutCanvas(drawingCanvas);
      break;
    default:
      printf("Unrecognized command. Type h for help.\n");
			printOutCanvas(drawingCanvas);
      break;
  }
}

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
#include "free.h"
#include "load.h"

bool correctNumArgs(int argc) {
  if (argc == 3) {
    return true;
  }else if(argc > 3){
    printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.\n");
  }
  //printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.\n");
  return false;
}

bool argvInputIsValid(char* c1, char* c2) {

  if (isdigit(*c1)) {
    if(atoi(c1) < 1){
      printf("The number of rows is less than 1.\nMaking default board of 10 X 10.\n");
      return false;
    }
		if(isdigit(*c2)) {
      if(atoi(c2) < 1){
        printf("The number of columns is less than 1.\nMaking default board of 10 X 10.\n");
        return false;
      }
			return true;
		}else{
			printf("The number of columns is not an integer.\nMaking default board of 10 X 10.\n");
			return false;
		}
  }else{
		printf("The number of rows is not an integer.\nMaking default board of 10 X 10.\n");
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
  do{
    char commandLetter;

    point* erasePoint;
    line* writeLine;

    int resizeX, resizeY;

    char addChar;
    int addInt;
    bool addBool = false;

    char delChar;
    int delInt;
    bool delBool = false;

    char saveFileName[100];
    char loadFileName[100];
    printf("Enter your command: ");
    scanf(" %c", &commandLetter);
    switch (commandLetter) {
      case 'q':
        //(q)uit DONE
        free_canvas(drawingCanvas);
        exit(0);
      case 'h':
        //(h)elp DONE
        print_help();
        printOutCanvas(drawingCanvas);
        break;
      case 'w':
  			//(w)write
        writeLine = (line*)calloc(1, sizeof(line));
  			if(writeValidation(drawingCanvas, writeLine) ){
  				write_line(drawingCanvas, writeLine);
  			}
        printOutCanvas(drawingCanvas);
        free_line(writeLine);
        break;
      case 'e':
  			//(e)rase
        erasePoint = (point*)calloc(1, sizeof(point));
  			if(eraseValidation(drawingCanvas, erasePoint) ){
  				erase_char(drawingCanvas, erasePoint->x, erasePoint->y);
  			}
  			printOutCanvas(drawingCanvas);
        free(erasePoint);
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
        if(addValidation(drawingCanvas, &addChar, &addInt, &addBool) ){
  				drawingCanvas = add_to_canvas(drawingCanvas, addInt, addBool);
  			}
        printOutCanvas(drawingCanvas);
        break;
      case 'd':
  			//(d)elete
        if(delValidation(drawingCanvas, &delChar, &delInt, &delBool) ){
  				drawingCanvas = delete_from_canvas(drawingCanvas, delInt, delBool);
  			}
        printOutCanvas(drawingCanvas);
        break;
      case 's':
  			//(s)ave
        scanf(" %s", saveFileName);
        save_canvas(drawingCanvas, saveFileName);
        printOutCanvas(drawingCanvas);
        break;
      case 'l':
  			//(l)oad
        scanf(" %s", loadFileName);
        drawingCanvas = load_canvas(drawingCanvas, loadFileName);
        printOutCanvas(drawingCanvas);
        break;
      default:
        printf("Unrecognized command. Type h for help.\n");
  			printOutCanvas(drawingCanvas);
        break;
    }
  }while(true);
}

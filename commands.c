#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "commands.h"
#include "canvas.h"
#include "erase.h"

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

bool validateNumArgs_and_Int(int** arrayOfArgs, int* numArgs, int reqNumArgs, char* command){
	char buffer[100];
	//int buffer;
	int i = 0;

	while(i < 100 && (scanf(" %c", &buffer[i]) == 1)){
		printf("%d\n", i);

		if(buffer[i]=='\n'){
			break;
		}


		i++;
	}

	if(i!=reqNumArgs){
		printf("Improper %s command.\n", command);
		return false;
	}
	/*
	for(int j = 0; j< reqNumArgs; ++j){
		if( isdigit(buffer[j]) ){
			(*arrayOfArgs)[j]=atoi(buffer);
		}else{
			*numArgs = 0;
			printf("Improper %s command.\n", command);
			return false;
		}
	}
	*/


	return true;
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
	int* arrayOfArgs;
	int numArguments;

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
      printOutCanvas(drawingCanvas);
      break;
    case 'e':
			//(e)rase
			if(validateNumArgs_and_Int(&arrayOfArgs, &numArguments, 2, "erase")){
				printf("erasing");
				erase_char(drawingCanvas, arrayOfArgs[0], arrayOfArgs[1]);
			}
			printOutCanvas(drawingCanvas);
      break;
    case 'r':
			//(r)esize
      printOutCanvas(drawingCanvas);
      break;
    case 'a':
			//(a)dd
      printOutCanvas(drawingCanvas);
      break;
    case 'd':
			//(d)elete
      printOutCanvas(drawingCanvas);
      break;
    case 's':
			//(s)ave
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

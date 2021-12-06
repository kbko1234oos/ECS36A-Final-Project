#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "commands.h"
#include "canvas.h"

int main(int argc, char** argv){
	canvas* drawingCanvas = NULL;
	char blankChar = '*';

	//Read in and input validate argc/argv
	if(correctNumArgs(argc) && argvInputIsValid(*argv[1], *argv[2])){
		//make custom size canvas IF correctNumberOfArguments and argsAreInts
		makeCanvas(*drawingCanvas, atoi(argv[1]), atoi(argv[2]), blankChar);
	}else{
		//make 10x10 canvas
		makeCanvas(*drawingCanvas, 10, 10, blankChar);
	}

  //Create empty canvas and check for 2 args for custom size
	//Create and Output blank board

	//Ask for command
	askAndExecute_for_command_type();


	return 0;
}

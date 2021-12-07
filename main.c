#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "commands.h"
#include "canvas.h"

int main(int argc, char** argv){
	canvas* drawingCanvas = (canvas*)calloc(1, sizeof(canvas));;
	char blankChar = '*';

	//Read in and input validate argc/argv
	printf("1\n");
	if(correctNumArgs(argc) && argvInputIsValid(*argv[1], *argv[2])){
		//make custom size canvas IF correctNumberOfArguments and argsAreInts
		printf("1\n");
		makeCanvas(drawingCanvas, atoi(argv[1]), atoi(argv[2]), blankChar);
	}else{
		//make 10x10 canvas
		printf("1\n");
		makeCanvas(drawingCanvas, 10, 10, blankChar);
	}

  //Create empty canvas and check for 2 args for custom size
	//Create and Output blank board

	//Ask for command
	askAndExecute_for_command_type();


	return 0;
}

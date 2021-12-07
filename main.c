#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "commands.h"
#include "canvas.h"

int main(int argc, char** argv){
	canvas* drawingCanvas = (canvas*)calloc(1, sizeof(canvas));
	drawingCanvas->blankChar = '*';

	//Read in and input validate argc/argv
	if(correctNumArgs(argc) && argvInputIsValid(*argv[1], *argv[2])){
		//make canvas size customizable IF correctNumberOfArguments and argsAreInts
		drawingCanvas->numRows = atoi(argv[1]);
		drawingCanvas->numCols = atoi(argv[2]);
	}else{
		//make canvas size 10x10
		drawingCanvas->numRows = 10;
		drawingCanvas->numCols = 10;
	}
	makeCanvas(drawingCanvas);

  //Create empty canvas and check for 2 args for custom size
	//Create and Output blank board

	//Ask for command
	askAndExecute_for_command_type();


	return 0;
}

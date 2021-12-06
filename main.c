#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "commands.h"

int main(int argc, char** argv){
	//Read in and input validate argc/argv
	if(correctNumArgs(argc)&&argvInputIsValid(*argv[1], *argv[2])){
		//make custom size canvas
		makeCanvas(argv[1], argv[2]);
	}else{
		//make 10x10 canvas
		makeCanvas(10, 10);
	}

  //Create empty canvas and check for 2 args for custom size
	//Create and Output blank board

	//Ask for command
	askAndExecute_for_command_type();


	return 0;
}

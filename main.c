#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "commands.h"

int main(int argc, char** argv){
	//Read in argc
	if(correctNumArgs(argc)&&argvInputIsValid(*argv[1], *argv[2])){
		makeMatrix(argv[1], argv[2]);
		printf("making custom matrix\n");
	}else{
		makeMatrix(10, 10);
	}

  //Create empty canvas and check for 2 args for custom size
	//Create and Output blank board

	//Ask for command
	askAndExecute_for_command_type();


	return 0;
}

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include "canvas.h"
#include "erase.h"
#include "inputValidation.h"
#include "write.h"
#include "resize.h"
#include "write.h"
#include "delete.h"
#include "save.h"




#ifndef COMMANDS_H
#define COMMANDS_H
	bool correctNumArgs(int argc);
	bool argvInputIsValid(char c1, char c2);
	bool validateNumArgs_and_Int(int** arrayOfArgs, int* numArgs, int reqNumArgs, char* command);
	void print_help();
	void askAndExecute_for_command_type(canvas* drawingCanvas);

#endif

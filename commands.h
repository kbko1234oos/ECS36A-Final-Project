#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#ifndef COMMANDS_H
#define COMMANDS_H
	bool correctNumArgs(int argc);
	bool argvInputIsValid(char c1, char c2);
	void askAndExecute_for_command_type();

#endif

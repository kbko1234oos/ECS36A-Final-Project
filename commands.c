#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "commands.h"

bool correctNumArgs(int argc){
	if(argc == 3){
		return true;
	}
	return false;
}

bool argvInputIsValid(char c1, char c2){
	if( isdigit(c1) && isdigit(c2) ){
		return true;
	}
	return false;
}

void askAndExecute_for_command_type(){
		char commandLetter;
    printf("Enter your command: ");
		scanf("%c", &commandLetter);

		switch (commandLetter) {
            case 'q':
                printf("quit");
                break;
						case 'h':
                printf("help");
                break;
						case 'w':
                printf("write");
                break;
						case 'e':
                printf("erase");
                break;
						case 'r':
                printf("read");
                break;
						case 'a':
                printf("add");
                break;
						case 'd':
                printf("delete");
                break;
            case 's':
                printf("save");
                break;
						case 'l':
                printf("load");
                break;
            default:
                printf("Out of range");
                break;
        }
}

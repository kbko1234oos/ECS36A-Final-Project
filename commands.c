#include <stdlib.h>
#include <stdio.h>
#include "commands.h"

void ask_for_command_type(){
		char commandLetter;
    printf("Enter your command: ");
		scanf("%c", commandLetter);

		switch (commandLetter) {
            case 'h':
                printf("help");
                break;
            case 'w':
                printf("write");
                break;
            case 'e':
                printf("erase");
                break;
            default:
                printf("Out of range");
                break;
        }

    return input_matrix;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "commands.h"
#include "canvas.h"
#include "resize.h"
#include "add.h"
#include "write.h"
#include "erase.h"

int main(int argc, char** argv){
    canvas* drawingCanvas = (canvas*)calloc(1, sizeof(canvas));
    drawingCanvas->blankChar = '*';

    //Read in and input validate argc/argv
    if(correctNumArgs(argc) && argvInputIsValid(*argv[1], *argv[2])){
        //make canvas size customizable IF correctNumberOfArguments and argsAreInts
        drawingCanvas->numRows = atoi(argv[1]);
        drawingCanvas->numCols = atoi(argv[2]);
				//printf("Making custom board of %d X %d.\n", atoi(argv[1]), atoi(argv[2]));
    }else{
        //make canvas size 10x10
        drawingCanvas->numRows = 10;
        drawingCanvas->numCols = 10;
				//printf("Making default board of 10 X 10.\n");
    }
    makeCanvas(drawingCanvas);

  //Create empty canvas and check for 2 args for custom size
    //Create and Output blank board

    //Ask for command
    printOutCanvas(drawingCanvas);

    askAndExecute_for_command_type(drawingCanvas);



    return 0;
}

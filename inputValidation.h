#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H
	#include "inputValidation.h"
	#include "write.h"
	#include "canvas.h"
	#include "add.h"
	#include "save.h"

  bool isValidFormat(const int numArgsRead, const int numArgsNeed);
	bool eraseValidation(canvas* drawingCanvas, point* erasePoint) ;
	bool resizeValidation(canvas* drawingCanvas, int* resizeX, int* resizeY);
	bool writeValidation(canvas* drawingCanvas, line* writeLine);
	bool addValidation(canvas* drawingCanvas, char* addChar, int* addInt);
	bool delValidation(canvas* drawingCanvas, char* delChar, int* delInt);


#endif

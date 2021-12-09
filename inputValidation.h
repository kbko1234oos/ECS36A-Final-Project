#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H
	#include "inputValidation.h"
	#include "write.h"
	#include "canvas.h"


  bool isValidFormat(const int numArgsRead, const int numArgsNeed);
	bool eraseValidation(canvas* drawingCanvas, point* erasePoint) ;
	bool resizeValidation(canvas* drawingCanvas, int* resizeX, int* resizeY);
	bool writeValidation(canvas* drawingCanvas, point* erasePoint);



#endif

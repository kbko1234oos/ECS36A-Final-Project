#include <stdlib.h>
#include <stdbool.h>
#include "delete.h"
#include "canvas.h"
#include "resize.h"
#include "add.h"
#include "free.h"

canvas* delete_from_canvas(canvas* old_canvas, int delete_index, bool delete_row) {
	//Makes a new canvas with the correct size for adding a row or column
	canvas* new_canvas = (canvas*)calloc(1, sizeof(canvas));
	new_canvas->blankChar = '*';
	if (delete_row) {
		new_canvas->numRows = old_canvas->numRows - 1;
		new_canvas->numCols = old_canvas->numCols;
		makeCanvas(new_canvas);
	} else {
		new_canvas->numRows = old_canvas->numRows;
		new_canvas->numCols = old_canvas->numCols - 1;
		makeCanvas(new_canvas);
	}

	//copies the old canvas into the new canvas row by row or column by column,
	//skipping the new row/column as needed.
	if (delete_row) {
		for (int i = 0; i < new_canvas->numRows; ++i) {
	    if (i < delete_index) {
	      copy_row(old_canvas, new_canvas, i, i);
	    } else {
	      copy_row(old_canvas, new_canvas,  i + 1, i);
	    }
	  }
	} else {
		for (int i = 0; i < new_canvas->numCols; ++i) {
	    if (i < delete_index) {
	      copy_column(old_canvas, new_canvas, i, i);
	    } else {
	      copy_column(old_canvas, new_canvas, i + 1, i);
	    }
	  }
	}
	free_canvas(old_canvas);
	return new_canvas;
}

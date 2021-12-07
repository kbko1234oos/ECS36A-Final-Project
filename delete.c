#include <stdlib.h>
#include <stdbool.h>
#include "delete.h"
#include "canvas.h"
#include "resize.h"
#include "add.h"

void delete_from_canvas(canvas* old_canvas, int add_index, bool add_row) {
	//Makes a new canvas with the correct size for adding a row or column
	canvas* new_canvas = (canvas*)calloc(1, sizeof(canvas));
	if (add_row) {
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
	if (add_row) {
		for (int i = 0; i < new_canvas->numRows; ++i) {
	    if (i < add_index) {
	      copy_row(old_canvas, new_canvas, i, i);
	    } else {
	      copy_row(old_canvas, new_canvas,  i, i - 1);
	    }
	  }
	} else {
		for (int i = 0; i < new_canvas->numCols; ++i) {
	    if (i < add_index) {
	      copy_column(old_canvas, new_canvas, i, i);
	    } else {
	      copy_column(old_canvas, new_canvas, i, i - 1);
	    }
	  }
	}
}
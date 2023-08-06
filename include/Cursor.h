#pragma once
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chessman.h"
#include "defines.h"

// *                                *
// * Create the cursor              *
// * to make the function of moving *

class Cursor
{
public:
	~Cursor() {};
	void setCursorX(int x);
	void setCursorY(int y);
	int getCursorX();
	int getCursorY();
private:
	int cursorX = DEFSET_X + GRIDS_N / 2 * GRID_VALUE;
	int cursorY = DEFSET_Y + GRIDS_N / 2 * GRID_VALUE;
};

#endif
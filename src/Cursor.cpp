#include "../include/Cursor.h"

// *                                     *
// * The functions to get private values *
// * and set the values.                 *

void Cursor::setCursorX(int x) {
	this->cursorX = x;
}

void Cursor::setCursorY(int y) {
	this->cursorY = y;
}

int Cursor::getCursorX() {
	return cursorX;
}

int Cursor::getCursorY() {
	return cursorY;
}


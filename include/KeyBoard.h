#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Cursor.h"
#include "Display.h"
#include "chessman.h"
#include "ai.h"



// *                                                   *
// * This file is to realize the function of keyboard  *
// *                             *

class KeyBoard
{
public:
	KeyBoard(); 
	void showGameOverMessage(int COLOR);
	void whoIsWinner(int y, int x);
	void printChess(Display display);
	void restrictedMove(int x, int y);
	void cursorMoving(Cursor chessBoard, Display display);
	void regretChess(Display display);
private:
};

#endif
#pragma once
#ifndef CHESSMAN_H
#define CHESSMAN_H

#include "defines.h"

// *                                           *
// * Create class "chessman"                   *
// * to store the information of each chessman *

class chessman
{
public:
	void setPlaceInf(bool input);
	void setPlacedCount(int count);
	void setCoordinate(int y, int x);
	void setChessmanColor(int COLOR);

	int getX();
	int getY();
	int getCOLOR();
	int getPlacedCount();

	bool IsPlaced();
private:
	int x = 0;
	int y = 0;
	int placedCount = 0;
	int COLOR = NULLPUT;
	bool hasPlaced = false;
};

extern chessman chessPositions[GRIDS_N][GRIDS_N];
#endif
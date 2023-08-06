#pragma once
#include <cstdlib>
#include "chessman.h"
#include "defines.h"

extern int whiteChessCoordinate[2];
extern int blackChessCoordinate[2];

// *                                           *
// * Create the fake "Artificial intelligence" *
// * to play with the player                   *

class AI
{
public:
	void pointsInI(); // Initialization score for each grids.
	void setX(int x);
	void setY(int y);
	void setPoints(int x ,int y);
	void searchMaxCounts(int x,int y);
	void aiPlaying(int blackX, int blackY);
	void setMaxCounts(int maxCounts, int x, int y);
	
	int getMaxCountsX();
	int getMaxCountsY();
	int getMaxCounts();
	int defense(int x, int y);
private:
	int x;
	int y;
	int maxCounts = 0;
	int maxCounts_X;
	int maxCounts_Y;
	int points[GRIDS_N][GRIDS_N] = {0};
};

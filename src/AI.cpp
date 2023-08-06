#include "../include/AI.h"

int whiteChessCoordinate[2] = { 0 }; // ????????????????????
int blackChessCoordinate[2] = { 0 };

int max(int x, int y, int z, int i)
{
	// Find the biggest one in three numbers.
	return (((x > y) ? x : y) > z ? ((x > y) ? x : y) : z) > i ? ((x > y) ? x : y) > z ? ((x > y) ? x : y) : z : i;
}

void AI::aiPlaying(int black_X,int black_Y)
{
	pointsInI();
	setPoints(black_X, black_Y);
	searchMaxCounts(black_X, black_Y);
	int x = maxCounts_X;
	int y = maxCounts_Y;
	int random = rand() % 2 + 1;

	if (chessPositions[y][x].getPlacedCount() == 0)
		chessPositions[y][x].setChessmanColor(WHITECOLOR);
	else
	{
		y += random;
		x += random;
		if (chessPositions[y][x].getCOLOR() == NULLPUT)
			chessPositions[y][x].setChessmanColor(WHITECOLOR);
		else
			y -= 2 * random, x -= 2 * random,
			chessPositions[y][x].setChessmanColor(WHITECOLOR);
	}
    // Introduced variable placecounts to place repeated placement chessman
	chessPositions[y][x].setPlaceInf(true);
	int temp = chessPositions[y][x].getPlacedCount();
	temp++;
	chessPositions[y][x].setPlacedCount(temp);
	whiteChessCoordinate[0] = y;
	whiteChessCoordinate[1] = x;
}

int getConnectedCounts(int x, int y,int COLOR)
{
	int scores = 0;
	int horizontalCount = 1;
	int left = x - 1;

	while (left >= 0 && chessPositions[y][left].getCOLOR() == COLOR)
	{
		horizontalCount++;
		left--;
	}
	int right = x + 1;
	while (right < GRIDS_N && chessPositions[y][right].getCOLOR() == COLOR)
	{
		horizontalCount++;
		right++;
	}
	int verticalCount = 1;
	int top = y - 1;
	while (top >= 0 && chessPositions[top][x].getCOLOR() == COLOR)
	{
		verticalCount++;
		top--;
	}
	int bottom = y + 1;
	while (bottom < GRIDS_N && chessPositions[bottom][x].getCOLOR() == COLOR)
	{
		verticalCount++;
		bottom++;
	}

	int diagonalCount = 1;
	int topRightY = y - 1;
	int topRightX = x + 1;
	while (topRightY >= 0 && topRightX < GRIDS_N && chessPositions[topRightY][topRightX].getCOLOR() == COLOR)
	{
		diagonalCount++;
		topRightY--;
		topRightX++;
	}
	int bottomLeftY = y + 1;
	int bottomLeftX = x - 1;
	while (bottomLeftY < GRIDS_N && bottomLeftX >= 0 && chessPositions[bottomLeftY][bottomLeftX].getCOLOR() == COLOR)
	{
		diagonalCount++;
		bottomLeftY++;
		bottomLeftX--;
	}

	int antiDiagonalCount = 1;
	int topLeftY = y - 1;
	int topLeftX = x - 1;
	while (topLeftY >= 0 && topLeftX >= 0 && chessPositions[topLeftY][topLeftX].getCOLOR() == COLOR)
	{
		antiDiagonalCount++;
		topLeftY--;
		topLeftX--;
	}

	int bottomRightY = y + 1;
	int bottomRightX = x + 1;
	while (bottomRightY < GRIDS_N && bottomRightX < GRIDS_N && chessPositions[bottomRightY][bottomRightX].getCOLOR() == COLOR)
	{
		antiDiagonalCount++;
		bottomRightY++;
		bottomRightX++;
	}
	scores = horizontalCount + verticalCount + diagonalCount + antiDiagonalCount;
	
	if (horizontalCount >= 3 || verticalCount >= 3 || diagonalCount >= 3 || antiDiagonalCount >= 3)
		scores += 10*max(horizontalCount, verticalCount, diagonalCount, antiDiagonalCount);
	if (horizontalCount == 4 || verticalCount == 4 || diagonalCount == 4 || antiDiagonalCount == 4)
		scores = 1000;
	return scores;
}

void AI::setPoints(int x, int y)
{

	for (int i = y - 2; i < y + 2; i++)
		for (int j = x - 2; j < x + 2; j++)
		{
			if (chessPositions[i][j].getPlacedCount() == 0)
			{
				points[i][j] += getConnectedCounts(i, j, WHITECOLOR);
				points[i][j] += defense(i, j);
			}	
		}	
}

void AI::searchMaxCounts(int x, int y)
{
	int temp = getMaxCounts();
	int temp_X = 0;
	int temp_Y = 0;
	for (int i = 0; i < GRIDS_N; i++)
	{
		for (int j = 0; j < GRIDS_N; j++)
		{
			if (points[i][j] >= temp)
			{
				temp = points[i][j];
				temp_X = j;
				temp_Y = i;
			}
		}
	}
	setMaxCounts(temp, temp_X, temp_Y);
}

void AI::pointsInI()
{
	for (int i = 0; i < GRIDS_N; i++)
		for (int j = 0; j < GRIDS_N; j++)
			points[i][j] = 0;
	setMaxCounts(0, 0, 0);
}

int AI::defense(int x, int y)
{
	for (int i = y - 2; i < y + 2; i++)
	{
		for (int j = x - 2; j < x + 2; j++)
		{
			int horizontalCount = 1;
			int left = x - 1;
			while (left >= 0 && chessPositions[y][left].getCOLOR() == BLACKCOLOR)
			{
				horizontalCount++;
				left--;
			}
			int right = x + 1;
			while (right < GRIDS_N && chessPositions[y][right].getCOLOR() == BLACKCOLOR)
			{
				horizontalCount++;
				right++;
			}
			// ?§Ø?????
			int verticalCount = 1;
			int top = y - 1;
			while (top >= 0 && chessPositions[top][x].getCOLOR() == BLACKCOLOR)
			{
				verticalCount++;
				top--;
			}
			int bottom = y + 1;
			while (bottom < GRIDS_N && chessPositions[bottom][x].getCOLOR() == BLACKCOLOR)
			{
				verticalCount++;
				bottom++;
			}

			int diagonalCount = 1;
			int topRightY = y - 1;
			int topRightX = x + 1;
			while (topRightY >= 0 && topRightX < GRIDS_N && chessPositions[topRightY][topRightX].getCOLOR() == BLACKCOLOR)
			{
				diagonalCount++;
				topRightY--;
				topRightX++;
			}

			int bottomLeftY = y + 1;
			int bottomLeftX = x - 1;
			while (bottomLeftY < GRIDS_N && bottomLeftX >= 0 && chessPositions[bottomLeftY][bottomLeftX].getCOLOR() == BLACKCOLOR)
			{
				diagonalCount++;
				bottomLeftY++;
				bottomLeftX--;
			}

			int antiDiagonalCount = 1;
			int topLeftY = y - 1;
			int topLeftX = x - 1;
			while (topLeftY >= 0 && topLeftX >= 0 && chessPositions[topLeftY][topLeftX].getCOLOR() == BLACKCOLOR)
			{
				antiDiagonalCount++;
				topLeftY--;
				topLeftX--;
			}

			int bottomRightY = y + 1;
			int bottomRightX = x + 1;
			while (bottomRightY < GRIDS_N && bottomRightX < GRIDS_N && chessPositions[bottomRightY][bottomRightX].getCOLOR() == BLACKCOLOR)
			{
				antiDiagonalCount++;
				bottomRightY++;
				bottomRightX++;
			}

			if (horizontalCount >= 3 || verticalCount >= 3 || diagonalCount >= 3 || antiDiagonalCount >= 3)
				return 999;
		}
	}
}



int AI::getMaxCountsX()
{
	return maxCounts_X;
}

int AI::getMaxCountsY()
{
	return maxCounts_X;
}

int AI::getMaxCounts()
{
	return maxCounts;
}

void AI::setX(int x)
{
	this->x = x;
}

void AI::setY(int y)
{
	this->y = y;
}

void AI::setMaxCounts(int maxCounts, int x, int y)
{
	this->maxCounts = maxCounts;
	this->maxCounts_X = x;
	this->maxCounts_Y = y;
}
#pragma once

// *                                                                  *
// * This file is to store the all macro definition of this project   *
// *                                                                  *

// Define the symbol number of each color.
#define BLACKCOLOR -1
#define WHITECOLOR 1
#define NULLPUT 0
#define MOVESTRICTED 2
#define DRAW 255

// The definitions of window.
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

// The definitions of chessboard.
#define GRIDS_N 15
#define GRID_VALUE 40
#define DEFSET_X 100 // The defset of chessboard from window.
#define DEFSET_Y 100

#define HALF_GRID_VALUE (int)1/2.0*GRID_VALUE
#define BLOCKVALUE_X (DEFSET_X + (GRIDS_N - 1 ) * GRID_VALUE) // XY coordinates corresponding to each grid.
#define BLOCKVALUE_Y (DEFSET_Y + (GRIDS_N - 1 ) * GRID_VALUE)



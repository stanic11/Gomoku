#include "../include/Display.h"

// Solution to the problem that the original EasyX cannot draw transparent PNG images
void Display::putimagePNG(int  picture_x, int picture_y, IMAGE* picture)
{
	DWORD* dst = GetImageBuffer();
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture);
	int picture_width = picture->getwidth();
	int picture_height = picture->getheight();
	int graphWidth = getwidth();
	int graphHeight = getheight();
	int dstX = 0;

	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width;
			int sa = ((src[srcX] & 0xff000000) >> 24);
			int sr = ((src[srcX] & 0xff0000) >> 16);    // Get R value
			int sg = ((src[srcX] & 0xff00) >> 8);      // Get G value
			int sb = src[srcX] & 0xff;                // Get B value
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth;
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  // Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}

void Display::displayInI()
{
	loadimage(&background, _T("..\\img\\back.jpg"));
	loadimage(&blackChess, _T("..\\img\\black.png"), HALF_GRID_VALUE, HALF_GRID_VALUE);
	loadimage(&whiteChess, _T("..\\img\\white.png"), HALF_GRID_VALUE, HALF_GRID_VALUE);
	loadimage(&cursor, _T("..\\img\\cursor.png"), GRID_VALUE, GRID_VALUE);
}


void Display::displayBackground()
{
    displayInI();
	// Loading the background picture.
	loadimage(NULL, _T("..\\img\\back.jpg"));

	// Painting the chessboard.
	setlinestyle(PS_SOLID | PS_ENDCAP_SQUARE, 3);
	setlinecolor(BLACK);
	for (int i = 0; i < GRIDS_N; i++)
	{
		line(DEFSET_X, DEFSET_X + i * GRID_VALUE, DEFSET_X + 14 * GRID_VALUE, DEFSET_X + i * GRID_VALUE);
		line(DEFSET_Y + i * GRID_VALUE, DEFSET_Y, DEFSET_Y + i * GRID_VALUE, DEFSET_Y + 14 * GRID_VALUE);
	}
	setfillcolor(BLACK);

	fillcircle(DEFSET_X + 3 * GRID_VALUE, DEFSET_Y + 3 * GRID_VALUE, 5);
	fillcircle(DEFSET_X + 3 * GRID_VALUE, DEFSET_Y + 11 * GRID_VALUE, 5);
	fillcircle(DEFSET_X + 11 * GRID_VALUE, DEFSET_Y + 3 * GRID_VALUE, 5);
	fillcircle(DEFSET_X + 11 * GRID_VALUE, DEFSET_Y + 11 * GRID_VALUE, 5);

	setlinestyle(PS_SOLID | PS_ENDCAP_SQUARE, 1);

	// Draw the right text prompt bar.
	settextstyle(20, 0, _T("Microsoft Yahei Font"));
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	TCHAR text[] = _T("You are playing:");
    // Drawing the black chess.
    IMAGE blackChess;
    loadimage(&blackChess, _T("..\\img\\black.png"), 100, 100);
    putimagePNG(WINDOW_WIDTH * 0.775, WINDOW_HEIGHT * 0.315, &blackChess);

	rectangle(WINDOW_WIDTH * 0.7, WINDOW_HEIGHT * 0.2, WINDOW_WIDTH * 0.95, WINDOW_HEIGHT * 0.5);
	outtextxy(WINDOW_WIDTH * 0.75, WINDOW_HEIGHT * 0.25, text);

	// The text below the chessboard.
	TCHAR textBelowFirstLine[] = _T("Press WSAD to move the cursor.\nPress SPACE to put the chessman.\n");
    TCHAR textBelowSecondLine[] = _T("Press CTRL to reput the chessman.\nPress ESC to exit the game.\n");
	outtextxy(WINDOW_WIDTH * 0.1, WINDOW_HEIGHT * 0.875, textBelowFirstLine);
    outtextxy(WINDOW_WIDTH * 0.1, WINDOW_HEIGHT * 0.9, textBelowSecondLine);
}

// *                                     *
// * The functions to get private values *
// *                                     *

IMAGE Display::getCursorPic(){
    return cursor;
}
IMAGE Display::getWhiteChessPic() {
    return whiteChess;
}
IMAGE Display::getBlackChessPic() {
    return blackChess;
}
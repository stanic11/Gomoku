#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H
#include <easyx.h>
#include "defines.h"

// *                                                                  *
// * This file is to realize the function of painting the background  *
// * and store the address of each picture                            *                                    *

class Display
{
public:
	Display() {};
	void displayInI(); // Initialization interface
	void displayBackground();
	//void updateChessTips(Display display);	// 更新右侧提示栏
	void putimagePNG(int  picture_x, int picture_y, IMAGE* pic); // Draw a transparent PNG image
	IMAGE getCursorPic();
	IMAGE getBlackChessPic();
	IMAGE getWhiteChessPic(); 
private:
	IMAGE background;
	IMAGE blackChess;
	IMAGE whiteChess;
	IMAGE cursor;
};

#endif
#include "../include/main.h"



/*
void playmusic()
{
	mciSendString(_T("open music\\������.mp3 alias BGM"), NULL, 0, NULL);
	mciSendString(_T("play BGM repeat"), NULL, 0, NULL);
}
*/

/*
 * This project is a coursework for the second semester of the freshman year in NPU
 * This project got 85/100 points while the highest points in class is 86 points.
 * "Gomoku" is based on EasyX version 2022090, Develop with Clion.
 *                                                                                      */

Cursor cursor;
Display display;
KeyBoard keyBoard;

int main()
{
	// playmusic();
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
	// ��ʼ������
	//display.displayInI();
	display.displayBackground();
	// ����
	keyBoard.cursorMoving(cursor, display);
	system("pause");
}



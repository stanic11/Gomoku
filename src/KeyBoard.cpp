#include "../include/KeyBoard.h"

int chesscounts = 0; // ���ڼ�¼��������������Ŀ���������Ŀʱƽ��
AI Betago;

void KeyBoard::showGameOverMessage(int COLOR)
{
    // Show the game over message.
    HWND winTips = GetHWnd();
    SetWindowText(winTips, _T("Display"));
    int result = 0;
    if (COLOR == MOVESTRICTED)
    {
        MessageBox(winTips, _T("Move restricted.\nContinue or quit?"), _T("Tips"), MB_OK | MB_OKCANCEL);
        result = MessageBox(winTips, _T("Move restricted.\nContinue or quit?"), _T("Display"), MB_OK | MB_OKCANCEL);
        switch (result)
        {
            case IDOK:
                exit(0);
                break;
        }
    }
    else if (COLOR == 225)
    {
        MessageBox(winTips, _T("Game over.\nIt's a draw."), _T("Tips"), MB_OK | MB_OKCANCEL);
        result = MessageBox(winTips, _T("Game over.\nIt's a draw."), _T("Display"), MB_OK | MB_OKCANCEL);
        switch (result)
        {
            case IDOK:
                exit(0);
                break;
            default:
                break;
        }
    }
    else if (COLOR == BLACKCOLOR)
    {
        MessageBox(winTips, _T("Game over.\nBlack wins."), _T("Tips"), MB_OK | MB_OKCANCEL);
        result = MessageBox(winTips, _T("Game over.\nBlack wins."), _T("Display"), MB_OK | MB_OKCANCEL);
        switch (result)
        {
            case IDOK:
                exit(0);
                break;
            default:
                break;
        }
    }
    else
    {
        MessageBox(winTips, _T("Game over.\nContinue or quit?"), _T("Tips"), MB_OK | MB_OKCANCEL);
        result = MessageBox(winTips, _T("Game over.\nContinue or quit?"), _T("Display"), MB_OK | MB_OKCANCEL);
        switch (result)
        {
            case IDOK:
                exit(0);
                break;
            default:
                break;
        }
    }
}


void KeyBoard::whoIsWinner(int y, int x)
{
	int element = chessPositions[y][x].getCOLOR();

	int horizontalCount = 1;
	int left = x - 1;
	while (left >= 0 && chessPositions[y][left].getCOLOR() == element)
	{
		horizontalCount++;
		left--;
	}

	int right = x + 1;
	while (right < GRIDS_N && chessPositions[y][right].getCOLOR() == element)
	{
		horizontalCount++;
		right++;
	}

	if (horizontalCount >= 5)
		showGameOverMessage(element);

	int verticalCount = 1;
	int top = y - 1;
	while (top >= 0 && chessPositions[top][x].getCOLOR() == element)
	{
		verticalCount++;
		top--;
	}

	int bottom = y + 1;
	while (bottom < GRIDS_N && chessPositions[bottom][x].getCOLOR() == element)
	{
		verticalCount++;
		bottom++;
	}

	if (verticalCount >= 5)
		showGameOverMessage(element);

	int diagonalCount = 1;
	int topRightY = y - 1;
	int topRightX = x + 1;
	while (topRightY >= 0 && topRightX < GRIDS_N && chessPositions[topRightY][topRightX].getCOLOR() == element)
	{
		diagonalCount++;
		topRightY--;
		topRightX++;
	}

	int bottomLeftY = y + 1;
	int bottomLeftX = x - 1;
	while (bottomLeftY < GRIDS_N && bottomLeftX >= 0 && chessPositions[bottomLeftY][bottomLeftX].getCOLOR() == element)
	{
		diagonalCount++;
		bottomLeftY++;
		bottomLeftX--;
	}

	if (diagonalCount >= 5)
		showGameOverMessage(element);

	int antiDiagonalCount = 1;
	int topLeftY = y - 1;
	int topLeftX = x - 1;
	while (topLeftY >= 0 && topLeftX >= 0 && chessPositions[topLeftY][topLeftX].getCOLOR() == element)
	{
		antiDiagonalCount++;
		topLeftY--;
		topLeftX--;
	}

	int bottomRightY = y + 1;
	int bottomRightX = x + 1;
	while (bottomRightY < GRIDS_N && bottomRightX < GRIDS_N && chessPositions[bottomRightY][bottomRightX].getCOLOR() == element)
	{
		antiDiagonalCount++;
		bottomRightY++;
		bottomRightX++;
	}

	if (antiDiagonalCount >= 5)
		showGameOverMessage(element);
	if (chesscounts == DRAW)
		showGameOverMessage(DRAW);
}

void KeyBoard::restrictedMove(int x, int y)
{
    // Realize black chess restricted movement
	if (chessPositions[y][x - 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x - 2].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 2][x].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 3][x].getCOLOR() == BLACKCOLOR)
		showGameOverMessage(MOVESTRICTED);
	if (chessPositions[y - 1][x - 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y - 1][x + 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 1][x - 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 1][x + 1].getCOLOR() == BLACKCOLOR)
		showGameOverMessage(MOVESTRICTED);

	if (chessPositions[y][x - 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x - 2].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x - 3].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 1][x].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 2][x].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 3][x].getCOLOR() == BLACKCOLOR)
		showGameOverMessage(MOVESTRICTED);
	if (chessPositions[y][x - 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x + 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x + 2].getCOLOR() == BLACKCOLOR &&
		chessPositions[y - 1][x].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 1][x].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 2][x].getCOLOR() == BLACKCOLOR)
		showGameOverMessage(MOVESTRICTED);
	if (chessPositions[y][x - 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x - 3].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x - 4].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x - 5].getCOLOR() == WHITECOLOR &&
		chessPositions[y][x + 2].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x + 3].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x + 4].getCOLOR() == WHITECOLOR)
		showGameOverMessage(MOVESTRICTED);
	if (chessPositions[y][x - 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x - 3].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x + 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x + 3].getCOLOR() == BLACKCOLOR)
		showGameOverMessage(MOVESTRICTED);

	if (chessPositions[y][x - 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x - 2].getCOLOR() == BLACKCOLOR &&
		chessPositions[y - 1][x + 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 1][x - 1].getCOLOR() == WHITECOLOR &&
		chessPositions[y + 1][x + 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 2][x - 2].getCOLOR() == BLACKCOLOR &&
		chessPositions[y + 2][x + 2].getCOLOR() == WHITECOLOR)
		showGameOverMessage(MOVESTRICTED);

	if (chessPositions[y][x - 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x - 2].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x + 1].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x + 2].getCOLOR() == BLACKCOLOR &&
		chessPositions[y][x + 3].getCOLOR() == BLACKCOLOR)
		showGameOverMessage(MOVESTRICTED);
}

KeyBoard::KeyBoard()
{
	// Initialize chessman data
	for (int i = 0; i < GRIDS_N; i++)
	{
		for (int j = 0; j < GRIDS_N; j++)
		{
			int x = DEFSET_X + GRID_VALUE * j;
			int y = DEFSET_Y + GRID_VALUE * i;
			chessPositions[i][j].setCoordinate(y, x);
			chessPositions[i][j].setChessmanColor(NULLPUT);
		}
	}
}

void KeyBoard::printChess(Display display)
{
	IMAGE blackChess = display.getBlackChessPic();
	IMAGE whiteChess = display.getWhiteChessPic();
	for (int i = 0; i < GRIDS_N; i++)
	{
		for (int j = 0; j < GRIDS_N; j++)
		{
			if (chessPositions[i][j].IsPlaced())
			{
				if (chessPositions[i][j].getCOLOR() == BLACKCOLOR)
					display.putimagePNG(chessPositions[i][j].getX() - HALF_GRID_VALUE / 2, chessPositions[i][j].getY() - HALF_GRID_VALUE / 2, &blackChess);

				if (chessPositions[i][j].getCOLOR() == WHITECOLOR)
					display.putimagePNG(chessPositions[i][j].getX() - HALF_GRID_VALUE / 2, chessPositions[i][j].getY() - HALF_GRID_VALUE / 2, &whiteChess);
			}
		}
	}
}

void KeyBoard::cursorMoving(Cursor cursor, Display display)
{
	IMAGE CURSOR = display.getCursorPic();
	while (true)
	{
		BeginBatchDraw();

		// Press WSAD to move the cursor.
		if (GetAsyncKeyState(0x57) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000)   // Press W & Forward
			if (DEFSET_X <= cursor.getCursorX() && 
				cursor.getCursorX() <= BLOCKVALUE_X && 
				cursor.getCursorY() > DEFSET_Y && 
				cursor.getCursorY() <= BLOCKVALUE_Y)
			{
				cleardevice();
				display.displayBackground();
				int temp = cursor.getCursorY();
				temp -= GRID_VALUE;
				cursor.setCursorY(temp);
				Sleep(250);
			}
		if (GetAsyncKeyState(0x53) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000)    // Press S & Down
			if (DEFSET_X <= cursor.getCursorX() && 
				cursor.getCursorX() <= BLOCKVALUE_X && 
				cursor.getCursorY() >= DEFSET_Y && 
				cursor.getCursorY() < BLOCKVALUE_Y)
			{
				cleardevice();
				display.displayBackground();
				int temp = cursor.getCursorY();
				temp += GRID_VALUE;
				cursor.setCursorY(temp);
				Sleep(250);
			}
		if (GetAsyncKeyState(0x41) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000)    // Press A & Left
			if (DEFSET_X < cursor.getCursorX() && 
				cursor.getCursorX() <= BLOCKVALUE_X && 
				cursor.getCursorY() >= DEFSET_Y &&
				cursor.getCursorY() <= BLOCKVALUE_Y)
			{
				cleardevice();
				display.displayBackground();
				int temp = cursor.getCursorX();
				temp -= GRID_VALUE;
				cursor.setCursorX(temp);
				Sleep(250);
			}
		if (GetAsyncKeyState(0x44) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000)   // Press D & Right
			if (DEFSET_X <= cursor.getCursorX() && 
				cursor.getCursorX() < BLOCKVALUE_X && 
				cursor.getCursorY() >= DEFSET_Y && 
				cursor.getCursorY() <= BLOCKVALUE_Y)
			{
				cleardevice();
				display.displayBackground();
				int temp = cursor.getCursorX();
				temp += GRID_VALUE;
				cursor.setCursorX(temp);
				Sleep(250);
			}

		// ��������
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			// �����º��壬AI�Զ��°���
			int i = (cursor.getCursorY() - DEFSET_Y) / GRID_VALUE;
			int j = (cursor.getCursorX() - DEFSET_X) / GRID_VALUE;
			chessPositions[i][j].setPlaceInf(true);
			if (chessPositions[i][j].getPlacedCount() == 0)
			{
				// ��ֹ���ӱ�֮����õ����Ӹ��ǣ��������placedcount�����ô���������>1˵��λ���ظ�����������
				chessPositions[i][j].setChessmanColor(BLACKCOLOR);
				blackChessCoordinate[0] = i, blackChessCoordinate[1] = j;
				restrictedMove(j, i);	// �������
				// ���¸�λ�õ����ӷ��ô���
				int temp = chessPositions[i][j].getPlacedCount();
				temp++;
				chessPositions[i][j].setPlacedCount(temp);
				chesscounts++;
				// �жϺ����Ƿ�ʤ��
				whoIsWinner(i, j);
				// �� AI �°���
				Betago.aiPlaying(j, i);
				
				chesscounts++;
				// �жϰ����Ƿ�ʤ��
				if(chessPositions[Betago.getMaxCountsY()][Betago.getMaxCountsX()].getPlacedCount()==1)
					whoIsWinner(Betago.getMaxCountsY(), Betago.getMaxCountsX());
			}
			printChess(display);
			Sleep(250);
		}

		// �˳���Ϸ
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			exit(0);
		if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
			regretChess(display);
		//display.updateChessTips(display);
		display.putimagePNG(cursor.getCursorX() - HALF_GRID_VALUE, cursor.getCursorY() - HALF_GRID_VALUE, &CURSOR);
		printChess(display);
		EndBatchDraw();
	}
}




void KeyBoard::regretChess(Display display)
{
	chessPositions[blackChessCoordinate[0]][blackChessCoordinate[1]].setChessmanColor(NULLPUT);
	chessPositions[whiteChessCoordinate[0]][whiteChessCoordinate[1]].setChessmanColor(NULLPUT);
	
	chessPositions[blackChessCoordinate[0]][blackChessCoordinate[1]].setPlacedCount(0);
	chessPositions[whiteChessCoordinate[0]][whiteChessCoordinate[1]].setPlacedCount(0);
	cleardevice();
	display.displayBackground();
	printChess(display);
}
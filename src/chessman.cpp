#include "../include/chessman.h"

chessman chessPositions[GRIDS_N][GRIDS_N];

int chessman::getCOLOR(){
    return this->COLOR;
}

int chessman::getX(){
    return this->x;
}

int chessman::getY(){
    return this->y;
}

int chessman::getPlacedCount() {
    return this->placedCount;
}

void chessman::setCoordinate(int y, int x){
	this->x = x;
	this->y = y;
}

void chessman::setPlacedCount(int count) {
	this->placedCount = count;
}

void chessman::setChessmanColor(int COLOR){
	this->COLOR = COLOR;
}

void chessman::setPlaceInf(bool input){
	this->hasPlaced = input;
}

bool chessman::IsPlaced() {
	if (this->COLOR != NULLPUT)
		return true;
	else return false;
}

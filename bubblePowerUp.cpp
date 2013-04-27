#include "bubblePowerUp.h"
BubblePowerUp:: BubblePowerUp(int x, int y, QPixmap *pixmap) : GameItem(x,y,pixmap) {
	vx_ = 1;
	vy_ = 0;
}

BubblePowerUp:: ~BubblePowerUp(){

}

void BubblePowerUp:: act(){

}

void BubblePowerUp:: move(){

}

void BubblePowerUp:: setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

#include "bubblePowerUp.h"
BubblePowerUp:: BubblePowerUp(int x, int y, QPixmap *pixmap) : GameItem(x,y,pixmap) {
	vx_ = -1;
	vy_ = -1;
	counter_ = 0;
}

BubblePowerUp:: ~BubblePowerUp(){

}

void BubblePowerUp:: act(){
	counter_++;
	setPos(x() + vx_*gameSpeed_, y() + vy_*gameSpeed_);
	
	if(counter_%200 == 0){
		vy_*= -1;
	}
}

void BubblePowerUp:: setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

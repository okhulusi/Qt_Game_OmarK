#include "clamPowerUp.h"

ClamPowerUp:: ClamPowerUp(int x, int y, QPixmap *pixmap) : GameItem(x,y,pixmap){
	vx_ = -1;
	vy_ = -2;
	counter_ = 0;
	type_ = "Clam";
}

ClamPowerUp:: ~ClamPowerUp(){

}

void ClamPowerUp:: act(){
	counter_++;
	if(counter_ > 400){
		vx_ = -1;
	} else if(counter_ > 200){
		vx_ = 1;
	}
	
	if(counter_%100 == 0){
		vy_*=-1;
	}
	setPos(x() + vx_*gameSpeed_, y() + vy_*gameSpeed_);
}

void ClamPowerUp::setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

string ClamPowerUp:: getType(){
	return type_;
}

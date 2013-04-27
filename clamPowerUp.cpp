#include "clamPowerUp.h"

ClamPowerUp:: ClamPowerUp(int x, int y, QPixmap *pixmap) : GameItem(x,y,pixmap){
	vx_ = 1;
	vy_ = 1;
	
	type_ = "Clam";
}

ClamPowerUp:: ~ClamPowerUp(){

}

void ClamPowerUp:: act(){
	setPos(x() + vx_*gameSpeed_, y() + vy_*gameSpeed_);
}

void ClamPowerUp::setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

string ClamPowerUp:: getType(){
	return type_;
}

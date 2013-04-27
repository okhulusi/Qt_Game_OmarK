#include "clamPowerUp.h"

ClamPowerUp:: ClamPowerUp(int x, int y, QPixmap *pixmap) : GameItem(x,y,pixmap){
	vx_ = 1;
	vy_ = 1;
}

ClamPowerUp:: ~ClamPowerUp(){

}

void ClamPowerUp:: act(){
	
}

void ClamPowerUp::setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

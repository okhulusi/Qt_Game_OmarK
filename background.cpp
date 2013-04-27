#include "background.h"

Background:: Background(int x, int y, QPixmap *pixmap) : GameItem(x, y, pixmap){
	vx_ = -1;
	vy_ = 0;
	
	type_ = "Background";
	setZValue(-1);
}

Background :: ~Background(){

}

void Background:: setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}
void Background:: act(){
	setPos(x() +vx_,y() + vy_);
}

string Background:: getType(){
	return type_;
}

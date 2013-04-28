
#include "shark.h"

using namespace std;

Shark:: Shark(int x, int y, QPixmap *pixmap) : GameItem(x, y, pixmap){
	vx_ = -1;
	vy_ = 0;
	counter_ = 0;
	moving_ = false;
	
	type_ = "Shark";
}

Shark:: ~Shark(){
}

void Shark:: act(){
	counter_++;
	if(counter_ > 3000){
		moving_ = true;
		setPos(x() + vx_, y() + vy_);
	}
}

void Shark::setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

string Shark:: getType(){
	return type_;
}

bool Shark:: isMoving(){
	return moving_;
}


#include "flounder.h"

using namespace std;

Flounder:: Flounder(int x, int y, QPixmap *pixmap, Player *player) : GameItem(x, y, pixmap){
	player_ = player;
	vx_ = -1;
	
	if(player->y()-y > 0){
		vy_ = 1;
	} else if(player->y()-y < 0){
		vy_ = -1;
	} else{
		vy_ = 0;
	}
	
	yDistToMove_ = abs(player->y() - y);
	counter_ = 0;
	moving_ = false;
	
	type_ = "Flounder";
}

Flounder:: ~Flounder(){
}

void Flounder:: act(){
	counter_++;
	if(counter_ > 200){
		moving_ = true;
		if(counter_%(450/yDistToMove_) == 0){
			setPos(x() + vx_, y() + vy_);
		} else{
			setPos(x() + vx_, y());
		}
	}
}

void Flounder::setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

string Flounder:: getType(){
	return type_;
}

bool Flounder:: isMoving(){
	return moving_;
}

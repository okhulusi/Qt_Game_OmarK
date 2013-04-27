
#include "shark.h"

using namespace std;

Shark:: Shark(int x, int y, QPixmap *pixmap) : GameItem(x, y, pixmap){
	vx_ = 2;
	vy_ = 2;
}

Shark:: ~Shark(){
}

void Shark:: act(){
	attack(10); 
}

void Shark:: attack(int speed){

}

void Shark::setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}


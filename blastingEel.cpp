#include "blastingEel.h"

using namespace std;

BlastingEel:: BlastingEel(int x, int y, QPixmap *pixmap) : GameItem(x,y,pixmap){
	vx_ = 0;
	vy_ = 2;
	counter_ = 0;
	
	type_ = "BlastingEel";
}

BlastingEel:: ~BlastingEel(){

}

void BlastingEel:: act(){
	if(counter_%1000 == 0){
		vy_*=-1;
	}
	if(counter_>3000){
		//emit signal
	}
	setPos(x() + vx_, y() + vy_);
	attack(0, 10, 10, 500);
}

void BlastingEel:: attack(int waitTime, int speed, int numBlasts, int blastInterval){

}

void BlastingEel:: setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

string BlastingEel:: getType(){
	return type_;
}


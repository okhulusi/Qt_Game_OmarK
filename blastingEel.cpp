#include "blastingEel.h"

using namespace std;

BlastingEel:: BlastingEel(int x, int y, QPixmap *pixmap) : GameItem(x,y,pixmap){
	vx_ = 2;
	vy_ = 2;
}

BlastingEel:: ~BlastingEel(){

}

void BlastingEel:: act(){
	attack(0, 10, 10, 500);
}

void BlastingEel:: attack(int waitTime, int speed, int numBlasts, int blastInterval){

}

void BlastingEel:: setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

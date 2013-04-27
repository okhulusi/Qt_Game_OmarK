#include "blastingEel.h"

using namespace std;

BlastingEel:: BlastingEel(QPixmap *pixmap) : GameItem(pixmap){
	vx_ = 2;
	vy_ = 2;
}

BlastingEel:: ~BlastingEel(){

}

void BlastingEel:: act(int delayTime){
	attack(delayTime, 10, 10, 500);
}

void BlastingEel:: attack(int waitTime, int speed, int numBlasts, int blastInterval){

}

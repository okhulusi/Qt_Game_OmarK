
#include "shark.h"

using namespace std;

Shark:: Shark(QPixmap *pixmap) : GameItem(pixmap){
	vx_ = 2;
	vy_ = 2;
}

Shark:: ~Shark(){
}

void Shark:: act(int delayTime){
	attack(delayTime, 10); 
}

void Shark:: attack(int waitTime, int speed){

}


#include "floatingMine.h"

using namespace std;

FloatingMine:: FloatingMine(int x, int y, QPixmap *pixmap) : GameItem(x,y,pixmap){
	vx_ = 1;
	vy_ = 1;
}

FloatingMine:: ~FloatingMine(){

}

void FloatingMine:: act(){
	
}

void FloatingMine:: MousePressedEvent(QGraphicsSceneMouseEvent *e){

}

void FloatingMine:: setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

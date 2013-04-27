#include "floatingMine.h"

using namespace std;

FloatingMine:: FloatingMine(QPixmap *pixmap) : GameItem(pixmap){
	vx_ = 1;
	vy_ = 1;
}

FloatingMine:: ~FloatingMine(){

}

void FloatingMine:: act(int delayTime){
	
}

void FloatingMine:: MousePressedEvent(QGraphicsSceneMouseEvent *e){

}

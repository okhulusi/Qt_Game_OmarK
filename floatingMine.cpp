#include "floatingMine.h"

using namespace std;

FloatingMine:: FloatingMine(int x, int y, QPixmap *pixmap) : GameItem(x,y,pixmap){
	vx_ = -1;
	vy_ = 0;
}

FloatingMine:: ~FloatingMine(){

}

void FloatingMine:: act(){
	counter_++;
	if(counter_%10 == 0){
		setPos(x() + vx_*gameSpeed_, y() + vy_*gameSpeed_);
	}
}

void FloatingMine:: mousePressEvent(QGraphicsSceneMouseEvent *event){
	if(event->button() == Qt::LeftButton){
		event = event;
		emit minePressed(true);
	}
}

void FloatingMine:: setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

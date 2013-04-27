#include "gameItem.h"

GameItem:: GameItem(QPixmap *pixmap){
	vx_ = 0;
	vy_ = 0;
	setPixmap(*pixmap);
}

GameItem:: ~GameItem(){
	
}

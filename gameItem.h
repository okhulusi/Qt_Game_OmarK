#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include <QPixMapItem>
class GameItem : public QPixMapItem {
	public:
		virtual void act(int delayTime) = 0;
		
		int getX();
		void setX();
		int getY();
		void setY();
	private:
		int x_;
		int y_;
};

int GameItem:: getX(){
	return x_;
}

void GameItem:: setX(int x){
	x_ = x;
}

int GameItem:: getY(){
	return y_;
}

int GameItem:: setY(int y){
	y_ = y;
}
#endif

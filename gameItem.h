#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include <QtGui>

class GameItem : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
	public:
		GameItem(int x, int y, QPixmap *pixmap);
		~GameItem();
		virtual void act() = 0;
		virtual void setSpeed(int gameSpeed) = 0;
	
	protected:
		int gameSpeed_;
		int vx_;
		int vy_;	
};
#endif

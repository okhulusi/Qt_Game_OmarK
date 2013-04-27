#ifndef FLOATING_MINE_H
#define FLOATING_MINE_H

#include "gameItem.h"
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
class FloatingMine: public GameItem {
	public:
		FloatingMine(int x, int y, QPixmap *pixmap);
		~FloatingMine();
		void act();
		void MousePressedEvent(QGraphicsSceneMouseEvent *e);
		void setSpeed(int gameSpeed);
	private:
};
#endif



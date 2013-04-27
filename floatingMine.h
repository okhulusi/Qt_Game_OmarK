#ifndef FLOATING_MINE_H
#define FLOATING_MINE_H

#include "gameItem.h"
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
class FloatingMine: public GameItem {
	public:
		FloatingMine(QPixmap *pixmap);
		~FloatingMine();
		void act(int delayTime);
		void MousePressedEvent(QGraphicsSceneMouseEvent *e);
	private:
};
#endif



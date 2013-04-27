#ifndef FLOATING_MINE_H
#define FLOATING_MINE_H

#include "gameItem.h"
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
class FloatingMine: public GameItem {
	Q_OBJECT
	public:
		FloatingMine(int x, int y, QPixmap *pixmap);
		~FloatingMine();
		void act();
		void setSpeed(int gameSpeed);
		string getType();
		
	protected:
		void mousePressEvent(QGraphicsSceneMouseEvent *event);
	signals:
		void minePressed(bool);	
	private:
		int counter_;
};
#endif



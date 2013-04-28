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
		int getID();
		void setID(int);
		bool isReadyToExplode();
		bool isDoneExploding();
		void setIsDoneExploding(bool);
		
	protected:
		void mousePressEvent(QGraphicsSceneMouseEvent *event);
	signals:
		void minePressed(FloatingMine*);	
	private:
		int counter_;
		int id_;
		bool readyToExplode_;
		bool doneExploding_;
};
#endif



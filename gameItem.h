#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
class GameItem : public QObject, QGraphicsPixmapItem {
	Q_OBJECT
	public:
		GameItem(QPixmap *pixmap);
		~GameItem();
		virtual void act(int delayTime) = 0;
	
	protected:
		int vx_;
		int vy_;
		
		
};
#endif

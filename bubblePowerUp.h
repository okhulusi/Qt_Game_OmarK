#ifndef BUBBLE_POWERUP_H
#define BUBBLE_POWERUP_H

#include "gameItem.h"
#include <QPixmap>
class BubblePowerUp : public GameItem {
	public:
		BubblePowerUp(QPixmap *pixmap);
		~BubblePowerUp();
		void act(int delayTime);
		void move();
		
	private:
};
#endif


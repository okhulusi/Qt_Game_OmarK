#ifndef BUBBLE_POWERUP_H
#define BUBBLE_POWERUP_H

#include "gameItem.h"
#include <QPixmap>
class BubblePowerUp : public GameItem {
	public:
		BubblePowerUp(int x, int y, QPixmap *pixmap);
		~BubblePowerUp();
		void act();
		void move();
		void setSpeed(int gameSpeed);
		
	private:
		bool velocitySwitch_;
		int counter_;
};
#endif


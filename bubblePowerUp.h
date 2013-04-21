#ifndef BUBBLE_POWERUP_H
#define BUBBLE_POWERUP_H

#include "gameItem.h"

class BubblePowerUp : public GameItem {
	public:
		BubblePowerUp();
		~BubblePowerUp();
		void act(int delayTime);
		
	private:
		int x_;
		int y_;
};
#endif

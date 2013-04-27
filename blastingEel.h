
#ifndef BLASTING_EEL_H
#define BLASTING_EEL_H

#include "gameItem.h"

class BlastingEel : public GameItem {

	public:
		BlastingEel(QPixmap *pixmap);
		~BlastingEel();
		void act(int delayTime);
		void attack(int waitTime, int speed, int numBlasts, int blastInterval);
		
	private:
};
#endif


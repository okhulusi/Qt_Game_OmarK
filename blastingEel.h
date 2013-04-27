
#ifndef BLASTING_EEL_H
#define BLASTING_EEL_H

#include "gameItem.h"
#include "eelBlast.h"

class BlastingEel : public GameItem {

	public:
		BlastingEel(int x, int y, QPixmap *pixmap);
		~BlastingEel();
		void act();
		void attack(int waitTime, int speed, int numBlasts, int blastInterval);
		void setSpeed(int gameSpeed);
		string getType();
		
	private:
		int counter_;
		string type_;
};
#endif


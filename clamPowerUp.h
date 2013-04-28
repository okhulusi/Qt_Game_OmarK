
#ifndef CLAM_POWERUP_H
#define CLAM_POWERUP_H

#include "gameItem.h"
#include <QPixmap>
class ClamPowerUp : public GameItem {
	public:
		ClamPowerUp(int x, int y, QPixmap *pixmap);
		~ClamPowerUp();
		void act();
		void setSpeed(int gameSpeed);
		string getType();
		
	private:
		int counter_;
};	
#endif


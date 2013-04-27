
#ifndef CLAM_POWERUP_H
#define CLAM_POWERUP_H

#include "gameItem.h"
#include <QPixmap>
class ClamPowerUp : public GameItem {
	public:
		ClamPowerUp(QPixmap *pixmap);
		~ClamPowerUp();
		void act(int delayTime);
		
	private:
};
#endif


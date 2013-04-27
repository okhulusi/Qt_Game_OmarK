
#ifndef SHARK_H
#define SHARK_H

#include "gameItem.h"

using namespace std;

class Shark : public GameItem{

	public:
		Shark(QPixmap *pixmap);
		~Shark();
		void act(int delayTime);
		void attack(int waitTime, int speed);
	
	private:
		
};
#endif


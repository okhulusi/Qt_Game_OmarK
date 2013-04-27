
#ifndef SHARK_H
#define SHARK_H

#include "gameItem.h"

using namespace std;

class Shark : public GameItem{

	public:
		Shark(int x, int y, QPixmap *pixmap);
		~Shark();
		void act();
		void setSpeed(int);
		string getType();
	
	private:
		int counter_;
		
};
#endif


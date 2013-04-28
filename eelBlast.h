
#ifndef BLAST_H
#define BLAST_H

#include "gameItem.h"

class Blast : public GameItem {

	public:
		Blast(int x, int y, QPixmap *pixmap);
		~Blast();
		void act();
		void setSpeed(int gameSpeed);
		string getType();
		
	private:
};
#endif


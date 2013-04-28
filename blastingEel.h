
#ifndef BLASTING_EEL_H
#define BLASTING_EEL_H

#include "gameItem.h"
#include "eelBlast.h"

class BlastingEel : public GameItem {
	Q_OBJECT
	public:
		BlastingEel(int x, int y, QPixmap *pixmap);
		~BlastingEel();
		void act();
		void setSpeed(int gameSpeed);
		string getType();
	
	signals:
		void firing(int, int);
	private:
		int counter_;
		string type_;
};
#endif


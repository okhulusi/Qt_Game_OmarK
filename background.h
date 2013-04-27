#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gameItem.h"
#include <QPixmap>

class Background : public GameItem{
	public:
	Background(int x, int y, QPixmap *pixmap);
	~Background();
	void setSpeed(int);
	void act();
	string getType();
	
	private:
};
#endif 

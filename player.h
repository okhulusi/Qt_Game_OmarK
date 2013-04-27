
#ifndef PLAYER_H
#define PLAYER_H

#include "gameItem.h"
#include <QtGui>
#include <QKeyEvent>

using namespace std;

class Player : public GameItem{

	public:
		Player(int x, int y, QPixmap *pixmap);
		~Player();
		void act();
		void setSpeed(int);
		int getLives();
		
		void addLife();
		void loseLife();
		bool isDead();
		void bubbleTime();
		
	void keyPressEvent(QKeyEvent *e);
	void keyReleaseEvent(QKeyEvent *e);
	
	private:
		int counter_;
		int imageNum_;
		int gameSpeed_;
		
		int lives_;
		bool invincible_;
		
};
#endif

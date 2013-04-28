
#ifndef PLAYER_H
#define PLAYER_H

#include "gameItem.h"
#include <QtGui>
#include <QKeyEvent>

using namespace std;

class Player : public GameItem{
	Q_OBJECT
	public:
		Player(int x, int y, QPixmap *pixmap);
		~Player();
		void act();
		void setSpeed(int);
		int getLives();
		
		string getType();
		
		void addLife();
		void loseLife();
		bool isInvincible();
		void startInvincibility();
		bool isDead();
		void bubbleTime();
		
	void keyPressEvent(QKeyEvent *e);
	void keyReleaseEvent(QKeyEvent *e);
	
	signals:
		void bubbleTimeOver();
		
	public slots:
		void stopInvincibility();
	
	private:
		int counter_;
		int imageNum_;
		int gameSpeed_;
		
		int lives_;
		bool invincible_;
		bool bubbleInvincibility_;
		
};
#endif

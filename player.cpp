
#include "player.h"

using namespace std;

Player:: Player(int x, int y, QPixmap *pixmap) : GameItem(x, y, pixmap){
	vx_ = 0;
	vy_ = 0;
	
	counter_ = 0;
	imageNum_ = 1;
	
	lives_ = 3;
	invincible_  = false;
}

Player:: ~Player(){
}

int Player:: getLives(){
	return lives_;
}

void Player:: bubbleTime(){
	invincible_ = true;
}

void Player:: addLife(){
	lives_++;
}

void Player::loseLife(){
	lives_--;
}

bool Player:: isDead(){
	if(lives_ <= 0){
		return true;
	}
	
	return false;
}

void Player:: act(){
	counter_++;
}

void Player::setSpeed(int gameSpeed){
	gameSpeed_ = gameSpeed;
}

void Player:: keyPressEvent(QKeyEvent *e){
	if(e->key() == Qt::Key_W){
		if(y() >= 30){
			setPos(x(), y() - 50);
		}
	} else if(e->key() == Qt::Key_S){
		if(y() <= 350){
			setPos(x(), y() + 50);
		}
	}
}
void Player:: keyReleaseEvent(QKeyEvent *e){
}
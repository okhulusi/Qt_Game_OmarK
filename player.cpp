
#include "player.h"
#include <iostream>

using namespace std;

Player:: Player(int x, int y, QPixmap *pixmap) : GameItem(x, y, pixmap){
	vx_ = 0;
	vy_ = 0;
	
	counter_ = 0;
	imageNum_ = 1;
	
	lives_ = 3;
	invincible_  = false;
	bubbleInvincibility_ = false;
	
	type_ = "Player";
}

Player:: ~Player(){
}

int Player:: getLives(){
	return lives_;
}

void Player:: bubbleTime(){
	if(invincible_ == false){
	cout << "BUBBLE TIME" << endl;
		bubbleInvincibility_ = true;
		startInvincibility();
	}
}

void Player:: startInvincibility(){
	if(invincible_ == false){
		invincible_ = true;
		counter_ = 0;
	}
}

void Player:: stopInvincibility(){
	cout << "Bubble Time Over." << endl;
	invincible_ = false;
	bubbleInvincibility_ = false;
	emit bubbleTimeOver();
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
	if(bubbleInvincibility_ == false && counter_ > 1000 && invincible_ == true){
		stopInvincibility();
	} else if(bubbleInvincibility_ == true && counter_ > 10000 && invincible_ == true){
		stopInvincibility();
	}
}

bool Player::isInvincible(){
	return invincible_;
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

string Player:: getType(){
	return type_;
}

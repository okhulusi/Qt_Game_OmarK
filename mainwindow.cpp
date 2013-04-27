#include <QtGui/QApplication>
#include "mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::~MainWindow(){

}

MainWindow::MainWindow(){
	itemVec = new vector<GameItem*>();
	counter_ = 0;
	gameSpeed_ = 1;
	scrollSwitch_ = true;
	gameStarted = false;
	
	timer = new QTimer();
	timer->setInterval(1);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	
	mainLayout = new QGridLayout();
	scene = new QGraphicsScene(0, 0, 500, 500);
	view = new QGraphicsView(scene);
	
	view->setFixedSize(505, 505);
	view->setWindowTitle("Under the Deep Blue Sea");
	
	style = new QPlastiqueStyle();
	qApp->setStyle(style);
	
	startMenuLayout = new QVBoxLayout();
	
	nameLabel = new QLabel("Enter Your Name Below!");
	startMenuLayout->addWidget(nameLabel);
	nameField = new QLineEdit();
	startMenuLayout->addWidget(nameField);
	
	//Start Button
	startButton = new QPushButton();
	startButton->setText("Start Game");
	connect(startButton, SIGNAL(clicked()), this, SLOT(handleStartButton()));
	startMenuLayout->addWidget(startButton); 
	
	//Pause Button
	pauseButton = new QPushButton();
	pauseButton->setText("Pause Button");
	connect(pauseButton, SIGNAL(clicked()), this, SLOT(handlePauseButton()));
	startMenuLayout->addWidget(pauseButton);
	
	//Quit Button
	quitButton = new QPushButton();
	quitButton->setText("Quit Game");
	connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	startMenuLayout->addWidget(quitButton);
	
	//background
	backgroundPixmap = new QPixmap("./GamePictures/Background.png");
	*backgroundPixmap = backgroundPixmap->scaled(500, 500);
	background = new Background(0,0, backgroundPixmap);
	background2 = new Background(500, 0, backgroundPixmap);
	scene->addItem(background);
	scene->addItem(background2);
	itemVec->push_back(background);
	itemVec->push_back(background2);
	
	mainLayout->addLayout(startMenuLayout, 0, 50, 10, 10);
	setLayout(mainLayout);	
	mainLayout->addWidget(view, 0, 0, 50, 50);
	
	setFocus();
}

void MainWindow:: keyPressEvent(QKeyEvent *e){
	if(gameStarted){
		player->keyPressEvent(e);
	}
}

void MainWindow:: handleStartButton(){
	username = nameField->text();
	timer->start();
	
	QPixmap *playerPixmap = new QPixmap("./GamePictures/Mermaid/Mermaid1.png");
	player = new Player(0,200,playerPixmap);
	scene->addItem(player);
	itemVec->push_back(player);
	
	QPixmap *sharkPixmap = new QPixmap("./GamePictures/Shark/Shark3.png");
	Shark *shark = new Shark(450, 0, sharkPixmap);
	scene->addItem(shark);
	itemVec->push_back(shark);
	
	QPixmap *bubblePixmap = new QPixmap("./GamePictures/Bubble/Bubble.png");
	*bubblePixmap = bubblePixmap->scaled(75, 75);
	BubblePowerUp *bubble = new BubblePowerUp(450, 250, bubblePixmap);
	scene->addItem(bubble);
	itemVec->push_back(bubble);
	
	QPixmap *minePixmap = new QPixmap("./GamePictures/Mine/Mine.png");
	*minePixmap = minePixmap->scaled(75, 75);
	FloatingMine *mine = new FloatingMine(450, 300, minePixmap);
	scene->addItem(mine);
	itemVec->push_back(mine);
	
	gameStarted = true;
}

void MainWindow:: handlePauseButton(){
	if(timer->isActive()){
		timer->stop();
	} else {
		timer->start();
	}
}

void MainWindow:: scrollBackground(){
	if(counter_%(500/gameSpeed_) == 0 && scrollSwitch_){
		background->setPos(500, 0);
		scrollSwitch_ = false;
	} else if(counter_%(500/gameSpeed_) == 0 && !scrollSwitch_){
		background2->setPos(500,0);
		scrollSwitch_ = true;
	}
}

void MainWindow:: handleTimer(){
	counter_++;
	scrollBackground();
	
//	if(counter_%10000 == 0){
//		gameSpeed_++;
//	}
	for(unsigned int i = 0; i < itemVec->size(); i++){
		string s = (*itemVec)[i]->getType();
		
		(*itemVec)[i]->setSpeed(gameSpeed_);
		(*itemVec)[i]->act();
		
		if(s == "Player"){
			controlPlayer(dynamic_cast<Player*>((*itemVec)[i]));
		} else if(s == "Shark"){
			controlShark(dynamic_cast<Shark*>((*itemVec)[i]));
		} else if(s == "BlastingEel"){
			controlEel(dynamic_cast<BlastingEel*>((*itemVec)[i]));
		} else if (s == "Blast"){
			controlEelBlast(dynamic_cast<Blast*>((*itemVec)[i]));
		} else if(s == "Mine"){
			controlMine(dynamic_cast<FloatingMine*>((*itemVec)[i]));
		} else if(s == "Clam"){
			controlClam(dynamic_cast<ClamPowerUp*>((*itemVec)[i]));
		} else if(s == "Bubble"){
			controlBubble(dynamic_cast<BubblePowerUp*>((*itemVec)[i]));
		} else{}
		//cout << "Type: " << s << endl;
	}
	score+=1;
}

void MainWindow:: controlPlayer(Player *player){
	for(unsigned int i = 0; i < itemVec->size(); i++){
		if(player->isDead()){
			for(unsigned int j = 0; j < itemVec->size(); j++){
				delete (*itemVec)[i];
				//YOU LOSE
			}
			return;
		}
		
		if((*itemVec)[i]->getType() != "Background" && player->collidesWithItem((*itemVec)[i])){
			if((*itemVec)[i]->getType() == "Bubble"){
				controlBubble(dynamic_cast<BubblePowerUp*>((*itemVec)[i]));
			} else if((*itemVec)[i]->getType() == "Clam"){
				controlClam(dynamic_cast<ClamPowerUp*>((*itemVec)[i]));
			} else if((*itemVec)[i]->getType() == "Shark"){
				if(!(player->isInvincible())){
					player->loseLife();
					player->startInvincibility();
				}
			}
		}
	}
	//cout << "Player Lives: " << player->getLives() << endl;
}

void MainWindow:: controlShark(Shark *shark){
}

void MainWindow:: controlEel(BlastingEel *eel){

}

void MainWindow:: controlEelBlast(Blast *blast){

}
void MainWindow:: controlMine(FloatingMine *mine){

}

void MainWindow:: controlClam(ClamPowerUp *clam){
	player->addLife();
}

void MainWindow:: controlBubble(BubblePowerUp *bubble){
	//player->bubbleTime();
}

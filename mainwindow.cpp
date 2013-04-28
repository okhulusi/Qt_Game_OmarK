#include <QtGui/QApplication>
#include "mainwindow.h"
#include <iostream>
#include <cmath>

using namespace std;

MainWindow::~MainWindow(){

}

MainWindow::MainWindow(){
	srand(time(NULL));
	
	itemVec = new vector<GameItem*>();
	counter_ = 0;
	gameSpeed_ = 1;
	score_ = 0;
	scoreBox = new QLabel();
	scoreLabel = new QLabel("SCORE:");
	scoreBox->setText(QString::number(score_));
	
	scrollSwitch_ = true;
	gameStarted = false;
	gamePaused = false;
	
	timer = new QTimer();
	timer->setInterval(1);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	
	mainLayout = new QGridLayout();
	scene = new QGraphicsScene(0, 0, 500, 500);
	view = new QGraphicsView(scene);
	//startMenuLayout->addWidget(scoreLabel);
	//startMenuLayout->addWidget(scoreBox);
	mainLayout->addWidget(scoreLabel, 10, 50, 10, 10);
	mainLayout->addWidget(scoreBox, 15, 50, 10, 10);
	
	view->setFixedSize(505, 505);
	view->setWindowTitle("Under the Deep Blue Sea");
	
	style = new QPlastiqueStyle();
	qApp->setStyle(style);
	
	startMenuLayout = new QVBoxLayout();
	
	nameLabel = new QLabel("Enter Your Name Below!");
	startMenuLayout->addWidget(nameLabel);
	nameField = new QLineEdit();
	startMenuLayout->addWidget(nameField);
	usernameDisplay = new QLabel(nameField->text());
	startMenuLayout->addWidget(usernameDisplay);
	
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
	if(gameStarted && !gamePaused && !player->isDead()){
		player->keyPressEvent(e);
	}
}

void MainWindow:: generateRandomItem(){
	int random = rand()%50;
	int randomYSharkLoc = rand()%425;
	int randomYBubbleLoc = rand()%425;
	int randomYMineLoc = rand()%425;
	int randomYClamLoc = rand()%425;
	int randomYEelLoc = rand()%300;
	if(random <= 20){
		QPixmap *sharkPixmap = new QPixmap("./GamePictures/Shark/Shark3.png");
		Shark *shark = new Shark(450, randomYSharkLoc, sharkPixmap);
		scene->addItem(shark);
		itemVec->push_back(shark);
	} else if(random == 21){
		QPixmap *bubblePixmap = new QPixmap("./GamePictures/Bubble/Bubble.png");
		*bubblePixmap = bubblePixmap->scaled(150, 150);
		BubblePowerUp *bubble = new BubblePowerUp(450, randomYBubbleLoc, bubblePixmap);
		scene->addItem(bubble);
		itemVec->push_back(bubble);
	} else if(random <= 36){
		QPixmap *minePixmap = new QPixmap("./GamePictures/Mine/Mine.png");
		*minePixmap = minePixmap->scaled(75, 75);
		FloatingMine *mine = new FloatingMine(450, randomYMineLoc, minePixmap);
		scene->addItem(mine);
		itemVec->push_back(mine);
		mineLocation = itemVec->size()-1;
		//NOT WORKING
		connect(mine, SIGNAL(minePressed(FloatingMine*)), this, SLOT(controlMineFromClick(FloatingMine *mine)));
	} else if(random == 37){
		QPixmap *clamPixmap = new QPixmap("./GamePictures/Clam/Clam.png");
		*clamPixmap = clamPixmap->scaled(50, 50);
		ClamPowerUp *clam = new ClamPowerUp(400, randomYClamLoc, clamPixmap);
		scene->addItem(clam);
		itemVec->push_back(clam); 
	} else if(random <= 49){
		QPixmap *eelPixmap = new QPixmap("./GamePictures/Eel/Eel3.png");
		*eelPixmap = eelPixmap->scaled(200, 200);
		BlastingEel *eel = new BlastingEel(425, randomYEelLoc, eelPixmap);
		connect(eel, SIGNAL(firing(int, int)), this, SLOT(handleEel(int, int)));
		scene->addItem(eel);
		itemVec->push_back(eel); 
	} else {}
}
void MainWindow:: handleStartButton(){
	if(!gameStarted){
		usernameDisplay->setText(nameField->text());
		nameField->setMaxLength(10);
		if(nameField->text() == ""){
			usernameDisplay->setText("Please Enter a Name.");
			return;
		} else{
			usernameDisplay->setText(nameField->text() + ", Have Fun!");
			timer->start();
	
			playerPixmap = new QPixmap("./GamePictures/Mermaid/Mermaid5.png");
			player = new Player(0,200,playerPixmap);
			connect(player, SIGNAL(bubbleTimeOver()), this, SLOT(deleteBubble()));
			scene->addItem(player);
			itemVec->push_back(player);
	
			for(int i = 0; i < 3; i++){
				generateRandomItem();
			}	
			gameStarted = true;
		}
	} else{
		score_ = 0;
		scoreBox->setText(QString::number(score_));
		disconnect(player, SIGNAL(bubbleTimeOver()), this, SLOT(deleteBubble()));
		scene->removeItem(player);
		while(itemVec->size() > 2){
			GameItem *temp = itemVec->at(itemVec->size()-1);
			itemVec->pop_back();
			delete temp;
		}
		
		itemVec = new vector<GameItem*>;
		itemVec->push_back(background);
		itemVec->push_back(background2);
		
		if(nameField->text() == ""){
			usernameDisplay->setText("Please Enter a Name.");
			return;
		} else{
			usernameDisplay->setText(nameField->text() + ", Have Fun!");
			timer->start();
	
			playerPixmap = new QPixmap("./GamePictures/Mermaid/Mermaid5.png");
			player = new Player(0,200,playerPixmap);
			connect(player, SIGNAL(bubbleTimeOver()), this, SLOT(deleteBubble()));
			scene->addItem(player);
			itemVec->push_back(player);
	
			for(int i = 0; i < 3; i++){
				generateRandomItem();
			}	
			gameStarted = true;
		}
		
		//restart
	}
}

void MainWindow:: handlePauseButton(){
	if(timer->isActive()){
		timer->stop();
		gamePaused = true;
	} else {
		timer->start();
		gamePaused = false;
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

void MainWindow:: incrementScore(int add){
	score_+=add;
	scoreBox->setText(QString::number(score_));
}
void MainWindow:: handleTimer(){
	counter_++;
	scrollBackground();
	
	if(counter_%(3500/gameSpeed_) == 0){
		generateRandomItem();
	}
	if(counter_%100 == 0 && gameSpeed_ >= 3 && counter_ > 90000){	//Becomes Impossible
		generateRandomItem();
		generateRandomItem();	
	}
	if(counter_%(1000/gameSpeed_) == 0){
		incrementScore(1);
	} 
	
	
	if(counter_%20000 == 0){
		cout << "GameSpeed: " << gameSpeed_ << endl;
		gameSpeed_++;
	}
	for(unsigned int i = 0; i < itemVec->size(); i++){
		string s = (*itemVec)[i]->getType();
		
		(*itemVec)[i]->setSpeed(gameSpeed_);
		(*itemVec)[i]->act();
		
		if(s == "Player"){
			controlPlayer(dynamic_cast<Player*>((*itemVec)[i]));
		} else if(s == "Shark"){
			controlShark(dynamic_cast<Shark*>((*itemVec)[i]));
		} else if(s == "BlastingEel"){
			controlEel(dynamic_cast<BlastingEel*>((*itemVec)[i]), i);
		} else if (s == "Blast"){
			controlEelBlast(dynamic_cast<Blast*>((*itemVec)[i]));
		} else if(s == "Mine"){
			//controlMine(dynamic_cast<FloatingMine*>((*itemVec)[i]));
		} else if(s == "Clam"){
			//controlClam(dynamic_cast<ClamPowerUp*>((*itemVec)[i]));
		} else if(s == "Bubble"){
			//controlBubble(dynamic_cast<BubblePowerUp*>((*itemVec)[i]));
		} else{}
		//cout << "Type: " << s << endl;
	}
}

void MainWindow:: controlPlayer(Player *player){
	if(counter_%2000 == 0){
		QPixmap *playerPixmap4 = new QPixmap("./GamePictures/Mermaid/Mermaid4.png");
		player->setPixmap(*playerPixmap4);
	} else if(counter_%1500 == 0){
		QPixmap *playerPixmap3 = new QPixmap("./GamePictures/Mermaid/Mermaid3.png");
		player->setPixmap(*playerPixmap3);
	} else if(counter_%1000 == 0){
		QPixmap *playerPixmap2 = new QPixmap("./GamePictures/Mermaid/Mermaid2.png");
		player->setPixmap(*playerPixmap2);
	} else if(counter_%500 == 0){
		QPixmap *playerPixmap1 = new QPixmap("./GamePictures/Mermaid/Mermaid5.png");
		player->setPixmap(*playerPixmap1);
	}
	for(unsigned int i = 0; i < itemVec->size(); i++){
		if(player->isDead()){
			timer->stop();
			/*while(itemVec->size() > 2){
				GameItem *temp = itemVec->at(itemVec->size()-1);
				itemVec->pop_back();
				delete temp;
			}*/
		}
		
		if((*itemVec)[i]->getType() != "Background" && player->collidesWithItem((*itemVec)[i])){
			if((*itemVec)[i]->getType() == "Bubble"){
				controlBubble(dynamic_cast<BubblePowerUp*>((*itemVec)[i]));
			} else if((*itemVec)[i]->getType() == "Clam"){
				controlClam(dynamic_cast<ClamPowerUp*>((*itemVec)[i]), i);
			} else if((*itemVec)[i]->getType() == "Shark"){
				if(!player->isInvincible()){
					player->startInvincibility();
					player->loseLife();
				}
			} else if((*itemVec)[i]->getType() == "Blast"){
				if(!(player->isInvincible())){
					player->startInvincibility();
					player->loseLife();
				}
			} else if((*itemVec)[i]->getType() == "Clam"){
				player->addLife();
			} else if((*itemVec)[i]->getType() == "Mine"){
				if(!player->isInvincible()){
					player->loseLife();
					player->startInvincibility();
				}
			}	
		}
	}
	//cout << "Player Lives: " << player->getLives() << endl;
}

void MainWindow:: controlShark(Shark *shark){
	if(shark->isMoving()){
		if(counter_%800 == 0){
			QPixmap *sharkPixmap2 = new QPixmap("./GamePictures/Shark/Shark5");
			shark->setPixmap(*sharkPixmap2);
		} else if(counter_%400 == 0){
			QPixmap *sharkPixmap3 = new QPixmap("./GamePictures/Shark/Shark4");
			shark->setPixmap(*sharkPixmap3);
		}
		
		if(shark->x() < -1000){
			int loc = 0;
			while(loc < itemVec->size()){
				if(itemVec->at(loc)->getType() == "Shark"){
					GameItem *temp = itemVec->at(loc);
					itemVec->erase(itemVec->begin() + loc);
					delete temp;
					return;
				}
				loc++;
			}
				
		}
	}
}

void MainWindow:: handleEel(int x, int y){
	QPixmap *blastPixmap1 = new QPixmap("./GamePictures/EelBlast/EelBlast1.png");
	*blastPixmap1 = blastPixmap1->scaled(50, 50);
	Blast *blast1 = new Blast(x, y + 85, blastPixmap1);
	scene->addItem(blast1);
	itemVec->push_back(blast1); 
}
void MainWindow:: controlEel(BlastingEel *eel, int loc){
	if(eel->getCounter() == 5000){
		GameItem *temp = itemVec->at(loc);
		itemVec->erase(itemVec->begin() + loc);
		delete temp;
	}
}

void MainWindow:: controlEelBlast(Blast *blast){
//if done, delete
}
void MainWindow:: controlMineFromClick(FloatingMine *mine){
	score_+=50;
	GameItem *tempPtr = mine;
	delete tempPtr;
	//erase from array
}

void MainWindow:: controlClam(ClamPowerUp *clam, int loc){
	player->addLife();
	GameItem *temp = itemVec->at(loc);
	itemVec->erase(itemVec->begin() + loc);
	delete temp;
}

void MainWindow:: controlBubble(BubblePowerUp *bubble){
	player->bubbleTime();
	bubble->setPos(player->x() - 30, player->y() - 30);
}

void MainWindow:: deleteBubble(){
	int loc = 0;
	while(loc < itemVec->size()){
		if(itemVec->at(loc)->getType() == "Bubble"){
			GameItem *temp = itemVec->at(loc);
			itemVec->erase(itemVec->begin() + loc);
			delete temp;
			return;
		}
		loc++;
	}
}

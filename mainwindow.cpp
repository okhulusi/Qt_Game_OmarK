#include <QtGui/QApplication>
#include "mainwindow.h"

MainWindow::~MainWindow(){

}

MainWindow::MainWindow(){
	itemVec = new vector<GameItem*>();
	counter_ = 0;
	
	timer = new QTimer();
	timer->setInterval(1);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	
	mainLayout = new QGridLayout();
	scene = new QGraphicsScene();
	view = new QGraphicsView(scene);
	
	view->setFixedSize(500, 500);
	view->setWindowTitle("Under the Deep Blue Sea");
	
	background = new QPixmap("./GamePictures/Background.png");
	//*background = background->scaled(500, 500);
	backgroundBrush = new QBrush();
	backgroundBrush->setTexture(*background);
	scene->setBackgroundBrush(*backgroundBrush);
	
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
	
	//Quit Button
	quitButton = new QPushButton();
	quitButton->setText("Quit Game");
	connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	startMenuLayout->addWidget(quitButton);
	
	mainLayout->addLayout(startMenuLayout, 0, 50, 10, 10);
	setLayout(mainLayout);	
	mainLayout->addWidget(view, 0, 0, 50, 50);
}

void MainWindow:: handleStartButton(){
	username = nameField->text();
	timer->start();
}

void MainWindow:: handleTimer(){
	counter_++;
	
	if(counter_%3000 == 0){
		//Scrolling image
	}
	for(unsigned int i = 0; i < itemVec->size(); i++){
		(*itemVec)[i]->act(0);
	}
	score+=1;
	
}

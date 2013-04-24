#include <QtGui/QApplication>
#include "mainwindow.h"

MainWindow::~MainWindow(){

}

MainWindow::MainWindow(){
	mainLayout = new QGridLayout();
	scene = new QGraphicsScene();
	view = new QGraphicsView();
	
	view->setFixedSize(250, 250);
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
	startButton->show();
	startMenuLayout->addWidget(startButton); 
	
	//Quit Button
	quitButton = new QPushButton();
	quitButton->setText("Quit Game");
	connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	quitButton->show();
	startMenuLayout->addWidget(quitButton);
	
	setLayout(startMenuLayout);
}

void MainWindow:: handleStartButton(){
	view->show();
}

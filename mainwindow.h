#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui>
#include <vector>
#include "gameItem.h"
#include "shark.h"
#include "blastingEel.h"
#include "bubblePowerUp.h"
#include "floatingMine.h"

class MainWindow: public QWidget{
	Q_OBJECT

	public:
		explicit MainWindow();
		~MainWindow();
	
	public slots:
		void handleStartButton();
		void handleTimer();
	
	private:
		vector<GameItem*> *itemVec;
		QTimer *timer;
		int counter_;
		
		QString username;
		int score_;
		QString score;
		
		QGridLayout *mainLayout;
		QPixmap *background;
		QBrush *backgroundBrush;
		
		QVBoxLayout *startMenuLayout;
		QLabel *nameLabel;
		QLineEdit *nameField;
		QPushButton *startButton;
		QPushButton *quitButton;
		
		QPlastiqueStyle *style;
		QGraphicsScene *scene;
		QGraphicsView *view;

};
#endif



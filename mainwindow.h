#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui>
#include <vector>
#include "gameItem.h"
#include "shark.h"
#include "blastingEel.h"
#include "bubblePowerUp.h"
#include "floatingMine.h"
#include "background.h"

class MainWindow: public QWidget{
	Q_OBJECT

	public:
		explicit MainWindow();
		~MainWindow();
		void scrollBackground();
	
	public slots:
		void handleStartButton();
		void handleTimer();
		void handlePauseButton();
	
	private:
		vector<GameItem*> *itemVec;
		QTimer *timer;
		int counter_;
		int gameSpeed_;
		bool scrollSwitch_;
		
		QString username;
		int score_;
		QString score;
		
		QGridLayout *mainLayout;
		
		QPixmap *backgroundPixmap;
		Background *background;
		Background *background2;
		
		QVBoxLayout *startMenuLayout;
		QLabel *nameLabel;
		QLineEdit *nameField;
		QPushButton *startButton;
		QPushButton *quitButton;
		QPushButton *pauseButton;
		
		QPlastiqueStyle *style;
		QGraphicsScene *scene;
		QGraphicsView *view;

};
#endif



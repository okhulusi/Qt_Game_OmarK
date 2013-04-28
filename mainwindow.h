#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui>
#include <vector>
#include "gameItem.h"
#include "shark.h"
#include "blastingEel.h"
#include "bubblePowerUp.h"
#include "clamPowerUp.h"
#include "floatingMine.h"
#include "background.h"
#include "player.h"

class MainWindow: public QWidget{
	Q_OBJECT

	public:
		explicit MainWindow();
		~MainWindow();
		void scrollBackground();
	protected:
		void keyPressEvent(QKeyEvent *e);
	
	public slots:
		void handleStartButton();
		void handleTimer();
		void handlePauseButton();
	
	private:
		Player *player;
		QPixmap *playerPixmap;
		bool gameStarted;
		vector<GameItem*> *itemVec;
		QTimer *timer;
		int counter_;
		int gameSpeed_;
		bool scrollSwitch_;
		
		void controlPlayer(Player *player);
		void controlShark(Shark *shark);
		void controlEel(BlastingEel *eel);
		void controlEelBlast(Blast *blast);
		void controlMine(FloatingMine *mine);
		void controlClam(ClamPowerUp *clam);
		void controlBubble(BubblePowerUp *bubble);
		
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



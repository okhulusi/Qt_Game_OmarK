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
#include <QString>

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
		void handleEel(int x, int y);
		void deleteBubble();
		void explode(FloatingMine *mine);
		void generateRandomItem();
	
	private:
		int mineLocation;
		int mineIDCount_;
		Player *player;
		QPixmap *playerPixmap;
		bool gameStarted;
		bool gamePaused;
		vector<GameItem*> *itemVec;
		QTimer *timer;
		int counter_;
		int gameSpeed_;
		bool scrollSwitch_;
		
		void incrementScore(int);
		void controlPlayer(Player *player);
		void controlShark(Shark *shark);
		void controlEel(BlastingEel *eel, int loc);
		void controlEelBlast(Blast *blast, int loc);
		void controlClam(ClamPowerUp *clam, int loc);
		void controlBubble(BubblePowerUp *bubble);
		void deleteMine(FloatingMine*);
		void displayGameOver();
		
		QLabel *usernameDisplay;
		int score_;
		QLabel *scoreLabel;
		QLabel *scoreBox;
		QLabel *levelLabel;
		QLabel *levelDisplay;
		
		QLabel *livesLabel;
		QLabel *numLivesLabel;
		
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

		QPixmap *sharkPixmap;
		QPixmap *bubblePixmap;
		QPixmap *minePixmap;
		QPixmap *clamPixmap;
		QPixmap *eelPixmap;
		
		QPixmap *playerPixmap4;
		QPixmap *playerPixmap3;
		QPixmap *playerPixmap2;
		QPixmap *playerPixmap1;
		
		QPixmap *sharkPixmap2;
		QPixmap *sharkPixmap3;
		QPixmap *sharkPixmap4;
		
		QPixmap *blastPixmap1;

};
#endif



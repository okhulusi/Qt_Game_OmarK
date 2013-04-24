#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QRadioButton>
#include <QListView>
#include <QtGui/QApplication>
#include <QGridLayout>
#include <QPlastiqueStyle>
#include <QStyle>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QPointF>
#include <QRectF>
#include <QListWidget>
#include <cmath>

class MainWindow: public QWidget{
	Q_OBJECT

	public:
		explicit MainWindow();
		~MainWindow();
	
	public slots:
		void handleStartButton();
	
	private:
		QGridLayout *mainLayout;
		
		QPlastiqueStyle *style;
		QVBoxLayout *startMenuLayout;
		QLabel *nameLabel;
		QLineEdit *nameField;
		QPushButton *startButton;
		QPushButton *quitButton;
		
		QGraphicsScene *scene;
		QGraphicsView *view;

};
#endif



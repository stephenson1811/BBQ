
#include <QtGui/QApplication>
#include <QGraphicsScene>
#include "WarGame.h"

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	QGraphicsScene scene(-350, -350, 700, 700);
	WarGame w(&scene);
    w.resize(w.sizeHint());
    w.setWindowTitle("War Game");
	w.show();
	return a.exec();
}

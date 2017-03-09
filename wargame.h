#ifndef WARGAME_H
#define WARGAME_H

#include <QtGui/QMainWindow>
#include "ui_wargame.h"
#include "Board.h"
class WarGame : public QMainWindow
{
	Q_OBJECT

public:
	WarGame(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WarGame();

private:
	Ui::WarGameClass ui;
	Board *m_Board;
};

#endif // WARGAME_H

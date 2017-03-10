#include "wargame.h"
#include <QGridLayout>
WarGame::WarGame(QGraphicsScene* c,QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	m_Board = new Board(c,this);
	//ui.verticalLayout->setMargin(1);
	//ui.verticalLayout->addWidget(m_Board);
	setCentralWidget(m_Board);
}

WarGame::~WarGame(){
}

#include "wargame.h"
#include <QGridLayout>

WarGame::WarGame(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);

    m_Scene = new BoardScene(0, 0, 800, 600);
    m_Board = new BoardView(m_Scene,this);
    m_Board->setBackgroundBrush(QPixmap("D:/data/background/Room_19-1.bmp"));
    //ui.verticalLayout->setMargin(1);
    //ui.verticalLayout->addWidget(m_Board);
    setCentralWidget(m_Board);
}

WarGame::~WarGame(){
}

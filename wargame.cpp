#include "wargame.h"
#include <QGridLayout>
#include <QBitmap>
#include <QImage>
WarGame::WarGame(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);

    m_Scene = new BoardScene(0, 0, 8268, 5730);
    m_Board = new BoardView(m_Scene);
    m_Board->setRenderHint(QPainter::Antialiasing);
    QImage o("F:/github/WarGame/BBQ/assets/map1.jpg");//
    m_Board->setBackgroundBrush(o);
    //"E:/vs08proj/0.81/client/Data/data/ADOPFLGG.bmp"
    //ui.verticalLayout->setMargin(1);
    //ui.verticalLayout->addWidget(m_Board);

//    m_Board->setCacheMode(QGraphicsView::CacheBackground);
//    m_Board->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//    m_Board->setDragMode(QGraphicsView::ScrollHandDrag);
//    m_Board->resize(400, 300);
    m_Board->show();

    setCentralWidget(m_Board);
    connect(m_Board,SIGNAL(p( QString&)),this,SLOT(onP( QString&)));
}
void WarGame::onP( QString& s){
    ui.statusBar->showMessage(s);
}
WarGame::~WarGame(){
}

#include "wargame.h"
#include <QDockWidget>
#include <QGridLayout>
#include <QBitmap>
#include <QImage>
WarGame::WarGame(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);
    createStatusBar();
    createActions();
    createDockWindows();

    m_Scene = new BoardScene(0, 0, 8268, 5730);
    m_MiniMap = new MiniMap(m_Scene);
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
void WarGame::createStatusBar(){
    statusBar()->showMessage(tr("部队信息"));
}
void WarGame::createActions(){
    viewMenu = menuBar()->addMenu(tr("&信息栏"));
}
void WarGame::createDockWindows(){
    QDockWidget *dock = new QDockWidget(tr("地图"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    //dock->setWidget(m_MiniMap);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());

    dock = new QDockWidget(tr("信息"), this);
    QWidget*w2 = new QWidget(dock);
    dock->setWidget(w2);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());


    dock = new QDockWidget(tr("事件"), this);
    QWidget*w3 = new QWidget(dock);
    dock->setWidget(w3);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());

//    connect(customerList, &QListWidget::currentTextChanged,
//            this, &MainWindow::insertCustomer);
//    connect(paragraphsList, &QListWidget::currentTextChanged,
//            this, &MainWindow::addParagraph);
}
void WarGame::onP( QString& s){
    ui.statusBar->showMessage(s);
}
WarGame::~WarGame(){
}

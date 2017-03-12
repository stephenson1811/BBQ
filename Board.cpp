#include "Board.h"

#include <QPainter>
#include <QPalette>
Board::Board(QGraphicsScene *scene, QWidget*p,Qt::WindowFlags f) : QGraphicsView(scene,p){
    createGUI();
    viewport()->setAttribute(Qt::WA_AcceptTouchEvents);
    setDragMode(ScrollHandDrag);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
Board::~Board(void){
}
void Board::createGUI(){
    init();
    connect(this,SIGNAL( clickHex(HexIndex&,QVector<Piece*>&)),&m_PieceManage,SLOT( onClickHex(HexIndex&,QVector<Piece*>&)));
}
void Board::init (){
    // 生成地图
    m_BoardHex.init(100,120); // 六角网格
    QVector <QPolygonF> out ;
    m_BoardHex.getHexes(out);
    for (QVector <QPolygonF>::Iterator it = out.begin(); it != out.end(); it ++){
        m_HexPath.addPolygon((*it));
        m_HexPath.closeSubpath();
    }
    // 生成算子
    m_PieceManage.init();
}
void Board::mouseMoveEvent ( QMouseEvent *  me){
    m_HexIndex;
}
void Board::mouseReleaseEvent ( QMouseEvent *  me){}
void Board::mousePressEvent ( QMouseEvent *  me){
    QVector<Piece*> out;
    //emit clickHex(HexIndex(1,2),out);
    out.push_back(0);
}
void Board::paintEvent(QPaintEvent * pe){
    QGraphicsView::paintEvent(pe);
    QPainter p(this->viewport());
    //QWidget::paintEvent(pe);
    p.drawPath(m_HexPath);

    this->viewport()->update();
}

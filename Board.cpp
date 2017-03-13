#include "Board.h"

#include <QPainter>
#include <QPalette>
BoardView::BoardView(QGraphicsScene *scene, QWidget*p,Qt::WindowFlags ) : QGraphicsView(scene,p){
    createGUI();
    viewport()->setAttribute(Qt::WA_AcceptTouchEvents);
    setDragMode(ScrollHandDrag);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
BoardView::~BoardView(void){
}
void BoardView::createGUI(){
    init();
}
void BoardView::init (){
    // 生成地图
    m_BoardHex.init(100,220); // 六角网格
    QVector <QPolygonF> out ;
    m_BoardHex.getHexes(out);
    for (QVector <QPolygonF>::Iterator it = out.begin(); it != out.end(); it ++){
        m_HexPath.addPolygon((*it));
        m_HexPath.closeSubpath();
    }
    Piece* f = new Piece(QPixmap("E:/github/war/BBQ/assets/butterfly.png"),HexIndex());
    Piece* e = new Piece(QPixmap("E:/github/war/BBQ/assets/qtlogo.png"),HexIndex());
    this->scene()->addItem(f);
    this->scene()->addItem(e);
    m_ActivePath = new Path(QPainterPath(QPointF()));
    // 生成算子
}
void BoardView::mouseMoveEvent ( QMouseEvent *  me){
    //m_ActivePath->setPath();
    HexIndex end = m_BoardHex.pos2Idx(QPointF(me->pos()));
    Piece p(QPixmap(""),HexIndex());
    m_BoardHex.genMovePath(p,m_Start,end);
    m_ActivePath;
}
void BoardView::mouseReleaseEvent ( QMouseEvent *  me){
    return ;
}
void BoardView::mousePressEvent ( QMouseEvent *  me){
    HexIndex hi = m_BoardHex.pos2Idx(QPointF(me->pos()));
    m_Start = hi;
}
void BoardView::paintEvent(QPaintEvent * pe){
    QGraphicsView::paintEvent(pe);
    QPainter p(this->viewport());
    //QWidget::paintEvent(pe);
    //p.drawPath(m_HexPath);

    this->viewport()->update();
}
BoardScene::BoardScene(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    :QGraphicsScene( x,  y,  width,  height, parent){
}

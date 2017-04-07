#include "Board.h"

#include <QPainter>
#include <QPalette>
#include <QMessageBox>
BoardView::BoardView(QGraphicsScene *scene, QWidget*p,Qt::WindowFlags ) : QGraphicsView(scene,p){
    createGUI();
    viewport()->setAttribute(Qt::WA_AcceptTouchEvents);
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
//    Piece* f = new Piece(QPixmap("E:/github/war/BBQ/assets/butterfly.png"),HexIndex());
//    Piece* e = new Piece(QPixmap("E:/github/war/BBQ/assets/qtlogo.png"),HexIndex());
//    this->scene()->addItem(f);
//    this->scene()->addItem(e);
//    m_ActivePath = new Path(QPainterPath(QPointF()));
    m_PieceManage.init();
    //this->scene()->addItem(m_PieceManage.m_Pieces[0]);
    this->setSceneRect(QRectF(0,0,8268,5730));
    // 生成算子
}
void BoardView::mouseMoveEvent ( QMouseEvent *  me){
    //m_ActivePath->setPath();
//    HexIndex end = m_BoardHex.pos2Idx(me->pos());
//    Piece p(QPixmap(""),HexIndex());
//    m_BoardHex.genMovePath(p,m_Start,end);
//    m_ActivePath;

    QPointF p2 = mapToScene(me->pos());
    HexIndex hi = m_BoardHex.pos2Idx(p2);
    QString a;
    a = QString("x=%1,y=%2,z=%3").arg(hi.getXsai()).arg(hi.getYupsilon()).arg(hi.getZeta());
}
void BoardView::mouseReleaseEvent ( QMouseEvent *  me){
    return ;
}
void BoardView::mousePressEvent ( QMouseEvent *  me){
    QPoint p1 = mapFromScene(me->pos());
    QPointF p2 = mapToScene(me->pos());
    HexIndex hi = m_BoardHex.pos2Idx(p2);
    m_Start = hi;
    QString a;
    a = QString("x=%1,y=%2,z=%3").arg(hi.getXsai()).arg(hi.getYupsilon()).arg(hi.getZeta());
//    QMessageBox b;
//    b.setText(a);
//    b.exec();
    emit p(a);
}
void BoardView::paintEvent(QPaintEvent * pe){
    QGraphicsView::paintEvent(pe);
    QPainter p(this->viewport());//

//    QWidget::paintEvent(pe);
//    p.drawPath(m_HexPath);
//    p.drawLine(QPoint(0,2865),QPoint(8268,2865));
//    p.drawLine(QPoint(4134,0),QPoint(4134,5730));
//    p.drawText(QRect(0, 0, 100, 50),m_Text,QTextOption(Qt::AlignCenter));
}
BoardScene::BoardScene(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    :QGraphicsScene( x,  y,  width,  height, parent){
}

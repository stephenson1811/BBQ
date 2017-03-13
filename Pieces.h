#pragma once
#include <QGraphicsWidget>
#include <QGraphicsItem>
#include <QPixmap>
#include <QString>
#include "Uni.h"
class Piece : public QGraphicsPixmapItem{
public:
    Piece(const QPixmap & , const HexIndex&);
    HexIndex getHexIndex(){return m_Index;}
    int getRow(){return m_Index.getRow();}
    int getCol(){return m_Index.getColumn();}
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    HexIndex m_Index;
    int w;
};
class Path : public QGraphicsPathItem {
public:
    explicit Path(const QPainterPath &path, QGraphicsItem *parent = Q_NULLPTR);
public:
};



class PieceManage : public QObject{
    Q_OBJECT
public:
    PieceManage();
    ~PieceManage();
public:
    void findChildren(HexIndex& ,QVector<Piece*>&);
    void init();
public slots:
    void onClickHex(HexIndex&,QVector<Piece*>&);
private:
    QVector<Piece*> m_Pieces;
};

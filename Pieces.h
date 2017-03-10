#pragma once
#include <QGraphicsWidget>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "Uni.h"
class Piece : public QGraphicsPixmapItem{
public:
    Piece(const QPixmap & , const HexIndex&);
    ~Piece(void);
    HexIndex getHexIndex(){return m_Index;}
    int getRow(){return m_Index.getRow();}
    int getCol(){return m_Index.getColumn();}
private:
    HexIndex m_Index;
};
class PiecePath{
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

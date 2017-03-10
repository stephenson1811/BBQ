#pragma once
#include "BoardHex.h"
#include "HexAttr.h"
#include "Pieces.h"
#include <QGraphicsView>
#include <QPaintEvent>
#include <QPolygon>
#include <QPainterPath>
class Board : public QGraphicsView{
    Q_OBJECT
public:
    Board(QGraphicsScene* ,QWidget*p = 0,Qt::WindowFlags f=0);
    ~Board(void);
public:
    void movePiece();
protected:
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent ( QMouseEvent *  );
    void mousePressEvent ( QMouseEvent *  ) ;
    void mouseMoveEvent ( QMouseEvent *  );
private:
    void init ();
    void createGUI();
signals:
    void clickHex(HexIndex&,QVector<Piece*>&);
public slots:
private:
    BoardHex m_BoardHex; // 六角网格
    PieceManage m_PieceManage;
    QPainterPath m_HexPath;
    HexIndex m_HexIndex;
};


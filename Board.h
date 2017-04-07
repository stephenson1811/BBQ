#pragma once
#include "BoardHex.h"
#include "HexAttr.h"
#include "Pieces.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPaintEvent>
#include <QPolygon>
#include <QPainterPath>

class BoardScene :public QGraphicsScene{
public:
    BoardScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = Q_NULLPTR);
};
class BoardView : public QGraphicsView{
    Q_OBJECT
public:
    BoardView(QGraphicsScene* ,QWidget*p = 0,Qt::WindowFlags f=0);
    ~BoardView(void);
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
    void p(QString&);
    void clickHex(HexIndex&,QVector<Piece*>&);
public slots:
private:
    HexIndex m_Start;
    PieceManage m_PieceManage;
    Path* m_ActivePath;
    BoardScene *m_Scene;
    BoardHex m_BoardHex; // 六角网格
    QPainterPath m_HexPath;
    HexIndex m_HexIndex;
    QString m_Text;
};


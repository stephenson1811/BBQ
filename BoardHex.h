#pragma once
#include <QObject>
#include <QPointF>
#include <QPolygon>
#include "Uni.h"
#include "Pieces.h"
#include "HexAttr.h"
class Hex{
public:
    Hex();
    void init(const Oriental,int r, int c);
    QPointF getPoint(int index);
    int getRow(){return m_Index.getRow();}
    int getColumn(){return m_Index.getColumn();}
private:
    QPointF m_1;
    QPointF m_2;
    QPointF m_3;
    QPointF m_4;
    QPointF m_5;
    QPointF m_6;
    QPointF m_Central;
    HexIndex m_Index;
    int m_Radius; // 六角网格中点到顶点的距离
    Oriental m_Oriental; // 方向
    Terrain m_Terrain; // 地形
    Weather m_Weather; // 天气
};
class BoardHex : public QObject
{
    Q_OBJECT
public:
    BoardHex(void);
    ~BoardHex(void);
private:

public:
    void setOriental(Oriental o){m_Oriental = o;}
    Oriental getOriental(){return m_Oriental;}
    void init(int,int);
    void getHexes(QVector<QPolygonF>& );
    void genMovePath(Piece&); // 根据算子属性和运动轨迹的起点终点生成路径
public slots:
    void onClickHex(HexIndex&);
private:
    void show ();
private:
    Oriental m_Oriental; // 方向
    bool m_Show; // 是否显示网格
    QVector<Hex> m_Hexes;
    QPointF m_Start;
    QPointF m_End;
};


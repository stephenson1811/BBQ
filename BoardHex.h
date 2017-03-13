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
    Hex(HexIndex&);
    Hex(Terrain&,Weather&);
    void init(int r, int c);
    QPointF getPoint (int index)const;
    int getRow(){return m_Index.getRow();}
    int getColumn()const{return m_Index.getColumn();}
    HexIndex getIndex()const {return m_Index;}
    bool operator == ( const HexIndex& hi){
        if (this->m_Index == hi){
            return true;
        }
        return false;
    }
    bool operator == (const Hex& hi){
        if (this->m_Index == hi.getIndex()){
            return true;
        }
        return false;
    }
    bool inHex(const QPointF&);
    QPointF getCentral();
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
    HexIndex pos2Idx(const QPointF&);
    QPointF idx2Pos(const HexIndex&);
    void init(int,int);
    void getHexes(QVector<QPolygonF>& );
    void genMovePath(Piece&); // 根据算子属性和运动轨迹的起点终点生成路径
public slots:
    void onClickHex(HexIndex&);
private:
    void show ();
    void calcPath(HexIndex&src, HexIndex&dst);
    void getNeighbourNodes(HexIndex&,QVector<HexIndex>&);
    Hex& getHex(HexIndex&) ;
private:
    bool m_Show; // 是否显示网格
    QVector<Hex> m_Hexes;
    QPointF m_Start;
    QPointF m_End;
};


#pragma once
#include <QVector>
#include <QPointF>
#include <QPolygon>
enum Oriental{
	Vertical = 0,
	Horizontal = 1,
};
class Hex{
public:
	void init(const Oriental,int r, int c);
	QPointF getPoint(int index);
	int getRow(){return m_Row;}
	int getColumn(){return m_Col;}
private:
	QPointF m_1;
	QPointF m_2;
	QPointF m_3;
	QPointF m_4;
	QPointF m_5;
	QPointF m_6;
	QPointF m_Central;
	int m_Radius; // 六角网格中点到顶点的距离
	int m_Row; // 行编号
	int m_Col; // 列编号
	Oriental m_Oriental; // 方向
};
class BoardHex
{
public:
	BoardHex(void);
	~BoardHex(void);
private:

public:
	void setOriental(Oriental o){m_Oriental = o;}
	Oriental getOriental(){return m_Oriental;}
	void init(int,int);
	void getHexes(QVector<QPolygonF>& );
private:
	void show ();
private:
	Oriental m_Oriental; // 方向
	bool m_Show; // 是否显示网格
	QVector<Hex> m_Hexes;
	QPointF m_Start;
	QPointF m_End;
};


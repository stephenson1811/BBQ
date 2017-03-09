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
	int m_Radius; // ���������е㵽����ľ���
	int m_Row; // �б��
	int m_Col; // �б��
	Oriental m_Oriental; // ����
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
	Oriental m_Oriental; // ����
	bool m_Show; // �Ƿ���ʾ����
	QVector<Hex> m_Hexes;
	QPointF m_Start;
	QPointF m_End;
};


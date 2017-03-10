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
	int m_Radius; // ���������е㵽����ľ���
	Oriental m_Oriental; // ����
	Terrain m_Terrain; // ����
	Weather m_Weather; // ����
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
	void genMovePath(Piece&); // �����������Ժ��˶��켣������յ�����·��
public slots:
	void onClickHex(HexIndex&);
private:
	void show ();
private:
	Oriental m_Oriental; // ����
	bool m_Show; // �Ƿ���ʾ����
	QVector<Hex> m_Hexes;
	QPointF m_Start;
	QPointF m_End;
};


#pragma once
#include "BoardHex.h"
#include "Terrain.h"
#include "Pieces.h"
#include <QWidget>
#include <QPaintEvent>
#include <QPolygon>
#include <QPainterPath>
class Board : public QWidget{
public:
	Board(QWidget* p = 0);
	~Board(void);
public:
	void movePiece();
protected:
	void paintEvent(QPaintEvent *);
private:
	void init ();
private:
	Pieces * m_Piece;
	BoardHex m_BoardHex; // ��������
	Terrain m_Terrain; // ����
	Weather m_Weather; // ����
	QPainterPath m_HexPath;
};


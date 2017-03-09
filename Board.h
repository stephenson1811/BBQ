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
	BoardHex m_BoardHex; // 六角网格
	Terrain m_Terrain; // 地形
	Weather m_Weather; // 天气
	QPainterPath m_HexPath;
};


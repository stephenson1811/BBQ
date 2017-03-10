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
	void mouseReleaseEvent ( QMouseEvent *  );
	void mousePressEvent ( QMouseEvent *  ) ;
private:
	void init ();
signals:
	void clickHex(HexIndex&);
public slots:
private:
	BoardHex m_BoardHex; // 六角网格
	Terrain m_Terrain; // 地形
	Weather m_Weather; // 天气
	PieceManage m_PieceManage;
	QPainterPath m_HexPath;
};


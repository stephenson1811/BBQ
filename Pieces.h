#pragma once
#include <QGraphicsWidget>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "Uni.h"
class Piece : public QGraphicsPixmapItem{
public:
	Piece(const QPixmap & , HexIndex&);
	~Piece(void);
	HexIndex getHexIndex(){return m_Index;}
	int getRow(){return m_Index.getRow();}
	int getCol(){return m_Index.getColumn();}
private:
	HexIndex m_Index;
};
class PieceManage : public QObject{
	Q_OBJECT
public:
	PieceManage();
	~PieceManage();
public:
	void findChildren(HexIndex& ,QVector<Piece*>&);
	void init();
private:
	QVector<Piece*> m_Pieces;
};

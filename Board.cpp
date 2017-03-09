#include "Board.h"

#include <QPainter>
Board::Board(QWidget* p):QWidget(p)
{
	init();
	m_Piece = new Pieces();
}


Board::~Board(void)
{
}
void Board::init (){
	m_BoardHex.init(10,12); // ��������
	m_Terrain; // ����
	m_Weather; // ����
	QVector <QPolygonF> out ;
	m_BoardHex.getHexes(out);
	for (QVector <QPolygonF>::Iterator it = out.begin(); it != out.end(); it ++){
		m_HexPath.addPolygon((*it));
		m_HexPath.closeSubpath();
	}
}
void Board::paintEvent(QPaintEvent * pe){
	QPainter p(this);
	p.drawPath(m_HexPath);
}
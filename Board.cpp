#include "Board.h"

#include <QPainter>
#include <QPalette>
Board::Board(QWidget* p):QWidget(p)
{
	createGUI();
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
Board::~Board(void){
}
void Board::createGUI(){
	init();
	connect(this,SIGNAL(void clickHex(HexIndex&)),&m_PieceManage,SLOT(void onClickHex(HexIndex&)));
}
void Board::init (){
	// 生成地图
	m_BoardHex.init(10,12); // 六角网格
	m_Terrain; // 地形
	QVector <QPolygonF> out ;
	m_BoardHex.getHexes(out);
	for (QVector <QPolygonF>::Iterator it = out.begin(); it != out.end(); it ++){
		m_HexPath.addPolygon((*it));
		m_HexPath.closeSubpath();
	}
	// 生成算子
	m_PieceManage.init();
	m_Weather; // 天气
}
void Board::mouseReleaseEvent ( QMouseEvent *  me){}
void Board::mousePressEvent ( QMouseEvent *  me){}
void Board::paintEvent(QPaintEvent * pe){
	QPainter p(this);
	//QWidget::paintEvent(pe);
	p.drawPath(m_HexPath);
}
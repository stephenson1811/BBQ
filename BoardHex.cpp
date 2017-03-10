#include "BoardHex.h"
#include <cmath>
const double s3 = sqrt(3.0);

void BoardHex::show(){
	m_Start.x();
}
void BoardHex::init(int row ,int col){
	for (int r = 0; r < row ; r ++){
		for (int c = 0; c < col ; c++){
			Hex h;
			h.init(Horizontal,r,c);
			m_Hexes.push_back(h);
		}
	}
}
void BoardHex::onClickHex(HexIndex& index){
	index;
}
void BoardHex::getHexes(QVector<QPolygonF>&out){
	for (QVector<Hex>::iterator it = m_Hexes.begin();it != m_Hexes.end(); it ++){
		QPolygonF plg;
		plg<<(*it).getPoint(1)<<(*it).getPoint(2)<<(*it).getPoint(3)<<
			(*it).getPoint(4)<<(*it).getPoint(5)<<(*it).getPoint(6);
		out.push_back(plg);
	}
}
void Hex::init(const Oriental o , int row, int col){
	int br=20;
	int bc = 20;
	m_Radius = 20;
	int r = m_Radius;
	if (row%2==0){
		m_Central = QPointF (r*3.0*col+bc,      r*row*s3/2+br);
	}else{
		m_Central = QPointF (r*(3.0/2+3*col)+bc,r*row*s3/2+br);
	}
	int cx = m_Central.x();
	int cy = m_Central.y();
	if (o == Vertical){
		m_1 = QPointF(cx, cy - r);
		m_2 = QPointF(cx - s3*r/2, cy - r/2);
		m_3 = QPointF(cx - s3*r/2, cy + r/2);
		m_4 = QPointF(cx, cy + r);
		m_5 = QPointF(cx + s3*r/2, cy + r/2);
		m_6 = QPointF(cx + s3*r/2, cy - r/2);	
	}else {
		m_1 = QPointF(cx - r, cy);
		m_2 = QPointF(cx - r/2, cy + s3*r/2);
		m_3 = QPointF(cx + r/2, cy + s3*r/2);
		m_4 = QPointF(cx + r, cy);
		m_5 = QPointF(cx + r/2, cy - s3*r/2);
		m_6 = QPointF(cx - r/2, cy - s3*r/2);		
	}
}
QPointF Hex::getPoint(int index){
	switch (index){
	case 0:
		return m_Central;
	case 1:
		return m_1;
	case 2:
		return m_2;
	case 3:
		return m_3;
	case 4:
		return m_4;
	case 5:
		return m_5;
	case 6:
		return m_6;
	}
}

BoardHex::BoardHex(void){

}
BoardHex::~BoardHex(void){
}
Hex::Hex(){
	m_Terrain; // 地形	
	m_Weather; // 天气
}

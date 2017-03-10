#include "Pieces.h"

void PieceManage::init(){
	// 读文件生成算子
	m_Pieces.push_back(new Piece(QPixmap(""), HexIndex()));
}

void PieceManage::findChildren(HexIndex& index,QVector<Piece*>& out){
	for (QVector<Piece*>::Iterator it = m_Pieces.begin();it != m_Pieces.end(); it ++){
		if ((*it)->getHexIndex() == index){
			out.push_back((*it));
		}
	}
	out;
}

Piece::Piece(const QPixmap & p, HexIndex&)
	:QGraphicsPixmapItem(p){
}
Piece::~Piece(void){
}
PieceManage::PieceManage(){
}
PieceManage::~PieceManage(){
	for (QVector<Piece*>::Iterator it = m_Pieces.begin();it != m_Pieces.end(); it ++){
		delete (*it);
	}
}
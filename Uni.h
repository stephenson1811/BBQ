#pragma once
#include <QVector>
class HexIndex{
public:
	HexIndex(){m_Row = 0;m_Col = 0;}
	HexIndex(int r, int c){m_Row = r;m_Col = c;}
	int m_Row; // 行编号
	int m_Col; // 列编号
	int getRow(){return m_Row;}
	int getColumn(){return m_Col;}
	bool operator == (HexIndex& index){
		return index.m_Col == this->m_Col && index.m_Row == this->m_Row;
	}
};


enum Oriental{
	Vertical = 0,
	Horizontal = 1,
};

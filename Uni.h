#pragma once
#include <QVector>
class HexIndex{
public:
    HexIndex(){m_Xsai = 0;m_Yupsilon = 0;m_Zeta = 0;}
    HexIndex(int x, int y, int z){m_Xsai = x;m_Yupsilon = y;m_Zeta = z;}
    int m_Xsai; // xsai编号
    int m_Yupsilon; // yupsilon编号
    int m_Zeta;  // zeta 编号
    int getXsai(){return m_Xsai;}
    int getYupsilon()const{return m_Yupsilon;}
    int getZeta()const{return m_Zeta;}
    bool operator == ( const HexIndex& index){
        return index.m_Zeta == this->m_Zeta && index.m_Yupsilon == this->m_Yupsilon &&
                index.m_Xsai == this->m_Xsai;
	}
    void operator = (const HexIndex& index){
        this->m_Xsai = index.m_Xsai;
        this->m_Yupsilon = index.m_Yupsilon;
        this->m_Zeta = index.m_Zeta;
    }
};


enum Oriental{
	Vertical = 0,
	Horizontal = 1,
};

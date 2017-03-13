#include <QDebug>
#include "BoardHex.h"
#include <cmath>

const double s3 = sqrt(3.0);

Hex::Hex(){
    m_Terrain; // 地形
    m_Weather; // 天气
}
Hex::Hex(HexIndex&){}
Hex::Hex(Terrain&,Weather&){
    m_Terrain; // 地形
    m_Weather; // 天气
}
bool Hex::inHex(const QPointF& p){
    QPolygonF plg;
    plg<<m_1<<m_2<<m_3<<m_4<<m_5<<m_6;
    if (plg.containsPoint(p,Qt::WindingFill)){
        return true;
    }
    return false;
}
QPointF Hex::getCentral(){
    //qFind ();
    return this->m_Central;
}
void Hex::init( int row, int col){
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
    if (1){
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
QPointF Hex::getPoint(int index)const{
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
void BoardHex::show(){
    m_Start.x();
}
HexIndex BoardHex::pos2Idx(const QPointF& point){
    for (QVector<Hex>::Iterator it = m_Hexes.begin(); it != m_Hexes.end();it ++){
        if ((*it).inHex(point)){
            return (*it).getIndex();
        }
    }
    return HexIndex();
}
QPointF BoardHex::idx2Pos(const HexIndex& index){
    for (QVector<Hex>::Iterator it = m_Hexes.begin(); it != m_Hexes.end();it ++){
        if ((*it).getIndex() == index){
            return (*it).getCentral();
        }
    }
    return QPointF();
}
void BoardHex::init(int row ,int col){
    for (int r = 0; r < row ; r ++){
        for (int c = 0; c < col ; c++){
            Hex h;
            h.init(r,c);
            m_Hexes.push_back(h);
        }
    }
}
void BoardHex::calcPath(HexIndex&src, HexIndex&dst){
    src;
    dst;
    QPainterPath p;
    src;
}
void BoardHex::onClickHex(HexIndex& index){
    index;
}
void BoardHex::genMovePath(Piece& p){
    p;
}
void BoardHex::getNeighbourNodes(HexIndex&hi,QVector<HexIndex>&out){
    Hex h;
    if (getHex(hi) == Hex()){
        out.push_back(hi);
    }
    if (getHex(hi) == Hex()){
        out.push_back(hi);
    }
    if (getHex(hi) == Hex()){
        out.push_back(hi);
    }
    if (getHex(hi) == Hex()){
        out.push_back(hi);
    }
    if (getHex(hi) == Hex()){
        out.push_back(hi);
    }
    if (getHex(hi) == Hex()){
        out.push_back(hi);
    }
}
Hex& BoardHex::getHex(HexIndex& hi) {
   Hex h;
   QVector<Hex>::Iterator it = qFind (m_Hexes.begin(), m_Hexes.end(), hi);
   if (it != m_Hexes.end()){
       qDebug()<<"getHex,true,r="<<(*it).getIndex().getRow()<<",c="<<(*it).getIndex().getColumn();
       return (*it);
   }else{
       qDebug()<<"getHex,false";
   }
   return h;
}
void BoardHex::getHexes(QVector<QPolygonF>&out){
    for (QVector<Hex>::iterator it = m_Hexes.begin();it != m_Hexes.end(); it ++){
        QPolygonF plg;
        plg<<(*it).getPoint(1)<<(*it).getPoint(2)<<(*it).getPoint(3)<<
            (*it).getPoint(4)<<(*it).getPoint(5)<<(*it).getPoint(6);
        out.push_back(plg);
    }
}
BoardHex::BoardHex(void){
}
BoardHex::~BoardHex(void){
}


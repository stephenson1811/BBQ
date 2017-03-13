#include "Pieces.h"


Piece::Piece(const QPixmap & p, const HexIndex&index)
    :QGraphicsPixmapItem(p){
    qreal x = index.m_Col*30.0;
    qreal y = index.m_Row*50.0;
    this->setPos(x,y);
    w = p.width();
}
void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event){
    int y = 0;
    y = 9;
    y += 8;
    y = w;
}
void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){}
Path::Path(const QPainterPath &path, QGraphicsItem *parent)
    :QGraphicsPathItem(path,parent){
}
PieceManage::PieceManage(){
}
PieceManage::~PieceManage(){
    for (QVector<Piece*>::Iterator it = m_Pieces.begin();it != m_Pieces.end(); it ++){
        delete (*it);
    }
}
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
    out.push_back(new Piece(QPixmap("ddf"),HexIndex()));
}
void PieceManage::onClickHex(HexIndex& hi,QVector<Piece*>&out){
    findChildren(hi, out);
}

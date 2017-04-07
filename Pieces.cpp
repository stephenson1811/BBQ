#include "Pieces.h"
#include <QImage>
#include <QBitmap>
Piece::Piece(const QPixmap & p, const HexIndex&index)
    :QGraphicsPixmapItem(p){
//    qreal x = index.m_Col*30.0;
//    qreal y = index.m_Row*50.0;
//    this->setPos(x,y);
//    w = p.width();
}
void Piece::mousePressEvent(QGraphicsSceneMouseEvent *){
    int y = 0;
    y = 9;
    y += 8;
    y = w;
}
void Piece::dragEnterEvent(QGraphicsSceneDragDropEvent *){}
void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent *){}
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
    int size = 160;
    int xs = 16;
    int ys = 14;
    QImage o("F:/github/WarGame/BBQ/assets/cf1.png");
    QImage m("F:/github/WarGame/BBQ/assets/mask1.png");
    o.setAlphaChannel(m);
    QPixmap another = QPixmap::fromImage(o);

    for (int i = 0; i < 12;i++){
        for (int j = 0; j< 8;j++){
            QPixmap p = another.copy(size*i,size*j,size,size);
            p.setMask(p.createHeuristicMask());
            m_Pieces.push_back(new Piece(p, HexIndex()));
        }
    }
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

#ifndef MINIMAP_H
#define MINIMAP_H

#include <QGraphicsView>

class MiniMap:public QGraphicsView
{
public:
    explicit MiniMap(QGraphicsScene* ,QWidget*p = 0,Qt::WindowFlags f=0);
};

#endif // MINIMAP_H

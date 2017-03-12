#ifndef WARGAME_H
#define WARGAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ui_wargame.h"
#include "Board.h"
class WarGame : public QMainWindow
{
    Q_OBJECT

public:
    WarGame(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~WarGame();

private:
    Ui::WarGameClass ui;
    Board *m_Board;
    QWidget* m_Right;
    QGraphicsScene* m_Scene;
};

#endif // WARGAME_H

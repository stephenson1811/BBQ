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
public slots:
    void onP(QString&s);
private:
    Ui::WarGameClass ui;
    BoardScene *m_Scene;
    BoardView *m_Board;
    QWidget* m_Right;
};

#endif // WARGAME_H

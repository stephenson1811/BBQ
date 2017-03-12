
#include <QApplication>

#include "WarGame.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    WarGame w;
    w.resize(w.sizeHint());
    w.setWindowTitle("War Game");
    w.show();
    return a.exec();
}

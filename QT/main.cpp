#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}



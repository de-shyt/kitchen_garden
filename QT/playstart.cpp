#include "playstart.h"
#include "ui_playstart.h"
#include "player.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QImage>
#include <QFont>
PlayStart::PlayStart(QWidget *parent)
{

   // setWindowTitle("POTATO SIMULATOR");
    //setStyleSheet(("background-image: url(:/img/weed.jpg)"));
    QGraphicsScene * scene = new QGraphicsScene();
    // create an item to add to the scene
    player * my_player = new player();
    my_player->setPixmap(QPixmap(":/img/top_farmer.png")); // change the rect from 0x0 (default) to 100x100 pixels
    scene->setBackgroundBrush(QBrush(QImage(":/img/weed.jpg")));
    // add the item to the scene
    scene->addItem(my_player);

    // make rect focusable
    my_player->setFlag(QGraphicsItem::ItemIsFocusable);
    my_player->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    // show the view
    view->show();

}

PlayStart::~PlayStart()
{
    delete ui;
}

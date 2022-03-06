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
    QGraphicsScene * scene = new QGraphicsScene();
   //create a FarMER
    player * my_player = new player();
    my_player->setPixmap(QPixmap(":/img/top_farmer.png")); 
    scene->setBackgroundBrush(QBrush(QImage(":/img/weed.jpg")));
    // add FARMER to the ferma
    scene->addItem(my_player);
   
    my_player->setFlag(QGraphicsItem::ItemIsFocusable);
    my_player->setFocus();
   
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();

}

PlayStart::~PlayStart()
{
    delete ui;
}

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

class player: public QGraphicsPixmapItem{
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H

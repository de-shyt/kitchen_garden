#ifndef PLAYSTART_H
#define PLAYSTART_H

#include <QMainWindow>

namespace Ui {
class PlayStart;
}

class PlayStart : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayStart(QWidget *parent = nullptr);
    ~PlayStart();

private:
    Ui::PlayStart *ui;
};

#endif // PLAYSTART_H

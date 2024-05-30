#ifndef BARCO_H
#define BARCO_H

#include <QGraphicsProxyWidget>
#include <QObject>

#include "animations.h"
#include "fisicas.h"

#define ship_animations_number 3
class barco : public fisicas
{
    Q_OBJECT
public:
    barco(int level, QString file_prefix, int pos_x, int pos_y);
    QLabel* getBarco();
    void move(int key);
    animations *getShip_animations();
private:
    int actual_animation;
    animations *ship_animations;
signals:
    void ask_move(QPoint future_pos, QGraphicsProxyWidget *widget);
};

#endif // BARCO_H

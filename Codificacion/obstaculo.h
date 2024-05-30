#ifndef OBSTACULO_H
#define OBSTACULO_H


#include <QLabel>
#include <QTimer>
#include <QObject>

#include "animations.h"
#include "fisicas.h"

#define file_prefix ":/gifs/Gifs/obstacle"
class obstaculo : public fisicas
{
    Q_OBJECT
public:
    obstaculo(unsigned short obs_number, float ship_mass);
    QLabel *getObstacle();
    void move(int direction);
    void setWidget(QGraphicsProxyWidget *widget);
    animations *getObstacle_animations();
private:
    animations *obstacle_animations;
    QTimer *movement_timer;
private slots:
    void handle_timeout();
signals:
    void wanna(QPoint future_pos, QGraphicsProxyWidget *widget, obstaculo *obstacle);
};

#endif // OBSTACULO_H

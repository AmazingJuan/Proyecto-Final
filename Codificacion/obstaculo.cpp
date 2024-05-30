#include "obstaculo.h"

obstaculo::obstaculo(unsigned short obs_number, float ship_mass) : fisicas(0, 0, ship_mass) {
    QString aux = file_prefix;
    aux.append("_" + std::to_string(obs_number) + ".gif");
    obstacle_animations = new animations(":/gifs/Gifs/obstacle_1.gif");
    speed = 6;
    movement_timer = new QTimer;
}

QLabel *obstaculo::getObstacle()
{
    return obstacle_animations -> getMain_label();
}

void obstaculo::setWidget(QGraphicsProxyWidget *widget)
{
    obstacle_animations -> setWidget(widget);
    movement_timer->start(300);
    connect(movement_timer, &QTimer::timeout, this, &obstaculo::handle_timeout);
    pos_x = widget->x();
    pos_y = widget->y();
}

animations *obstaculo::getObstacle_animations()
{
    return obstacle_animations;
}

void obstaculo::handle_timeout()
{
    float x = obstacle_animations -> getWidget() -> x();
    float y = obstacle_animations -> getWidget() -> y();
    QPoint aux = QPoint(x, y + mru(1));
    emit wanna(aux, obstacle_animations -> getWidget(), this);
}


#include "obstaculo.h"

obstaculo::obstaculo(unsigned short obs_number, float ship_mass) : fisicas(0, 0, ship_mass) {
    QString aux = file_prefix;
    aux.append("_" + std::to_string(obs_number) + ".gif");
    obstacle_animations = new animations(":/gifs/Gifs/obstacle_1.gif");
    speed = 1;
    crash_happening = false;
    crash_counter = 0;
    movement_timer = new QTimer;
    movement_timer->start(25);
    setWidget(obstacle_animations -> getMain_label());
    connect(movement_timer, &QTimer::timeout, this, &obstaculo::handle_timeout);
}


animations *obstaculo::getObstacle_animations()
{
    return obstacle_animations;
}

void obstaculo::handle_timeout()
{
    QPoint aux = QPoint(x(), y() + mru(1));
    emit ask_move(aux, this, crash_happening);
}

void obstaculo::crash_timeout()
{
    if(crash_counter < 40){
        QPoint aux = QPoint(x(), y() + mru(-1));
        speed = trabajo(-0.1);
        emit ask_move(aux, this, crash_happening);
        crash_counter++;
    }
    else{
        crash_timer -> stop();
        movement_timer -> start(25);
        crash_happening = false;
        crash_counter = 0;
    }
}

void obstaculo::start_crash(QGraphicsProxyWidget *widget)
{
    if(widget == this){
        crash_happening = true;
        movement_timer -> stop();
        crash_timer = new QTimer;
        crash_timer -> start(25);
        connect(crash_timer, &QTimer::timeout, this, &obstaculo::crash_timeout);
    }
}


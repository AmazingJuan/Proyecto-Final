#include "barco.h"

barco::barco(int level, QString file_prefix, int pos_x, int pos_y) : fisicas(pos_x, pos_y, level * 5)
{
    ship_animations = new animations(file_prefix, ship_animations_number);
    crash_counter = 0;
    crash_happening = false;
    this -> setWidget(ship_animations -> getMain_label());
    ship_animations -> set_animation(0);
}

void barco::move(int animation)
{

    ship_animations -> set_animation(animation);
    if(animation == 1){
        emit ask_move(QPoint(x() + mru(-1), y()), this, crash_happening);
    }
    else if(animation == 2){
        emit ask_move(QPoint(x() + mru(1), y()), this, crash_happening);
    }
}

animations *barco::getShip_animations()
{
    return ship_animations;
}

void barco::crash_timeout()
{
    if(crash_counter < 40){
        QPoint aux = QPoint(x(), y() + mru(1));
        speed = trabajo(-0.1);
        emit ask_move(aux, this, crash_happening);
        crash_counter++;
    }
    else if(y() != 400){
        QPoint aux = QPoint(x(), y() + mru(-1));
        emit ask_move(aux, this, crash_happening);
        if(y() + mru(-1) <= 400){
            crash_timer -> stop();
            crash_happening = false;
            crash_counter = 0;
        }
    }
}

void barco::start_crash(QGraphicsProxyWidget *widget)
{
    crash_happening = true;
    crash_timer = new QTimer;
    crash_timer -> start(25);
    speed = 1;
    connect(crash_timer, &QTimer::timeout, this, &barco::crash_timeout);
}

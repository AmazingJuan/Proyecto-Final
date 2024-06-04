#include "barco.h"

barco::barco(int level, int pos_x, int pos_y) : fisicas(pos_x, pos_y, level * 5, 0.1 * level)
{
    QString aux = file_prefix + QString::number(level);
    ship_animations = new animations(aux, ship_animations_number, 100);
    crash_counter = 0;
    money = 8500;
    this -> level = level;
    crash_timer = nullptr;
    crash_happening = false;
    this -> setWidget(ship_animations -> getMain_label());
    ship_animations -> set_animation(0);
    crash_timer = new QTimer;
    connect(crash_timer, &QTimer::timeout, this, &barco::crash_timeout);
    setX(pos_x);
    setY(pos_y);

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

unsigned short barco::getMoney() const
{
    return money;
}

void barco::addMoney(unsigned short newMoney)
{
    money = newMoney;
}

unsigned short barco::getLevel() const
{
    return level;
}

void barco::setLevel(unsigned short newLevel)
{
    level = newLevel;
}

void barco::level_up(unsigned short level)
{
    this -> level = level;
    ship_force *= level;
    QString aux = file_prefix + QString::number(level);
    ship_animations -> change_animations(aux, 3);
}

void barco::crash_timeout()
{
    if(crash_counter < 40){
        QPoint aux = QPoint(x(), y() + mru(1));
        speed = trabajo(-1);
        emit ask_move(aux, this, crash_happening);
        crash_counter++;
    }
    else if(y() != 400){
        QPoint aux = QPoint(x(), y() + mru(-1));
        emit ask_move(aux, this, crash_happening);
        if(y() + mru(-1) <= 400){
            crash_timer -> stop();
            crash_counter = 0;
            crash_happening = false;
        }
        speed = 2;
    }
}

void barco::start_crash(float speed)
{
    crash_happening = true;
    if(!crash_timer->isActive()) crash_timer -> start(25);
    this -> speed = speed;

}

void barco::recieve_coin()
{
    money += 10;
}

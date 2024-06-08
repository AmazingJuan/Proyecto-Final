#include "obstaculo.h"

obstaculo::obstaculo(unsigned short obs_number, float ship_mass, float ship_force, unsigned short max_pixels) : fisicas(0, 0, ship_mass, ship_force) {
    QString aux = prefix;
    aux.append("_" + std::to_string(obs_number) + ".gif");
    obstacle_animations = new animations(aux, max_pixels);
    speed = 1;
    crash_happening = false;
    crash_counter = 0;
    setWidget(obstacle_animations -> getMain_label());
    movement_timer = new QTimer;
    crash_timer = new QTimer;
    connect(movement_timer, &QTimer::timeout, this, &obstaculo::handle_timeout);
    connect(crash_timer, &QTimer::timeout, this, &obstaculo::crash_timeout);
    if(obs_number != 4) is_dangerous = true;
    else is_dangerous = false;
}

obstaculo::~obstaculo()
{
    delete movement_timer;
    delete crash_timer;
    setWidget(nullptr);
    delete obstacle_animations;
    this -> disconnect();
}


animations *obstaculo::getObstacle_animations()
{
    return obstacle_animations;
}

bool obstaculo::getIs_dangerous() const
{
    return is_dangerous;
}

void obstaculo::setIs_dangerous(bool newIs_dangerous)
{
    is_dangerous = newIs_dangerous;
}

void obstaculo::handle_timeout()
{
    QPoint aux = QPoint(x(), y() + mru(1));
    emit ask_move(aux, this, crash_happening);
    if(y() > 700) {
        emit surpassed_limit(this);
    }
}

void obstaculo::crash_timeout()
{
    if(crash_counter < 40){
        QPoint aux = QPoint(x(), y() + mru(-1));
        speed = trabajo(-1);
        emit ask_move(aux, this, crash_happening);
        crash_counter++;
    }
    else{
        crash_timer -> stop();
        if(!movement_timer->isActive()) movement_timer -> start(25);
        crash_happening = false;
        crash_counter = 0;
    }
}

void obstaculo::start_crash(QGraphicsProxyWidget *widget)
{
    if(widget == this && is_dangerous){
        crash_happening = true;
        movement_timer -> stop();
        crash_timer -> start(25);

    }
    else if(widget == this && !is_dangerous){
        emit collect_coin();
    }
}

void obstaculo::start_movement(){
    movement_timer->start(25);
}

void obstaculo::stop_movement()
{
    movement_timer -> stop();
    crash_timer -> stop();
}

void obstaculo::change_speed(short direction)
{
    if(!crash_happening) speed = trabajo(direction);
}


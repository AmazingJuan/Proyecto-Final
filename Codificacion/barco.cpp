#include "barco.h"

barco::barco(int level, QString file_prefix, int pos_x, int pos_y) : fisicas(pos_x, pos_y, level * 5)
{
    ship_animations = new animations(file_prefix, ship_animations_number);

}

QLabel* barco::getBarco()
{
    return ship_animations -> getMain_label();
}

void barco::move(int animation)
{
    float x = ship_animations -> getWidget() -> x();
    float y = ship_animations -> getWidget() -> y();
    ship_animations -> set_animation(animation);
    if(animation == 1){
        emit ask_move(QPoint(x + mru(-1), y), ship_animations -> getWidget());
    }
    else if(animation == 2){
        emit ask_move(QPoint(x + mru(1), y), ship_animations -> getWidget());
    }
}

animations *barco::getShip_animations()
{
    return ship_animations;
}

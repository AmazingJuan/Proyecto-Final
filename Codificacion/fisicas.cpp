#include "fisicas.h"
#include <cmath>

fisicas::fisicas(int pos_x, int pos_y, float mass)
{
    this -> pos_x = pos_x;
    this -> pos_y = pos_y;
    this -> mass = mass;
    speed = 6;
}

float fisicas::mru(short direction)
{
    return speed * 1 * direction;
}
float fisicas::trabajo(int y_actual, float net_force)
{
    float aux = ((2*net_force * speed)/mass) + speed * speed;
    if(aux < 0) return 0;

    speed = sqrt(aux);
}

qreal fisicas::getSpeed() const
{
    return speed;
}

void fisicas::setSpeed(qreal newSpeed)
{
    speed = newSpeed;
}

float fisicas::getPos_x() const
{
    return pos_x;
}

void fisicas::setPos_x(float newPos_x)
{
    pos_x = newPos_x;
}

float fisicas::getPos_y() const
{
    return pos_y;
}

void fisicas::setPos_y(float newPos_y)
{
    pos_y = newPos_y;
}


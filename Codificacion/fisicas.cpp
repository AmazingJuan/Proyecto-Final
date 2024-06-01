#include "fisicas.h"
#include <cmath>


fisicas::fisicas(int pos_x, int pos_y, float mass)
{
    this -> pos_x = pos_x;
    this -> pos_y = pos_y;
    this -> mass = mass;
    min_speed = SPEED_MIN;
    max_speed = SPEED_MAX;
    speed = DEFAULT_SPEED;
}

float fisicas::mru(short direction)
{
    return speed * direction;
}
float fisicas::trabajo(float net_force)
{
    float aux = ((2*net_force * speed)/mass) + speed * speed;
    if(aux < min_speed) return min_speed;
    else if(aux > max_speed) return max_speed;

    speed = sqrt(aux);
}

float fisicas::getSpeed() const
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

float fisicas::getMass() const
{
    return mass;
}

void fisicas::setMass(float newMass)
{
    mass = newMass;
}


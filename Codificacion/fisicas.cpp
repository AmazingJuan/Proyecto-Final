#include "fisicas.h"
#include <cmath>


fisicas::fisicas(int pos_x, int pos_y, float mass, float ship_force)
{
    this -> pos_x = pos_x;
    this -> pos_y = pos_y;
    this -> mass = mass;
    this -> ship_force = ship_force;
    phase = M_PI / 2;
    min_speed = SPEED_MIN;
    max_speed = SPEED_MAX;
    speed = DEFAULT_SPEED;
}

float fisicas::mru(short direction)
{
    return speed * direction;
}
float fisicas::trabajo(short direction)
{
    float aux = ((2*ship_force* direction * speed)/mass) + speed * speed;
    if(sqrt(aux) < min_speed) return min_speed;
    else if(sqrt(aux) > max_speed) return max_speed;
    return sqrt(aux);
}

float fisicas::shm_x(unsigned int actual_time)
{
    float omega = 2 * M_PI * frequence;
    double var = initial_x + amplitude*cos(omega * float(actual_time)/1000 + phase);
    return var;
}

float fisicas::getSpeed() const
{
    return speed;
}

void fisicas::setSpeed(float newSpeed)
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

float fisicas::getShip_force() const
{
    return ship_force;
}

void fisicas::setShip_force(float newShip_force)
{
    ship_force = newShip_force;
}

void fisicas::calculate_phase(float initial_x)
{
    double hola = acos(initial_x/amplitude);
    phase = hola;
}

void fisicas::mcu(){

};


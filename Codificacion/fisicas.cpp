#include "fisicas.h"
#include <cmath>


fisicas::fisicas(int pos_x, int pos_y, float mass, float ship_force, unsigned short SPEED_MAX)
{
    //Se inicializan las variables físicas.
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
    return speed * direction; //La velocidad se interpreta en este escenario como pixeles avanzados por cada invocacion.
}
float fisicas::trabajo(short direction)
{
    float aux = ((2*ship_force*direction*speed)/mass) + speed * speed; //Se implementa el modelo de trabajo y energia, suponiendo que una fuerza incide en el barco cada vez que acelera o desacelera.
    if(sqrt(aux) < min_speed) return min_speed; //Si la velocidad resultante es menor que la velocidad minima, se devuelve la velocidad minima.
    else if(sqrt(aux) > max_speed) return max_speed; //Si la velocidad resultante es mayor que la velocidad máxima, se devuelve la velocidad máxima.
    return sqrt(aux); //Se devuelve la velocidad resultante.
}

float fisicas::shm_x(unsigned int actual_time)
{
    double omega = 2 * M_PI * frequence; //Se define la variable omega, rapidez angular.
    double var = 350 + amplitude*cos(omega * float(actual_time + initial_time)/10 + phase); //Se calcula la nueva posición del cuerpo, tomando como punto de maxima velocidad x = 350
    return var; //Se devuelve tal posición.
}

void fisicas::calculate_initial_time()
{
    double omega = 2 * M_PI * frequence; //Se define la variable omega, rapidez angular.
    initial_time = (acos(double(initial_x - 350) / amplitude) - phase)/omega; //Se despeja el tiempo en la ecuación de movimiento armonico simple.
}

QPoint fisicas::mcu(){
    angle += mcu_speed; //El angulo se actualiza con la velocidad angular.
    float aux = angle * (M_PI / 180.0f); //Se convierte de grados a radianes.
    float x = center_x + radius * cos(aux); //Se calcula la nueva posición X.
    float y = center_y - radius * sin(aux); //Se calcula la nueva posición Y.
    QPoint result(x,y); //Se inicializa un QPoint con las coordenadas nuevas.
    if(mcu_counter % 50 == 0) { //Si el contador de movimiento es multiplo de 50, el radio se disminuye en un 5%.
        radius *= 0.95;
        mcu_speed += 0.8; //Se aumenta la velocidad angular en 0.8.
    }
    return result; //Se devuelven las coordenadas nuevas.
};


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

unsigned short fisicas::getMax_speed() const
{
    return max_speed;
}

